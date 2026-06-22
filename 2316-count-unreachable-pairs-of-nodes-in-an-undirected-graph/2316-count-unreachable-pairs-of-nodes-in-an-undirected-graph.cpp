class DSU {
    vector<int> parent, rank_;

public:
    DSU(int n) {
        parent.resize(n + 1);
        rank_.resize(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Find with Path Compression
    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    // Union by Rank
    void unionSets(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA == rootB)
            return;

        if (rank_[rootA] < rank_[rootB]) {
            parent[rootA] = rootB;
        }
        else if (rank_[rootA] > rank_[rootB]) {
            parent[rootB] = rootA;
        }
        else {
            parent[rootB] = rootA;
            rank_[rootA]++;
        }
    }
};
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DSU st(n);
        for(auto edge : edges){
            st.unionSets(edge[0], edge[1]);
        }
        long long ans = 0;
        //vector<int> arr;
        int total = n;
        unordered_map<int, int>mp;
        for(int i = 0; i < n; i++) mp[st.find(i)]++;
        for(auto set : mp){
            int curn = set.second;
            int rem = total - curn;
            ans += (long long)curn * (long long)rem;
            total -= curn;
        }
        return ans;
    }
};