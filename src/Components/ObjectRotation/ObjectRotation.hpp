/*!
 * \file
 * \brief 
 * \author lzmuda,,,
 */

#ifndef OBJECTROTATION_HPP_
#define OBJECTROTATION_HPP_

#include "Component_Aux.hpp"
#include "Component.hpp"
#include "DataStream.hpp"
#include "Property.hpp"
#include "EventHandler2.hpp"
#include <opencv2/opencv.hpp>
#include "../../Types/Objects3D/Chessboard.hpp"
#include "Types/CameraInfo.hpp"


namespace Processors {
namespace ObjectRotation {

/*!
 * \class ObjectRotation
 * \brief ObjectRotation processor class.
 *
 * ObjectRotation processor.
 */
class ObjectRotation: public Base::Component {
public:
	/*!
	 * Constructor.
	 */
	ObjectRotation(const std::string & name = "ObjectRotation");

	/*!
	 * Destructor
	 */
	virtual ~ObjectRotation();

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

	// Data streams
	Base::DataStreamIn< Types::Objects3D::Chessboard > in_chessboard;

	Base::DataStreamIn< Types::CameraInfo > in_camerainfo;
      
	Base::DataStreamIn <cv::Mat, Base::DataStreamBuffer::Newest> in_img1;
	
	Base::DataStreamIn <int> counter;
	
	Base::DataStreamOut< Types::CameraInfo > out_camerainfo;
	
	/// Output data stream - image.
	Base::DataStreamOut <cv::Mat> out_img;

	// Handlers

	// Handler activated when datastream chessboard is present.
	Base::EventHandler2 h_process_chessboard;
    
	Base::EventHandler2 h_test;
	// Handler activated a calibration computations should be performed.
	//Base::EventHandler2 h_perform_calibration;

	// Handler activated when user will trigger "add chessboard"
	//Base::EventHandler2 h_add_chessboard;

	// Handler activated when user will trigger "clear whole dataset"
	//Base::EventHandler2 h_clear_dataset;

	// Adds received chessboard observation to calibration set.
	void process_chessboard();
	void test();

	// Performs the calibration.
	//void perform_calibration();

	// Sets the add_set flag.
	//void add_chessboard();

	// Adds received chessboard observation to calibration set.
	//void clear_dataset();
	


	// Working mode: if activated, memorizes every data set that is received.
	Base::Property<bool> continuous;

private:

	// The vector of vectors of the object point projections on the calibration pattern views, one vector per a view.
	//vector<vector<cv::Point2f> > imagePoints;

	// The vector of vectors of points on the calibration pattern in its coordinate system, one vector per view.
	//vector<vector<cv::Point3f> > objectPoints;

	cv::Size imageSize;

	cv::Mat img1;
	cv::Mat imgOut;
	
	std::vector<cv::Point2f> imgPoints;
 	std::vector<cv::Point3f> objpoints;

	// Flag used for memorizing that used demanded to process and store the incomming frame.
	bool addChessboard;
	double lastAngle, actualAngle;
};

} //: namespace ObjectRotation
} //: namespace Processors

/*
 * Register processor component.
 */
REGISTER_COMPONENT("ObjectRotation", Processors::ObjectRotation::ObjectRotation)

#endif /* OBJECTROTATION_HPP_ */
