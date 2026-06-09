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
                if((arr[i-1]>='a')&&(arr[i-1]<'z')&&(arr[i+1]>'a')&&(arr[i+1]<='z')) // @@ [Error: The condition uses arr[i-1] and arr[i+1] without checking if i-1 and i+1 are within bounds. Also, the logic for expansion is incorrect; it should include the starting character and use proper character arithmetic.]
                {
                    char c=0;
                    c=arr[i-1]-'a'+'b'; // @@ [Error: Incorrect character calculation. Should be arr[i-1]+1 to get the next character.]
                    x=c;
                    y=arr[i+1];
                    while(x<=y-1) // @@ [Error: Loop condition and increment logic are flawed. Should print characters from arr[i-1]+1 to arr[i+1]-1.]
                    {
                        printf("%c",c);
                        c=c-'a'+'b'; // @@ [Error: Incorrect increment. Should be c++ or c=c+1.]
                        x=c;
                    }
                }
                else if((arr[i-1]>='A')&&(arr[i-1]<'Z')&&(arr[i+1]>'A')&&(arr[i+1]<='Z')) // @@ [Error: Same bounds and logic issues as above.]
            
                {
                    char d=0;
                    d=arr[i-1]-'a'+'b'; // @@ [Error: Incorrect character calculation for uppercase. Should be arr[i-1]+1.]
                    x=d;
                    y=arr[i+1];
                    while(x<=y-1) // @@ [Error: Same loop logic issues.]
                    {
                        
                        printf("%c",d);
                        d=d-'a'+'b'; // @@ [Error: Incorrect increment. Should be d++ or d=d+1.]
                        x=d;
                    }
                }
                else if(arr[i-1]>='0'&&arr[i-1]<'9'&&arr[i+1]>'0'&&arr[i+1]<='9') // @@ [Error: Same bounds issues. Also, condition should allow arr[i-1] < arr[i+1] for expansion.]
            
                {
                    char f=0;
                
                    f=arr[i-1]+'b'-'a'; // @@ [Error: Incorrect character calculation. Should be arr[i-1]+1.]
                            x=f;
                    y=arr[i+1];
                    while(x<=y-1) // @@ [Error: Same loop logic issues.]
                    {
                        printf("%c",f);
                        f=f+'b'-'a'; // @@ [Error: Incorrect increment. Should be f++ or f=f+1.]
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