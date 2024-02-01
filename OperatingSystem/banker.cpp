#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, i, j, k;

    cout << "Enter the number of processes: ";
    cin >> n;

    cout << "Enter the number of resources: ";
    cin >> m;

    // Allocate vectors for matrices
    vector<vector<int>> alloc(n, vector<int>(m));
    vector<vector<int>> max(n, vector<int>(m));
    vector<int> avail(m);

    cout << "Enter the Allocation Matrix:" << endl;
    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j)
            cin >> alloc[i][j];

    cout << "Enter the Max Matrix:" << endl;
    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j)
            cin >> max[i][j];

    cout << "Enter the Available Resources:" << endl;
    for (j = 0; j < m; ++j)
        cin >> avail[j];

    vector<int> f(n, 0);
    vector<int> ans(n, 0);
    int ind = 0;

    vector<vector<int>> need(n, vector<int>(m));
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    int y = 0;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {

                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }

    int flag = 1;

    // To check if the sequence is safe or not
    for (int i = 0; i < n; i++) {
        if (f[i] == 0) {
            flag = 0;
            cout << "The given sequence is not safe";
            break;
        }
    }

    if (flag == 1) {
        cout << "Following is the SAFE Sequence" << endl;
        for (i = 0; i < n - 1; i++)
            cout << " P" << ans[i] << " ->";
        cout << " P" << ans[n - 1] << endl; // The missing line
    }
    return 0;
}