#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Three vectors for age, salary, and experience
    vector<int> age = {30, 25, 30, 25, 30};
    vector<int> salary = {50000, 40000, 55000, 60000, 50000};
    vector<int> experience = {5, 4, 6, 2, 8};

    int n = age.size();

    // Simple bubble sort logic
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Compare current and next employee
            bool shouldSwap = false;

            // Rule 1: Age ascending
            if (age[j] > age[j + 1]) {
                shouldSwap = true;
            }
            // Rule 2: If age same → Salary descending
            else if (age[j] == age[j + 1] && salary[j] < salary[j + 1]) {
                shouldSwap = true;
            }
            // Rule 3: If age & salary same → Experience descending
            else if (age[j] == age[j + 1] && salary[j] == salary[j + 1] && experience[j] < experience[j + 1]) {
                shouldSwap = true;
            }

            // If swap needed, swap all three values
            if (shouldSwap) {
                swap(age[j], age[j + 1]);
                swap(salary[j], salary[j + 1]);
                swap(experience[j], experience[j + 1]);
            }
        }
    }

    // Print the sorted employees
    cout << "Sorted Employees (Age Salary Experience):" << endl;
    for (int i = 0; i < n; i++) {
        cout << age[i] << " " << salary[i] << " " << experience[i] << endl;
    }

    return 0;
}
