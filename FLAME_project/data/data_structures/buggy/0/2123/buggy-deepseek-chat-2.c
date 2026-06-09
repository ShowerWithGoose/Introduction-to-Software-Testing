/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include <stdio.h>
#include <string.h>
int main()
{
    int n,x,y;
    char arr[1000];
    fgets(arr); // @@ [Error: fgets requires three arguments: buffer, size, and stream. Should be fgets(arr, sizeof(arr), stdin).]
    n=strlen(arr);
    for(int i=0;i<n;i++)
    {
        if(arr[i]!='-')
        {
            printf("%c",arr[i]);
        }
        else if(arr[i]=='-')
        {    
                if((arr[i-1]>='a')&&(arr[i-1]<'z')&&(arr[i+1]>'a')&&(arr[i+1]<='z')) // @@ [Error: Logic error. Condition should check arr[i-1] < arr[i+1] and both within same range. Also, using '<' instead of '<=' for the upper bound excludes 'z'.]
                {
                    char c=0;
                    c=arr[i-1]-'a'+'b'; // @@ [Error: Incorrect calculation. Should start from arr[i-1]+1, not this formula.]
                    x=c;
                    y=arr[i+1];
                    while(x<=y-1)
                    {
                        printf("%c",c);
                        c=c-'a'+'b'; // @@ [Error: Incorrect increment. Should be c = c + 1 or similar.]
                        x=c;
                    }
                }
                else if((arr[i-1]>='A')&&(arr[i-1]<'Z')&&(arr[i+1]>'A')&&(arr[i+1]<='Z')) // @@ [Error: Same logic error as above; should check arr[i-1] < arr[i+1] and use proper bounds.]
            
                {
                    char d=0;
                    d=arr[i-1]-'a'+'b'; // @@ [Error: Incorrect calculation for uppercase. Should use 'A' and 'B' instead of 'a' and 'b'.]
                    x=d;
                    y=arr[i+1];
                    while(x<=y-1)
                    {
                        
                        printf("%c",d);
                        d=d-'a'+'b'; // @@ [Error: Incorrect increment for uppercase.]
                        x=d;
                    }
                }
                else if(arr[i-1]>='0'&&arr[i-1]<'9'&&arr[i+1]>'0'&&arr[i+1]<='9') // @@ [Error: Same logic error; should check arr[i-1] < arr[i+1].]
            
                {
                    char f=0;
                
                    f=arr[i-1]+'b'-'a'; // @@ [Error: Incorrect calculation for digits. Should use '1' and '0' or simply f = arr[i-1] + 1.]
                            x=f;
                    y=arr[i+1];
                    while(x<=y-1)
                    {
                        printf("%c",f);
                        f=f+'b'-'a'; // @@ [Error: Incorrect increment for digits.]
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