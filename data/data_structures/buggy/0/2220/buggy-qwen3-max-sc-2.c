#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    gets(str); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers that remove 'gets' entirely. Also, if input length exceeds buffer size, it causes buffer overflow.]
    //printf("%c",str[3]);
    int len=strlen(str);
    //printf("%d",len);
    printf("%c",str[0]); 
    for(int i=1;i<len;i++)
    {
        if(str[i]=='-')
        {
        if(((str[i-1]-'a')>=0 )&& ((str[i-1]-'a')<=26)){ // @@ [Condition allows 'z'-'a'=25, but <=26 includes one extra invalid character (e.g., '{'). Should be <=25. Also, does not ensure str[i+1] is within bounds when i = len-1.]
            if(((str[i+1]-'a')>=0 && (str[i+1]-'a')<=26)&&(str[i+1]>str[i-1])){ // @@ [Same issue: <=26 is incorrect; should be <=25. Also, accesses str[i+1] without checking if i+1 < len, leading to out-of-bounds read when '-' is at the last position.]
                
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
            if(((str[i-1]-'A')>=0 )&& ((str[i-1]-'A')<=26)){ // @@ [Same logical error: <=26 should be <=25 for uppercase letters. Also, no bounds check for str[i+1].]
            if(((str[i+1]-'A')>=0 && (str[i+1]-'A')<=26)&&(str[i+1]>str[i-1])){ // @@ [Same issues: incorrect range and potential out-of-bounds access.]
                
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
            if(((str[i-1]-'0')>=0 )&& ((str[i-1]-'0')<=9)){ // @@ [This condition is correct for digits, but still lacks bounds check for str[i+1].]
            if(((str[i+1]-'0')>=0 && (str[i+1]-'0')<=9)&&(str[i+1]>str[i-1])){ // @@ [Correct digit range, but again accesses str[i+1] without ensuring i+1 < len.]
                
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