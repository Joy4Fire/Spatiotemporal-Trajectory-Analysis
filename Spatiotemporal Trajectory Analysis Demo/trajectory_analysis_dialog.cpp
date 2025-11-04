///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

enum trajtime
{

};

//---------------------------------------------------------

#include "trajectory_analysis_dialog.h"
#include "trajectory_analysis_control.h"
#include "trajectory_analysis_data.h"
#include "trajectory_analysis_chart.h"
#include "trajctory_analysis_tcalculate.h"
#include "trajctory_analysis_scalculate.h"


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
BEGIN_EVENT_TABLE(Ctrajectory_analysis_dialog, wxFrame)

	EVT_TIMER(TIMER_ID, Ctrajectory_analysis_dialog::On_Timer)
	EVT_TOOL(Menu_Data_ShowLoad, Ctrajectory_analysis_dialog::On_ShowDataDialog)
	EVT_MENU(Menu_Data_Stop, Ctrajectory_analysis_dialog::On_ShowDataStop)
	EVT_MENU(Menu_Data_Start, Ctrajectory_analysis_dialog::On_ShowDataStart)
	EVT_MENU(Menu_Cal_TShowFace, Ctrajectory_analysis_dialog::On_ShowCalTface)
	EVT_MENU(Menu_Cal_SShowFace, Ctrajectory_analysis_dialog::On_ShowCalSface)
	
