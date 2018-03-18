#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

char stack[MAXSIZE];
int top = -1;

void push(char ch){
    stack[++top] = ch;
}

char pop(){
    return stack[top--];
}

int isOperator(char ch){
    if(ch=='/'||ch=='*'||ch=='.'||ch=='('||ch==')')
        return 1;
    return 0;
}

int precedence(char symbol){
	if(symbol == '*')
		return 3;
	else if(symbol=='.')
		return 2;
	else if(symbol=='/')
		return 1;
	else
		return 0;
    
}

int closure(char symbol,int prevEndState){
	printf("%d --> %d = @ \n",prevEndState+0,prevEndState+1);
	printf("%d --> %d = @ \n",prevEndState+0,prevEndState+3);
	printf("%d --> %d = %c \n",prevEndState+1,prevEndState+2,symbol);
	printf("%d --> %d = @ \n",prevEndState+2,prevEndState+1);
	printf("%d --> %d = @ \n",prevEndState+2,prevEndState+3);
	return prevEndState+3;


}

int and(char first,char second,int prevEndState){
	
	if(first!='x')
		printf("%d --> %d = %c \n",prevEndState+0,prevEndState+1,first);
	if(second!='x')
		printf("%d --> %d = %c \n",prevEndState+1,prevEndState+2,second);
	return prevEndState+1;

	

}

int or(char first,char second,int prevEndState){
	
	if(first!='x')
		printf("%d --> %d = %c \n",prevEndState+0,prevEndState+1,first);
	if(second!='x')
		printf("%d --> %d = %c \n",prevEndState+1,prevEndState+2,second);
	return prevEndState+1;

	

}


int main(void){

    int i=0,postfixIndex=0;
    char *str = (char *)malloc(sizeof(str));
    char *postfix = (char *)malloc(sizeof(str));
    printf("Enter the regular expresiion \n");
    fgets(str,100,stdin);

    //printf("%s",str);
    stack[++top] = '#';
    while(str[i]){
        if(isOperator(str[i])){
            if(precedence(str[i])>precedence(stack[top]))
            	push(str[i]);
            else if(precedence(str[i])<=precedence(stack[top])){
            	while(precedence(str[i])<=precedence(stack[top]))
            		postfix[postfixIndex++] = pop();
            	push(str[i]);
            }
            
		}
		
		else
            postfix[postfixIndex++] = str[i];

    i++;
    }
    while(stack[top]!='#')
    	postfix[postfixIndex++] = pop();
    postfix[postfixIndex]='\0';
    
    top=-1;
    i=0;
    int prevEndState = 0;
    while(postfix[i]!='\0'){
    	char eval = postfix[i];
    	if(eval>='a'&&eval<='z')
    		push(eval);
    	else if(eval == '*' || eval == '.' || eval == '/'){
    		char first,second;
    		switch(eval){
    			case '*' : prevEndState = closure(pop(),prevEndState);
    			push('x');
    			break;
    			case '.' : 
    			second = pop();
    			first = pop();
    			printf("second = %c\n",second);
    			printf("first = %c\n",first);
    			if(first!=second)
    				prevEndState = and(first,second,prevEndState);
    			push('x');
    			break;
    			/*case '/' :
    			second = pop();
    			first = pop();
    			prevEndState = or(first,second);
    			push('x');
    			*/
    		}
	    }
	    i++;
    }
}