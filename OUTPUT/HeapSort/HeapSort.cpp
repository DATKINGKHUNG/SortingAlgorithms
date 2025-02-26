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

void heapify(vector<double>& arr, int n, int i){

    // Initialize largest as root
    int largest = i;

    // left index = 2*i + 1
    int l = 2 * i + 1;

    // right index = 2*i + 2
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Main function to do heap sort
void heapSort(vector<double>& arr){
    int n = arr.size();

    // Build heap (rearrange vector)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {

        // Move current root to end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// A utility function to print vector of size n
void printArray(vector<int>& arr){
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << "\n";
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

        heapSort(arr);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);

        cout << "Test " << iTest << " " << duration.count() << " ms" << endl; 

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
