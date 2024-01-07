#include <iostream>
#include <cmath>

using namespace std;

// Fungsi untuk menerapkan transformasi menggunakan matriks pada titik (x, y)
void applyTransformation(double matrix[3][3], double &x, double &y) {
    double result[3] = {0};
    // Perhitungan hasil transformasi menggunakan matriks
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            result[i] += matrix[i][j] * (j == 0 ? x : (j == 1 ? y : 1));
// Update nilai x dan y sesuai hasil transformasi
    x = result[0];
    y = result[1];
}

// Fungsi untuk mencetak matriks transformasi
void printMatrix(const double matrix[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            cout << matrix[i][j] << " ";
        cout << (i == 0 ? "\n" : "") << (i == 1 ? "\n" : "") << (i < 2 ? "\n" : "");
    }
}

void translate(double tx, double ty, double &x, double &y) {
    double matrix[3][3] = {{1, 0, tx}, {0, 1, ty}, {0, 0, 1}};
    cout << "Translation Matrix:\n";
    printMatrix(matrix);
    applyTransformation(matrix, x, y);
}

void scale(double sx, double sy, double &x, double &y) {
    double matrix[3][3] = {{sx, 0, 0}, {0, sy, 0}, {0, 0, 1}};
    cout << "Scaling Matrix:\n";
    printMatrix(matrix);
    applyTransformation(matrix, x, y);
}

void rotate(double suduttheta, double &x, double &y) {
    double theta = suduttheta * M_PI / 180.0;
    double matrix[3][3] = {{cos(theta), -sin(theta), 0},
                           {sin(theta), cos(theta), 0},
                           {0, 0, 1}};
    cout << "Rotation Matrix:\n";
    printMatrix(matrix);
    applyTransformation(matrix, x, y);
}

void mirrorX(double &x, double y) {
    cout << "Mirror X Matrix:\n";
    cout << "1  0  0\t[ " << x << " ]\n";
    cout << "0 -1  0\t[ " << y << " ]\n";
    x = x;
    y = -y;
}

void mirrorY(double x, double &y) {
    cout << "Mirror Y Matrix:\n";
    cout << "-1  0  0\t[ " << x << " ]\n";
    cout << "0  1  0\t[ " << y << " ]\n";
    x = -x;
    y = y;
}

int main() {
    int choice;
    char lagi;
    double x, y;

    cout << "Masukkan titik nilai awal P (x y): ";
    cin >> x >> y;
	do{
    cout << "Choose transformation:\n";
    cout << "1. Translate\n";
    cout << "2. Scale\n";
    cout << "3. Rotate\n";
    cout << "4. Mirror X\n";
    cout << "5. Mirror Y\n";
    cout << "Masukkan pilihan: ";
    cin >> choice;

    switch (choice) {
        case 1:
            double tx, ty;
            cout << "Masukkan nilai translasi (tx): ";
            cin >> tx;
            cout << "Masukkan nilai translasi (ty): ";
            cin >>ty;
            translate(tx, ty, x, y);
            break;
        case 2:
            double sx, sy;
            cout << "Masukkan nilai skala(sx): ";
            cin >> sx;
            cout << "Masukkan nilai skala(sy): ";
            cin >> sy;
            scale(sx, sy, x, y);
            break;
        case 3:
            double suduttheta;
            cout << "Masukkan nilai rotasi (derajat): ";
            cin >> suduttheta;
            rotate(suduttheta, x, y);
            break;
        case 4:
            mirrorX(x, y);
            break;
        case 5:
            mirrorY(x, y);
            break;
        default:
            cout << "Pilihan tidak ada.\n";
            break;
    }
	cout <<"\n";
    cout << " Hasil koordinat titik P: (" << x << ", " << y << ")\n";
	cout << "Pilih operasi transformasi matriks lagi (y/t): ";
        cin >> lagi;
    } while (lagi == 'y' || lagi == 'Y');
    return 0;
}


