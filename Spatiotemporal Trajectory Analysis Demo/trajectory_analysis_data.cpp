///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
#include <wx/wxprec.h>

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#include <wx/settings.h>
#include <wx/dc.h>
#include <wx/dcclient.h>

#include <causta_api/causta_api.h>

//---------------------------------------------------------
#include "trajectory_analysis_data.h"
#include "trajectory_analysis_dialog.h"


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
#define m_Settings	(*m_pSettings)


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
BEGIN_EVENT_TABLE(Ctrajectory_analysis_data, CSGDI_Dialog)
END_EVENT_TABLE()


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
Ctrajectory_analysis_data::Ctrajectory_analysis_data()
: CSGDI_Dialog(_TL("Trajectory Data"))
{
	Sequence = "";

	m_bitmap = _Draw_Sequence(DrwaSqe);

	x = 0.0;

	this->SetSize(400, 300);

	SetWindowStyle(wxDEFAULT_FRAME_STYLE | wxNO_FULL_REPAINT_ON_RESIZE);

	bSizer1 = new wxBoxSizer(wxVERTICAL);
	bSizer2 = new wxBoxSizer(wxVERTICAL);
	bSizer3 = new wxBoxSizer(wxVERTICAL);
	bSizer4 = new wxBoxSizer(wxVERTICAL);

	m_sText1 = new wxStaticText(this, wxID_ANY, wxT("Sensor Point Selection"), wxDefaultPosition, wxDefaultSize, 0);
	m_sText1->Wrap(-1);
	bSizer1->Add(m_sText1, 0, wxALL, 5);
	m_combo = new wxComboBox(this, wxID_ANY, wxT("SensorID"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
	m_combo->Append(_TL("361"));
	m_combo->Append(_TL("359"));
	m_combo->Append(_TL("331"));
	m_combo->Append(_TL("324"));
	m_combo->SetSelection(0);
	bSizer1->Add(m_combo, 0, wxALL | wxEXPAND, 5);
	bSizer4->Add(bSizer1, 1, wxEXPAND, 5);

	m_sText2 = new wxStaticText(this, wxID_ANY, wxT("Response Sequence List"), wxDefaultPosition, wxDefaultSize, 0);
	m_sText2->Wrap(-1);
	bSizer2->Add(m_sText2, 0, wxALL, 5);
	m_textCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	m_textCtrl->SetValue(Sequence);
	bSizer2->Add(m_textCtrl, 1, wxALL | wxEXPAND, 5);
	bSizer4->Add(bSizer2, 1, wxEXPAND, 5);

	m_sText3 = new wxStaticText(this, wxID_ANY, wxT("All Data Show With Time"), wxDefaultPosition, wxDefaultSize, 0);
	m_sText3->Wrap(-1);
	bSizer3->Add(m_sText3, 0, wxALL, 5);
	m_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	bSizer3->Add(m_panel, 1, wxEXPAND | wxALL, 5);
	bSizer4->Add(bSizer3, 1, wxEXPAND, 5);

	this->SetSizer(bSizer4);
	this->Layout();

	this->Centre(wxBOTH);
}

///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------

void Ctrajectory_analysis_data::Update_View()
{
	if ( DrwaSqe.size()%374 == 0 )
	{
		DrwaSqe.clear();
		x = 0;
	}
	wxClientDC	dc(m_panel);
	wxBitmap bt(m_bitmap.GetSize().GetWidth(), m_bitmap.GetSize().GetHeight());
	m_bitmap = _Draw_Sequence(DrwaSqe);
	wxMemoryDC mdc;
	mdc.SelectObject(bt);
	mdc.DrawBitmap(m_bitmap,wxDefaultPosition);
	mdc.SetPen(*wxRED_PEN);
	mdc.DrawLine(wxPoint(x, 0), wxPoint(x, 50));
	mdc.SelectObject(wxNullBitmap);
	dc.DrawBitmap(bt, 0, 0, false);
}

///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
void Ctrajectory_analysis_data::Update_Sequence(wxString Sequence)
{
	m_textCtrl->SetValue(Sequence);
}

//---------------------------------------------------------
PGconn* Ctrajectory_analysis_data::ConnectionToDB(PGconn *conn, char *pghost, char *pgport, char *dbname, char *user, char *pwd)
{
	char *pgoptions, *pgtty;
	pgoptions = NULL;
	pgtty = NULL;
	conn = PQsetdbLogin(pghost, pgport, pgoptions, pgtty, dbname, user, pwd);
	if (PQstatus(conn) == CONNECTION_BAD)
	{
		MessageBox(NULL, TEXT("Connection is error"),
			TEXT("Error"),
			MB_OK);
		return NULL;
	}
	else
	{
		return conn;
	}
}

//---------------------------------------------------------
PGresult* Ctrajectory_analysis_data::Query(CSG_String sql)
{
	PGresult *res;
	conn = ConnectionToDB(conn, pghost, pgport, dbname, user, pwd);
	if (conn != NULL)
	{
		res = PQexec(conn, sql);
		PQfinish(conn);
		return res;
	}
	else
	{
		return NULL;
	}
}

//---------------------------------------------------------
wxBitmap Ctrajectory_analysis_data::_Draw_Sequence(vector<int> dSqe)
{
	wxBitmap bt(374,48);
	wxMemoryDC mdc;
	mdc.SelectObject(bt);

	for (int i = 0; i < 374; i++)
	{
		if (i < dSqe.size())
		{
			if (dSqe[i] == 1)
			{
				for (int j = 0; j < 48; j++)
				{
					mdc.SetPen(*wxWHITE_PEN);
					mdc.DrawPoint(i, j);
				}
			}
		}
	}

	mdc.SelectObject(wxNullBitmap);

	return bt;
}