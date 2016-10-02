
// apt-get install libopencv-objdetect-dev
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>


using namespace std;
using namespace cv;

CascadeClassifier cascade;
string window_name = "Face detection";


void detectAndDisplay(Mat frame) {
   std::vector<Rect> faces;
   Mat frame_gray;

   cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
   equalizeHist(frame_gray, frame_gray);

   //-- Detect faces
   cascade.detectMultiScale(frame_gray, faces, 1.1, 5, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30));

   for(size_t i = 0; i < faces.size(); i++) {
     rectangle(frame, faces[i], Scalar(0, 0, 255), 2, 8, 0);
   }

   //-- Show what you got
   imshow(window_name, frame);
}

int main( void )
{
  VideoCapture capture;
  Mat frame;

  //-- 1. Load the cascade
  if(!cascade.load("haarcascade_frontalface_default.xml")) {
    printf("--(!)Error loading haarcascade_frontalface_default.xml\n");
    return -1;
  };
  
  //-- 2. Read the video stream
  capture.open( -1 );
  if(capture.isOpened()) {
    for(;;) {
      capture >> frame;

      //-- 3. Apply the classifier to the frame
      if(!frame.empty()) {
	detectAndDisplay(frame);
      }
      else {
	printf(" --(!) No captured frame -- Break!");
	break;
      }

      int c = waitKey(10);
      if((char)c == 'c' || (char)c == 'q') {
	break;
      }

    }
 
  }

  return 0;
}
