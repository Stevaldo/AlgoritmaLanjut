#include <iostream>
using namespace std;


void printTheArray(int arr[],int n);
void generateAllBinaryString(int n,int arr[],int i);

int main(){
	int n;
	cout << "Mau Input Berapa Data?";cin >> n;
	int arr[n];
	generateAllBinaryString(n,arr,0);
	return 0;
}

void printTheArray(int arr[],int n){
	for(int i=0;i<n;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

void generateAllBinaryString(int n,int arr[],int i){
	if(n == i){
		printTheArray(arr,n);
		return;
	}
	
	arr[i] = 0;
	generateAllBinaryString(n,arr,i+1);
	
	arr[i] = 1;
	generateAllBinaryString(n,arr,i+1);
}