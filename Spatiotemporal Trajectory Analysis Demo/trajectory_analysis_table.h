///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __NONAME_H__
#define __NONAME_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/grid.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class trajectory_analysis_table
///////////////////////////////////////////////////////////////////////////////
class trajectory_analysis_table : public wxDialog
{
	private:
	
	protected:
		wxStaticText* m_staticText1;
		wxStaticText* m_staticText2;
		wxStaticLine* m_staticline1;
		wxStaticText* m_staticText3;
		wxTextCtrl* m_textCtrl1;
		wxButton* m_button4;
		wxButton* m_button7;
		wxStaticText* m_staticText4;
		wxTextCtrl* m_textCtrl2;
		wxButton* m_button6;
		wxButton* m_button8;
		wxStaticLine* m_staticline3;
		wxGrid* m_grid1;
	
	public:
		
		trajectory_analysis_table(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("PIR Data Management"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(470, 237), long style = wxDEFAULT_DIALOG_STYLE);
		~trajectory_analysis_table();
	
};

#endif //__NONAME_H__
