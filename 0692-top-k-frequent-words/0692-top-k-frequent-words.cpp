
    bool comp(pair<string, int> a, pair<string, int> b){
        if(a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    }
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(auto s : words) mp[s]++;
        vector<pair<string, int>> vec;
        for(auto p : mp) vec.push_back(p);
        sort(vec.begin(), vec.end(), comp);
        vector<string> ans;
        for(int i = 0; i < k; i++) ans.push_back(vec[i].first);
        return ans;
    }
};