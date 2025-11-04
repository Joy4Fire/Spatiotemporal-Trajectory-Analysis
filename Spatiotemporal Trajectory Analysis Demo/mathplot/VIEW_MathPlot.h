//---------------------------------------------------------
#ifndef _HEADER_INCLUDED__SAGA_GUI__VIEW_MathPlot_H
#define _HEADER_INCLUDED__SAGA_GUI__VIEW_MathPlot_H


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
#include <saga_api/saga_api.h>
#include "view_base.h"



///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
// void		Add_MathPlot(void); //½ö¹©²âÊÔ
// void		Add_MathPlot(CSG_Grid *pGrid);
// void		Add_MathPlot(CSG_Table *pTable);
// void		Add_MathPlot(CSG_Table *pTable,int TEST);


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
class CVIEW_MathPlot : public CVIEW_Base
{
public:
	CVIEW_MathPlot(class CWKSP_Table *pTable);
	virtual ~CVIEW_MathPlot(void);

	static class wxToolBarBase *		_Create_ToolBar		(void);
	static class wxMenu *				_Create_Menu		(void);

	bool								Update_Mathplot		(void);


private:

	class CVIEW_MathPlot_control		*m_pControl;

	class CWKSP_Table					*m_pOwner;

	CSG_Parameters						m_paraAdd;

	void								_Create_paraAdd		(void);
	void								On_Parameters		(wxCommandEvent &event);
	void								On_Size_Fit			(wxCommandEvent &event);
	void								On_Size_Inc			(wxCommandEvent &event);
	void								On_Size_Dec			(wxCommandEvent &event);
	void								On_Mathplot_Save_Image(wxCommandEvent &event);
	void								On_Mathplot_Add		(wxCommandEvent &event);
	void								On_Key_Down			(wxKeyEvent &event);

	static int		_On_Parameter_Changed(CSG_Parameter *pParameter);
	static int		On_Parameter_Changed (CSG_Parameters *pParameters, CSG_Parameter *pParameter);
	//---------------------------------------------------------
	DECLARE_EVENT_TABLE()
	DECLARE_CLASS(CVIEW_MathPlot)
};


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
#endif // #ifndef _HEADER_INCLUDED__SAGA_GUI__VIEW_MathPlot_H

