#include<bits/stdc++.h>
using namespace std;
int component;
vector<int> ComponentVector[50009];
int n,m;
vector<int> Edge[50009];
vector<int> revEdge[50009];
int color[50009];
int visited[50009];
stack<int> st;

void DFS(int u)
{
    color[u] = 1;

    for(int i=0; i<(int) Edge[u].size(); i++)
    {
        if(color[Edge[u][i]]==0)
        {
            DFS(Edge[u][i]);
        }
    }
    st.push(u);
}
void DFS2(int u,int component)
{
    visited[u] = 1;
    ComponentVector[component].push_back(u);
    for(int i=0; i<(int) revEdge[u].size(); i++)
    {
        if(visited[revEdge[u][i]]==0)
        {
            DFS2(revEdge[u][i],component);
        }
    }
}


void findSCC()
{
    for(int i=1; i<=n; i++)
    {
        color[i] = 0;
        visited[i] = 0;
        ComponentVector[i].clear();
    }
    while(!st.empty())
    {
        st.pop();
    }
    /** Every nodes are sorted in topsort style Using DFS() **/
    for(int i=1; i<=n; i++)
    {
        if(color[i]==0)
        {
            DFS(i);
        }
    }

    /** Now building SCC using DFS2() on ReverseEdge **/

    while(!st.empty())
    {
        int u = st.top();
        st.pop();
        if(visited[u]==0)
        {
            component++;
            DFS2(u,component);

        }
    }


}

int main()
{
    int c = 1;
    while(scanf("%d%d",&n,&m))
    {
        if(n==0 and m==0)
            break;
            component =0;
        for(int i=1; i<=m; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            Edge[a].push_back(b);
            Edge[b].push_back(a);
            revEdge[b].push_back(a);
            revEdge[a].push_back(b);
        }
        findSCC();
        printf("Case %d: ",c);
        cout<<component<<endl;
        c++;
        for(int i=0; i<=n; i++)
        {
            ComponentVector[i].clear();
            visited[i] = 0;
            color[i] = 0;
            Edge[i].clear();
            revEdge[i].clear();
        }
    }
    return 0;
}

