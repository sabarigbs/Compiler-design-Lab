#include<stdio.h>
#include<stdlib.h>

//Stack and its methods
char stack[15];
int top = -1;

void push(char ch){
    if(top>=14)
        printf("Stack Overflow!!!\n");
    else
        stack[++top] = ch; 
}

char pop(){
    if(top == -1)
        printf("Stack Underflow!!!\n");
    else    
        return stack[top--];
   
}

char peek(){
    if(top == -1)
        printf("Stack Underflow!!!\n");
    else    
        return stack[top];
}

//Utility methods
int isOperator(char ch){
    if(ch == '+' ||ch == '-' ||ch == '*' ||ch == '/' ||ch == '^' )
        return 1;
    return 0;
}

int precedence(char ch){
    if(ch == '^')
        return 4;
    else if(ch == '*' || ch == '/')
        return 3;
    else if(ch == '+' || ch == '-')
        return 2;
    return 1;
}


//Postfix Conversion takes place here
void convertPostfix(char* expression){
    //fputs(expression,stdout);
    char *postfix = (char *)malloc(sizeof(char));
    char result[10][6];
    int postfixIndex = 0,i=0,rowIndex=0,columnIndex=0;
    stack[++top] = '#'; 
    
    while(expression[i]){
        if(isOperator(expression[i])){
            if(precedence(expression[i])>precedence(stack[top]))
            	push(expression[i]);
            else if(precedence(expression[i])<=precedence(stack[top])){
            	while(precedence(expression[i])<=precedence(stack[top]))
            		postfix[postfixIndex++] = pop();
            push(expression[i]);
            }
        }else
            postfix[postfixIndex++] = expression[i]; 
        i++;
        

    }
    //printf("Postfix Index = %d\n",postfixIndex);
    postfixIndex--;
    while(stack[top]!='#')
    	postfix[postfixIndex++] = pop();
    postfix[postfixIndex]='\0';

    top = -1;
    i=0;
    
    //printf("Top = %d Postfix = %s",top,postfix);
    char ch,first,second,temp='P';
    while(postfix[i]){
        
        ch = postfix[i];
        if(ch >='a'&&ch<='z')
            push(ch);
        else{
            second = pop();
            first = pop();
            //printf("First = %c\nSymbol = %c\nSecond = %c \n",first,ch,second);
            //printf("%c \n",ch);
            push(temp);
            result[rowIndex][columnIndex++]=temp++;
            result[rowIndex][columnIndex++]='=';
            result[rowIndex][columnIndex++]=first;
            result[rowIndex][columnIndex++]=ch;
            result[rowIndex][columnIndex++]=second;
            result[rowIndex][columnIndex]='\0';
            rowIndex++;
            columnIndex = 0;
            //printf("Stack = %s \n",stack);


        }
        //printf("%c \n",postfix[i]);
        i++;

       
    }

     printf("\nThree Address Codes \n");
     for(i=0;i<rowIndex;i++)
            printf("%s \n",result[i]);
    

    }


int main(void){

    char *expression = (char *)malloc(sizeof(char));
    printf("Enter the expression \n");
    fgets(expression,255,stdin);
    convertPostfix(expression);
    
    return 0;

}