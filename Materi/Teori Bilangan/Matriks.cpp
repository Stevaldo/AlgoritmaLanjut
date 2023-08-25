#include <iostream>
#include <conio.h>
using namespace std;


int main(){
	int matriks,baris,kolom;
	cout << "Jumlah Matriks : "; cin >> matriks;	
	
	if(matriks == 1 || matriks == 0){
		cout <<"Masukkan Jumlah yang Valid";
		exit(0);
	}
	
		cout << "Jumlah Baris : " ; cin >> baris;
		cout << "Jumlah Kolom : " ; cin >> kolom;
	
	int A[matriks][baris][kolom];
		
		cout << endl;
	
	for(int x=0;x<matriks;x++){
		cout << "Matriks ke-" << x+1 << endl;
		for(int j=0;j<baris;j++){
				for(int i=0;i<kolom;i++){
					cout << "Matriks[" << j << "][" << i <<"] : ";
					cin >> A[x][j][i];
				}
		}
		cout << endl;
	}
	
	cout << "Hasil dari Matriks";
	for(int i=0;i<matriks;i++){
		if(i==matriks-1){
			cout << " " << i+1 << " : " << endl;
		}else{
			cout << " " << i+1 << " +";
		}
	}
	
	int B[matriks][baris][kolom];
	
	// Rumus Menghitung Pertambahan Matriks
	for(int x=0;x<matriks;x++){
		for(int j=0;j<baris;j++){
			for(int i=0;i<kolom;i++){
				B[x][j][i] = A[x][j][i] + A[x+1][j][i];
			}
		}
	}
	
	
	//Cetak
		cout << "Hasil Matriks : " << endl;
		for(int j=0;j<baris;j++){
			cout << "[";
				for(int i=0;i<kolom;i++){
					cout << B[0][j][i];
					cout << " ";
				}
			cout << "]" << endl;
		}
	
	
	return 0;
}