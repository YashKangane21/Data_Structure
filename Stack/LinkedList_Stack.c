#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* top = NULL;

void push(int x){ 
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Memory allocation failed !\n\n");
        return;
    }else{
        newnode->data = x;
        newnode->next = top;
        top = newnode;
        printf("Value %d pushed\n\n",x);
    }
}
void pop(){
    if(top == NULL){
        printf("Underflow\n\n");
    }else{
        struct node* temp = top;
        printf("Popped element : %d\n\n",top->data);
        top = top->next;
        free(temp);
    }
}
void peek(){
    if(top == NULL){
        printf("Stack is empty\n\n");
    }else{
        printf("Value at top : %d\n\n",top->data);
    }
}
void display(){
    if(top == NULL){
        printf("Stack is empty\n\n");
    }else{
        printf("Stack Elements :\n\n");
        struct node* temp = top;
        while(temp != NULL){
            printf("%d ->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n\n");
    }
}
int main(){
    int choice,  value;
    do{
        printf("=============== Menu ===============\n");
        printf("Enter 1 - Push\n");
        printf("Enter 2 - Pop \n");
        printf("Enter 3 - Peek\n");
        printf("Enter 4 - Display\n");
        printf("Enter 5 - Exit\n");
        printf("====================================\n\n");

        printf("Enter your choice :");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter value :");
                scanf("%d",&value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                break;
            default :
                printf("Enter valid choice !!\n\n");
                break;
        }
    }while(choice != 5);
    return 0;
}