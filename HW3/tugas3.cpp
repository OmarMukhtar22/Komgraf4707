#include <iostream>
#include <cmath>
using namespace std;

void DDA(int x0, int y0, int x1, int y1) {
    float dx, dy, m, x, y;
    int steps;

    // Menentukan delta x dan delta y
    dx = float(x1 - x0);
    dy = float(y1 - y0);

	// Menentukan nilai m(gradient)
    m = dy / dx;
	
	 // Inisialisasi titik awal (x, y)
    x = x0;
    y = y0;
    
	// Menentukan jumlah langkah
    if (dx >= dy) {
        steps=dx;
    }else{
        steps=dy;     
    }
    // Menghitung perubahan x dan y pada setiap langkah
    float xInc = dx / steps;
    float yInc = dy / steps;
    
    // Mencetak titik-titik dalam garis
    cout << "Titik-titik dalam garis:\n";
    for (int i = 0; i <= steps; i++) {
        cout << "(" << round(x) << ", " << round(y) << ")\n";
        x += xInc;
        y += yInc;
    }
}

int main() {
    int x0, y0, x1, y1;

    cout << "Masukkan koordinat titik awal (x1 y1): ";
    cin >> x0 >> y0;

    cout << "Masukkan koordinat titik akhir (x2 y2): ";
    cin >> x1 >> y1;

    DDA(x0, y0, x1, y1);
}


