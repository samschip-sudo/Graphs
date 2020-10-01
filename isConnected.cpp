#include <iostream>
using namespace std;

void dfs(int** graph, int n, int startNode, bool* visited){
    visited[startNode] = true;
    for(int i=0;i<n;i++){
        if(graph[startNode][i]==1 && visited[i]!=true){
            dfs(graph,n,i,visited);
        }
    }
}

bool dfs(int** graph, int n, int startNode){
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){ visited[i] = false; }
    dfs(graph,n,0,visited);
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            return false;
        }
    }
    return true;
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
    if(dfs(graph,n,0)){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
}
