///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
#ifndef HEADER_INCLUDED__trajectory_analysis_data_H
#define HEADER_INCLUDED__trajectory_analysis_data_H


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
#include <causta_gdi/causta_gdi.h>
#include <wx/textctrl.h>
#include <wx/string.h>
#include <wx/dcbuffer.h>
#include <vector>
#include <libpq-fe.h>

using namespace std;
///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
class Ctrajectory_analysis_data : public CSGDI_Dialog
{
public:
	Ctrajectory_analysis_data();

	double                  x;

	wxComboBox              *m_combo;

	wxTextCtrl              *m_textCtrl;

	wxString                Sequence;

	vector<int>             DrwaSqe;

	
	void				    Update_View();

	void                    Update_Sequence(wxString sequence);

private:

	long long               startime;

	wxBoxSizer              *bSizer1, *bSizer2, *bSizer3, *bSizer4;

	wxStaticText            *m_sText1, *m_sText2, *m_sText3;

	wxTimer                 m_timer1;

	wxPanel                 *m_panel;

	wxBitmap                m_bitmap;

	char                    *pghost, *pgport, *dbname, *user, *pwd;

	PGconn                  *conn;

	PGresult                *res;

	PGconn*                 ConnectionToDB(PGconn *conn, char *pghost, char *pgport, char *dbname, char *user, char *pwd);

	wxBitmap                _Draw_Sequence(vector<int> drawSqe);

	PGresult*               Query(CSG_String sql);

	DECLARE_EVENT_TABLE()
};


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
#endif // #ifndef HEADER_INCLUDED__trajectory_analysis_data_H


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------