#include <iostream>
#define n 5
using namespace std;

struct mahasiswa
{
    int noPeserta,mtk,bindo,binggris,hasil;
    string kelulusan;
};

void MinMax (struct mahasiswa mhs[n],int i,int j, int &min , int &max);
void print(struct mahasiswa data[n]);

int main()
{
    //Inisialisasi Awal
    mahasiswa mhs[n] =
     {
        {202,89,80,80,0,"NULL"},{302,60,86,70,0,"NULL"},{311,50,40,65,0,"NULL"},
        {233,97,100,95,0,"NULL"},{321,88,87,90,0,"NULL"}
    };
    
    //Menghitung Hasil Akhir dan Seleksi Kelulusan
    for(int i=0;i<n;i++){
        mhs[i].hasil = (mhs[i].mtk+mhs[i].bindo+mhs[i].binggris)/3;
        if(mhs[i].hasil >= 80 && mhs[i].hasil <=100){
            mhs[i].kelulusan = "Lulus";
        }else if(mhs[i].hasil < 80 && mhs[i].hasil >= 0){
            mhs[i].kelulusan = "Tidak Lulus";
        }else{
            mhs[i].kelulusan = "Nilai tidak Valid";
        }
    }

    //Mengambil Nilai Terbaik dan Terburuk Mahasiswa
    int min,max;
    MinMax(mhs,0,n-1,min,max);

    //Mencetak Data
    print(mhs);

    //Mencetak Nilai Terbaik dan Terburuk Mahasiswa
    cout << endl;
    cout << "Mahasiswa dengan Nilai Terbaik" << endl;
    cout << "   " << mhs[max].noPeserta << "\t\t" << mhs[max].mtk << "\t\t" << mhs[max].bindo << "\t\t  " << mhs[max].binggris <<"\t\t  "<< mhs[max].hasil << "\t" << mhs[max].kelulusan << endl;

    cout << "Mahasiswa dengan Nilai Terburuk" << endl;
    cout << "   " << mhs[min].noPeserta << "\t\t" << mhs[min].mtk << "\t\t" << mhs[min].bindo << "\t\t  " << mhs[min].binggris <<"\t\t  "<< mhs[min].hasil << "\t" << mhs[min].kelulusan << endl ;


}

void print(struct mahasiswa data[n]){
    cout << "No Peserta\tMTK\tBahasa Indonesia    Bahasa Inggris\tHasil" << endl;
    for(int i=0;i<n;i++){
        cout << "   " << data[i].noPeserta << "\t\t" << data[i].mtk << "\t\t" << data[i].bindo << "\t\t  " << data[i].binggris <<"\t\t  "<< data[i].hasil << "\t" << data[i].kelulusan << endl;
    }
}

void MinMax (struct mahasiswa mhs[n],int i,int j, int &min , int &max){
	int k , min1 , min2 , max1 , max2;
	
	if(i==j){
		min = i; 
		max = i;
	}else{
		if(i == j-1){
			if(mhs[i].hasil<mhs[j].hasil){
				min = i;
				max = j;
			}
			else{	
				min = j;
				max = i;
			}
		}else{
			k = (i+j)/2;
			MinMax(mhs,i,k,min1,max1);
			MinMax(mhs,k+1,j,min2,max2);
            
			if(mhs[min1].hasil<mhs[min2].hasil){
				min = min1;
			}else{
				min = min2;
			}
			
			if(mhs[max1].hasil>mhs[max2].hasil){
				max = max1;
			} else{
				max = max2;
			}
		}
	}
}
