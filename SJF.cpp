#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    // Burst Time Pair List
    pair<int, int> BT[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter the burst time for P" << i << ": ";
        BT[i].first = i;
        cin >> BT[i].second;
    }
    
    // Sorting BT
    for (int i = 0; i < n - 1; i++) {
        int j = i + 1;
        while (j > 0 && (BT[j].second < BT[j - 1].second)) {
            // swapping
            pair<int, int> tmp;
            tmp = BT[j];
            BT[j] = BT[j - 1];
            BT[j - 1] = tmp;

            j--;
        }
    }

    cout << "\n\n-------------------------------------------------------------------------------" << endl;
    cout << "---------------------------------USING SJF------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;

    pair<int, int> WT[n + 1];
    int x = 0;
    for (int i = 0; i < n; i++) {
        WT[i].first = BT[i].first;
        WT[i].second = x;
        x += BT[i].second;
    }
    WT[n].second = x;


    int total_WT = 0;
    for (int i = 0; i < n; i++) {
        total_WT += WT[i].second;
    }

    // Gann Chart
    cout << "\n-----GANN CHART-----\n\n";
    for (int i = 0; i <= n; i++) {
        if (i > 1) cout << "\t";
        cout << WT[i].second << "\t";
    }
    cout << "\n-------------------------------------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << "P" << WT[i].first << "\t|\t";
    }
    cout << "\n-------------------------------------------------------------------------\n\n";

    int TAT[n];
    int total_TAT = 0;
    for (int i = 0; i < n; i++) {
        TAT[BT[i].first] = BT[i].second + WT[i].second;
        total_TAT += TAT[BT[i].first];
    }

    for (auto &&i : TAT) {
        cout << i << " ";
    }
    cout << "\n";

    // EVALUATED TABLE

    cout << "\n---------------------Evaluation Table---------------------------\n" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << "Pid\t|\tBurst Time\t|\tWaiting Time\t|\tTurnaround Time" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < n; i++) {
        cout << "P" << BT[i].first << "\t|\t     " << BT[i].second
             << "    \t|\t     " << WT[i].second << "     \t|\t     " << TAT[i]
             << "    \t|" << endl;
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
