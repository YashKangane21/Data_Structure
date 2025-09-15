#include<stdio.h>
#include<math.h>

#define max 100
char operatorStack[max];
int operatorTop = -1;

char postfixExpression[max];
int postfixTop = -1;

void pushPostfix(char ch){
    postfixExpression[++postfixTop] = ch;
}
void pushOperator(char ch){
    operatorStack[++operatorTop] = ch;
}
char popOperator(){
    return operatorStack[operatorTop--];
}
char peekOperator(){
    return operatorStack[operatorTop];
}

int precedence(char ch){
    switch(ch){
        case '+' : case '-' : return 1;
        case '*' : case '/' : case '%' : return 2;
        case '^' : return 3;
        case '(' : return 0;
    }
    return -1;
}
int isOperator(char ch){
    return (ch == '+' || ch == '-' ||ch == '*' ||ch == '/'||ch == '%'||ch == '^'||ch == '('||ch == ')');
}
void printPostfix(){
    for(int i=0; i<=postfixTop ;i++){
        printf("%c ",postfixExpression[i]);
    }
    printf("\n");
}

void convertInfixToPostfix(char infix[]){
    for(int i=0; infix[i] != '\0' ;i++){
        char currChar = infix[i];
        
        if(isOperator(currChar)){
            if(currChar == '('){
                pushOperator(currChar);
            }
            else if(currChar == ')'){
                while(operatorTop != -1 && peekOperator() != '(' ){
                    pushPostfix(popOperator());
                }
                popOperator();
            }else{
                while(operatorTop != -1 && 
                    ((currChar != '^' && precedence(peekOperator()) >= precedence(currChar)) || 
                    (currChar == '^' && precedence(peekOperator()) > precedence(currChar)))){
                    pushPostfix(popOperator());
                }
                pushOperator(currChar);
            }
        }
        else{
            pushPostfix(currChar);
        }
    }
    while(operatorTop != -1){
        pushPostfix(popOperator());
    }
}

int main(){
    char infixExpression[] = "3^2^1-1";
    printf("Infix Expression :");
    for(int i=0; infixExpression[i] != '\0' ;i++){
        printf("%c",infixExpression[i]);
    }
    printf("\n");

    printf("Postfix Expression :");
    convertInfixToPostfix(infixExpression);
    printPostfix();
    return 0;
}