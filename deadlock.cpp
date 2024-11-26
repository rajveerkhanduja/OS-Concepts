#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the "need" matrix
void calculateNeedMatrix(vector<vector<int>>& need, const vector<vector<int>>& max, const vector<vector<int>>& alloc, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
}

// Function to check if a process can be satisfied with available resources
bool canProcessRun(const vector<int>& need, const vector<int>& avail, int m) {
    for (int j = 0; j < m; j++) {
        if (need[j] > avail[j]) {
            return false;
        }
    }
    return true;
}

// Banker's algorithm implementation
bool bankersAlgorithm(int n, int m, const vector<vector<int>>& alloc, const vector<vector<int>>& max, vector<int>& avail) {
    vector<vector<int>> need(n, vector<int>(m));
    vector<int> f(n, 0); // Process flags, initially all unmarked
    vector<int> safeSequence(n); // Stores the safe sequence
    int index = 0;

    // Calculate the need matrix
    calculateNeedMatrix(need, max, alloc, n, m);

    // Iterate to find the safe sequence
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (!f[i] && canProcessRun(need[i], avail, m)) {
                // Process can safely execute
                for (int j = 0; j < m; j++) {
                    avail[j] += alloc[i][j];
                }
                safeSequence[index++] = i;
                f[i] = 1; // Mark the process as completed
            }
        }
    }

    // Check if all processes are marked
    for (int i = 0; i < n; i++) {
        if (!f[i]) {
            cout << "The system is not in a safe state." << endl;
            return false;
        }
    }

    // If safe sequence exists, print it
    cout << "The system is in a safe state.\nSafe Sequence: ";
    for (int i = 0; i < n - 1; i++) {
        cout << "P" << safeSequence[i] << " -> ";
    }
    cout << "P" << safeSequence[n - 1] << endl;

    return true;
}

int main() {
    int n = 5; // Number of processes
    int m = 3; // Number of resources

    // Allocation matrix
    vector<vector<int>> alloc = {
        {0, 1, 0}, // P0
        {2, 0, 0}, // P1
        {3, 0, 2}, // P2
        {2, 1, 1}, // P3
        {0, 0, 2}  // P4
    };

    // Maximum demand matrix
    vector<vector<int>> max = {
        {7, 5, 3}, // P0
        {3, 2, 2}, // P1
        {9, 0, 2}, // P2
        {2, 2, 2}, // P3
        {4, 3, 3}  // P4
    };

    // Available resources
    vector<int> avail = {3, 3, 2};

    // Run the Banker's Algorithm
    bankersAlgorithm(n, m, alloc, max, avail);

    return 0;
}