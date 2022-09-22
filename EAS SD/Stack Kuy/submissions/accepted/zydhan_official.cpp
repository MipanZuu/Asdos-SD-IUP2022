#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
typedef pair<ll, long double> pld;

vector<pld> dijkstra(int n, vector<pair<int, ll>> adjList[], int src) {
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    vector<pld> shortestPath(n, make_pair(INT64_MAX, 0));
    shortestPath[src] = make_pair(0LL, 1.0);
    pq.push(make_pair(0, src));
    while(!pq.empty()) {
        ll distance = pq.top().first;
        int currPos = pq.top().second;
        pq.pop();
        for(unsigned i=0; i<adjList[currPos].size(); i++) {
            int dest = adjList[currPos][i].first;
            ll newDist = adjList[currPos][i].second + distance;
            if(newDist < shortestPath[dest].first) {
                pq.push(make_pair(newDist, dest));
                shortestPath[dest].first = newDist;
                shortestPath[dest].second = shortestPath[currPos].second;
            } else if(newDist == shortestPath[dest].first)
                shortestPath[dest].second += shortestPath[currPos].second;
        }
    }
    return shortestPath;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, a, b;
    cin>>n>>m>>a>>b;
    a--, b--;
    vector<pair<int, ll>> adjList[n];
    for(int i=0; i<m; i++) {
        int u, v, w;
        cin>>u>>v>>w;
        adjList[--u].push_back(make_pair(--v, w));
        adjList[v].push_back(make_pair(u, w));
    }
    vector<pld> shortestPathFromStart = dijkstra(n, adjList, a), shortestPathFromDest = dijkstra(n, adjList, b);
    for(int i=0; i<n; i++) {
        long double countShortestPath = shortestPathFromStart[i].second * shortestPathFromDest[i].second;
        if(shortestPathFromStart[i].first <= shortestPathFromStart[b].first - shortestPathFromDest[i].first)
            cout<<setprecision(9)<<fixed<<(countShortestPath * 2 / shortestPathFromStart[b].second)<<"\n";
        else cout<<setprecision(9)<<fixed<<((long double)0)<<"\n";
    }
}