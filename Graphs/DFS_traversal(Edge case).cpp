// Edge case when node is not connected 

void addEdge(int u, int v, vector<vector<int>> &graph){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void printGraph(vector<vector<int>> graph){
    for(int i=0;i<graph.size();i++){
        cout<<i;
        for(auto g:graph[i]){
            cout<<"->"<<g;
        }
        cout<<endl;
    }
}

void DFSUtil(int v, vector<vector<int>> graph, vector<bool> &visited){
    visited[v]=true;
    cout<<v<<endl;
    for(int i=0;i<graph[v].size();i++){
        if(!visited[graph[v][i]]){
            DFSUtil(graph[v][i], graph, visited);
        }
    }
}

void DFS(int v, vector<vector<int>> graph, vector<bool> &visited){
    DFSUtil(v, graph, visited);
    for(int i=0;i<visited.size();i++){
         if(!visited[graph[v][i]]){
            DFSUtil(i, graph, visited);
        }
    }
}

int main() {
    vector<vector<int>> graph(4);
    addEdge(0, 1, graph); 
    addEdge(0, 2, graph); 
    addEdge(1, 2, graph); 
    addEdge(2, 0, graph); 
    addEdge(2, 3, graph); 
    addEdge(3, 3, graph); 
    vector<bool> visited(4, false);
    cout<<"The DFS is "<<endl;
    DFS(2, graph, visited);
    printGraph(graph);
}