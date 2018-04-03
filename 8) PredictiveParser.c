#include<stdio.h>
#include<ctype.h>
#include<string.h>
int n,m=0,p,i=0,j=0;
char a[10][10],followResult[10];
void follow(char c);
void first(char c);
void addToResult(char);

int getIndex(char c){
    int iterator;
    for(iterator=0;iterator<n;iterator++)
        if(a[iterator][0]==c)
            return iterator;
    return -1;
}
int main()
{
    int i;
    int choice;
    char c,ch;

    printf("Enter the no.of productions\n");
    scanf("%d", &n);
    printf("Enter %d productions\n", n);
    for(i=0;i<n;i++)
        scanf("%s%c",a[i],&ch);
    
    
    do
    {
        m=0;
        printf("Enter the symbol to find first and follow \n");
        scanf(" %c",&c);
        first(c); 
        printf("\n First(%c)= { ",c);
        for(i=0;followResult[i]!='\0';i++){
            printf(" %c ",followResult[i]);
            
        } 
        printf("}\n");
        int index = getIndex(c);
        printf("Index = %d ",index);
        printf("Predictive Parsing Table \n");
        for(i=0;followResult[i]!='\0';i++){
             printf("( %c , %c ) = %s \n",c,followResult[i],a[index]);
        }  

        follow(c);
        printf("Follow (%c) = { ",c);
        for(i=0;i<m;i++)
            printf("%c ",followResult[i]);
        printf(" }\n");
        printf("Press 1 to continue\n");
        scanf("%d",&choice);
        }
    while(choice==1);
}
void follow(char c)
{
    if(a[0][0]==c)
        addToResult('$');
    for(i=0;i<n;i++)
    {
        for(j=2;j<strlen(a[i]);j++)
        {
            if(a[i][j]==c)
            {
                if(a[i][j+1]!='\0')
                    first(a[i][j+1]);
                if(a[i][j+1]=='\0'&&c!=a[i][0])
                    follow(a[i][0]);
            }
        }
    }
}
void first(char c)
{
    int k;
    if(!(isupper(c)))
        addToResult(c);
    for(k=0;k<n;k++)
    {
        if(a[k][0]==c)
        {
            if(a[k][2]=='#') 
                follow(a[i][0]);
            else if(islower(a[k][2]))
                addToResult(a[k][2]);
            else 
                first(a[k][2]);
        }
    }
}
void  addToResult(char c)
{
    int i;
    for( i=0;i<=m;i++)
        if(followResult[i]==c)
            return;
   followResult[m++]=c;
} 

