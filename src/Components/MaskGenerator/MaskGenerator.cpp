/*!
 * \file
 * \brief
 * \author lzmuda,,,
 */

#include <memory>
#include <string>

#include "MaskGenerator.hpp"
#include "Common/Logger.hpp"

#include <boost/bind.hpp>

namespace Processors {
namespace MaskGenerator {

MaskGenerator::MaskGenerator(const std::string & name) :
		Base::Component(name)  {

}

MaskGenerator::~MaskGenerator() {
}

void MaskGenerator::prepareInterface() {
	// Register data streams, events and event handlers HERE!

}

bool MaskGenerator::onInit() {

	return true;
}

bool MaskGenerator::onFinish() {
	return true;
}

bool MaskGenerator::onStop() {
	return true;
}

bool MaskGenerator::onStart() {
	return true;
}



} //: namespace MaskGenerator
} //: namespace Processors
