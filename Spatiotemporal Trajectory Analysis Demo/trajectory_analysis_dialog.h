///////////////////////////////////////////////////////////
//														 //
//                                                       //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------

#ifndef HEADER_INCLUDED__trajectory_analysis_dialog_H
#define HEADER_INCLUDED__trajectory_analysis_dialog_H

///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
#include <causta_gdi/causta_gdi.h>
#include <libpq-fe.h>
#include <wx/artprov.h>
#include <wx/dataview.h>
#include <wx/sizer.h>
#include <wx/gdicmn.h>
#include <wx/settings.h>
#include <wx/menu.h>
#include <wx/frame.h>
#include <wx/treectrl.h>
#include <windows.h>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

enum MyEnum
{
	 TIMER_ID           = 0,
     Menu_Data_ShowLoad = 1,
	 Menu_Data_Stop     = 2,
	 Menu_Data_Start    = 3,
	 Menu_Cal_TShowFace = 4,
	 Menu_Cal_SShowFace = 5,
};

///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------

class Ctrajectory_analysis_dialog : public wxFrame
{
public:
	
	Ctrajectory_analysis_dialog(CSG_Shapes *pSensorData, CSG_Shapes *pFloor, CSG_Shapes *pSensorpoint);


private:

	CSG_String                 label;

	long long                  starttime, endtime, s_starttime, s_endtime, recordtime;

	int                        timestep, classcount;

	int                        judgeID = 1, recordcount = 0;

	char                       *pghost, *pgport, *dbname, *user, *pwd;

	vector<vector<int>>        tSquence;

	PGconn                     *conn;

	PGresult                   *res, *tresult;

	wxTreeCtrl                 *m_tree;

	wxToolBar                  *m_toolbar;

	wxBoxSizer                 *bSizer1, *bSizer2;

	wxWindow                   *parent;

	wxMenuBar                  *m_MenuBar;

	wxMenu                     *m_File, *m_Traj, *m_Sem;
	
	wxStatusBar                *m_StatusBar;

	wxDataViewCtrl             *m_DataView;

	wxTimer                    *m_timer;


	class Ctrajectory_analysis_control	*m_tView;

	class Ctrajectory_analysis_data *m_tData;

	class Ctrajectory_analysis_tcalculate *m_tCal;

	class Ctrajectory_analysis_scalculate *m_sCal;

	CSG_Parameters				m_Settings;

	//11.17
	int                         m_CValue, m_TValue, m_SValue;

	void						On_ShowDataDialog(wxCommandEvent &WXUNUSED(event));
	void                        On_ShowDataStop(wxCommandEvent &WXUNUSED(event));
	void                        On_ShowDataStart(wxCommandEvent &WXUNUSED(event));
	void                        On_ShowCalTface(wxCommandEvent &WXUNUSED(event));
	void                        On_ShowCalSface(wxCommandEvent &WXUNUSED(event));
	void                        On_Timer(wxTimerEvent& event);

	bool                        isEmpty(vector<vector<int>> tSquence);

	wxTreeCtrl*                 CreateTreeListCtrl(long  style);

	PGconn*                     ConnectionToDB(PGconn *conn, char *pghost, char *pgport, char *dbname, char *user, char *pwd);
	PGresult*                   ExecSQL(PGconn *conn, char *sql);
	PGresult*                   QueryData(CSG_String sql);
	PGresult*                   Dataload(int category);

	DECLARE_EVENT_TABLE()

};



///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
#endif // #ifndef HEADER_INCLUDED__trajectory_analysis_dialog_H


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