END_EVENT_TABLE()


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//--------------------------------------------------------- 
Ctrajectory_analysis_dialog::Ctrajectory_analysis_dialog(CSG_Shapes *pSensorData, CSG_Shapes *pFloor, CSG_Shapes *pSensorpoint)
: wxFrame(NULL, wxID_ANY, _TL("�������ڻ�������Ⱥ��Ϊ�Ķ�̬��������Ϸ���ϵͳ"), wxDefaultPosition, wxSize(1200, 700), wxDEFAULT_FRAME_STYLE | wxNO_FULL_REPAINT_ON_RESIZE)//(_TL("Space-Time Trajectory Engine"), SGDI_DLG_STYLE_START_MAXIMISED)
{
	//-----------------------------------------------------
	m_Settings.Create(NULL, _TL("STEngine Settings"), _TL(""));

	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	m_tData = NULL;
	m_tCal = NULL;
	m_sCal = NULL;
	m_tView = new Ctrajectory_analysis_control(this, pSensorData, pFloor, pSensorpoint, m_Settings);

	//-----------------------------------------------------
	bSizer1 = new wxBoxSizer(wxVERTICAL);
	bSizer2 = new wxBoxSizer(wxHORIZONTAL);
	m_tree= CreateTreeListCtrl(wxTR_HAS_BUTTONS | wxTR_SINGLE);

	bSizer2->Add(m_tree, 0, wxEXPAND, 5);
	bSizer2->Add(m_tView, 1, wxEXPAND|wxALL, 5);

	bSizer1->Add(bSizer2, 1, wxEXPAND, 5);
	this->SetSizer(bSizer1);
	this->Layout();

	////-----------------------------------------------------
	m_StatusBar = this->CreateStatusBar(1, wxST_SIZEGRIP, wxID_ANY);

	m_toolbar = this->CreateToolBar(wxTB_HORIZONTAL, wxID_ANY);
	wxBitmap p_tool1 = wxBitmap(wxT("G:\\CAUSTA_NEW\\src\\src\\STEngine\\addshp.png"), wxBITMAP_TYPE_PNG);
	wxBitmap p_tool2 = wxBitmap(wxT("G:\\CAUSTA_NEW\\src\\src\\STEngine\\adddata.png"), wxBITMAP_TYPE_PNG);
	wxBitmap p_tool3 = wxBitmap(wxT("G:\\CAUSTA_NEW\\src\\src\\STEngine\\save.png"), wxBITMAP_TYPE_PNG);
	wxBitmap p_tool4 = wxBitmap(wxT("G:\\CAUSTA_NEW\\src\\src\\STEngine\\expand.png"), wxBITMAP_TYPE_PNG);
	wxBitmap p_tool5 = wxBitmap(wxT("G:\\CAUSTA_NEW\\src\\src\\STEngine\\move.png"), wxBITMAP_TYPE_PNG);
	wxBitmap p_tool6 = wxBitmap(wxT("G:\\CAUSTA_NEW\\src\\src\\STEngine\\zoomin.png"), wxBITMAP_TYPE_PNG);
	wxBitmap p_tool7 = wxBitmap(wxT("G:\\CAUSTA_NEW\\src\\src\\STEngine\\zoomout.png"), wxBITMAP_TYPE_PNG);
	wxBitmap p_tool8 = wxBitmap(wxT("G:\\CAUSTA_NEW\\src\\src\\STEngine\\start.png"), wxBITMAP_TYPE_PNG);
	wxBitmap p_tool9 = wxBitmap(wxT("G:\\CAUSTA_NEW\\src\\src\\STEngine\\stop.png"), wxBITMAP_TYPE_PNG);
	wxBitmap p_tool10 = wxBitmap(wxT("G:\\CAUSTA_NEW\\src\\src\\STEngine\\attribute.png"), wxBITMAP_TYPE_PNG);
	wxBitmap p_tool11 = wxBitmap(wxT("G:\\CAUSTA_NEW\\src\\src\\STEngine\\help.png"), wxBITMAP_TYPE_PNG);
	wxBitmap p_tool12 = wxBitmap(wxT("G:\\CAUSTA_NEW\\src\\src\\STEngine\\exit.png"), wxBITMAP_TYPE_PNG);

	m_toolbar->AddTool(wxID_ANY, p_tool1, _TL("Load Shp"));
	m_toolbar->AddTool(Menu_Data_ShowLoad, p_tool2, _TL("Load PIR"));
	m_toolbar->AddTool(wxID_ANY, p_tool3, _TL("Save Result"));
	m_toolbar->AddTool(wxID_ANY, p_tool4, _TL("Show All"));
	m_toolbar->AddTool(wxID_ANY, p_tool5, _TL("Pan"));
	m_toolbar->AddTool(wxID_ANY, p_tool6, _TL("Zoom In"));
	m_toolbar->AddTool(wxID_ANY, p_tool7, _TL("Zoom Out"));
	m_toolbar->AddTool(wxID_ANY, p_tool8, _TL("Start"));
	m_toolbar->AddTool(wxID_ANY, p_tool9, _TL("Stop"));
	m_toolbar->AddTool(wxID_ANY, p_tool10, _TL("Attributes"));
	m_toolbar->AddTool(wxID_ANY, p_tool11, _TL("Help"));
	m_toolbar->AddTool(wxID_ANY, p_tool12, _TL("Exit"));


	m_toolbar->Realize();

	m_MenuBar = new wxMenuBar(0);
	m_File = new wxMenu();
	m_Traj = new wxMenu(); 
	m_Sem = new wxMenu();
	m_MenuBar->Append(m_File, _TL("File"));
	m_File->Append(wxID_ANY,_TL("&Open\tCtrl+O"));
	m_File->Append(wxID_ANY, _TL("&Save\tCtrl+S"));
	m_File->Append(wxID_ANY, _TL("Save as..."));
	m_File->Append(wxID_ANY, _TL("Options"));
	m_File->Append(wxID_ANY, _TL("&Help\tF1"));
	m_File->Append(wxID_ANY, _TL("Quit"));

	m_MenuBar->Append(m_Traj, _TL("Trajectory"));
	m_Traj->Append(wxID_ANY, _TL("Network Topology Reconfiguration"));
	m_Traj->Append(Menu_Cal_TShowFace, _TL("Trajectory Computation"));

	m_MenuBar->Append(m_Sem, _TL("Semantics"));
	m_Sem->Append(wxID_ANY, _TL("Semantic Encoding"));
	m_Sem->Append(Menu_Cal_SShowFace, _TL("Semantic Computation"));

	this->SetMenuBar(m_MenuBar);
	this->Center(wxBOTH);

	//-----------------------------------------------------
	conn = NULL;
	res = NULL;
	pghost = "localhost";
	pgport = "5432";
	dbname = "sensordb";
	user = "postgres";
	pwd = "121421";
	//-----------------------------------------------------
	m_CValue = 7;
	m_TValue = 50;
	m_SValue = 0;
}

