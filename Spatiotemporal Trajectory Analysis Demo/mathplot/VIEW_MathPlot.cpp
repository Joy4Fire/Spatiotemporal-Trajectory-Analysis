#include <wx/wx.h>
#include <wx/window.h>

#include "res_commands.h"
#include "res_controls.h"
#include "res_images.h"
#include "res_dialogs.h"

#include "helper.h"
#include "dc_helper.h"

#include "wksp_table.h"

#include "VIEW_MathPlot.h "
#include "VIEW_MathPlot_control.h"

///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
IMPLEMENT_CLASS(CVIEW_MathPlot, CVIEW_Base);

//---------------------------------------------------------
BEGIN_EVENT_TABLE(CVIEW_MathPlot, CVIEW_Base)
EVT_MENU			(ID_CMD_MATHPLOT_PARAMETERS		, CVIEW_MathPlot::On_Parameters)
EVT_MENU			(ID_CMD_MATHPLOT_SIZE_FIT		, CVIEW_MathPlot::On_Size_Fit)
EVT_MENU			(ID_CMD_MATHPLOT_SIZE_INC		, CVIEW_MathPlot::On_Size_Inc)
EVT_MENU			(ID_CMD_MATHPLOT_SIZE_DEC		, CVIEW_MathPlot::On_Size_Dec)

EVT_MENU			(ID_CMD_MATHPLOT_SAVE			, CVIEW_MathPlot::On_Mathplot_Add)
//EVT_MENU			(ID_CMD_MATHPLOT_SAVE			, CVIEW_MathPlot::On_Mathplot_Save_Image)

EVT_KEY_DOWN		(CVIEW_MathPlot::On_Key_Down)
END_EVENT_TABLE()


///////////////////////////////////////////////////////////
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
CVIEW_MathPlot::CVIEW_MathPlot(CWKSP_Table *pTable)
: CVIEW_Base(ID_VIEW_MATHPLOT_TABLE, wxString::Format(wxT("%s [%s]"), LNG("[CAP] MathPlot"), pTable->Get_Name().c_str()), ID_IMG_WND_MATHPLOT, CVIEW_MathPlot::_Create_Menu(), LNG("[CAP] Mathplot"))
{
	SYS_Set_Color_BG_Window(this);

	m_pOwner	= pTable;

	m_pControl	= new CVIEW_MathPlot_control(this, pTable->Get_Table());

	_Create_paraAdd();

	wxCommandEvent	dummy;

	On_Size_Fit(dummy);
}

//---------------------------------------------------------
CVIEW_MathPlot::~CVIEW_MathPlot(void)
{
	m_pOwner->View_Closes(this);
}


///////////////////////////////////////////////////////////
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
wxMenu * CVIEW_MathPlot::_Create_Menu(void)
{
	wxMenu	*pMenu	= new wxMenu();

	CMD_Menu_Add_Item(pMenu, false, ID_CMD_MATHPLOT_PARAMETERS);
	CMD_Menu_Add_Item(pMenu, false, ID_CMD_MATHPLOT_SIZE_FIT);
	CMD_Menu_Add_Item(pMenu, false, ID_CMD_MATHPLOT_SIZE_INC);
	CMD_Menu_Add_Item(pMenu, false, ID_CMD_MATHPLOT_SIZE_DEC);
	CMD_Menu_Add_Item(pMenu, false, ID_CMD_MATHPLOT_SAVE);

	return( pMenu );
}

//---------------------------------------------------------
wxToolBarBase * CVIEW_MathPlot::_Create_ToolBar(void)
{
	wxToolBarBase	*pToolBar	= CMD_ToolBar_Create(ID_TB_MATHPLOT);

	CMD_ToolBar_Add_Item(pToolBar, false, ID_CMD_MATHPLOT_PARAMETERS);
	CMD_ToolBar_Add_Item(pToolBar, false, ID_CMD_MATHPLOT_SIZE_FIT);
	CMD_ToolBar_Add_Item(pToolBar, false, ID_CMD_MATHPLOT_SIZE_INC);
	CMD_ToolBar_Add_Item(pToolBar, false, ID_CMD_MATHPLOT_SIZE_DEC);
	CMD_ToolBar_Add_Item(pToolBar, false, ID_CMD_MATHPLOT_SAVE);

	CMD_ToolBar_Add(pToolBar, LNG("[CAP] Line Plot"));

	return( pToolBar );
}


