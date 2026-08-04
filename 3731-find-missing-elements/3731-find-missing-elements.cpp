class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> st;
        int mini = INT_MAX, maxi = 0;
        for(int i : nums){
            mini = min(i, mini);
            maxi = max(i, maxi);
            st.insert(i);
        }
        vector<int> ans;
        for(int i = mini; i <= maxi; i++) if(st.find(i) == st.end()) ans.push_back(i);
        return ans;
    }
};