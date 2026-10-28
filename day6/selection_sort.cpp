#include <iostream>
using namespace std;

int main(){
    int data[] = {5, 2, 4, 1, 3};
    // 1, 2, 4, 5, 3
    int n = 5;

    for (int i = 0; i <n-1;i++){
        int minIndex = i; //patokan 5 (indeks 0)

        for (int j= i+1; j<n;j++){ // j -3
                if(data[j]<data[minIndex]){ //1<2?
                minIndex = j; //indeks 3
            }
        }
        swap (data[i],data[minIndex]);
    }

    cout << "Hasil Selection Sort : ";
    for (int i = 0;i<n;i++){
        cout<<data[i]<<" ";
    }

    return 0;
}