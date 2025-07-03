#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <list> 

using namespace std;

int FunHash(int x) {
    return x % 13;
}

void Insert(int key, list<string> hashTable[], string name) {
    hashTable[key].push_back(name);
    cout << "Wstawiam: " << name << " pod indeks: " << key << endl;
}

int CountSumOfTheName(string name) {
    int sum = 0;
    for (int i = 0; i < name.length(); i++) {
        sum += name[i] - 64; // A == 65 in ASCII
    }
    return sum;
}

void Search(list<string> hashTable[]) {
    string name;
    cout << "Find the name: ";
    cin >> name;

    transform(name.begin(), name.end(), name.begin(), [](unsigned char c) {
        return toupper(c);
        });

    int sum = CountSumOfTheName(name);
    int hash = FunHash(sum);

    int place_in_index = 0;

    for (auto& item : hashTable[hash]) {
        if (item == name) {
            cout << name << " zostal znaleziony w indeksie " << hash << " place_in_index: " << place_in_index << endl;
            return;
        }
        else {
            place_in_index += 1;
        }
    }
    cout << name << " nie zostal znaleziony w indeksie " << hash << endl;
}

int main() {
    list<string> hashTable[13];

    // Insert 8 names into hash table
    for (int i = 0; i < 8; i++) {
        string name;
        cout << "Insert the name: ";
        cin >> name;

        transform(name.begin(), name.end(), name.begin(), [](unsigned char c) {
            return toupper(c);
            });

        int sum = CountSumOfTheName(name);
        int hash = FunHash(sum);
        cout << "Hash dla " << name << ": " << hash << endl;

        Insert(hash, hashTable, name);
    }

    // Display hash table contents
    for (int i = 0; i < 13; i++) {
        cout << i << ": ";
        for (const auto& item : hashTable[i]) {
            cout << item << " -> ";
        }
        cout << "null" << endl;
    }

    Search(hashTable);

    return 0;
}