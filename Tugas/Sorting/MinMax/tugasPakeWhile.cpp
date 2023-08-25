#include <iostream>
using namespace std;

struct dataMahasiswa{
    int no,mtk,bindo,binggris,hasil;
    string lulusTidakLulus;
};

int x = 0;

void minMax (struct dataMahasiswa dat[5],int i,int j, int &min , int &max){
	int k , min1 , min2 , max1 , max2;
	
	if(i==j){
		min = i;
		max = i;
	}else{
		if(i == j-1){
			if(dat[i].hasil<dat[j].hasil){
				min = i;
				max = j;
			}
			else{	
				min = j;
				max = i;
			}
		}else{
			k = (i+j)/2;
			minMax(dat,i,k,min1,max1);
			minMax(dat,k+1,j,min2,max2);
			if(dat[min1].hasil<dat[min2].hasil){
				min = min1;
			}else{
				min = min2;
			}
			
			if(dat[max1].hasil>dat[max2].hasil){
				max = max1;
			} else{
				max = max2;
			}
		}
	}
}

int main(){
    dataMahasiswa mhs[5] = {
         {202,89,80,80,0},{302,60,86,70,0},{311,50,40,65,0},
        {233,97,100,95,0},{321,88,87,90,0}
        };

    while(mhs[x].hasil == 0){
        mhs[x].hasil = (mhs[x].mtk + mhs[x].bindo + mhs[x].binggris)/3;
        if(mhs[x].hasil >= 80){
            mhs[x].lulusTidakLulus = "Lulus";
        }else{
            mhs[x].lulusTidakLulus = "Tidak Lulus";
        }
        x++;
    }

    int min ,max;
    minMax(mhs,0,4,min,max);

    cout << "No Peserta\tMTK\tBahasa Indonesia    Bahasa Inggris\tHasil" << endl;
    for(int x=0;x<5;x++){
        cout << "   " << mhs[x].no << "\t\t" << mhs[x].mtk << "\t\t" << mhs[x].bindo << "\t\t  " << mhs[x].binggris <<"\t\t  "<< mhs[x].hasil << "\t" << mhs[x].lulusTidakLulus << endl;
    }

    cout << endl;
    cout << "Mahasiswa dengan Nilai Terbaik" << endl;
    cout << "   " << mhs[max].no << "\t\t" << mhs[max].mtk << "\t\t" << mhs[max].bindo << "\t\t  " << mhs[max].binggris <<"\t\t  "<< mhs[max].hasil << "\t" << mhs[max].lulusTidakLulus << endl;

    cout << "Mahasiswa dengan Nilai Terburuk" << endl;
    cout << "   " << mhs[min].no << "\t\t" << mhs[min].mtk << "\t\t" << mhs[min].bindo << "\t\t  " << mhs[min].binggris <<"\t\t  "<< mhs[min].hasil << "\t" << mhs[min].lulusTidakLulus << endl ;

}