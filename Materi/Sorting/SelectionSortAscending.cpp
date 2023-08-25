#include <iostream>
using namespace std;

int main(){
	int index , smallestIndex , minIndex , temp ,n;
	int bil[100];
	
	cout << "Banyak Data : ";
	cin >> n;
	cout << endl;
	
	for(int i=0;i<n;i++){
		cout << "Bilangan[" << i << "]: ";
		cin >> bil[i];
	}
	
	cout << "\n\n";
	cout << "Data Sebelum diurutkan" << endl;
	cout << "-------------------------------" << endl;
	for(int i=0;i<n;i++){
		cout << bil[i] << " ";
	}
	cout << endl;
	
	//Proses Sorting
	for(index=0;index<n-1;index++){
		//Proses Searching
		smallestIndex = index;
		for(minIndex = index+1;minIndex<n;minIndex++){
			if(bil[minIndex] < bil[smallestIndex])smallestIndex = minIndex;
		}
	
		//Swap
		temp = bil[index];
		bil[index] = bil[smallestIndex];
		bil[smallestIndex] = temp;
	}
		cout << "\n\n";
	cout << "Data Setelah diurutkan" << endl;
	cout << "-------------------------------" << endl;
	for(int i=0;i<n;i++){
		cout << bil[i] << " ";
	}
	cout << endl;
	system("pause");
	
	return 0;
}