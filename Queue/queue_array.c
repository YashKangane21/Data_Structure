#include<stdio.h>
#define N 5
int Queue[N];
int front = -1, rear = -1;

int isEmpty(){
    return (front == -1 || front > rear);
}
int isFull(){
    return rear == N-1;
}
void enqueue(int x){
    if(isFull()){
        printf("Queue Overflow!\n");
    }else{
        if(front == -1){
            front = 0;
        }
        Queue[++rear] = x;
        printf("Enqueued element : %d\n",x);
    }
}
void dequeue(){
    if(isEmpty()){
        printf("Queue underflow!\n");
    }else{
        printf("Dequeued element : %d\n",Queue[front++]);
        if(front > rear){
            front = rear = -1;
        }
    }
}
void peekFront(){
    if(isEmpty()){
        printf("Queue is empty\n");
    }else{
        printf("Element at front : %d\n",Queue[front]);
    }
}
void peekRear(){
    if(isEmpty()){
        printf("Queue is empty\n");
    }else{
        printf("Element at rear : %d\n",Queue[rear]);
    }
}
void display(){
    if(isEmpty()){
        printf("Queue is empty\n");
    }else{
        printf("Queue elements : ");
        for(int i = front; i <= rear; i++){
            printf("%d ",Queue[i]);
        }
    }
    printf("\n");

}
int main(){
    int choice, value;
    do{
        printf("------------ Menu ------------\n");
        printf("1 - Enqueue\n");
        printf("2 - Dequeue\n");
        printf("3 - Peek Front\n");
        printf("4 - Peek Rear\n");
        printf("5 - Display\n");
        printf("6 - Exit\n");
        printf("------------------------------\n\n");

        printf("Enter your choice :");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter element :");
                scanf("%d",&value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peekFront();
                break;
            case 4:
                peekRear();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default :
                printf("Enter valid choice !\n");
        }
    }while(choice != 6);
    return 0;
}