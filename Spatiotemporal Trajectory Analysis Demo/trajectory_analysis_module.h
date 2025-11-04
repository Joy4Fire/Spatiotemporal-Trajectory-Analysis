///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
#ifndef HEADER_INCLUDED__trajectory_analysis_module_H
#define HEADER_INCLUDED__trajectory_analysis_module_H

//---------------------------------------------------------
#include "MLB_Interface.h"


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
// Use the 'trajectory_analysis_EXPORT' macro as defined in
// 'MLB_Interface.h' to export this class to allow other
// programs/libraries to use its functions:
//
// class trajectory_analysis_EXPORT Ctrajectory_analysis : public CSG_Module
// ...
//

class Ctrajectory_analysis : public CSG_Module
{
public:
	Ctrajectory_analysis(void);

	virtual bool			needs_GUI(void)	{ return(true); }


protected:

	virtual bool				On_Execute		(void);


private:

};


///////////////////////////////////////////////////////////
//														 //
//														 //
//														 //
///////////////////////////////////////////////////////////

//---------------------------------------------------------
#endif // #ifndef HEADER_INCLUDED__trajectory_analysis_module_H
