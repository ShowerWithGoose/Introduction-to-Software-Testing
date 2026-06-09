/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include <stdio.h>
#include <string.h>
int main()
{
    int n,x,y;
    char arr[1000];
    fgets(arr); // @@ Compilation error: fgets requires 3 arguments (buffer, size, stream), e.g., fgets(arr, sizeof(arr), stdin);
    n=strlen(arr);
    for(int i=0;i<n;i++)
    {
        if(arr[i]!='-')
        {
            printf("%c",arr[i]);
        }
        else if(arr[i]=='-')
        {    
                if((arr[i-1]>='a')&&(arr[i-1]<'z')&&(arr[i+1]>'a')&&(arr[i+1]<='z')) // @@ Logical error: Out-of-bounds access when i=0; range '<'z'' excludes 'z'; should check arr[i+1] > arr[i-1] for expansion.
                {
                    char c=0;
                    c=arr[i-1]-'a'+'b'; // @@ Logical error: Skips printing the starting character arr[i-1]; expansion should include both endpoints.
                    x=c;
                    y=arr[i+1];
                    while(x<=y-1) // @@ Logical error: Loop condition stops before the end character; should be x <= y to include the last character.
                    {
                        printf("%c",c);
                        c=c-'a'+'b';
                        x=c;
                    }
                }
                else if((arr[i-1]>='A')&&(arr[i-1]<'Z')&&(arr[i+1]>'A')&&(arr[i+1]<='Z')) // @@ Logical error: Same range and comparison issues as line 18; '<'Z'' excludes 'Z'.
            
                {
                    char d=0;
                    d=arr[i-1]-'a'+'b'; // @@ Logical error: Uses lowercase 'a' for uppercase calculation; should use 'A' or simply d = arr[i-1] + 1.
                    x=d;
                    y=arr[i+1];
                    while(x<=y-1) // @@ Logical error: Same as line 24; stops before end character.
                    {
                        
                        printf("%c",d);
                        d=d-'a'+'b';
                        x=d;
                    }
                }
                else if(arr[i-1]>='0'&&arr[i-1]<'9'&&arr[i+1]>'0'&&arr[i+1]<='9') // @@ Logical error: Range check '<'9'' excludes '9'; should check arr[i+1] > arr[i-1].
            
                {
                    char f=0;
                
                    f=arr[i-1]+'b'-'a'; // @@ Logical error: Skips starting character; should start from arr[i-1].
                            x=f;
                    y=arr[i+1];
                    while(x<=y-1) // @@ Logical error: Same as line 24; stops before end character.
                    {
                        printf("%c",f);
                        f=f+'b'-'a';
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