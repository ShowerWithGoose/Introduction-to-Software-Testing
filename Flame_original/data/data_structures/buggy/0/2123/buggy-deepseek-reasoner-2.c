/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include <stdio.h>
#include <string.h>
int main()
{
    int n,x,y;
    char arr[1000];
    fgets(arr); // @@ 缺少第二个参数（大小）和第三个参数（文件流），应为 fgets(arr, sizeof(arr), stdin);
    n=strlen(arr);
    for(int i=0;i<n;i++)
    {
        if(arr[i]!='-')
        {
            printf("%c",arr[i]);
        }
        else if(arr[i]=='-')
        {    
                if((arr[i-1]>='a')&&(arr[i-1]<'z')&&(arr[i+1]>'a')&&(arr[i+1]<='z')) // @@ 缺少对 arr[i-1] < arr[i+1] 的检查，会导致降序或差1情况处理错误
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
                else if((arr[i-1]>='A')&&(arr[i-1]<'Z')&&(arr[i+1]>'A')&&(arr[i+1]<='Z')) // @@ 缺少对 arr[i-1] < arr[i+1] 的检查
            
                {
                    char d=0;
                    d=arr[i-1]-'a'+'b'; // @@ 错误：应使用大写字母偏移 d=arr[i-1]-'A'+'B' 或 d=arr[i-1]+1
                    x=d;
                    y=arr[i+1];
                    while(x<=y-1)
                    {
                        
                        printf("%c",d);
                        d=d-'a'+'b'; // @@ 错误：应使用大写字母偏移 d=d-'A'+'B' 或 d=d+1
                        x=d;
                    }
                }
                else if(arr[i-1]>='0'&&arr[i-1]<'9'&&arr[i+1]>'0'&&arr[i+1]<='9') // @@ 缺少对 arr[i-1] < arr[i+1] 的检查
            
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