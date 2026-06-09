//expend_1
#include<stdio.h>
void expend_1(char *a);
int judge(char *a, int i);
char output[2000];
int main()
{
	char input[2000];
	scanf("%s",input);
	expend_1(input);
	printf("%s",output);
	return 0;
}
int judge(char *a, int i)
{
	if((a[i-1]<a[i+1]&&a[i-1]<='z'&&a[i+1]<='z'&&a[i-1]>='a'&&a[i+1]>='a')||\
	(a[i-1]<a[i+1]&&a[i-1]<='9'&&a[i+1]<='9'&&a[i-1]>='0'&&a[i+1]>='0')||\
	(a[i-1]<a[i+1]&&a[i-1]<='Z'&&a[i+1]<='Z'&&a[i-1]>='A'&&a[i+1]>='A')){
		return 1;
	}
	return 0;
}
void expend_1(char *a)
{
	int i,j=0;
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]=='-'){
			if(judge(a,i)){
				do{
					output[j]=output[j-1]+1;
					j++;
				}while(output[j-1]!=a[i+1]-1);
				continue;
			}
		}
		output[j++]=a[i];
	}
	return ;
}



