#include <stdio.h>
#include <stdlib.h>

typedef struct dLinkedList{
    struct dLinkedList* left_link;
    struct dLinkedList* right_link;
    int index;
    int data;
}dLinkedList;

dLinkedList* insert(dLinkedList* head, int index, int data){
    dLinkedList* node = (dLinkedList*)malloc(sizeof(dLinkedList));
    node->index = index;
    node->data = data;
    
    if(head == NULL){
        head = node;
        node -> left_link = head;
        node -> right_link = head;
    }else{
        node->right_link = head->right_link;
        head->right_link->left_link = node;
        node->left_link = head;
        head->right_link = node;
    }
    head = node;
    return head;
}
dLinkedList* delete_return(dLinkedList* head){
    dLinkedList* nextNode = head;
    int step = head->data;
   
    printf("%d ",head->index);

    if(step > 0){
        while(step > 0){
            nextNode = nextNode->right_link;
            step--;
        }
    }
    else if(step < 0){
        while(step < 0){
            nextNode = nextNode->left_link;
            step++;
        }
    }
    head->left_link->right_link = head->right_link;
    head->right_link->left_link = head->left_link;
    free(head);
    return nextNode;
}


int main(){
    int ballonNum ;
    int movement[1001] = {0,};
    dLinkedList* head = NULL;
    scanf("%d",&ballonNum);

    for(int i = 0; i < ballonNum ; i++){
        scanf("%d",&movement[i]);
    }
    for(int i = 0; i < ballonNum ; i++){
        head = insert(head,i+1,movement[i]);
    }
    head = head->right_link;
    for(int i = 0; i< ballonNum;i++){
        head = delete_return(head);
    }
    return 0;
    
}