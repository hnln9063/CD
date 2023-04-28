/* Implementation of elimination of left recursion */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void ELS(char s[])
{
	int not=0,i,f=0,j,flag=0;
	for(i=0;i<strlen(s);i++)
		if(s[i]=='|')
			not++;
	char s1[not+1][100];
	int idx1=0,idx2=0;
	int count[not+1],c=0;

	for(i=3;i<strlen(s);i++) {
		if(s[i]=='|') {
			idx2=0;
			count[idx1]=c;
			c=0;
			idx1++;
		} else {
			s1[idx1][idx2]=s[i];
			c++;
			idx2=idx2+1;
		}
	}

	count[idx1]=c;
	for(i=0;i<=not;i++) {
		if(s[0]==s1[i][0])
		flag=1;
	}
	if(flag==1) {
		printf("After elemination of left recursion \n");
		printf("%c->",s[0]);
		for(i=0;i<=not;i++) {
			if(s[0]!=s1[i][0]) {
				if(f==0) {
					f=1;
					for(j=0;j<count[i];j++)
						printf("%c",s1[i][j]);	
					printf("%c'",s[0]);
				} else {
					printf("|");
					for(j=0;j<count[i];j++)
						printf("%c",s1[i][j]);
					printf("%c'",s[0]);
				}
			}
		}
		printf("\n");
		printf("%c'->",s[0]);
		f=0;
		for(i=0;i<=not;i++) {
			if(s[0] == s1[i][0]) {
				if(f == 0) {
					f = 1;
					for(j=1;j<count[i];j++)
						printf("%c",s1[i][j]);
					printf("%c'",s[0]);
				} else {
					printf("|");
					for(j=1;j<count[i];j++)
					printf("%c",s1[i][j]);
					printf("%c'",s[0]);
				}
			}
		}
		printf("|E\n");
	} else
		printf("Given production %s is not in left recursion\n",s);
}
void main()
{
	char s[100];
	int n;
	printf("Enter no of productions : ");
	scanf("%d",&n);
	while(n--!=0)
	{
		printf("Ener the Production in the form(A->A@|B) : ");
		scanf("%s",s);
		printf("The Production is : %s\n",s);
		ELS(s);
	}
}
/*
Test Case :
Enter no of productions : 2
Ener the Production in the form(A->A@|B) : A->Aa|b
The Production is : A->Aa|b
After elemination of left recursion
A->bA'
A'->aA'|E
Ener the Production in the form(A->A@|B) : A->ab|c
The Production is : A->ab|c
Given production A->ab|c is not in left recursion
*/
