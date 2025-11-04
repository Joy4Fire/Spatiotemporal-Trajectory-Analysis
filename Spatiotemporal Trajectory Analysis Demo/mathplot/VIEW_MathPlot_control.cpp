#include <wx/window.h>
#include <vector>

#include <saga_api/saga_api.h>

// #include "res_commands.h"
// #include "res_controls.h"
// #include "res_images.h"
 #include "res_dialogs.h"

 #include "helper.h"
// #include "dc_helper.h"

// #include "wksp.h"
// #include "wksp_data_manager.h"

// #include "wksp_grid.h"
// #include "wksp_shapes.h"

#include "VIEW_MathPlot_control.h "

#include  "wksp_table.h"


//---------------------------------------------------------
CVIEW_MathPlot_control::~CVIEW_MathPlot_control(void)
{
	
}

//---------------------------------------------------------
CVIEW_MathPlot_control::CVIEW_MathPlot_control(wxWindow *pParent, CSG_Table *pTable) : wxPanel(pParent,wxID_ANY)
{	
	SYS_Set_Color_BG_Window(this);

	m_pTable	= pTable;
	m_nFields	= 0;
	m_Fields	= NULL;
	
	m_pWindow		= new mpWindow(this, wxID_ANY);

	//---------------------------------------------------------
 	wxBoxSizer *topsizer = new wxBoxSizer( wxVERTICAL );
 	topsizer->Add( m_pWindow, 1, wxEXPAND );
	m_pWindow->EnableDoubleBuffer(true);
	SetAutoLayout( true );
	SetSizer( topsizer );

	//---------------------------------------------------------
	_Initialize();

	Set_Parameters();
}

//---------------------------------------------------------
bool CVIEW_MathPlot_control::Set_Parameters(void)
{
	if( DLG_Parameters(&m_Parameters) )
	{
		return( _Create() );
	}

	return( false );
}