///////////////////////////////////////////////////////////
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
bool CVIEW_MathPlot::Update_Mathplot(void)
{
	return( m_pControl->Update_Mathplot() );
}


///////////////////////////////////////////////////////////
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
void CVIEW_MathPlot::On_Parameters(wxCommandEvent &event)
{
	m_pControl->Set_Parameters();
}

//---------------------------------------------------------
void CVIEW_MathPlot::On_Size_Fit(wxCommandEvent &event)
{
	m_pControl->Fit_Size();
}

//---------------------------------------------------------
void CVIEW_MathPlot::On_Size_Inc(wxCommandEvent &event)
{
	m_pControl->Inc_Size();
}

//---------------------------------------------------------
void CVIEW_MathPlot::On_Size_Dec(wxCommandEvent &event)
{
	m_pControl->Dec_Size();
}

//---------------------------------------------------------
void CVIEW_MathPlot::On_Mathplot_Save_Image(wxCommandEvent &event)
{
	m_pControl->SaveAs_Image();
}

//---------------------------------------------------------
void CVIEW_MathPlot::On_Key_Down(wxKeyEvent &event)
{

	switch( event.GetKeyCode() )
	{
	default:
		event.Skip();
		break;

	case 'S':
		if( event.GetModifiers() == wxMOD_CONTROL )
		{
			m_pControl->SaveAs_Image();
		}
		break;
	}
}

//---------------------------------------------------------
void CVIEW_MathPlot::_Create_paraAdd(void)
{
	CSG_Parameter *pNodeLabel, *pNodeMarkL, *pNodeL;
	m_paraAdd.Set_Callback_On_Parameter_Changed(&_On_Parameter_Changed);

	m_paraAdd.Add_Choice(
		NULL	, "ADD"	, LNG("The Item to Add"),
		LNG(""),
		CSG_String::Format(LNG("%s|%s|%s|"),
		LNG("Label"),
		LNG("MarkLine"),
		LNG("Line")
		), 0
		);

	pNodeLabel = m_paraAdd.Add_Node(NULL, "NODE1", "Label", "");
	pNodeMarkL = m_paraAdd.Add_Node(NULL, "NODE2", "MarkLine", "");
	pNodeL = m_paraAdd.Add_Node(NULL, "NODE3", "Line", "");

	//---------------------------------------------------------Txt
	m_paraAdd.Add_String(
		pNodeLabel,	"LABEL",	LNG("Label"),
		LNG(""),
		LNG("Level")
		);

	//---------------------------------------------------------MarkLine
	m_paraAdd.Add_Value(
		pNodeMarkL,	"LENGTH",	LNG("Length"),
		LNG(""),
		PARAMETER_TYPE_Double,800
		);
	m_paraAdd.Add_Choice(
		pNodeMarkL, "MARKLINETYPE"		, LNG("Type"),
		LNG(""),
		wxString::Format(wxT("%s|%s|%s|%s|%s|"),
		LNG("Solid"),
		LNG("Dot"),
		LNG("Long_Dash"),
		LNG("Short_Dash"),
		LNG("Dot_Dash")
		), 2
		);
	m_paraAdd.Add_Value(
		pNodeMarkL,	"MARKLINECOLOR",	LNG("Color"),
		LNG(""),
		PARAMETER_TYPE_Color,SG_COLOR_GREEN
		);


	//---------------------------------------------------------Line
	m_paraAdd.Add_Table(
		pNodeL,	"TABLE",	LNG("table"),
		LNG(""),
		PARAMETER_INPUT_OPTIONAL
		);
	m_paraAdd.Add_Table_Field(
		m_paraAdd("TABLE"),	"FIELD",	LNG("Field"),
		LNG("")
		);
	m_paraAdd.Add_Value(
		pNodeL,	"SCALE",	LNG("Scale"),
		LNG(""),
		PARAMETER_TYPE_Double, 10
		);

	//������Ԥ����û������!
	// 	m_paraAdd("LENGTH")->Set_Enabled(false);
	// 	m_paraAdd("LABEL")->Set_Enabled(false);
	// 	m_paraAdd("TABLE")->Set_Enabled(false);

}


