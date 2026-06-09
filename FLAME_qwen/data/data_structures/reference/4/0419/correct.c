#include <stdio.h>
#include <string.h>
char arr[100][1024],brr[100][100],crr[100];
int main()
{
    FILE* Read=fopen("article.txt","r");
    int len=0,len1=0;
    while(fgets(arr[len],1024,Read)!=NULL)len++;


    int i,j;
    for(j=0;j<len;j++)
    {
        for(i=0;i<strlen(arr[j]);i++)
        {
            if(arr[j][i]>='A'&&arr[j][i]<='Z')
            arr[j][i]=arr[j][i]+32;
        }

    }
    int len2=0;
    for(j=0;j<len;j++)
    {
        for(i=0;i<strlen(arr[j]);i++)
        {
            if(arr[j][i]>='a'&&arr[j][i]<='z')
            {
                len2=0;
                brr[len1][len2]=arr[j][i];
                i++;len2++;
                while(arr[j][i]>='a'&&arr[j][i]<='z')
                {
                    brr[len1][len2]=arr[j][i];
                    i++;len2++;
                }
                len1++;
            }
        }
    }


    for(i=0;i<len1-1;i++)
    {
        for(j=i+1;j<=len1-1;j++)
        {
            if(strcmp(brr[i],brr[j])>0)
            {
                strcpy(crr,brr[j]);
                strcpy(brr[j],brr[i]);
                strcpy(brr[i],crr);


            }
        }

    }
    int drr[50]={0},n=0;
    for(i=0;i<len1-1;i++)
    {
        if(brr[i][0]!='A')
        {
            for(j=i+1;j<len1;j++)
        {
            if(strcmp(brr[i],brr[j])==0)
            {
                drr[n]++;
                brr[j][0]='A';
            }
        }
        n++;
        }


    }
    n=0;
    for(i=0;i<len1;i++)
    {
        if(brr[i][0]!='A')
        {
            printf("%s %d",brr[i],drr[n]+1);
            n++;printf("\n");

        }

    }






    fclose(Read);
    Read=NULL;
    return 0;
}


