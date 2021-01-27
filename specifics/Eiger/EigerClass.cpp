static const char *ClassId    = "$Id:  $";
static const char *TagName    = "$Name:  $";
static const char *CvsPath    = "$Source:  $";
static const char *SvnPath    = "$HeadURL: $";
static const char *HttpServer = "http://www.esrf.fr/computing/cs/tango/tango_doc/ds_doc/";
//+=============================================================================
//
// file :        EigerClass.cpp
//
// description : C++ source for the EigerClass. A singleton
//               class derived from DeviceClass. It implements the
//               command list and all properties and methods required
//               by the Eiger once per process.
//
// project :     TANGO Device Server
//
// $Author:  $
//
// $Revision:  $
//
// $Log:  $
//
// copyleft :   European Synchrotron Radiation Facility
//              BP 220, Grenoble 38043
//              FRANCE
//
//-=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================


#include <tango.h>

#include <Eiger.h>
#include <EigerClass.h>


//+----------------------------------------------------------------------------
/**
 *	Create EigerClass singleton and return it in a C function for Python usage
 */
//+----------------------------------------------------------------------------
extern "C" {
#ifdef WIN32

__declspec(dllexport)

#endif

	Tango::DeviceClass *_create_Eiger_class(const char *name) {
		return Eiger_ns::EigerClass::init(name);
	}
}


namespace Eiger_ns
{
//+----------------------------------------------------------------------------
//
// method : 		UpdateTHClass::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be executed
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *UpdateTHClass::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "UpdateTHClass::execute(): arrived" << endl;

	((static_cast<Eiger *>(device))->update_th());
	return new CORBA::Any();
}

//+----------------------------------------------------------------------------
//
// method : 		DisarmCmd::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be executed
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *DisarmCmd::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "DisarmCmd::execute(): arrived" << endl;

	((static_cast<Eiger *>(device))->disarm());
	return new CORBA::Any();
}

//+----------------------------------------------------------------------------
//
// method : 		InitializeCmd::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be executed
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *InitializeCmd::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "InitializeCmd::execute(): arrived" << endl;

	((static_cast<Eiger *>(device))->initialize());
	return new CORBA::Any();
}





//
//----------------------------------------------------------------
//	Initialize pointer for singleton pattern
//----------------------------------------------------------------
//
EigerClass *EigerClass::_instance = NULL;

//+----------------------------------------------------------------------------
//
// method : 		EigerClass::EigerClass(string &s)
// 
// description : 	constructor for the EigerClass
//
// in : - s : The class name
//
//-----------------------------------------------------------------------------
EigerClass::EigerClass(string &s):DeviceClass(s)
{

	cout2 << "Entering EigerClass constructor" << endl;
	set_default_property();
	get_class_property();
	write_class_property();
	
	cout2 << "Leaving EigerClass constructor" << endl;

}
//+----------------------------------------------------------------------------
//
// method : 		EigerClass::~EigerClass()
// 
// description : 	destructor for the EigerClass
//
//-----------------------------------------------------------------------------
EigerClass::~EigerClass()
{
	_instance = NULL;
}

//+----------------------------------------------------------------------------
//
// method : 		EigerClass::instance
// 
// description : 	Create the object if not already done. Otherwise, just
//			return a pointer to the object
//
// in : - name : The class name
//
//-----------------------------------------------------------------------------
EigerClass *EigerClass::init(const char *name)
{
	if (_instance == NULL)
	{
		try
		{
			string s(name);
			_instance = new EigerClass(s);
		}
		catch (bad_alloc)
		{
			throw;
		}		
	}		
	return _instance;
}

EigerClass *EigerClass::instance()
{
	if (_instance == NULL)
	{
		cerr << "Class is not initialised !!" << endl;
		exit(-1);
	}
	return _instance;
}

