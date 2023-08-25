#include <iostream>
#include <numeric>
using namespace std;

int C[50],S[50]; // C = Himpunan Kandidat & S = Himpunan Solusi

void sort(int n);
int sumS(int S[],int n);
void exchange(int n,int m);

int main(){
	int n,m; //n = banyaknya kandidat & m = uang yang akan ditukarkan
	
	cout << "Banyaknya Koin : "; cin >> n;
	
	// Input jenis koin
	for(int i=0;i<n;i++){
		cout << "Input Jenis Koin ke-" << i+1 << " : ";
		cin>> C[i];
	}
	
	// Urutkan jenis koin secara Ascending
	sort(n);
	cout << endl;
	
	// Input Uang
	cout << "Masukkan Uang yang akan ditukarkan : "; cin >> m;
	cout << endl;
	
	// Tukar uang dengan koin yang tersedia
	exchange(n,m);
	
	system("pause");
	return 0;
}

void sort(int n){
	// Bubble Sort
	int temp;
	for(int iteration=1;iteration<n;iteration++){
		for(int index=0;index<n-iteration;index++){
			if(C[index] > C[index+1]){
				temp 	   = C[index];  
				C[index]   = C[index+1];
				C[index+1] = temp;
			} 
		}
	}
}

int sumS(int S[],int n){ // Menghitung jumlah uang himpunan S
	int initSum = 0; // untuk menampung hasil penjumlahan
	return accumulate(S,S+n,initSum);
	//accumulate(first , last , sum)
}

void exchange(int n,int m){
	int x=0 , i=n-1 , count=0;
	while((sumS(S,n) != m) && (i>=0)){
		x = C[i];
		i--;
		if((sumS(S,n)+x)<= m){
			S[count] = x;
			count++;
		}
	}
	
	if(sumS(S,n) == m){
		cout << "Koinnya terdiri dari " << count << " koin yakni : ";
		for(int i=0;i<count;i++){
			cout << S[i] << " ";
		}
		cout << endl;
	}else{
		cout << "Tidak ada Solusi" << endl;
	}	
}

// Rumus masih salah benerin lagi dong

