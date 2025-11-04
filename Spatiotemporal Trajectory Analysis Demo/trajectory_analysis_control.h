///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
#ifndef HEADER_INCLUDED__trajectory_analysis_control_H
#define HEADER_INCLUDED__trajectory_analysis_control_H


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
#include <causta_gdi/causta_gdi.h>

#include <wx/wxprec.h>
#include <wx/settings.h>
#include <wx/dc.h>
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>
#include <wx/memory.h>
#include <vector>
#include <algorithm>

using namespace std;
///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
enum
{
	COLOR_MODE_RGB,
	COLOR_MODE_RED,
	COLOR_MODE_BLUE
};


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------

class Ctrajectory_analysis_control : public wxPanel
{
public:
	Ctrajectory_analysis_control(wxWindow *pParent, CSG_Shapes *pSensorData, CSG_Shapes *pFloor, 
		CSG_Shapes *pSensorpoint, CSG_Parameters &Settings);

	virtual ~Ctrajectory_analysis_control(void);

	vector<int>                 r_ID;
	
	void						Update_View(vector<int> r_ID, int idCode);
	void                        Update_View(vector<vector<int>> drawdata, int judge);

	void						On_Paint(wxPaintEvent &event);

	void                        On_Mouse_LDown(wxMouseEvent &event);
	void                        On_Mouse_LUp(wxMouseEvent &event);
	void						On_Mouse_Motion(wxMouseEvent &event);
	void						On_Mouse_Wheel(wxMouseEvent &event);

private:

	int                         defaultID = -1, count =0;
	float                       r_Scale, t_Xshift, t_Yshift;
	vector<int>                 store_id;
	wxBitmap				    m_Bitmap;
	wxPoint                     wPoint, m_Mouse_Down;
	wxPoint                     *PointList;
	wxRect	                    DCRect;
	CSG_Parameters				*m_pSettings;
	CSG_Shapes                  *m_pSensorData, *m_pFloor, *m_pSensorpoint;

	wxBitmap                    _Draw_Image(vector<int> r_ID, int idCode);
	wxBitmap                    _Draw_Traj(vector<vector<int>> drawdata);
	wxBitmap                    _ini_Bitmap(void);
	wxBitmap                    _Draw_Rect(vector<int> r_ID);
	void                        _Draw_Shp(wxMemoryDC &mdc, wxRect &DCRect, vector<int> r_ID, int idCode);
	void                        _Draw_ShpPoint(wxMemoryDC &mdc, wxRect &DCRect, CSG_Shape *t_Point, vector<int> r_ID);
	void                        _Draw_ShpPolyline(wxMemoryDC &mdc, wxRect &DCRect, CSG_Shape *t_Line);
	void                        _Draw_ShpPolygon(wxMemoryDC &mdc, wxRect &DCRect, CSG_Shape *t_Polygon);
	vector<int>                 _Delete_ID(vector<int> store_id);
	DECLARE_EVENT_TABLE()
};

///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
#endif // #ifndef HEADER_INCLUDED__points_view_control_H


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------