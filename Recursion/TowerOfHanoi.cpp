// Tower of Hanoi
#include <iostream>
using namespace std;

// Function to solve Tower of Hanoi
int towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        cout << "Move disk 1 from rod " << from << " to rod " << to << endl;
        return 1;
    }

    // Move n-1 disks from source to auxiliary
    int count = towerOfHanoi(n - 1, from, aux, to);

    // Move the nth disk from source to destination
    cout << "Move disk " << n << " from rod " << from << " to rod " << to << endl;
    count++;

    // Move n-1 disks from auxiliary to destination
    count += towerOfHanoi(n - 1, aux, to, from);

    return count;
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    int totalMoves = towerOfHanoi(n, 'A', 'C', 'B');

    cout << "\nTotal moves required: " << totalMoves << endl;

    return 0;
}
