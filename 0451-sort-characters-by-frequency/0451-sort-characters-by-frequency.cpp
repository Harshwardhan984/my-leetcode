class Solution {
public:
    struct cmp{
        bool operator()(pair<char, int> a, pair<char, int> b){
            if(a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        }
    };
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(char c : s) mp[c]++;
        priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> pq;
        for(auto p : mp) pq.push(p);
        string ans = "";
        while(!pq.empty()){
            auto p = pq.top(); pq.pop();
            ans.append(p.second, p.first);
        }
        return ans;
    }
};