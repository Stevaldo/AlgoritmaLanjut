#include <iostream>
#include <conio.h>
using namespace std;

int searchNIM(int Data[] , int n, int cariBil){
   int low = 0 , high = n-1 , mid;
	
	while(low <= high){  
		
		mid = (low+high)/2;
		
		if(Data[mid] == cariBil) return mid;
		
		else if(Data[mid] < cariBil) low = mid+1; // Ascending menggunakan < sedangkan Descending menggunakan >
		
		else high = mid-1;
	}
	return -1;
}

int main(){
    char pilihan;
    int nim[6] = {32190047,32190035,32190044,32190056,32190037,32190059},
        nilaiTugas[6] = {89,60,76,97,88,80},
        nilaiUTS[6] = {80,86,79,100,87,75},
        nilaiUAS[6] = {80,70,65,95,90,62},
        nilaiAkhir[6];

    // Hitung Nilai Akhir
    for(int i=0;i<6;i++){
       nilaiAkhir[i] = ((30*nilaiTugas[i])/100) + ((30*nilaiUTS[i])/100) + ((40*nilaiUAS[i])/100); 
    }

    balik:
    cout << "Menu :" << endl;
    cout << "1. Urutkan nilai akhir secara descending" << endl;
    cout << "2. Search NIM" << endl;
    pilihan = getch();
    cout << endl;

    if(pilihan == '1'){
        int firstOutOfOrder , location , temp , n=6;
        //Proses Sorting
	    for(firstOutOfOrder=1;firstOutOfOrder<n;firstOutOfOrder++){
		temp  = nilaiAkhir[firstOutOfOrder];
		location = firstOutOfOrder;
		while(nilaiAkhir[location-1] < temp && location >= 1){
			nilaiAkhir[location] = nilaiAkhir[location-1];
			location--;
		}
		nilaiAkhir[location] = temp;	
	    }

        // Output
        cout << "Data Nilai Mahasiswa Algoritma Lanjut" << endl;
        cout << "------------------------------------------------------------------" << endl;
        cout << "NIM       | Nilai Tugas  | Nilai UTS    | Nilai Uas  | Nilai Akhir" << endl;
        cout << "------------------------------------------------------------------" << endl;
        for(int i=0;i<6;i++){
        cout << nim[i] << "  | " << nilaiTugas[i] << "           | " << nilaiUTS[i] << "           | " << nilaiUAS[i] << "         | " << nilaiAkhir[i] << endl;
        } 
    }else if(pilihan == '2'){
        int cariBil , index;
        cout << "Silahkan Masukkan NIM yang ingin dicari : "; cin >> cariBil;
        index = searchNIM(nim,6,cariBil);

        if(index != -1){
            // Output
            cout << "Data Nilai Mahasiswa Algoritma Lanjut" << endl;
            cout << "------------------------------------------------------------------" << endl;
            cout << "NIM       | Nilai Tugas  | Nilai UTS    | Nilai Uas  | Nilai Akhir" << endl;
            cout << "------------------------------------------------------------------" << endl;
            cout << nim[index] << "  | " << nilaiTugas[index] << "           | " << nilaiUTS[index] << "           | " << nilaiUAS[index] << "         | " << nilaiAkhir[index] << endl;
        }else{
            cout << "Data tidak ditemukan";
        }
        
    }else{
        cout << "Masukkan Angka 1/2";
        goto balik;
    }
    return 0;
}
