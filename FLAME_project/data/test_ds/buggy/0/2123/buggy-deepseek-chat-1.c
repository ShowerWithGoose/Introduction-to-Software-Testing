/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include <stdio.h>
#include <string.h>
int main()
{
    int n,x,y;
    char arr[1000];
    fgets(arr); // @@ [Error: fgets requires three arguments: buffer, size, and stream. Should be fgets(arr, sizeof(arr), stdin)]
    n=strlen(arr);
    for(int i=0;i<n;i++)
    {
        if(arr[i]!='-')
        {
            printf("%c",arr[i]);
        }
        else if(arr[i]=='-')
        {    
                if((arr[i-1]>='a')&&(arr[i-1]<'z')&&(arr[i+1]>'a')&&(arr[i+1]<='z')) // @@ [Error: Condition should check arr[i-1] < 'z' and arr[i+1] > 'a' with inclusive bounds; also missing check that both characters are same type and arr[i+1] > arr[i-1]]
                {
                    char c=0;
                    c=arr[i-1]-'a'+'b'; // @@ [Error: Incorrect calculation; should start from arr[i-1]+1, not using 'b']
                    x=c;
                    y=arr[i+1];
                    while(x<=y-1)
                    {
                        printf("%c",c);
                        c=c-'a'+'b'; // @@ [Error: Incorrect increment; should be c = c + 1]
                        x=c;
                    }
                }
                else if((arr[i-1]>='A')&&(arr[i-1]<'Z')&&(arr[i+1]>'A')&&(arr[i+1]<='Z')) // @@ [Error: Same issue as above for uppercase]
            
                {
                    char d=0;
                    d=arr[i-1]-'a'+'b'; // @@ [Error: Should use 'A' instead of 'a' for uppercase]
                    x=d;
                    y=arr[i+1];
                    while(x<=y-1)
                    {
                        
                        printf("%c",d);
                        d=d-'a'+'b'; // @@ [Error: Should be d = d + 1]
                        x=d;
                    }
                }
                else if(arr[i-1]>='0'&&arr[i-1]<'9'&&arr[i+1]>'0'&&arr[i+1]<='9') // @@ [Error: Same bound issues for digits]
            
                {
                    char f=0;
                
                    f=arr[i-1]+'b'-'a'; // @@ [Error: Incorrect calculation; should be arr[i-1]+1]
                            x=f;
                    y=arr[i+1];
                    while(x<=y-1)
                    {
                        printf("%c",f);
                        f=f+'b'-'a'; // @@ [Error: Should be f = f + 1]
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