void addEdge(vector<set<int, greater<int>>> &graph, int src, int dest){
    graph[src].insert(dest);
    graph[dest].insert(src);
}

void printGraph(vector<set<int, greater<int>>> &graph) 
{ 
    for(int i=0;i<graph.size();i++){
        cout<<i;
        for(auto s:graph[i]){
            cout<<"->"<<s;
        }
        cout<<endl;
    }
} 

void searchEdge(vector<set<int, greater<int>>> &graph, int src, int dest){
    auto itr=graph[src].find(dest);
    if(itr==graph[src].end()){
        cout<<"There's no relation between the src "<<src<<" and "<<dest<<endl;
    }
    else{
        cout<<"Edge from "<< src<< " to " << dest << " found."<< endl; 
    }
}

int main() {
    vector<set<int, greater<int>>> graph(5);
    addEdge(graph, 0, 1); 
    addEdge(graph, 0, 4); 
    addEdge(graph, 1, 2); 
    addEdge(graph, 1, 3); 
    addEdge(graph, 1, 4); 
    addEdge(graph, 2, 3); 
    addEdge(graph, 3, 4); 
    printGraph(graph);
    searchEdge(graph, 2, 1);
    searchEdge(graph, 0, 3);
}