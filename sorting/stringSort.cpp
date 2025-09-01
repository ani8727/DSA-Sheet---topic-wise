#include <iostream>
#include <vector>
using namespace std;

// Insertion sort for characters
void insertionSort(vector<char>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        char key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    vector<char> uppercase;
    vector<char> lowercase;
    vector<char> spaces;

    // Separate characters
    for (char ch : input) {
        if (isupper(ch)) {
            uppercase.push_back(ch);
        } else if (islower(ch)) {
            lowercase.push_back(ch);
        } else if (isspace(ch)) {
            spaces.push_back(ch);
        }
    }

    // Sort each group using insertion sort
    insertionSort(uppercase);
    insertionSort(lowercase);
    insertionSort(spaces); // Optional, though spaces remain unchanged

    // Output: uppercase + space + lowercase
    cout << "Sorted output: ";
    for (char ch : uppercase) cout << ch;
    for (char ch : spaces) cout << ch;
    for (char ch : lowercase) cout << ch;
    cout << endl;

    return 0;
}
