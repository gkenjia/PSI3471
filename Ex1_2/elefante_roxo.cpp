//elefante_roxo.cpp
#include <opencv2/opencv.hpp>
#include <cmath>
using namespace std;
using namespace cv;

int distancia(Vec3b a, Vec3b b) {
    return sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2) + pow(a[2] - b[2], 2) );
}

int main() {
    Mat_<Vec3b> a=imread("elefante.jpg", 1);
    Mat_<Vec3b> b;
    b=a.clone();

    Vec3b roxo(160, 90, 120);

    for (int l = 0; l < a.rows; l++)
        for (int c = 0; c < a.cols; c++)
        if (distancia(roxo, a(l ,c)) < 50)
            b(l, c)= Vec3b(0, 0, 0);

    imwrite("elefante_preto.png", b);
    waitKey(0);
}