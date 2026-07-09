class DisjointSet {
private:
    std::vector<int> parent; // Parent of each node
    std::vector<int> rank;   // Rank (approximate tree height)

public:
    // Constructor: initializes n disjoint sets (0 to n-1)
    DisjointSet(int n) {
        if (n <= 0) {
            throw std::invalid_argument("Size of DisjointSet must be positive.");
        }
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i; // Each node is its own parent initially
        }
    }

    // Find with path compression
    int find(int x) {
        if (x < 0 || x >= (int)parent.size()) {
            throw std::out_of_range("Element index out of range.");
        }
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Union by rank
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return; // Already in the same set

        // Attach smaller rank tree under root of higher rank tree
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++; // Increase rank if both have same rank
        }
    }

    // Check if two elements are in the same set
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DisjointSet ds(n);
        vector<pair<int, int>> indexedNums;
        for (int i = 0; i < n; i++) indexedNums.push_back({nums[i], i});
        sort(indexedNums.begin(), indexedNums.end());

        for (int i = 0; i < n - 1; i++) {
            if (indexedNums[i+1].first - indexedNums[i].first <= maxDiff) {
                int u = indexedNums[i].second;
                int v = indexedNums[i+1].second;
                ds.unite(u, v);
            }
        }
        vector<bool> ans;
        for(auto q : queries){
            if(ds.connected(q[0], q[1])) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};