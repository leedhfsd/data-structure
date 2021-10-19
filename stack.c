#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int element;
typedef struct Stack{
    int top;
    element* data;
    int max_size;
}Stack;

void stack_init(Stack *stk,int stack_size){
    stk->top = -1;
    stk->max_size = stack_size;
    stk->data = (element*)malloc(sizeof(element)*stack_size);
}

void push(Stack* stk,element value){
    if(stk->top < stk->max_size-1){
        stk->top++;
        stk->data[stk->top] = value;
        printf("->stack is pushed: %d\n ",value);
    }else{
        printf("Stack is full\n");
    }
}

element pop(Stack *stk){
    element value;
    if(stk->top >= 0){
        value = stk->data[stk->top];
        stk->top--;
        printf("->stack is popped: %d\n",value);
        return value;
    }else{
        printf("stack is empty\n");
    }
}

element peek(Stack *stk){
    element value;
    if(stk->top >= 0){
        value = stk->data[stk->top];
        printf("stack is peeked: %d\n",value);
        return value;
    }else{
        printf("stack is empty\n");
    }
}

bool is_empty(Stack* stk){
    if(stk->top == -1){
        printf("true\n");
        return true;
    }else{
        printf("false\n");
        return false;
    } 
}

bool is_full(Stack* stk){
    if(stk->top == stk->max_size -1){
        printf("true\n");
        return true;
    }else{
        printf("false\n");
        return false;
    }
}



int main(){
    Stack stack;
    int max_size;
    scanf("%d",&max_size);
    stack_init(&stack,max_size);

    is_empty(&stack);
    push(&stack,2);
    push(&stack,5);
    push(&stack,8);
    push(&stack,10);
    push(&stack,12);
    push(&stack,13);
    is_full(&stack);
    peek(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);

    return 0;
}

