#include<stdio.h>
#define n 5
int stack[n];
int top = -1;

void push(int x){
    if(top >= n-1){
        printf("Overflow\n");
    }else{
        stack[++top] = x;
        printf("Pushed element : %d\n",x);
    }
}
void pop(){
    if(top == -1){
        printf("Underflow\n");
    }else{
        printf("Popped element : %d\n",stack[top--]);
    }
}
void peek(){
    if(top == -1){
        printf("Stack is empty\n");
    }else{
        printf("value at top : %d\n",stack[top]);
    }
}
void display(){
    if(top == -1){
        printf("Stack is empty\n");
    }else{
        for(int i=top; i>=0; i--){
        printf("%d\n",stack[i]);
        }
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
        printf("====================================\n");

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
                printf("Enter valid choice !!\n");
                break;
        }
    }while(choice != 5);
    return 0;
}