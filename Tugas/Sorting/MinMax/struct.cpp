#include <iostream>
using namespace std;

struct Mahasiswa{
    int nilai , nim;
    string nama;
};

void test(struct Mahasiswa mhs);
int main(){
    Mahasiswa mhs2;
    mhs2.nama = "Indra";
    test(mhs2);
}

void test(struct Mahasiswa mhs){
    cout << mhs.nama;
}