#include<stdio.h>
#include<stdlib.h>

int main(void){

    int n,i,j;
    char instructionSet[10][6];
    printf("Enter the number of instructions \n");
    scanf("%d",&n);
   

    printf("Enter the instructions \n");
    for(i=0;i<n;i++)
        scanf("%s",instructionSet[i]);
        
    for(i=0;i<n;i++){
        char ch = instructionSet[i][3];
        switch(ch){
            case '+':printf("ADD %c , %c , %c \n",instructionSet[i][0],instructionSet[i][2],instructionSet[i][4]);
            break;
            case '-':printf("SUB %c , %c , %c \n",instructionSet[i][0],instructionSet[i][2],instructionSet[i][4]);
            break;
            case '*':printf("MUL %c , %c , %c \n",instructionSet[i][0],instructionSet[i][2],instructionSet[i][4]);
            break;        
            case '/':printf("DIV %c , %c , %c \n",instructionSet[i][0],instructionSet[i][2],instructionSet[i][4]);
            break;
        
        }
    }
    
    return 0;
}