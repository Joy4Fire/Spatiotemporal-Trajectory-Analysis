///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
#include "trajectory_analysis_module.h"
#include "trajectory_analysis_dialog.h"


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
Ctrajectory_analysis::Ctrajectory_analysis(void)
{
	Set_Name		(_TL("Module trajectory_analysis"));

	Set_Author		(SG_T("George Orwell (c) 1984"));

	Set_Description	(_TW(
		"This is a trajectory analysis module in "
	));

	Parameters.Add_Shapes(
		NULL, "SensorData", _TL("SensorData"),
		_TL(""),
		PARAMETER_INPUT
		);

	Parameters.Add_Shapes(
		NULL, "Floor", _TL("Floor"),
		_TL(""),
		PARAMETER_INPUT
		);

	Parameters.Add_Shapes(
		NULL, "SensorPoint", _TL("SensorPoint"),
		_TL(""),
		PARAMETER_INPUT
		);
} 


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
bool Ctrajectory_analysis::On_Execute(void)
{
	if (!SG_UI_Get_Window_Main())
	{
		Message_Add(_TL("Trajectory analysis viewer can only be run from graphical user interface"));

		return(false);
	}

	CSG_Shapes	*tPolygon = Parameters("SensorData")->asShapes();
	CSG_Shapes	*tLines = Parameters("Floor")->asShapes();
	CSG_Shapes	*tPoints = Parameters("SensorPoint")->asShapes();

	Ctrajectory_analysis_dialog	*dlg = new Ctrajectory_analysis_dialog(tPolygon, tLines, tPoints);

	dlg->Show(true);

	//wxWindow* parent = new wxWindow();
	//MyDialog1 *dlg = new MyDialog1(parent, wxID_ANY, wxT("PIR Data Management"), wxDefaultPosition, wxSize(470, 350), wxDEFAULT_DIALOG_STYLE);
	//dlg->Show(true);

	return(true);
}

///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
