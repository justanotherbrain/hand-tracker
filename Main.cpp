// HandTracker.cpp: rabadi
// description: a simple hand-tracking algorithm using opencv

#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <string>


#include "ProcessImage.h"
#include "Gui.h"

using namespace cv;
using namespace std;

// escape key number
const char ESC = 27;

int main( int argc, char *argv[]) {

  // Set up control window
  cvNamedWindow("control", WINDOW_NORMAL);
  createTrackbar("edge threshold", "control", &edges_threshold_slider, edges_threshold_slider_max, edges_threshold_trackbar);
  
  createTrackbar("laplacian filter size", "control", &laplacian_filter_size_slider, laplacian_filter_size_slider_max, laplacian_filter_size_trackbar);

  createTrackbar("med blur filter size", "control", &med_blur_filter_size_slider, med_blur_filter_size_slider_max, med_blur_filter_size_trackbar);


  
  // access camera
  int camera_number = 0;
  if (argc > 1)
    camera_number = atoi(argv[1]);

  VideoCapture camera;
  camera.open(camera_number);

  if ( !camera.isOpened() ) {
    cerr << "ERROR: could not acces camera!" << endl;
    exit(1);
  }
  Mat camera_frame;
  
  for(;;) {
    camera >> camera_frame;
    if ( camera_frame.empty() ){
      cerr << "ERROR: could not grab camera frame!" << endl;
      exit(1);
    }
    
    Mat processed_frame( camera_frame.size(), CV_8UC3 );
    cvtColor( processed_frame, processed_frame, CV_BGR2GRAY );

    ProcessImage( camera_frame, processed_frame);

    // display processed image
    RunGui(processed_frame);

    char keypress = cv::waitKey(20);
    if (keypress == ESC) {
      break;
    }

  }
}


