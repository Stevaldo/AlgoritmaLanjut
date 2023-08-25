#include <iostream>
using namespace std;

struct mahasiswa{
	int nim;
	string nama;
	int nilai_akhir;
};

mahasiswa nilai[7]={{321102,"Puspa",90},
					{321123,"Sari",70},
					{321105,"Andi",69},
					{321121,"Laras",87},
					{321132,"Budi",76},
					{321101,"Anton",80},
					{321106,"Kiran",95}
};


void print();

void minmax(struct mahasiswa nilai[], int i, int j, int &min, int &max);

int main(){
	int n=7,i,j,jawaban;
	int min, max;
	
	cout<<endl;
	print();
	minmax(nilai, 0, n-1, min, max);
	cout<<"\nNilai Minimum adalah \t: \n"<<min<<endl;
	cout<<"\nNilai Maksimum adalah \t: \n"<<max<<endl;
	
	
	cout<<"Terimakasih sudah menggunakan program ini!\n";
	system("pause");
	return 0;
}

void print(){
	for(int i=0; i < 7 ; i++){
		cout<<nilai[i].nim<<"\t||\t"<<nilai[i].nama<<"\t||\t"<<nilai[i].nilai_akhir<<endl;
	}
}

void minmax(struct mahasiswa nilai[], int i, int j, int &min, int &max){
	int mid, min1, max1 , min2, max2;

	
	if(i == j){//Jika data cuman ada 1 (i(0) == j-1 (1-1))
		min = i;
		max = i;
	}else{//jika data ada lebih dari 1
		if(i == j-1){//jika data = 2, bandingkan bil[0] dengan bil[1]
			if(nilai[i].nilai_akhir<nilai[j].nilai_akhir){//jika bil[0] < bil[1], maka min = bil[0] dan max = bil[1]
				min = i;
				max = j;
			}else{//jika bil[1] < bil[0], maka min = bil[1] dan max = bil[0]
				min = j;
				max = i;
			}
		}else{
			mid = (j+i)/2;//bagi dua data
			minmax(nilai,i,mid,min1,max1);//memanggil minmax dari jangkauan i-k (low -> mid)
			minmax(nilai,mid+1,j,min2,max2);//memanggil minmax dari jangkauan k+1 - j (mid+1 -> high)
			//membandingkan min dan max yang lebih kecil
			if(nilai[min1].nilai_akhir<nilai[min2].nilai_akhir){
				min = min1;	
			}else{
				min = min2;
			}
			
			if(nilai[max1].nilai_akhir>nilai[max2].nilai_akhir){
				max = max1;
			}else{
				max = max2;
			}
			
		}
	}	
}
