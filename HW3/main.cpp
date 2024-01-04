#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>

float x1,x2,y1,y2;

// Fungsi untuk menampilkan garis menggunakan algoritma DDA
void display(void){
	float dy,dx,step,x,y,k,Xin,Yin;
	dx=x2-x1;
	dy=y2-y1;

// Menentukan langkah iterasi berdasarkan perbedaan absolut antara dx dan dy
	if(abs(dx)> abs(dy)){
		step = abs(dx);
	}else
		step = abs(dy);

// Menentukan nilai pertambahan x dan y setiap iterasi
	Xin = dx/step;
	Yin = dy/step;
	x= x1;
	y=y1;

// Menggambar titik awal garis
	glBegin(GL_POINTS);
	glVertex2i(x*5,y*5);
	glEnd();

// Melakukan iterasi untuk menggambar garis
	for (k=1 ;k<=step;k++){
		x= x + Xin;
		y= y + Yin;

// Menggambar titik pada garis
	glBegin(GL_POINTS);
	glVertex2i(x*5,y*5);
	glEnd();
}
glFlush();
}

// Fungsi untuk inisialisasi pengaturan tampilan OpenGL
void init(void){
	glClearColor(0.7,0.7,0.7,0.7);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,100,-100,100);
}

int main(int argc, char** argv) {
printf("Masukkan nilai x1 : ");
scanf("%f",&x1);
printf("Masukkan nilai y1 : ");
scanf("%f",&y1);
printf("Masukkan nilai x2 : ");
scanf("%f",&x2);
printf("Masukkan nilai y2 : ");
scanf("%f",&y2);

glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100,100);
glutCreateWindow ("DDA Line Algorithm");
init();
glutDisplayFunc(display);
glutMainLoop();

return 0;
}
