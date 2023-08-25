#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int bil,batas,prima[100],count;
	bool flag;
	
	cout << "Masukkan Bilangan : "; cin >> bil;
	
	if(bil == 0 || bil == 1){
		cout << "Bukan bilangan prima ataupun komposit" << endl;
	}else{
			if(bil == 2 || bil == 3){
				flag = true;
			}else{
				batas = sqrt(bil);
				count =0;
				
				for(int i=2;i<=batas;i++){
					flag = true;
					for(int j=2;j<i;j++){
						if(i%j==0){
							flag = false;
						}
					}
				
					if(flag==true){
						prima[count] = i;
						count++;
					}
				}
			
			
				cout << "Bilangan prima yang <= sqrt(" << bil << ") adalah :";
				for(int i=0;i<count;i++){
					cout << prima[i] << " ";
				}
				
				cout << endl;
				
				flag = true;
				for(int i=0;i<count;i++){
					if(bil%prima[i] == 0){
						flag = false;
						break;
					}
				}
			}
				
		if(flag == true){
			cout << bil << " Merupakan Bilangan Prima" << endl;
		}else{
			cout << "Bilangan Komposit" << endl;
		}
	}
	
	return 0;
}