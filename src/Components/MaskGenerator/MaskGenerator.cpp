/*!
 * \file
 * \brief
 * \author lzmuda
 */

#include <memory>
#include <string>

#include "MaskGenerator.hpp"
#include "Common/Logger.hpp"

#include <boost/bind.hpp>

namespace Processors {
namespace MaskGenerator {

MaskGenerator::MaskGenerator(const std::string & name) :
		Base::Component(name),
		
	m_sum_diff("sumOfDiffColors.diff", 0, "range")/*,
	m_green_diff("green.diff", 0, "range"),
	m_blue_diff("blue.diff", 0, "range"),
	m_red_diff("sum.diff", 0, "range")*/
{
	// Constraints.
	/*m_red_diff.addConstraint("0");
	m_red_diff.addConstraint("255");
	m_green_diff.addConstraint("0");
	m_green_diff.addConstraint("255");

	m_blue_diff.addConstraint("0");
	m_blue_diff.addConstraint("255");*/
	m_sum_diff.addConstraint("0");
	m_sum_diff.addConstraint("765");

	/*registerProperty(m_red_diff);
	registerProperty(m_green_diff);
	registerProperty(m_blue_diff);*/
	registerProperty(m_sum_diff);
      
	LOG(LTRACE) << "Hello MaskGenerator\n";
}

MaskGenerator::~MaskGenerator() {
}

void MaskGenerator::prepareInterface() {
	// Register data streams, events and event handlers HERE!
	h_onNewImage.setup(this, &MaskGenerator::onNewImage);
	registerHandler("GenerateMask", &h_onNewImage);

	registerStream("in_img1", &in_img1);
	registerStream("in_img2", &in_img2);
	registerStream("out_img", &out_img);

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

void MaskGenerator::onNewImage(){
    LOG(LTRACE) << "MaskGenerator::onNewImage\n";
    try {
        std::cout<<"Start\n";
        int val=0;
        img1 = in_img1.read();
        img2 = in_img2.read();
        cv::Size size1 = img1.size();
        cv::Size size2 = img2.size();
        std::cout<<"Clone to tmp\n";
	tmp_img=img1.clone();
        // Check the arrays for continuity and, if this is the case,
        // treat the arrays as 1D vectors
        std::cout<<"Set width\n";
        if (img1.isContinuous() && tmp_img.isContinuous()) {
        	size1.width *= size1.height;
        	size1.height = 1;
        }
        size1.width *= 3;
        std::cout<<"For\n";
        for (int i = 0; i < size1.height; i++)
        {
            const uchar* rgb_p1 = img1.ptr <uchar> (i);
            const uchar* rgb_p2 = img2.ptr <uchar> (i);
            uchar* tmp_p = tmp_img.ptr <uchar> (i);
            int j, k = 0;
            for (j = 0; j < size1.width; j += 3)
            {
            	uchar r1 = rgb_p1[j];
                uchar g1 = rgb_p1[j + 1];
                uchar b1 = rgb_p1[j + 2];
		
		uchar r2 = rgb_p2[j];
                uchar g2 = rgb_p2[j + 1];
                uchar b2 = rgb_p2[j + 2];
                
		uchar sum1 = r1+g1+b1;
		uchar sum2 = r2+g2+b2;
		
		if(abs(sum1-sum2)>m_sum_diff)
		{
		  tmp_p[j] = 255;
		  tmp_p[j+1]  = 255;
		  tmp_p[j+2]  = 255;
		}
		else
		{
		  tmp_p[j]=tmp_p[j+1]=tmp_p[j+2]=0;
		}
            }
        }
        std::cout<<"Write\n";
        out_img.write(tmp_img);
    }
    catch (Common::DisCODeException& ex) {
                   LOG(LERROR) << ex.what() << "\n";
                   ex.printStackTrace();
                   exit(EXIT_FAILURE);
           }
    catch (const char * ex) {
                   LOG(LERROR) << ex;
           }
   catch (...) {
                   LOG(LERROR) << "MaskGenerator::onNewImage failed\n";
           }
}


} //: namespace MaskGenerator
} //: namespace Processors
