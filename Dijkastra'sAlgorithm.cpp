#include <iostream>
#include <climits>
using namespace std;

int getMinDistance(int* distance,int V,bool *visited){
  int min = -1;
  int minDistance = INT_MAX;
  for(int i=0;i<V;i++){ 
    if(visited[i] == false && distance[i] < minDistance){
      min = i;
      minDistance = distance[i];
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
  
  int* distance = new int[V];
  for(int i=0;i<V;i++){
    distance[i] = INT_MAX;
  }
  distance[0] = 0;
  
  for(int i=0;i<V-1;i++){
    int currentVertex = getMinDistance(distance,V, visited);
    visited[currentVertex] = true;
    for(int i=0;i<V;i++){
      if( currentVertex == i){
        continue;
      }
      if(edges[currentVertex][i]!=0 && visited[i]==false){
        
        int new_distance = edges[currentVertex][i] + distance[currentVertex];
       if( distance[i] > new_distance ){
         distance[i] = new_distance;
       }
      }
    }
  }

  for(int i=0;i<V;i++){
      cout << i << " " << distance[i] << endl;
  }
  
  return 0;
}
