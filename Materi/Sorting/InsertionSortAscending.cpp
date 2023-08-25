#include <iostream>
using namespace std;

int main(){
	int firstOutOfOrder , location , temp  , n;
	int bil[100];
	
	cout << "Banyak Data : ";
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
	//Proses Sorting
	for(firstOutOfOrder=1;firstOutOfOrder<n;firstOutOfOrder++){
		temp  = bil[firstOutOfOrder];
		location = firstOutOfOrder;
		while(bil[location-1] > temp && location >= 1){
			bil[location] = bil[location-1];
			location--;
		}
		bil[location] = temp;
		
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