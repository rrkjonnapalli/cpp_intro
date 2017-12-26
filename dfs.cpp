#include<bits/stdc++.h>

using namespace std;

class Graph{
    int V;
    list<int> *adj;
    void dfs_util(int v, bool visited[]);

    public:
        Graph(int v);
        void add_edge(int v, int w);
        void dfs(int v);
};

Graph::Graph(int v){
    this->V = v;
    adj = new list<int>[v];
}

void Graph::add_edge(int v, int w){
    adj[v].push_back(w);
}

void Graph::dfs_util(int v, bool visited[]){
    visited[v] = true;
    cout << v << " ";
    
    list<int>::iterator _i;

    for (_i = adj[v].begin() ; _i != adj[v].end(); _i++){
        if(!visited[*_i]){
            dfs_util(*_i, visited);
        }
    }
}

void Graph::dfs(int v){
    bool *visited = new bool[v];

    memset(visited, false, sizeof visited);
    
    dfs_util(v, visited);
}

int main(){

    std::ios_base::sync_with_stdio(false);

    Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);
 
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.dfs(2);

    cout << "\n";
    return 0;
}