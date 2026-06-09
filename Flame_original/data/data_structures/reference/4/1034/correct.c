#include <stdio.h>
#include <string.h>
#include <ctype.h>
char str[1000];
char input[100][1000];
char *t[100];
int i,j;
int number[100];
char *word[100];
void sort(char *s[],int n)
{
	int i,j,flag;
	char *hold;
	for (i=0; i<n-1; i++)
		{
			flag=0;
			for (j=0; j<n-1-i; j++)
				{
					if(strcmp(s[j], s[j+1])>0)
						{
							hold=s[j];
							s[j]=s[j+1];
							s[j+1]=hold;
							flag=1;
						}
				}
			if(0==flag)
				break;
		}
}
int main(int argc, char *argv[]) {
	FILE* in;
	in=fopen("article.txt", "r");
	int num=0,k=0,m=0;
	while(fgets(str, 1000, in)!=NULL)
	{
		int len=strlen(str);
		for (i=0; i<len; i++)
			{
				k=0;
				if(isalpha(str[i])!=0)
					{
						for (j=i; isalpha(str[j])!=0; j++)
							{
								input[num][k]=tolower(str[j]);
								k++;
							}
						t[m]=input[num];
						m++;
						num++;
						i=j;
					}
			}
	}
	sort(t, num);
	int l=0;
	for (int i=0; i<num-1; i++)
		{
			word[l]=t[i];
			if(strcmp(t[i], t[i+1])==0)
				{
					number[l]++;
				}
			else
			{
				l++;
			}
		}
	word[l]=t[num-1];
	for (int p=0; p<=l; p++)
	{
		printf("%s %d\n",word[p],number[p]+1);
	}
	fclose(in);
	return 0;
}