///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
void Ctrajectory_analysis_dialog::On_ShowDataDialog(wxCommandEvent &WXUNUSED(event))
{
	judgeID = 0;
	if ( NULL == m_tData)
	{
		m_tData = new Ctrajectory_analysis_data();
		m_tData->Show(true);
	}
	else
	{
		m_tData->SetFocus();
	}

	conn = ConnectionToDB(conn, pghost, pgport, dbname, user, pwd);
	CSG_String sql = "select startime from fireday limit 1";
	res = PQexec(conn, sql);
	starttime = atoll(PQgetvalue(res, 0, 0));
	PQfinish(conn);

	m_timer = new wxTimer(this, TIMER_ID);

	m_timer->Start(500);

} 

//---------------------------------------------------------
void Ctrajectory_analysis_dialog::On_ShowDataStop(wxCommandEvent &WXUNUSED(event))
{
	m_timer->Stop();
}

//---------------------------------------------------------
void Ctrajectory_analysis_dialog::On_ShowDataStart(wxCommandEvent &WXUNUSED(event))
{
	m_timer->Start(500);
}

//---------------------------------------------------------
void Ctrajectory_analysis_dialog::On_ShowCalTface(wxCommandEvent &WXUNUSED(event))
{
	m_CValue = 7;
	m_TValue = 50;
	m_SValue = 0;
	vector<int> upid;
	m_timer->Stop();
	judgeID = -1;
	m_tView->Update_View(upid,judgeID);
	judgeID = 1;
	if (NULL == m_tCal)
	{
		m_tCal = new Ctrajectory_analysis_tcalculate();
		m_tCal->Show(true);
	}
	else
	{
		m_tCal->SetFocus();
	}
	
	m_timer = new wxTimer(this, TIMER_ID);

	m_timer->Start(5000);
}

//---------------------------------------------------------
void Ctrajectory_analysis_dialog::On_ShowCalSface(wxCommandEvent &WXUNUSED(event))
{
	m_CValue = 7;
	m_TValue = 50;
	m_SValue = 0;
	vector<int> upid;
	m_timer->Stop();
	judgeID = -1;
	m_tView->Update_View(upid,judgeID);
	judgeID = 2;
	if (NULL == m_sCal)
	{
		m_sCal = new Ctrajectory_analysis_scalculate();
		m_sCal->Show(true);
	}
	else
	{
		m_sCal->SetFocus();
	}
	
	conn = ConnectionToDB(conn, pghost, pgport, dbname, user, pwd);
	CSG_String sql = "select startime from fireday limit 1";
	res = PQexec(conn, sql);
	starttime = atoll(PQgetvalue(res, 0, 0));
	PQfinish(conn);

	m_timer = new wxTimer(this, TIMER_ID);

	m_timer->Start(500);
}

