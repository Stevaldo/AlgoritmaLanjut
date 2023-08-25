#include <iostream>
#include <conio.h>
using namespace std;

struct logic{
	int arr[3][3];
};
logic x , y;

int tryx;
void print(int angka = 0 , char var = 'A');

void isiKolomX(int pilihan){
	if(pilihan == 1 && y.arr[0][0] != 1){
		x.arr[0][0] = 1;
	}else if(pilihan == 2 && y.arr[0][1] != 1){
		x.arr[0][1] = 1;
	}else if(pilihan == 3 && y.arr[0][2] != 1){
		x.arr[0][2] = 1;
	}else if(pilihan == 4 && y.arr[1][0] != 1){
		x.arr[1][0] = 1;
	}else if(pilihan == 5 && y.arr[1][1] != 1){
		x.arr[1][1] = 1;
	}else if(pilihan == 6 && y.arr[1][2] != 1){
		x.arr[1][2] = 1;
	}else if(pilihan == 7 && y.arr[2][0] != 1){
		x.arr[2][0] = 1;
	}else if(pilihan == 8 && y.arr[2][1] != 1){
		x.arr[2][1] = 1;
	}else if(pilihan == 9 && y.arr[2][2] != 1){
		x.arr[2][2] = 1;
	}
	
	if(
		(x.arr[0][0] == 1 && x.arr[0][1] == 1 && x.arr[0][2] == 1 )||
		(x.arr[1][0] == 1 && x.arr[1][1] == 1 && x.arr[1][2] == 1 )||
		(x.arr[2][0] == 1 && x.arr[2][1] == 1 && x.arr[2][2] == 1 )||
		(x.arr[0][0] == 1 && x.arr[1][0] == 1 && x.arr[2][0] == 1 )||
		(x.arr[0][1] == 1 && x.arr[1][1] == 1 && x.arr[2][1] == 1 )||
		(x.arr[0][2] == 1 && x.arr[1][2] == 1 && x.arr[2][2] == 1 )||
		(x.arr[0][0] == 1 && x.arr[1][1] == 1 && x.arr[2][2] == 1 )||
		(x.arr[0][2] == 1 && x.arr[1][1] == 1 && x.arr[2][0] == 1 )
	){
		system("cls");
		print(0,'a');
		cout << "Player 1 Menang" << endl;
		exit(0);
	}
	
	if(tryx == 9){
		system("cls");
		print(0,'a');
		cout << "Skor Seri T_T" << endl;
		exit(0);
	}
}

void isiKolomY(int pilihan){
	if(pilihan == 1 && x.arr[0][0] != 1){
		y.arr[0][0] = 1;
	}else if(pilihan == 2 && x.arr[0][1] != 1){
		y.arr[0][1] = 1;
	}else if(pilihan == 3 && x.arr[0][2] != 1){
		y.arr[0][2] = 1;
	}else if(pilihan == 4 && x.arr[1][0] != 1){
		y.arr[1][0] = 1;
	}else if(pilihan == 5 && x.arr[1][1] != 1){
		y.arr[1][1] = 1;
	}else if(pilihan == 6 && x.arr[1][2] != 1){
		y.arr[1][2] = 1;
	}else if(pilihan == 7 && x.arr[2][0] != 1){
		y.arr[2][0] = 1;
	}else if(pilihan == 8 && x.arr[2][1] != 1){
		y.arr[2][1] = 1;
	}else if(pilihan == 9 && x.arr[2][2] != 1){
		y.arr[2][2] = 1;
	}
	
	if(
		(y.arr[0][0] == 1 && y.arr[0][1] == 1 && y.arr[0][2] == 1 )||
		(y.arr[1][0] == 1 && y.arr[1][1] == 1 && y.arr[1][2] == 1 )||
		(y.arr[2][0] == 1 && y.arr[2][1] == 1 && y.arr[2][2] == 1 )||
		(y.arr[0][0] == 1 && y.arr[1][0] == 1 && y.arr[2][0] == 1 )||
		(y.arr[0][1] == 1 && y.arr[1][1] == 1 && y.arr[2][1] == 1 )||
		(y.arr[0][2] == 1 && y.arr[1][2] == 1 && y.arr[2][2] == 1 )||
		(y.arr[0][0] == 1 && y.arr[1][1] == 1 && y.arr[2][2] == 1 )||
		(y.arr[0][2] == 1 && y.arr[1][1] == 1 && y.arr[2][0] == 1 )
	){
		system("cls");
		print(0,'a');
		cout << "Player 2 Menang" << endl;
		exit(0);
	}
	
	if(tryx == 9){
		system("cls");
		print(0,'a');
		cout << "Skor Seri T_T" << endl;
		exit(0);
	}
	
}

char a='1',b='2',c='3',d='4',e='5',f='6',g='7',h='8',i='9';
void print(int angka , char var){
		if(angka == 1){
			a=var;
		}else if(angka == 2){
			b=var;
		}else if(angka == 3){
			c=var;
		}else if(angka == 4){
			d=var;
		}else if(angka == 5){
			e=var;
		}else if(angka == 6){
			f=var;
		}else if(angka == 7){
			g=var;
		}else if(angka == 8){
			h=var;
		}else if(angka == 9){
			i=var;
		}
		
		cout << "-------------" << endl;
		cout << "| "<<a<<" | "<<b<<" | "<<c<<" |" << endl;
		cout << "-------------" << endl;
		cout << "| "<<d<<" | "<<e<<" | "<<f<<" |" << endl;
		cout << "-------------" << endl;
		cout << "| "<<g<<" | "<<h<<" | "<<i<<" |" << endl;
		cout << "-------------" << endl;	
	

}
int main(){
	int pilihan;
		back:
		system("cls");
		cout << "Player 1 :";
		cout << endl;
		print(0,'a');
		cout << "Input : ";
		cin >> pilihan;
		isiKolomX(pilihan);
		system("cls");
		cout << "Player 1 :" << endl;
		print(pilihan,'X');
		cout << "Output...";getch();
		tryx++;
		
		system("cls");
		cout << "Player 2 :";
		cout << endl;
		print(0,'a');
		cout << "Input : ";
		cin >> pilihan;
		isiKolomY(pilihan);
		system("cls");
		cout << "Player 2 :" << endl;
		print(pilihan,'Y');
		cout << "Output...";getch();
		tryx++;
		goto back;
	
}