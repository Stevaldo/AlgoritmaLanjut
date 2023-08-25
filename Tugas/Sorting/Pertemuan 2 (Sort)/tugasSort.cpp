#include <iostream>
using namespace std;

int main(){
	/*Nama : Stevaldo Claudio
	  NIM  : 32220105 		 */
	string temp;
	int tempInt , n;
	string item[] = {"Botol","Gunting","Buku","Spidol","Map"};
	int harga[] = {35000,8000,5000,28000,5500},
		terjual[] = {5,10,2,8,3};
	
	// Cetak Data
	cout << "\n\nData Sebelum diurutkan" << endl;
	cout << "----------------------------------------" << endl;
	cout << "Nama Item\tHarga(Rp)\tTerjual" << endl;
	n = 5;
	
	for(int i=0;i<n;i++){
		cout << item[i] << "\t\t" << harga[i] << "\t\t" << terjual[i] << "\t\t" << endl;
	}
	
	cout << endl;
	
	// Proses Sorting (Ascending Bubble Sort)
	for(int iteration =1;iteration<n;iteration++){
		for(int index=0;index<n-iteration;index++){
			
			if(item[index] > item[index+1]){ /* untuk Ascending menggunakan > dari , sedangkan Descending menggunakan < */
				temp = item[index];
				item[index] = item[index+1];
				item[index+1] = temp;

				tempInt = harga[index];
				harga[index] = harga[index+1];
				harga[index+1] = tempInt;

				tempInt = terjual[index];
				terjual[index] = terjual[index+1];
				terjual[index+1] = tempInt;
			}
			
		}
	}
	
	// Cetak Data
	cout << "\n\nData Setelah diurutkan (Bubble Sort Ascending)" << endl;
	cout << "----------------------------------------" << endl;
	cout << "Nama Item\tHarga(Rp)\tTerjual" << endl;

	for(int i=0;i<n;i++){
		cout << item[i] << "\t\t" << harga[i] << "\t\t" << terjual[i] << "\t\t" << endl;
	}
	cout << endl;


	// Descending Insertion Sort
	int firstOutOfOrder , location , tempTerjual , tempHarga;
	string tempItem;
	//Proses Sorting
	for(firstOutOfOrder=1;firstOutOfOrder<n;firstOutOfOrder++){
		tempTerjual  = terjual[firstOutOfOrder];
		tempHarga  = harga[firstOutOfOrder];
		tempItem  = item[firstOutOfOrder];
		location = firstOutOfOrder;
		/* untuk Ascending menggunakan > dari , sedangkan Descending menggunakan < gunakan pada bagian terjual[location-1] < / > tempTerjual */
		while(terjual[location-1] < tempTerjual && location >= 1){ 
			terjual[location] = terjual[location-1];	
			harga[location] = harga[location-1];
			item[location] = item[location-1];
			location--;
		}
		terjual[location] = tempTerjual;
		harga[location] = tempHarga;
		item[location] = tempItem;
	}

	// Cetak Data
	cout << "\n\nData Paling Laris (Insertion Sort Descending)" << endl;
	cout << "----------------------------------------" << endl;
	cout << "Nama Item\tHarga(Rp)\tTerjual" << endl;

	for(int i=0;i<n;i++){
		cout << item[i] << "\t\t" << harga[i] << "\t\t" << terjual[i] << "\t\t" << endl;
	}
	cout << endl;
	
	system("pause");
	return 0;
}