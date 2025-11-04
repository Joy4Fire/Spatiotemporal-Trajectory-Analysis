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
#include "trajctory_analysis_tcalculate.h"


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
BEGIN_EVENT_TABLE(Ctrajectory_analysis_tcalculate, CSGDI_Dialog)
END_EVENT_TABLE()


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
Ctrajectory_analysis_tcalculate::Ctrajectory_analysis_tcalculate()
: CSGDI_Dialog(_TL("Trajection Extraction Interface"))
{
	this->SetSize(500, 400);

	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer(wxVERTICAL);

	m_sText1 = new wxStaticText(this, wxID_ANY, wxT("Date Select"), wxDefaultPosition, wxDefaultSize, 0);
	m_sText1->Wrap(-1);
	bSizer4->Add(m_sText1, 0, wxALL, 5);

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer(wxHORIZONTAL);

	m_comboBox1 = new wxComboBox(this, wxID_ANY, wxT("Date"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
	m_comboBox1->Append("2006.03.28");
	m_comboBox1->SetSelection(0);
	bSizer6->Add(m_comboBox1, 1, wxALL, 5);

	//m_button1 = new wxButton(this, wxID_ANY, wxT("Select"), wxDefaultPosition, wxDefaultSize, 0);
	//bSizer6->Add(m_button1, 0, wxALL, 5);

	bSizer4->Add(bSizer6, 1, wxEXPAND, 5);

	m_sline1 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	bSizer4->Add(m_sline1, 0, wxEXPAND | wxALL, 5);

	m_sText2 = new wxStaticText(this, wxID_ANY, wxT("Time Window"), wxDefaultPosition, wxDefaultSize, 0);
	m_sText2->Wrap(-1);
	bSizer4->Add(m_sText2, 0, wxALL | wxEXPAND, 5);

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer(wxHORIZONTAL);

	m_comboBox2 = new wxComboBox(this, wxID_ANY, wxT("Start Time Select"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
	m_comboBox2->Append("2:30 -- 24:00");
	m_comboBox2->SetSelection(0);
	bSizer7->Add(m_comboBox2, 1, wxALL | wxEXPAND, 5);	

	bSizer4->Add(bSizer7, 1, wxEXPAND, 5);

	m_sline2 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	bSizer4->Add(m_sline2, 0, wxEXPAND | wxALL, 5);

	m_slider1 = new wxSlider(this, wxID_ANY, 0, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bSizer4->Add(m_slider1, 1, wxALL | wxEXPAND, 5);

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer(wxVERTICAL);

	m_sText3 = new wxStaticText(this, wxID_ANY, wxT("07:50"), wxDefaultPosition, wxDefaultSize, 0);
	m_sText3->Wrap(-1);
	bSizer9->Add(m_sText3, 0, wxALL, 5);

	bSizer8->Add(bSizer9, 1, wxEXPAND, 5);

	//11.17zs
	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer(wxVERTICAL);
	m_statictext = new wxStaticText(this, wxID_ANY, _TL("Time Lable"));
	bSizer20->Add(m_statictext, 0, wxALIGN_CENTER | wxALL, 5);

	bSizer8->Add(bSizer20, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer(wxVERTICAL);

	m_sText4 = new wxStaticText(this, wxID_ANY, wxT("23:59"), wxDefaultPosition, wxDefaultSize, 0);
	m_sText4->Wrap(-1);
	bSizer10->Add(m_sText4, 0, wxALIGN_RIGHT | wxALL, 5);

	bSizer8->Add(bSizer10, 1, wxEXPAND, 5);

	bSizer4->Add(bSizer8, 1, wxEXPAND, 5);

	bSizer2->Add(bSizer4, 1, wxEXPAND, 5);

	m_sline5 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL);
	bSizer2->Add(m_sline5, 0, wxEXPAND | wxALL, 5);

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer(wxVERTICAL);

	m_sText5 = new wxStaticText(this, wxID_ANY, wxT("Path Matrix"), wxDefaultPosition, wxDefaultSize, 0);
	m_sText5->Wrap(-1);
	bSizer5->Add(m_sText5, 0, wxALL, 5);

	m_sline3 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	bSizer5->Add(m_sline3, 0, wxEXPAND | wxALL, 5);

	m_panel1 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	bSizer5->Add(m_panel1, 1, wxEXPAND | wxALL, 5);

	bSizer2->Add(bSizer5, 1, wxEXPAND, 5);


	bSizer1->Add(bSizer2, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer(wxVERTICAL);

	m_sline4 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	bSizer3->Add(m_sline4, 0, wxEXPAND | wxALL, 5);

	m_sText6 = new wxStaticText(this, wxID_ANY, wxT("Path List"), wxDefaultPosition, wxDefaultSize, 0);
	m_sText6->Wrap(-1);
	bSizer3->Add(m_sText6, 0, wxALL, 5);

	m_listBox1 = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
	bSizer3->Add(m_listBox1, 1, wxALL | wxEXPAND, 5);

	bSizer1->Add(bSizer3, 1, wxEXPAND, 5);

	this->SetSizer(bSizer1);
	this->Layout();

	this->Centre(wxBOTH);

	//---------------------------------------------------------
	conn = NULL;
	pghost = "localhost";
	pgport = "5432";
	dbname = "sensordb";
	user = "postgres";
	pwd = "121421";

	//---------------------------------------------------------
	count = 0;

	for (int i = 0; i < 213; i++)
	{
		vector<int> tmp;
		for (int j = 0; j < 213; j++)
		{
			tmp.push_back(0);
		}
		result.push_back(tmp);
	}

	//---------------------------------------------------------
	CSG_String sql = " select * from linyu";
	PGresult *resl = QueryTraj(sql);
	for (int i = 0; i < PQntuples(resl); i++)
	{
		LNode tmpnode = LNode();
		tmpnode.NodeID = atoi(PQgetvalue(resl, i, 0));
		tmpnode.TopNodeID = atoi(PQgetvalue(resl, i, 1));
		tmpnode.BottomNodeID = atoi(PQgetvalue(resl, i, 2));
		tmpnode.LeftNodeID = atoi(PQgetvalue(resl, i, 3));
		tmpnode.RightNodeID = atoi(PQgetvalue(resl, i, 4));
		tNode.push_back(tmpnode);
	}
}


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
void Ctrajectory_analysis_tcalculate::UpdateView(vector<vector<int>> drawdata)
{
	count++;
	
	wxBitmap m_bitmap = _DrawMatrix(drawdata, count);
	wxClientDC dc(m_panel1);
	dc.DrawBitmap(m_bitmap, 0, 0, false);

	m_slider1->SetValue(count * 0.06);
}


//---------------------------------------------------------
void Ctrajectory_analysis_tcalculate::Update()
{

	wxString tmp;
	vector<wxString> rString;

	for (int i = traResult.size()-1; i > -1; i--)
	{
		for (int j = 0; j < traResult[i].size(); j++)
		{
			if (j == traResult[i].size() - 1)
			{
				tmp += wxString::Format("%d", traResult[i][j]);
			}
			else
			{
				tmp += wxString::Format("%d", traResult[i][j]) + "-";
			}
		}
		rString.push_back(tmp);
		tmp = "";
	}

	sort(rString.begin(), rString.end());
	rString.erase(unique(rString.begin(), rString.end()), rString.end());

	for each (wxString var in rString)
	{
		m_listBox1->Append(var);
	}
}

//---------------------------------------------------------
PGconn* Ctrajectory_analysis_tcalculate::ConnectionToDB(PGconn *conn, char *pghost, char *pgport, char *dbname, char *user, char *pwd)
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
PGresult* Ctrajectory_analysis_tcalculate::QueryTraj(CSG_String sql)
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
Ctrajectory_analysis_tcalculate::LNode Ctrajectory_analysis_tcalculate::findNode(int NodeID, vector<LNode> nodelist)
{
	for each (LNode tmp in nodelist)
	{
		if ( tmp.NodeID == NodeID  )
		{
			return tmp;
		}
	}
}

//---------------------------------------------------------
bool  Ctrajectory_analysis_tcalculate::ifexist(int id, vector<Tnode> tmpList)
{
	for (int i = 0; i < tmpList.size(); i++)
	if (tmpList[i].NodeID == id)
		return true;
	return false;
}

//---------------------------------------------------------
bool  Ctrajectory_analysis_tcalculate::isAdjacent(int start, int id, vector<Tnode> tmpList)
{
	for (int i = start; i < tmpList.size(); i++)
	if (tmpList[i].TopNodeID == id || tmpList[i].BottomNodeID == id || tmpList[i].LeftNodeID == id || tmpList[i].RightNodeID == id)
		return true;
	return false;
}

//---------------------------------------------------------
vector<int>  Ctrajectory_analysis_tcalculate::searchList(Tnode node, vector<Tnode> nodelist)
{
	vector<int> tmpResult;
	vector<int> result;
	tmpResult.push_back(node.NodeID);
	Tnode *tmpNode = &node;
	while (tmpNode->ParentID != -1)
	{
	    tmpResult.push_back(nodelist[tmpNode->ParentID].NodeID);
		tmpNode = &nodelist[tmpNode->ParentID];
	}
	for (int i = tmpResult.size()-1; i > -1; i--)
	{
		result.push_back(tmpResult[i]);
	}
	return result;
}

//---------------------------------------------------------
void Ctrajectory_analysis_tcalculate::ComputePath(PGresult *res, vector<LNode> tNode)
{
	trajectList.clear();
	Tnode rootNode = Tnode();
	trajectList.push_back(rootNode);
	Tnode fnode = Tnode(findNode(atoi(PQgetvalue(res, 0, 0)),tNode));
	fnode.startime = atoll(PQgetvalue(res, 0, 1));
	fnode.endtime = atoll(PQgetvalue(res, 0, 2));
	fnode.isLeaf = false;

	//����һ�������·���� ��Ϊ��һ���ӽڵ�
	trajectList.push_back(fnode);
	int size = 1;

	while (size < trajectList.size())
	{
		fnode = trajectList[size];
		// ʱ�䴰��
		if ( fnode.startime < trajectList[1].startime + 30*1000 )
		{
			long long  maxstartime = fnode.endtime + 3000;
			//Ѱ��3s��������Ӧ��
			CSG_String sql = "select id, startime, endtime from fireday where ( startime < " + CSG_String::Format("%lld", maxstartime) + " ) and ( startime > " +
				CSG_String::Format("%lld", fnode.endtime) + " ) order by startime";
			PGresult *Tres = QueryTraj(sql);
			//���������Ѿ�û�нڵ�,��fnodeΪҶ�ӽڵ�,��fnode�ÿ�
			if (PQntuples(Tres) == 0)
			{
				trajectList[size].isLeaf = true;
				trajectList[size].clear();
			}
			//�������ڴ��ڽڵ�
			else
			{
				vector<Tnode> tempNodeList;
				vector<Tnode> tempJudgeList;
				for (int i = 0; i < PQntuples(Tres); i++)
				{
					Tnode tmpNode = Tnode(findNode(atoi(PQgetvalue(Tres, i, 0)), tNode));
					tmpNode.startime = atoll(PQgetvalue(Tres, i, 1));
					tmpNode.endtime = atoll(PQgetvalue(Tres, i, 2));
					tmpNode.isLeaf = false;
					if (!ifexist(tmpNode.NodeID, tempNodeList))
					{
						if (fnode.TopNodeID == tmpNode.NodeID || fnode.BottomNodeID == tmpNode.NodeID || fnode.LeftNodeID == tmpNode.NodeID || fnode.RightNodeID == tmpNode.NodeID)
						{
							tmpNode.ParentID = size;
							tempNodeList.push_back(tmpNode);
						}
						else
						{
							tempJudgeList.push_back(tmpNode);
						}
					}
				}
				//���tempnodelistΪ����fnodeΪҶ�ӽڵ�
				if (tempNodeList.size() == 0)
				{
					trajectList[size].isLeaf = true;
				}

				for (int i = 0; i < tempJudgeList.size(); i++)
				{
					Tnode tmpnode = tempJudgeList[i];
					//���ֲ��ظ�
					if (!ifexist(tmpnode.NodeID, tempNodeList))
					{
						//��������ݿ��Ƿ����������ڵ�ǰ�ڵ㣬������Ϊ�µ����
						if (!isAdjacent(size + 1, tmpnode.NodeID, trajectList))
						{
							tmpnode.ParentID = -1;
							tempNodeList.push_back(tmpnode);
						}
					}
				}
				for each (Tnode tmpnode in tempNodeList)
				{
					trajectList.push_back(tmpnode);
				}
			}
		} 
		else
		{
			trajectList[size].isLeaf = true;
			trajectList[size].clear();
		}
		size++;
	}

	for (int i = trajectList.size()-1; i > 0; i--)
	{
		if (trajectList[i].isLeaf == true)
		{
			if (trajectList[i].ParentID != 0)
			{
				if (searchList(trajectList[i], trajectList).size() > 1)
				{
					traResult.push_back(searchList(trajectList[i], trajectList));
				}
			}
		}
	}
	
}

wxBitmap Ctrajectory_analysis_tcalculate::_DrawMatrix(vector<vector<int>> dataraw, int count)
{
	vector<int> recod;

	for (int i = 0; i < dataraw.size(); i++)
	{
		for (int j = 0; j < dataraw[i].size(); j++)
		{
			CSG_String sql = "select fid from sensorpoint where sid = " + CSG_String::Format("%d",dataraw[i][j]);
			PGresult* restime = QueryTraj(sql);
			recod.push_back(atoi(PQgetvalue(restime, 0, 0))); 
		}
	}

	for (int i = 0; i < 213; i++)
	{
		for (int j = 0; j < 213; j++)
		{
			for (int n = 0; n < recod.size(); n=n+2)
			{
				if ( i == recod[n] && j == recod[n+1])
				{
					result[i][j]++;
				}
			}
		}
	}

	wxBitmap bt(213, 213);
	wxMemoryDC mdc;
	mdc.SelectObject(bt);

	for (int i = 0; i < 213; i++)
	{
		for (int j = 0; j < 213; j++)
		{
			if (result[i][j] > 0)
			{
				mdc.SetPen(wxPen(wxColour(255, 230 - result[i][j]*5, 255)));
				mdc.DrawPoint(i, j);
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