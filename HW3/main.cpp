#include <iostream>
#include <math.h>
#include <GL/glut.h>

using namespace std;

// Fungsi untuk menggambar titik
void drawPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

// Fungsi DDA untuk menggambar garis
void DDA(int x0, int y0, int x1, int y1) {
    float dx, dy, m, x, y;
    int steps;

    // Menentukan delta x dan delta y
    dx = float(x1 - x0);
    dy = float(y1 - y0);

    // Menentukan nilai m (gradient)
    m = dy / dx;

    // Inisialisasi titik awal (x, y)
    x = x0;
    y = y0;

    // Menentukan jumlah langkah
    if (dx >= dy) {
        steps = dx;
    } else {
        steps = dy;
    }

    // Menghitung perubahan x dan y pada setiap langkah
    float xInc = dx / steps;
    float yInc = dy / steps;

    // Mencetak titik-titik dalam garis
    for (int i = 0; i <= steps; i++) {
        drawPixel(round(x), round(y));
        x += xInc;
        y += yInc;
    }

    glFlush();
}

// Fungsi untuk menampilkan garis
void display() {
	glColor3f(1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
    int x0, y0, x1, y1;

    DDA(x0, y0, x1, y1);
}

// Fungsi inisialisasi OpenGL
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 640, 0, 480);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(720, 480);
    glutCreateWindow("DDA Line Drawing Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
