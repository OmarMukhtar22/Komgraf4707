#include <GL/glut.h>
#include <math.h>

// Koordinat titik A
float xA = 6.0;
float yA = 3.0;

// Koordinat titik B
float xB = 0.0;
float yB = 3.0;

// Sudut rotasi dalam derajat
float angle = 45.0;

void rotasi() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Gambar garis awal
    glColor3f(1.0, 0.0, 0.0);  // Warna merah
    glBegin(GL_LINES);
    glVertex2f(xA, yA);
    glVertex2f(xB, yB);
    glEnd();

    // Konversi sudut rotasi ke radian
    float radian = angle * (3.14159265 / 180.0);
    
    // Hitung koordinat titik A dan B setelah rotasi
    float xA_rotated = xA * cos(radian) - yA * sin(radian);
    float yA_rotated = xA * sin(radian) + yA * cos(radian);
    float xB_rotated = xB * cos(radian) - yB * sin(radian);
    float yB_rotated = xB * sin(radian) + yB * cos(radian);

    // Gambar garis hasil rotasi
    glColor3f(0.0, 0.0, 0.0); //warna hitam
    glBegin(GL_LINES);
    glVertex2f(xA_rotated, yA_rotated);
    glVertex2f(xB_rotated, yB_rotated);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rotasi 2D");
    init();
    glutDisplayFunc(rotasi);
    glutMainLoop();
    return 0;
}

