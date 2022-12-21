#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    // Burst Time List
    int BT[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter the burst time for P" << i << ": ";
        cin >> BT[i];
    }

    cout << "\n\n-------------------------------------------------------------------------------" << endl;
    cout << "---------------------------------USING FCFS------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;

    // Wating Time List
    int WT[n + 1];
    int x = 0;
    for (int i = 0; i < n; i++) {
        WT[i] = x;
        x += BT[i];
    }
    WT[n] = x;

    int total_WT = 0;
    for (int i = 0; i < n; i++) {
        total_WT += WT[i];
    }

    // Gann Chart
    cout << "\n-----GANN CHART-----\n\n";
    for (int i = 0; i <= n; i++) {
        if (i > 1) cout << "\t";
        cout << WT[i] << "\t";
    }
    cout << "\n-------------------------------------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << "P" << i << "\t|\t";
    }
    cout <<  "\n-------------------------------------------------------------------------\n\n";

    // Turnaround Time Table

    int TAT[n];
    int total_TAT = 0;
    for (int i = 0; i < n; i++) {
        TAT[i] = WT[i + 1];
        total_TAT += TAT[i];
    }


    // EVALUATED TABLE

    cout << "\n---------------------Evaluation Table---------------------------\n" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << "Pid\t|\tBurst Time\t|\tWaiting Time\t|\tTurnaround Time" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < n; i++) {
        cout << "P" << i << "\t|\t     " << BT[i] << "    \t|\t     " << WT[i]
             << "     \t|\t     " << TAT[i] << "    \t|" << endl;
    }

    // Average WT, TAT
    float avg_WT = float(total_WT) / n;
    float avg_TAT = float(total_TAT) / n;
    cout << "\n\n-----------------Averages-----------------\n" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Average Waiting Time: " << avg_WT << endl;
    cout << "Average Turnaorund Time: " << avg_TAT << endl;
    cout << "------------------------------------------------" << endl;

    return 0;
}
