///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
#ifndef HEADER_INCLUDED__trajectory_analysis_scalculate_H
#define HEADER_INCLUDED__trajectory_analysis_scalculate_H


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
#include <causta_gdi/causta_gdi.h>

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/listbox.h>
#include <wx/calctrl.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/statline.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/bmpbuttn.h>
#include <wx/dialog.h>
#include <vector>
#include <libpq-fe.h>

using namespace std;
///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

class Node
{
public:
	int sid;
	int direction;
};

class Code
{
public:
	wxString code;
	wxString mean;
private:

};

//---------------------------------------------------------
class Ctrajectory_analysis_scalculate : public CSGDI_Dialog
{
public:
	Ctrajectory_analysis_scalculate();

	int                         x = 0, y = 0, count = 0;
	long long                   startime;
	void                        Update_Semantics(int selectID, long long startime, long long endtime);
	void				        Update_View();

	wxBitmap                    m_bitmap;
	wxComboBox                  *m_comboBox1, *m_comboBox2;
	wxListBox                   *m_listBox1, *m_listBox2;
	wxStaticText                *m_statictext;
	/*wxListBox                   *m_listBox3;*/

private:

	wxStaticText				*m_sText1, *m_sText2, *m_sText3, *m_sText4, *m_sText5, *m_sText6, *m_sText7, *m_sText8, *m_sText9;
	wxStaticLine                *m_sline1, *m_sline2, *m_sline3, *m_sline4;
	wxPanel                     *m_panel1, *m_panel2, *m_panel3, *m_panel4, *m_panel5, *m_panel6;

	wxSlider                    *m_slider1;
	wxBitmapButton              *m_bpButton;
	CSG_String                  Scode;
	
	char                       *pghost, *pgport, *dbname, *user, *pwd;

	PGconn                     *conn;

	PGresult                   *Pres, *Ares, *Lres;

	void                        Update_Neighborhood(int selectID, vector<int> sID);
	void                        Update_Listbox(vector<Code> Scode);
	void                        Set_Semantics(int selctID, vector<Node> preque, vector<Node> aftque);
   	PGconn*                     ConnectionToDB(PGconn *conn, char *pghost, char *pgport, char *dbname, char *user, char *pwd);
	PGresult*                   Query(CSG_String sql);

	wxBitmap                    DrawMatrix(long long startime);

	DECLARE_EVENT_TABLE()
};


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
#endif // #ifndef HEADER_INCLUDED__Ctrajectory_analysis_scalculate_H


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------