//+----------------------------------------------------------------------------
//
// method : 		EigerClass::command_factory
// 
// description : 	Create the command object(s) and store them in the 
//			command list
//
//-----------------------------------------------------------------------------
void EigerClass::command_factory()
{
	command_list.push_back(new InitializeCmd("Initialize",
		Tango::DEV_VOID, Tango::DEV_VOID,
		"",
		"",
		Tango::OPERATOR));
	command_list.push_back(new DisarmCmd("Disarm",
		Tango::DEV_VOID, Tango::DEV_VOID,
		"",
		"",
		Tango::OPERATOR));
	command_list.push_back(new UpdateTHClass("UpdateTH",
		Tango::DEV_VOID, Tango::DEV_VOID,
		"",
		"",
		Tango::OPERATOR));

	//	add polling if any
	for (unsigned int i=0 ; i<command_list.size(); i++)
	{
	}
}

//+----------------------------------------------------------------------------
//
// method : 		EigerClass::get_class_property
// 
// description : 	Get the class property for specified name.
//
// in :		string	name : The property name
//
//+----------------------------------------------------------------------------
Tango::DbDatum EigerClass::get_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_prop.size() ; i++)
		if (cl_prop[i].name == prop_name)
			return cl_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}
//+----------------------------------------------------------------------------
//
// method : 		EigerClass::get_default_device_property()
// 
// description : 	Return the default value for device property.
//
//-----------------------------------------------------------------------------
Tango::DbDatum EigerClass::get_default_device_property(string &prop_name)
{
	for (unsigned int i=0 ; i<dev_def_prop.size() ; i++)
		if (dev_def_prop[i].name == prop_name)
			return dev_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//+----------------------------------------------------------------------------
//
// method : 		EigerClass::get_default_class_property()
// 
// description : 	Return the default value for class property.
//
//-----------------------------------------------------------------------------
Tango::DbDatum EigerClass::get_default_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_def_prop.size() ; i++)
		if (cl_def_prop[i].name == prop_name)
			return cl_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}
