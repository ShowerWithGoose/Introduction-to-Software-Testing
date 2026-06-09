/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include <stdio.h>
#include <string.h>
int main()
{
    int n,x,y;
    char arr[1000];
    fgets(arr); // @@ fgets requires three arguments: fgets(arr, sizeof(arr), stdin); also, fgets includes the newline character, which may affect logic
    n=strlen(arr);
    for(int i=0;i<n;i++)
    {
        if(arr[i]!='-')
        {
            printf("%c",arr[i]);
        }
        else if(arr[i]=='-')
        {    
                if((arr[i-1]>='a')&&(arr[i-1]<'z')&&(arr[i+1]>'a')&&(arr[i+1]<='z')) // @@ Condition should check arr[i-1] < arr[i+1] and both within range; also missing handling for 'z' and 'a' boundaries; the logic for increment is incorrect
                {
                    char c=0;
                    c=arr[i-1]-'a'+'b'; // @@ Incorrect calculation; should start from arr[i-1]+1, not this expression
                    x=c;
                    y=arr[i+1];
                    while(x<=y-1) // @@ Loop condition and increment logic are flawed; should use simple char increment
                    {
                        printf("%c",c);
                        c=c-'a'+'b'; // @@ Incorrect increment; should be c = c + 1
                        x=c;
                    }
                }
                else if((arr[i-1]>='A')&&(arr[i-1]<'Z')&&(arr[i+1]>'A')&&(arr[i+1]<='Z')) // @@ Same issues as above for uppercase
            
                {
                    char d=0;
                    d=arr[i-1]-'a'+'b'; // @@ Should use 'A' and 'B' for uppercase, not 'a' and 'b'
                    x=d;
                    y=arr[i+1];
                    while(x<=y-1)
                    {
                        
                        printf("%c",d);
                        d=d-'a'+'b'; // @@ Incorrect increment
                        x=d;
                    }
                }
                else if(arr[i-1]>='0'&&arr[i-1]<'9'&&arr[i+1]>'0'&&arr[i+1]<='9') // @@ Same issues for digits
            
                {
                    char f=0;
                
                    f=arr[i-1]+'b'-'a'; // @@ Incorrect calculation; should start from arr[i-1]+1
                            x=f;
                    y=arr[i+1];
                    while(x<=y-1)
                    {
                        printf("%c",f);
                        f=f+'b'-'a'; // @@ Incorrect increment
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