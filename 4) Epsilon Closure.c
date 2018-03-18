#include<stdio.h>



void main()
{
	int n,i,j,k=0,l,m,temp;
	printf("Enter the number of states \n");
	scanf("%d",&n);
	//printf("%d ",n);
	int transition_table[n][n];
	int row[n];
	printf("Enter the transition table\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&transition_table[i][j]);

	for(i=0;i<n;i++)
	{	
		k=0;
		row[k++]=i;
		//printf("Epsilon closure of %d is ( %d",i,i);
		for(j=0;j<n;j++)
			if(transition_table[i][j]==1)
				row[k++]=j;
		int size = k;
		
		for(l=0;l<size-1;l++)
			for(m=0;m<size-l-1;m++)
				if(row[m]>row[m+1])
				{
					temp = row[l];
					row[l] = row[m];
					row[m] = temp;
				}
		printf("Epsilon closure of %d is ( ",i);
		for(l=0;l<size;l++)
			printf("%d ",row[l]);
		printf(" ) \n");
	}

}