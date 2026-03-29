
class Solution {
public:
   ListNode* mergeTwoSortedList(ListNode* l1, ListNode* l2){
     if(!l1) return l2;
     if(!l2) return l1;

     if(l1->val < l2->val){
        l1->next = mergeTwoSortedList(l1->next, l2);
        return l1;
     }else{
        l2->next = mergeTwoSortedList(l1, l2->next);
        return l2;
     }
     return NULL;
   }

   ListNode* partitionMerge(int start, int end, vector<ListNode*>& lists){
      if(start > end){
        return NULL;
      }
      if(start == end){
        return lists[start];
      }
      int mid = start+(end-start)/2;
      ListNode* l1 = partitionMerge(start, mid, lists);
      ListNode* l2 = partitionMerge(mid+1, end, lists);

      return mergeTwoSortedList(l1,l2);
   }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();

        if(k==0){
            return NULL;
        }
        return partitionMerge(0, k-1, lists);
    }
};