//---------------------------------------------------------
bool CVIEW_MathPlot_control::_Initialize(void)
{
	_Destroy();

	//-----------------------------------------------------
	if( m_pTable && m_pTable->Get_Field_Count() > 0 && m_pTable->Get_Count() > 0 )
	{
		CSG_String		sFields_All, sFields_Num;
		CSG_Parameter	*pNode, *pFields, *pColors;

		m_Structure.Create(m_pTable);

		m_Colors.Set_Count(m_pTable->Get_Field_Count());

		m_Parameters.Create(NULL, LNG("[CAP] Properties"), LNG(""));

		//---------------------------------------------------------
		//Attributes
		pFields	= m_Parameters.Add_Node(NULL, "NODE_FIELDS", LNG("[CAP] Attributes")	, LNG(""));

		for(int iField=0; iField<m_pTable->Get_Field_Count(); iField++)
		{
			if( m_pTable->Get_Field_Type(iField) != SG_DATATYPE_String )
			{
				pColors	= m_Parameters.Add_Value(
					pFields, wxString::Format(wxT("FIELD_%d"), iField), m_pTable->Get_Field_Name(iField),
					LNG("[CAP] Show"),
					PARAMETER_TYPE_Bool, false
					);

				m_Parameters.Add_Value(
					pColors, wxString::Format(wxT("COLOR_%d"), iField), SG_T(""),
					LNG("[CAP] Color"),
					PARAMETER_TYPE_Color, m_Colors.Get_Color(iField)
					);

				sFields_Num	+= m_pTable->Get_Field_Name(iField) + CSG_String(SG_T("|"));
			}

			sFields_All	+= m_pTable->Get_Field_Name(iField) + CSG_String(SG_T("|"));
		}

		sFields_Num	+= LNG("[CAP] [none]") + CSG_String(SG_T("|"));
		sFields_All	+= LNG("[CAP] [none]") + CSG_String(SG_T("|"));

		//-------------------------------------------------
		//General
		pNode	= m_Parameters.Add_Node(
			NULL, "GENERAL", LNG("[CAP] General"),
			LNG("")
			);

		m_Parameters.Add_Choice(
			pNode, "_PLOT_TYPE"		, LNG("[CAP] Display Type"),
			LNG(""),
			wxString::Format(wxT("%s|%s|%s|%s|"),
			LNG("Lines and Points"),
			LNG("Lines"),
			LNG("Points"),
			LNG("Bars")
			), 0
			);

		m_pFont	= m_Parameters.Add_Font(
			pNode, "_PLOT_FONT"		, LNG("[CAP] Font"),
			LNG("")
			)->asFont();

		m_Parameters.Add_Value(
			pNode, "_PLOT_LEGEND"	, LNG("[CAP] Legend"),
			LNG(""),
			PARAMETER_TYPE_Bool, true
			);

		m_Parameters.Add_Value(
			pNode, "_PLOT_COOR"		, LNG("[CAP] Coordinate"),
			LNG(""),
			PARAMETER_TYPE_Bool, false
			);

		m_Parameters.Add_Value(
			pNode, "_X_GRID"		, LNG("[CAP] x_Grid"),
			LNG(""),
			PARAMETER_TYPE_Bool, false
			);
		m_Parameters.Add_Value(
			pNode, "_Y_GRID"		, LNG("[CAP] y_Grid"),
			LNG(""),
			PARAMETER_TYPE_Bool, false
			);

		//-------------------------------------------------
		//Style
		pNode	= m_Parameters.Add_Node(
			NULL, "NODE_POINTS", LNG("[CAP] Style"),
			LNG("")
			);

		m_Parameters.Add_Value(
			pNode, "_POINTS_SIZE"		, LNG("[CAP] Points Size"),
			LNG(""),
			PARAMETER_TYPE_Int, 3, 1, true
			);

		m_Parameters.Add_Choice(
			pNode, "_POINTS_TYPE"		, LNG("[CAP] Points Type"),
			LNG(""),
			wxString::Format(wxT("%s|%s|%s|"),
			LNG("Solid"),
			LNG("Cross_Diag"),
			LNG("Cross")
			), 0
			);

		m_Parameters.Add_Value(
			pNode, "_LINES_SIZE"		, LNG("[CAP] Lines Size"),
			LNG(""),
			PARAMETER_TYPE_Int, 1, 1, true
			);
		m_Parameters.Add_Choice(
			pNode, "_LINES_TYPE"		, LNG("[CAP] Lines Type"),
			LNG(""),
			wxString::Format(wxT("%s|%s|%s|%s|%s|"),
			LNG("Solid"),
			LNG("Dot"),
			LNG("Long_Dash"),
			LNG("Short_Dash"),
			LNG("Dot_Dash")
			), 0
			);

		//-------------------------------------------------
		//Axis
		pNode	= m_Parameters.Add_Node(
			NULL, "NODE_AXIS", LNG("[CAP] Axis"),
			LNG("")
			);
		
		m_Parameters.Add_Value(
			pNode, "_AXIS_CENTRAL"	, LNG("[CAP] Axis_Central"),
			LNG(""),
			PARAMETER_TYPE_Bool, true
			);
		
		m_Parameters.Add_Choice(
			pNode, "_X_FIELD"	, LNG("[CAP] x_Axis"),
			LNG(""),
			sFields_Num, m_pTable->Get_Field_Count() + 1
			);

 		m_Parameters.Add_Value(
 			pNode, "_X_BORD"	, LNG("[CAP] x_Bord"),
 			LNG(""),
 			PARAMETER_TYPE_Int,20,0,true
 			);
		m_Parameters.Add_String(
			pNode, "_X_FMT"		, LNG("x_Format"),
			LNG(""),
			".0f"
			);

 		m_Parameters.Add_Value(
 			pNode, "_Y_BORD"	, LNG("[CAP] y_Bord"),
 			LNG(""),
 			PARAMETER_TYPE_Int,35,0,true
 			);
		m_Parameters.Add_String(
			pNode, "_Y_FMT"		, LNG("y_Format"),
			LNG(""),
			".2f"
			);
		m_Parameters.Add_String(
			pNode, "_Y_LABEL"		, LNG("y_Label"),
			LNG(""),
			"Value"
			);

		return( _Create() );
	}
	return false;
}

