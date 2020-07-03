static const char *RcsId = "$Id:  $";
//+=============================================================================
//
// file :         Mask.cpp
//
// description :  C++ source for the Mask and its commands. 
//                The class is derived from Device. It represents the
//                CORBA servant object which will be accessed from the
//                network. All commands which can be executed on the
//                Mask are implemented in this file.
//
// project :      TANGO Device Server
//
// $Author:  $
//
// $Revision:  $
//
// $Revision:  $
// $Date:  $
//
// SVN only:
// $HeadURL: $
//
// CVS only:
// $Source:  $
// $Log:  $
//
// copyleft :    Synchrotron SOLEIL 
//               L'Orme des merisiers - Saint Aubin
//               BP48 - 91192 Gif sur Yvette
//               FRANCE
//
//-=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================



//===================================================================
//
//	The following table gives the correspondence
//	between commands and method name.
//
//  Command name|  Method name
//	----------------------------------------
//  State   |  dev_state()
//  Status  |  dev_status()
//
//===================================================================


#ifdef WIN32
#include <tango.h>
#include <helpers/PogoHelper.h>
#endif

#include <Mask.h>
#include <MaskClass.h>

#ifndef WIN32
#include <tango.h>
#include <helpers/PogoHelper.h>
#endif



namespace Mask_ns
{

//+----------------------------------------------------------------------------
//
// method : 		Mask::Mask(string &s)
// 
// description : 	constructor for simulated Mask
//
// in : - cl : Pointer to the DeviceClass object
//      - s : Device name 
//
//-----------------------------------------------------------------------------
Mask::Mask(Tango::DeviceClass *cl, string &s)
:Tango::Device_4Impl(cl, s.c_str())
{
	init_device();
}
Mask::Mask(Tango::DeviceClass *cl, const char *s)
:Tango::Device_4Impl(cl, s)
{
	init_device();
}
Mask::Mask(Tango::DeviceClass *cl, const char *s, const char *d)
:Tango::Device_4Impl(cl, s, d)
{
	init_device();
}

//+----------------------------------------------------------------------------
//
// method : 		Mask::delete_device()
// 
// description : 	will be called at device destruction or at init command.
//
//-----------------------------------------------------------------------------
void Mask::delete_device()
{
	INFO_STREAM << "Mask::delete_device() delete device " << device_name << endl;
	yat::AutoMutex<> _lock(ControlFactory::instance().get_global_mutex());
		
	//	Delete device allocated objects	
	DELETE_DEVSTRING_ATTRIBUTE(attr_version_read);
	if(attr_maskImage_read)
	{
		delete[] attr_maskImage_read;
		attr_maskImage_read = 0;
	}
	
	INFO_STREAM << "Remove the inner-appender." << endl;
	yat4tango::InnerAppender::release(this);		
}

//+----------------------------------------------------------------------------
//
// method : 		Mask::init_device()
// 
// description : 	will be called at device initialization.
//
//-----------------------------------------------------------------------------
void Mask::init_device()
{
	INFO_STREAM << "Mask::init_device() create device " << device_name << endl;
	yat::AutoMutex<> _lock(ControlFactory::instance().get_global_mutex());
	// Initialise variables to default values
	//--------------------------------------------	
	get_device_property();
	CREATE_DEVSTRING_ATTRIBUTE(attr_version_read, 256);
	m_dim_x = 0;
	m_dim_y = 0;
	attr_maskImage_read = 0;
	m_operations_list.clear();
	//By default INIT, need to ensure that all objets are OK before set the device to STANDBY
	set_state(Tango::INIT);
	m_is_device_initialized = false;
	m_status_message.str("");
	attr_runLevel_write = memorizedRunLevel;
	
	//- instanciate the appender in order to manage logs
	INFO_STREAM << "Create the inner-appender in order to manage logs." << endl;
	yat4tango::InnerAppender::initialize(this, 512);	
	try
	{
		yat::AutoMutex<> _lock(ControlFactory::instance().get_global_mutex());
		//- get the main object used to pilot the lima framework
		//in fact LimaDetector is create the singleton control objet
		m_ct = ControlFactory::instance().get_control("Mask");
		
	//delete the operation	"AMask"		
    //remove external operations
	INFO_STREAM << "- remove all external operations ..."<<endl;	
	std::stringstream opId("");
	opId << ":Mask";
	INFO_STREAM << "\t- delOp [" << opId.str() << "]"<<endl;
	m_ct->externalOperation()->delOp(opId.str());		
	
	}
	catch(Exception& e)
	{
		INFO_STREAM << "Initialization Failed : " << e.getErrMsg() << endl;
		m_status_message << "Initialization Failed : " << e.getErrMsg() << endl;
		m_is_device_initialized = false;
		set_state(Tango::FAULT);
		return;
	}
	catch(...)
	{
		INFO_STREAM << "Initialization Failed : UNKNOWN" << endl;
		m_status_message << "Initialization Failed : UNKNOWN" << endl;
		set_state(Tango::FAULT);
		m_is_device_initialized = false;
		return;
	}

	try
	{
		Tango::WAttribute &runlevel = dev_attr->get_w_attr_by_name("runLevel");
		attr_runLevel_write = memorizedRunLevel;
		runlevel.set_write_value(attr_runLevel_write);
		write_runLevel(runlevel);
	}
	catch(Tango::DevFailed& df)
	{
		ERROR_STREAM << df << endl;
		m_status_message << "Initialization Failed : ";
		for(unsigned i = 0;i < df.errors.length();i++)
		{
			m_status_message << df.errors[i].desc << endl;
		}
		m_is_device_initialized = false;
		set_state(Tango::FAULT);
		return;
	}
	catch(Exception& e)
	{
		ERROR_STREAM << "Initialization Failed : " << e.getErrMsg() << endl;
		m_status_message << "Initialization Failed : " << e.getErrMsg() << endl;
		m_is_device_initialized = false;
		set_state(Tango::FAULT);
		return;
	}
	//everything is Ok
	m_is_device_initialized = true;	
	set_state(Tango::STANDBY);
	dev_state();
}

//+----------------------------------------------------------------------------
//
// method : 		Mask::get_device_property()
// 
// description : 	Read the device properties from database.
//
//-----------------------------------------------------------------------------
void Mask::get_device_property()
{
	//	Initialize your default values here (if not done with  POGO).
	//------------------------------------------------------------------

	//	Read device properties from database.(Automatic code generation)
	//------------------------------------------------------------------
	Tango::DbData	dev_prop;
	dev_prop.push_back(Tango::DbDatum("MemorizedRunLevel"));

	//	Call database and extract values
	//--------------------------------------------
	if (Tango::Util::instance()->_UseDb==true)
		get_db_device()->get_property(dev_prop);
	Tango::DbDatum	def_prop, cl_prop;
	MaskClass	*ds_class =
		(static_cast<MaskClass *>(get_device_class()));
	int	i = -1;

	//	Try to initialize MemorizedRunLevel from class property
	cl_prop = ds_class->get_class_property(dev_prop[++i].name);
	if (cl_prop.is_empty()==false)	cl_prop  >>  memorizedRunLevel;
	else {
		//	Try to initialize MemorizedRunLevel from default device value
		def_prop = ds_class->get_default_device_property(dev_prop[i].name);
		if (def_prop.is_empty()==false)	def_prop  >>  memorizedRunLevel;
	}
	//	And try to extract MemorizedRunLevel value from database
	if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  memorizedRunLevel;



	//	End of Automatic code generation
	//------------------------------------------------------------------
	yat4tango::PropertyHelper::create_property_if_empty(this, dev_prop, "0", "MemorizedRunLevel");
}

//+----------------------------------------------------------------------------
//
// method : 		Mask::always_executed_hook()
// 
// description : 	method always executed before any command is executed
//
//-----------------------------------------------------------------------------
void Mask::always_executed_hook()
{
	yat::AutoMutex<> _lock(ControlFactory::instance().get_global_mutex());
	try
	{
		if(!m_is_device_initialized)//nothing to do ! device need init
			return;

		//- get the singleton control objet used to pilot the lima framework
		m_ct = ControlFactory::instance().get_control("Mask");

		dev_state();
	}
	catch(Exception& e)
	{
		ERROR_STREAM << e.getErrMsg() << endl;
		m_status_message << "Initialization Failed : " << e.getErrMsg() << endl;
		//- throw exception
		set_state(Tango::FAULT);
		m_is_device_initialized = false;
		return;
	}
	catch(Tango::DevFailed& df)
	{
		ERROR_STREAM << df << endl;
		INFO_STREAM << "Initialization Failed : " << string(df.errors[0].desc) << endl;
		m_status_message << "Initialization Failed : " << string(df.errors[0].desc) << endl;
		m_is_device_initialized = false;
		set_state(Tango::FAULT);
		return;
	}
}
//+----------------------------------------------------------------------------
//
// method : 		Mask::read_attr_hardware
// 
// description : 	Hardware acquisition for attributes.
//
//-----------------------------------------------------------------------------
void Mask::read_attr_hardware(vector<long> &attr_list)
{
	DEBUG_STREAM << "Mask::read_attr_hardware(vector<long> &attr_list) entering... " << endl;
	//	Add your own code here
	try
	{

	}
	catch(Exception& e)
	{
		ERROR_STREAM << e.getErrMsg() << endl;
		//- throw exception
		Tango::Except::throw_exception("TANGO_DEVICE_ERROR",
									e.getErrMsg().c_str(),
									"Mask::read_attr_hardware");
	}
}
//+----------------------------------------------------------------------------
//
// method : 		Mask::read_operationsList
// 
// description : 	Extract real attribute values for operationsList acquisition result.
//
//-----------------------------------------------------------------------------
void Mask::read_operationsList(Tango::Attribute &attr)
{
	DEBUG_STREAM << "Mask::read_operationsList(Tango::Attribute &attr) entering... "<< endl;
	try
	{
		//list all operations
		Tango::DevString *ptr = new Tango::DevString[ 1024 ];

		int item_idx = 0;
		ptr[item_idx] = CORBA::string_dup("");
		for(int i = 0;i < m_operations_list.size();i++)
		{
			ptr[item_idx] = CORBA::string_dup(m_operations_list.at(i).c_str());
			item_idx++;
		}

		attr.set_value(ptr, item_idx, 0, true);
	}
	catch(Exception& e)
	{
		ERROR_STREAM << e.getErrMsg() << endl;
		//- throw exception
		THROW_DEVFAILED("TANGO_DEVICE_ERROR",
						e.getErrMsg().c_str(),
						"Mask::read_operationsList");
	}	
    catch(Tango::DevFailed& df)
    {
        ERROR_STREAM << df << endl;
        //- rethrow exception
        RETHROW_DEVFAILED(	df,
							"TANGO_DEVICE_ERROR",
							std::string(df.errors[0].desc).c_str(),
							"Mask::read_operationsList");
    }		
}

//+----------------------------------------------------------------------------
//
// method : 		Mask::read_maskImage
// 
// description : 	Extract real attribute values for maskImage acquisition result.
//
//-----------------------------------------------------------------------------
void Mask::read_maskImage(Tango::Attribute &attr)
{
	DEBUG_STREAM << "Mask::read_maskImage(Tango::Attribute &attr) entering... " << endl;
	//only if a write_maskImage was called previuosly
	if(m_dim_x != 0 && m_dim_y != 0)
		attr.set_value(attr_maskImage_read, m_dim_x, m_dim_y);
}

//+----------------------------------------------------------------------------
//
// method : 		Mask::write_maskImage
// 
// description : 	Write maskImage attribute values to hardware.
//
//-----------------------------------------------------------------------------
void Mask::write_maskImage(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "Mask::write_maskImage(Tango::WAttribute &attr) entering... " << endl;
	try
	{
		//	Retrieve number of write values	
		int w_length = attr.get_write_value_length();
		//	Retrieve pointer on write values (Do not delete !)	
		const Tango::DevShort *w_val;
		attr.get_write_value(w_val);
		const short * p;
		attr.get_write_value(p);

		m_dim_x = attr.get_w_dim_x();
		m_dim_y = attr.get_w_dim_y();
		if(attr_maskImage_read)
		{
			delete[] attr_maskImage_read;
			attr_maskImage_read = 0;
		}
		INFO_STREAM << "m_dim_x = " << m_dim_x << endl;
		INFO_STREAM << "m_dim_y = " << m_dim_y << endl;
		attr_maskImage_read = new Tango::DevShort[m_dim_x * m_dim_y];
		::memcpy(attr_maskImage_read, p, (m_dim_x * m_dim_y) * sizeof(Tango::DevShort));

		//prepare Data for the Mask ProcessLib Task	
		set_mask_image();
	}
	catch(ProcessException& p)
	{
		ERROR_STREAM << p.getErrMsg()<< endl;
		//- throw exception
		THROW_DEVFAILED("TANGO_DEVICE_ERROR",
						p.getErrMsg().c_str(),
						"Mask::write_maskImage");		
	}	
	catch(Exception& e)
	{
		ERROR_STREAM << e.getErrMsg() << endl;
		//- throw exception
		THROW_DEVFAILED("TANGO_DEVICE_ERROR",
						e.getErrMsg().c_str(),
						"Mask::write_maskImage");
	}
	catch(Tango::DevFailed& df)
	{
        ERROR_STREAM << df << endl;
        //- rethrow exception
        RETHROW_DEVFAILED(	df,
							"TANGO_DEVICE_ERROR",
							std::string(df.errors[0].desc).c_str(),
							"Mask::write_maskImage");
	}

	INFO_STREAM << "Mask Image is Defined and Activated ." << endl;
}

//+----------------------------------------------------------------------------
//
// method : 		Mask::read_runLevel
// 
// description : 	Extract real attribute values for runLevel acquisition result.
//
//-----------------------------------------------------------------------------
void Mask::read_runLevel(Tango::Attribute &attr)
{
	DEBUG_STREAM << "Mask::read_runLevel(Tango::Attribute &attr) entering... " << endl;
}

//+----------------------------------------------------------------------------
//
// method : 		Mask::write_runLevel
// 
// description : 	Write runLevel attribute values to hardware.
//
//-----------------------------------------------------------------------------
void Mask::write_runLevel(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "Mask::write_runLevel(Tango::WAttribute &attr) entering... " << endl;
	try
	{
		attr.get_write_value(attr_runLevel_write);		
		
		//prepare Data for the Mask ProcessLib Task	
		set_mask_image();
	}
	catch(Tango::DevFailed& df)
	{
		ERROR_STREAM << df << endl;
		//- rethrow exception
		Tango::Except::re_throw_exception(df,
										"TANGO_DEVICE_ERROR",
										string(df.errors[0].desc).c_str(),
										"Mask::write_runLevel");
	}
	catch(Exception& e)
	{
		ERROR_STREAM << e.getErrMsg() << endl;
		//- throw exception
		Tango::Except::throw_exception("TANGO_DEVICE_ERROR",
									e.getErrMsg().c_str(),
									"Mask::write_runLevel");
	}
}


//+----------------------------------------------------------------------------
//
// method : 		Mask::read_version
// 
// description : 	Extract real attribute values for version acquisition result.
//
//-----------------------------------------------------------------------------
void Mask::read_version(Tango::Attribute &attr)
{
	DEBUG_STREAM << "Mask::read_version(Tango::Attribute &attr) entering... " << endl;
	try
	{
		strcpy(*attr_version_read, MASK_CURRENT_VERSION);
		attr.set_value(attr_version_read);
	}
	catch(Tango::DevFailed& df)
	{
		ERROR_STREAM << df << endl;
		//- rethrow exception
		Tango::Except::re_throw_exception(df,
										"TANGO_DEVICE_ERROR",
										string(df.errors[0].desc).c_str(),
										"Mask::read_version()");
	}
}


//-----------------------------------------------------------------------------
//
// 	Mask::set_mask_image(void)
//-----------------------------------------------------------------------------
void Mask::set_mask_image(void)
{
	
	//only if a write_maskImage was called previously & device is already initialized !
	if(!is_device_initialized())
		return;
	
	if(m_dim_x == 0 || m_dim_y == 0)
	{
		Tango::Except::throw_exception(
										"TANGO_DEVICE_ERROR",
										"Cannot Define the Mask, the 'maskImage' attribute is Empty !",
										"Mask::set_mask_image()");	
		return;
	}
	
	try
	{			
		
		//get DetectorPixelDepth from LimaDetector Property
		std::string class_name = "LimaDetector";
		std::string device_name_generic;
		Tango::DbDatum db_datum;
		std::string server_name = Tango::Util::instance()->get_ds_name();
		db_datum = (Tango::Util::instance()->get_database())->get_device_name(server_name, class_name);
		db_datum >> device_name_generic;
		Tango::DbData db_data;
		db_data.push_back(Tango::DbDatum("DetectorPixelDepth"));
		(Tango::Util::instance()->get_database())->get_device_property(device_name_generic, db_data);
		std::string pixel_depth;
		db_data[0] >> pixel_depth;
		
		//prepare Data for the Mask ProcessLib Task	
		Data data;
		if(pixel_depth == "8")
		{
			data = create_data_from_mask<Tango::DevUChar>(attr_maskImage_read, m_dim_x, m_dim_y, Data::UINT8, 1);
		}
		else if(pixel_depth == "12" || pixel_depth == "16")
		{
			data = create_data_from_mask<Tango::DevUShort>(attr_maskImage_read, m_dim_x, m_dim_y, Data::UINT16, 2);
		}
		else if(pixel_depth == "16S")
		{
			data = create_data_from_mask<Tango::DevShort>(attr_maskImage_read, m_dim_x, m_dim_y, Data::INT16, 2);
		}		
		else if(pixel_depth == "24" || pixel_depth == "32")
		{
			data = create_data_from_mask<Tango::DevULong>(attr_maskImage_read, m_dim_x, m_dim_y, Data::UINT32, 4);
		}
		else if(pixel_depth == "32S")
		{
			data = create_data_from_mask<Tango::DevLong>(attr_maskImage_read, m_dim_x, m_dim_y, Data::INT32, 4);
		}
		else
		{
			stringstream ss;
			ss << "Failed to Create a Mask image !" << endl;
			ss << "DetectorPixelDepth " << "(" << pixel_depth << ") is not supported!" << endl;
			ERROR_STREAM << ss.str() << std::endl;
			Tango::Except::throw_exception("TANGO_DEVICE_ERROR",
										ss.str().c_str(),
										"Mask::write_maskImage");
		}

		//first delete the operation	"AMask"		
		std::stringstream opId("");
		opId << ":Mask";
		INFO_STREAM << "delOp [" << opId.str() << "]" << endl;
		m_ct->externalOperation()->delOp(opId.str());
		
		//INFO_STREAM<<(!m_soft_operation.m_opt) ? "deOp() NOT NECESSARY" : "deOp() NECESSARY"<<endl;
		//create new operation			
		INFO_STREAM << "addOp [" << opId.str() << "]" << endl;
		m_ct->externalOperation()->addOp(MASK, opId.str(), attr_runLevel_write, m_soft_operation);		
		yat4tango::PropertyHelper::set_property(this, "MemorizedRunLevel", attr_runLevel_write);
		
		//activate the Mask
		(reinterpret_cast<SoftOpMask*> (m_soft_operation.m_opt))->setMaskImage(data);
		
		//in order to update operationsList attribute		
		m_operations_list.clear();
		std::stringstream ss("");
		ss<<"runLevel = "<<attr_runLevel_write<<" : Operation = "<<"Mask"<<endl;
		m_operations_list.push_back(ss.str());
	}
	catch(ProcessException& p)
	{
		ERROR_STREAM << p.getErrMsg()<< endl;
		//- throw exception
		THROW_DEVFAILED("TANGO_DEVICE_ERROR",
						p.getErrMsg().c_str(),
						"Mask::write_maskImage");		
	}	
	catch(Exception& e)
	{
		ERROR_STREAM << e.getErrMsg() << endl;
		//- throw exception
		THROW_DEVFAILED("TANGO_DEVICE_ERROR",
						e.getErrMsg().c_str(),
						"Mask::write_maskImage");
	}
	catch(Tango::DevFailed& df)
	{
        ERROR_STREAM << df << endl;
        //- rethrow exception
        RETHROW_DEVFAILED(	df,
							"TANGO_DEVICE_ERROR",
							std::string(df.errors[0].desc).c_str(),
							"Mask::write_maskImage");
	}
}
//+------------------------------------------------------------------
/**
 *	method:	Mask::dev_state
 *
 *	description:	method to execute "State"
 *	This command gets the device state (stored in its <i>device_state</i> data member) and returns it to the caller.
 *
 * @return	State Code
 *
 */
//+------------------------------------------------------------------
Tango::DevState Mask::dev_state()
{
	Tango::DevState argout = DeviceImpl::dev_state();
	DEBUG_STREAM << "Mask::dev_state(): entering... !" << endl;
	//    Add your own code to control device here	
	stringstream DeviceStatus;
	DeviceStatus << "";
	Tango::DevState DeviceState = Tango::STANDBY;
	if(!m_is_device_initialized)
	{
		DeviceState = Tango::FAULT;
		DeviceStatus << m_status_message.str();
	}
	else
	{
		// state & status are retrieved from Factory, Factory is updated by Generic device
		DeviceState = ControlFactory::instance().get_state();
		DeviceStatus << ControlFactory::instance().get_status();
	}

	set_state(DeviceState);
	set_status(DeviceStatus.str());

	argout = DeviceState;
	return argout;
}










}	//	namespace
