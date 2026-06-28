class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int ans = 1;
        int prv = 0;
        for(int i = 0; i < arr.size(); i++){
            int cur = arr[i];
            cout<<cur<<" "<<prv<<" "<<endl;
            if(cur > prv+1){
                cur = prv+1;
            }
            arr[i] = cur;
            ans = max(ans, cur);
            prv = cur;
            
        }
        //ans = max(ans, prv);
        return ans;
    }
};