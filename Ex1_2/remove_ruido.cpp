#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    Mat_<uchar> a=imread("mickeyr.bmp", 0);
    Mat_<uchar> sem_ruido= a.clone();

    for (int l = 1; l < a.rows - 1; l++) {
        for (int c = 1; c < a.cols - 1; c++) {
            // Contagem dos pixeis adjacentes que são iguais ao central
            int pixeisIguais = 0;

        // Análise dos 8 pixeis adjacentes
        for (int i = - 1; i <= 1; i++)
            for (int j = - 1; j <= 1; j++)
                if (a(l + i, c + j) == a(l, c)) {
                    pixeisIguais++;
                }

        if (pixeisIguais <= 5) {
            if ((a(l, c)) == 0)
                sem_ruido(l, c) = 255;
            else
                sem_ruido(l, c) = 0;
        }
        }
    }

    imwrite("eliminarui.png", sem_ruido);
    waitKey(0);
}