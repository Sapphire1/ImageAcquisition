/*!
 * \file
 * \brief 
 * \author lzmuda,,,
 */

#ifndef MASKGENERATOR_HPP_
#define MASKGENERATOR_HPP_

#include "Component_Aux.hpp"
#include "Component.hpp"
#include "DataStream.hpp"
#include "Property.hpp"
#include "EventHandler2.hpp"



namespace Processors {
namespace MaskGenerator {

/*!
 * \class MaskGenerator
 * \brief MaskGenerator processor class.
 *
 * MaskGenerator processor.
 */
class MaskGenerator: public Base::Component {
public:
	/*!
	 * Constructor.
	 */
	MaskGenerator(const std::string & name = "MaskGenerator");

	/*!
	 * Destructor
	 */
	virtual ~MaskGenerator();

	/*!
	 * Prepare components interface (register streams and handlers).
	 * At this point, all properties are already initialized and loaded to 
	 * values set in config file.
	 */
	void prepareInterface();

protected:

	/*!
	 * Connects source to given device.
	 */
	bool onInit();

	/*!
	 * Disconnect source from device, closes streams, etc.
	 */
	bool onFinish();

	/*!
	 * Start component
	 */
	bool onStart();

	/*!
	 * Stop component
	 */
	bool onStop();


	

};

} //: namespace MaskGenerator
} //: namespace Processors

/*
 * Register processor component.
 */
REGISTER_COMPONENT("MaskGenerator", Processors::MaskGenerator::MaskGenerator)

#endif /* MASKGENERATOR_HPP_ */
