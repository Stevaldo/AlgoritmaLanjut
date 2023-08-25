#include <iostream>
#include <conio.h>
using namespace std;

int segitiga();
int persegi();
void sort();
void menu();
int luas[2] ,a=0;


int main(){	
	menu();
	return 0;
}

void menu(){
	system("cls");
	int pilihan;
	cout << "Program Luas Bangun" << endl;
	cout << "=====================" << endl;
	cout << "1 Segitiga" << endl;
	cout << "2 Persegi" << endl;
	cout << "3 Sort" << endl;
	pilihan:
	cout << "Pilih Menu: ";
	cin >> pilihan;
	if(pilihan == 1){
		system("cls");
		segitiga();
	}else if(pilihan == 2){
		system("cls");
		 persegi();
	}else if(pilihan == 3){
		system("cls");
		sort();
	}else{
		cout << "Input tidak ditemukan,Silahkan Masukkan lagi" << endl;
		goto pilihan;
	}
}

int segitiga(){
	int alas,tinggi;
	if(a==2){
		cout << "Data Sudah Penuh (Maksimal 2)" << endl;
		getch();
		menu();
	}else{
		cout << "Masukkan Alas   : ";
		cin >> alas;
		cout << "Masukkan Tinggi : ";
		cin >> tinggi;
		luas[0]= (alas*tinggi)/2;
		cout << "Luas Segitiga   : " << luas[0] << "cm";
		a++;
		cout << endl << "Ketik apa saja untuk melanjutkan...";
		getch();
		menu();	
	}
}

int persegi(){
	int panjang,lebar;
	if(a==2){
		cout << "Data Sudah Penuh (Maksimal 2)" << endl;
		getch();
		menu();
	}else{
		cout << "Masukkan Panjang : ";
		cin >> panjang;
		cout << "Masukkan Lebar   : ";
		cin >> lebar;
		luas[1] = panjang * lebar;
		cout << "Luas Persegi     : " << luas[1] << "cm";
		a++;
		cout << endl << "Ketik apa saja untuk melanjutkan...";
		getch();
		menu();	
	}
}

void sort(){
	if(a==2){
	int n=2 , temp;
	
	cout << "Data Sebelum diurutkan" << endl;
	cout << "========================" << endl;
 	for(int i=0;i<n;i++){
			cout << "Luas ke-"<< i+1 <<" : " << luas[i] << "cm"<< endl;
		}	
	cout << endl;

		for(int x=0;x<n-1;x++){
			if(luas[x] > luas[x+1]){
				temp = luas[x];
				luas[x] = luas[x+1];
				luas[x+1] = temp;
			}
		}
	
	
	cout << "Data Setelah diurutkan" << endl;
	cout << "========================" << endl;
 	for(int i=0;i<n;i++){
			cout << "Luas ke-"<< i+1 <<" : " << luas[i] << "cm"<< endl;
		}
	getch();
	
	}else{
		cout << "Data Harus 2" << endl;
		getch();
		menu();
	}
}