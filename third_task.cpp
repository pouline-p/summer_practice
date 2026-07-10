#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
const ull MOD = 1e9 + 7;
using pll = array<int, 2>;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<ull>> dp(n+1, vector<ull>(m+1));
    vector<vector<ull>> blocked(n+1, vector<ull>(m+1));
    string x;
    int a,b;
    for (int  i{}; i < k; i++){
        cin >> a >> b;
        blocked[a][b] = 1;
    }
    dp[0][0] = 1;
    for (int i{}; i <= n; i++){
        for (int j{}; j <= m; j++){
            if (blocked[i][j] == 0){
                if ((i-1) >= 0){
                    dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
                } 
                if ((j-1) >= 0){
                    dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
                }
            }
        }
    }

    cout << dp[n][m] % MOD;
}