#include <iostream>
using namespace std;

int BinarySearch(int data[], int n, int target){
    int low = 0;
    int high = n-1;

   while (low <= high) {
        int mid = low + (high - low) / 2; // menghitung indeks middle = 3

        if (data[mid] == target) {
            return mid; // 3
        } else if (target < data[mid]) {
            high = mid - 1; // 3-1 = 2 -> high
        } else {
            low = mid + 1; //low = 3+1 = 4
        }
    }
    return -1;
}

int main(){
    int data[]= {10,20,30,40,50,60,70,80,90,100};
    int n = 10;
    int target;

    cout << "Masukkan data yang ingin dicari : ";
    cin >> target;

    int hasil = BinarySearch(data,n,target);
    if (hasil != -1){
        cout << "Data ditemukan pada indeks : " << hasil << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }
    return 0;
}   
