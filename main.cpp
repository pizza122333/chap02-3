#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    cout << "Hello OpenCV " << CV_VERSION << endl;

    // 1. lenna.bmp 파일을 그레이스케일로 읽기
    Mat img = imread("lenna.bmp", IMREAD_GRAYSCALE);
    if (img.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    namedWindow("Original Image");
    imshow("Original Image", img);

    Mat brightImg = img + 100;
    namedWindow("Bright Image");
    imshow("Bright Image", brightImg);

    // 두 창 모두 띄운 상태에서 키 입력 대기
    waitKey(0);

    // 4. 밝아진 영상을 파일로 저장
    if (!imwrite("bright.jpg", brightImg)) {
        cerr << "Image save failed!" << endl;
        return -1;
    }

    cout << "Brightened image saved as bright.jpg" << endl;
    return 0;
}