//+----------------------------------------------------------------------------
//
// method : 		EigerClass::device_factory
// 
// description : 	Create the device object(s) and store them in the 
//			device list
//
// in :		Tango::DevVarStringArray *devlist_ptr : The device name list
//
//-----------------------------------------------------------------------------
void EigerClass::device_factory(const Tango::DevVarStringArray *devlist_ptr)
{

	//	Create all devices.(Automatic code generation)
	//-------------------------------------------------------------
	for (unsigned long i=0 ; i < devlist_ptr->length() ; i++)
	{
		cout4 << "Device name : " << (*devlist_ptr)[i].in() << endl;
						
		// Create devices and add it into the device list
		//----------------------------------------------------
		device_list.push_back(new Eiger(this, (*devlist_ptr)[i]));							 

		// Export device to the outside world
		// Check before if database used.
		//---------------------------------------------
		if ((Tango::Util::_UseDb == true) && (Tango::Util::_FileDb == false))
			export_device(device_list.back());
		else
			export_device(device_list.back(), (*devlist_ptr)[i]);
	}
	//	End of Automatic code generation
	//-------------------------------------------------------------

}
//+----------------------------------------------------------------------------
//	Method: EigerClass::attribute_factory(vector<Tango::Attr *> &att_list)
//-----------------------------------------------------------------------------
void EigerClass::attribute_factory(vector<Tango::Attr *> &att_list)
{
	//	Attribute : countrateCorrection
	countrateCorrectionAttrib	*countrate_correction = new countrateCorrectionAttrib();
	Tango::UserDefaultAttrProp	countrate_correction_prop;
	countrate_correction_prop.set_unit(" ");
	countrate_correction->set_default_properties(countrate_correction_prop);
	countrate_correction->set_disp_level(Tango::EXPERT);
	att_list.push_back(countrate_correction);

	//	Attribute : flatfieldCorrection
	flatfieldCorrectionAttrib	*flatfield_correction = new flatfieldCorrectionAttrib();
	Tango::UserDefaultAttrProp	flatfield_correction_prop;
	flatfield_correction_prop.set_unit(" ");
	flatfield_correction->set_default_properties(flatfield_correction_prop);
	att_list.push_back(flatfield_correction);

	//	Attribute : pixelMask
	pixelMaskAttrib	*pixel_mask = new pixelMaskAttrib();
	Tango::UserDefaultAttrProp	pixel_mask_prop;
	pixel_mask_prop.set_unit(" ");
	pixel_mask->set_default_properties(pixel_mask_prop);
	att_list.push_back(pixel_mask);

	//	Attribute : virtualPixelCorrection
	virtualPixelCorrectionAttrib	*virtual_pixel_correction = new virtualPixelCorrectionAttrib();
	Tango::UserDefaultAttrProp	virtual_pixel_correction_prop;
	virtual_pixel_correction_prop.set_unit(" ");
	virtual_pixel_correction->set_default_properties(virtual_pixel_correction_prop);
	virtual_pixel_correction->set_disp_level(Tango::EXPERT);
	att_list.push_back(virtual_pixel_correction);

	//	Attribute : managedMode
	managedModeAttrib	*managed_mode = new managedModeAttrib();
	Tango::UserDefaultAttrProp	managed_mode_prop;
	managed_mode_prop.set_unit(" ");
	managed_mode_prop.set_standard_unit(" ");
	managed_mode_prop.set_display_unit(" ");
	managed_mode_prop.set_description("Available values of Managed Mode are : <br>\n- STREAMING: Image and header data are transferred via zeromq sockets & Nexus files could be generated into an user defined path. <br>\n- FILEWRITER: Image and the metadata are generated into the DCU in HDF5 format & data files are tranferred into an user defined path through the device & data files are deleted from DCU. <br>\n- LAZY : Image and the metadata are generated in DCU in HDF5 format .\n\n");
	managed_mode->set_default_properties(managed_mode_prop);
	att_list.push_back(managed_mode);

	//	Attribute : dataCollectionDate
	dataCollectionDateAttrib	*data_collection_date = new dataCollectionDateAttrib();
	att_list.push_back(data_collection_date);

	//	Attribute : thresholdEnergy
	thresholdEnergyAttrib	*threshold_energy = new thresholdEnergyAttrib();
	Tango::UserDefaultAttrProp	threshold_energy_prop;
	threshold_energy_prop.set_unit("eV");
	threshold_energy_prop.set_standard_unit("eV");
	threshold_energy_prop.set_display_unit("eV");
	threshold_energy->set_default_properties(threshold_energy_prop);
	att_list.push_back(threshold_energy);

	//	Attribute : photonEnergy
	photonEnergyAttrib	*photon_energy = new photonEnergyAttrib();
	Tango::UserDefaultAttrProp	photon_energy_prop;
	photon_energy_prop.set_unit("eV");
	photon_energy_prop.set_standard_unit("eV");
	photon_energy_prop.set_display_unit("eV");
	photon_energy->set_default_properties(photon_energy_prop);
	att_list.push_back(photon_energy);

	//	Attribute : wavelength
	wavelengthAttrib	*wavelength = new wavelengthAttrib();
	Tango::UserDefaultAttrProp	wavelength_prop;
	wavelength_prop.set_unit("angstrom");
	wavelength_prop.set_standard_unit("angstrom");
	wavelength_prop.set_display_unit("angstrom");
	wavelength->set_default_properties(wavelength_prop);
	att_list.push_back(wavelength);

	//	Attribute : roiMode
	roiModeAttrib	*roi_mode = new roiModeAttrib();
	att_list.push_back(roi_mode);

	//	Attribute : beamCenterX
	beamCenterXAttrib	*beam_center_x = new beamCenterXAttrib();
	Tango::UserDefaultAttrProp	beam_center_x_prop;
	beam_center_x_prop.set_unit("pixels");
	beam_center_x_prop.set_standard_unit("pixels");
	beam_center_x_prop.set_display_unit("pixels");
	beam_center_x->set_default_properties(beam_center_x_prop);
	att_list.push_back(beam_center_x);

	//	Attribute : beamCenterY
	beamCenterYAttrib	*beam_center_y = new beamCenterYAttrib();
	Tango::UserDefaultAttrProp	beam_center_y_prop;
	beam_center_y_prop.set_unit("pixels");
	beam_center_y_prop.set_standard_unit("pixels");
	beam_center_y_prop.set_display_unit("pixels");
	beam_center_y->set_default_properties(beam_center_y_prop);
	att_list.push_back(beam_center_y);

	//	Attribute : detectorDistance
	detectorDistanceAttrib	*detector_distance = new detectorDistanceAttrib();
	Tango::UserDefaultAttrProp	detector_distance_prop;
	detector_distance_prop.set_unit("m");
	detector_distance_prop.set_standard_unit("m");
	detector_distance_prop.set_display_unit("m");
	detector_distance->set_default_properties(detector_distance_prop);
	att_list.push_back(detector_distance);

	//	Attribute : detectorReadoutTime
	detectorReadoutTimeAttrib	*detector_readout_time = new detectorReadoutTimeAttrib();
	Tango::UserDefaultAttrProp	detector_readout_time_prop;
	detector_readout_time_prop.set_unit(" ");
	detector_readout_time_prop.set_standard_unit(" ");
	detector_readout_time_prop.set_display_unit(" ");
	detector_readout_time->set_default_properties(detector_readout_time_prop);
	att_list.push_back(detector_readout_time);

	//	Attribute : temperature
	temperatureAttrib	*temperature = new temperatureAttrib();
	Tango::UserDefaultAttrProp	temperature_prop;
	temperature_prop.set_unit("Celsius");
	temperature_prop.set_standard_unit("Celsius");
	temperature_prop.set_display_unit("Celsius");
	temperature->set_default_properties(temperature_prop);
	att_list.push_back(temperature);

	//	Attribute : humidity
	humidityAttrib	*humidity = new humidityAttrib();
	Tango::UserDefaultAttrProp	humidity_prop;
	humidity_prop.set_unit("%");
	humidity_prop.set_standard_unit("%");
	humidity_prop.set_display_unit("%");
	humidity->set_default_properties(humidity_prop);
	att_list.push_back(humidity);

	//	Attribute : chiIncrement
	chiIncrementAttrib	*chi_increment = new chiIncrementAttrib();
	Tango::UserDefaultAttrProp	chi_increment_prop;
	chi_increment_prop.set_unit("degree");
	chi_increment_prop.set_standard_unit("degree");
	chi_increment_prop.set_display_unit("degree");
	chi_increment->set_default_properties(chi_increment_prop);
	att_list.push_back(chi_increment);

	//	Attribute : chiStart
	chiStartAttrib	*chi_start = new chiStartAttrib();
	Tango::UserDefaultAttrProp	chi_start_prop;
	chi_start_prop.set_unit("degree");
	chi_start_prop.set_standard_unit("degree");
	chi_start_prop.set_display_unit("degree");
	chi_start->set_default_properties(chi_start_prop);
	att_list.push_back(chi_start);

	//	Attribute : kappaIncrement
	kappaIncrementAttrib	*kappa_increment = new kappaIncrementAttrib();
	Tango::UserDefaultAttrProp	kappa_increment_prop;
	kappa_increment_prop.set_unit("degree");
	kappa_increment_prop.set_standard_unit("degree");
	kappa_increment_prop.set_display_unit("degree");
	kappa_increment->set_default_properties(kappa_increment_prop);
	att_list.push_back(kappa_increment);

	//	Attribute : kappaStart
	kappaStartAttrib	*kappa_start = new kappaStartAttrib();
	Tango::UserDefaultAttrProp	kappa_start_prop;
	kappa_start_prop.set_unit("degree");
	kappa_start_prop.set_standard_unit("degree");
	kappa_start_prop.set_display_unit("degree");
	kappa_start->set_default_properties(kappa_start_prop);
	att_list.push_back(kappa_start);

	//	Attribute : omegaIncrement
	omegaIncrementAttrib	*omega_increment = new omegaIncrementAttrib();
	Tango::UserDefaultAttrProp	omega_increment_prop;
	omega_increment_prop.set_unit("degree");
	omega_increment_prop.set_standard_unit("degree");
	omega_increment_prop.set_display_unit("degree");
	omega_increment->set_default_properties(omega_increment_prop);
	att_list.push_back(omega_increment);

	//	Attribute : omegaStart
	omegaStartAttrib	*omega_start = new omegaStartAttrib();
	Tango::UserDefaultAttrProp	omega_start_prop;
	omega_start_prop.set_unit("degree");
	omega_start_prop.set_standard_unit("degree");
	omega_start_prop.set_display_unit("degree");
	omega_start->set_default_properties(omega_start_prop);
	att_list.push_back(omega_start);

	//	Attribute : phiIncrement
	phiIncrementAttrib	*phi_increment = new phiIncrementAttrib();
	Tango::UserDefaultAttrProp	phi_increment_prop;
	phi_increment_prop.set_unit("degree");
	phi_increment_prop.set_standard_unit("degree");
	phi_increment_prop.set_display_unit("degree");
	phi_increment->set_default_properties(phi_increment_prop);
	att_list.push_back(phi_increment);

	//	Attribute : phiStart
	phiStartAttrib	*phi_start = new phiStartAttrib();
	Tango::UserDefaultAttrProp	phi_start_prop;
	phi_start_prop.set_unit("degree");
	phi_start_prop.set_standard_unit("degree");
	phi_start_prop.set_display_unit("degree");
	phi_start->set_default_properties(phi_start_prop);
	att_list.push_back(phi_start);

	//	Attribute : autoSummation
	autoSummationAttrib	*auto_summation = new autoSummationAttrib();
	auto_summation->set_disp_level(Tango::EXPERT);
	att_list.push_back(auto_summation);

	//	Attribute : compression
	compressionAttrib	*compression = new compressionAttrib();
	Tango::UserDefaultAttrProp	compression_prop;
	compression_prop.set_unit(" ");
	compression_prop.set_description("Controls the compression of images.[Default= ON]");
	compression->set_default_properties(compression_prop);
	compression->set_disp_level(Tango::EXPERT);
	att_list.push_back(compression);

	//	Attribute : compressionType
	compressionTypeAttrib	*compression_type = new compressionTypeAttrib();
	Tango::UserDefaultAttrProp	compression_type_prop;
	compression_type_prop.set_description("The compression type can be set as follows :\n- LZ4\n- BSLZ4\n\n\n");
	compression_type->set_default_properties(compression_type_prop);
	compression_type->set_disp_level(Tango::EXPERT);
	att_list.push_back(compression_type);

	//	Attribute : softwareVersion
	softwareVersionAttrib	*software_version = new softwareVersionAttrib();
	software_version->set_disp_level(Tango::EXPERT);
	att_list.push_back(software_version);

	//	Attribute : nbTriggers
	nbTriggersAttrib	*nb_triggers = new nbTriggersAttrib();
	Tango::UserDefaultAttrProp	nb_triggers_prop;
	nb_triggers_prop.set_unit(" ");
	nb_triggers_prop.set_standard_unit(" ");
	nb_triggers_prop.set_display_unit(" ");
	nb_triggers_prop.set_description("Define the number of triggers expected by the detector to terminate the acquisition.<br>\nThe detector stays armed until nbTriggers are received.<br>\nAvailable only for the triggers modes :<br>\nINTERNAL_SINGLE (ints).<br>\nEXTERNAL_SINGLE (exts)  triggers modes.<br>");
	nb_triggers->set_default_properties(nb_triggers_prop);
	nb_triggers->set_disp_level(Tango::EXPERT);
	att_list.push_back(nb_triggers);

	//	Attribute : nbFramesPerTrigger
	nbFramesPerTriggerAttrib	*nb_frames_per_trigger = new nbFramesPerTriggerAttrib();
	Tango::UserDefaultAttrProp	nb_frames_per_trigger_prop;
	nb_frames_per_trigger_prop.set_unit(" ");
	nb_frames_per_trigger_prop.set_standard_unit(" ");
	nb_frames_per_trigger_prop.set_display_unit(" ");
	nb_frames_per_trigger_prop.set_description("Define the number of frames acquired by the detector for each received trigger.\nAvailable only for the triggers modes :<br>\nINTERNAL_SINGLE (ints).<br>\nEXTERNAL_SINGLE (exts)  triggers modes.<br>\n");
	nb_frames_per_trigger->set_default_properties(nb_frames_per_trigger_prop);
	nb_frames_per_trigger->set_disp_level(Tango::EXPERT);
	att_list.push_back(nb_frames_per_trigger);

	//	End of Automatic code generation
	//-------------------------------------------------------------
}


