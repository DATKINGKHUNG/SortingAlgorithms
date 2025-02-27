#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define MAX 10000005
const int N = 1e6 + 5;
const int INF = 1e9;
const int mod = 1e9 + 7;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
    vector<string> testnames;
    for (int numtest = 1; numtest <= 10; numtest++) {
        testnames.push_back(to_string(numtest));
    }

    for (int iTest = 1; iTest <= 10; iTest++) {
        const string output = testnames[iTest - 1] + ".inp";
        ofstream fileout("Test" + testnames[iTest - 1] + ".inp");

        int n = 1e6;
        fileout << n << "\n";

        vector<double> arr;

        uniform_real_distribution<double> make_num(-1e6, 1e6);

        for (int i = 1; i <= n; i++)    
            arr.push_back(make_num(rd));

        if (iTest == 1) sort(arr.begin(), arr.end());
        else if (iTest == 2) sort(arr.begin(), arr.end(), greater<double>());

        for (double x : arr) fileout << x << " ";
        fileout.close();
    }
    return 0;
}