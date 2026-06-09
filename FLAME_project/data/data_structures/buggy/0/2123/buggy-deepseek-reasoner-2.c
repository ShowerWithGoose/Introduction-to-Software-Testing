/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include <stdio.h>
#include <string.h>
int main()
{
    int n,x,y;
    char arr[1000];
    fgets(arr); // @@ [Error: fgets requires three arguments: buffer, size, and stream. Should be fgets(arr, sizeof(arr), stdin);]
    n=strlen(arr);
    for(int i=0;i<n;i++)
    {
        if(arr[i]!='-')
        {
            printf("%c",arr[i]);
        }
        else if(arr[i]=='-')
        {    
                if((arr[i-1]>='a')&&(arr[i-1]<'z')&&(arr[i+1]>'a')&&(arr[i+1]<='z')) // @@ [Error: Conditions incorrectly exclude 'z' as first character and 'a' as second character. Should use <= 'z' and >= 'a', and also need to check arr[i+1] > arr[i-1].]
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
                else if((arr[i-1]>='A')&&(arr[i-1]<'Z')&&(arr[i+1]>'A')&&(arr[i+1]<='Z')) // @@ [Error: Conditions incorrectly exclude 'Z' as first character and 'A' as second character. Should use <= 'Z' and >= 'A', and need arr[i+1] > arr[i-1].]
            
                {
                    char d=0;
                    d=arr[i-1]-'a'+'b';
                    x=d;
                    y=arr[i+1];
                    while(x<=y-1)
                    {
                        
                        printf("%c",d);
                        d=d-'a'+'b';
                        x=d;
                    }
                }
                else if(arr[i-1]>='0'&&arr[i-1]<'9'&&arr[i+1]>'0'&&arr[i+1]<='9') // @@ [Error: Conditions incorrectly exclude '9' as first character and '0' as second character. Should use <= '9' and >= '0', and need arr[i+1] > arr[i-1].]
            
                {
                    char f=0;
                
                    f=arr[i-1]+'b'-'a';
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