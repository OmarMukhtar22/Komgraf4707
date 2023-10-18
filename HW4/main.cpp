#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include <iostream>
#include <GL\freeglut.h>
#include <GL\glut.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>


using namespace std;

void tampilan(void)
{
	glClearColor(1.0, 1.0, 0.0, 0.0); //set warna background 
	glMatrixMode(GL_PROJECTION); //set mode matriks yang digunakan 
	gluOrtho2D(0.0, 300.0, 0.0, 300.0); // set ukuran viewing window
}
void aturPixel (GLint x, GLint y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glFlush();
    glEnd();
}

void garisbresenham(GLint x0, GLint y0, GLint xEnd, GLint yEnd) {
	//hitung dx dan dy
	GLint dx = (float)fabs((float)xEnd - x0);
    GLint dy = (float)fabs((float)yEnd - y0);
    GLint p = 2 * (dy - dx);
   	GLint duady = 2 * dy;
    GLint duadydx = 2 * (dy - dx);
    GLint x,y;
    
    if (x0 > xEnd) {
        x = xEnd;
        y = yEnd;
        xEnd=x;
    } else {
        x = x0;
        y = y0;
    }
	
	aturPixel(x, y);
    
    while (y < yEnd) {
        y++;
        if (p > 0) {
            p += duady;
        } else {
            x++;
            p += duadydx;
        }
        aturPixel(x, y);
    }
}

void gambarGaris(void){
	glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0);
    glPointSize(5.0);
    GLint  x0 = 3;
    GLint  y0 = 0;
    GLint  xEnd = 3;
    GLint  yEnd = 6;
    glutSwapBuffers(); //swap buffer 
	
	garisbresenham(x0, y0, xEnd, yEnd);
}

int main(int argc, char** argv) {
	
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(720, 480);
    glutCreateWindow("Bresenham Line Drawing Algorithm");
    tampilan();
    glutDisplayFunc(gambarGaris);
    glutMainLoop();

	return 0;
}
