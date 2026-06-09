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
                if((arr[i-1]>='a')&&(arr[i-1]<'z')&&(arr[i+1]>'a')&&(arr[i+1]<='z')) // @@ [Error: The condition uses '<' and '>' incorrectly; should be '<=' and '>=' to include the endpoints. Also, the logic for expansion is flawed; it should check that both characters are in the same range and that the second is greater than the first.]
                {
                    char c=0;
                    c=arr[i-1]-'a'+'b'; // @@ [Error: This calculation is incorrect. It should start from arr[i-1] and increment by 1 each step, not convert to 'b'.]
                    x=c;
                    y=arr[i+1];
                    while(x<=y-1)
                    {
                        printf("%c",c);
                        c=c-'a'+'b'; // @@ [Error: This increment logic is wrong. It should be c = c + 1 or similar.]
                        x=c;
                    }
                }
                else if((arr[i-1]>='A')&&(arr[i-1]<'Z')&&(arr[i+1]>'A')&&(arr[i+1]<='Z')) // @@ [Error: Same issue as above with range checks and expansion logic.]
            
                {
                    char d=0;
                    d=arr[i-1]-'a'+'b'; // @@ [Error: Incorrect calculation; should use 'A' and 'B' for uppercase, not 'a' and 'b'.]
                    x=d;
                    y=arr[i+1];
                    while(x<=y-1)
                    {
                        
                        printf("%c",d);
                        d=d-'a'+'b'; // @@ [Error: Wrong increment logic.]
                        x=d;
                    }
                }
                else if(arr[i-1]>='0'&&arr[i-1]<'9'&&arr[i+1]>'0'&&arr[i+1]<='9') // @@ [Error: Same range check issue.]
            
                {
                    char f=0;
                
                    f=arr[i-1]+'b'-'a'; // @@ [Error: Incorrect calculation for digits; should use '0' and '1' as base.]
                            x=f;
                    y=arr[i+1];
                    while(x<=y-1)
                    {
                        printf("%c",f);
                        f=f+'b'-'a'; // @@ [Error: Wrong increment logic.]
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