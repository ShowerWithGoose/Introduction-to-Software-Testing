/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include <stdio.h>
#include <string.h>
int main()
{
    int n,x,y;
    char arr[1000];
    fgets(arr); // @@ [fgets requires three arguments: buffer, size, and stream. Correct usage: fgets(arr, sizeof(arr), stdin);]
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
                    c=arr[i-1]-'a'+'b';
                    x=c;
                    y=arr[i+1];
                    while(x<=y-1)
                    {
                        printf("%c",c);
                        c=c-'a'+'b';
                        x=c;
                    }
                }
                else if((arr[i-1]>='A')&&(arr[i-1]<'Z')&&(arr[i+1]>'A')&&(arr[i+1]<='Z'))
            
                {
                    char d=0;
                    d=arr[i-1]-'a'+'b'; // @@ [Should use 'A' instead of 'a' for uppercase letters: d = arr[i-1] - 'A' + 'B';]
                    x=d;
                    y=arr[i+1];
                    while(x<=y-1)
                    {
                        
                        printf("%c",d);
                        d=d-'a'+'b'; // @@ [Same error: should use 'A' for uppercase: d = d - 'A' + 'B';]
                        x=d;
                    }
                }
                else if(arr[i-1]>='0'&&arr[i-1]<'9'&&arr[i+1]>'0'&&arr[i+1]<='9')
            
                {
                    char f=0;
                
                    f=arr[i-1]+'b'-'a'; // @@ [Incorrect logic for digits: should be f = arr[i-1] + 1; since 'b'-'a' is 1 but applied to digits incorrectly]
                            x=f;
                    y=arr[i+1];
                    while(x<=y-1)
                    {
                        printf("%c",f);
                        f=f+'b'-'a'; // @@ [Same issue: should increment by 1 directly: f++;]
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