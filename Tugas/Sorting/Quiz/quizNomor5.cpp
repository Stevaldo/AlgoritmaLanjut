#include <iostream>
using namespace std;

int findMinute(double menitPenuh, double kapasitasTarget , double kapasitas) {
	if(kapasitas == kapasitasTarget){
		return menitPenuh;
	}else{
		menitPenuh--;
		findMinute(menitPenuh,kapasitasTarget,(kapasitas*2));
	}
}

int main() {
	double menitPenuh;
    double kapasitasTarget;
	double kapasitas = 1;
	cout << "Berapa Menit sampai Air Penuh = "; cin >> menitPenuh;
	cout << "Target kapasitas 1/"; cin >> kapasitasTarget;
    int minute = findMinute(menitPenuh, kapasitasTarget , kapasitas);
    cout << "Wadah akan 1/"<< kapasitasTarget << " penuh saat menit ke " << minute << endl;

    return 0;
}