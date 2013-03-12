// Face-Verification-System.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"
#include <string>
#include <stdlib.h>
#include "tools.h"
#include "fisherfaces.h"

using namespace FaceVerificationSystem;
using namespace std;

Mat src1, src2, dst;

[STAThreadAttribute]

int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Form1());

	// Test of fisherfaces
	test();

	// Creation of the video capture
	VideoCapture cap(0);
	if (!cap.isOpened()) return -1;

	Mat frame;
	Mat capture;
	static CvMat *eigenVec, *eigenVal;
	namedWindow("Webcam", 1);
	namedWindow("Capture", 1);

	for(;;)
	{
		cap >> frame;
		imshow("Webcam", frame);
		if (waitKey(30) >= 0) 
		{
			capture = frame;
			imshow("Capture", capture);
		}
	}

	waitKey(0);
	return 0;

}