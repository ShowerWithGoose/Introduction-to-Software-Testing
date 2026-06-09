/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include <stdio.h>
#include <string.h>
int main()
{
    int n,x,y;
    char arr[1000];
    fgets(arr); // @@ [fgets requires three arguments: buffer, size, and stream; should be fgets(arr, 1000, stdin)]
    n=strlen(arr);
    for(int i=0;i<n;i++)
    {
        if(arr[i]!='-')
        {
            printf("%c",arr[i]);
        }
        else if(arr[i]=='-')
        {    
                if((arr[i-1]>='a')&&(arr[i-1]<'z')&&(arr[i+1]>'a')&&(arr[i+1]<='z'))
                {
                    char c=0;
                    c=arr[i-1]-'a'+'b'; // @@ [Incorrect calculation; should be arr[i-1]+1 to get the next character]
                    x=c;
                    y=arr[i+1];
                    while(x<=y-1)
                    {
                        printf("%c",c);
                        c=c-'a'+'b'; // @@ [Incorrect increment; should be c+1 to get the next character]
                        x=c;
                    }
                }
                else if((arr[i-1]>='A')&&(arr[i-1]<'Z')&&(arr[i+1]>'A')&&(arr[i+1]<='Z'))
            
                {
                    char d=0;
                    d=arr[i-1]-'a'+'b'; // @@ [Incorrect calculation; should be arr[i-1]+1, and uses lowercase 'a' instead of 'A']
                    x=d;
                    y=arr[i+1];
                    while(x<=y-1)
                    {
                        
                        printf("%c",d);
                        d=d-'a'+'b'; // @@ [Incorrect increment; should be d+1, and uses lowercase 'a' instead of 'A']
                        x=d;
                    }
                }
                else if(arr[i-1]>='0'&&arr[i-1]<'9'&&arr[i+1]>'0'&&arr[i+1]<='9')
            
                {
                    char f=0;
                
                    f=arr[i-1]+'b'-'a'; // @@ [Incorrect calculation; should be arr[i-1]+1]
                            x=f;
                    y=arr[i+1];
                    while(x<=y-1)
                    {
                        printf("%c",f);
                        f=f+'b'-'a'; // @@ [Incorrect increment; should be f+1]
                        x=f;
                    }
                }
                else
                {
                    printf("-");
                }
            
        }
    }
    return 0;
}