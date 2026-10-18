class LockingTree {
public:
    vector<int> hold;
    vector<int> p;
    vector<vector<int>> children; 
    int n;
    LockingTree(vector<int>& parent) {
        n = parent.size();
        p = parent;
        hold = vector<int>(n, 0);
        children.assign(n, {});
        for (int i = 1; i < n; i++) children[parent[i]].push_back(i);
    }
    
    bool lock(int num, int user) {
        if(hold[num] == 0){
            hold[num] = user;
            return true;
        }
        else return false;
    }
    
    bool unlock(int num, int user) {
        if(hold[num] == user){
            hold[num] = 0;
            return true;
        }
        else return false;
    }

    vector<int> findlockdes(int num){
        vector<int> res;
        queue<int> q;
        for (int c : children[num]) q.push(c);

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            if (hold[cur] != 0) res.push_back(cur);
            for (int c : children[cur]) q.push(c);
        }
        return res;
    }
    
    bool islockans(int num){
        if(num == -1) return false; 
        return (hold[num] != 0) || islockans(p[num]);
    }

    bool upgrade(int num, int user) {
        if(hold[num] != 0) return false;
        vector<int> lockdes = findlockdes(num);
        if(lockdes.size() == 0) return false;
        if(islockans(num)) return false;

        for(auto d : lockdes) hold[d] = 0;
        hold[num] = user;
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */