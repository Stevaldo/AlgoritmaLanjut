#include <iostream>
using namespace std;

int InterpolationSearch(int Data[],int n,int cariBil);


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
	
	hasil = InterpolationSearch(bil,n,cariBil);
	
	if(hasil != -1){
		cout << cariBil << " ditemukan pada index ke-["<< hasil <<"]" << endl;
	}else{
		cout << cariBil << " tidak ditemukan" << endl;
	}
	system("pause");
	return 0;
}

int InterpolationSearch(int Data[] , int n, int cariBil){
	int low = 0 , high = n-1 , mid;
	
	while(low <= high){ 
		
		mid = low + (((cariBil-Data[low])*(high-low))/(Data[high]-Data[low]));
		
		if(Data[mid] == cariBil) return mid;
		
		else if(Data[mid] < cariBil) low = mid+1; // Ascending menggunakan < sedangkan Descending menggunakan >
		
		else high = mid-1;
	}
	return -1;
}