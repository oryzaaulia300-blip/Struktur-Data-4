#include<iostream>
using namespace std;

struct Node{
    char data;
    Node* next;
};

int main(){
    system("cls");
    Node* top = nullptr;
    string kata;

    cout << "Masukkan huruf: ";
    cin >> kata;

    for (int i = 0; i < kata.length(); i++){
        Node* newNode = new Node();
        newNode ->data =kata[i];
        newNode ->next = top;
        top = newNode; 
    }

    cout << "setelah terbalik: ";
    while (top != nullptr){
        Node* hapus = top;
        cout << top -> data;
        top = top -> next;
        delete hapus;
    }
    cout << endl;
    
}
    