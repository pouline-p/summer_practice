#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        ll n;
        cin >> n;
        
        if (n == 0) {
            printf("10\n");
            continue;
        }
        if (n == 1) {
            printf("1\n");
            continue;
        }
        
        vector<int> digits;
        for (int d = 9; d >= 2; d--) {
            while (n % d == 0) {
                digits.push_back(d);
                n /= d;
            }
        }
        
        if (n != 1) {
            printf("-1\n");
        } else {
            sort(all(digits));
            string res;
            for (int d : digits) res += char('0' + d);
            printf("%s\n", res.c_str());
        }
    }
}