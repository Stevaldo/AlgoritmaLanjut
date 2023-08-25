#include <iostream>
using namespace std;

void minmax(int a[], int i, int j, int &min, int &max);

int main(){
	int n, bil[100],min, max,i,j,jawaban;
	do{
	cout<<"Masukan Banyak Data \t: ";cin>>n;
	cout<<"\n";
	for (int i=0;i<n;i++){
		cout<<"Bilangan ["<<i<<"] \t: ";cin>>bil[i];
	}cout<<endl;
	
		do{
		cout<<"Terdapat Array [0] sampai Array ["<<n-1<<"] \n";
		cout<<"\n";
		cout<<"Lakukan pencarian dari Array ke \t: ";cin>>i;
		cout<<"Sampai Array ke \t\t\t: ";cin>>j;
		minmax(bil, i, j, min, max);
		
		cout<<"Nilai Minimum adalah \t: "<<min<<endl;
		cout<<"Nilai Maksimum adalah \t: "<<max<<endl;
		
		cout<<"Apakah kamu ingin mengulang pencarian?\n1. Dengan Data baru\n2. Dengan Data yang sama\n3. Exit\nPilih \t:";
		cin>>jawaban;
		}while(jawaban == 2);
		
	}while(jawaban == 1);
	
	cout<<"Terimakasih sudah menggunakan program ini!\n";
	system("pause");
	return 0;
}

void minmax(int a[], int i, int j, int &min, int &max){
	int mid, min1, min2, max1, max2;
	
	if(i == j){//Jika data cuman ada 1 (i(0) == j-1 (1-1))
		min = a[i];
		max = a[i];
	}else{//jika data ada lebih dari 1
		if(i == j-1){//jika data = 2, bandingkan bil[0] dengan bil[1]
			if(a[i]<a[j]){//jika bil[0] < bil[1], maka min = bil[0] dan max = bil[1]
				min = a[i];
				max = a[j];
			}else{//jika bil[1] < bil[0], maka min = bil[1] dan max = bil[0]
				min = a[j];
				max = a[i];
			}
		}else{
			mid = (j+i)/2;//bagi dua data
			minmax(a,i,mid,min1,max1);//memanggil minmax dari jangkauan i-k (low -> mid)
			minmax(a,mid+1,j,min2,max2);//memanggil minmax dari jangkauan k+1 - j (mid+1 -> high)
			//membandingkan min dan max yang lebih kecil
			if(min1<min2){
				min = min1;	
			}else{
				min = min2;
			}
			
			if(max1>max2){
				max = max1;
			}else{
				max = max2;
			}
		}
	}	
}
