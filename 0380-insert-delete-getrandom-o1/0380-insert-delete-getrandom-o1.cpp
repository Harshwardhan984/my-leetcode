class RandomizedSet {
public:
    unordered_set<int> st;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(st.find(val) == st.end()){
            st.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        auto i = st.find(val);
        if(i != st.end()){
            st.erase(i);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int n = st.size()-1;
        int r = (rand() % (n - 0 + 1)) + 0;
        auto i = st.begin();
        advance(i, r);
        return (int)*i;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */