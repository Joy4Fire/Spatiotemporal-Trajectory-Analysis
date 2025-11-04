//---------------------------------------------------------
#ifndef _HEADER_INCLUDED__SAGA_GUI__VIEW_MathPlot_control_H
#define _HEADER_INCLUDED__SAGA_GUI__VIEW_MathPlot_control_H


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
#include <saga_api/saga_api.h>

/*#include "view_base.h"*/


#include "wx/wx.h"
#include "mathplot.h"
// For compilers that support precompilation, includes "wx/wx.h".
//#include "wx/wxprec.h" //用于预编译

#include "wx/image.h"
#include "wx/listctrl.h"
#include "wx/sizer.h"
#include "wx/log.h"
#include "wx/intl.h"
#include "wx/print.h"
#include <wx/filename.h>
#include "wx/file.h"

#include <math.h>

#include "wksp_data_manager.h"
#include "wksp_layer_classify.h"
#include "wksp_grid.h"



///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
// void		Add_MathPlot(void); //仅供测试
// void		Add_MathPlot(CSG_Grid *pGrid);
// void		Add_MathPlot(CSG_Table *pTable);
// void		Add_MathPlot(CSG_Table *pTable,int TEST);


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
class CVIEW_MathPlot_control : public wxPanel
{
public:
	CVIEW_MathPlot_control(wxWindow *pParent, CSG_Table *pTable);
	virtual ~CVIEW_MathPlot_control(void);

	bool							Update_Mathplot		(void);

	void							Fit_Size			(void)	{ m_pWindow->Fit();}
	void							Inc_Size			(void)	{ m_pWindow->ZoomIn();}
	void							Dec_Size			(void)	{ m_pWindow->ZoomOut();}
	bool							Set_Parameters		(void);
	void							SaveAs_Image		(void);
	void							Add_Txt				(const SG_Char* name);
	void							Add_MarkLine		(double LineLength, wxPen pen);
	void							Add_Line			(double *data, double scale, int nRecord, const SG_Char* name);

private:

	bool								_Initialize			(void);
	bool								_Create				(void);
	void								_Destroy			(void);
	void								_Draw				(void);

	int									_Get_Field_By_Name	(const CSG_String &sField);

	CSG_Parameters						m_Parameters;
	double								m_xMin, m_xMax, m_yMin, m_yMax;
	int									m_nFields, *m_Fields, m_xField;
	CSG_Table							*m_pTable, m_Structure;
	CSG_Colors							m_Colors;
	wxFont								*m_pFont;

	
	mpWindow							*m_pWindow;
	mpScaleX							*m_pXaxis;
	mpScaleY							*m_pYaxis, *m_pYaxis_add;
	
	mpInfoCoords						*m_pCoor_nfo;
	mpInfoLegend						*m_pLeg_nfo;
	wxPen								*m_pPtPen, *m_pLnPen;

	//void								_On_close			(wxCloseEvent& WXUNUSED(event));


	////---------------------------------------------------------
	//DECLARE_EVENT_TABLE()
	//DECLARE_CLASS(CVIEW_MathPlot_control)

};


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
#endif // #ifndef _HEADER_INCLUDED__SAGA_GUI__VIEW_MathPlot_control_H

