#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define tolower(c)  (c>='A'&&c<='Z' ? 'a'-'A'+c:c)

typedef struct count
{
    char word[205];
    int cnt;/* data */
}count;

int cmp(const void *p1,const void *p2)
{
    return -strcmp(((count*)p1)->word , ((count*)p2)->word);
}

count list[13000];
char r[50005],w[1300];

int main()
{
    
    int len=0;
    FILE *in;
    setbuf(stdout, 0);
    in=fopen("article.txt","r");
    while( fgets(r,50000,in)!=NULL )
    {
        int i=0,j=0,k=0;
        for(i=0;r[i]!='\0';i++)
        {
            if(isalpha(r[i]))
            {
                while(isalpha(r[i]))
                {
                    w[j]=tolower(r[i]);
                    j++;
                    i++;
                }
                for(k=0;k<=len;k++)
                {
                    if(strcmp(w,list[k].word)==0)
                    {
                        list[k].cnt++;
                        break;
                    }
                }
                if(k>len)
                {
                    strcpy(list[len].word,w);
                    list[len].cnt++;
                    len++;
                }
                j=0;
                memset(w,'\0',1270);
            }
        }
    }
    qsort(list,len,sizeof (count),cmp);
    while(len--)
    {
        printf("%s %d\n",list[len].word,list[len].cnt);
    }
    fclose(in);
    return 0;

}



