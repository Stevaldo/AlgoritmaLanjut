#include <iostream>
using namespace std;

int main(){
	int temp,n;
	int bil[100];
	
	cout << "Jumlah Data : ";
	cin >> n;
	cout << endl;
	
	for(int i=0;i<n;i++){
		cout << "Bilangan[" << i << "]: ";
		cin >> bil[i];
	}
	
	// Cetak Data
	cout << "\n\nData Sebelum diurutkan" << endl;
	cout << "---------------------------" << endl;
	
	for(int i=0;i<n;i++){
		cout << bil[i] << " ";
	}
	
	cout << endl;
	
	// Proses Sorting
	for(int iteration =1;iteration<n;iteration++){
		for(int index=0;index<n-iteration;index++){
			
			if(bil[index] < bil[index+1]){ // untuk Ascending menggunakan > dari , sedangkan Descending menggunakan <
				temp = bil[index];
				bil[index] = bil[index+1];
				bil[index+1] = temp;
			}
			
		}
	}
	
	// Cetak Data
	cout << "\n\nData Setelah diurutkan" << endl;
	cout << "---------------------------" << endl;
	
	for(int i=0;i<n;i++){
		cout << bil[i] << " ";
	}
	
	cout << endl;
	system("pause"); // Mempertahankan Layar , seperti getch()
}