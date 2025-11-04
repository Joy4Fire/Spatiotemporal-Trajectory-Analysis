#ifdef __BORLANDC__
#pragma hdrstop
#endif

#include <causta_api/causta_api.h>

//---------------------------------------------------------
#include "trajectory_analysis_control.h"
#include "trajectory_analysis_dialog.h"


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
BEGIN_EVENT_TABLE(Ctrajectory_analysis_control, wxPanel)
	EVT_PAINT(Ctrajectory_analysis_control::On_Paint)
	EVT_MOTION(Ctrajectory_analysis_control::On_Mouse_Motion)
	EVT_MOUSEWHEEL(Ctrajectory_analysis_control::On_Mouse_Wheel)
	EVT_LEFT_DOWN(Ctrajectory_analysis_control::On_Mouse_LDown)
	EVT_LEFT_UP(Ctrajectory_analysis_control::On_Mouse_LUp)
END_EVENT_TABLE()


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
Ctrajectory_analysis_control::Ctrajectory_analysis_control(wxWindow *pParent, CSG_Shapes *pSensorData, CSG_Shapes *pFloor,
	CSG_Shapes *pSensorpoint, CSG_Parameters &Settings)
: wxPanel(pParent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL | wxSUNKEN_BORDER | wxNO_FULL_REPAINT_ON_RESIZE)
{
	m_pSensorData = pSensorData;
	m_pFloor = pFloor;
	m_pSensorpoint = pSensorpoint;
	m_pSettings = &Settings;
	r_Scale = 0.65;
	t_Xshift = -400;
	t_Yshift = 0;
}

//---------------------------------------------------------
Ctrajectory_analysis_control::~Ctrajectory_analysis_control(void)
{
}

///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------

void Ctrajectory_analysis_control::On_Paint(wxPaintEvent &WXUNUSED(event))
{
	 m_Bitmap = _Draw_Image(r_ID, defaultID);
	 //m_Bitmap = wxBitmap("G:\\CAUSTA_NEW\\src\\src\\STEngine\\background.png", wxBITMAP_TYPE_PNG);

	 wxPaintDC	dc(this);

	 dc.DrawBitmap(m_Bitmap, 0, 0, false);
}

//---------------------------------------------------------
void Ctrajectory_analysis_control::Update_View(vector<int> r_ID, int idCode)
{
	if (idCode == -1 || idCode == 0)
	{
		m_Bitmap = _Draw_Image(r_ID, idCode);
		wxClientDC	dc(this);
		dc.DrawBitmap(m_Bitmap, 0, 0, false);
	}


	if (idCode == 2)
	{
		if ( r_ID.size() != 0 )
		{
			for (int i = 0; i < r_ID.size(); i++)
			{
				store_id.push_back(r_ID[i]);
			}
			store_id = _Delete_ID(store_id);
		}
		else
		{
			store_id.clear();
		}
		m_Bitmap = _Draw_Image(r_ID, idCode);
		if ( store_id.size() != 0 )
		{
			m_Bitmap = _Draw_Rect(r_ID);
		}

		wxClientDC	dc(this);
		dc.DrawBitmap(m_Bitmap, 0, 0, false);
	}
}

//---------------------------------------------------------
void Ctrajectory_analysis_control::Update_View(vector<vector<int>> drawdata, int judge)
{

	vector<int> nullid;
	if ( judge == 0 )
	{
		m_Bitmap = _Draw_Image(nullid, -1);
	}
	m_Bitmap = _Draw_Traj(drawdata);
	wxClientDC	dc(this);
	dc.DrawBitmap(m_Bitmap, 0, 0, false);

}


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

#define GET_MOUSE_X_RELDIFF	((double)(m_Mouse_Down.x - event.GetX()) / (double)GetClientSize().x)
#define GET_MOUSE_Y_RELDIFF	((double)(m_Mouse_Down.y - event.GetY()) / (double)GetClientSize().y)

//---------------------------------------------------------
void Ctrajectory_analysis_control::On_Mouse_LUp(wxMouseEvent &event)
{
	if( HasCapture() )
	{
		ReleaseMouse();
	}
}

//---------------------------------------------------------
void Ctrajectory_analysis_control::On_Mouse_LDown(wxMouseEvent &event)
{
	SetFocus();

	m_Mouse_Down = event.GetPosition();

	if (!HasCapture())
	{
		CaptureMouse();
	}
}

