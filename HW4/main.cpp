#include <gl/glut.h>
#include <stdio.h>

int x0, y0, xend, yend;

void myInit() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 10, 0, 10);
}

void draw_pixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void gambarGaris(int x0, int xend, int y0, int yend) {
    int dx, dy, i, point;
    int incx, incy, inc1, inc2;
    int x, y;

    dx = xend - x0;
    dy = yend - y0;

    incx = 1;
    if (dx < 0) {
        incx = -1;
        dx = -dx;
    }
    incy = 1;
    if (dy < 0) {
        incy = -1;
        dy = -dy;
    }

    x = x0;
    y = y0;

    if (dx > dy) {
        point = 2 * dy - dx;
        inc1 = 2 * (dy - dx);
        inc2 = 2 * dy;

        for (i = 0; i < dx; i++) {
            x += incx;
            if (point >= 0) {
                y += incy;
                point += inc1;
            } else {
                point += inc2;
            }
        }
    } else {
        point = 2 * dx - dy;
        inc1 = 2 * (dx - dy);
        inc2 = 2 * dx;

        for (i = 0; i < dy; i++) {
            y += incy;
            if (point >= 0) {
                x += incx;
                point += inc1;
            } else {
                point += inc2;
            }
        }
    }
}

void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); 
    glBegin(GL_LINES);
    glVertex2i(x0, y0);
    glVertex2i(xend, yend);
    glEnd();
    gambarGaris(x0, xend, y0, yend);
    glFlush();
}



int main(int argc, char **argv) {
    printf("Masukkan koordinat x0: ");
    scanf("%d", &x0);
    printf("Masukkan koordinat y0: ");
    scanf("%d", &y0);
    printf("Masukkan koordinat xend: ");
    scanf("%d", &xend);
    printf("Masukkan koordinat yend: ");
    scanf("%d", &yend);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bresenham Algorithm Line Drawing");
    myInit();

    glutDisplayFunc(myDisplay);
    glutMainLoop();

    return 0;
}
