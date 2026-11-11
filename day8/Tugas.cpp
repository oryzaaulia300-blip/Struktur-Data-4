#include<iostream>
#include<vector>
#include<string>
using namespace std;

const int TABLE_SIZE = 10;

// NIM dan Nama 
class HashTable {
    private:
        vector<pair<int, string>> table;
        vector<int> status; 

        int hash1 (int key) {
            return key % TABLE_SIZE;
        }

        int hash2 (int key) {
            return 7 - (key % 7);
        }

    public:
        HashTable() {
            table.resize(TABLE_SIZE);
            status.resize(TABLE_SIZE, 0);
        }

        void insert (int key, string value) {
            int index = hash1(key);
            int step = hash2(key);
            int initialIndex = index;

            int deletedIndex = -1;

            while (true) {
                if (status[index] == 1 && table[index].first == key) {
                    table[index].second = value;
                    return;
                }

                if (status[index] == 2 && deletedIndex == -1) {
                    deletedIndex = index; 
                }

                if (status[index] == 0) {
                    if(deletedIndex != -1) {
                        index = deletedIndex;
                    }

                    table[index] = make_pair(key, value);
                    status[index] = 1;
                    return;
                }

                index = (index + step) % TABLE_SIZE;

                if (index == initialIndex) {
                    break;
                }
            }

            if (deletedIndex != -1) {
                table[deletedIndex] = make_pair(key, value);
                status[deletedIndex] = 1;
            } else {
                cout << "Table penuh" << endl;
            }
        }

        void search(int key) {
            int index = hash1(key);
            int step = hash2(key);
            int initialIndex = index;

            while (status[index] != 0) { 
                if (status[index] == 1 && table[index].first == key) {
                    cout << "Data ditemukan : " << table[index].second << endl;
                    return;
                }

                index = (index + step) % TABLE_SIZE;

                if (index == initialIndex) {
                    break;
                }
            }

            cout << "Data tidak ditemukan" << endl;
        }

        void remove (int key) {
            int index = hash1(key);
            int step = hash2(key);
            int initialIndex = index;

            while (status[index] != 0) {
                if (status[index] == 1 && table[index].first == key) {
                    status[index] = 2; 
                    cout << "Data dengan NIM " << key << " berhasil dihapus" << endl;
                    return;
                }

                index = (index + step) % TABLE_SIZE;

                if (index == initialIndex) {
                    break;
                }
            }

            cout << "Data tidak ditemukan" << endl;
        }

        void display() {
            for (int i = 0; i < TABLE_SIZE; i++) {
                cout << i << " : ";
            
                if (status[i] == 1) {
                    cout << table[i].first << " - " << table[i].second;
                } else if (status[i] == 2) { 
                    cout << "DELETED";
                } else {
                    cout << "EMPTY";
                }

                cout << endl;
            }
        }
};

int main(){
    HashTable ht;

    cout << "Melakukan Insert Data " << endl;
    ht.insert(107, "Oryza");
    ht.insert(110, "Billy");  
    ht.insert(86, "Aca");
    ht.insert(128, "Dwai");

    cout << "Isi hash table awal:" << endl;
    ht.display();

    cout << "Mencari key 110: " << endl;
    ht.search(110);

    cout << "Menghapus key 128: " << endl;
    ht.remove(128);

    cout << "Isi hash table setelah seluruh operasi dilakukan" << endl;
    ht.display();

    return 0;
}