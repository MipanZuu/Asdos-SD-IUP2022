#include <bits/stdc++.h>
using namespace std;

int v,e;
vector <int> graph[100005];
set <int> visited;
stack<int> solution;
bool cyclic = false;
bool path[100005];

void dfs(int s) {
    if (cyclic) 
        return;
    if(visited.find(s) != visited.end()) {
        return;
	}
    visited.insert(s);
    path[s] = true;
    for(int i = 0; i < graph[s].size(); i++) {
        int next = graph[s][i];
        if (path[next]==true){
            cyclic = true;
        }
        dfs(next);
        
    }
    solution.push(s);
    path[s] = false;
}

int main (){
    cin >> v >> e;
    for (int i=0;i<v;i++){
        path[i] = false;
    }
    for (int i = 0; i < e; i++) {
        int src,dest;
        cin >> src >> dest;
        graph[src].push_back(dest);
    }
    for (int i = 1; i <= v; i++) {
        dfs(i);
    }
    if (cyclic){
        cout << -1 << endl;
    }
    else {
        while(!solution.empty()){
        cout << solution.top();
        if (solution.size()!=1){
            cout << " ";
        }
        solution.pop();
        }
        cout << endl;
    }
}