#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> adj(n + 1);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n + 1, -1);
    vector<int> queue_(n + 1);
    int qhead = 0, qtail = 0;

    dist[k] = 0;
    queue_[qtail++] = k;

    while(qhead < qtail){
        int u = queue_[qhead++];
        for(int v : adj[u]){
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                queue_[qtail++] = v;
            }
        }
    }

    string out;
    for(int i = 1; i <= n; i++){
        out += to_string(dist[i]);
        out += (i < n) ? ' ' : '\n';
    }
    fwrite(out.data(), 1, out.size(), stdout);

}