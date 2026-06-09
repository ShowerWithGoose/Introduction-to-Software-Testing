#include<stdio.h>
#include<string.h>
struct node{ 
	char word[200]; 
	int rate;     
};
typedef struct node P;
char s[200],tran[200],ch;
int i,j,k,count=0;
P a[1000];
int cmp(const void*p1,const void*p2);
void Del(FILE *fp1);//ШЅжи  
int main()
{	
	FILE *fp1 = fopen("article.txt","r");
	char c;
    int i = 0;
    while ((c = fgetc(fp1)) != EOF) 
        s[i++] = c;  
	for(i=0;i<strlen(s);i++)
	{
		if(isalpha(s[i])) s[i]=tolower(s[i]);  
	}               

	for(i=0;i<strlen(s);i++)
	{
		if(isalpha(s[i]))  
		{
			for(j=i;j<strlen(s);j++)
				if(!isalpha(s[j])) 
					break;
			memset(tran,0,sizeof(tran));
			for(k=0;k<j-i;k++)
				tran[k]=s[i+k];   
			strcpy(a[count].word,tran); 
			count++;
			i=j;
		}
		else	continue;
	}
	qsort(a,count,sizeof(P),cmp); 
	for(i=0;i<count;i++) a[i].rate=1;
	
	Del(fp1);	 
	for(i=0;i<count;i++)
		if(a[i].rate!=0)
		printf("%s %d\n",a[i].word,a[i].rate);

}
int cmp(const void*p1,const void*p2) 
{
	struct node *a=(struct node*)p1;
	struct node *b=(struct node*)p2;
	return strcmp(a->word,b->word);
}

void Del(FILE *fp1)
{
	for(i=0;i<count;i++)
		if(strcmp(a[i].word,a[i+1].word)==0)  
		{
			a[i+1].rate+=a[i].rate; 
			a[i].rate=0;
		}
//	qsort(a,count,sizeof(P),cmp);                    /?????????????
}


