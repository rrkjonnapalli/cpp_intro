#include<bits/stdc++.h>

using namespace std;


class Graph {
    int V; //no of vertices
    list<int> *adj; // pointer to an containing adjacency lists

    public:
        Graph(int V); //constuctor
        
        void add_edge(int v, int w);

        void bfs(int s);
};

Graph::Graph(int v){
    this->V = v;
    adj = new list<int>[V];
}

void Graph::add_edge(int v, int w){
    adj[v].push_back(w);
}
void Graph::bfs(int s){
    bool *visited = new bool[V];
    memset(visited, false, sizeof visited);

    list<int> bfs_queue;

    visited[s] = true;

    bfs_queue.push_back(s);

    list<int>::iterator i;
    while(!bfs_queue.empty()){
        s = bfs_queue.front();
        cout << s << " ";
        bfs_queue.pop_front();

        for (i = adj[s].begin() ; i != adj[s].end(); i++){
            if (!visited[*i]){
                visited[*i] = true;
                bfs_queue.push_back(*i);
            }
        }
    }
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

    g.bfs(2);

    cout << "\n";

    return 0;
}