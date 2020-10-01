#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

vector<int> getPathBFS(int** graph, int n, int s, int e, int* visited, map<int,int> m){
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    m[s] = -1;
    while(q.empty()==false){
        int c = q.front();
        q.pop();
        if(c==e) break;
        for(int i=0;i<n;i++){
            if(graph[c][i]==1 && !visited[i]){
                m[i] = c;
                visited[i] = 1;
                q.push(i);
            }
        }
    }
    vector<int> v{};
    if(m.find(e)==m.end()){
        return v;
    }
    int temp = e;
    while(temp!=-1){
        v.push_back(temp);
        temp = m[temp];
    }
    return v;
}

int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to Print the output yourself
	 
  */
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
  map<int,int> m;
  int sv,ev;
  cin >> sv >> ev;
  vector<int> v = getPathBFS(edges,V,sv,ev,visited,m);
  for(int i=0;i<v.size();i++){
    cout << v[i] << " ";
  }
  return 0;
}
