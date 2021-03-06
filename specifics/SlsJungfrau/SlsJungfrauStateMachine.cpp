/*----- PROTECTED REGION ID(SlsJungfrauStateMachine.cpp) ENABLED START -----*/
static const char *RcsId = "$Id:  $";
//=============================================================================
//
// file :        SlsJungfrauStateMachine.cpp
//
// description : State machine file for the SlsJungfrau class
//
// project :     Sls dectector TANGO specific device.
//
// This file is part of Tango device class.
// 
// Tango is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Tango is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Tango.  If not, see <http://www.gnu.org/licenses/>.
// 
// $Author:  $
//
// $Revision:  $
// $Date:  $
//
// $HeadURL:  $
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================

#include <SlsJungfrau.h>

/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::SlsJungfrauStateMachine.cpp

//================================================================
//  States   |  Description
//================================================================
//  INIT     |  
//  STANDBY  |  
//  FAULT    |  
//  RUNNING  |  


namespace SlsJungfrau_ns
{
//=================================================
//		Attributes Allowed Methods
//=================================================

//--------------------------------------------------------
/**
 *	Method      : SlsJungfrau::is_clockDivider_allowed()
 *	Description : Execution allowed for clockDivider attribute
 */
//--------------------------------------------------------
bool SlsJungfrau::is_clockDivider_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Check access type.
	if ( type!=Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for WRITE 
		if (get_state()==Tango::INIT ||
			get_state()==Tango::FAULT ||
			get_state()==Tango::RUNNING)
		{
		/*----- PROTECTED REGION ID(SlsJungfrau::clockDividerStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::clockDividerStateAllowed_WRITE
			return false;
		}
		return true;
	}
	else

	//	Check access type.
	if ( type==Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for READ 
		if (get_state()==Tango::INIT ||
			get_state()==Tango::FAULT)
		{
		/*----- PROTECTED REGION ID(SlsJungfrau::clockDividerStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::clockDividerStateAllowed_READ
			return false;
		}
		return true;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : SlsJungfrau::is_configFileName_allowed()
 *	Description : Execution allowed for configFileName attribute
 */
//--------------------------------------------------------
bool SlsJungfrau::is_configFileName_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Check access type.
	if ( type==Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for READ 
		if (get_state()==Tango::INIT ||
			get_state()==Tango::FAULT)
		{
		/*----- PROTECTED REGION ID(SlsJungfrau::configFileNameStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::configFileNameStateAllowed_READ
			return false;
		}
		return true;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : SlsJungfrau::is_delayAfterTrigger_allowed()
 *	Description : Execution allowed for delayAfterTrigger attribute
 */
//--------------------------------------------------------
bool SlsJungfrau::is_delayAfterTrigger_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Check access type.
	if ( type!=Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for WRITE 
		if (get_state()==Tango::INIT ||
			get_state()==Tango::FAULT ||
			get_state()==Tango::RUNNING)
		{
		/*----- PROTECTED REGION ID(SlsJungfrau::delayAfterTriggerStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::delayAfterTriggerStateAllowed_WRITE
			return false;
		}
		return true;
	}
	else

	//	Check access type.
	if ( type==Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for READ 
		if (get_state()==Tango::INIT ||
			get_state()==Tango::FAULT)
		{
		/*----- PROTECTED REGION ID(SlsJungfrau::delayAfterTriggerStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::delayAfterTriggerStateAllowed_READ
			return false;
		}
		return true;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : SlsJungfrau::is_detectorFirmwareVersion_allowed()
 *	Description : Execution allowed for detectorFirmwareVersion attribute
 */
//--------------------------------------------------------
bool SlsJungfrau::is_detectorFirmwareVersion_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Check access type.
	if ( type==Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for READ 
		if (get_state()==Tango::INIT ||
			get_state()==Tango::FAULT)
		{
		/*----- PROTECTED REGION ID(SlsJungfrau::detectorFirmwareVersionStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::detectorFirmwareVersionStateAllowed_READ
			return false;
		}
		return true;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : SlsJungfrau::is_detectorSoftwareVersion_allowed()
 *	Description : Execution allowed for detectorSoftwareVersion attribute
 */
//--------------------------------------------------------
bool SlsJungfrau::is_detectorSoftwareVersion_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Check access type.
	if ( type==Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for READ 
		if (get_state()==Tango::INIT ||
			get_state()==Tango::FAULT)
		{
		/*----- PROTECTED REGION ID(SlsJungfrau::detectorSoftwareVersionStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::detectorSoftwareVersionStateAllowed_READ
			return false;
		}
		return true;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : SlsJungfrau::is_gainMode_allowed()
 *	Description : Execution allowed for gainMode attribute
 */
//--------------------------------------------------------
bool SlsJungfrau::is_gainMode_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Check access type.
	if ( type!=Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for WRITE 
		if (get_state()==Tango::INIT ||
			get_state()==Tango::FAULT ||
			get_state()==Tango::RUNNING)
		{
		/*----- PROTECTED REGION ID(SlsJungfrau::gainModeStateAllowed_WRITE) ENABLED START -----*/
		
		/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::gainModeStateAllowed_WRITE
			return false;
		}
		return true;
	}
	else

	//	Check access type.
	if ( type==Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for READ 
		if (get_state()==Tango::INIT ||
			get_state()==Tango::FAULT)
		{
		/*----- PROTECTED REGION ID(SlsJungfrau::gainModeStateAllowed_READ) ENABLED START -----*/
		
		/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::gainModeStateAllowed_READ
			return false;
		}
		return true;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : SlsJungfrau::is_gainCoeffsFileName_allowed()
 *	Description : Execution allowed for gainCoeffsFileName attribute
 */
//--------------------------------------------------------
bool SlsJungfrau::is_gainCoeffsFileName_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Check access type.
	if ( type==Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for READ 
		if (get_state()==Tango::INIT ||
			get_state()==Tango::FAULT)
		{
		/*----- PROTECTED REGION ID(SlsJungfrau::gainCoeffsFileNameStateAllowed_READ) ENABLED START -----*/
		
		/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::gainCoeffsFileNameStateAllowed_READ
			return false;
		}
		return true;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : SlsJungfrau::is_pedestalFileName1_allowed()
 *	Description : Execution allowed for pedestalFileName1 attribute
 */
//--------------------------------------------------------
bool SlsJungfrau::is_pedestalFileName1_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Check access type.
	if ( type==Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for READ 
		if (get_state()==Tango::INIT ||
			get_state()==Tango::FAULT)
		{
		/*----- PROTECTED REGION ID(SlsJungfrau::pedestalFileName1StateAllowed_READ) ENABLED START -----*/
		
		/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::pedestalFileName1StateAllowed_READ
			return false;
		}
		return true;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : SlsJungfrau::is_pedestalFileName2_allowed()
 *	Description : Execution allowed for pedestalFileName2 attribute
 */
//--------------------------------------------------------
bool SlsJungfrau::is_pedestalFileName2_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Check access type.
	if ( type==Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for READ 
		if (get_state()==Tango::INIT ||
			get_state()==Tango::FAULT)
		{
		/*----- PROTECTED REGION ID(SlsJungfrau::pedestalFileName2StateAllowed_READ) ENABLED START -----*/
		
		/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::pedestalFileName2StateAllowed_READ
			return false;
		}
		return true;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : SlsJungfrau::is_pedestalFileName3_allowed()
 *	Description : Execution allowed for pedestalFileName3 attribute
 */
//--------------------------------------------------------
bool SlsJungfrau::is_pedestalFileName3_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Check access type.
	if ( type==Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for READ 
		if (get_state()==Tango::INIT ||
			get_state()==Tango::FAULT)
		{
		/*----- PROTECTED REGION ID(SlsJungfrau::pedestalFileName3StateAllowed_READ) ENABLED START -----*/
		
		/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::pedestalFileName3StateAllowed_READ
			return false;
		}
		return true;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : SlsJungfrau::is_gainCoeffsState_allowed()
 *	Description : Execution allowed for gainCoeffsState attribute
 */
//--------------------------------------------------------
bool SlsJungfrau::is_gainCoeffsState_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Check access type.
	if ( type==Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for READ 
		if (get_state()==Tango::INIT ||
			get_state()==Tango::FAULT)
		{
		/*----- PROTECTED REGION ID(SlsJungfrau::gainCoeffsStateStateAllowed_READ) ENABLED START -----*/
		
		/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::gainCoeffsStateStateAllowed_READ
			return false;
		}
		return true;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : SlsJungfrau::is_calibrationState_allowed()
 *	Description : Execution allowed for calibrationState attribute
 */
//--------------------------------------------------------
bool SlsJungfrau::is_calibrationState_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Check access type.
	if ( type==Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for READ 
		if (get_state()==Tango::INIT ||
			get_state()==Tango::FAULT)
		{
		/*----- PROTECTED REGION ID(SlsJungfrau::calibrationStateStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::calibrationStateStateAllowed_READ
			return false;
		}
		return true;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : SlsJungfrau::is_gainCoeffs1_allowed()
 *	Description : Execution allowed for gainCoeffs1 attribute
 */
//--------------------------------------------------------
bool SlsJungfrau::is_gainCoeffs1_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Check access type.
	if ( type==Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for READ 
		if (get_state()==Tango::INIT ||
			get_state()==Tango::FAULT ||
			get_state()==Tango::RUNNING)
		{
		/*----- PROTECTED REGION ID(SlsJungfrau::gainCoeffs1StateAllowed_READ) ENABLED START -----*/
		
		/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::gainCoeffs1StateAllowed_READ
			return false;
		}
		return true;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : SlsJungfrau::is_gainCoeffs2_allowed()
 *	Description : Execution allowed for gainCoeffs2 attribute
 */
//--------------------------------------------------------
bool SlsJungfrau::is_gainCoeffs2_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Check access type.
	if ( type==Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for READ 
		if (get_state()==Tango::INIT ||
			get_state()==Tango::FAULT ||
			get_state()==Tango::RUNNING)
		{
		/*----- PROTECTED REGION ID(SlsJungfrau::gainCoeffs2StateAllowed_READ) ENABLED START -----*/
		
		/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::gainCoeffs2StateAllowed_READ
			return false;
		}
		return true;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : SlsJungfrau::is_gainCoeffs3_allowed()
 *	Description : Execution allowed for gainCoeffs3 attribute
 */
//--------------------------------------------------------
bool SlsJungfrau::is_gainCoeffs3_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Check access type.
	if ( type==Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for READ 
		if (get_state()==Tango::INIT ||
			get_state()==Tango::FAULT ||
			get_state()==Tango::RUNNING)
		{
		/*----- PROTECTED REGION ID(SlsJungfrau::gainCoeffs3StateAllowed_READ) ENABLED START -----*/
		
		/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::gainCoeffs3StateAllowed_READ
			return false;
		}
		return true;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : SlsJungfrau::is_pedestal1_allowed()
 *	Description : Execution allowed for pedestal1 attribute
 */
//--------------------------------------------------------
bool SlsJungfrau::is_pedestal1_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Check access type.
	if ( type==Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for READ 
		if (get_state()==Tango::INIT ||
			get_state()==Tango::FAULT ||
			get_state()==Tango::RUNNING)
		{
		/*----- PROTECTED REGION ID(SlsJungfrau::pedestal1StateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::pedestal1StateAllowed_READ
			return false;
		}
		return true;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : SlsJungfrau::is_pedestal2_allowed()
 *	Description : Execution allowed for pedestal2 attribute
 */
//--------------------------------------------------------
bool SlsJungfrau::is_pedestal2_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Check access type.
	if ( type==Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for READ 
		if (get_state()==Tango::INIT ||
			get_state()==Tango::FAULT ||
			get_state()==Tango::RUNNING)
		{
		/*----- PROTECTED REGION ID(SlsJungfrau::pedestal2StateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::pedestal2StateAllowed_READ
			return false;
		}
		return true;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : SlsJungfrau::is_pedestal3_allowed()
 *	Description : Execution allowed for pedestal3 attribute
 */
//--------------------------------------------------------
bool SlsJungfrau::is_pedestal3_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Check access type.
	if ( type==Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for READ 
		if (get_state()==Tango::INIT ||
			get_state()==Tango::FAULT ||
			get_state()==Tango::RUNNING)
		{
		/*----- PROTECTED REGION ID(SlsJungfrau::pedestal3StateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::pedestal3StateAllowed_READ
			return false;
		}
		return true;
	}
	return true;
}

//=================================================
//		Commands Allowed Methods
//=================================================

//--------------------------------------------------------
/**
 *	Method      : SlsJungfrau::is_SetCmd_allowed()
 *	Description : Execution allowed for SetCmd attribute
 */
//--------------------------------------------------------
bool SlsJungfrau::is_SetCmd_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::INIT ||
		get_state()==Tango::RUNNING)
	{
	/*----- PROTECTED REGION ID(SlsJungfrau::SetCmdStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::SetCmdStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : SlsJungfrau::is_GetCmd_allowed()
 *	Description : Execution allowed for GetCmd attribute
 */
//--------------------------------------------------------
bool SlsJungfrau::is_GetCmd_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::INIT ||
		get_state()==Tango::RUNNING)
	{
	/*----- PROTECTED REGION ID(SlsJungfrau::GetCmdStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::GetCmdStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : SlsJungfrau::is_ResetCamera_allowed()
 *	Description : Execution allowed for ResetCamera attribute
 */
//--------------------------------------------------------
bool SlsJungfrau::is_ResetCamera_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::INIT ||
		get_state()==Tango::RUNNING)
	{
	/*----- PROTECTED REGION ID(SlsJungfrau::ResetCameraStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::ResetCameraStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : SlsJungfrau::is_Calibrate_allowed()
 *	Description : Execution allowed for Calibrate attribute
 */
//--------------------------------------------------------
bool SlsJungfrau::is_Calibrate_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::INIT ||
		get_state()==Tango::FAULT ||
		get_state()==Tango::RUNNING)
	{
	/*----- PROTECTED REGION ID(SlsJungfrau::CalibrateStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::CalibrateStateAllowed
		return false;
	}
	return true;
}

}	//	End of namespace
