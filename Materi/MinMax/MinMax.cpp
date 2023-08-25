#include <iostream>
using namespace std;

void MinMax (int A[],int i,int j, int &min , int &max);

int main(){
	int n , bil[100], min ,max;
	cout << "Banyak Data : ";
	cin >> n;
	cout << endl;
	
	for(int i=0;i<n;i++){
		cout << "Bilangan [" << i << "]: ";
		cin >> bil[i];
	}
	cout  << endl;
	
	MinMax(bil,0,n-1,min,max);
	
	cout << "Nilai Minimum  adalah " << min << endl;
	cout << "Nilai Maksimum adalah " << max << endl;
	
	system("pause");
	return 0;
}

void MinMax (int A[],int i,int j, int &min , int &max){
	int k , min1 , min2 , max1 , max2;
	
	if(i==j){
		min = A[i];
		max = A[i];
	}else{
		if(i == j-1){
			if(A[i] < A[j]){
				min = A[i];
				max = A[j];
			}
			else{	
				min = A[j];
				max = A[i];
			}
		}else{
			k = (i+j)/2;
			MinMax(A,i,k,min1,max1);
			MinMax(A,k+1,j,min2,max2);
			if(min1<min2){
				min = min1;
			}else{
				min = min2;
			}
			
			if(max1>max2){
				max = max1;
			} else{
				max = max2;
			}
		}
	}
}
	
