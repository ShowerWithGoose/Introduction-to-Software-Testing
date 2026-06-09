#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
/*struct node{
	char s[30];
	struct node *left;
	struct node *right;
};*/



char list[1000000][30];
int cmp(char *s1,char *s2){
	if(strcmp(s1,s2)<=0)
		return -1;
	else
		return 1;
}

int main()
{
	FILE *fp=fopen("article.txt","r");
	int i,j,n,count;
	char c='a';
	/*for(i=0;fscanf(fp,"%*[^a-zA-Z]%[a-zA-Z]",list[i])!=0;i++)
		strlwr(list[i]);*/
	for(i=0,j=0;(c=fgetc(fp))!=EOF;){
		if(isalpha(c)){
			do{
				list[i][j++]=tolower(c);
			}while(isalpha(c=fgetc(fp)));
			i++;
			j=0;
		}
	}
	n=i;
	qsort(list,n,sizeof(list[0]),cmp);
	for(i=0,count=1;i<n;i++){
		if(strcmp(list[i],list[i+1])==0)
			count++;
		else {
			printf("%s %d\n",list[i],count);
			count=1;
		}
	}
	fclose(fp);
	return 0;
}







