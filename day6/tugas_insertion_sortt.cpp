#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah kata: ";
    cin >> n;

    string data[100];
    cout << "Masukkan " << n << " kata: ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    cout << "\nProses Pergeseran:\n";

    for (int i = 1; i < n; i++) {
        string key = data[i];
        int j = i - 1;

        cout << "Langkah " << i << " (key: " << key << ") menjadi -> ";

        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            cout << "geser " << data[j] << " jadi -> ";
            j--;
        }

        data[j + 1] = key;

        cout << "Sort sementara: ";
        for (int k = 0; k < n; k++) {
            cout << data[k] << " ";
        }
        cout << endl;
    }

    cout << "\nHasil Insertion Sort : ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}