class Solution {
public:
    void printStack(stack<int> st){
        
        while(!st.empty()){
            cout<<st.top()<<" "; st.pop();
        }

        cout<<endl;
        return;
    }
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && t[i] > t[st.top()]){
                int prvt = st.top();
                ans[prvt] = i- prvt;
                st.pop();
            }
            st.push(i);
           // printStack(st);
        }
        return ans;
    }
};