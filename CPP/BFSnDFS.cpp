#include <bits/stdc++.h>
using namespace std;

int shortestDist[10];
vector <pair<int,int>> graph[10];

void dijkstra(int s, int n) {
    priority_queue <pair<int,int>, vector <pair<int,int>>, greater <pair<int,int>> > p_que;
    set <int> visited;
    memset(shortestDist, -1, sizeof(shortestDist));
    shortestDist[s] = 0;
    p_que.push({0, s});
    while(!p_que.empty()) {
        pair<int,int> now = p_que.top();
        p_que.pop();
        if(visited.find(now.second) != visited.end()) continue;
        visited.insert(now.second);
        for(int i = 0; i < graph[now.second].size(); i++) {
            int next = graph[now.second][i].second;
            int cost = graph[now.second][i].first;
			cout <<  now.second << "->" << graph[now.second][i].second << " Total weight to node : " << now.first << " Cost : " << cost << endl;
            if(now.first + cost < shortestDist[next] || shortestDist[next] == -1) {
                shortestDist[next] = now.first + cost;
                p_que.push({shortestDist[next], next});
            }
        }
        for(int i = 0; i < 6; i++) {
            cout << "shortestDist " << i <<" : " << shortestDist[i] << endl;
        }
    }
    for(int i = 0; i < n; i++) {
        cout << "Shortest path from " << s << " to " << i << " : " << shortestDist[i] << endl;
    }
    return;
}

void bfs(int s) {
	cout << "BFS" << endl;
	queue <pair<int,int>> que;
	set <int> visited;
	que.push({0, s});
	while(!que.empty()) {
        pair<int,int> now = que.front();
        que.pop();
        if(visited.find(now.second) != visited.end()) {
        	//cout << "KETEMU " << now.second << endl;
        	continue;	
		}
        visited.insert(now.second);
        printf("%d -> ",now.second);
        for(int i = 0; i < graph[now.second].size(); i++) {
            int next = graph[now.second][i].second;
            que.push(make_pair(0, next));
        }
    }
}


void dfs(int s) {
	cout << "\nDFS" << endl;
	stack <pair<int,int>> stek;
	set <int> visited;
	stek.push({0, s});
	while(!stek.empty()) {
        pair<int,int> now = stek.top();
        stek.pop();
        if(visited.find(now.second) != visited.end()) {
        	//cout << "KETEMU " << now.second << endl;
        	continue;	
		}
        visited.insert(now.second);
        printf("%d -> ",now.second);
        for(int i = 0; i < graph[now.second].size(); i++) {
            int next = graph[now.second][i].second;
            stek.push(make_pair(0, next));
        }
    }
}


int main () {
	graph[1].push_back(make_pair(9,5));
	graph[1].push_back(make_pair(2,3));
	graph[1].push_back(make_pair(1,2));
	graph[2].push_back(make_pair(9,3));
	graph[2].push_back(make_pair(6,4));
	graph[2].push_back(make_pair(10,4));
	graph[3].push_back(make_pair(2,1));
	graph[3].push_back(make_pair(5,5));
	graph[3].push_back(make_pair(4,4));
	graph[3].push_back(make_pair(9,2));
	graph[4].push_back(make_pair(6,2));
	graph[4].push_back(make_pair(4,3));
	graph[5].push_back(make_pair(9,1));
	graph[5].push_back(make_pair(5,3));
	//dijkstra(5,6);
	bfs(5);
	dfs(5);
}
