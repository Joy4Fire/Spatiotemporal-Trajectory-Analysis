///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "trajectory_analysis_table.h"

///////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------
IMPLEMENT_CLASS(CDLG_Table, CDLG_Base)

//---------------------------------------------------------
BEGIN_EVENT_TABLE(CDLG_Table, CDLG_Base)
EVT_KEY_DOWN(CDLG_Table::On_Key)

EVT_BUTTON(ID_BTN_LOAD, CDLG_Table::On_Load)
EVT_BUTTON(ID_BTN_SAVE, CDLG_Table::On_Save)
EVT_BUTTON(ID_BTN_ADD, CDLG_Table::On_Add)
EVT_BUTTON(ID_BTN_INSERT, CDLG_Table::On_Insert)
EVT_BUTTON(ID_BTN_DELETE, CDLG_Table::On_Delete)
EVT_BUTTON(ID_BTN_DELETE_ALL, CDLG_Table::On_Delete_All)
EVT_BUTTON(ID_BTN_COLORS, CDLG_Table::On_Colors)
END_EVENT_TABLE()

///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------

trajectory_analysis_table::trajectory_analysis_table(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxDialog(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer(wxHORIZONTAL);

	m_staticText1 = new wxStaticText(this, wxID_ANY, wxT("Selected ID:"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText1->Wrap(-1);
	bSizer2->Add(m_staticText1, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	m_staticText2 = new wxStaticText(this, wxID_ANY, wxT("359"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText2->Wrap(-1);
	bSizer2->Add(m_staticText2, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);


	bSizer1->Add(bSizer2, 1, wxEXPAND, 5);

	m_staticline1 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	bSizer1->Add(m_staticline1, 0, wxEXPAND | wxALL, 5);

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer(wxVERTICAL);

	m_staticText3 = new wxStaticText(this, wxID_ANY, wxT("Start Time:"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText3->Wrap(-1);
	bSizer6->Add(m_staticText3, 0, wxALL, 5);

	m_textCtrl1 = new wxTextCtrl(this, wxID_ANY, wxT("1145533950000"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer6->Add(m_textCtrl1, 0, wxALL | wxEXPAND, 5);

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer(wxHORIZONTAL);

	m_button4 = new wxButton(this, wxID_ANY, wxT("Query"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer9->Add(m_button4, 1, wxALL, 5);

	m_button7 = new wxButton(this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer9->Add(m_button7, 1, wxALL, 5);


	bSizer6->Add(bSizer9, 1, wxEXPAND, 5);


	bSizer3->Add(bSizer6, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer(wxVERTICAL);

	m_staticText4 = new wxStaticText(this, wxID_ANY, wxT("End Time:"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText4->Wrap(-1);
	bSizer7->Add(m_staticText4, 0, wxALL, 5);

	m_textCtrl2 = new wxTextCtrl(this, wxID_ANY, wxT("1145538440000"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer7->Add(m_textCtrl2, 0, wxALL | wxEXPAND, 5);

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer(wxHORIZONTAL);

	m_button6 = new wxButton(this, wxID_ANY, wxT("Edit"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer10->Add(m_button6, 1, wxALL, 5);

	m_button8 = new wxButton(this, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer10->Add(m_button8, 1, wxALL, 5);


	bSizer7->Add(bSizer10, 1, wxEXPAND, 5);


	bSizer3->Add(bSizer7, 1, wxEXPAND, 5);


	bSizer1->Add(bSizer3, 1, wxEXPAND, 5);

	m_staticline3 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	bSizer1->Add(m_staticline3, 0, wxEXPAND | wxALL, 5);

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer(wxVERTICAL);

	m_grid1 = new wxGrid(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);

	// Grid
	m_grid1->CreateGrid(10, 3);
	m_grid1->EnableEditing(true);
	m_grid1->EnableGridLines(true);
	m_grid1->EnableDragGridSize(true);
	m_grid1->SetMargins(0, 0);

	// Columns
	m_grid1->SetColSize(0, 99);
	m_grid1->SetColSize(1, 114);
	m_grid1->SetColSize(2, 137);
	m_grid1->EnableDragColMove(false);
	m_grid1->EnableDragColSize(true);
	m_grid1->SetColLabelSize(30);
	m_grid1->SetColLabelValue(0, wxT("id"));
	m_grid1->SetColLabelValue(1, wxT("startime"));
	m_grid1->SetColLabelValue(2, wxT("endtime"));
	m_grid1->SetColLabelAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);

	// Rows
	m_grid1->SetRowSize(0, 30);
	m_grid1->AutoSizeRows();
	m_grid1->EnableDragRowSize(true);
	m_grid1->SetRowLabelSize(80);
	m_grid1->SetRowLabelAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);

	// Label Appearance

	// Cell Defaults
	m_grid1->SetDefaultCellAlignment(wxALIGN_LEFT, wxALIGN_TOP);
	bSizer8->Add(m_grid1, 0, wxALL | wxEXPAND, 5);


	bSizer1->Add(bSizer8, 1, wxEXPAND, 5);


	this->SetSizer(bSizer1);
	this->Layout();

	this->Centre(wxBOTH);
}

trajectory_analysis_table::~trajectory_analysis_table()
{
}



void trajectory_analysis_table::Set_Labeling(bool bOn)
{
	if (bOn && m_Field_Offset == 0)
	{
		m_Field_Offset = 1;

		SetRowLabelAlignment(wxALIGN_RIGHT, wxALIGN_CENTRE);
	}
	else if (!bOn && m_Field_Offset != 0)
	{
		m_Field_Offset = 0;

		SetRowLabelAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);

		Freeze();

		for (int i = 0; i < GetRows(); i++)
		{
			SetRowLabelValue(i, wxString::Format("%d", 1 + i));
		}

		Thaw();
	}
}


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
void trajectory_analysis_table::_Update_Views(void)
{
	if (GetBatchCount() == 0)
	{
		BeginBatch();

		g_pData->Update_Views(m_pTable);

		EndBatch();
	}
}


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
bool trajectory_analysis_table::Update_Table(void)
{
	if (GetBatchCount() > 0)
	{
		return(false);
	}

	BeginBatch();

	//-----------------------------------------------------
	int	Difference = (m_pTable->Get_Field_Count() - m_Field_Offset) - GetNumberCols();

	if (Difference > 0)
	{
		AppendCols(Difference);
	}
	else if ((Difference = -Difference < GetNumberCols() ? -Difference : GetNumberCols()) > 0)
	{	// here is (or was!?) a memory leak - solution: use own wxGridTableBase derived grid table class
		DeleteCols(0, Difference);
	}

	//-----------------------------------------------------
	for (int iCol = 0, iField = m_Field_Offset; iField < m_pTable->Get_Field_Count(); iCol++, iField++)
	{
		SetColLabelValue(iCol, m_pTable->Get_Field_Name(iField));

		switch (m_pTable->Get_Field_Type(iField))
		{
		default:
		case SG_DATATYPE_Byte:
		case SG_DATATYPE_Char:
		case SG_DATATYPE_String:
		case SG_DATATYPE_Date:
		case SG_DATATYPE_Binary:
			SetColFormatCustom(iCol, wxGRID_VALUE_STRING);
			break;

		case SG_DATATYPE_Bit:
		case SG_DATATYPE_Word:
		case SG_DATATYPE_Short:
		case SG_DATATYPE_DWord:
		case SG_DATATYPE_Int:
		case SG_DATATYPE_ULong:
		case SG_DATATYPE_Long:
		case SG_DATATYPE_Color:
			SetColFormatNumber(iCol);
			break;

		case SG_DATATYPE_Float:
		case SG_DATATYPE_Double:
			SetColFormatFloat(iCol);
			break;
		}
	}

	//-----------------------------------------------------
	EndBatch();

	return(_Set_Records());
}

//---------------------------------------------------------
bool trajectory_analysis_table::_Set_Records(bool bSelection_To_Top)
{
	BeginBatch();

	//-----------------------------------------------------
	if (m_bSelOnly && m_pTable->Get_Selection_Count() <= 0)
	{
		m_bSelOnly = false;
	}

	int	Difference, nRecords = m_bSelOnly ? m_pTable->Get_Selection_Count() : m_pTable->Get_Count();

	if ((Difference = nRecords - GetNumberRows()) > 0)
	{
		AppendRows(Difference);
	}
	else if (Difference < 0 && (Difference = -Difference < GetNumberRows() ? -Difference : GetNumberRows()) > 0)
	{
		DeleteRows(0, Difference);
	}

	m_pRecords = (CSG_Table_Record **)SG_Realloc(m_pRecords, nRecords * sizeof(CSG_Table_Record *));

	ClearSelection();

	//-----------------------------------------------------
	if (m_bSelOnly)
	{
		//	#pragma omp parallel for
		for (int iRecord = 0; iRecord < nRecords; iRecord++)
		{
			_Set_Record(iRecord, m_pTable->Get_Selection(iRecord));
		}
	}
	else if (!bSelection_To_Top)
	{
		//	#pragma omp parallel for
		for (int iRecord = 0; iRecord < nRecords; iRecord++)
		{
			_Set_Record(iRecord, m_pTable->Get_Record_byIndex(iRecord));
		}
	}
	else // if( bSelection_To_Top && m_pTable->Get_Selection_Count() > 0 )
	{
		for (int iRecord = 0, iSel = 0, iNoSel = m_pTable->Get_Selection_Count(); iRecord < nRecords && PROGRESSBAR_Set_Position(iRecord, nRecords); iRecord++)
		{
			CSG_Table_Record	*pRecord = m_pTable->Get_Record_byIndex(iRecord);

			if (pRecord->is_Selected())
			{
				_Set_Record(iSel++, pRecord);
			}
			else
			{
				_Set_Record(iNoSel++, pRecord);
			}
		}

		PROCESS_Set_Okay();
	}

	//-----------------------------------------------------
	EndBatch();

	_Update_Views();

	return(true);
}

//---------------------------------------------------------
bool trajectory_analysis_table::_Set_Record(int iRecord, CSG_Table_Record *pRecord)
{
	m_pRecords[iRecord] = pRecord;

	if (m_Field_Offset)
	{
		SetRowLabelValue(iRecord, pRecord->asString(0));
	}

	for (int iCol = 0, iField = m_Field_Offset; iField < m_pTable->Get_Field_Count(); iCol++, iField++)
	{
		switch (m_pTable->Get_Field_Type(iField))
		{
		default:
			SetCellValue(iRecord, iCol, pRecord->is_NoData(iField) ? SG_T("") : pRecord->asString(iField));
			break;

		case SG_DATATYPE_Color:
			SetCellBackgroundColour(iRecord, iCol, Get_Color_asWX(pRecord->asInt(iField)));
			break;
		}
	}

	if (pRecord->is_Selected())
	{
		SelectRow(iRecord, true);
	}

	return(true);
}


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
bool trajectory_analysis_table::Update_Sorting(int iField, int Direction)
{
	if (iField >= 0 && iField < m_pTable->Get_Field_Count())
	{
		switch (Direction)
		{
		default:	m_pTable->Toggle_Index(iField);	break;
		case 0:		m_pTable->Set_Index(iField, TABLE_INDEX_None);	break;
		case 1:		m_pTable->Set_Index(iField, TABLE_INDEX_Ascending);	break;
		case 2:		m_pTable->Set_Index(iField, TABLE_INDEX_Descending);	break;
		}

		return(_Set_Records());
	}

	return(false);
}


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
bool trajectory_analysis_table::Add_Record(void)
{
	if (!FIXED_ROWS && m_pTable->Get_ObjectType() == DATAOBJECT_TYPE_Table)
	{
		AppendRows();

		m_pRecords = (CSG_Table_Record **)SG_Realloc(m_pRecords, GetNumberRows() * sizeof(CSG_Table_Record *));

		_Set_Record(GetNumberRows() - 1, m_pTable->Add_Record());

		return(true);
	}

	return(false);
}

//---------------------------------------------------------
bool trajectory_analysis_table::Ins_Record(void)
{
	if (!FIXED_ROWS && m_pTable->Get_ObjectType() == DATAOBJECT_TYPE_Table)
	{
		int		iRecord = GetGridCursorRow();

		if (iRecord >= 0 && iRecord < GetNumberRows())
		{
			InsertRows(iRecord);

			m_pRecords = (CSG_Table_Record **)SG_Realloc(m_pRecords, GetNumberRows() * sizeof(CSG_Table_Record *));

			for (int i = GetNumberRows() - 1; i>iRecord; i--)
			{
				m_pRecords[i] = m_pRecords[i - 1];
			}

			_Set_Record(iRecord, m_pTable->Ins_Record(iRecord));

			return(true);
		}
	}

	return(false);
}

//---------------------------------------------------------
bool trajectory_analysis_table::Del_Record(void)
{
	return(!FIXED_ROWS && m_pTable->Del_Selection() && Update_Table());
}

//---------------------------------------------------------
bool trajectory_analysis_table::Del_Records(void)
{
	return(!FIXED_ROWS && m_pTable->Del_Records() && Update_Table());
}


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
bool trajectory_analysis_table::Load(const wxString &File_Name)
{
	CSG_Table	Table(&File_Name);

	bool	bResult = Table.Get_Count() > 0
		&& Table.Get_Field_Count() == m_pTable->Get_Field_Count()
		&& m_pTable->Assign_Values(&Table)
		&& Update_Table();

	PROCESS_Set_Okay();

	return(bResult);
}

//---------------------------------------------------------
bool trajectory_analysis_table::Save(const wxString &File_Name, int Format)
{
	bool	bResult = m_pTable->Save(&File_Name);

	PROCESS_Set_Okay();

	return(bResult);
}


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
void trajectory_analysis_table::On_Size(wxSizeEvent &event)//&WXUNUSED(event))
{
	if (m_Field_Offset && GetNumberCols() && GetClientSize().x > GetRowLabelSize())
	{
		SetColSize(0, GetClientSize().x - GetRowLabelSize());
	}

	event.Skip();
}

//---------------------------------------------------------
void trajectory_analysis_table::On_Key(wxKeyEvent &event)
{
	event.Skip(true);

	if (event.GetKeyCode() == WXK_RETURN)
	{
		if (!m_bEditing && GetParent() == g_pACTIVE->Get_Attributes())
		{
			event.Skip(false);

			g_pACTIVE->Get_Attributes()->Save_Changes(false);
		}
	}
}

//---------------------------------------------------------
void trajectory_analysis_table::On_Edit_Start(wxGridEvent &event)
{
	m_bEditing = true;

	event.Skip();
}

//---------------------------------------------------------
void trajectory_analysis_table::On_Edit_Stop(wxGridEvent &event)
{
	m_bEditing = false;

	event.Skip();
}

//---------------------------------------------------------
void trajectory_analysis_table::On_Changed(wxGridEvent &event)
{
	CSG_Table_Record	*pRecord = m_pRecords[event.GetRow()];

	if (pRecord)
	{
		int	iField = m_Field_Offset + event.GetCol();

		if (iField >= m_Field_Offset && iField < m_pTable->Get_Field_Count())
		{
			pRecord->Set_Value(iField, GetCellValue(event.GetRow(), event.GetCol()).wx_str());

			SetCellValue(event.GetRow(), event.GetCol(), pRecord->asString(iField));
		}
	}
}


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
void trajectory_analysis_table::On_Field_Add(wxCommandEvent &event)
{
	int				i;
	CSG_String		sFields;
	CSG_Parameters	P;

	//-----------------------------------------------------
	for (i = 0; i < m_pTable->Get_Field_Count(); i++)
	{
		sFields.Append(m_pTable->Get_Field_Name(i));	sFields.Append(wxT('|'));
	}

	//-----------------------------------------------------
	P.Set_Name(_TL("Add Field"));

	P.Add_String(
		NULL, "NAME", _TL("Name"),
		_TL(""),
		_TL("Field")
		);

	P.Add_Choice(
		NULL, "TYPE", _TL("Field Type"),
		_TL(""),
		CSG_String::Format(SG_T("%s|%s|%s|%s|%s|%s|%s|%s|"),
		_TL("character string"),
		_TL("1 byte integer"),
		_TL("2 byte integer"),
		_TL("4 byte integer"),
		_TL("4 byte floating point"),
		_TL("8 byte floating point"),
		_TL("date (dd.mm.yyyy)"),
		_TL("color (rgb)")
		)
		);

	P.Add_Choice(
		NULL, "FIELD", _TL("Insert Position"),
		_TL(""),
		sFields, m_pTable->Get_Field_Count() - 1
		);

	P.Add_Choice(
		NULL, "INSERT", _TL("Insert Method"),
		_TL(""),
		CSG_String::Format(SG_T("%s|%s|"),
		_TL("before"),
		_TL("after")
		), 1
		);

	//-----------------------------------------------------
	if (DLG_Parameters(&P))
	{
		int				Position;
		TSG_Data_Type	Type;

		switch (P("TYPE")->asInt())
		{
		default:
		case 0:	Type = SG_DATATYPE_String;	break;
		case 1:	Type = SG_DATATYPE_Char;		break;
		case 2:	Type = SG_DATATYPE_Short;	break;
		case 3:	Type = SG_DATATYPE_Int;		break;
		case 4:	Type = SG_DATATYPE_Float;	break;
		case 5:	Type = SG_DATATYPE_Double;	break;
		case 6:	Type = SG_DATATYPE_Date;		break;
		case 7:	Type = SG_DATATYPE_Color;	break;
		}

		Position = P("FIELD")->asInt() + P("INSERT")->asInt();

		m_pTable->Add_Field(P("NAME")->asString(), Type, Position);

		g_pData->Update(m_pTable, NULL);
	}
}

void trajectory_analysis_table::On_Field_Add_UI(wxUpdateUIEvent &event)
{
	event.Enable(FIXED_COLS == false);
}

//---------------------------------------------------------
void trajectory_analysis_table::On_Field_Del(wxCommandEvent &event)
{
	int				i;
	CSG_Parameters	P;

	//-----------------------------------------------------
	P.Set_Name(_TL("Delete Fields"));

	for (i = 0; i < m_pTable->Get_Field_Count(); i++)
	{
		P.Add_Value(NULL, SG_Get_String(i, 0), m_pTable->Get_Field_Name(i), _TL(""), PARAMETER_TYPE_Bool, false);
	}

	//-----------------------------------------------------
	if (DLG_Parameters(&P))
	{
		for (i = m_pTable->Get_Field_Count() - 1; i >= 0; i--)
		{
			if (P(SG_Get_String(i, 0))->asBool())
			{
				m_pTable->Del_Field(i);

				DeleteCols(i);
			}
		}

		g_pData->Update(m_pTable, NULL);
	}
}

void trajectory_analysis_table::On_Field_Del_UI(wxUpdateUIEvent &event)
{
	event.Enable(FIXED_COLS == false);
}

//---------------------------------------------------------
void trajectory_analysis_table::On_Field_Sort(wxCommandEvent &event)
{
	CSG_String		sFields, sOrder;
	CSG_Parameter	*pNode;
	CSG_Parameters	P;

	//-----------------------------------------------------
	for (int i = 0; i < m_pTable->Get_Field_Count(); i++)
	{
		sFields.Append(m_pTable->Get_Field_Name(i));	sFields.Append('|');
	}

	sOrder.Printf(SG_T("%s|%s|%s|"),
		_TL("unsorted"),
		_TL("ascending"),
		_TL("descending")
		);

	//-----------------------------------------------------
	P.Set_Name(_TL("Sort Table"));

	pNode = P.Add_Choice(NULL, "FIELD_1", _TL("Sort first by"), _TL(""), sFields, !m_pTable->is_Indexed() ? 0 : m_pTable->Get_Index_Field(0));
	pNode = P.Add_Choice(pNode, "ORDER_1", _TL("Direction"), _TL(""), sOrder, !m_pTable->is_Indexed() ? 1 : m_pTable->Get_Index_Order(0));

	pNode = P.Add_Choice(NULL, "FIELD_2", _TL("Sort second by"), _TL(""), sFields, !m_pTable->is_Indexed() ? 0 : m_pTable->Get_Index_Field(1));
	pNode = P.Add_Choice(pNode, "ORDER_2", _TL("Direction"), _TL(""), sOrder, !m_pTable->is_Indexed() ? 0 : m_pTable->Get_Index_Order(1));

	pNode = P.Add_Choice(NULL, "FIELD_3", _TL("Sort third by"), _TL(""), sFields, !m_pTable->is_Indexed() ? 0 : m_pTable->Get_Index_Field(2));
	pNode = P.Add_Choice(pNode, "ORDER_3", _TL("Direction"), _TL(""), sOrder, !m_pTable->is_Indexed() ? 0 : m_pTable->Get_Index_Order(2));

	//-----------------------------------------------------
	if (DLG_Parameters(&P))
	{
		m_pTable->Set_Index(
			P("FIELD_1")->asInt(), P("ORDER_1")->asInt() == 1 ? TABLE_INDEX_Ascending : P("ORDER_1")->asInt() == 2 ? TABLE_INDEX_Descending : TABLE_INDEX_None,
			P("FIELD_2")->asInt(), P("ORDER_2")->asInt() == 1 ? TABLE_INDEX_Ascending : P("ORDER_2")->asInt() == 2 ? TABLE_INDEX_Descending : TABLE_INDEX_None,
			P("FIELD_3")->asInt(), P("ORDER_3")->asInt() == 1 ? TABLE_INDEX_Ascending : P("ORDER_3")->asInt() == 2 ? TABLE_INDEX_Descending : TABLE_INDEX_None
			);

		_Set_Records();
	}
}

void trajectory_analysis_table::On_Field_Sort_UI(wxUpdateUIEvent &event)
{
	event.Enable(m_pTable->Get_Field_Count() > 0 && m_pTable->Get_Record_Count() > 1);
}

//---------------------------------------------------------
void trajectory_analysis_table::On_Field_Rename(wxCommandEvent &event)
{
	int				i;
	CSG_Parameters	P;

	P.Set_Name(_TL("Rename Fields"));

	for (i = 0; i < m_pTable->Get_Field_Count(); i++)
	{
		P.Add_String(NULL, "", m_pTable->Get_Field_Name(i), _TL(""), m_pTable->Get_Field_Name(i));
	}

	//-----------------------------------------------------
	if (DLG_Parameters(&P))
	{
		for (i = 0; i<m_pTable->Get_Field_Count(); i++)
		{
			CSG_String	s(P(i)->asString());

			if (s.Length() > 0 && s.Cmp(m_pTable->Get_Field_Name(i)))
			{
				m_pTable->Set_Field_Name(i, s);

				SetColLabelValue(i, s.c_str());
			}
		}

		g_pData->Update(m_pTable, NULL);
	}
}

void trajectory_analysis_table::On_Field_Rename_UI(wxUpdateUIEvent &event)
{
	event.Enable(m_pTable->Get_Field_Count() > 0);
}

//---------------------------------------------------------
void trajectory_analysis_table::On_Field_Type(wxCommandEvent &event)
{
	int				i, *Types = new int[m_pTable->Get_Field_Count()];
	CSG_Parameters	P;

	P.Set_Name(_TL("Change Field Type"));

	for (i = 0; i < m_pTable->Get_Field_Count(); i++)
	{
		switch (m_pTable->Get_Field_Type(i))
		{
		default:
		case SG_DATATYPE_String:	Types[i] = 0;	break;
		case SG_DATATYPE_Char:		Types[i] = 1;	break;
		case SG_DATATYPE_Short:		Types[i] = 2;	break;
		case SG_DATATYPE_Int:		Types[i] = 3;	break;
		case SG_DATATYPE_Float:	    Types[i] = 4;	break;
		case SG_DATATYPE_Double:	Types[i] = 5;	break;
		case SG_DATATYPE_Date:	    Types[i] = 6;	break;
		case SG_DATATYPE_Binary:	Types[i] = 7;	break;
		}

		P.Add_Choice(NULL, "", m_pTable->Get_Field_Name(i), _TL(""),
			CSG_String::Format(SG_T("%s|%s|%s|%s|%s|%s|%s|%s|"),
			_TL("character string"),
			_TL("1 byte integer"),
			_TL("2 byte integer"),
			_TL("4 byte integer"),
			_TL("4 byte floating point"),
			_TL("8 byte floating point"),
			_TL("date (dd.mm.yyyy)"),
			_TL("color (rgb)")
			), Types[i]
			);
	}

	//-----------------------------------------------------
	if (DLG_Parameters(&P))
	{
		bool	bChanged = false;

		for (i = 0; i < m_pTable->Get_Field_Count(); i++)
		{
			TSG_Data_Type	Type;

			switch (P(i)->asInt())
			{
			default:
			case 0:	Type = SG_DATATYPE_String;	break;
			case 1:	Type = SG_DATATYPE_Char;		break;
			case 2:	Type = SG_DATATYPE_Short;	break;
			case 3:	Type = SG_DATATYPE_Int;		break;
			case 4:	Type = SG_DATATYPE_Float;	break;
			case 5:	Type = SG_DATATYPE_Double;	break;
			case 6:	Type = SG_DATATYPE_Date;		break;
			case 7:	Type = SG_DATATYPE_Color;	break;
			}

			if (Type != Types[i])
			{
				m_pTable->Set_Field_Type(i, Type);

				bChanged = true;
			}
		}

		if (bChanged)
		{
			Update_Table();
		}
	}
}

void trajectory_analysis_table::On_Field_Type_UI(wxUpdateUIEvent &event)
{
	event.Enable(m_pTable->Get_Field_Count() > 0);
}


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
void trajectory_analysis_table::On_Record_Add(wxCommandEvent &event)
{
	Add_Record();
}

void trajectory_analysis_table::On_Record_Add_UI(wxUpdateUIEvent &event)
{
	event.Enable(!FIXED_ROWS && m_pTable->Get_ObjectType() == DATAOBJECT_TYPE_Table);
}

//---------------------------------------------------------
void trajectory_analysis_table::On_Record_Ins(wxCommandEvent &event)
{
	Ins_Record();
}

void trajectory_analysis_table::On_Record_Ins_UI(wxUpdateUIEvent &event)
{
	event.Enable(!FIXED_ROWS && m_pTable->Get_ObjectType() == DATAOBJECT_TYPE_Table);
}

//---------------------------------------------------------
void trajectory_analysis_table::On_Record_Del(wxCommandEvent &event)
{
	Del_Record();
}

void trajectory_analysis_table::On_Record_Del_UI(wxUpdateUIEvent &event)
{
	event.Enable(!FIXED_ROWS && m_pTable->Get_Selection_Count() > 0);
}

//---------------------------------------------------------
void trajectory_analysis_table::On_Record_Clr(wxCommandEvent &event)
{
	Del_Records();
}

void trajectory_analysis_table::On_Record_Clr_UI(wxUpdateUIEvent &event)
{
	event.Enable(!FIXED_ROWS);
}


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
void trajectory_analysis_table::On_Sel_To_Top(wxCommandEvent  &event)
{
	if (m_pTable->Get_Selection_Count() > 0)
	{
		_Set_Records(true);
	}
}

void trajectory_analysis_table::On_Sel_To_Top_UI(wxUpdateUIEvent &event)
{
	event.Enable(m_pTable->Get_Selection_Count() > 0);
}

//---------------------------------------------------------
void trajectory_analysis_table::On_Sel_Only(wxCommandEvent  &event)
{
	if (m_pTable->Get_Selection_Count() > 0 && m_pTable->Get_Selection_Count() < GetNumberRows())
	{
		m_bSelOnly = true;

		_Set_Records();
	}
	else if (m_bSelOnly)
	{
		m_bSelOnly = false;

		_Set_Records();
	}
}

void trajectory_analysis_table::On_Sel_Only_UI(wxUpdateUIEvent &event)
{
	event.Check(m_bSelOnly);
}


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
void trajectory_analysis_table::On_Autosize_Cols(wxCommandEvent &event)
{
	AutoSizeColumns(false);
}

//---------------------------------------------------------
void trajectory_analysis_table::On_Autosize_Rows(wxCommandEvent &event)
{
	AutoSizeRows(false);
}


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
void trajectory_analysis_table::On_LClick(wxGridEvent &event)
{
	int					iField = m_Field_Offset + event.GetCol();
	CSG_Table_Record	*pRecord = m_pRecords[event.GetRow()];

	//-----------------------------------------------------
	if (event.ControlDown())
	{
		m_pTable->Select(pRecord, true);

		Update_Selection();
	}

	else if (event.ShiftDown())
	{
		SelectBlock(event.GetRow(), 0, GetGridCursorRow(), GetNumberCols(), false);
	}

	else if (event.AltDown())
	{
		if (m_pTable->Get_Field_Type(iField) == SG_DATATYPE_String)
		{
			Open_Application(pRecord->asString(iField));
		}
	}

	else
	{
		SelectRow(event.GetRow(), false);

		if (pRecord && iField >= m_Field_Offset && iField < m_pTable->Get_Field_Count() && m_pTable->Get_Field_Type(iField) == SG_DATATYPE_Color)
		{
			long	lValue;

			if (DLG_Color(lValue = pRecord->asInt(iField)))
			{
				pRecord->Set_Value(iField, lValue);

				SetCellBackgroundColour(event.GetRow(), event.GetCol(), Get_Color_asWX(pRecord->asInt(iField)));

				ForceRefresh();
			}
		}
	}

	//-----------------------------------------------------
	SetGridCursor(event.GetRow(), event.GetCol());
}


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
void trajectory_analysis_table::On_LClick_Label(wxGridEvent &event)
{
	if (event.GetCol() >= 0)
	{
		SetGridCursor(GetGridCursorRow(), event.GetCol());
	}
	else if (event.GetRow() >= 0)
	{
		SetGridCursor(event.GetRow(), GetGridCursorCol());
	}
	else
	{
		//	SelectAll();
	}
}

//---------------------------------------------------------
void trajectory_analysis_table::On_RClick_Label(wxGridEvent &event)
{
	wxMenu	Menu;

	//-----------------------------------------------------
	if (event.GetCol() != -1)
	{
		Menu.SetTitle(wxString::Format(wxT("%s"), _TL("Columns")));

		CMD_Menu_Add_Item(&Menu, false, ID_CMD_TABLE_FIELD_ADD);
		CMD_Menu_Add_Item(&Menu, false, ID_CMD_TABLE_FIELD_DEL);

		Menu.AppendSeparator();
		CMD_Menu_Add_Item(&Menu, false, ID_CMD_TABLE_AUTOSIZE_COLS);
		CMD_Menu_Add_Item(&Menu, false, ID_CMD_TABLE_FIELD_SORT);
		CMD_Menu_Add_Item(&Menu, false, ID_CMD_TABLE_FIELD_RENAME);
		CMD_Menu_Add_Item(&Menu, false, ID_CMD_TABLE_FIELD_TYPE);

		PopupMenu(&Menu, event.GetPosition().x, event.GetPosition().y - GetColLabelSize());
	}

	//-----------------------------------------------------
	else if (event.GetRow() != -1)
	{
		Menu.SetTitle(wxString::Format(wxT("%s"), _TL("Rows")));

		CMD_Menu_Add_Item(&Menu, false, ID_CMD_TABLE_RECORD_ADD);
		CMD_Menu_Add_Item(&Menu, false, ID_CMD_TABLE_RECORD_INS);
		CMD_Menu_Add_Item(&Menu, false, ID_CMD_TABLE_RECORD_DEL);
		CMD_Menu_Add_Item(&Menu, false, ID_CMD_TABLE_RECORD_DEL_ALL);

		Menu.AppendSeparator();
		CMD_Menu_Add_Item(&Menu, false, ID_CMD_TABLE_AUTOSIZE_ROWS);

		if (!FIXED_ROWS)
		{
			Menu.AppendSeparator();
			CMD_Menu_Add_Item(&Menu, false, ID_CMD_TABLE_SELECTION_TO_TOP);
			CMD_Menu_Add_Item(&Menu, true, ID_CMD_TABLE_SELECTION_ONLY);
		}

		PopupMenu(&Menu, event.GetPosition().x - GetRowLabelSize(), event.GetPosition().y);
	}

	//-----------------------------------------------------
	else
	{
		ClearSelection();
	}
}

//---------------------------------------------------------
void trajectory_analysis_table::On_LDClick_Label(wxGridEvent &event)
{
	Update_Sorting(event.GetCol(), -1);
}


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
bool trajectory_analysis_table::Update_Selection(void)
{
	if (GetBatchCount() == 0)
	{
		BeginBatch();

		if (m_pTable->Get_Selection_Count() >= m_pTable->Get_Count())
		{
			SelectAll();
		}
		else
		{
			ClearSelection();

			if (m_pTable->Get_Selection_Count() > 0)
			{
#pragma omp parallel for
				for (int iRecord = 0; iRecord < GetNumberRows(); iRecord++)
				{
					if (m_pRecords[iRecord]->is_Selected())
					{
						SelectRow(iRecord, true);
					}
				}
			}
		}

		EndBatch();

		_Update_Views();

		return(true);
	}

	return(false);
}

//---------------------------------------------------------
void trajectory_analysis_table::On_Select(wxGridRangeSelectEvent &event)
{
	if (GetBatchCount() == 0)
	{
		BeginBatch();

		for (int iRow = event.GetTopRow(); iRow <= event.GetBottomRow(); iRow++)
		{
			if (m_pRecords[iRow]->is_Selected() != event.Selecting())
			{
				m_pTable->Select(m_pRecords[iRow], true);
			}
		}

		EndBatch();

		_Update_Views();
	}

	event.Skip();
}


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
