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
    for(int i=1;i<len;i++) // @@ Loop condition allows i to reach len-1, causing str[i+1] to access out-of-bounds memory. Should be i < len - 1.
    {
        if(str[i]=='-')
        {
        if(((str[i-1]-'a')>=0 )&& ((str[i-1]-'a')<=26)){ // @@ Range check <=26 is off-by-one; 'z'-'a' is 25, so <=25 should be used to strictly match [a-z].
            if(((str[i+1]-'a')>=0 && (str[i+1]-'a')<=26)&&(str[i+1]>str[i-1])){ // @@ Same off-by-one range error as above.
                
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
            if(((str[i-1]-'A')>=0 )&& ((str[i-1]-'A')<=26)){ // @@ Range check <=26 is off-by-one; 'Z'-'A' is 25, should be <=25.
            if(((str[i+1]-'A')>=0 && (str[i+1]-'A')<=26)&&(str[i+1]>str[i-1])){ // @@ Same off-by-one range error as above.
                
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
            } // @@ Missing else clause to print '-' when digit expansion condition fails, causing '-' to be omitted from output.
            
        }
        }
        else{
            printf("%c",str[i]); 
        } 
    }
return 0;
}