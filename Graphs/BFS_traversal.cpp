void addEdge(vector<vector<int>> &adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void BFS(int start, vector<vector<int>> &adj){
    vector<bool> visited(4, false);
    deque<int> BFSQueue;
    BFSQueue.push_back(start);
    visited[start]=true;
    while(!BFSQueue.empty()){
        int temp=BFSQueue.front();
        BFSQueue.pop_front();
        cout<<temp<<" ";
        for(int i=0;i<adj[temp].size();i++){
            if(!visited[adj[temp][i]]){
                visited[adj[temp][i]]=true;
                BFSQueue.push_back(adj[temp][i]);
            }
        }
    }
}

void printGraph(vector<vector<int>> adj){
    for(int i=0;i<adj.size();i++){
        cout<<i;
        for(auto g:adj[i]){
            cout<<"->"<<g;
        }
        cout<<endl;
    }
}
int main() {
    vector<vector<int>> adj(4);
    addEdge(adj, 0, 1);
	addEdge(adj, 0, 2);  
	addEdge(adj, 1, 2); 
	addEdge(adj, 2, 0);  
	addEdge(adj, 3, 3); 
	addEdge(adj, 2, 3); 
	printGraph(adj); 
    cout<<"BFS traversal is "<<endl;
    BFS(2, adj);
    return 0;
}