//---------------------------------------------------------
void CVIEW_MathPlot::On_Mathplot_Add( wxCommandEvent &event )
{
	if (DLG_Parameters(&m_paraAdd) && m_paraAdd.DataObjects_Check())
	{
		switch(m_paraAdd("ADD")->asInt())
		{
		default:
		case 0:
			m_pControl-> Add_Txt(m_paraAdd("LABEL")->asString());
			break;
		case 1:
			long ln_flag;
			switch( m_paraAdd("MARKLINETYPE")->asInt() )
			{
			default:
			case 0:		ln_flag =	wxSOLID;			break;	
			case 1:		ln_flag =	wxDOT; 				break;
			case 2:		ln_flag =	wxLONG_DASH;		break;
			case 3:		ln_flag =	wxSHORT_DASH;		break;	
			case 4:		ln_flag =	wxDOT_DASH;			break;
			}
			m_pControl-> Add_MarkLine(m_paraAdd("LENGTH")->asDouble(), 
									  wxPen(wxColor(m_paraAdd("MARKLINECOLOR")->asInt()),1,ln_flag)
									  );
			break;
		case 2:
			int iField;
			double scale, *data;
			CSG_Table *pTable = NULL;
			CSG_Table_Record *pRecord;
			pTable	= m_paraAdd("TABLE")->asTable();
			
			if (pTable)
			{
				iField	= m_paraAdd("FIELD")->asInt();
				scale	= m_paraAdd("SCALE")->asDouble();
				data	= new double[pTable->Get_Record_Count()];
				for (int iRecord = 0; iRecord < pTable->Get_Record_Count(); iRecord++)
				{
					pTable->Get_Value(iRecord, iField, data[iRecord]);
				}
				m_pControl-> Add_Line(data, scale,  pTable->Get_Record_Count(), pTable->Get_Field_Name(iField));
			}
			break;
		}
	}
}


//--------------------------------------------------------
int CVIEW_MathPlot::_On_Parameter_Changed( CSG_Parameter *pParameter)
{
	if ( pParameter && pParameter->Get_Owner())
	{
		return (On_Parameter_Changed(pParameter->Get_Owner(), pParameter));
	}

	return( 0);
}


//--------------------------------------------------------
int CVIEW_MathPlot::On_Parameter_Changed( CSG_Parameters *pParameters, CSG_Parameter *pParameter )//�ܽ���,���Ǹо�û��������,������setvalue����������,������������,֮ǰ������������Ϊ��paraent�����Ƕ���������,����ȫ��NULL��Ϊparent�Ϳ�����!!�����ַ����ˣ�Ȼ���ֲ���������
{
	switch(pParameters->Get_Parameter("ADD")->asInt())
	{
	default:
	case 0:
		{
			pParameters->Get_Parameter("NODE1")->Set_Enabled(true);
			pParameters->Get_Parameter("NODE2")->Set_Enabled(false);
			pParameters->Get_Parameter("NODE3")->Set_Enabled(false);
		}break;
	case 1:
		{
			pParameters->Get_Parameter("NODE1")->Set_Enabled(false);
			pParameters->Get_Parameter("NODE2")->Set_Enabled(true);
			pParameters->Get_Parameter("NODE3")->Set_Enabled(false);
		}break;

	case 2:
		{
			pParameters->Get_Parameter("NODE1")->Set_Enabled(false);
			pParameters->Get_Parameter("NODE2")->Set_Enabled(false);
			pParameters->Get_Parameter("NODE3")->Set_Enabled(true);

		}break;
	}

	return 1;
}