//---------------------------------------------------------
bool CVIEW_MathPlot_control::_Create(void)
{
	_Destroy();

	//-----------------------------------------------------
	if( m_pTable && m_pTable->Get_Field_Count() > 0 )
	{
		m_xField	= _Get_Field_By_Name(m_Parameters("_X_FIELD")->asString());

		if( m_xField < 0 && m_pTable->Get_Range(m_xField) <= 0.0 )
		{
			m_xField	= -1;
		}

		//-------------------------------------------------
		for(int iField=0; iField<m_pTable->Get_Field_Count(); iField++)
		{
			if(	m_pTable->Get_Field_Type(iField) != SG_DATATYPE_String
				&&	m_Parameters(wxString::Format(wxT("FIELD_%d"), iField))->asBool() )
			{
				m_Fields			= (int *)SG_Realloc(m_Fields, (m_nFields + 1) * sizeof(int));
				m_Fields[m_nFields]	= iField;
				m_Colors.Set_Color(iField, m_Parameters(wxString::Format(wxT("COLOR_%d"), iField))->asColor());
				
				m_nFields++;
			}
		}
	}
	
	//---------------------------------------------------------
	if (m_nFields > 0)
	{
		_Draw();
		return true;
	}
	else	
	{
		mpText *pText = new mpText(LNG("NO DATA TO PLOT"),35,45);
		m_pWindow->AddLayer(pText);
	}
	return false;
	
}

