/**********************************************************
* Version $Id: points_view_extent.h 1921 2014-01-09 10:24:11Z oconrad $
*********************************************************/

///////////////////////////////////////////////////////////
//                                                       //
//                         SAGA                          //
///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
#ifndef HEADER_INCLUDED__trajectory_analysis_tcalculate_H
#define HEADER_INCLUDED__trajectory_analysis_tcalculate_H


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
#include <stdio.h>  
#include <stdlib.h>  
#include <windows.h>  
#include <iostream>
#include <algorithm>


using namespace std;

///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
class Ctrajectory_analysis_tcalculate : public CSGDI_Dialog
{
public:

	struct LNode
	{
		LNode(){}
		int NodeID;
		int TopNodeID;
		int BottomNodeID;
		int LeftNodeID;
		int RightNodeID;
	};

	struct Tnode
	{
		Tnode() {
			NodeID = TopNodeID = BottomNodeID = LeftNodeID = RightNodeID = 0;
			ParentID = -1;
			isLeaf = false;
		}

		Tnode(LNode tmpNode)
		{
			NodeID = tmpNode.NodeID;
			TopNodeID = tmpNode.TopNodeID;
			BottomNodeID = tmpNode.BottomNodeID;
			LeftNodeID = tmpNode.LeftNodeID;
			RightNodeID = tmpNode.RightNodeID;
			isLeaf = false;
			ParentID = -1;
		}

		void clear(){
			NodeID = TopNodeID = BottomNodeID = LeftNodeID = RightNodeID = ParentID = 0;
			isLeaf = false;
			startime = 0;
			endtime = 0;
			ParentID = -1;
		}
		int NodeID, TopNodeID, BottomNodeID, LeftNodeID, RightNodeID, ParentID;
		long long startime, endtime;
		bool isLeaf;
	};

	Ctrajectory_analysis_tcalculate();

	vector<LNode>               tNode;
	vector<vector<int>>         traResult;

	void                        ComputePath(PGresult *res, vector<LNode> tNode);
	void                        Update();
	void                        UpdateView(vector<vector<int>> drawdata);
	wxStaticText                *m_statictext;

private:

	int                         count;
	vector<vector<int>>         drawdata;
	vector<vector<int>>         result;
	vector<Tnode>               trajectList;
	char                        *pghost, *pgport, *dbname, *user, *pwd;
	wxBitmap                    m_bitmap;
	wxImage                     m_image;
	PGconn                      *conn;
	wxStaticText				*m_sText1, *m_sText2, *m_sText3, *m_sText4, *m_sText5, *m_sText6;
	wxComboBox                  *m_comboBox1, *m_comboBox2;
	wxListBox                   *m_listBox1;

	wxStaticLine                *m_sline1, *m_sline2, *m_sline3, *m_sline4, *m_sline5;
	wxButton                    *m_button1;
	wxSlider                    *m_slider1;
	wxPanel                     *m_panel1;

	wxBitmap                    _DrawMatrix(vector<vector<int>> data, int count);
	vector<int>                 searchList(Tnode node, vector<Tnode> nodelist);
	LNode                       findNode(int NodeID, vector<LNode> nodelist);
	bool                        ifexist(int id, vector<Tnode> tmpList);
	bool                        isAdjacent(int start, int id, vector<Tnode> tmpList);
	PGconn*                     ConnectionToDB(PGconn *conn, char *pghost, char *pgport, char *dbname, char *user, char *pwd);
	PGresult*                   QueryTraj(CSG_String sql);

	DECLARE_EVENT_TABLE()
};

///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
#endif // #ifndef HEADER_INCLUDED__Ctrajectory_analysis_tcalculate_H

///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------