//+----------------------------------------------------------------------------
//
// method : 		EigerClass::get_class_property()
// 
// description : 	Read the class properties from database.
//
//-----------------------------------------------------------------------------
void EigerClass::get_class_property()
{
	//	Initialize your default values here (if not done with  POGO).
	//------------------------------------------------------------------

	//	Read class properties from database.(Automatic code generation)
	//------------------------------------------------------------------

	//	Call database and extract values
	//--------------------------------------------
	if (Tango::Util::instance()->_UseDb==true)
		get_db_class()->get_property(cl_prop);
	Tango::DbDatum	def_prop;
	int	i = -1;


	//	End of Automatic code generation
	//------------------------------------------------------------------

}

//+----------------------------------------------------------------------------
//
// method : 	EigerClass::set_default_property
// 
// description: Set default property (class and device) for wizard.
//              For each property, add to wizard property name and description
//              If default value has been set, add it to wizard property and
//              store it in a DbDatum.
//
//-----------------------------------------------------------------------------
void EigerClass::set_default_property()
{
	string	prop_name;
	string	prop_desc;
	string	prop_def;

	vector<string>	vect_data;
	//	Set Default Class Properties
	//	Set Default Device Properties
	prop_name = "DetectorIP";
	prop_desc = "Eiger server IP address (ex: 192.168.0.1)";
	prop_def  = "127.0.0.1";
	vect_data.clear();
	vect_data.push_back("127.0.0.1");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "TimestampType";
	prop_desc = "Define the timestamp type of each frame: <br>\n- RELATIVE : The time difference between the moment of reading the frame and the start acquisition time<br>\n- ABSOLUTE : The time at the moment of reading the frame from detector<br>";
	prop_def  = "RELATIVE";
	vect_data.clear();
	vect_data.push_back("RELATIVE");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "CurlDelayMs";
	prop_desc = "Curl delay in ms. this is used as a sleep delay for waiting the curl responses (default = 100)";
	prop_def  = "100";
	vect_data.clear();
	vect_data.push_back("100");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "DownloadDataFile";
	prop_desc = "Enable/Disable downloading data files from DCU.\nDo not download data files (master+data) [by default]";
	prop_def  = "false";
	vect_data.clear();
	vect_data.push_back("false");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "NbFramesPerTriggerIsMaster";
	prop_desc = "If True: nbFrames = memorized values of NbTriggers * NbFramesPerTrigger (case on PX1 beamline)\nIf False: nbFrames = memorized nbFrames (case on Swing, Sixs beamlines)";
	prop_def  = "false";
	vect_data.clear();
	vect_data.push_back("false");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "MemorizedCountrateCorrection";
	prop_desc = "Memorize the value of countrateCorrection attribute.";
	prop_def  = "false";
	vect_data.clear();
	vect_data.push_back("false");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "MemorizedFlatfieldCorrection";
	prop_desc = "Memorize the value of flatfieldCorrection attribute.";
	prop_def  = "true";
	vect_data.clear();
	vect_data.push_back("true");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "MemorizedPixelMask";
	prop_desc = "Memorize the value of pixelMask attribute.";
	prop_def  = "false";
	vect_data.clear();
	vect_data.push_back("false");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "MemorizedVirtualPixelCorrection";
	prop_desc = "Memorize the value of virtualPixelCorrection attribute.";
	prop_def  = "false";
	vect_data.clear();
	vect_data.push_back("false");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "MemorizedThresholdEnergy";
	prop_desc = "Memorize the value of thresholdEnergy attribute.";
	prop_def  = "4000.0";
	vect_data.clear();
	vect_data.push_back("4000.0");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "MemorizedPhotonEnergy";
	prop_desc = "Memorize the value of photonEnergy attribute.";
	prop_def  = "8000.0";
	vect_data.clear();
	vect_data.push_back("8000.0");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "MemorizedAutoSummation";
	prop_desc = "Memorize the value of autoSummation attribute.";
	prop_def  = "true";
	vect_data.clear();
	vect_data.push_back("true");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "MemorizedCompression";
	prop_desc = "Memorize the value of compression attribute.";
	prop_def  = "true";
	vect_data.clear();
	vect_data.push_back("true");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "MemorizedCompressionType";
	prop_desc = "Memorize the value of compressionType attribute.";
	prop_def  = "LZ4";
	vect_data.clear();
	vect_data.push_back("LZ4");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "MemorizedWavelength";
	prop_desc = "Memorize the value of wavelength attribute.";
	prop_def  = "0";
	vect_data.clear();
	vect_data.push_back("0");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "MemorizedRoiMode";
	prop_desc = "Memorize the value of roiMode attribute.";
	prop_def  = "DISABLED";
	vect_data.clear();
	vect_data.push_back("DISABLED");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "MemorizedBeamCenterX";
	prop_desc = "Memorize the value of beamCenterX attribute.";
	prop_def  = "0";
	vect_data.clear();
	vect_data.push_back("0");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "MemorizedBeamCenterY";
	prop_desc = "Memorize the value of beamCenterY attribute.";
	prop_def  = "0";
	vect_data.clear();
	vect_data.push_back("0");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "MemorizedDetectorDistance";
	prop_desc = "Memorize the value of detectorDistance attribute.";
	prop_def  = "0";
	vect_data.clear();
	vect_data.push_back("0");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "MemorizedChiIncrement";
	prop_desc = "Memorize the value of chiIncrement attribute.";
	prop_def  = "0";
	vect_data.clear();
	vect_data.push_back("0");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "MemorizedChiStart";
	prop_desc = "Memorize the value of chiStart attribute.";
	prop_def  = "0";
	vect_data.clear();
	vect_data.push_back("0");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "MemorizedKappaIncrement";
	prop_desc = "Memorize the value of kappaIncrement attribute.";
	prop_def  = "0";
	vect_data.clear();
	vect_data.push_back("0");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "MemorizedKappaStart";
	prop_desc = "Memorize the value of kappaStart attribute.";
	prop_def  = "0";
	vect_data.clear();
	vect_data.push_back("0");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "MemorizedOmegaIncrement";
	prop_desc = "Memorize the value of omegaIncrement attribute.";
	prop_def  = "0";
	vect_data.clear();
	vect_data.push_back("0");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "MemorizedOmegaStart";
	prop_desc = "Memorize the value of omegaStart attribute.";
	prop_def  = "0";
	vect_data.clear();
	vect_data.push_back("0");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "MemorizedPhiIncrement";
	prop_desc = "Memorize the value of phiIncrement attribute.";
	prop_def  = "0";
	vect_data.clear();
	vect_data.push_back("0");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "MemorizedPhiStart";
	prop_desc = "Memorize the value of phiStart attribute.";
	prop_def  = "0";
	vect_data.clear();
	vect_data.push_back("0");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "MemorizedNbTriggers";
	prop_desc = "Memorize the value of nbTriggers attribute.";
	prop_def  = "1";
	vect_data.clear();
	vect_data.push_back("1");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "MemorizedNbFramesPerTrigger";
	prop_desc = "Memorize the value of nbFramesPerTrigger attribute.";
	prop_def  = "1";
	vect_data.clear();
	vect_data.push_back("1");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

}
//+----------------------------------------------------------------------------
//
// method : 		EigerClass::write_class_property
// 
// description : 	Set class description as property in database
//
//-----------------------------------------------------------------------------
void EigerClass::write_class_property()
{
	//	First time, check if database used
	//--------------------------------------------
	if (Tango::Util::_UseDb == false)
		return;

	Tango::DbData	data;
	string	classname = get_name();
	string	header;
	string::size_type	start, end;

	//	Put title
	Tango::DbDatum	title("ProjectTitle");
	string	str_title("");
	title << str_title;
	data.push_back(title);

	//	Put Description
	Tango::DbDatum	description("Description");
	vector<string>	str_desc;
	str_desc.push_back("  ");
	description << str_desc;
	data.push_back(description);
		
	//	put cvs or svn location
	string	filename(classname);
	filename += "Class.cpp";
	
	// Create a string with the class ID to
	// get the string into the binary
	string	class_id(ClassId);
	
	// check for cvs information
	string	src_path(CvsPath);
	start = src_path.find("/");
	if (start!=string::npos)
	{
		end   = src_path.find(filename);
		if (end>start)
		{
			string	strloc = src_path.substr(start, end-start);
			//	Check if specific repository
			start = strloc.find("/cvsroot/");
			if (start!=string::npos && start>0)
			{
				string	repository = strloc.substr(0, start);
				if (repository.find("/segfs/")!=string::npos)
					strloc = "ESRF:" + strloc.substr(start, strloc.length()-start);
			}
			Tango::DbDatum	cvs_loc("cvs_location");
			cvs_loc << strloc;
			data.push_back(cvs_loc);
		}
	}
	// check for svn information
	else
	{
		string	src_path(SvnPath);
		start = src_path.find("://");
		if (start!=string::npos)
		{
			end = src_path.find(filename);
			if (end>start)
			{
				header = "$HeadURL: ";
				start = header.length();
				string	strloc = src_path.substr(start, (end-start));
				
				Tango::DbDatum	svn_loc("svn_location");
				svn_loc << strloc;
				data.push_back(svn_loc);
			}
		}
	}

	//	Get CVS or SVN revision tag
	
	// CVS tag
	string	tagname(TagName);
	header = "$Name: ";
	start = header.length();
	string	endstr(" $");
	
	end   = tagname.find(endstr);
	if (end!=string::npos && end>start)
	{
		string	strtag = tagname.substr(start, end-start);
		Tango::DbDatum	cvs_tag("cvs_tag");
		cvs_tag << strtag;
		data.push_back(cvs_tag);
	}
	
	// SVN tag
	string	svnpath(SvnPath);
	header = "$HeadURL: ";
	start = header.length();
	
	end   = svnpath.find(endstr);
	if (end!=string::npos && end>start)
	{
		string	strloc = svnpath.substr(start, end-start);
		
		string tagstr ("/tags/");
		start = strloc.find(tagstr);
		if ( start!=string::npos )
		{
			start = start + tagstr.length();
			end   = strloc.find(filename);
			string	strtag = strloc.substr(start, end-start-1);
			
			Tango::DbDatum	svn_tag("svn_tag");
			svn_tag << strtag;
			data.push_back(svn_tag);
		}
	}

	//	Get URL location
	string	httpServ(HttpServer);
	if (httpServ.length()>0)
	{
		Tango::DbDatum	db_doc_url("doc_url");
		db_doc_url << httpServ;
		data.push_back(db_doc_url);
	}

	//  Put inheritance
	Tango::DbDatum	inher_datum("InheritedFrom");
	vector<string> inheritance;
	inheritance.push_back("Device_4Impl");
	inher_datum << inheritance;
	data.push_back(inher_datum);

	//	Call database and and values
	//--------------------------------------------
	get_db_class()->put_property(data);
}

}	// namespace
