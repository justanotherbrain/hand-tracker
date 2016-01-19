// HandTracker.cpp: rabadi
// description: a simple hand-tracking algorithm using opencv

#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <string>

#include "ProcessImage.h"
//#include "Helpers.h"

using namespace cv;
using namespace std;

// escape key number
const char ESC = 27;

int main( int argc, char *argv[]) {
  
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

  for(;;) {
    Mat camera_frame;
    camera >> camera_frame;
    if ( camera_frame.empty() ){
      cerr << "ERROR: could not grab camera frame!" << endl;
      exit(1);
    }
    
    Mat processed_frame( camera_frame.size(), CV_8UC3 );
    cvtColor( processed_frame, processed_frame, CV_BGR2GRAY );

    ProcessImage( camera_frame, processed_frame );

    // display processed image
    imshow("Processed", processed_frame );

    char keypress = cv::waitKey(20);
    if (keypress == ESC) {
      break;
    }

  }
}


