#include<stdio.h>
#include<string.h>
char s[10000000]="";
int main()
{
    gets(s);
    int len=strlen(s);

    int point;
    for( point=0;s[point]!='\0';point++)
    {
        if(s[point]=='.')
            break;

    }
    if(point==1&&s[0]=='0')
    {
        int i=point+1;
        while(s[i]=='0')
        {

            i++;
        }
        int k;
        for(k=len-1;s[k]=='0';k--);
        if(k==i)
            printf("%ce-%d",s[k],k-point);
        else
        {
            printf("%c",s[i]);
            printf(".");
            for(int p=i+1;p<=k;p++)
                printf("%c",s[p]);
            printf("e-%d",i-point);
        }

    }
    else if(point==1&&s[0]!='0')
    {
        int k;
        for(k=len-1;s[k]=='0';k--);

            for(int i=0;i<=k;i++)
                printf("%c",s[i]);
            printf("e0");
            printf("\n");


    }
    else
    {
        int point;
        for( point=0;s[point]!='\0';point++)
        {
            if(s[point]=='.')
                break;

        }
        if(point==len)
        {
            int j;
            for(j=len-1;s[j]=='0';j--);
            printf("%c.",s[0]);

            for(int p=1;p<=j;p++)
            {
                printf("%c",s[p]);
            }
            printf("e%d",len-1);

        }
        else{
                    int k;
        for(k=len-1;s[k]=='0';k--);
        printf("%c.",s[0]);
        for(int p=1;p<point;p++)
        {
            printf("%c",s[p]);
        }
        for(int p=point+1;p<=k;p++)
            printf("%c",s[p]);
        printf("e%d",point-1);
        }


    }
    return 0;

}


