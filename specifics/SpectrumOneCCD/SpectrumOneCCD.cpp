/*----- PROTECTED REGION ID(SpectrumOneCCD.cpp) ENABLED START -----*/
//=============================================================================
//
// file :        SpectrumOneCCD.cpp
//
// description : C++ source for the SpectrumOneCCD class and its commands.
//               The class is derived from Device. It represents the
//               CORBA servant object which will be accessed from the
//               network. All commands which can be executed on the
//               SpectrumOneCCD are implemented in this file.
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


#include <SpectrumOneCCD.h>
#include <SpectrumOneCCDClass.h>

/*----- PROTECTED REGION END -----*/	//	SpectrumOneCCD.cpp

/**
 *  SpectrumOneCCD class description:
 *    
 */

//================================================================
//  The following table gives the correspondence
//  between command and method names.
//
//  Command name  |  Method name
//================================================================
//  State         |  dev_state
//  Status        |  dev_status
//  Write         |  write
//  Read          |  read
//  Reboot        |  reboot
//  WhereAmI      |  where_am_i
//================================================================

//================================================================
//  Attributes managed is:
//================================================================
//================================================================

namespace SpectrumOneCCD_ns
{
/*----- PROTECTED REGION ID(SpectrumOneCCD::namespace_starting) ENABLED START -----*/

//	static initializations

/*----- PROTECTED REGION END -----*/	//	SpectrumOneCCD::namespace_starting

//--------------------------------------------------------
/**
 *	Method      : SpectrumOneCCD::SpectrumOneCCD()
 *	Description : Constructors for a Tango device
 *                implementing the classSpectrumOneCCD
 */
//--------------------------------------------------------
SpectrumOneCCD::SpectrumOneCCD(Tango::DeviceClass *cl, string &s)
 : TANGO_BASE_CLASS(cl, s.c_str())
{
	/*----- PROTECTED REGION ID(SpectrumOneCCD::constructor_1) ENABLED START -----*/
	init_device();
	
	/*----- PROTECTED REGION END -----*/	//	SpectrumOneCCD::constructor_1
}
//--------------------------------------------------------
SpectrumOneCCD::SpectrumOneCCD(Tango::DeviceClass *cl, const char *s)
 : TANGO_BASE_CLASS(cl, s)
{
	/*----- PROTECTED REGION ID(SpectrumOneCCD::constructor_2) ENABLED START -----*/
	init_device();
	
	/*----- PROTECTED REGION END -----*/	//	SpectrumOneCCD::constructor_2
}
//--------------------------------------------------------
SpectrumOneCCD::SpectrumOneCCD(Tango::DeviceClass *cl, const char *s, const char *d)
 : TANGO_BASE_CLASS(cl, s, d)
{
	/*----- PROTECTED REGION ID(SpectrumOneCCD::constructor_3) ENABLED START -----*/
	init_device();
	
	/*----- PROTECTED REGION END -----*/	//	SpectrumOneCCD::constructor_3
}

//--------------------------------------------------------
/**
 *	Method      : SpectrumOneCCD::delete_device()
 *	Description : will be called at device destruction or at init command
 */
//--------------------------------------------------------
void SpectrumOneCCD::delete_device()
{
	DEBUG_STREAM << "SpectrumOneCCD::delete_device() " << device_name << endl;
	/*----- PROTECTED REGION ID(SpectrumOneCCD::delete_device) ENABLED START -----*/
	
	//	Delete device allocated objects
    m_is_device_initialized = false;
    // INFO_STREAM << "Remove the inner-appender." << std::endl;
    // yat4tango::InnerAppender::release(this);

	
	/*----- PROTECTED REGION END -----*/	//	SpectrumOneCCD::delete_device
}

//--------------------------------------------------------
/**
 *	Method      : SpectrumOneCCD::init_device()
 *	Description : will be called at device initialization.
 */
//--------------------------------------------------------
void SpectrumOneCCD::init_device()
{
	DEBUG_STREAM << "SpectrumOneCCD::init_device() create device " << device_name << endl;
	/*----- PROTECTED REGION ID(SpectrumOneCCD::init_device_before) ENABLED START -----*/
	
	//	Initialization before get_device_property() call

    m_is_device_initialized = false;
    m_status_message.str("");

    // try
    // {
    //     INFO_STREAM << "Create the inner-appender in order to manage logs." << std::endl;  
    //     yat4tango::InnerAppender::initialize(this, 512);
    // }
    // catch (...)
    // {
    //     ERROR_STREAM << "Error when creating the inner-appender, ignoring..." << std::endl;
    // }
	
	/*----- PROTECTED REGION END -----*/	//	SpectrumOneCCD::init_device_before
	

	//	Get the device properties from database
	get_device_property();
	
	/*----- PROTECTED REGION ID(SpectrumOneCCD::init_device) ENABLED START -----*/
	
	//	Initialize device


    try
    {
        // Get the main camera object
        m_ct = ControlFactory::instance().get_control("SpectrumOneCCD");

        // Get interface to the camera
        m_hw = dynamic_cast<SpectrumOne::Interface*>(m_ct->hwInterface());

        m_camera = m_hw->getCamera();

        m_is_device_initialized = true;
    }
    catch (Tango::DevFailed& df)
    {
        m_status_message << "Initialization Failed! Error: ";
        m_status_message << std::string(df.errors[0].desc) << std::endl;
        ERROR_STREAM << m_status_message.str();
    }
    catch(Exception& e)
    {
        m_status_message << "Initialization Failed! Error: " << e.getErrMsg() << std::endl;
        ERROR_STREAM << m_status_message.str();
    }
    catch(...)
    {
        m_status_message << "Initialization Failed : Unknown error!" << std::endl;
        ERROR_STREAM << m_status_message.str();
    }

	
	/*----- PROTECTED REGION END -----*/	//	SpectrumOneCCD::init_device
}

//--------------------------------------------------------
/**
 *	Method      : SpectrumOneCCD::get_device_property()
 *	Description : Read database to initialize property data members.
 */
//--------------------------------------------------------
void SpectrumOneCCD::get_device_property()
{
	/*----- PROTECTED REGION ID(SpectrumOneCCD::get_device_property_before) ENABLED START -----*/
	
	//	Initialize property data members
	
	/*----- PROTECTED REGION END -----*/	//	SpectrumOneCCD::get_device_property_before


	//	Read device properties from database.
	Tango::DbData	dev_prop;
	dev_prop.push_back(Tango::DbDatum("GpibAddress"));
	dev_prop.push_back(Tango::DbDatum("Port"));
	dev_prop.push_back(Tango::DbDatum("Host"));
	dev_prop.push_back(Tango::DbDatum("ReadTimeout"));
	dev_prop.push_back(Tango::DbDatum("TablesPath"));

	//	is there at least one property to be read ?
	if (dev_prop.size()>0)
	{
		//	Call database and extract values
		if (Tango::Util::instance()->_UseDb==true)
			get_db_device()->get_property(dev_prop);
	
		//	get instance on SpectrumOneCCDClass to get class property
		Tango::DbDatum	def_prop, cl_prop;
		SpectrumOneCCDClass	*ds_class =
			(static_cast<SpectrumOneCCDClass *>(get_device_class()));
		int	i = -1;

		//	Try to initialize GpibAddress from class property
		cl_prop = ds_class->get_class_property(dev_prop[++i].name);
		if (cl_prop.is_empty()==false)	cl_prop  >>  gpibAddress;
		else {
			//	Try to initialize GpibAddress from default device value
			def_prop = ds_class->get_default_device_property(dev_prop[i].name);
			if (def_prop.is_empty()==false)	def_prop  >>  gpibAddress;
		}
		//	And try to extract GpibAddress value from database
		if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  gpibAddress;

		//	Try to initialize Port from class property
		cl_prop = ds_class->get_class_property(dev_prop[++i].name);
		if (cl_prop.is_empty()==false)	cl_prop  >>  port;
		else {
			//	Try to initialize Port from default device value
			def_prop = ds_class->get_default_device_property(dev_prop[i].name);
			if (def_prop.is_empty()==false)	def_prop  >>  port;
		}
		//	And try to extract Port value from database
		if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  port;

		//	Try to initialize Host from class property
		cl_prop = ds_class->get_class_property(dev_prop[++i].name);
		if (cl_prop.is_empty()==false)	cl_prop  >>  host;
		else {
			//	Try to initialize Host from default device value
			def_prop = ds_class->get_default_device_property(dev_prop[i].name);
			if (def_prop.is_empty()==false)	def_prop  >>  host;
		}
		//	And try to extract Host value from database
		if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  host;

		//	Try to initialize ReadTimeout from class property
		cl_prop = ds_class->get_class_property(dev_prop[++i].name);
		if (cl_prop.is_empty()==false)	cl_prop  >>  readTimeout;
		else {
			//	Try to initialize ReadTimeout from default device value
			def_prop = ds_class->get_default_device_property(dev_prop[i].name);
			if (def_prop.is_empty()==false)	def_prop  >>  readTimeout;
		}
		//	And try to extract ReadTimeout value from database
		if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  readTimeout;

		//	Try to initialize TablesPath from class property
		cl_prop = ds_class->get_class_property(dev_prop[++i].name);
		if (cl_prop.is_empty()==false)	cl_prop  >>  tablesPath;
		else {
			//	Try to initialize TablesPath from default device value
			def_prop = ds_class->get_default_device_property(dev_prop[i].name);
			if (def_prop.is_empty()==false)	def_prop  >>  tablesPath;
		}
		//	And try to extract TablesPath value from database
		if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  tablesPath;

	}

	/*----- PROTECTED REGION ID(SpectrumOneCCD::get_device_property_after) ENABLED START -----*/
	
	//	Check device property data members init
    yat4tango::PropertyHelper::create_property_if_empty(this, dev_prop, "0", "GpibAddress");
    yat4tango::PropertyHelper::create_property_if_empty(this, dev_prop, "1234", "Port");
    yat4tango::PropertyHelper::create_property_if_empty(this, dev_prop, "127.0.0.1", "Host");
    yat4tango::PropertyHelper::create_property_if_empty(this, dev_prop, "100", "ReadTimeout");
    yat4tango::PropertyHelper::create_property_if_empty(this, dev_prop, "/usr/Local/configFiles/SpectrumOne", "TablesPath");
	
	/*----- PROTECTED REGION END -----*/	//	SpectrumOneCCD::get_device_property_after
}

//--------------------------------------------------------
/**
 *	Method      : SpectrumOneCCD::always_executed_hook()
 *	Description : method always executed before any command is executed
 */
//--------------------------------------------------------
void SpectrumOneCCD::always_executed_hook()
{
	DEBUG_STREAM << "SpectrumOneCCD::always_executed_hook()  " << device_name << endl;
	/*----- PROTECTED REGION ID(SpectrumOneCCD::always_executed_hook) ENABLED START -----*/
	
	//	code always executed before all requests
	
	/*----- PROTECTED REGION END -----*/	//	SpectrumOneCCD::always_executed_hook
}

//--------------------------------------------------------
/**
 *	Method      : SpectrumOneCCD::read_attr_hardware()
 *	Description : Hardware acquisition for attributes
 */
//--------------------------------------------------------
void SpectrumOneCCD::read_attr_hardware(TANGO_UNUSED(vector<long> &attr_list))
{
	DEBUG_STREAM << "SpectrumOneCCD::read_attr_hardware(vector<long> &attr_list) entering... " << endl;
	/*----- PROTECTED REGION ID(SpectrumOneCCD::read_attr_hardware) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	SpectrumOneCCD::read_attr_hardware
}


//--------------------------------------------------------
/**
 *	Method      : SpectrumOneCCD::add_dynamic_attributes()
 *	Description : Create the dynamic attributes if any
 *                for specified device.
 */
//--------------------------------------------------------
void SpectrumOneCCD::add_dynamic_attributes()
{
	/*----- PROTECTED REGION ID(SpectrumOneCCD::add_dynamic_attributes) ENABLED START -----*/
	
	//	Add your own code to create and add dynamic attributes if any
	
	/*----- PROTECTED REGION END -----*/	//	SpectrumOneCCD::add_dynamic_attributes
}

//--------------------------------------------------------
/**
 *	Command State related method
 *	Description: This command gets the device state (stored in its device_state data member) and returns it to the caller.
 *
 *	@returns Device state
 */
//--------------------------------------------------------
Tango::DevState SpectrumOneCCD::dev_state()
{
	DEBUG_STREAM << "SpectrumOneCCD::State()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(SpectrumOneCCD::dev_state) ENABLED START -----*/
	
	Tango::DevState	argout = Tango::UNKNOWN; // replace by your own algorithm
	//	Add your own code
    if(!m_is_device_initialized)
    {
        argout = Tango::FAULT;
    }
    else
    {
        argout = ControlFactory::instance().get_state();
    }
	
	/*----- PROTECTED REGION END -----*/	//	SpectrumOneCCD::dev_state
	set_state(argout);    // Give the state to Tango.
	if (argout!=Tango::ALARM)
		Tango::DeviceImpl::dev_state();
	return get_state();  // Return it after Tango management.
}
//--------------------------------------------------------
/**
 *	Command Status related method
 *	Description: This command gets the device status (stored in its device_status data member) and returns it to the caller.
 *
 *	@returns Device status
 */
//--------------------------------------------------------
Tango::ConstDevString SpectrumOneCCD::dev_status()
{
	DEBUG_STREAM << "SpectrumOneCCD::Status()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(SpectrumOneCCD::dev_status) ENABLED START -----*/
	
	string	status = "Device is OK";
	//	Add your own code

    if(!m_is_device_initialized)
    {
        status = m_status_message.str();
    }
    else
    {
        status = ControlFactory::instance().get_status();
    }
	
	/*----- PROTECTED REGION END -----*/	//	SpectrumOneCCD::dev_status
	set_status(status);               // Give the status to Tango.
	return Tango::DeviceImpl::dev_status();  // Return it.
}
//--------------------------------------------------------
/**
 *	Command Write related method
 *	Description: 
 *
 *	@param argin 
 */
//--------------------------------------------------------
void SpectrumOneCCD::write(Tango::DevString argin)
{
	DEBUG_STREAM << "SpectrumOneCCD::Write()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(SpectrumOneCCD::write) ENABLED START -----*/
	
	//	Add your own code
    std::string cmd(argin);
    m_camera->write(cmd);
	
	/*----- PROTECTED REGION END -----*/	//	SpectrumOneCCD::write
}
//--------------------------------------------------------
/**
 *	Command Read related method
 *	Description: 
 *
 *	@returns 
 */
//--------------------------------------------------------
Tango::DevString SpectrumOneCCD::read()
{
	Tango::DevString argout;
	DEBUG_STREAM << "SpectrumOneCCD::Read()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(SpectrumOneCCD::read) ENABLED START -----*/
	
	//	Add your own code
    std::string answer(m_camera->read());
    argout = new char[answer.size()+1];
    strcpy(argout, answer.c_str());

	
	/*----- PROTECTED REGION END -----*/	//	SpectrumOneCCD::read
	return argout;
}
//--------------------------------------------------------
/**
 *	Command Reboot related method
 *	Description: 
 *
 */
//--------------------------------------------------------
void SpectrumOneCCD::reboot()
{
	DEBUG_STREAM << "SpectrumOneCCD::Reboot()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(SpectrumOneCCD::reboot) ENABLED START -----*/
	
	//	Add your own code
    m_camera->rebootIfHung();
	
	/*----- PROTECTED REGION END -----*/	//	SpectrumOneCCD::reboot
}
//--------------------------------------------------------
/**
 *	Command WhereAmI related method
 *	Description: 
 *
 *	@returns 
 */
//--------------------------------------------------------
Tango::DevString SpectrumOneCCD::where_am_i()
{
	Tango::DevString argout;
	DEBUG_STREAM << "SpectrumOneCCD::WhereAmI()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(SpectrumOneCCD::where_am_i) ENABLED START -----*/
	
	//	Add your own code
    argout = new char[1];
    argout[0] = m_camera->whereAmI();
	
	/*----- PROTECTED REGION END -----*/	//	SpectrumOneCCD::where_am_i
	return argout;
}
//--------------------------------------------------------
/**
 *	Method      : SpectrumOneCCD::add_dynamic_commands()
 *	Description : Create the dynamic commands if any
 *                for specified device.
 */
//--------------------------------------------------------
void SpectrumOneCCD::add_dynamic_commands()
{
	/*----- PROTECTED REGION ID(SpectrumOneCCD::add_dynamic_commands) ENABLED START -----*/
	
	//	Add your own code to create and add dynamic commands if any
	
	/*----- PROTECTED REGION END -----*/	//	SpectrumOneCCD::add_dynamic_commands
}

/*----- PROTECTED REGION ID(SpectrumOneCCD::namespace_ending) ENABLED START -----*/

//	Additional Methods

/*----- PROTECTED REGION END -----*/	//	SpectrumOneCCD::namespace_ending
} //	namespace
