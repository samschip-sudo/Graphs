#include <iostream>
#include <algorithm>
using namespace std;

class Edge{
  
 public:
  int start;
  int end;
  int weight;
};

bool ValueCmp(Edge a, Edge b)
{
    return a.weight < b.weight;
}

int getParent(int* parent,int v){
  if(parent[v]==v){
    return v;
  }
  return getParent(parent, parent[v]);
}

int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
  
  Edge* edges = new Edge[E];
  Edge* MST = new Edge[V-1];
  
  for(int i=0;i<E;i++){
    int start;
    int end;
    int weight;
    cin >> start >> end >> weight;
    edges[i].start = start;
    edges[i].end = end;
    edges[i].weight = weight;
  }
  
  sort(edges, edges + E, ValueCmp);
  
  int* parent = new int[V];
  for(int i=0;i<V;i++){
    parent[i] = i;
  }
  
  int count = 0;
  int k=0;
  while(count < V-1){
   Edge edge = edges[k];
   int parent1 = getParent(parent,edge.start);
   int parent2 = getParent(parent,edge.end);
    if(parent1!=parent2){
      MST[count] = edge;
      count++;
      parent[parent1] = parent2;
    }
    k++;
  }
  
  for(int i=0;i<V-1;i++){
    if(MST[i].start < MST[i].end){
      cout << MST[i].start << " " << MST[i].end << " " << MST[i].weight << endl;
    }else{
      cout << MST[i].end << " " << MST[i].start << " " << MST[i].weight << endl;
    }
    
  }
  return 0;
}
