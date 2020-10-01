#include <queue>
#include <vector>
#include <algorithm> 
#include <iostream>
using namespace std;

void bfs(int** edges, int V, int sv, vector<int>* dfs_vector, bool* visited){
  queue<int> pendingVertices;
  pendingVertices.push(sv);
  visited[sv] = true;
  while(!pendingVertices.empty()){
    int currentVertex = pendingVertices.front();
    pendingVertices.pop();
    dfs_vector -> push_back(currentVertex);
    for(int i=0;i<V;i++){
      if(i==currentVertex){
        continue;
      }
      if( edges[currentVertex][i]==1 && visited[i]==false){
        pendingVertices.push(i);
        visited[i] = true;
      } 
    }
  }
}

int main() {
    int V, E;
    cin >> V >> E;
  int **edges = new int*[V];
  for(int i=0;i<V;i++){
    edges[i] = new int[V];
    for(int j=0;j<V;j++){
      edges[i][j] = 0;
    }
  }
  for(int i=0;i<E;i++){
    int gi;
    int gj;
    cin >> gi >> gj;
    edges[gi][gj] = 1;
    edges[gj][gi] = 1;
  }
  
  bool* visited  = new bool[V];
  for(int i=0;i<V;i++){
    visited[i] = false;
  }
  
  for(int i=0;i<V;i++){
    if(visited[i]==false){
      vector<int>* smallAns = new vector<int>();
      bfs(edges,V,i,smallAns,visited);
      sort(smallAns->begin(), smallAns->end());
      for(int j=0;j<smallAns->size();j++){
        cout << smallAns->at(j) << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
