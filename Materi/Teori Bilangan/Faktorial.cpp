#include <iostream>
using namespace std;

int faktorial(int n);

int main(){
	int f;
	cout << "Masukkan Angka yang akan di faktorialkan : "; cin >> f;
	cout << f << "!= " << faktorial(f) << endl;
	system("pause");	
	return 0;
}

int faktorial(int n){
	if(n==0){
		return 1;
	}else{
		return n * faktorial(n-1);
	}
}