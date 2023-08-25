#include <iostream>
using namespace std;



float wirus(int menit, float wadah){
	if (wadah != 0.0625){
		menit--;
		wadah = wadah/2;
		return wirus(menit, wadah);
	}else{
		return menit;
	}
	
}

int main(){
	int menit = 120;
	float wadah = 1;
	cout << wirus(menit, wadah);
	return 0;
}