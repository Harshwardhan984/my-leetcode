class Solution {
public:
    struct DSU {
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]); // Path compression
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (sz[x] < sz[y])
            swap(x, y);

        parent[y] = x;
        sz[x] += sz[y];

        return true;
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    int size(int x) {
        return sz[find(x)];
    }
};
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        vector<int> ans(2);
        DSU dsu(n+1);
        for(auto eg : edges){
            int u = eg[0], v = eg[1];
            if(dsu.connected(u, v)) ans = eg;
            else dsu.unite(u, v);
        }
        return ans;
    }
};