//---------------------------------------------------------
void Ctrajectory_analysis_control::On_Mouse_Motion(wxMouseEvent &event)
{
	if (HasCapture() && event.Dragging())
	{
		if (event.LeftIsDown())
		{
			t_Xshift += GET_MOUSE_X_RELDIFF * 30;
			t_Yshift += GET_MOUSE_Y_RELDIFF * 30;
		}
		else
		{
			return;
		}

		Update_View(r_ID,defaultID);
	}
}

//---------------------------------------------------------
void Ctrajectory_analysis_control::On_Mouse_Wheel(wxMouseEvent &event)
{
	if (event.GetWheelRotation())
	{
		r_Scale += event.GetWheelRotation() / 1000.0;

		Update_View(r_ID,defaultID);
	}
}

///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////


//---------------------------------------------------------
wxBitmap Ctrajectory_analysis_control::_Draw_Image(vector<int> r_ID, int idCode)
{
	wxSize	dcSize = this->GetSize();
	wxBitmap new_Bitmap;
	if (!new_Bitmap.IsOk() || dcSize.x != new_Bitmap.GetWidth() || dcSize.y != new_Bitmap.GetHeight())
	{
		new_Bitmap.Create(dcSize.x, dcSize.y);
	}
	wxMemoryDC mdc(new_Bitmap);
	mdc.SetLogicalOrigin(t_Xshift, t_Yshift);
	mdc.SetUserScale(r_Scale, r_Scale);
	mdc.SetPen(*wxWHITE_PEN);
	DCRect = this->GetClientRect();
	_Draw_Shp(mdc, DCRect,r_ID, idCode);
	mdc.SelectObject(wxNullBitmap);
	mdc.Clear();
	return new_Bitmap;
}

//---------------------------------------------------------
void Ctrajectory_analysis_control::_Draw_Shp(wxMemoryDC &mdc, wxRect &DCRect, vector<int> r_ID, int idCode)
{
	for (int i = 0; i < m_pFloor->Get_Count(); i++)
	{
		_Draw_ShpPolyline(mdc, DCRect, m_pFloor->Get_Shape(i));
	}

	for (int i = 0; i < m_pSensorData->Get_Count(); i++)
	{
		_Draw_ShpPolygon(mdc, DCRect, m_pSensorData->Get_Shape(i));
	}

	for (int i = 0; i < m_pSensorpoint->Get_Count(); i++)
	{
		_Draw_ShpPoint(mdc, DCRect, m_pSensorpoint->Get_Shape(i), r_ID);
	}
}

//---------------------------------------------------------
void Ctrajectory_analysis_control::_Draw_ShpPoint(wxMemoryDC &mdc, wxRect &DCRect, CSG_Shape *t_Point, vector<int> r_ID)
{
	int flag = 0;
	double Radius = (DCRect.GetLeft() - DCRect.GetRight()) / 250;
	if ( r_ID.size()!=0 )
	{
		for (int i = 0; i < r_ID.size(); i++)
		{
			if (t_Point->Get_Value(0)->asInt() == r_ID[i])
			{
				flag = 1;
			}
		}
	}
	if ( flag == 1 )
	{
		mdc.SetBrush(*wxGREEN_BRUSH);
		wPoint.x = t_Point->Get_Point(0).x;
		wPoint.y = t_Point->Get_Point(0).y;
		mdc.DrawCircle(wPoint, Radius);
	}
	else
	{
		mdc.SetBrush(*wxRED_BRUSH);
		wPoint.x = t_Point->Get_Point(0).x;
		wPoint.y = t_Point->Get_Point(0).y;
		mdc.DrawCircle(wPoint, Radius);
	}
}

//---------------------------------------------------------
void Ctrajectory_analysis_control::_Draw_ShpPolyline(wxMemoryDC &mdc, wxRect &DCRect, CSG_Shape *t_Line)
{
	mdc.SetBrush(*wxGREY_BRUSH);
	if ( t_Line->Get_Part_Count() > 1 )
	{
		for (int i = 0; i < t_Line->Get_Part_Count(); i++)
		{
			PointList = new wxPoint[5];
			for (int j = 0; j < 5; j++)
			{
				PointList[j].x = t_Line->Get_Point(j,i).x;
				PointList[j].y = t_Line->Get_Point(j,i).y;
			}
			mdc.DrawLines(5, PointList);
			PointList = NULL;
		}
	}
	else
	{
		PointList = new wxPoint[t_Line->Get_Point_Count()];
		for (int i = 0; i < t_Line->Get_Point_Count(); i++)
		{
			PointList[i].x = t_Line->Get_Point(i).x;
			PointList[i].y = t_Line->Get_Point(i).y;
		}
		mdc.DrawLines(t_Line->Get_Point_Count(), PointList);
		PointList = NULL;
	}
	
}

