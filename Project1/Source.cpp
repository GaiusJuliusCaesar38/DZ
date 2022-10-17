#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <cmath>
#include <string>
#include <iostream>

//#include <utility>

using namespace cv;
using std::cout;
using std::cin;
using std::endl;

int main() {
    std::string image;
    int n = 100;
    std::string* imageDataSet;
    imageDataSet = new std::string[n];
    int count = 0;
    for (;;) {
        cin >> image;
        if (image == "q" || image == "Q") {
            break;
        }
        std::string image_path = samples::findFile(image);
        Mat img = imread(image_path, IMREAD_COLOR);
        if (img.empty()) {
            std::cout << "Could not read the image: " << image_path << std::endl;
            return 1;
        }
        int gb = 0;
        int gr = 0;
        for (int y = 0; y < img.rows; y++) {
            for (int x = 0; x < img.cols; x++) {
                Vec3b color = img.at<Vec3b>(Point(x, y));
                gr += color[1];
                gb += color[1];
                gr -= color[2];
                gb -= color[0];
            }
        }
        if (gr > 0 && gb > 0) {
            //cout << "Green picture" << endl;
        }
        else if (gr > 0 && gb < 0) {
            imageDataSet[count] = image;
            count++;
        }
        else if (gr < 0 && gb>0) {
            //cout << "Red picture" << endl;
        }
        else if (gr < 0 && gb < 0) {
            if (abs(gr) >= abs(gb)) {
               //cout << "Red picture" << endl;
            }
            else {
                imageDataSet[count] = image;
                count++;
            }
        }
        //imshow("Display window", img);
        //int key = waitKey(0);
        //if( key == 'n' || key == 'N') {
        //    i++;
        //}
        //if (key == 27 ) {
        //    break;
        //}
    }
    cout << endl << endl << "Blue pictures";
    for (int i = 0; i < count; i++) {
        cout << imageDataSet[i] << endl;
    }
    return 0;
}
//BGR
// 
// 
//Vec3b intensity = img.at<Vec3b>(y, x); uchar
//uchar blue = intensity.val[0];
//uchar green = intensity.val[1];
//uchar red = intensity.val[2];