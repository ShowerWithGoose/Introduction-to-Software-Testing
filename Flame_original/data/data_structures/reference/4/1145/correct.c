#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define M 1000
char sr[M];
int cmp(const void *p,const void *q)
{
    return strcmp(p,q);
}
void fileread(){
    FILE*in=fopen("article.txt","r");
    if (in==NULL)
    {
        perror("open file failed:");
        return;
    }
    fclose(in);
}
int main()
{
    int i=0;
    int j=0;
    char shuchu[M][M];
    fileread();
    FILE *fp;
    fp=fopen("article.txt","r");
    while(fgets(sr,M,fp)!=NULL)
    {
        
        while(sr[i]!='\0')
        {
            sr[i]=tolower(sr[i]);
            i++;
        }
        i=0;
        while(sr[i]!='\0')
        {
            if(islower(sr[i]))
            {
                int l=0;
                while(islower(sr[i]))
                {
                    shuchu[j][l]=sr[i];
                    i++;
                    l++;
                }
                j++;
            }
            i++;
        }
        i=0;
    }
    qsort(shuchu,j,sizeof(shuchu[0]),cmp);
    int count=1;
    for(i=0; i<j; i++)
    {
        if(strcmp(shuchu[i],shuchu[i+1])==0)
            count++;
        else
        {
            printf("%s %d\n",shuchu[i],count);
            count=1;
        }
    }
    fclose(fp);
    return 0;
}


