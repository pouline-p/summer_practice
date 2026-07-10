#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >>n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll ans{};
    sort(all(a));
    for (int k = n-1; k >= 2; k--){
        int i = 0, j = k - 1;
        while (i < j){
            if ((a[i] + a[j]) > a[k]){
                ans += (j - i);
                j--;
            } else {
                i++;
            }
        }
    }
    cout << ans;
}