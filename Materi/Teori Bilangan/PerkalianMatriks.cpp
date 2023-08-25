#include <iostream>
using namespace std;


// Butuh banyak perbaikannnnnnnnnnnnnn
int main(){
	int matriks = 2;	
	
	int tempBaris[matriks],tempKolom[matriks],baris,kolom;;
	for(int i=0;i<matriks;i++){
		cout << "Jumlah Baris Matriks ke-" << i+1 << " : "; cin >> tempBaris[i];
		cout << "Jumlah Kolom Matriks ke-" << i+1 << " : "; cin >> tempKolom[i];
		cout << endl;
	}
	
		if(tempKolom[0] != tempBaris[1]){
			cout << "Matriks tidak dapat dikalikan Karena tidak sesuai";
			exit(0);
		}
	
	int C[matriks][baris][kolom];
	
	for(int x=0;x<matriks;x++){
		cout << "Matriks ke-" << x+1 << endl;
			for(int j=0;j<tempBaris[x];j++){
					for(int i=0;i<tempKolom[x];i++){
						cout << "Matriks[" << j << "][" << i <<"] : ";
						cin >> C[x][j][i];
					}
			}
		cout << endl;
	}
	
	baris = tempBaris[0];
	kolom = tempKolom[1];
	
	cout << "Hasil dari Matriks";
	for(int i=0;i<matriks;i++){
		if(i==matriks-1){
			cout << " " << i+1 << " : Matriks " << baris << "x" << kolom << endl;;
		}else{
			cout << " " << i+1 << " *";
		}
	}
	
	// Rumus Menghitung Perkalian Matriks
	for(int x=0;x<matriks;x++){
		for(int j=0;j<baris;j++){
			for(int i=0;i<kolom;i++){
				
			}
		}
	}
	
	return 0;
}