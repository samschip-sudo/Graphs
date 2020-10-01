#include <iostream>
#include <queue>
using namespace std;

//O(V^2) TIME COMPLEXITY
void bfs(int** edges, int n, int sv, int* visited){
  queue<int> q;
  q.push(sv);
  visited[sv]=1;
  while(q.size()!=0){
    int currentVertex = q.front();
    q.pop();
    cout << currentVertex << " ";
    for(int i=0;i<n;i++){
      if(visited[i]==0&&edges[currentVertex][i]==1){
        q.push(i);
        visited[i]=1;
      }
    }
  }
}

int main() {
  int V, E;
  cin >> V >> E;
  int** edges = new int*[V];
  for(int i=0;i<V;i++){
    edges[i]=new int[V];
    for(int j=0;j<V;j++){
      edges[i][j]=0;
    }
  }
  for(int i=0;i<E;i++){
    int s,e;
    cin >> s >> e;
    edges[s][e]=1;
    edges[e][s]=1;
  }
  int* visited = new int[V];
  for(int i=0;i<V;i++){
    visited[i]=0;
  }
  bfs(edges,V,0,visited);
  return 0;
}

