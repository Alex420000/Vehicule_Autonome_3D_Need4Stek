// This file is part of the URDF PLUGIN for V-REP
//  
// Copyright 2006-2016 Coppelia Robotics GmbH. All rights reserved. 
// marc@coppeliarobotics.com
// www.coppeliarobotics.com
// 
// A big thanks to Ignacio Tartavull and Martin Pecka for their precious help!
// 
// The URDF PLUGIN is licensed under the terms of GNU GPL:
// 
// -------------------------------------------------------------------
// The URDF PLUGIN is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// THE URDF PLUGIN IS DISTRIBUTED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
// WARRANTY. THE USER WILL USE IT AT HIS/HER OWN RISK. THE ORIGINAL
// AUTHORS AND COPPELIA ROBOTICS GMBH WILL NOT BE LIABLE FOR DATA LOSS,
// DAMAGES, LOSS OF PROFITS OR ANY OTHER KIND OF LOSS WHILE USING OR
// MISUSING THIS SOFTWARE.
// 
// See the GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with the URDF PLUGIN.  If not, see <http://www.gnu.org/licenses/>.
// -------------------------------------------------------------------

//
// This file was automatically created for V-REP release V3.3.1 Rev1 on May 17th 2016

// The URDF plugin is courtesy of Ignacio Tartavull and Martin Pecka.

#pragma once

#include "v_repLib.h"
#include <string>

#ifdef _WIN32
	#define VREP_DLLEXPORT extern "C" __declspec(dllexport)
#endif /* _WIN32 */
#if defined (__linux) || defined (__APPLE__)
	#define VREP_DLLEXPORT extern "C"
#endif /* __linux || __APPLE__ */

// The 3 required entry points of the V-REP plugin:
VREP_DLLEXPORT unsigned char v_repStart(void* reservedPointer,int reservedInt);
VREP_DLLEXPORT void v_repEnd();
VREP_DLLEXPORT void* v_repMessage(int message,int* auxiliaryData,void* customData,int* replyData);

void v_repImportUrdfCallback(SScriptCallBack* p);
VREP_DLLEXPORT simChar* v_repImportUrdf(const simChar* filenameOrUrdf, simBool hideCollisionLinks, simBool hideJoints, simBool convexDecomposeNonConvexCollidables, simBool createVisualIfNone, simBool showConvexDecompositionDlg, simBool centerAboveGround, simBool makeModel, simBool noSelfCollision, simBool positionCtrl);