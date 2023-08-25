#include <iostream>
using namespace std;

int SortedLinerSearch(int Data[],int n,int cariBil);

/* Data input User harus secara Descending / Ascending sesuai dengan Bari 36
Pastikan data sudah di sort */

int main(){
	int n , bil[100] , cariBil , hasil;
	
	cout << "Banyak Data : "; cin >> n;
	cout << endl;
	
	for(int i=0;i<n;i++){
		cout << "Bilangan["<< i << "] :"; cin >> bil[i]; 
	}
	cout << endl;
	
	cout << "Cari Bilangan\t : "; cin >> cariBil;
	
	cout << endl;
	
	hasil = SortedLinerSearch(bil,n,cariBil);
	
	if(hasil != -1){
		cout << cariBil << " ditemukan pada index ke-["<< hasil <<"]" << endl;
	}else{
		cout << cariBil << " tidak ditemukan" << endl;
	}
	system("pause");
	return 0;
}

int SortedLinerSearch(int Data[] , int n, int cariBil){
	for(int i=0;i<n;i++){
		if(Data[i] ==  cariBil)return i;
		if(Data[i] > cariBil) return -1; // Ascending menggunakan > sedangkan Descending menggunakan <
	}
	return -1;
}