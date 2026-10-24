class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool> visited(V, false);
        vector<bool> pathVisited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, graph, visited, pathVisited);
            }
        } 

        vector<int> result; 
        for (int i = 0; i < V; i++) {
            if (!pathVisited[i]) {
                result.push_back(i);
            }
        }
        return result;
    }

    bool dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& pathVisited) {
        visited[node] = true; 
        pathVisited[node] = true; 

        for (auto const &it : graph[node]) {
            if (!visited[it]) {
                if (dfs(it, graph, visited, pathVisited))
                    return true; 
            }
            else if (pathVisited[it]) {
                return true;
            }
        }

        pathVisited[node] = false;
        return false; 
    }
};