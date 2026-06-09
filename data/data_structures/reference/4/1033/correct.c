#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void tolow(char *s,char** arr,int *ret)
{
    int i,j,k;
    int total=*ret;
    i=0;j=0;
    while(s[i])
    {
        if(isalpha(s[i])) s[j++]=s[i++];//只存字母
        else
        {
           s[j]=0;
           for(k=0;s[k];k++)
           {
               if(s[k]>='A'&&s[k]<='Z')
               s[k]=s[k]-'A'+'a';
           }
           arr[total]=(char*)malloc(sizeof(char)*(strlen(s)+1));
           strcpy(arr[total],s);
           j=0;
           i++;
           total++;
        }
    }
    s[j]=0;
    for(k=0;s[k];k++)
    {
        if(s[k]>='A'&&s[k]<='Z')
        s[k]=s[k]-'A'+'a';
    }
    arr[total]=(char*)malloc(sizeof(char)*(strlen(s)+1));
    strcpy(arr[total],s);
    total++;
    *ret=total;
    return;
}

void swap(char** a,char**b)//交换指针
{
    char* c=*a;
    *a=*b;
    *b=c;
    return ;
}


void bubble_sort(char** arr,int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(strcmp(arr[j],arr[j+1])>0)
            {
                swap(arr+j,arr+j+1);
            }
        }
    }
    return ;
}

int main()
{
    char buff[1000];
    char* arr[1000];
    int total=0,i,j,cnt;
    FILE *in;
    in=fopen("article.txt","r");
    while(fscanf(in,"%s",buff)>0)//读不进来
    {
        tolow(buff,arr,&total);

    }
    bubble_sort(arr,total);
    for(i=0;i<total;)
    {
        cnt=1;
        if(arr[i][0]==0)
        {
            i++;
            continue;
        }
        for(j=i+1;j<total&&strcmp(arr[i],arr[j])==0;j++,cnt++);
        printf("%s %d\n",arr[i],cnt);
        i=j;
    }
    for(i=0;i<total;i++)
    {
        free(arr[i]);
    }
    fclose(in);
    return 0;
}



