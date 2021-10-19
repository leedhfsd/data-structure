#include <stdio.h>
#include <Stdlib.h>

typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode *head, element value){
    ListNode* new_head = (ListNode*)malloc(sizeof(ListNode));
    new_head->link = head;
    new_head->data = value;
    head = new_head;
    return head;
}

ListNode* insert(ListNode* head ,ListNode* pre, element value){
    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    new_node->data = value;
    new_node->link = pre->link;
    return head;
}

ListNode* delete_first(ListNode* head){
    ListNode* removed;
    if(head==NULL) return NULL;
    removed = head;
    head = head->link;
    free(removed);
    return head;
}

ListNode* delete(ListNode* head, ListNode* pre){
    ListNode* removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

ListNode* print_list(ListNode* head){
    for(ListNode* p = head; p != NULL; p = p->link){
        printf("%d->",p->data);
    }
    printf("\n");
}
int main(){
    ListNode* head = NULL;
    for(int i = 0; i<5;i++){
        head = insert_first(head,i);
        print_list(head);
    }
    for(int i = 0; i < 5; i++){
        head = delete_first(head);
        print_list(head);
    }
    return 0;
}