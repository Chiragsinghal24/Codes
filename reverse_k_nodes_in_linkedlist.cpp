//leetcode 25

class Solution {
public:
    ListNode* reversenode(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* prev=NULL;
        ListNode* forward=head;
        ListNode* current=head;
        while(current!=NULL){
            current=current->next;
            forward->next=prev;
            prev=forward;
            forward=current;
        }
        return prev;  //it is the head node of the linked list
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        //reversing the nodes in the k groups
        ListNode* curr=head;
        ListNode* slow=head;
        ListNode* newhead=NULL;
        ListNode* track=NULL;
        ListNode* prev=NULL;
        int count=0;
        while(curr!=NULL){
            count++;
            prev=curr;
            curr=curr->next;
            if(k==count){
                ListNode* head1=NULL;
                prev->next=NULL;
                //here prev is the head and slow is the tail
                if(newhead==NULL){
                    newhead=reversenode(slow);
                }
                else{
                    cout<<"data "<<slow->val<<endl;
                    head1=reversenode(track);
                    slow->next=head1;
                    slow=track;
                }
                count=0;
                track=curr;
            }
        }
        slow->next=track;
        return newhead;
    }
};