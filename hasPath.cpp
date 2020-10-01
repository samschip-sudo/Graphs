#include <iostream>
#include <queue>
using namespace std;

bool hasPath(int** graph, int n, bool* visited, int s, int t){
    if(s==t) return true;
    visited[s] = true;
    for(int i=0;i<n;i++){
        if(graph[s][i]==1 && !visited[i]){
            if(hasPath(graph,n,visited,i,t)){
                return true;
            }
        }
    }
    return false;
}

bool hasPath(int** graph, int n, int s, int t){
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){ visited[i] = false; }
    return hasPath(graph,n,visited,s,t);
}

int main() {
    int n, e;
    cin >> n >> e;
    int** graph = new int*[n];
    for(int i=0;i<n;i++){
        graph[i] = new int[n];
        for(int j=0;j<n;j++){
            graph[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int x,y;
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    int s, t;
    cin >> s >> t;
    if(hasPath(graph,n,s,t)){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
}
