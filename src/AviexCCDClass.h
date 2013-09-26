//=============================================================================
//
// file :         AviexCCDClass.h
//
// description :  Include for the AviexCCDClass root class.
//                This class is the singleton class for
//                the AviexCCD device class.
//                It contains all properties and methods which the 
//                AviexCCD requires only once e.g. the commands.
//			
// project :      TANGO Device Server
//
// $Author:  $
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
// copyleft :     European Synchrotron Radiation Facility
//                BP 220, Grenoble 38043
//                FRANCE
//
//=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================

#ifndef _AVIEXCCDCLASS_H
#define _AVIEXCCDCLASS_H

#ifdef WIN32
#include "tango.h"
#endif
#include <AviexCCD.h>

#ifndef WIN32
#include "tango.h"
#endif

namespace AviexCCD_ns
{//=====================================
//	Define classes for attributes
//=====================================
class internalAcquisitionModeAttrib: public Tango::Attr
{
public:
	internalAcquisitionModeAttrib():Attr("internalAcquisitionMode", Tango::DEV_STRING, Tango::READ_WRITE) {};
	~internalAcquisitionModeAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<AviexCCD *>(dev))->read_internalAcquisitionMode(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<AviexCCD *>(dev))->write_internalAcquisitionMode(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<AviexCCD *>(dev))->is_internalAcquisitionMode_allowed(ty);}
};

//=========================================
//	Define classes for commands
//=========================================
//
// The AviexCCDClass singleton definition
//

class
#ifdef WIN32
	__declspec(dllexport)
#endif
	AviexCCDClass : public Tango::DeviceClass
{
public:
//	properties member data

//	add your own data members here
//------------------------------------

public:
	Tango::DbData	cl_prop;
	Tango::DbData	cl_def_prop;
	Tango::DbData	dev_def_prop;

//	Method prototypes
	static AviexCCDClass *init(const char *);
	static AviexCCDClass *instance();
	~AviexCCDClass();
	Tango::DbDatum	get_class_property(string &);
	Tango::DbDatum	get_default_device_property(string &);
	Tango::DbDatum	get_default_class_property(string &);
	
protected:
	AviexCCDClass(string &);
	static AviexCCDClass *_instance;
	void command_factory();
	void get_class_property();
	void attribute_factory(vector<Tango::Attr *> &);
	void write_class_property();
	void set_default_property();
	string get_cvstag();
	string get_cvsroot();

private:
	void device_factory(const Tango::DevVarStringArray *);
};


}	//	namespace AviexCCD_ns

#endif // _AVIEXCCDCLASS_H
