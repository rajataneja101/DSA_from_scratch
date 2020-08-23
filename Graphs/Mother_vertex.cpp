void addEdge(vector<vector<int>> &graph, int src, int dest){
    graph[src].push_back(dest);
}

void printGraph(vector<vector<int>> &graph) 
{ 
    for(int i=0;i<graph.size();i++){
        cout<<i;
        for(auto s:graph[i]){
            cout<<"->"<<s;
        }
        cout<<endl;
    }
} 

void DFS(vector<vector<int>> &graph, int V, vector<int> &visited){
    visited[V]=true;
    for(int i=0;i<graph[V].size(); i++){
        if(!visited[graph[V][i]]){
            DFS(graph, graph[V][i], visited);
        }
    }
}

void findMother(vector<vector<int>> &graph){
    int final_v=0;
    vector<int> visited(7, false);
    for(int i=0;i<visited.size();i++){
        if(visited[i]==false){
            DFS(graph, i, visited);
            final_v=i;
        }
    }
    fill(visited.begin(), visited.end(), false);
    DFS(graph, final_v, visited);
    for(int i=0;i<visited.size();i++){
        if(visited[i]==false){
            cout<<-1;
            return;
        }
    }
    cout<<final_v;
}


int main() {
    vector<vector<int>> graph(7);
    addEdge(graph, 0, 1); 
    addEdge(graph, 0, 2); 
    addEdge(graph, 1, 3);
    addEdge(graph, 4, 1); 
    addEdge(graph, 6, 4); 
    addEdge(graph, 5, 6);
    addEdge(graph, 5, 2);
    addEdge(graph, 6, 0);
    // printGraph(graph);
    findMother(graph);
}