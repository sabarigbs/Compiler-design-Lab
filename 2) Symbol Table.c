#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char* substring(char *src,char *key){
	int source_length = strlen(src)-1;
	int key_length = strlen(key)-1;

	//printf("source_length = %d \n",source_length);
	//printf("key length = %d\n",key_length);
	
	int i,j,flag;
	for(i=0;i<=source_length-key_length;i++)
	{
		
		//printf("i+key_length = %d",i+key_length);
		for(j=i;j<i+key_length;j++){
			flag = 1;
			if(src[j]==key[j-i]){
				//printf("%c == %c \n",src[j],key[j-i]);
				
			}else{
				flag=0;
				break;
			}
			
		}
		//printf("Flag %d \n",flag);
		if(flag){
			src[i]='\0';
			break;
		}
	}
	return src;

}


int isKeyword(char* word)
{
	char keywords[32][10]={"auto\0","double\0","int\0","struct\0","break\0","else\0","long\0","switch\0","case\0","enum\0","register\0","typedef\0","char\0","extern\0","return\0","union\0","const\0","float\0","short\0","unsigned\0","continue\0","for\0","signed\0","void\0","default\0","goto\0","sizeof\0","volatile\0","do\0","if\0","static\0","while\0"};
	int ki;
	for(ki=0;ki<32;ki++)
		if(strcmp(keywords[ki],word)==0)
			return 1;
	return 0;
}

void main(){

	char *str = (char *)malloc(sizeof(char));

	char *line = (char *)malloc(sizeof(char));
	char *word = (char *)malloc(sizeof(char));
	char *keyword = (char *)malloc(sizeof(char));
	char *type = (char *)malloc(sizeof(char));


	int wc=0,lc=0,i=0,j=0,line_index=0,word_index=0,identifiers_index=0,expressions_index=0;


	printf("Enter the string \n");
	fgets(str,100,stdin);

	//printf("%s ",str);
	//Count no of lines and words
	while(str[i]!='\0')
	{
		if(str[i]==';'){
			lc++;				//Increment line count when a semicolon is encountered 
			wc++;				//Increment word count to count the last word which is not deliminted by space or comma
		}
		else if(str[i]==' '||str[i]==','){
			wc++;							//Increment word count when a space or comma is encountered
		}
		i++;
	}

	//printf("Line count = %d \n",lc);
	//printf("Word count = %d \n",wc);

	char *lines[lc]; 
	char *words[wc];
	char *identifiers[wc-lc];
	char *expressions[lc];


	i = 0;
	//Separate lines based on semicolon
	while(str[i]!='\0'){
		if(str[i]==';'){
			line[j]=';';
			line[j+1]='\0';
			lines[line_index] = (char *)malloc(strlen(line)+1);
			strcpy(lines[line_index++],line);
			j=0;
		}
		else{
			line[j++] = str[i];
		}
		i++;
	}

	
	//printf("Printing array contents \n")
	//for(i=0;i<lc;i++)
	//	printf("%s \n",lines[i]);
	//  strstr(lines[i],"=")?printf("%s\n",lines[i]):printf("Not found \n");
	j=0;
	int k=0;
	for(line_index=0;line_index<lc;line_index++){
		i=0;
		if(strstr(lines[line_index],"=")){
			expressions[expressions_index] = (char *)malloc(strlen(lines[line_index])+1);
			strcpy(expressions[expressions_index++],lines[line_index]);
			//printf("%s\n",lines[line_index]);
			continue;
		}
		while(lines[line_index][i]!='\0'){
			if(lines[line_index][i]==' '||lines[line_index][i]==','||lines[line_index][i]==';'){
				word[j]='\0';
				if(isKeyword(word))
					strcpy(keyword,word);
				else{
					strcat(word,keyword);
					identifiers[identifiers_index] = (char *)malloc(strlen(word)+1);
					strcpy(identifiers[identifiers_index++],word);

				}
				/*printf("%s \n",word);
				printf("Checking for substring %s \n",strstr(word,keyword));*/
				j=0;
			}
			else{
				word[j++] = lines[line_index][i];
			}
			i++;
		}
		
	}
	int memory = 998;
	for(i=0;i<identifiers_index;i++)
	{
		
		
		if(strstr(identifiers[i],"int"))
			if(strcmp(strstr(identifiers[i],"int"),"int")==0){
				strcpy(identifiers[i],substring(identifiers[i],"int"));
				type="int";
				memory +=2;
			}
		if(strstr(identifiers[i],"float"))
			if(strcmp(strstr(identifiers[i],"float"),"float")==0){
				strcpy(identifiers[i],substring(identifiers[i],"float"));
				type="float";
				memory +=4;
			}

		printf("<id %d> %s %s %d \n",i,identifiers[i],type,memory);

			
		
	}
	printf("expressions \n");
	j=0;
	k=0;
	int token_index = 0;
	int search_flag=0;
	for(i=0;i<expressions_index;i++){
		//printf("%s \n",expressions[i]);
		while(expressions[i][j]!='\0')
		{
			if(expressions[i][j]==';'||expressions[i][j]=='='||expressions[i][j]=='+'||expressions[i][j]=='-'||expressions[i][j]=='*'||expressions[i][j]=='/')
			{
				word[token_index]='\0';
				for(k=0;k<identifiers_index;k++)
					if(strcmp(identifiers[k],word)==0){
						search_flag = 1;
						break;
					}
				if(!search_flag)
					printf("%s is not declared \n",word);

				token_index=0;

			}else{
				word[token_index++]=expressions[i][j];
			}
			j++;
		}
	}

}