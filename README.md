# chap02-3


소스코드 설명

```cpp
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    // OpenCV 버전 출력
    cout << "Hello OpenCV " << CV_VERSION << endl;

    // 1. lenna.bmp 파일을 그레이스케일로 읽기
    Mat img = imread("lenna.bmp", IMREAD_GRAYSCALE);
    if (img.empty()) {
        // 이미지 읽기 실패 시 에러 메시지 출력 후 종료
        cerr << "Image load failed!" << endl;
        return -1;
    }

    // 2. 원본 이미지 화면에 출력
    namedWindow("Original Image"); // "Original Image" 창 생성
    imshow("Original Image", img); // 원본 이미지 표시

    // 3. 이미지 밝기 증가
    Mat brightImg = img + 100; // 모든 픽셀 값에 100 더하기
    namedWindow("Bright Image"); // 밝기 증가 영상용 새 창 생성
    imshow("Bright Image", brightImg); // 밝아진 이미지 표시

    // 두 창 모두 띄운 상태에서 키 입력을 기다림
    waitKey(0);

    // 4. 밝아진 이미지를 파일로 저장
    if (!imwrite("bright.jpg", brightImg)) {
        cerr << "Image save failed!" << endl;
        return -1;
    }

    cout << "Brightened image saved as bright.jpg" << endl;
    return 0;
}
