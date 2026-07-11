#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX / 2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, s;
    cin >> n >> m >> s;

    vector<int> eu(m), ev(m);
    vector<ll> ew(m);
    for (int i = 0; i < m; i++) {
        cin >> eu[i] >> ev[i] >> ew[i];
    }

    vector<ll> dist(n + 1, INF);
    dist[s] = 0;

    for (int iter = 0; iter < n - 1; iter++) {
        bool changed = false;
        for (int i = 0; i < m; i++) {
            if (dist[eu[i]] < INF && dist[eu[i]] + ew[i] < dist[ev[i]]) {
                dist[ev[i]] = dist[eu[i]] + ew[i];
                changed = true;
            }
        }
        if (!changed) break;
    }

    
    vector<bool> affected(n + 1, false);
    for (int i = 0; i < m; i++) {
        if (dist[eu[i]] < INF && dist[eu[i]] + ew[i] < dist[ev[i]]) {
            affected[ev[i]] = true;
        }
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        adj[eu[i]].push_back(ev[i]);
    }

    queue<int> q;
    vector<bool> inQueue(n + 1, false);
    for (int v = 1; v <= n; v++) {
        if (affected[v]) {
            q.push(v);
            inQueue[v] = true;
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!affected[v]) {
                affected[v] = true;
                q.push(v);
            }
        }
    }

    bool flag = false;
    for (int v = 1; v <= n; v++) {
        if (affected[v] && dist[v] < INF) {
            flag = true;
            break;
        }
    }

    if (flag) {
        cout << "Negative cycle\n";
        return 0;
    }

    for (int v = 1; v <= n; v++) {
        if (dist[v] >= INF) {
            cout << "inf";
        } else {
            cout << dist[v];
        }
        cout << (v == n ? '\n' : ' ');
    }
}