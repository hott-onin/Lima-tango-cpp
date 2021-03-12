/*----- PROTECTED REGION ID(SpectrumOneCCD.h) ENABLED START -----*/
//=============================================================================
//
// file :        SpectrumOneCCD.h
//
// description : Include file for the SpectrumOneCCD class
//
// project :     
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
//
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#ifndef SpectrumOneCCD_H
#define SpectrumOneCCD_H

#include <tango.h>

#include <PogoHelper.h>

#include <yat4tango/InnerAppender.h>
#include <yat4tango/PropertyHelper.h>

#include "Factory.h"

#include <lima/CtControl.h>

#include <SpectrumOneInterface.h>


/*----- PROTECTED REGION END -----*/	//	SpectrumOneCCD.h

/**
 *  SpectrumOneCCD class description:
 *    
 */

namespace SpectrumOneCCD_ns
{
/*----- PROTECTED REGION ID(SpectrumOneCCD::Additional Class Declarations) ENABLED START -----*/

//	Additional Class Declarations

/*----- PROTECTED REGION END -----*/	//	SpectrumOneCCD::Additional Class Declarations

class SpectrumOneCCD : public TANGO_BASE_CLASS
{

/*----- PROTECTED REGION ID(SpectrumOneCCD::Data Members) ENABLED START -----*/

//	Add your own data members
private:

    bool                    m_is_device_initialized;
    std::stringstream       m_status_message;

    lima::SpectrumOne::Interface*   m_hw;
    lima::SpectrumOne::Camera*      m_camera;
    lima::CtControl*                m_ct;


/*----- PROTECTED REGION END -----*/	//	SpectrumOneCCD::Data Members

//	Device property data members
public:
	//	GpibAddress:	Gpib Address of the controller (from 0 to 30)
	Tango::DevULong	gpibAddress;
	//	Port:	IP port of the controller
	Tango::DevULong	port;
	//	Host:	Host name or IP adress of the controller
	string	host;
	//	TablesPath:	Path of the tables to be loaded in the camera for its initialization
	string	tablesPath;
	//	ExpertConfig:	Advanced config for the camera
	vector<string>	expertConfig;
	//	InvertX:	Used to invert the X axis of the images
	Tango::DevBoolean	invertX;
	//	TablesMode:	Mode of the tables to send to the camera for its initialization.
	//  Is contained in the file names of the tables.
	//  For example the mode of XXXX1401.TAB is 1401.
	string	tablesMode;

//	Attribute data members
public:
	Tango::DevDouble	*attr_lastTemperature_read;
	Tango::DevLong	*attr_gain_read;

//	Constructors and destructors
public:
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	SpectrumOneCCD(Tango::DeviceClass *cl,string &s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	SpectrumOneCCD(Tango::DeviceClass *cl,const char *s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device name
	 *	@param d	Device description.
	 */
	SpectrumOneCCD(Tango::DeviceClass *cl,const char *s,const char *d);
	/**
	 * The device object destructor.
	 */
	~SpectrumOneCCD() {delete_device();};


//	Miscellaneous methods
public:
	/*
	 *	will be called at device destruction or at init command.
	 */
	void delete_device();
	/*
	 *	Initialize the device
	 */
	virtual void init_device();
	/*
	 *	Read the device properties from database
	 */
	void get_device_property();
	/*
	 *	Always executed method before execution command method.
	 */
	virtual void always_executed_hook();


//	Attribute methods
public:
	//--------------------------------------------------------
	/*
	 *	Method      : SpectrumOneCCD::read_attr_hardware()
	 *	Description : Hardware acquisition for attributes.
	 */
	//--------------------------------------------------------
	virtual void read_attr_hardware(vector<long> &attr_list);
	//--------------------------------------------------------
	/*
	 *	Method      : SpectrumOneCCD::write_attr_hardware()
	 *	Description : Hardware writing for attributes.
	 */
	//--------------------------------------------------------
	virtual void write_attr_hardware(vector<long> &attr_list);

/**
 *	Attribute lastTemperature related methods
 *	Description: Last temperature of the CCD
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_lastTemperature(Tango::Attribute &attr);
	virtual bool is_lastTemperature_allowed(Tango::AttReqType type);
/**
 *	Attribute gain related methods
 *	Description: Define CCD gain of the camera.
 *
 *	Data type:	Tango::DevLong
 *	Attr type:	Scalar
 */
	virtual void read_gain(Tango::Attribute &attr);
	virtual void write_gain(Tango::WAttribute &attr);
	virtual bool is_gain_allowed(Tango::AttReqType type);


	//--------------------------------------------------------
	/**
	 *	Method      : SpectrumOneCCD::add_dynamic_attributes()
	 *	Description : Add dynamic attributes if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_attributes();




//	Command related methods
public:
	/**
	 *	Command State related method
	 *	Description: This command gets the device state (stored in its device_state data member) and returns it to the caller.
	 *
	 *	@returns Device state
	 */
	virtual Tango::DevState dev_state();
	/**
	 *	Command Status related method
	 *	Description: This command gets the device status (stored in its device_status data member) and returns it to the caller.
	 *
	 *	@returns Device status
	 */
	virtual Tango::ConstDevString dev_status();
	/**
	 *	Command ForcedInit related method
	 *	Description: Force the initialization, injection of the tables and the reconfiguration of the camera
	 *
	 */
	virtual void forced_init();
	virtual bool is_ForcedInit_allowed(const CORBA::Any &any);
	/**
	 *	Command GetTemperature related method
	 *	Description: Get the temperature of the CCD sensor.
	 *               The temperature will be updated in the lastTemperature attribute.
	 *
	 */
	virtual void get_temperature();
	virtual bool is_GetTemperature_allowed(const CORBA::Any &any);
	/**
	 *	Command ReConfig related method
	 *	Description: Force the re-configuration of the camera.
	 *
	 */
	virtual void re_config();
	virtual bool is_ReConfig_allowed(const CORBA::Any &any);
	/**
	 *	Command SetNumFlushes related method
	 *	Description: Set the number of flushes for the acquisition
	 *
	 *	@param argin Number of flushes
	 */
	virtual void set_num_flushes(Tango::DevLong argin);
	virtual bool is_SetNumFlushes_allowed(const CORBA::Any &any);
	/**
	 *	Command GetGain related method
	 *	Description: Get the temperature of the camera.
	 *               The gain will be updated in the gain attribute.
	 *
	 */
	virtual void get_gain();
	virtual bool is_GetGain_allowed(const CORBA::Any &any);


	//--------------------------------------------------------
	/**
	 *	Method      : SpectrumOneCCD::add_dynamic_commands()
	 *	Description : Add dynamic commands if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_commands();

/*----- PROTECTED REGION ID(SpectrumOneCCD::Additional Method prototypes) ENABLED START -----*/

//	Additional Method prototypes

/*----- PROTECTED REGION END -----*/	//	SpectrumOneCCD::Additional Method prototypes
};

/*----- PROTECTED REGION ID(SpectrumOneCCD::Additional Classes Definitions) ENABLED START -----*/

//	Additional Classes Definitions

/*----- PROTECTED REGION END -----*/	//	SpectrumOneCCD::Additional Classes Definitions

}	//	End of namespace

#endif   //	SpectrumOneCCD_H
