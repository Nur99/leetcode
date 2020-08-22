class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(int i = 0; i < lists.size(); i++){
            ListNode *l = lists[i];
            if(l != NULL){
                pq.push(make_pair(l -> val, i));
            }
        }

        ListNode *head = new ListNode(0);
        ListNode *temp = head;
        while(pq.size()){
            auto cur = pq.top();
            temp -> next = new ListNode(cur.first);
            temp = temp -> next;
            lists[cur.second] = lists[cur.second] -> next;
            if(lists[cur.second] != NULL){
                pq.push(make_pair(lists[cur.second] -> val, cur.second));
            }  
            pq.pop();
        }

        return head -> next;
    }
private:
    priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq;
};

