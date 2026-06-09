#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct node {
    char s[1024];
    int num;

}p[2048];                           

int cmpfuc(const void* a, const void* b)
{
    struct node* c = (struct node*)a; 
    struct node* d = (struct node*)b;
    return strcmp(c->s, d->s);          
}
int main()
{
    FILE*fp;
	fp=fopen("article.txt","r");
    char str[1000];
    char tmp[1000];
    char c;
    int cnt=0,i=0,j=0;
    while ((c=fgetc(fp))!=EOF)
	{
        str[cnt++] = c;                
    }
    for(i=0;i<strlen(str);i++)
    {
    if(isalpha(str[i]))
	str[i]=tolower(str[i]); 
    }

    int k=0;
    for (i=0; i<strlen(str); i++)
    {
        if (isalpha(str[i]))          
        {
        	for(j=i;j<strlen(str);j++)
            {
             if(!isalpha(str[j])) 
            {
            break;
            }
            }
            memset(tmp,0,sizeof(tmp));
            for(k=0;k<j-i;k++)
            {
            tmp[k]=str[i+k]; 
            }
            strcpy(p[cnt].s,tmp); 
            cnt++;
            i=j;
        }
        else continue;
    }
        	
    qsort(p, cnt, sizeof(p[0]), cmpfuc);    

    for(i=0; i<cnt; i++)
        if(strlen(p[i].s)) p[i].num=1; 
    for(i=0; i<cnt; i++)
        if (!strcmp(p[i].s, p[i+1].s))
        {
            p[i+1].num+=p[i].num;       
            p[i].num =0;
        }
	   
    for(i=0; i < cnt; i++)
        if (p[i].num != 0)
            printf("%s %d\n", p[i].s, p[i].num);    
    return 0;
}

