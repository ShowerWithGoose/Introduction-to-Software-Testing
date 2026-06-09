#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,k,move,len;
    char a[1000],b;
    scanf("%s",a);
    len=strlen(a);
    for(i=0;i<=len-1;i++)
    {
        
        if(a[i+1]=='-')
        {
            if((a[i]>='a'&&a[i]<='z')&&(a[i+2]<='z'&&a[i+2]>='a')&&(a[i+2]>a[i]))
            {
                move=a[i+2]-a[i]-1;
                if(move==0)
               {
                    for(j=i+1;j<=len-1;j++)
                    {
                        a[j]=a[j+1];
                    }
                    
               }
                else {
                    for(j=len-1;j>i+1;j--)
                     {
                        a[j+move-1]=a[j];
                     }
                    for(k=1;k<=move;k++)
                    {
                        b=a[i]+k;
                        a[i+k]=b;
                    }
                    len=strlen(a);
                    }
            }
            else if((a[i]>='A'&&a[i]<='Z')&&(a[i+2]<='Z'&&a[i+2]>='A')&&(a[i+2]>a[i]))
            {
                move=a[i+2]-a[i]-1;
                if(move==0)
               {
                    for(j=i+1;j<=len-1;j++)
                    {
                        a[j]=a[j+1];
                    }
                    
               }
                else {
                    for(j=len-1;j>i+1;j--)
                     {
                        a[j+move-1]=a[j];
                     }
                    for(k=1;k<=move;k++)
                    {
                        b=a[i]+k;
                        a[i+k]=b;
                    }
                    len=strlen(a);
                    }
            }
            else if((a[i]>='0'&&a[i]<='9')&&(a[i+2]<='9'&&a[i+2]>='0')&&(a[i+2]>a[i]))
            {
                move=a[i+2]-a[i]-1;
                if(move==0)
               {
                    for(j=i+1;j<=len-1;j++)
                    {
                        a[j]=a[j+1];
                    }
                    
               }
                else {
                    for(j=len-1;j>i+1;j--)
                     {
                        a[j+move-1]=a[j];
                     }
                    for(k=1;k<=move;k++)
                    {
                        b=a[i]+k;
                        a[i+k]=b;
                    }
                    len=strlen(a);
                    }
            }
        }
    }
    printf("%s",a);
    return 0;
}


