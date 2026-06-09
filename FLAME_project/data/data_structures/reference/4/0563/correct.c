#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct node{
	char s[5000];
	int sum;
}word[5000];
char q[20000];
int Iisapha(char c){
	if((c<='z'&&c>='a')||(c<='Z'&&c>='A')){
		return 1;
	}
	else return 0;
}
char change(char c){
	if(c<='z'&&c>='a'){
		return c;
	}
	else if(c<='Z'&&c>='A'){
		return c+'a'-'A';
	}
	else return 'N'; 
}
int compare(const void *a,const void *b){
	struct node *c=(struct node*)a;
	struct node *d=(struct node*)b;
	return strcmp(c->s,d->s);
}
int main()
{
	int num=0;int inum=0;
	FILE *fp=fopen("article.txt","r");
	int y=0;
	while(fscanf(fp,"%c",&q[y])!=EOF){
		y++;
	}
	int p=0;int flag=0;
	for(p=0;p<y&&flag==0;p++){
		if(Iisapha(q[p])==1){
			word[num].s[inum]=change(q[p]);
			flag=1;inum++;
		}
	}
	for(int i=p;i<y;i++){
		if(Iisapha(q[i])==1){
			if(Iisapha(q[i-1])==1){
				word[num].s[inum++]=change(q[i]);
			}
			else if(Iisapha(q[i-1])==0){
				num++;inum=0;
				word[num].s[inum++]=change(q[i]);
			}
		}
		
	}
	num++;
	for(int i=0;i<num;i++){
		word[i].sum=1;
	}
	
	for(int i=0;i<num;i++){
		for(int j=i+1;j<num;j++){
			if(strcmp(word[i].s,word[j].s)==0){
				if(word[i].sum!=0)
				word[i].sum++;
				word[j].sum=0;
			}
		}
	}
	qsort(word,num,sizeof(word[1]),compare);
	for(int i=0;i<num;i++)
	{
	if(word[i].sum!=0) 
	printf("%s %d\n",word[i].s,word[i].sum);
		
	}
	return 0;
}

