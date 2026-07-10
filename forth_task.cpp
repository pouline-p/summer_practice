#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    ll bestSum = LLONG_MIN;
    int toBuy = 1, toSell = 1;

    ll curSum = 0;
    int curStart = 1;

    for (int i = 1; i <= n; i++) {
        curSum += a[i];

        if (curSum > bestSum) {
            bestSum = curSum;
            toBuy = curStart;
            toSell = i;
        }

        if (curSum < 0) {
            curSum = 0;
            curStart = i + 1;
        }
    }

    if (bestSum <= 0) {
        cout << -1 << ' ' << -1 << '\n';
    } else {
        cout << toBuy << ' ' << (toSell + 1) << '\n';
    }
}