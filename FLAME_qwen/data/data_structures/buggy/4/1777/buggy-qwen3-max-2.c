#include <math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define tolower(c)     (c>=‘A’&&c<=‘Z’?‘a’-’A’+ c : c) // @@ [Using non-ASCII single quotes ‘ and ’ instead of standard ASCII single quotes ' causes a compilation error.]
char line[200]={};
int jline[200]={};
typedef struct
{
    char name[20];
    int num;
}letter;
letter a[999];
int cmp(const void*e1,const void*e2)
{
    letter*e=(letter*)e1,*f=(letter*)e2;
    if(strcmp(e->name,f->name)<0)return -1;
    else return 1; // @@ [The comparison function for qsort must return 0 when elements are equal. This implementation never returns 0, leading to undefined behavior in sorting, though this is a logical error, not the cause of the compilation error. However, the primary compilation error is due to the non-ASCII quotes above.]
}
int main()
{
    for(int i=0;i<999;i++)
    {
        a[i].num=0;
    }
    
    FILE*in,*out;
    in=fopen("article.txt","r");
    int sum=0;
    while(fscanf(in,"%s",line)!=EOF)
    {
        for(int i=0;i<200;i++)
        {
            jline[i]=0;
        }
        int jk=0;
        for(int i=0;line[i]!='\0';i++)
        {
            if(line[i]<='z'&&line[i]>='a')
            {
                jk++;
            }
            else if(line[i]<='Z'&&line[i]>='A')
            {
                line[i]=line[i]-'A'+'a';jk++;
            }
            else
            {
                jline[i]=1;
            }
        }
        int rr=0;
    
        for(int i=0;line[i]!='\0';i++)
        {
            if(jline[i]!=1)
            {
                line[rr++]=line[i];
            }
        }
        line[rr]='\0';
        
        int judge=0;
        for(int i=0;i<sum;i++)
        {
            if(strcmp(a[i].name,line)==0)
            {
                judge=1;a[i].num++;break;
            }
        }
        if(judge==0&&jk!=0)
        {
            int t;
            for(t=0;line[t]!='\0';t++)
            {
                a[sum].name[t]=line[t];
            }
            a[sum].name[t]='\0';
            a[sum].num=1;
            sum++;
        }
    }
    qsort(a,sum,sizeof(letter),cmp);
    
    for(int i=0;i<sum;i++)
    {
        printf("%s %d\n",a[i].name,a[i].num);
    }
    

    
    
    
    return 0;
}