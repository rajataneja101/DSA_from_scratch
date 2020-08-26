#define INF 9999
void Solve(int dist[][4])  
{  
    int V=4;
    cout<<"The following matrix shows the shortest distances"
            " between every pair of vertices \n";  
    for (int i = 0; i < V; i++)  
    {  
        for (int j = 0; j < V; j++)  
        {  
            if (dist[i][j] == INF)  
                cout<<"INF"<<"     ";  
            else
                cout<<dist[i][j]<<"     ";  
        }  
        cout<<endl;  
    }  
} 

void floydWarshall(int graph[][4]){
    int dist[4][4], i, j, k, V=4;
    for (i = 0; i < V; i++)  
        for (j = 0; j < V; j++)  
            dist[i][j] = graph[i][j];  
    for (k = 0; k < V; k++)  
    {  
        for (i = 0; i < V; i++)  
        {  
            for (j = 0; j < V; j++)  
            {  
                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
            }  
        }  
    }  
  
    Solve(dist);  
}  
  


int main() {
    int graph[4][4]={
        {0, 5, INF, 10},  
        {INF, 0, 3, INF},  
        {INF, INF, 0, 1},  
        {INF, INF, INF, 0}  
    };
    floydWarshall(graph);  
    
}