//---------------------------------------------------------
void CVIEW_MathPlot_control::_Draw(void)
{
	int					nPoints, x_bord, y_bord, pt_size, ln_size;
	wxString			x_Fmt, y_Fmt, x_label, y_label;
	long				pt_flag, ln_flag;
	bool				b_lines, b_points;
	
	nPoints		= m_pTable->Get_Count();
	x_bord		= m_Parameters(LNG("_X_BORD"))->asInt();
	y_bord		= m_Parameters(LNG("_Y_BORD"))->asInt();
	x_Fmt		= wxString::Format("%s%s","%",m_Parameters(LNG("_X_FMT"))->asString());
	y_Fmt		= wxString::Format("%s%s","%",m_Parameters(LNG("_Y_FMT"))->asString());	
	x_label		= (m_xField >= 0)
				? m_pTable->Get_Field_Name(m_xField)
				: LNG("Index");
	y_label		= wxString(m_Parameters("_Y_LABEL")->asString());
	pt_flag		= wxSOLID;
	ln_flag		= wxSOLID;
	b_lines		= false;
	b_points	= false;
	pt_size		= m_Parameters("_POINTS_SIZE")->asInt();
	ln_size		= m_Parameters("_LINES_SIZE")->asInt();


	switch( m_Parameters("_POINTS_TYPE")->asInt() )
	{
	default:
	case 0:		pt_flag =	wxSOLID;			break; 	
	case 1:		pt_flag =	wxCROSSDIAG_HATCH;	break;	
	case 2:		pt_flag =	wxCROSS_HATCH;		break;	
	}

	switch( m_Parameters("_LINES_TYPE")->asInt() )
	{
	default:
	case 0:		ln_flag =	wxSOLID;			break;	
	case 1:		ln_flag =	wxDOT; 				break;
	case 2:		ln_flag =	wxLONG_DASH;		break;
	case 3:		ln_flag =	wxSHORT_DASH;		break;	
	case 4:		ln_flag =	wxDOT_DASH;			break;
	}
	m_pPtPen	=	new wxPen(*wxRED,pt_size,pt_flag);
	m_pLnPen	=	new wxPen(*wxRED,ln_size,ln_flag);

	switch( m_Parameters("_PLOT_TYPE")->asInt())
	{
	default:
	case 0:		b_lines =	true;	b_points =	true;		break;	//lines and points
	case 1:		b_lines =	true;	b_points =	false;		break;	//lines
	case 2:		b_lines =	false;	b_points =	true;		break;	//points
	case 3:		b_lines =	false;	b_points =	false;		break;	//bar
	}
	//---------------------------------------------------------
	wxBrush hatch_Coords(wxColour(200,200,200), wxSOLID);
	wxBrush hatch_Legend(wxColour(163,208,212), wxSOLID);

	m_pXaxis		= new mpScaleX();
	m_pYaxis		= new mpScaleY();
	m_pCoor_nfo		= new mpInfoCoords(wxRect(80,20,40,30), &hatch_Coords);
	m_pLeg_nfo		= new mpInfoLegend(wxRect(200,20,40,40),&hatch_Legend);

	m_pWindow	->	SetMargins(0, 0, x_bord, y_bord);
	m_pXaxis	->	SetName(x_label);
	m_pYaxis	->	SetName(y_label);
	m_pXaxis	->	SetFmt(x_Fmt);
	m_pYaxis	->	SetFmt(y_Fmt);
	m_pXaxis	->	SetFont(*m_pFont);
	m_pYaxis	->	SetFont(*m_pFont);
	m_pCoor_nfo	->	SetVisible(m_Parameters("_PLOT_COOR")->asBool());
	m_pLeg_nfo	->	SetVisible(m_Parameters("_PLOT_LEGEND")->asBool());
	m_pXaxis	->	SetTicks(!(m_Parameters("_X_GRID")->asBool()));
	m_pYaxis	->	SetTicks(!(m_Parameters("_Y_GRID")->asBool()));	
	m_pWindow	->	AddLayer(m_pXaxis ); 
	m_pWindow	->	AddLayer(m_pYaxis );
	m_pWindow	->	AddLayer(m_pCoor_nfo);
	m_pWindow	->	AddLayer(m_pLeg_nfo);
	//---------------------------------------------------------
	if (!(m_Parameters("_AXIS_CENTRAL")->asBool()))
	{
		m_pXaxis	->	SetDrawOutsideMargins(false);
		m_pYaxis	->	SetDrawOutsideMargins(false);
		m_pXaxis	->	SetAlign(mpALIGN_BOTTOM);
		m_pYaxis	->	SetAlign(mpALIGN_LEFT);
	}
	

	//---------------------------------------------------------
	for (int i=0; i < m_nFields; i++)
	{
		int						n, iField;
		wxColour				Rcolor;
		CSG_Table_Record		*pRecord;
		wxPen					RptPen, RlnPen;
		std::vector<float>		xs_f(nPoints), ys_f(nPoints);
		
		//---------------------------------------------------------
		n			=	0;
		iField		=	m_Fields[i];
		Rcolor		=	Get_Color_asWX(m_Colors.Get_Color(iField));
		RptPen		=	*m_pPtPen;		// Get the old pen to modify only colour, not style or width
		RlnPen		=	*m_pLnPen;
		RptPen.SetColour(Rcolor);
		RlnPen.SetColour(Rcolor);

		for (int iRecord = 0;iRecord < nPoints; iRecord ++)
		{
			pRecord		=	m_pTable->Get_Record(iRecord);
			xs_f[n]		=	(m_xField >= 0)
						?	pRecord->asDouble(m_xField)
						:	n;			//1 was the first index 
			ys_f[n]		=	pRecord->asDouble(iField);
			
			n++;
		}

		if (b_lines)
		{
			mpPolygon		*pPolygon;
			pPolygon		=	new mpPolygon(wxT(m_pTable->Get_Field_Name(iField)));
			pPolygon		->	ShowName(false);
			pPolygon		->	SetPen( RlnPen);
			pPolygon		->	setPoints(xs_f, ys_f, false); 
			m_pWindow		->	AddLayer(pPolygon);
		}
			
		if (b_points)
		{
			mpFXYVector							*pFxyvector;
			pFxyvector	=	new mpFXYVector(wxT(m_pTable->Get_Field_Name(iField)));
			pFxyvector	->	ShowName(false);
			pFxyvector	->	SetLayerType(mpLAYER_NO_Legend);
			pFxyvector	->	SetPen( RptPen);
			pFxyvector	->	SetData(xs_f, ys_f);
			m_pWindow		->	AddLayer(pFxyvector);
		}
	}
	m_pWindow->Fit();
}

//---------------------------------------------------------
bool CVIEW_MathPlot_control::Update_Mathplot(void)
{
	return( m_Structure.is_Compatible(m_pTable, true) ? _Create() : _Initialize() );
}