//---------------------------------------------------------
void Ctrajectory_analysis_dialog::On_Timer(wxTimerEvent& event)
{
	int flag = 0;
	int selectflag = 0;
	PGresult *tmp;
	tmp = Dataload(1);

	int tuple_num = PQntuples(res);
	int field_num = PQnfields(res);
	if ( judgeID == 0 )
	{
		if (tuple_num != 0)
		{
			for (int i = 0; i < tuple_num; i++)
			{
				m_tView->r_ID.push_back(atoi(PQgetvalue(res, i, 0)));
				if (atoi(PQgetvalue(res, i, 0)) == atoi(m_tData->m_combo->GetValue()))
				{
					flag = 1;
				}
			}
			m_tView->Update_View(m_tView->r_ID, judgeID);
			m_tView->r_ID.clear();

			if (flag == 1)
			{
				m_tData->Sequence += "1";
				m_tData->DrwaSqe.push_back(1);
			}
			else
			{
				m_tData->Sequence += "0";
				m_tData->DrwaSqe.push_back(0);
			}
			m_tData->Update_Sequence(m_tData->Sequence);

			m_tData->x += 1;
			m_tData->Update_View();

			starttime += 1000;
			
		}
		else
		{
			m_tView->Update_View(m_tView->r_ID, judgeID);
			m_tData->Sequence += "0";
			m_tData->DrwaSqe.push_back(0);
			m_tData->Update_Sequence(m_tData->Sequence);
			m_tData->x += 1;
			m_tData->Update_View();
			starttime += 1000;
		}
	}

	if ( judgeID == 1 )
	{
		PGresult *res;
		wxString str = "";

		tSquence.clear();
		if (recordcount == 0)
		{
			CSG_String sql = "select id, startime, endtime from fireday order by startime limit 1";
			res = QueryData(sql);
			recordtime = atoll(PQgetvalue(res, 0, 1));
			recordcount++;
		}
		else
		{
			CSG_String sql = "select id, startime, endtime from fireday where startime > " + CSG_String::Format("%lld", recordtime + 30 * 1000) + " order by startime limit 1";
			res = QueryData(sql);
			recordtime = atoll(PQgetvalue(res, 0, 1));
		}
		m_tCal->traResult.clear();
		m_tCal->ComputePath(res, m_tCal->tNode);
		tSquence = m_tCal->traResult;

		if ( tSquence.size() == 0 )
		{
			m_tView->Update_View(tSquence, 0);
			m_SValue += 30;
			if (m_SValue / 60 != 0)
			{
				m_TValue += m_SValue / 60;
				m_SValue = 0;
			}
			if (m_TValue / 60 != 0)
			{
				m_CValue += m_TValue / 60;
				m_TValue = 0;
			}
		    str = "0" + to_string(m_CValue) + ":" + to_string(m_TValue) + ":" + to_string(m_SValue);
			m_tCal->m_statictext->SetLabel(str);
		}
		else
		{
			m_tView->Update_View(tSquence, 1);
			
			m_SValue += 30;
			if (m_SValue / 60 != 0)
			{
				m_TValue += m_SValue / 60;
				m_SValue = 0;
			}
			if (m_TValue / 60 != 0)
			{
				m_CValue += m_TValue / 60;
				m_TValue = 0;
			}
			str = "0" + to_string(m_CValue) + ":" + to_string(m_TValue) + ":" + to_string(m_SValue);
			m_tCal->m_statictext->SetLabel(str);

			m_tCal->UpdateView(tSquence);
			m_tCal->Update();
		}
	}

	if ( judgeID == 2 )
	{
		if (tuple_num != 0)
		{
			for (int i = 0; i < tuple_num; i++)
			{
				m_tView->r_ID.push_back(atoi(PQgetvalue(res, i, 0)));
				if (atoi(PQgetvalue(res, i, 0)) == atoi(m_sCal->m_comboBox1->GetValue()))
				{
					selectflag = 1;
					s_starttime = atoll(PQgetvalue(res, i, 1));
					s_endtime = atoll(PQgetvalue(res, i, 2));
				}
			}
			m_tView->Update_View(m_tView->r_ID, judgeID);

			m_tView->r_ID.clear();

			if ( selectflag == 1 )
			{
				m_sCal->Update_Semantics(atoi(m_sCal->m_comboBox1->GetValue()), s_starttime, s_endtime);
			}

			m_sCal->x += 1;
			m_sCal->Update_View();

			starttime += 1000;
			//11.17
			wxString str = "";
			m_SValue++;
			if (m_SValue / 60 != 0 )
			{
				m_TValue += m_SValue / 60;
				m_SValue = 0;
			}
			if (m_TValue / 60 != 0)
			{
				m_CValue += m_TValue / 60;
				m_TValue = 0;
			}

			if ( m_CValue < 10 )
			{
				str = "0"+ to_string(m_CValue)+ ":" + to_string(m_TValue) + ":" + to_string(m_SValue);
			}
			else
			{
				str = to_string(m_CValue) + ":" + to_string(m_TValue) + ":" + to_string(m_SValue);
			}

			m_sCal->m_statictext->SetLabel(str);
		}
		else
		{
			m_tView->Update_View(m_tView->r_ID, judgeID);
			m_sCal->x += 1;
			m_sCal->Update_View();
			starttime += 1000;
			//11.17
			wxString str = "";
			m_SValue++;
			if (m_SValue / 60 != 0)
			{
				m_TValue += m_SValue / 60;
				m_SValue = 0;
			}
			if (m_TValue / 60 != 0)
			{
				m_CValue += m_TValue / 60;
				m_TValue = 0;
			}


			if (m_CValue < 10)
			{
				str = "0" + to_string(m_CValue) + ":" + to_string(m_TValue) + ":" + to_string(m_SValue);
			}
			else
			{
				str = to_string(m_CValue) + ":" + to_string(m_TValue) + ":" + to_string(m_SValue);
			}

			m_sCal->m_statictext->SetLabel(str);
		}
	}
	
}

