

// check that do a path exist between two vertices.

#include<iostream>
#include<vector>
using namespace std;



bool checkPath(vector<vector<int>>& graph,int src,int dest,vector<bool>& visited)
{
    if(src == dest)
    {
        return true;
    }
    visited[src]=true;
    for(int i=0;i<graph[src].size();i++)
    {
        if(visited[graph[src][i]]==false)
        {
            bool x=checkPath(graph,graph[src][i],dest,visited);
            if(x)
            {
                return x;
            }
        }
    }
    visited[src]=false;
    return false;
}



int main()
{
    // Undirected Graph Starting from vertice 0
    int v,e;
    cout<<"enter the number of vertices and number of edges\n";
    cin>>v>>e;
    vector<vector<int>>graph(v);
    for(int i=0;i<e;i++)
    {
        cout<<"enter the edge\n";
        int m,n;
        cin>>m>>n;
        graph[m].push_back(n);
        graph[n].push_back(m);
    }
    cout<<"enter the source and destination you want to check for\n";
    int source,destination;
    cin>>source>>destination;
    vector<bool>visited(v,false);
    bool ans=checkPath(graph,source,destination,visited);
    if(ans)
    {
        cout<<"Exists\n";
    }
    else
    {
        cout<<"does not exists\n";
    }
    return 0;
}