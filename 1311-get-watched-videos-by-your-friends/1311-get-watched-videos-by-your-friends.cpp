class Solution {
public:
    void customSort(vector<string>& videos) {
    unordered_map<string, int> freq;

    for (const string& s : videos) {
        freq[s]++;
    }

    sort(videos.begin(), videos.end(), [&](const string& a, const string& b) {
        if (freq[a] != freq[b])
            return freq[a] < freq[b];
        return a < b;
    });

    videos.erase(unique(videos.begin(), videos.end()), videos.end());
}
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = watchedVideos.size();
        vector<string> videos;
        vector<bool> visited(n);
        queue<pair<int, int>> q;
        q.push({id, 0});
        visited[id] = 1;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int curpeop = p.first, curlvl = p.second;
            if(curlvl == level){
                for(auto s : watchedVideos[curpeop]) videos.push_back(s);
            }
            if(curlvl > level) continue;
            for(int ngpeop : friends[curpeop]){
                if(!visited[ngpeop]){
                    q.push({ngpeop, curlvl+1});
                    visited[ngpeop] = 1;
                }
            }
        }
        customSort(videos);
        return videos;
    }
};