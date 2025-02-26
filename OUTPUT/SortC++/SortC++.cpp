#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

#define ll long long
#define int ll

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int iTest = 1; iTest <= 10; iTest++){

        string inputFile = "Test" + to_string(iTest) + ".inp";
        string outputFile = "Test" + to_string(iTest) + ".out";

        ifstream filein(inputFile);
        ofstream fileout(outputFile);

        int n;
        filein >> n;
        
        vector<double> arr(n);
        for (int i = 0; i < n; i++){
            filein >> arr[i];
        }

        //hàm tính thời gian chạy
        auto start = high_resolution_clock::now();

        sort(arr.begin(), arr.end());

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);

        cout << "Test " << iTest << " " << duration.count() << " ms\n"; 

        fileout << n << "\n";

        fileout << duration.count() << " ms\n"; 
        
        for(double x : arr){
            fileout << x << " ";
        }

        filein.close();
        fileout.close();
    }

    return 0;
}
