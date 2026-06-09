#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
struct node {
    char s[1000];
    int num;
}w[10000];                          
int cmpfuc(const void* a, const void* b)
{
    struct node* c=(struct node*)a; 
    struct node* d=(struct node*)b;
    return strcmp(c->s, d->s);          
}
	

int main()
{
    FILE* in=fopen("article.txt","r");
    char str[1000],c;
    int cnt=0,k=0,i=0;	
    while((c=fgetc(in))!=EOF) 
    str[cnt++]=c;                 
    cnt=0;
    for(i=0;i<strlen(str);i++)
    {
    if(!isalpha(str[i])){
    cnt++;                      
    k=0;                      
    }
    if(isalpha(str[i])) 
	w[cnt].s[k++]=tolower(str[i]); 
    }
    qsort(w,cnt,sizeof(w[0]),cmpfuc);   

    for(i=0;i<cnt;i++)
        if(strlen(w[i].s)) 
		w[i].num=1;   
    for(i=0;i<cnt;i++)
        if(strcmp(w[i].s, w[i+1].s)==0)
        {
        w[i+1].num+=w[i].num;       
        w[i].num=0;
        }
    for(i=0;i<cnt;i++)
    if(w[i].num!=0)
    printf("%s %d\n",w[i].s,w[i].num);  		
    return 0;
}


