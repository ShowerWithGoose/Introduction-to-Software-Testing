#include<stdio.h>
#include<string.h>
int main()
{
    char s[100],c[100];
    scanf("%s",&s);
    int i,j,k,w,temp;
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='.')
        {
            temp=i;
            k=1;
            if(i!=1)
            {
                c[0]=s[0];
                c[1]='.';
                for(j=2;j<strlen(s);j++)
                {
                    c[j]=s[k];
                    k++;
                    if(s[k]=='.')
                    k++;
                }
                w=temp-1;
                printf("%se%d",c,w);
                return 0;
            }
            else if(i==1)
            {
                if(s[0]!='0')
                {
                   printf("%se0",s);
                   return 0;
                }
            //小数点为0；
            else
            {
                for(k=2;k<strlen(s);k++)
                {
                    if(s[k]!='0')
                    break;
                } 
                temp=k;
                k++;
                if(k==strlen(s))
                c[0]=s[k-1];
                else
                { 
                    c[0]=s[k-1];
                    c[1]='.';
                    for(j=2;j<=strlen(s)-temp+1;j++)
                    {
                     
                        c[j]=s[k];
                         k++;
                    }
                }
                printf("%se-%d",c,temp-1);
                return 0;
            }
            }
        }
    }
    if(strlen(s)==1)
    printf("%se0",s);
    else
    {
        c[0]=s[0];
        c[1]='.';
        for(j=2,i=1;i<strlen(s);i++,j++)
        {
            c[j]=s[i];
        }
        printf("%se%d",c,i-1);
    }
    
    return 0;
}
