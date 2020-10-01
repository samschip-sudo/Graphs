#include <iostream>
#include <vector>
using namespace std;

vector<int> getPathDFS(int** graph, int n, int s, int e, int* visited){
  vector<int> v{};  
  if(s==e){
    v.push_back(e);
    return v;
  }
  visited[s]=1;
  for(int i=0;i<n;i++){
    if(!visited[i] && graph[s][i]==1){
      vector<int> smallAns = getPathDFS(graph,n,i,e,visited);
      if(smallAns.size()!=0){
        smallAns.push_back(s);
        return smallAns;
      }
    }
  }
  return v;
}

int main()
{
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
  int* visited = new int[V];
  for(int i=0;i<V;i++){
    visited[i] = 0;
  }
  int sv,ev;
  cin >> sv >> ev;
  vector<int> v = getPathDFS(edges,V,sv,ev,visited);
  //cout << v << endl;
  for(int i=0;i<v.size();i++){
    cout << v.at(i) << " ";
  }
  return 0;
}
