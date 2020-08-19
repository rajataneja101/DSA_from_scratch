void addEdge(vector<vector<int>> &adj, int u, int v) 
{ 
    adj[u].push_back(v);
	adj[v].push_back(u); 
} 
void printGraph(vector<vector<int>> adj, int V) 
{ 
	for(int i=0;i<V;i++){
        cout<<i;
        for(auto s:adj[i]){
            cout<<"->"<<s;
        }
        cout<<endl;
	}
} 
int main() 
{ 
	int V = 5; 
	vector<vector<int>> adj(5);
	addEdge(adj, 0, 1); 
	addEdge(adj, 0, 4); 
	addEdge(adj, 1, 2); 
	addEdge(adj, 1, 3); 
	addEdge(adj, 1, 4); 
	addEdge(adj, 2, 3); 
	addEdge(adj, 3, 4); 
	printGraph(adj, V); 
	return 0; 
} 
