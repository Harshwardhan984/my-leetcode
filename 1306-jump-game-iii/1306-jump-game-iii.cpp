class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start);
        visited[start] = 1;
        while(!q.empty()){
            int curi = q.front(); q.pop();
            if(arr[curi] == 0) return true;
            int left = curi - arr[curi];
            int right = curi + arr[curi];
            if(0 <= left && left < n && !visited[left]){
                q.push(left);
                visited[left] = 1;
            }
            if(0 <= right && right < n && !visited[right]){
                q.push(right);
                visited[right] = 1;
            }
        }
        return false;
    }
};