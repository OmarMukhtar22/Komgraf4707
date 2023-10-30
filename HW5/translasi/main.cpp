#include <GL/glut.h>

// Koordinat titik A
float xA = 6.0;
float yA = 3.0;

// Koordinat titik B
float xB = 0.0;
float yB = 3.0;

// Vektor translasi
float tx = 2.0;
float ty = 2.0;

void translasi() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Gambar garis awal
    glColor3f(1.0, 0.0, 0.0);  // Warna merah
    glBegin(GL_LINES);
    glVertex2f(xA, yA);
    glVertex2f(xB, yB);
    glEnd();

    // Hitung koordinat titik A dan B setelah translasi
    float xA_translated = xA + tx;
    float yA_translated = yA + ty;
    float xB_translated = xB + tx;
    float yB_translated = yB + ty;

    // Gambar garis hasil translasi
    glColor3f(0.0, 0.0, 0.0); //warna hitams
    glBegin(GL_LINES);
    glVertex2f(xA_translated, yA_translated);
    glVertex2f(xB_translated, yB_translated);
    glEnd();
    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 10.0, 0.0, 10.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Translasi 2D");
    init();
    glutDisplayFunc(translasi);
    glutMainLoop();
    return 0;
}

