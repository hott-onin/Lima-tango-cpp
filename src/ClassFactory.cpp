static const char *RcsId = "$Id:  $";
//+=============================================================================
//
// file :        ClassFactory.cpp
//
// description : C++ source for the class_factory method of the DServer
//               device class. This method is responsible for the creation of
//               all class singleton for a device server. It is called
//               at device server startup
//
// project :     TANGO Device Server
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
// copyleft :    European Synchrotron Radiation Facility
//               BP 220, Grenoble 38043
//               FRANCE
//
//-=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================
#ifdef WIN32
#include "tango.h"
#endif
#include <LimaDetectorClass.h>


#ifdef LAYOUT_ENABLED
#include <LayoutClass.h>
#endif

#ifdef ROICOUNTERS_ENABLED
#include <RoiCountersClass.h>
#endif

#ifdef MASK_ENABLED
#include <MaskClass.h>
#endif

#ifdef SIMULATOR_ENABLED
#include <SimulatorCCDClass.h>
#endif

#ifdef BASLER_ENABLED
#include <BaslerCCDClass.h>
#endif

#ifdef PILATUS_ENABLED
#include <PilatusPixelDetectorClass.h>
#endif

#ifdef IMXPAD_ENABLED
#include <ImXpadClass.h>
#endif

#ifdef XPAD_ENABLED
#include <XpadPixelDetectorClass.h>
#endif

#ifdef MARCCD_ENABLED
#include <MarCCDClass.h>
#endif

#ifdef MAXIPIX_ENABLED
#include <MaxipixClass.h>
#endif

#ifdef ADSC_ENABLED
#include <AdscCCDClass.h>
#endif

#ifdef PROSILICA_ENABLED
#include <ProsilicaCCDClass.h>
#endif

#ifdef SPECTRUMONE_ENABLED
#include <SpectrumOneCCDClass.h>
#endif

#ifdef PRINCETON_ENABLED
#include <PrincetonCCDClass.h>
#endif

#ifdef PCO_ENABLED
#include <PcoClass.h>
#endif

#ifdef PERKINELMER_ENABLED
#include <PerkinElmerClass.h>
#endif

#ifdef MERLIN_ENABLED
#include <MerlinClass.h>
#endif

#ifdef ANDOR_ENABLED
#include <AndorCCDClass.h>
#endif

#ifdef ANDOR3_ENABLED
#include <Andor3Class.h>
#endif

#ifdef VIEWORKSVP_ENABLED
#include <VieworksVPClass.h>
#endif

#ifdef HAMAMATSU_ENABLED
#include <HamamatsuClass.h>
#endif

#ifdef EIGER_ENABLED
#include <EigerClass.h>
#endif

#ifdef SLSJUNGFRAU_ENABLED
#include <SlsJungfrauClass.h>
#endif

#ifdef SLSEIGER_ENABLED
#include <SlsEigerClass.h>
#endif

#ifdef LAMBDA_ENABLED
#include <LambdaClass.h>
#endif

#ifdef DHYANA_ENABLED
#include <DhyanaClass.h>
#endif

#ifdef UFXC_ENABLED
#include <UfxcClass.h>
#endif

#ifdef XSPRESS3_ENABLED
#include <Xspress3Class.h>
#endif

#ifndef WIN32
#include "tango.h"
#endif

/**
 *	Create LimaDetectorClass singleton and store it in DServer object.
 */

void Tango::DServer::class_factory()
{
    add_class(LimaDetector_ns::LimaDetectorClass::init("LimaDetector"));

#ifdef SIMULATOR_ENABLED
    add_class(SimulatorCCD_ns::SimulatorCCDClass::init("SimulatorCCD"));
#endif
    
#ifdef BASLER_ENABLED
    add_class(BaslerCCD_ns::BaslerCCDClass::init("BaslerCCD"));
#endif

#ifdef PILATUS_ENABLED
    add_class(PilatusPixelDetector_ns::PilatusPixelDetectorClass::init("PilatusPixelDetector"));
#endif

#ifdef IMXPAD_ENABLED	
    add_class(ImXpad_ns::ImXpadClass::init("ImXpad"));
#endif
    
#ifdef XPAD_ENABLED	
    add_class(XpadPixelDetector_ns::XpadPixelDetectorClass::init("XpadPixelDetector"));
#endif

#ifdef MARCCD_ENABLED	
    add_class(MarCCD_ns::MarCCDClass::init("MarCCD"));
#endif

#ifdef MAXIPIX_ENABLED	
    add_class(Maxipix_ns::MaxipixClass::init("Maxipix"));
#endif
    
#ifdef ADSC_ENABLED	
    add_class(AdscCCD_ns::AdscCCDClass::init("AdscCCD"));
#endif

#ifdef PROSILICA_ENABLED
    add_class(ProsilicaCCD_ns::ProsilicaCCDClass::init("ProsilicaCCD"));
#endif

#ifdef SPECTRUMONE_ENABLED
    add_class(SpectrumOneCCD_ns::SpectrumOneCCDClass::init("SpectrumOneCCD"));
#endif

#ifdef PRINCETON_ENABLED
    add_class(PrincetonCCD_ns::PrincetonCCDClass::init("PrincetonCCD"));
#endif

#ifdef PCO_ENABLED
    add_class(Pco_ns::PcoClass::init("Pco"));
#endif

#ifdef PERKINELMER_ENABLED
    add_class(PerkinElmer_ns::PerkinElmerClass::init("PerkinElmer"));
#endif

#ifdef MERLIN_ENABLED
    add_class(Merlin_ns::MerlinClass::init("Merlin"));
#endif

#ifdef ANDOR_ENABLED
    add_class(AndorCCD_ns::AndorCCDClass::init("AndorCCD"));
#endif
	
#ifdef ANDOR3_ENABLED
    add_class(Andor3_ns::Andor3Class::init("Andor3"));
#endif

#ifdef VIEWORKSVP_ENABLED
    add_class(VieworksVP_ns::Andor3Class::init("VieworksVP"));
#endif

#ifdef HAMAMATSU_ENABLED
    add_class(Hamamatsu_ns::HamamatsuClass::init("Hamamatsu"));
#endif

#ifdef EIGER_ENABLED
    add_class(Eiger_ns::EigerClass::init("Eiger"));
#endif

#ifdef LAYOUT_ENABLED    
    add_class(Layout_ns::LayoutClass::init("Layout"));
#endif
	
#ifdef ROICOUNTERS_ENABLED    
    add_class(RoiCounters_ns::RoiCountersClass::init("RoiCounters"));
#endif	

#ifdef MASK_ENABLED    
    add_class(Mask_ns::MaskClass::init("Mask"));
#endif

#ifdef SLSJUNGFRAU_ENABLED        
    add_class(SlsJungfrau_ns::SlsJungfrauClass::init("SlsJungfrau"));
#endif	

#ifdef SLSEIGER_ENABLED        
    add_class(SlsEiger_ns::SlsEigerClass::init("SlsEiger"));
#endif	

#ifdef LAMBDA_ENABLED        
    add_class(Lambda_ns::LambdaClass::init("Lambda"));
#endif	

	
#ifdef DHYANA_ENABLED        
    add_class(Dhyana_ns::DhyanaClass::init("Dhyana"));
#endif
	
#ifdef UFXC_ENABLED        
    add_class(Ufxc_ns::UfxcClass::init("Ufxc"));
#endif	

#ifdef XSPRESS3_ENABLED        
    add_class(Xspress3_ns::Xspress3Class::init("Xspress3"));
#endif	
	
}

