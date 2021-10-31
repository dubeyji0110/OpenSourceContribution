
// Check that a graph is bipartite or not

#include<iostream>
#include<vector>
using namespace std;

/*
1 -> Green
0 -> Blue
-1 -> Uncoloured
*/

bool isBipartite(vector<vector<int>>& graph,vector<int>& color,int start,int c)
{
    

    for(int i=0;i<graph[start].size();i++)
    {
        if(color[graph[start][i]]==-1)
        {
            if(c==0)
            {
                color[start]=1;
            }
            else
            {
                color[start]=0;
            }
            bool x= isBipartite(graph,color,graph[start][i],~c);
            if(x==false)
            {
                return false;
            }
        }
        else
        {
            if((color[graph[start][i]])==(~c))
            {
                return false;
            }
        }
    }
    return true;
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
    vector<int>color(v,-1);
    int c=0;
    bool ans=isBipartite(graph,color,0,c);
    if(ans)
    {
        cout<<"the graph is bipartite\n";
    }
    else
    {
        cout<<"the graph is not bipartite\n";
    }
    return 0;
}