//---------------------------------------------------------
int CVIEW_MathPlot_control::_Get_Field_By_Name(const CSG_String &sField)
{
	if( m_pTable )
	{
		for(int iField=0; iField<m_pTable->Get_Field_Count(); iField++)
		{
			if( sField.Cmp(m_pTable->Get_Field_Name(iField)) == 0 )
			{
				return( iField );
			}
		}
	}

	return( -1 );
}

//---------------------------------------------------------
void CVIEW_MathPlot_control::_Destroy(void)
{
	
	m_pWindow->DelAllLayers(true);
	
	if( m_nFields > 0 )
	{
		SG_Free(m_Fields);

		m_Fields	= NULL;
		m_nFields	= 0;
	}
}


//---------------------------------------------------------
void CVIEW_MathPlot_control::SaveAs_Image(void)
{
	wxFileDialog fileDialog(this, _("Save a screenshot"), wxT(""), wxT(""), wxT("BMP image (*.bmp) | *.bmp|JPEG image (*.jpg) | *.jpeg;*.jpg|PNG image (*.png) | *.png"), wxFD_SAVE);
	if(fileDialog.ShowModal() == wxID_OK) 
	{
		wxFileName namePath(fileDialog.GetPath());
		int fileType = wxBITMAP_TYPE_BMP;
		if( namePath.GetExt().CmpNoCase(wxT("jpeg")) == 0 ) fileType = wxBITMAP_TYPE_JPEG;
		if( namePath.GetExt().CmpNoCase(wxT("jpg")) == 0 )  fileType = wxBITMAP_TYPE_JPEG;
		if( namePath.GetExt().CmpNoCase(wxT("png")) == 0 )  fileType = wxBITMAP_TYPE_PNG;
		m_pWindow->SaveScreenshot(fileDialog.GetPath(), fileType);
	}
}

//---------------------------------------------------------
void CVIEW_MathPlot_control::Add_Txt( const SG_Char* name )
{
	wxBrush hatch_Text(wxColour(200,200,200), wxSOLID);
	m_pWindow->AddLayer(new mpInfoText(wxRect(80,20,40,30), name, &hatch_Text));
}


//---------------------------------------------------------
void CVIEW_MathPlot_control::Add_MarkLine(double LineLength, wxPen pen)
{
	//wxBrush hatch_Text(wxColour(200,200,200), wxSOLID);
	m_pWindow->AddLayer(new mpInfoLine(wxRect(80,20,40,30), LineLength, pen));
}

//---------------------------------------------------------
void CVIEW_MathPlot_control::Add_Line(double *data, double scale, int nRecord, const SG_Char* name)
{
	//mpSubScaleY
	m_pWindow->SetMarginRight(20);
	std::vector<float>		xs_f(nRecord), ys_f(nRecord);
	mpSubScaleY *pSubYaxis = new mpSubScaleY();
	//pSubYaxis->SetFmt();
	pSubYaxis->SetName(name);
	pSubYaxis->SetFont(*m_pFont);
	pSubYaxis->SetScale(scale);
	m_pWindow -> AddLayer(pSubYaxis);
	wxPen RptPen, RlnPen;
	RptPen		=	*m_pPtPen;		// Get the old pen to modify only colour, not style or width
	RlnPen		=	*m_pLnPen;
	//RptPen.SetColour(Rcolor);
	//RlnPen.SetColour(Rcolor);

	for (unsigned i = 0; i < nRecord; i++)
	{
		xs_f[i]		=	i;			//1 was the first index 
		ys_f[i]		=	data[i] * scale;
	}
	if (/*b_lines*/true)
	{
		mpPolygon		*pPolygon;
		pPolygon		=	new mpPolygon(name);
		pPolygon		->	ShowName(false);
		//pPolygon		->	SetPen( RlnPen);
		pPolygon		->	setPoints(xs_f, ys_f, false); 
		m_pWindow		->	AddLayer(pPolygon);
	}

	if (/*b_points*/true)
	{
		mpFXYVector							*pFxyvector;
		pFxyvector	=	new mpFXYVector(name);
		pFxyvector	->	ShowName(false);
		pFxyvector	->	SetLayerType(mpLAYER_NO_Legend);
		//pFxyvector	->	SetPen( RptPen);
		pFxyvector	->	SetData(xs_f, ys_f);
		m_pWindow		->	AddLayer(pFxyvector);
	}
}