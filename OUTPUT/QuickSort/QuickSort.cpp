#include <bits/stdc++.h>

using namespace std;
using namespace chrono;


#define ll long long
#define int ll
#define MAX 10000005
const int N = 1e6 + 5;
const int INF = 1e9;
const int mod = 1e9 + 7;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int partition(vector<double>& arr, int low, int high) {
    
    double random = low + rand() % (high - low + 1); // chon pivot ngau nhien
    swap(arr[random], arr[high]); //dua pivot ve cuoi
    
    double pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i + 1], arr[high]);  //dua pivot ve dung vi tri
    return i + 1;
}

void quickSort(vector<double>& arr, int low, int high) {
    if (low < high) {
      
        int pivot_index = partition(arr, low, high);

        quickSort(arr, low, pivot_index - 1);
        quickSort(arr, pivot_index + 1, high);
    }
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int iTest = 1; iTest <= 10; iTest++){

        string inputFile = "Test" + to_string(iTest) + ".inp";
        string outputFile = "Test" + to_string(iTest) + ".out";

        ifstream filein(inputFile);
        ofstream fileout(outputFile);

        // if (!filein) {
        //     cerr << "Lỗi: Không thể mở file " << inputFile << endl;
        //     return 1;
        // }
        // if (!fileout) {
        //     cerr << "Lỗi: Không thể mở file " << outputFile << endl;
        //     return 1;
        // }

        int n;
        filein >> n;
        
        vector<double> arr(n);
        for (int i = 0; i < n; i++){
            filein >> arr[i];
        }

        // // Kiểm tra nếu dữ liệu đọc từ file là toàn số 0
        // cout << "Dữ liệu từ file " << inputFile << ": ";
        // for (double x : arr) cout << x << " ";
        // cout << endl;

        
        //hàm tính thời gian chạy
        auto start = high_resolution_clock::now();

        quickSort(arr, 0, n - 1);

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