///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
wxTreeCtrl* Ctrajectory_analysis_dialog::CreateTreeListCtrl(long style)
{
	wxTreeCtrl* const
		tree = new wxTreeCtrl(this, wxID_ANY,
		wxDefaultPosition, wxSize(150,600),
		style);
	wxImageList* imageList = new wxImageList(16, 16);
	imageList->Add(wxBitmap(wxT("G:\\CAUSTA_NEW\\src\\src\\STEngine\\data.png"), wxBITMAP_TYPE_PNG));
	imageList->Add(wxBitmap(wxT("G:\\CAUSTA_NEW\\src\\src\\STEngine\\point.png"), wxBITMAP_TYPE_PNG));
	imageList->Add(wxBitmap(wxT("G:\\CAUSTA_NEW\\src\\src\\STEngine\\line.png"), wxBITMAP_TYPE_PNG));
	imageList->Add(wxBitmap(wxT("G:\\CAUSTA_NEW\\src\\src\\STEngine\\square.png"), wxBITMAP_TYPE_PNG));
	tree->AssignImageList(imageList);

	wxTreeItemId rootId = tree->AddRoot(_TL("Data"), 0, 0);
	wxTreeItemId itemId1 = tree->AppendItem(rootId,
		wxT("SensorPoint"), 1, 1);
	wxTreeItemId itemId2 = tree->AppendItem(rootId,
		wxT("SensorFloor"), 2, 1);
	wxTreeItemId itemId3 = tree->AppendItem(rootId,
		wxT("SensorData"), 3, 1);
	return tree;

}

///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
PGresult* Ctrajectory_analysis_dialog::QueryData(CSG_String sql)
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
PGconn* Ctrajectory_analysis_dialog::ConnectionToDB(PGconn *conn, char *pghost, char *pgport, char *dbname, char *user, char *pwd)
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
PGresult* Ctrajectory_analysis_dialog::Dataload(int category)
{
	conn = ConnectionToDB(conn, pghost, pgport, dbname, user, pwd);
	if (conn != NULL)
	{
		CSG_String sql = "select id, startime, endtime from fireday where startime between "
			+ CSG_String::Format("%lld", starttime) + " and " + CSG_String::Format("%lld", (starttime + 1000));
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
bool Ctrajectory_analysis_dialog::isEmpty(vector<vector<int>> tSquence)
{
	if ( tSquence.size() == 0 )
	{
		return true;
	}
	for (int i = 0; i < tSquence.size(); i++)
	{
		if ( tSquence[i].size ()> 0 )
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}
