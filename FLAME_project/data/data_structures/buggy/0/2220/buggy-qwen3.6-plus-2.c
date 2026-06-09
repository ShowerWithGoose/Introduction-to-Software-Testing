#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    gets(str);
    //printf("%c",str[3]);
    int len=strlen(str);
    //printf("%d",len);
    printf("%c",str[0]); 
    for(int i=1;i<len;i++)
    {
        if(str[i]=='-')
        {
        if(((str[i-1]-'a')>=0 )&& ((str[i-1]-'a')<=26)){ // @@ The condition `<= 26` is incorrect for checking lowercase letters 'a'-'z'. 'a'-'a' is 0, 'z'-'a' is 25. It should be `<= 25`. Also, this logic fails to ensure mutual exclusivity with other types if ranges overlap or are checked sequentially without else-if, though here the main issue is the boundary and the lack of handling for the case where expansion doesn't happen but the character is still printed later. More critically, if this block executes (even if it doesn't expand), it might fall through or interfere. However, the specific bug causing the wrong output `abcdefg0A` instead of `abcdefg0-A` is that when `0-A` is encountered, `0` is a digit. The code checks lowercase, then uppercase, then digits. For `0-A`, `str[i-1]` is '0'. `'0'-'a'` is negative, so first if fails. `'0'-'A'` is negative, so second if fails. `'0'-'0'` is 0, which is `>=0` and `<=9`. So it enters the digit block. Inside, it checks `str[i+1]` which is 'A'. `'A'-'0'` is not `>=0 && <=9` (it's much larger). So the inner if fails. There is no `else` clause in the digit block to print the '-' character. Thus, the '-' is skipped entirely.
            if(((str[i+1]-'a')>=0 && (str[i+1]-'a')<=26)&&(str[i+1]>str[i-1])){
                
                int k;
                k=str[i+1]-str[i-1];
                int m;
                m=(str[i-1]);
                for(int v=1;v<k;v++)
                {
                    char q;
                    q=(m+v);
                    printf("%c",q);
                }
            }
            else {
                printf("%c",str[i]);
            }
        }
            if(((str[i-1]-'A')>=0 )&& ((str[i-1]-'A')<=26)){ // @@ Similar boundary error `<= 26` should be `<= 25`. Also, this is an independent `if`, not `else if`. If the previous block executed its `else`, it printed '-'. If this block executes, it might print again or check conditions. But the critical missing piece is in the digit block below.
            if(((str[i+1]-'A')>=0 && (str[i+1]-'A')<=26)&&(str[i+1]>str[i-1])){
                
                int k;
                k=str[i+1]-str[i-1];
                int m;
                m=(str[i-1]);
                for(int v=1;v<k;v++)
                {
                    char q;
                    q=(m+v);
                    printf("%c",q);
                }
            }
            else {
                printf("%c",str[i]);
            }
        }
            if(((str[i-1]-'0')>=0 )&& ((str[i-1]-'0')<=9)){ // @@ This block handles digits. If the expansion condition fails (e.g., mixed types like 0-A), there is no `else` clause to print the '-' character. This causes the '-' to be omitted from the output.
            if(((str[i+1]-'0')>=0 && (str[i+1]-'0')<=9)&&(str[i+1]>str[i-1])){
                
                int k;
                k=str[i+1]-str[i-1];
                int m;
                m=(str[i-1]);
                for(int v=1;v<k;v++)
                {
                    char q;
                    q=(m+v);
                    printf("%c",q);
                }
            }
            
        }
        }
        else{
            printf("%c",str[i]); 
        } 
    }
return 0;
}