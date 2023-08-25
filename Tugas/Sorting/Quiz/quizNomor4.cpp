#include <iostream>
using namespace std;

int main(){
	int index , smallestIndex , minIndex  ,n = 3;
	string plat[50] = {"B4032XY","B5632AB","D7362VI"},
		   mobil[50]= {"Honda","Toyota","Hyundai"};
	string temp;
	
	cout << "Data Sebelum diurutkan" << endl;
	cout << "Plat\tMobil" << endl;
	for(int i=0;i<n;i++){	
		cout << plat[i] << "\t" << mobil[i] << endl;
	}
	cout << endl;
	
	//Proses Sorting
	for(index=0;index<n-1;index++){
		//Proses Searching
		smallestIndex = index;
		for(minIndex = index+1;minIndex<n;minIndex++){
			if(plat[minIndex] > plat[smallestIndex])smallestIndex = minIndex;
		}
	
		//Swap
		temp = plat[index];
		plat[index] = plat[smallestIndex];
		plat[smallestIndex] = temp;
		
		temp = mobil[index];
		mobil[index] = mobil[smallestIndex];
		mobil[smallestIndex] = temp;
	}

	cout << "Data Setelah diurutkan (Descending)" << endl;
	cout << "Plat\tMobil" << endl;
	for(int i=0;i<n;i++){	
		cout << plat[i] << "\t" << mobil[i] << endl;
	}
	cout << endl;
	cout << endl;
	system("pause");
	
	return 0;
}