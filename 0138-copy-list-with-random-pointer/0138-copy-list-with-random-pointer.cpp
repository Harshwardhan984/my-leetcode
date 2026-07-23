/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(0);
        Node* o = head;
        Node* n = dummy;
        unordered_map<Node*, Node*> mp;
        while(o){
            n->next = new Node(o->val);
            n = n->next;
            mp[o] = n;
            o = o->next;
        }
        n->next = NULL;
        o = head;
        n = dummy->next;
        while(o){
            n->random = mp[o->random];
            o = o->next;
            n = n->next;
        }
        return dummy->next;
    }
};