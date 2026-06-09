#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100000

struct word{
	char s[100];
	long long num;
};
struct word w[N];
int n=0;

int find(int,char []);  //≤È’“£¨Õ≥º∆ 
int compare(const void *,const void *);
int judge(char);
int get(char [],int);
void clear(char []);

int main()
{
	int i,flag,k,loc;
	char *a,b[100]="";
	a=(char *)malloc(1300);
	FILE *in;
	in=fopen("article.txt","r");
	for(i=1;i<=99999;i++)
	w[i].num=0;
	while(fgets(a,1290,in)){
		loc=0;
		while(get(a,loc)>=0){
			loc=get(a,loc);
			k=loc;
			while(judge(a[k])>0){
				b[k-loc]=(judge(a[k])==2)?a[k]-'A'+'a':a[k];
				k++;
			}
			loc=k;

			
		if(n==0){
			strcpy(w[n+1].s,b); 
			w[n+1].num++;
			n++;
		}
		else
		{
			flag=find(n,b);
			if(flag==0){
				strcpy(w[n+1].s,b); 
				w[n+1].num++;
				n++;
				qsort(w,n+1,sizeof(struct word),compare); 
			}
			else w[flag].num++;
		}
		clear(b);
		}
				
	}
	for(i=1;i<n;i++)
	printf("%s %lld\n",w[i].s,w[i].num);
	printf("%s %lld",w[i].s,w[i].num);
	
	fclose(in);
	return 0;
}

int find(int n,char a[])
{
	int low=1,high=n,mid,i;
	mid=(low+high)/2;
	while(low<=high){		
		if(strcmp(w[mid].s,a)>0)  high=mid-1;					
		else low=mid+1;
		
		mid=(low+high)/2;
	}
	if(strcmp(w[mid].s,a)!=0) return 0;
	return mid;
}

int compare(const void *a,const void *b)
{
	return strcmp((*(struct word *)a).s,(*(struct word *)b).s);
}

int judge(char c)
{
	if(c>='A'&&c<='Z') return 2;
	else if(c>='a'&&c<='z') return 1;
	else return 0;
}

int get(char a[],int k)
{
	int i=k;
	while(a[i]!='\0'){
		if(judge(a[i])==0)	i++;
		else break;
	}
	if(a[i]=='\0') return -1;
	return i;
}

void clear(char b[])
{
	int i;
	for(i=0;i<98;i++)
	b[i]='\0';
}

