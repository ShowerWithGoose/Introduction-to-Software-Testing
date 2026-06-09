/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include <stdio.h>
#include <string.h>
int main()
{
    int n,x,y;
    char arr[1000];
    fgets(arr); // @@ [Error: fgets requires three arguments: buffer, size, and stream. It should be fgets(arr, sizeof(arr), stdin). Also, this causes the compilation error mentioned in the problem description.]
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
                    d=arr[i-1]-'a'+'b'; // @@ [Logic Error: Incorrect calculation for next uppercase character. Should be arr[i-1]+1 or similar logic relative to 'A'. Using 'a' base for uppercase letters is incorrect.]
                    x=d;
                    y=arr[i+1];
                    while(x<=y-1)
                    {
                        
                        printf("%c",d);
                        d=d-'a'+'b'; // @@ [Logic Error: Incorrect increment logic for uppercase letters. Should simply increment d by 1.]
                        x=d;
                    }
                }
                else if(arr[i-1]>='0'&&arr[i-1]<'9'&&arr[i+1]>'0'&&arr[i+1]<='9')
            
                {
                    char f=0;
                
                    f=arr[i-1]+'b'-'a'; // @@ [Logic Error: Incorrect calculation for next digit. Should be arr[i-1]+1. 'b'-'a' is 1, so this accidentally works for increment but semantically confusing and relies on ASCII continuity which is fine for digits but the variable naming and logic are messy. More importantly, it fails to print the start character correctly in the loop structure compared to reference.]
                            x=f;
                    y=arr[i+1];
                    while(x<=y-1)
                    {
                        printf("%c",f);
                        f=f+'b'-'a'; // @@ [Logic Error: Increment logic. While 'b'-'a' is 1, standard practice is f++. This block also fails to handle the case where expansion shouldn't happen correctly if types don't match strictly as per requirements, e.g., mixing types.]
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