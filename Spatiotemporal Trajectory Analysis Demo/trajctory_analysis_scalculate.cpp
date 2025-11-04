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
#include "trajctory_analysis_scalculate.h"


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
BEGIN_EVENT_TABLE(Ctrajectory_analysis_scalculate, CSGDI_Dialog)
END_EVENT_TABLE()


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
Ctrajectory_analysis_scalculate::Ctrajectory_analysis_scalculate()
: CSGDI_Dialog(_TL("Semantics Extraction Interface"))
{
	this->SetSize(620, 440);

	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer(wxVERTICAL);

	m_sText1 = new wxStaticText(this, wxID_ANY, wxT("Node List"), wxDefaultPosition, wxDefaultSize, 0);
	m_sText1->Wrap(-1);
	bSizer4->Add(m_sText1, 0, wxALL, 5);

	m_comboBox1 = new wxComboBox(this, wxID_ANY, wxT("Sensor ID Select"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
	m_comboBox1->Append(_TL("359"));
	m_comboBox1->Append(_TL("361"));
	m_comboBox1->Append(_TL("330"));
	m_comboBox1->Append(_TL("315"));
	m_comboBox1->Append(_TL("310"));
	m_comboBox1->Append(_TL("331"));
	m_comboBox1->Append(_TL("449"));
	m_comboBox1->Append(_TL("327"));
	m_comboBox1->SetSelection(1);
	bSizer4->Add(m_comboBox1, 0, wxALL | wxEXPAND, 5);

	m_sline1 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	bSizer4->Add(m_sline1, 0, wxEXPAND | wxALL, 5);

	m_sText2 = new wxStaticText(this, wxID_ANY, wxT("Five Neighborhood"), wxDefaultPosition, wxDefaultSize, 0);
	m_sText2->Wrap(-1);
	bSizer4->Add(m_sText2, 0, wxALL, 5);

	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer(wxVERTICAL);

	m_sText6 = new wxStaticText(this, wxID_ANY, wxT("Upper"), wxDefaultPosition, wxDefaultSize, 0);
	m_sText6->Wrap(-1);
	bSizer25->Add(m_sText6, 0, wxALL, 5);

	m_panel1 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	bSizer25->Add(m_panel1, 1, wxEXPAND | wxALL, 5);

	m_sText7 = new wxStaticText(this, wxID_ANY, wxT("Left"), wxDefaultPosition, wxDefaultSize, 0);
	m_sText7->Wrap(-1);
	bSizer25->Add(m_sText7, 0, wxALL, 5);


	bSizer28->Add(bSizer25, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer(wxVERTICAL);

	m_panel2 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	bSizer26->Add(m_panel2, 1, wxEXPAND | wxALL, 5);

	m_panel3 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	bSizer26->Add(m_panel3, 1, wxEXPAND | wxALL, 5);

	m_panel4 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	bSizer26->Add(m_panel4, 1, wxEXPAND | wxALL, 5);


	bSizer28->Add(bSizer26, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer(wxVERTICAL);

	m_sText8 = new wxStaticText(this, wxID_ANY, wxT("Right"), wxDefaultPosition, wxDefaultSize, 0);
	m_sText8->Wrap(-1);
	bSizer27->Add(m_sText8, 0, wxALIGN_RIGHT | wxALL, 5);

	m_panel5 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	bSizer27->Add(m_panel5, 1, wxEXPAND | wxALL, 5);

	m_sText9 = new wxStaticText(this, wxID_ANY, wxT("Down"), wxDefaultPosition, wxDefaultSize, 0);
	m_sText9->Wrap(-1);
	bSizer27->Add(m_sText9, 0, wxALIGN_RIGHT | wxALL, 5);


	bSizer28->Add(bSizer27, 1, wxEXPAND, 5);


	bSizer4->Add(bSizer28, 1, wxEXPAND, 5);


	bSizer2->Add(bSizer4, 1, wxEXPAND, 5);

	m_sline4 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL);
	bSizer2->Add(m_sline4, 0, wxALL | wxEXPAND | wxALIGN_CENTER_VERTICAL, 5);

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer(wxVERTICAL);

	m_sText3 = new wxStaticText(this, wxID_ANY, wxT("Time Window"), wxDefaultPosition, wxDefaultSize, 0);
	m_sText3->Wrap(-1);
	bSizer7->Add(m_sText3, 0, wxALL, 5);

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer(wxHORIZONTAL);

	m_comboBox2 = new wxComboBox(this, wxID_ANY, wxT("Time Select"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
	m_comboBox2->Append(_TL("2006.3.27 7:50 -- 23:50"));
	m_comboBox2->Append(_TL("2006.3.28 7:50 -- 23:50"));
	m_comboBox2->Append(_TL("2006.3.29 7:50 -- 23:50"));
	m_comboBox2->Append(_TL("2006.3.30 7:50 -- 23:50"));
	m_comboBox2->SetSelection(2);
	bSizer10->Add(m_comboBox2, 1, wxALL | wxEXPAND, 5);

	m_statictext = new wxStaticText(this, wxID_ANY, wxT("time lable"), wxDefaultPosition, wxDefaultSize, 0);
	m_statictext->Wrap(-1);
	bSizer10->Add(m_statictext, 0, wxALIGN_CENTER_VERTICAL | wxALIGN_RIGHT | wxALL, 5);

	bSizer7->Add(bSizer10, 0, wxEXPAND, 5);

	m_sline2 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	bSizer7->Add(m_sline2, 0, wxEXPAND | wxALL, 5);


	m_panel6 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	bSizer7->Add(m_panel6, 1, wxEXPAND | wxALL, 5);

	m_slider1 = new wxSlider(this, wxID_ANY, 0, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bSizer7->Add(m_slider1, 0, wxALL | wxEXPAND, 5);

	bSizer5->Add(bSizer7, 1, wxEXPAND, 5);


	bSizer2->Add(bSizer5, 1, wxEXPAND, 5);


	bSizer1->Add(bSizer2, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer(wxVERTICAL);

	m_sline3 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	bSizer3->Add(m_sline3, 0, wxEXPAND | wxRIGHT | wxLEFT, 5);

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer(wxVERTICAL);

	m_sText4 = new wxStaticText(this, wxID_ANY, wxT("Semantic encoding"), wxDefaultPosition, wxDefaultSize, 0);
	m_sText4->Wrap(-1);
	bSizer8->Add(m_sText4, 0, wxALL, 5);

	m_listBox1 = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
	bSizer8->Add(m_listBox1, 1, wxALL | wxEXPAND, 5);


	bSizer6->Add(bSizer8, 1, wxEXPAND, 5);

	m_bpButton = new wxBitmapButton(this, wxID_ANY, wxBitmap(wxT("G:\\CAUSTA_NEW\\src\\src\\STEngine\\arrow.bmp"), wxBITMAP_TYPE_ANY), wxDefaultPosition, wxSize(30, 30), wxBU_AUTODRAW);
	bSizer6->Add(m_bpButton, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer(wxVERTICAL);

	m_sText5 = new wxStaticText(this, wxID_ANY, wxT("Motion Semantics"), wxDefaultPosition, wxDefaultSize, 0);
	m_sText5->Wrap(-1);
	bSizer9->Add(m_sText5, 0, wxALL, 5);

	m_listBox2 = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
	bSizer9->Add(m_listBox2, 1, wxALL | wxEXPAND, 5);


	bSizer6->Add(bSizer9, 1, wxEXPAND | wxALIGN_CENTER_VERTICAL, 5);


	bSizer3->Add(bSizer6, 1, wxEXPAND, 5);


	bSizer1->Add(bSizer3, 1, wxEXPAND, 5);


	this->SetSizer(bSizer1);
	this->Layout();

	this->Centre(wxBOTH);

	//-----------------------------------------------------
	conn = NULL;
	Pres = NULL;
	Ares = NULL;
	pghost = "localhost";
	pgport = "5432";
	dbname = "sensordb";
	user = "postgres";
	pwd = "121421";

	//-----------------------------------------------------
	CSG_String sql = "select startime from fireday order by startime limit 1";
	PGresult* restime = Query(sql);
	startime = atoll(PQgetvalue(restime, 0, 0));
	m_bitmap = DrawMatrix(startime);
}


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
void Ctrajectory_analysis_scalculate::Update_View()
{
	count++;
	if ( count%283 == 0 )
	{
		startime = startime + 283 * 1000;
		m_bitmap = DrawMatrix(startime);
		x = 0;
		y = 0;
	}
	wxClientDC	dc(m_panel6);
	wxBitmap bt(m_bitmap.GetSize().GetWidth(), m_bitmap.GetSize().GetHeight());
	wxMemoryDC mdc;
	mdc.SelectObject(bt);
	mdc.DrawBitmap(m_bitmap, wxDefaultPosition);
	mdc.SetPen(*wxWHITE_PEN);
	wxBrush brush(wxColour(10, 10, 10), wxTRANSPARENT);
	mdc.SetBrush(brush);
	mdc.DrawRectangle(x, y, 3, m_bitmap.GetSize().GetHeight());
	mdc.SelectObject(wxNullBitmap);
	dc.DrawBitmap(bt, 0, 0, false);
}

//---------------------------------------------------------
void Ctrajectory_analysis_scalculate::Update_Neighborhood(int selectID, vector<int> sID)
{
	wxClientDC	dcl(m_panel1);
	wxClientDC	dcu(m_panel2);
	wxClientDC	dcc(m_panel3);
	wxClientDC	dcd(m_panel4);
	wxClientDC	dcr(m_panel5);

	wxBitmap bitmapG(m_panel2->GetSize().GetWidth(), m_panel2->GetSize().GetHeight());
	wxBitmap bitmapR(m_panel2->GetSize().GetWidth(), m_panel2->GetSize().GetHeight());
	wxMemoryDC mdc;

	mdc.SelectObject(bitmapR);
	mdc.DrawBitmap(bitmapR, wxDefaultPosition);
	mdc.SetBackground(*wxWHITE_BRUSH);
	mdc.Clear();
	mdc.SetPen(*wxBLACK_PEN);
	mdc.SetBrush(*wxRED_BRUSH);
	mdc.DrawRectangle(m_panel2->GetSize().GetWidth() / 10, m_panel2->GetSize().GetHeight() / 10, m_panel2->GetSize().GetWidth() * 4 / 5, m_panel2->GetSize().GetWidth() * 4 / 5);
	mdc.SelectObject(wxNullBitmap);

	mdc.SelectObject(bitmapG);
	mdc.DrawBitmap(bitmapG, wxDefaultPosition);
	mdc.SetBackground(*wxWHITE_BRUSH);
	mdc.Clear();
	mdc.SetPen(*wxBLACK_PEN);
	mdc.SetBrush(*wxGREEN);
	mdc.DrawRectangle(m_panel2->GetSize().GetWidth() / 10, m_panel2->GetSize().GetHeight() / 10, m_panel2->GetSize().GetWidth() * 4 / 5, m_panel2->GetSize().GetWidth() * 4 / 5);
	mdc.SelectObject(wxNullBitmap);

	if ( sID.size() == 0 )
	{ 
		dcl.DrawBitmap(bitmapR, 0, 0, false);
		dcu.DrawBitmap(bitmapR, 0, 0, false);
		dcc.DrawBitmap(bitmapR, 0, 0, false);
		dcd.DrawBitmap(bitmapR, 0, 0, false);
		dcr.DrawBitmap(bitmapR, 0, 0, false);
	}
	else
	{
		dcl.DrawBitmap(bitmapR, 0, 0, false);
		dcu.DrawBitmap(bitmapR, 0, 0, false);
		dcc.DrawBitmap(bitmapR, 0, 0, false);
		dcd.DrawBitmap(bitmapR, 0, 0, false);
		dcr.DrawBitmap(bitmapR, 0, 0, false);
		for each (int id in sID)
		{
			switch (id)
			{
			case 0:
				dcc.DrawBitmap(bitmapG, 0, 0, false);
				break;
			case 1:
				dcu.DrawBitmap(bitmapG, 0, 0, false);
				break;
			case 2:
				dcl.DrawBitmap(bitmapG, 0, 0, false);
				break;
			case 3:
				dcd.DrawBitmap(bitmapG, 0, 0, false);
				break;
			case 4:
				dcr.DrawBitmap(bitmapG, 0, 0, false);
				break;
			}
		}
	}
	
}

//---------------------------------------------------------
void Ctrajectory_analysis_scalculate::Update_Semantics(int selectID, long long startime, long long endtime)
{
	vector<Node> preque;
	vector<Node> aftque;
	CSG_String sql= "select id, startime, endtime from fireday where startime > " + CSG_String::Format("%lld", (startime - 3000)) +
		
    " and " + "startime < " + CSG_String::Format("%lld", startime);
	Pres = Query(sql);

	sql = "select id, startime, endtime from fireday where endtime < " + CSG_String::Format("%lld", (endtime + 3000)) +

		" and " + "endtime > " + CSG_String::Format("%lld", endtime);
	Ares = Query(sql);

	sql = "select * from linyu where cid = " + CSG_String::Format("%d", selectID);
	Lres = Query(sql);

	Node tNode = Node();

	for (int i = 0; i < PQntuples(Lres); i++)
	{
		for (int j = 0; j < PQntuples(Pres); j++)
		{
			if (atoi(PQgetvalue(Pres, j, 0)) == atoi(PQgetvalue(Lres, i, 0)))
			{
				tNode.sid = atoi(PQgetvalue(Lres, i, 0));
				tNode.direction = 0;
				preque.push_back(tNode);
			}
			if (atoi(PQgetvalue(Pres, j, 0)) == atoi(PQgetvalue(Lres, i, 1)))
			{
				tNode.sid = atoi(PQgetvalue(Lres, i, 1));
				tNode.direction = 1;
				preque.push_back(tNode);
			}
			if (atoi(PQgetvalue(Pres, j, 0)) == atoi(PQgetvalue(Lres, i, 2)))
			{
				tNode.sid = atoi(PQgetvalue(Lres, i, 2));
				tNode.direction = 2;
				preque.push_back(tNode);
			}
			if (atoi(PQgetvalue(Pres, j, 0)) == atoi(PQgetvalue(Lres, i, 3)))
			{
				tNode.sid = atoi(PQgetvalue(Lres, i, 3));
				tNode.direction = 3;
				preque.push_back(tNode);
			}
			if (atoi(PQgetvalue(Pres, j, 0)) == atoi(PQgetvalue(Lres, i, 4)))
			{
				tNode.sid = atoi(PQgetvalue(Lres, i, 4));
				tNode.direction = 4;
				preque.push_back(tNode);
			}
		}

		for (int j = 0; j < PQntuples(Ares); j++)
		{
			if (atoi(PQgetvalue(Ares, j, 0)) == atoi(PQgetvalue(Lres, i, 0)))
			{
				tNode.sid = atoi(PQgetvalue(Lres, i, 0));
				tNode.direction = 0;
				aftque.push_back(tNode);
			}
			if (atoi(PQgetvalue(Ares, j, 0)) == atoi(PQgetvalue(Lres, i, 1)))
			{
				tNode.sid = atoi(PQgetvalue(Lres, i, 1));
				tNode.direction = 1;
				aftque.push_back(tNode);
			}
			if (atoi(PQgetvalue(Ares, j, 0)) == atoi(PQgetvalue(Lres, i, 2)))
			{
				tNode.sid = atoi(PQgetvalue(Lres, i, 2));
				tNode.direction = 2;
				aftque.push_back(tNode);
			}
			if (atoi(PQgetvalue(Ares, j, 0)) == atoi(PQgetvalue(Lres, i, 3)))
			{
				tNode.sid = atoi(PQgetvalue(Lres, i, 3));
				tNode.direction = 3;
				aftque.push_back(tNode);
			}
			if (atoi(PQgetvalue(Ares, j, 0)) == atoi(PQgetvalue(Lres, i, 4)))
			{
				tNode.sid = atoi(PQgetvalue(Lres, i, 4));
				tNode.direction = 4;
				aftque.push_back(tNode);
			}
		}
	}

	Set_Semantics(selectID, preque, aftque);
}

//---------------------------------------------------------
void Ctrajectory_analysis_scalculate::Set_Semantics(int selectID, vector<Node> preque, vector<Node> aftque)
{
	vector<int> r_ID;
	vector<Code> tmeanings;
	vector<Node>::iterator it;
	Code tcode = Code();

	for (it = preque.begin(); it != preque.end();)
	{
		if (it->sid == selectID)
			it = preque.erase(it);
		else
	       ++it;    
    }

	for (it = aftque.begin(); it != aftque.end();)
	{
		if (it->sid == selectID)
			it = aftque.erase(it);
		else
			++it;
	}


	if (preque.size() == 1 && aftque.size() == 0)
	{
		for each (Node tmp in preque)
		{
			switch (tmp.direction)
			{
			case 1:
				r_ID.push_back(0);
				r_ID.push_back(1);
				tcode.code = "eU-eC";
				tcode.mean = "����";
				tmeanings.push_back(tcode);
				break;
			case 2:
				r_ID.push_back(0);
				r_ID.push_back(2);
				tcode.code = "eL-eC";
				tcode.mean = "����";
				tmeanings.push_back(tcode);
				break;
			case 3:
				r_ID.push_back(0);
				r_ID.push_back(3);
				tcode.code = "eD-eC";
				tcode.mean = "����";
				tmeanings.push_back(tcode);
				break;
			case 4:
				r_ID.push_back(0);
				r_ID.push_back(4);
				tcode.code = "eR-eC";
				tcode.mean = "����";
				tmeanings.push_back(tcode);
				break;
			}
		}
	}
	else if (preque.size() == 0 && aftque.size() == 1)
	{
		for each (Node tmp in aftque)
		{
			switch (tmp.direction)
			{
			case 1:
				r_ID.push_back(0);
				r_ID.push_back(1);
				tcode.code = "eC-eU";
				tcode.mean = "�뿪";
				tmeanings.push_back(tcode);
				break;
			case 2:
				r_ID.push_back(0);
				r_ID.push_back(2);
				tcode.code = "eC-eL";
				tcode.mean = "�뿪";
				tmeanings.push_back(tcode);
				break;
			case 3:
				r_ID.push_back(0);
				r_ID.push_back(3);
				tcode.code = "eC-eD";
				tcode.mean = "�뿪";
				tmeanings.push_back(tcode);
				break;
			case 4:
				r_ID.push_back(0);
				r_ID.push_back(4);
				tcode.code = "eC-eR";
				tcode.mean = "�뿪";
				tmeanings.push_back(tcode);
				break;
			}
		}
	}
	else if (preque.size() > 1 && aftque.size() == 0)
	{
		for each (Node tmp in preque)
		{
			switch (tmp.direction)
			{
			case 1:
				r_ID.push_back(0);
				r_ID.push_back(1);
				tcode.code += "eU-eC ";
				tcode.mean = "�ۺ�";
				tmeanings.push_back(tcode);
				break;
			case 2:
				r_ID.push_back(0);
				r_ID.push_back(2);
				tcode.code += "eL-eC ";
				tcode.mean = "�ۺ�";
				tmeanings.push_back(tcode);
				break;
			case 3:
				r_ID.push_back(0);
				r_ID.push_back(3);
				tcode.code += "eD-eC ";
				tcode.mean = "�ۺ�";
				tmeanings.push_back(tcode);
				break;
			case 4:
				r_ID.push_back(0);
				r_ID.push_back(4);
				tcode.code += "eR-eC ";
				tcode.mean = "�ۺ�";
				tmeanings.push_back(tcode);
				break;
			}
		}
	}
	else if (preque.size() == 0 && aftque.size() > 1)
	{
		for each (Node tmp in aftque)
		{
			switch (tmp.direction)
			{
			case 1:
				r_ID.push_back(0);
				r_ID.push_back(1);
				tcode.code += "eC-eU ";
				tcode.mean = "����";
				tmeanings.push_back(tcode);
				break;
			case 2:
				r_ID.push_back(0);
				r_ID.push_back(2);
				tcode.code += "eC-eL ";
				tcode.mean = "����";
				tmeanings.push_back(tcode);
				break;
			case 3:
				r_ID.push_back(0);
				r_ID.push_back(3);
				tcode.code += "eC-eD ";
				tcode.mean = "����";
				tmeanings.push_back(tcode);
				break;
			case 4:
				r_ID.push_back(0);
				r_ID.push_back(4);
				tcode.code += "eC-eR ";
				tcode.mean = "����";
				tmeanings.push_back(tcode);
				break;
			}
		}
	}

	else if (preque.size() == 1 && aftque.size() == 1)
	{
		if (preque[0].direction == 1 && aftque[0].direction == 4)
		{
			r_ID.push_back(0);
			r_ID.push_back(1);
			r_ID.push_back(4);
			tcode.code = "eU-eC-eR";
			tcode.mean = "����ת��";
			tmeanings.push_back(tcode);
		}
		if (preque[0].direction == 1 && aftque[0].direction == 2)
		{
			r_ID.push_back(0);
			r_ID.push_back(1);
			r_ID.push_back(2);
			tcode.code = "eU-eC-eL";
			tcode.mean = "����ת��";
			tmeanings.push_back(tcode);
		}
		if (preque[0].direction == 3 && aftque[0].direction == 4)
		{
			r_ID.push_back(0);
			r_ID.push_back(3);
			r_ID.push_back(4);
			tcode.code = "eD-eC-eR";
			tcode.mean = "����ת��";
			tmeanings.push_back(tcode);
		}
		if (preque[0].direction == 3 && aftque[0].direction == 2)
		{
			r_ID.push_back(0);
			r_ID.push_back(3);
			r_ID.push_back(2);
			tcode.code = "eD-eC-eL";
			tcode.mean = "����ת��";
			tmeanings.push_back(tcode);
		}
		if (preque[0].direction == 4 && aftque[0].direction == 3)
		{
			r_ID.push_back(0);
			r_ID.push_back(4);
			r_ID.push_back(3);
			tcode.code = "eR-eC-eD";
			tcode.mean = "����ת��";
			tmeanings.push_back(tcode);
		}
		if (preque[0].direction == 4 && aftque[0].direction == 1)
		{
			r_ID.push_back(0);
			r_ID.push_back(4);
			r_ID.push_back(1);
			tcode.code = "eR-eC-eU";
			tcode.mean = "����ת��";
			tmeanings.push_back(tcode);
		}
		if (preque[0].direction == 2 && aftque[0].direction == 3)
		{
			r_ID.push_back(0);
			r_ID.push_back(2);
			r_ID.push_back(3);
			tcode.code = "eL-eC-eD";
			tcode.mean = "����ת��";
			tmeanings.push_back(tcode);
		}
		if (preque[0].direction == 2 && aftque[0].direction == 1)
		{
			r_ID.push_back(0);
			r_ID.push_back(2);
			r_ID.push_back(1);
			tcode.code = "eL-eC-eU";
			tcode.mean = "����ת��";
			tmeanings.push_back(tcode);
		}
		if (preque[0].direction == 3 && aftque[0].direction == 1)
		{
			r_ID.push_back(0);
			r_ID.push_back(3);
			r_ID.push_back(1);
			tcode.code = "eD-eC-eU";
			tcode.mean = "���ϴ�Խ";
			tmeanings.push_back(tcode);
		}
		if (preque[0].direction == 1 && aftque[0].direction == 3)
		{
			r_ID.push_back(0);
			r_ID.push_back(1);
			r_ID.push_back(3);
			tcode.code = "eU-eC-eD";
			tcode.mean = "���´�Խ";
			tmeanings.push_back(tcode);
		}
		if (preque[0].direction == 2 && aftque[0].direction == 4)
		{
			r_ID.push_back(0);
			r_ID.push_back(2);
			r_ID.push_back(4);
			tcode.code = "eL-eC-eR";
			tcode.mean = "���Ҵ�Խ";
			tmeanings.push_back(tcode);
		}
		if (preque[0].direction == 4 && aftque[0].direction == 2)
		{
			r_ID.push_back(0);
			r_ID.push_back(4);
			r_ID.push_back(2);
			tcode.code = "eR-eC-eL";
			tcode.mean = "����Խ";
			tmeanings.push_back(tcode);
		}

		if (preque[0].direction == aftque[0].direction )
		{
			r_ID.push_back(preque[0].direction);
			r_ID.push_back(0);
			switch (preque[0].direction)
			{
			case 1:
				tcode.code = "eU-eC-eU";
				tcode.mean = "����";
				tmeanings.push_back(tcode);
				break;
			case 2:
				tcode.code = "eL-eC-eL";
				tcode.mean = "����";
				tmeanings.push_back(tcode);
				break;
			case 3:
				tcode.code = "eD-eC-eD";
				tcode.mean = "����";
				tmeanings.push_back(tcode);
				break;
			case 4:
				tcode.code = "eR-eC-eR";
				tcode.mean = "����";
				tmeanings.push_back(tcode);
				break;
			}
		}
	}
	else
	{
		if (preque.size() > 1 && aftque.size() == 1 && aftque[0].sid == selectID)
		{
			for each (Node tmp in preque)
			{
				switch (tmp.direction)
				{
				case 1:
					r_ID.push_back(0);
					r_ID.push_back(1);
					tcode.code += "eU-eC ";
					tcode.mean = "�ۺ�";
					tmeanings.push_back(tcode);
					break;
				case 2:
					r_ID.push_back(0);
					r_ID.push_back(2);
					tcode.code += "eL-eC ";
					tcode.mean = "�ۺ�";
					tmeanings.push_back(tcode);
					break;
				case 3:
					r_ID.push_back(0);
					r_ID.push_back(3);
					tcode.code += "eD-eC ";
					tcode.mean = "�ۺ�";
					tmeanings.push_back(tcode);
					break;
				case 4:
					r_ID.push_back(0);
					r_ID.push_back(4);
					tcode.code += "eR-eC ";
					tcode.mean = "�ۺ�";
					tmeanings.push_back(tcode);
					break;
				}
			}
		}

		if (preque.size() == 1 && aftque.size() > 1 && preque[0].sid == selectID)
		{
			for each (Node tmp in aftque)
			{
				switch (tmp.direction)
				{
				case 1:
					r_ID.push_back(0);
					r_ID.push_back(1);
					tcode.code += "eC-eU ";
					tcode.mean = "����";
					tmeanings.push_back(tcode);
					break;
				case 2:
					r_ID.push_back(0);
					r_ID.push_back(2);
					tcode.code += "eC-eL ";
					tcode.mean = "����";
					tmeanings.push_back(tcode);
					break;
				case 3:
					r_ID.push_back(0);
					r_ID.push_back(3);
					tcode.code += "eC-eD ";
					tcode.mean = "����";
					tmeanings.push_back(tcode);
					break;
				case 4:
					r_ID.push_back(0);
					r_ID.push_back(4);
					tcode.code += "eC-eR ";
					tcode.mean = "����";
					tmeanings.push_back(tcode);
					break;
				}
			}
		}
	}

	if ( tmeanings.size() ==0 )
	{
		r_ID.push_back(0);
		tcode.code = "eC";
		tcode.mean = "��ֹ";
		tmeanings.push_back(tcode);
	}

	Update_Neighborhood(selectID, r_ID);
	Update_Listbox(tmeanings);
	
}

//---------------------------------------------------------
void   Ctrajectory_analysis_scalculate::Update_Listbox(vector<Code> Scode)
{
	m_listBox1->Append(Scode[0].code);
	m_listBox2->Append(Scode[0].mean);
}

///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
PGconn* Ctrajectory_analysis_scalculate::ConnectionToDB(PGconn *conn, char *pghost, char *pgport, char *dbname, char *user, char *pwd)
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
PGresult* Ctrajectory_analysis_scalculate::Query(CSG_String sql)
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
wxBitmap Ctrajectory_analysis_scalculate::DrawMatrix(long long startime)
{
	int flag = 0;
	static int a[286][213];
	static int b[213][286];
	int count = 0;
	for (int i = 0; i < 286; i++)
	{
		vector<int> tmp;
		CSG_String sql = "select id, sensorpoint.fid from fireday left join sensorpoint on id = sid where startime between " + CSG_String::Format("%lld", startime) + " and "
			+ CSG_String::Format("%lld", startime + 1000);
		PGresult* resid = Query(sql);
		for (int j = 0; j < 213; j++)
		{
			for (int k = 0; k < PQntuples(resid); k++)
			{
				if ( atoi(PQgetvalue(resid,k,1)) ==  j)
				{
					flag = 1;
				}
				else
				{
					flag = 0;
				}
			}

			if ( flag == 1 )
			{
				a[i][j] = 1;
				count++;
			}
			else
			{
				a[i][j] = 0;
			}
		}
		startime += 1000;
	}

	for (int i = 0; i < 286; i++)
	{
		for (int j = 0; j < 213; j++)
		{
			b[j][i] = a[i][j];
		}
	}

	wxBitmap bt(286, 213);
	wxMemoryDC mdc;
	mdc.SelectObject(bt);

	for (int i = 0; i < 213; i++)
	{
		for (int j = 0; j < 286; j++)
		{
			if ( a[i][j] == 1 )
			{
				mdc.SetPen(*wxWHITE_PEN);
				mdc.DrawPoint(i,j);
			}
			else
			{
				mdc.SetPen(*wxBLACK_PEN);
				mdc.DrawPoint(i, j);
			}
		}
	}

	mdc.SelectObject(wxNullBitmap);

	return bt;

}