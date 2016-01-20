#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

//#include "Gui.h"
//#include "ProcessImage.h"

using namespace cv;
using namespace std;


void RunGui( Mat processed_frame ){
  imshow("processed", processed_frame);
}


