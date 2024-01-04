#include <iostream>
using namespace std;

int getRegionCode(double x, double y,double x_min,double x_max,double y_min,double y_max)
{
	int code = 0;

	// Mengatur bit kode wilayah berdasarkan posisi terhadap batas jendela
	if (x < x_min)
		code = code | 1;//0001 adalah disebelah kiri jendela
	else if (x > x_max)
		code = code | 2;//0010 adalah disebelah kanan jendela
	if (y < y_min)
		code = code | 4;//0100 adalah disebelah bawah jendela
	else if (y > y_max)
		code = code | 8;//1000 adalah disebelah atas jendela

	return code;
}

string CSAlgorithm(int code1, int code2, double x1, double y1, double x2, double y2,double x_min,double x_max,double y_min,double y_max){

    //bool clip=true;
    bool outside=false;
    bool inside=false;

    //Jika garis sepenuhnya berada dalam jendela
    if(code1==0 && code2==0){
    //inside=true;
    return "inside";
    }
    else
    if(code1 & code2){
      return "outside";
    }
    else{
        cout <<"\n\t Garis sebagian ada di dalam dan perlu dipotong...\n";

// Iterasi untuk melakukan kliping pada garis
    while(true)
	{
	if(code1==0 && code2==0){
    	break;
        }
        else if (code1 & code2)
		{
			break;
		}
        else{
			double x, y;
			int code;
			if (code1 != 0)
				code = code1;
			else
				code = code2;

			// Menghitung titik potong garis dengan window
			if (code & 8)
			{
				x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
				y = y_max;
			}
			else if (code & 4)
			{
				x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
				y = y_min;
			}
			else if (code & 2)
			{
				y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
				x = x_max;
			}
			else if (code & 1)
			{
				y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
				x = x_min;
			}
			
			// Memperbarui titik awal atau akhir garis dan kode wilayah
			if (code == code1)
			{
				x1 = x;
				y1 = y;
				code1 = getRegionCode(x1, y1,x_min,x_max,y_min,y_max);
			}
			else
			{
				x2 = x;
				y2 = y;
				code2 = getRegionCode(x2, y2,x_min,x_max,y_min,y_max);
			}
        }

	}
        cout <<"\t Garis yang dipotong dari P(" << x1 << "," << y1 << ") ke Q("<< x2 << "," << y2 << ")."<< endl;

    }

return "clipped";
}


int main()
{

    double x_max,y_max,x_min,y_min;
    double px,py,qx,qy;

    cout<<"\t masukkan koordinat windows : \n";
    cout<<"\tx_min : ";
    cin>>x_min;
    cout<<"\ty_min : ";
    cin>>y_min;
    cout<<"\tx_max : ";
    cin>>x_max;
    cout<<"\tx_max : ";
    cin>>y_max;

    cout <<"\n\t koordinat windows:";
    cout <<"\n\tx_min= " << x_min << " , y_min= " << y_min << " , x_max= "<< x_max << " , y_max= " << y_max << "\n" << endl;

    cout<<"\t masukkan koordinat garis : \n";
    cout<<"\tPx : ";
    cin>>px;
    cout<<"\tPy : ";
    cin>>py;
    cout<<"\tQx : ";
    cin>>qx;
    cout<<"\tQy : ";
    cin>>qy;

    // Menampilkan koordinat garis
    cout <<"\n\t Garis P(" << px << "," << py << ") ke Q("<< qx << "," << qy << ") \n"<< endl;

    // Mendapatkan kode wilayah untuk titik awal dan akhir garis
    int code1=getRegionCode(px,py,x_min,x_max,y_min,y_max);
    int code2=getRegionCode(qx,qy,x_min,x_max,y_min,y_max);

    string result=CSAlgorithm(code1,code2,px,py,qx,qy,x_min,x_max,y_min,y_max);

    // Menampilkan hasil kliping
    if(result=="inside")
        cout <<"\n\t Garis P(" << px << "," << py << ") ke Q("<< qx << "," << qy << ") yaitu didalam koordinat jendela. Tidak perlu dipotong"<< endl;

    if(result=="outside")
        cout <<"\n\t Garis P(" << px << "," << py << ") ke Q("<< qx << "," << qy << ") yaitu diluar koordinat jendela."<< endl;

	return 0;
}
