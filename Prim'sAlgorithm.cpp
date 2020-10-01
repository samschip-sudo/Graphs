#include <iostream>
#include <climits>
using namespace std;

int getMinWeight(int* weight,int V,bool *visited){
  int min = -1;
  int minWeight = INT_MAX;
  for(int i=0;i<V;i++){ 
    if(visited[i] == false && weight[i] < minWeight){
      min = i;
      minWeight = weight[i];
    }
  }
  return min;
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
    int weight;
    cin >> gi >> gj >> weight;
    edges[gi][gj] = weight;
    edges[gj][gi] = weight;
  }
  
  bool* visited = new bool[V];
  for(int i=0;i<V;i++){
    visited[i] = false;
  }
  
  int* parent = new int[V];
  parent[0] = -1;
  
  int* weight = new int[V];
  for(int i=0;i<V;i++){
    weight[i] = INT_MAX;
  }
  weight[0] = 0;
  
  for(int i=0;i<V-1;i++){
    int currentVertex = getMinWeight(weight,V, visited);
    visited[currentVertex] = true;
    for(int i=0;i<V;i++){
      if( currentVertex == i){
        continue;
      }
      if(edges[currentVertex][i]!=0 && visited[i]==false){
       if( weight[i] > edges[currentVertex][i] ){
         weight[i] = edges[currentVertex][i];
         parent[i] = currentVertex;
       }
      }
    }
  }

  for(int i=1;i<V;i++){
    if(i < parent[i]){
      cout << i << " " << parent[i] << " " << weight[i] << endl;
    }else{
      cout << parent[i] << " " << i << " " << weight[i] << endl;
    }
    
  }
  
  return 0;
}
