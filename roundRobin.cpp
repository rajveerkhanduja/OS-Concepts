#include <iostream>
#include <vector>
#include <iomanip> // For precision formatting

using namespace std;

struct Process {
    int id;          // Process ID
    int arrivalTime; // Arrival Time
    int burstTime;   // Burst Time
    int remainTime;  // Remaining Time
    int waitingTime; // Waiting Time
};

int main() {
    int n, timeQuantum, totalExecutionTime = 0, remainProcess;
    float totalWaitingTime = 0;

    cout << "Enter the number of processes: ";
    cin >> n;
    remainProcess = n;

    vector<Process> processes(n);

    // Input arrival times
    cout << "Enter Arrival Times:\n";
    for (int i = 0; i < n; ++i) {
        processes[i].id = i + 1;
        cout << "For P[" << processes[i].id << "]: ";
        cin >> processes[i].arrivalTime;
    }

    // Input burst times
    cout << "\nEnter Burst Times:\n";
    for (int i = 0; i < n; ++i) {
        cout << "For P[" << processes[i].id << "]: ";
        cin >> processes[i].burstTime;
        processes[i].remainTime = processes[i].burstTime; // Initially, remaining time = burst time
        processes[i].waitingTime = 0;                     // Waiting time starts at 0
    }

    // Input time quantum
    cout << "\nEnter Time Quantum: ";
    cin >> timeQuantum;

    cout << "\nProcess Execution Order:\n";

    int i = 0;
    while (remainProcess != 0) {
        if (processes[i].remainTime > 0) {
            // Process can execute within the time quantum
            if (processes[i].remainTime <= timeQuantum) {
                totalExecutionTime += processes[i].remainTime;
                processes[i].waitingTime = totalExecutionTime - processes[i].arrivalTime - processes[i].burstTime;
                processes[i].remainTime = 0;
                cout << "P[" << processes[i].id << "] | Waiting Time: " << processes[i].waitingTime << "\n";
                totalWaitingTime += processes[i].waitingTime;
                remainProcess--;
            }
            // Process cannot finish in one quantum
            else {
                processes[i].remainTime -= timeQuantum;
                totalExecutionTime += timeQuantum;
            }
        }

        // Move to the next process in a round-robin manner
        if (i == n - 1)
            i = 0;
        else if (processes[i + 1].arrivalTime <= totalExecutionTime)
            i++;
        else
            i = 0;
    }

    // Calculate and display average waiting time
    float avgWaitingTime = totalWaitingTime / n;
    cout << fixed << setprecision(2);
    cout << "\nThe Average Waiting Time: " << avgWaitingTime << "\n";

    return 0;
}