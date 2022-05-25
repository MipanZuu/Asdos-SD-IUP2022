#include <bits/stdc++.h>
using namespace std;

vector<int> adj[64];

void makeArena(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(i + 2 >= 0 && i + 2 <= 7 ){
                if(j + 1 >= 0 && j + 1 <= 7){
                    adj[i * 8 + j].push_back((i + 2) * 8 + j + 1);
                }
                if(j - 1 >= 0 && j - 1 <= 7){
                    adj[i * 8 + j].push_back((i + 2) * 8 + j - 1);
                }
            }
            if(i + 1 >= 0 && i + 1 <= 7 ){
                if(j + 2 >= 0 && j + 2 <= 7){
                    adj[i * 8 + j].push_back((i + 1) * 8 + j + 2);
                }
                if(j - 2 >= 0 && j - 2 <= 7){
                    adj[i * 8 + j].push_back((i + 1) * 8 + j - 2);
                }
            }
            if(i - 2 >= 0 && i - 2 <= 7 ){
                if(j + 1 >= 0 && j + 1 <= 7){
                    adj[i * 8 + j].push_back((i - 2) * 8 + j + 1);
                }
                if(j - 1 >= 0 && j - 1 <= 7){
                    adj[i * 8 + j].push_back((i - 2) * 8 + j - 1);
                }
            }
            if(i - 1 >= 0 && i - 1 <= 7 ){
                if(j + 2 >= 0 && j + 2 <= 7){
                    adj[i * 8 + j].push_back((i - 1) * 8 + j + 2);
                }
                if(j - 2 >= 0 && j - 2 <= 7){
                    adj[i * 8 + j].push_back((i - 1) * 8 + j - 2);
                }
            }
        }
    }
}

int BFS(int s,int dest) 
{
    int source = s;
    set <int> visited;
    list<int> queue; 
    map <int,int> path;
    visited.insert(s);
    queue.push_back(s); 
    while(!queue.empty()) 
    {
        s = queue.front();
        if(s == dest){
            int temp = dest;
            int ans = 0;
            while (temp != source){
                ans++;
                temp = path[temp];
            }
            return ans;
        }
        queue.pop_front(); 
        for (unsigned int i = 0; i < adj[s].size(); i++) 
        { 
            if(!visited.count(adj[s][i])) {
                visited.insert(adj[s][i]);
        	    queue.push_back(adj[s][i]); 
                path[adj[s][i]] = s;
            }
		} 
    }
    return -1;
} 


int main(){
    makeArena();
    int testcase;
    cin >> testcase;
    for(int i = 0; i < testcase; i++){
        char a,b;
        int a1,a2,b1,b2;
        cin >> a >> a2 >> b >> b2;
        a1 = a - 'a';
        b1 = b - 'a';
        cout << BFS((a1) * 8 + a2 -1 ,b1 * 8 + b2 - 1) << endl;
    }
}