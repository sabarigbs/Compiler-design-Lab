#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
char *str = (char *)malloc(sizeof(char));
char keywords[32][10]={"auto\0","double\0","int\0","struct\0","break\0","else\0","long\0","switch\0","case\0","enum\0","register\0","typedef\0","char\0","extern\0","return\0","union\0","const\0","float\0","short\0","unsigned\0","continue\0","for\0","signed\0","void\0","default\0","goto\0","sizeof\0","volatile\0","do\0","if\0","static\0","while\0"};
char symbols[26][4]={"!\0","#\0","$\0","%\0","&\0","'\0","(\0",")\0",".\0",":\0","<\0","=\0",">\0","?\0","@\0","[\0","\\\0","]\0","^\0","_\0",",\0","+\0","-\0","*\0","/\0"};
printf("Enter the string ");
fgets(str,100,stdin);

int i=0,wc=1;
//count the no of words
while(str[i]!='\0')
{
	if(str[i]==','||str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='%')
		wc+=2;			
	if(str[i]==' ')
		wc++;
	i++;
}

printf("%d\n",wc);

char words[wc][20];
int j=0,w=0;
i=0;

while(str[i]!='\0')
{
	if(str[i]==';')		
		break;			
	if(str[i]!=' ')
	{
		
		if(str[i]==','||str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='%')
		{
			
			words[w][j]='\0';		//delimiter is encountered,End the previous word
			w++;					//Increment the word index
			words[w][0]=str[i];		//Store the delimiter
			words[w][1]='\0';		//end the delimiter
			w++;					//Increment word index for next word
			j=0;					//set second index to start from 0
		}
		else{
			words[w][j++]=str[i];	//store each letter of word to corresponding index
		}

	}else if(str[i]==' '){
		/*printf("w---> %d ",w);
		printf("j---> %d ",j);*/
		words[w++][j]='\0';
		j=0;
	}
	i++;
}
/*printf("w---> %d ",w);
printf("j---> %d ",j);*/
//printf("Symbols size %d ",sizeof(symbols)/sizeof(char));
words[w][j]='\0';		//set null to avoid garbage value at the end of last token
int k;
/*for(i=0;i<wc;i++)
	printf("At position %d  ---> %s",i,words[i]);*/

for(i=0;i<wc;i++)
{
	for(k=0;k<32;k++)
	{
		if(strcmp(words[i],keywords[k])==0)
		{
			printf("Keyword    ---> %s \n",words[i]);
			break;
		}
		else if(k<26)
		{
			//printf("words[i] inside else if --> %s \n",words[i]);
			//printf("symbols[k] inside else if --> %s \n",symbols[k]);
			if(strcmp(words[i],symbols[k])==0)
			{
				printf("Symbol ---> %s \n",words[i]);
				break;
			}
		}
		else{
			printf("Identifier ---> %s \n",words[i]);
			break;
		}
	}
}	

	
}