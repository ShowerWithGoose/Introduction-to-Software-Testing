#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct word
{
    char word[1000];
    int num;
} m[1000];
int n;
int cmp(const void *p,const void *q)
{
    struct word *pp=(struct word*)p,*qq=(struct word *)q;
    return strcmp(pp->word,qq->word);
}
void ser(char *q)
{
    int i;
    for(i=0; i<n; i++)
        if(!strcmp(m[i].word,q))
        {
            m[i].num++;
            return;
        }
    strcpy(m[n].word,q);
    m[n].num++;
    n++;
}
void fun()
{
    FILE *in;
    in=fopen("article.txt","r");
    char s[1024],ch1[1000];
    while(fgets(s,1024,in)!=NULL)
    {
        int k=0,m=0;
        while(s[k]!='\0')
        {
            int f=0;
            for(; !isalpha(s[k]); k++)
                if(s[k]=='\0')
                {
                    f=1;
                    break;
                }
            if(f==1)
                break;
            m=0;
            for(; isalpha(s[k]); k++)
            {
                ch1[m++]=s[k]<='z'&&s[k]>='a'?s[k]:s[k]-'A'+'a';
            }
            ch1[m]='\0';
            ser(ch1);
        }
    }
}
int main()
{
    fun();
    int i;
    qsort(m,n,sizeof(m[0]),cmp);
    for(i=0; i<n; i++)
        printf("%s %d\n",m[i].word,m[i].num);
    return 0;
}



