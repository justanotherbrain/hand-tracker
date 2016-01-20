#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// edge threshold slider
extern int edges_threshold_slider_max = 255;
extern int edges_threshold_slider = 0;
extern int edges_threshold = 0;
void edges_threshold_trackbar(int, void*) {
  edges_threshold = (int) edges_threshold_slider;
};


// laplacian filter size slider
extern int laplacian_filter_size_slider_max = 20;
extern int laplacian_filter_size_slider = 3;
extern int laplacian_filter_size = 3;
void laplacian_filter_size_trackbar(int, void*) {
  if (laplacian_filter_size_slider == 0) laplacian_filter_size_slider++;
  if ( !(laplacian_filter_size_slider % 2) ) laplacian_filter_size_slider++; 
  laplacian_filter_size = (int) laplacian_filter_size_slider;
}


// median blur filter size slider
extern int med_blur_filter_size_slider_max = 20;
extern int med_blur_filter_size_slider = 3;
extern int med_blur_filter_size = 3;
void med_blur_filter_size_trackbar(int, void*) {
  if (med_blur_filter_size_slider == 0) med_blur_filter_size_slider++;
  if ( !(med_blur_filter_size_slider % 2) ) med_blur_filter_size_slider++;
  med_blur_filter_size = (int) med_blur_filter_size_slider;
}

// run gui function
void RunGui( Mat processed_image );

