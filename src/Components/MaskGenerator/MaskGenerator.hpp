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
#include <opencv2/opencv.hpp>


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
	void onNewImage();

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
	
	/// Event handler.
	Base::EventHandler <MaskGenerator> h_onNewImage;
	// Input data streams
	
	// image without object
	Base::DataStreamIn <cv::Mat, Base::DataStreamBuffer::Newest> in_img1;

	// image with object of topic
	Base::DataStreamIn <cv::Mat, Base::DataStreamBuffer::Newest> in_img2;

	/// Output data stream - image.
	Base::DataStreamOut <cv::Mat> out_img;

private:

	cv::Mat img1;
	cv::Mat img2;
	cv::Mat imgOut;
	cv::Mat tmp_img;
    
	/*Base::Property<int> m_red_diff;
	Base::Property<int> m_green_diff;
	Base::Property<int> m_blue_diff;*/
	Base::Property<int> m_sum_diff;


};

} //: namespace MaskGenerator
} //: namespace Processors

/*
 * Register processor component.
 */
REGISTER_COMPONENT("MaskGenerator", Processors::MaskGenerator::MaskGenerator)

#endif /* MASKGENERATOR_HPP_ */
