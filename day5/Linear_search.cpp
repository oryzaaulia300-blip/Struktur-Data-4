#include <iostream>
using namespace std;

//membuat fungsi
int LinearSearch (int data[], int n,int target){
    for (int i = 0; i < n; i++){
        if (data[i] == target){
            return i;
        }
    }
    return -1;
}
int main(){
    int data[] = {70,14,28,21,35,49,42,56,63,70};
    int n = 10;
    int target = 49;

    int hasil = LinearSearch(data,n,target);

    if (hasil != -1){
        cout << "Data ditemukan pada index : " << hasil << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }

    return 0;
}