#include <iostream>
using namespace std;

int unsortedLinerSearch(int Data[],int n,int cariBil);

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
	
	hasil = unsortedLinerSearch(bil,n,cariBil);
	
	if(hasil != -1){
		cout << cariBil << " ditemukan pada index ke-["<< hasil <<"]" << endl;
	}else{
		cout << cariBil << " tidak ditemukan" << endl;
	}
	system("pause");
	return 0;
}

int unsortedLinerSearch(int Data[] , int n, int cariBil){
	for(int i=0;i<n;i++){
		if(Data[i] ==  cariBil)return i;
	}
	return -1;
}