#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
struct wordlist 
{
    char s[20];
    int num;

}word[500];                          

int cmp(const void* a, const void* b)
{
    struct wordlist* c = (struct wordlist*)a; 
    struct wordlist* d = (struct wordlist*)b;
    return strcmp(c->s, d->s);          
}
int main()
{
    FILE* fp=fopen("article.txt","r");
    char str[10000],c;
    int m=0,k=0;
    while((c=fgetc(fp))!=EOF) str[m++]=c;               
    m=0;
    for(int i=0;i<strlen(str);i++)
    {
    	if(!isalpha(str[i]))
    	{
    		m++;
    		k=0;
		}
        else word[m].s[k++]=tolower(str[i]); 
    }
    qsort(word,m,sizeof(word[0]),cmp);
    for(int i=0;i<m;i++)
    {
    	if(strlen(word[i].s)) word[i].num=1;   
	}
    for(int i=0;i<m;i++)
    {
    	if(strcmp(word[i].s,word[i+1].s)==0)
        {
            word[i+1].num+=word[i].num;      
            word[i].num=0;
        }
	}
    for(int i=0;i<=m;i++)
    {
    	if(word[i].num!=0) printf("%s %d\n",word[i].s,word[i].num);
	}
    return 0;
}


