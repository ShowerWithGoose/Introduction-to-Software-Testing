#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char buf[BUFSIZ];
#define N 100
struct M
{
    char word[30];
    int x;
}; 
int c0;
char c;
int i,j,k,f,m,n;
int count[500];
#define people M
void qsort(
			void *base,//数组起始地址，通常为数组名 
			size_t num,//数组中元素的个数 
			size_t size,//数组中每个元素的大小（字节数） 
			int(*compare)(const void*,const void*));//指向比较函数的函数指针 			
int compare (const void* a,const void* b)
{
    struct people aa=*(struct people*)a;
    struct people bb=*(struct people*)b;
    return strcmp(aa.word,bb.word);
	//return strcmp((*(people*)a).name,((people*)b).name);
    //char* c=*(char**)a;
    //char* d=*(char**)b;
}
int main()
{
    FILE *in; 
	struct M a[500];
    in=fopen("article.txt","r");
    if(in == NULL){
	      printf("Can't open file ");
	      return 1;
	}
    while((c=fgetc(in))!=EOF)
    {
    //	printf("jtjtjj");
    	//c=c0;
    //	printf("%c",c);
        if(c>='a' && c<='z')
        {
            a[i].word[j]=c;
            j++;
            f=1;
            //printf("%c",c);
        }
        else if(c>='A'&&c<='Z')
        {
            a[i].word[j]=tolower(c);
            j++;
            f=1;
        }
        else
        {
            
            j=0;
            if(f==1)
				i++;
            f=0;//这标志着 
        }
    }
    //printf("%d\n",i);
    qsort(a,i,sizeof(a[0]),compare);
//    for(i=0;i<=20;i++)
//        puts(a[i].word);
	for(k=0;k<i;)
	{
		printf("%s ",a[k].word);
		n=1;
		while(strcmp(a[k].word,a[k+n].word)==0)
		{
			n++;
		}
		printf("%d\n",n);
		k=k+n;
	/*	if(k==0)
		{
			printf("%s",a[0].word);
			continue;
		}	
		if(strcmp(a[k].word,a[k-1].word)==0)
			count[m]++;
		else
		{
			printf("%s %d\n",a[k].word,count[m]+1);
			m++;
		}	*/	
	}
}

