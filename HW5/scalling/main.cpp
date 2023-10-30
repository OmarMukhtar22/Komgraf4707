#include <GL/glut.h>

// Koordinat titik A
float xA = 6.0;
float yA = 3.0;

// Koordinat titik B
float xB = 0.0;
float yB = 3.0;

// Faktor scaling
float scaleX = 0.5;
float scaleY = 0.5;

void scaling() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Gambar garis awal
    glColor3f(1.0, 0.0, 0.0);  // Warna merah
    glBegin(GL_LINES);
    glVertex2f(xA, yA);
    glVertex2f(xB, yB);
    glEnd();

    // Hitung koordinat titik A dan B setelah scaling
    float xA_scaled = xA * scaleX;
    float yA_scaled = yA * scaleY;
    float xB_scaled = xB * scaleX;
    float yB_scaled = yB * scaleY;

    // Gambar garis hasil scaling
    glColor3f(0.0, 0.0, 0.0); // warna hitam
    glBegin(GL_LINES);
    glVertex2f(xA_scaled, yA_scaled);
    glVertex2f(xB_scaled, yB_scaled);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 12.0, 0.0, 12.0); // Sesuaikan dengan batasan koordinat
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Scaling 2D");
    init();
    glutDisplayFunc(scaling);
    glutMainLoop();
    return 0;
}