//---------------------------------------------------------
void Ctrajectory_analysis_control::_Draw_ShpPolygon(wxMemoryDC &mdc, wxRect &DCRect, CSG_Shape *t_Polygon)
{
	PointList = new wxPoint[t_Polygon-> Get_Point_Count()];

	for (int i = 0; i < t_Polygon->Get_Point_Count(); i++)
	{
		PointList[i].x = t_Polygon->Get_Point(i).x;
		PointList[i].y = t_Polygon->Get_Point(i).y;
	}

	mdc.DrawPolygon(t_Polygon->Get_Point_Count(), PointList);
	PointList = NULL;
}

//---------------------------------------------------------
wxBitmap Ctrajectory_analysis_control::_ini_Bitmap(void)
{
	wxBitmap bitmap(this->GetSize().GetWidth(), this->GetSize().GetHeight());
	return bitmap;
}

//---------------------------------------------------------
wxBitmap Ctrajectory_analysis_control::_Draw_Rect(vector<int> r_ID)
{
	wxMemoryDC mdc(m_Bitmap);
	mdc.SetLogicalOrigin(t_Xshift, t_Yshift);
	mdc.SetUserScale(r_Scale, r_Scale);
	mdc.SetPen(*wxRED_PEN);
	wxBrush brush(wxColour(10, 10, 10), wxTRANSPARENT);
	mdc.SetBrush(brush);
	for (int i = 0; i < m_pSensorpoint->Get_Count(); i++)
	{
		for (int j = 0; j < store_id.size(); j++)
		{
			if (m_pSensorpoint->Get_Shape(i)->Get_Value(0)->asInt() == store_id[j])
			{

				mdc.DrawRectangle(m_pSensorpoint->Get_Shape(i)->Get_Point(0).x-30, m_pSensorpoint->Get_Shape(i)->Get_Point(0).y -30, 60, 60);
			}
		}
	}
	mdc.SelectObject(wxNullBitmap);
	mdc.Clear();
	return m_Bitmap;
}

//---------------------------------------------------------
wxBitmap Ctrajectory_analysis_control::_Draw_Traj(vector<vector<int>> drawdata)
{
	wxMemoryDC mdc(m_Bitmap);
	mdc.SetLogicalOrigin(t_Xshift, t_Yshift);
	mdc.SetUserScale(r_Scale, r_Scale);
	wxPen pen(*wxYELLOW, 3);
	mdc.SetPen(pen);

	for (int j = 0; j < drawdata.size(); j++)
	{
		for (int k = 0; k < drawdata[j].size() - 1; k++)
		{
			double x1, y1, x2, y2;

			for (int i = 0; i < m_pSensorpoint->Get_Count(); i++)
			{
				if (m_pSensorpoint->Get_Shape(i)->Get_Value(0)->asInt() == drawdata[j][k])
				{
					x1 = m_pSensorpoint->Get_Shape(i)->Get_Point(0).x;
					y1 = m_pSensorpoint->Get_Shape(i)->Get_Point(0).y;
				}
				if (m_pSensorpoint->Get_Shape(i)->Get_Value(0)->asInt() == drawdata[j][k+1])
				{
					x2 = m_pSensorpoint->Get_Shape(i)->Get_Point(0).x;
					y2 = m_pSensorpoint->Get_Shape(i)->Get_Point(0).y;
				}
			}
			mdc.DrawLine(wxPoint(x1, y1), wxPoint(x2, y2));
		}

	}
	mdc.SelectObject(wxNullBitmap);
	mdc.Clear();
	return m_Bitmap;
}

//---------------------------------------------------------
vector<int> Ctrajectory_analysis_control::_Delete_ID(vector<int> store_id)
{
	sort(store_id.begin(), store_id.end());
	store_id.erase(unique(store_id.begin(), store_id.end()), store_id.end());
	return store_id;
}

///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////
