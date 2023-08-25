#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Algoritma yang saya Pilih adalah Quick Sort untuk sorting dan Binary Search untuk searching

// Quick Sort
int partition(vector<string> &zodiacs, int low, int high)
{
    string pivot = zodiacs[high]; // Choose the last element as the pivot
    int i = (low - 1);            // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        if (zodiacs[j] < pivot)
        {
            i++;
            swap(zodiacs[i], zodiacs[j]);
        }
    }
    swap(zodiacs[i + 1], zodiacs[high]);
    return (i + 1);
}

void quickSort(vector<string> &zodiacs, int low, int high)
{
    if (low < high)
    {
        // Partition the array
        int pi = partition(zodiacs, low, high);

        // Recursively sort the subarrays
        quickSort(zodiacs, low, pi - 1);
        quickSort(zodiacs, pi + 1, high);
    }
}

// Function to print the sorted array
void printArray(const vector<string> &zodiacs)
{
    for (const auto &zodiac : zodiacs)
    {
        cout << zodiac << ' ';
    }
    cout << endl;
}

// Binary Search
struct Zodiac
{
    string name;
    int startDay;
    int startMonth;
    int endDay;
    int endMonth;
};

int binarySearch(const vector<Zodiac> &zodiacs, int day, int month)
{
    int left = 0;
    int right = zodiacs.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        // Jika tanggal dan bulan berada dalam rentang zodiak saat ini
        if ((month == zodiacs[mid].startMonth && day >= zodiacs[mid].startDay) ||
            (month == zodiacs[mid].endMonth && day <= zodiacs[mid].endDay) ||
            (month > zodiacs[mid].startMonth && month < zodiacs[mid].endMonth))
        {
            return mid;
        }
        // Jika bulan lebih kecil, cari di sebelah kiri
        else if (month < zodiacs[mid].startMonth ||
                 (month == zodiacs[mid].startMonth && day < zodiacs[mid].startDay))
        {
            right = mid - 1;
        }
        // Jika bulan lebih besar, cari di sebelah kanan
        else
        {
            left = mid + 1;
        }
    }

    // Jika tidak ditemukan, kembalikan -1
    return -1;
}

int main()
{
    // Quick Sort
    vector<string> zodiacsQuick = {"Leo", "Aquarius", "Gemini", "Capricorn", "Aries", "Taurus", "Libra", "Cancer",
                                   "Virgo", "Scorpio", "Sagittarius", "Pisces"};

    int size = zodiacsQuick.size();
    quickSort(zodiacsQuick, 0, size - 1);

    cout << endl
         << "12 Zodiak Yang telah diurutkan : ";
    printArray(zodiacsQuick);
    cout << endl;

    // Binary Search
    vector<Zodiac> zodiacsBinary = {
        {"Aquarius", 20, 1, 18, 2},
        {"Pisces", 19, 2, 20, 3},
        {"Aries", 21, 3, 19, 4},
        {"Taurus", 20, 4, 20, 5},
        {"Gemini", 21, 5, 20, 6},
        {"Cancer", 21, 6, 22, 7},
        {"Leo", 23, 7, 22, 8},
        {"Virgo", 23, 8, 22, 9},
        {"Libra", 23, 9, 22, 10},
        {"Scorpio", 23, 10, 21, 11},
        {"Sagittarius", 22, 11, 21, 12},
        {"Capricorn", 22, 12, 19, 1}};
    int day, month;
    cout << "Cek Zodiak Kamu" << endl;
    cout << "Masukan Tanggal Lahir : ";
    cin >> day;
    cout << "Masukan Bulan Lahir   : ";
    cin >> month;

    // Lakukan pencarian biner
    int index = binarySearch(zodiacsBinary, day, month);

    if (index != -1)
    {
        cout << "Zodiak Kamu adalah " << zodiacsBinary[index].name << endl;
    }
    else
    {
        cout << "Maaf , Zodiak kamu tidak ditemukan" << endl;
    }
    return 0;
}
