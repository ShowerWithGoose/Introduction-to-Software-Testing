/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include <stdio.h>
#include <string.h>
int main()
{
    int n,x,y;
    char arr[1000];
    fgets(arr); // @@ [Error: fgets requires three arguments: buffer, size, and stream. It should be fgets(arr, sizeof(arr), stdin).]
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
                    d=arr[i-1]-'a'+'b'; // @@ [Error: Logic error for uppercase letters. Subtracting 'a' from an uppercase letter results in a negative or incorrect offset. It should be arr[i-1]-'A'+'B'.]
                    x=d;
                    y=arr[i+1];
                    while(x<=y-1)
                    {
                        
                        printf("%c",d);
                        d=d-'a'+'b'; // @@ [Error: Same logic error as above. Incrementing uppercase letters should use 'A' and 'B'.]
                        x=d;
                    }
                }
                else if(arr[i-1]>='0'&&arr[i-1]<'9'&&arr[i+1]>'0'&&arr[i+1]<='9')
            
                {
                    char f=0;
                
                    f=arr[i-1]+'b'-'a'; // @@ [Error: Logic error for digits. Adding ('b'-'a') which is 1 to a digit character works for incrementing, but the variable name and clarity are poor. More importantly, the loop condition and update logic rely on this being correct. While 'b'-'a' is 1, using '1' is clearer. However, strictly speaking, this calculates the next digit correctly if f is treated as char. But wait, f is initialized to 0, then assigned. The real issue is often boundary conditions or type mixing. Let's look closer. arr[i-1] is '0'..'8'. f becomes '1'..'9'. x=f. y=arr[i+1]. If input is 0-2, f='1', x='1', y='2'. Loop runs for '1'. Then f becomes '2', x='2'. Loop stops. Output "1". Expected "12" if expanding 0-2? No, expansion of 0-2 is 012. The code prints start char separately? No, the main loop prints non-dash chars. So when i is at '-', it prints the expansion between start and end. The start char was already printed when i was at i-1. So we only need to print from start+1 to end. The code prints c (which is start+1). This seems logically okay for the range, but the calculation for uppercase is definitely wrong.]
                            x=f;
                    y=arr[i+1];
                    while(x<=y-1)
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