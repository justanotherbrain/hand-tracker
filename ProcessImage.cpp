#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
//#include "ProcessImage.h"
//#include "Gui.h"
using namespace cv;


extern int edges_threshold;
extern int laplacian_filter_size;
extern int med_blur_filter_size;

// receive color src image
// return grayscale processed image dst
void ProcessImage( Mat src, Mat dst ){
  Mat gray;
  Mat mask;

  cvtColor(src, gray, CV_BGR2GRAY);

  medianBlur(gray, gray, med_blur_filter_size);

  Mat edges;
  
  Laplacian(gray, edges, CV_8U, laplacian_filter_size);
  threshold(edges, dst, edges_threshold, 255, THRESH_BINARY_INV);
}


