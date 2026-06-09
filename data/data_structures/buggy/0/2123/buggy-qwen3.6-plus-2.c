/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include <stdio.h>
#include <string.h>
int main()
{
    int n,x,y;
    char arr[1000];
    fgets(arr); // @@ Compilation error: fgets requires three arguments (buffer, size, stream), e.g., fgets(arr, sizeof(arr), stdin);
    n=strlen(arr);
    for(int i=0;i<n;i++)
    {
        if(arr[i]!='-')
        {
            printf("%c",arr[i]);
        }
        else if(arr[i]=='-')
        {    
                if((arr[i-1]>='a')&&(arr[i-1]<'z')&&(arr[i+1]>'a')&&(arr[i+1]<='z')) // @@ Logical error: Incorrect range boundaries (should be <= 'z' and >= 'a'), lacks boundary checks for i=0/i=n-1, and does not verify arr[i-1] < arr[i+1].
                {
                    char c=0;
                    c=arr[i-1]-'a'+'b'; // @@ Logical error: Hardcoded 'b' is incorrect for general expansion; should be c = arr[i-1] + 1;
                    x=c;
                    y=arr[i+1];
                    while(x<=y-1)
                    {
                        printf("%c",c);
                        c=c-'a'+'b'; // @@ Logical error: Should be c++; to iterate through characters.
                        x=c;
                    }
                }
                else if((arr[i-1]>='A')&&(arr[i-1]<'Z')&&(arr[i+1]>'A')&&(arr[i+1]<='Z')) // @@ Logical error: Same range and boundary issues as lowercase check.
        
                {
                    char d=0;
                    d=arr[i-1]-'a'+'b'; // @@ Logical error: Uses lowercase 'a'/'b' for uppercase letters, producing wrong characters; should be d = arr[i-1] + 1;
                    x=d;
                    y=arr[i+1];
                    while(x<=y-1)
                    {
                        
                        printf("%c",d);
                        d=d-'a'+'b'; // @@ Logical error: Should be d++;.
                        x=d;
                    }
                }
                else if(arr[i-1]>='0'&&arr[i-1]<'9'&&arr[i+1]>'0'&&arr[i+1]<='9') // @@ Logical error: Incorrect range boundaries (should be <= '9' and >= '0'), lacks boundary checks, and does not verify arr[i-1] < arr[i+1].
        
                {
                    char f=0;
                
                    f=arr[i-1]+'b'-'a'; // @@ Logical error: While 'b'-'a' is 1, it's semantically wrong for digits; should be f = arr[i-1] + 1;
                            x=f;
                    y=arr[i+1];
                    while(x<=y-1)
                    {
                        printf("%c",f);
                        f=f+'b'-'a'; // @@ Logical error: Should be f++;.
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