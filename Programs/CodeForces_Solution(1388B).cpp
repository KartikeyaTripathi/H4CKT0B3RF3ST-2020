#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define mod 1000000007
int min(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}
bool compare(int a, int b) {
    return a > b;
}
int32_t main() {
    fio;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int no_nine = ((n * 4) - n) / 4;
        for (int i = 0; i < no_nine; i++) {
            cout << "9";
        }
        int no_zero = n - no_nine;
        for (int i = 0; i < no_zero; i++) {
            cout << "8";
        }
        cout << endl;
    }
}
