#include<iostream>
#include<list>
#include<iterator>
using namespace std;
class Graph
{
    public:
    int V;
    list<int> *adj;
    Graph(int V);
    add(int v,int w);
    Dfs(int v);
    DfsCheck(int v,bool visited[]);

};
Graph::Graph(int V)
{
    this->V=V;
    adj=new list<int>[V];
}
Graph::add(int v,int w)
{
    adj[v].push_back(w);
}
Graph::Dfs(int v)
{
    bool *visited=new bool[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }
    DfsCheck(v,visited);
}
Graph::DfsCheck(int v,bool visited[])
{
    visited[v]=true;
    cout<<v<<"\t";
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DfsCheck(*i, visited);
}


int main()
{
    int v,w,a,r;
    cout<<"how many edges? :";
    cin>>a;
    Graph g(a);

    cout<<"Enter vertices and nodes  (" <<a<<")\n";

    for(int i=0;i<2*a;i++)
    {
        if(v>a||w>a)
        {
            break;
        }
        else
        {
        cin>>v>>w;
        g.add(v,w);
        }
    }
    cout<<"Enter root : ";
    cin>>r;
    g.Dfs(r);




}
