#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
private:
    vector<int> size, parent;

public:
    DisjointSet(int n)
    {
        size.resize(n + 1, 1);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            size[i] = 1;
            parent[i] = i;
        }
    }

    int findUParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }

        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int up_u = findUParent(u);
        int up_v = findUParent(v);

        if (up_u == up_v)
            return;

        if (size[up_u] < size[up_v])
        {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }

        else
        {
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }
};

int main()
{
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    if (ds.findUParent(3) == ds.findUParent(7))
        cout << "same" << endl;
    else
        cout << " Not Same" << endl;

    ds.unionBySize(3, 7);
    if (ds.findUParent(3) == ds.findUParent(7))
        cout << "same" << endl;
    else
        cout << " Not Same" << endl;

    return 0;
}