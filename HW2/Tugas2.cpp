#include <iostream>

using namespace std;

int main() {
    int baris1, kolom1, baris2, kolom2;
    double skalar;

	cout << "=========================" <<endl;
	cout << "TUGAS 2 KOMPUTER GRAFIK" <<endl;
	cout << "=========================" <<endl;
	cout <<endl;
    cout << "Masukkan jumlah baris matriks pertama: ";
    cin >> baris1;
    cout << "Masukkan jumlah kolom matriks pertama: ";
    cin >> kolom1;
    cout << "Masukkan jumlah baris matriks kedua: ";
    cin >> baris2;
    cout << "Masukkan jumlah kolom matriks kedua: ";
    cin >> kolom2;

	cout << endl;
    // Membuat matriks A
    int matrixA[baris1][kolom1];

    cout << "Masukkan nilai matriks A:" << endl;
    for (int i = 0; i < baris1; i++) {
        for (int j = 0; j < kolom1; j++) {
            cin >> matrixA[i][j];
        }
    }

    // Membuat matriks B
    int matrixB[baris2][kolom2];

    cout << "Masukkan nilai matriks B:" << endl;
    for (int i = 0; i < baris2; i++) {
        for (int j = 0; j < kolom2; j++) {
            cin >> matrixB[i][j];
        }
    }
    
    cout<<endl;

    // Membuat matriks hasil penjumlahan
    int hasilPenjumlahan[baris1][kolom1];

    // Melakukan penjumlahan matriks A dan matriks B
    for (int i = 0; i < baris1; i++) {
        for (int j = 0; j < kolom1; j++) {
            hasilPenjumlahan[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    // Menampilkan hasil penjumlahan matriks
    cout << "Hasil penjumlahan matriks :" << endl;
    for (int i = 0; i < baris1; i++) {
        for (int j = 0; j < kolom1; j++) {
            cout << hasilPenjumlahan[i][j] << " ";
        }
        cout << endl;
    }
    
    cout<<endl;
    
    // Membuat matriks hasil pengurangan
    int hasilPengurangan[baris1][kolom1];

    // Melakukan pengurangan matriks A dan matriks B
    for (int i = 0; i < baris1; i++) {
        for (int j = 0; j < kolom1; j++) {
            hasilPengurangan[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }

    // Menampilkan matriks hasil pengurangan
    cout << "Hasil pengurangan matriks:" << endl;
    for (int i = 0; i < baris1; i++) {
        for (int j = 0; j < kolom1; j++) {
            cout << hasilPengurangan[i][j] << " ";
        }
        cout << endl;
    }
    
    cout<<endl;
    // Cek apakah matriks dapat dikalikan
    if (kolom1 != kolom2 || baris1 != baris2) {
        cout << "Matriks tidak dapat dikalikan karena ordonya tidak sama." << endl;
    }else{

    // Membuat matriks hasil perkalian 
    int hasilPerkalian[baris1][kolom2];

    // Melakukan perkalian matriks A dan matriks B
    for (int i = 0; i < baris1; i++) {
        for (int j = 0; j < kolom2; j++) {
            hasilPerkalian[i][j] = 0;
            for (int k = 0; k < kolom1; k++) {
                hasilPerkalian[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    // Menampilkan matriks hasil perkalian 
    cout << "Hasil perkalian matriks:" << endl;
    for (int i = 0; i < baris1; i++) {
        for (int j = 0; j < kolom2; j++) {
            cout << hasilPerkalian[i][j] << " ";
        }
        cout << endl;
    }
    
    cout<<endl;
    cout << "Masukkan skalar untuk perkalian skalar: ";
    cin >> skalar;

    // Melakukan perkalian matriks A dengan skalar
    for (int i = 0; i < baris1; i++) {
        for (int j = 0; j < kolom1; j++) {
            matrixA[i][j] *= skalar;
        }
    }
       // Menampilkan matriks A hasil perkalian dengan skalar
    cout << "Hasil perkalian matriks A dengan skalar " << skalar << ":"<<endl;
    for (int i = 0; i < baris1; i++) {
        for (int j = 0; j < kolom1; j++) {
            cout << matrixA[i][j] << " ";
        }
        cout << endl;
    }
        // Melakukan perkalian matriks B dengan skalar
    for (int i = 0; i < baris2; i++) {
        for (int j = 0; j < kolom2; j++) {
            matrixB[i][j] *= skalar;
        }
    }
       // Menampilkan matriks B hasil perkalian dengan skalar
    cout << "Hasil perkalian matriks B dengan skalar " << skalar << ":"<<endl;
    for (int i = 0; i < baris2; i++) {
        for (int j = 0; j < kolom2; j++) {
            cout << matrixB[i][j] << " ";
        }
        cout << endl;
    }
    
    cout<<endl;
    cout << "========================================================" <<endl;
    cout << "Nama   : Omar Mukhtar" <<endl;
    cout << "Nim    : A11.2020.13036" <<endl;
    cout << "Matkul : Komputer Grafik" <<endl;
    cout << "Kelas  : A11.4707" <<endl;
    cout << "========================================================" <<endl;
    
}
    return 0;
}



