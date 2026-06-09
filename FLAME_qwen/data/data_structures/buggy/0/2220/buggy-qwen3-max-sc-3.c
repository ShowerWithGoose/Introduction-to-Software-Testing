#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    gets(str); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to removal from standard library]
    //printf("%c",str[3]);
    int len=strlen(str);
    //printf("%d",len);
    printf("%c",str[0]); 
    for(int i=1;i<len;i++)
    {
        if(str[i]=='-')
        {
        if(((str[i-1]-'a')>=0 )&& ((str[i-1]-'a')<=26)){ // @@ [Incorrect range check: 'z'-'a' is 25, so <=26 allows one extra invalid character (e.g., '{')]
            if(((str[i+1]-'a')>=0 && (str[i+1]-'a')<=26)&&(str[i+1]>str[i-1])){ // @@ [Same issue: <=26 is incorrect; should be <=25]
                
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
            if(((str[i-1]-'A')>=0 )&& ((str[i-1]-'A')<=26)){ // @@ [Same error: 'Z'-'A' is 25, so <=26 is wrong]
            if(((str[i+1]-'A')>=0 && (str[i+1]-'A')<=26)&&(str[i+1]>str[i-1])){ // @@ [Same error: <=26 should be <=25]
                
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
            if(((str[i-1]-'0')>=0 )&& ((str[i-1]-'0')<=9)){
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