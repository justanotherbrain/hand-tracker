#include "ProcessImage.h"

using namespace cv;

// receive color src image
// return grayscale processed image dst
void ProcessImage( Mat src, Mat dst ){
  Mat gray;
  Mat mask;

  cvtColor(src, gray, CV_BGR2GRAY);
  const int MEDIAN_BLUR_FILTER_SIZE = 7; // should be in gui
  medianBlur(gray, gray, MEDIAN_BLUR_FILTER_SIZE);

  Mat edges;
  const int LAPLACIAN_FILTER_SIZE = 5; // should be in gui
  Laplacian(gray, edges, CV_8U, LAPLACIAN_FILTER_SIZE);

  const int EDGES_THRESHOLD = 60;
  threshold(edges, dst, EDGES_THRESHOLD, 255, THRESH_BINARY_INV);

}


