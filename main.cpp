#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <vector>

using namespace cv;
using namespace std;


/////////////////  Face Recognition //////////////////////

int main() {
    double scale = 3.0;
    Mat bg(640, 640, CV_8UC3,
           Scalar(230, 230, 230));

    Scalar rectColor = Scalar(255, 0, 0);
    Scalar fontColor = Scalar(0, 0, 0);


    CascadeClassifier faceCascade;
    faceCascade.load("haarcascade_frontalface_alt.xml");


    VideoCapture cap(0);
    if(!cap.isOpened())
        return -1;

    putText(bg, "Detecting your face. Smile :)", Point(30, 50), FONT_HERSHEY_PLAIN, 1.5, fontColor);
    putText(bg, "Press any key to exit", Point(30, 610), FONT_HERSHEY_PLAIN, 1.5, fontColor);

    for(;;)
    {
        Mat frame;
        cap >> frame;

        Mat grayFrame;
        cvtColor(frame, grayFrame, COLOR_BGR2GRAY);
        resize(grayFrame, grayFrame, Size(grayFrame.size().width / scale, grayFrame.size().height / scale));

        vector<Rect> faces;
        faceCascade.detectMultiScale(grayFrame, faces, 1.1, 3, 0, Size(30, 30));

        for(const Rect& area : faces)
        {
            rectangle(
                    frame,
                    Point(cvRound(area.x * scale), cvRound(area.y * scale)),
                    Point(cvRound((area.x + area.width - 1) * scale), cvRound((area.y + area.height - 1) * scale)),
                    rectColor,
                    2
                    );
        }


        // rescaled height of webcam frame
        auto h = cvRound(bg.size().width * (float)frame.rows / (float)frame.cols);

        resize(frame, frame, Size(bg.size().width, h));

        frame.copyTo(bg(Rect(0, cvRound((float)(bg.size().height - h) / 2), frame.cols, frame.rows)));
        imshow("Webcam Frame", bg);

        if(waitKey(30) > 0)
            break;
    }




    return 0;
}
