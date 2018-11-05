#include<bits/stdc++.h>
#define sz(a) (int)(a.size())
using namespace std;
struct StronglyConnectedComponents
{
    int n;
    int totalComponents;
    vector <vector <int>> adj, components;
    vector <int> idx, componentOf, st, low;
    vector <bool> inStack;

    StronglyConnectedComponents (int n): n(n), adj(n) {}

    void AddEdge (int a, int b)
    {
        adj[a].push_back(b);
    }

    int DFS (int v, int index)
    {
        idx[v] = index;
        low[v] = index;
        index += 1;
        st.push_back(v);
        inStack[v] = true;

        for (auto& w : adj[v])
        {
            if (idx[w] == -1)
            {
                index = DFS(w, index);
                low[v] = min(low[v], low[w]);
            }
            else if (inStack[w])
            {
                low[v] = min(low[v], low[w]);
            }
        }

        if (low[v] == idx[v])
        {
            int w;
            components.push_back(vector <int>());
            do
            {
                w = st.back();
                st.pop_back();
                inStack[w] = false;
                componentOf[w] = totalComponents;
                components[totalComponents].push_back(w);
            }
            while (w != v);
            totalComponents++;
        }
        return index;
    }

    void BuildSCC ()
    {
        totalComponents = 0;
        idx = vector <int>(n, -1), low = vector <int>(n), componentOf = vector <int>(n);
        inStack = vector <bool>(n, false);
        st.clear();

        for (int i = 0; i < n; i++)
        {
            if (idx[i] == -1)
            {
                DFS(i, 0);
            }
        }
    }
};

int main()
{
    int n,m;
    int t=1;
    while(scanf("%d%d",&n,&m)==2)
    {
        if(n==0 and m==0)
            break;

        StronglyConnectedComponents T(n);

        for(int i=1; i<=m; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            T.AddEdge(a-1,b-1);
            T.AddEdge(b-1,a-1);
        }
        T.BuildSCC();

        printf("Case %d: %d\n",t,T.components.size());
        t++;
    }

return 0;
}
/**
1
7 8
1 2
2 3
3 1
3 4
4 5
5 6
6 7
7 5
**/
