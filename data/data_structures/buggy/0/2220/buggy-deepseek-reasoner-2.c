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
    for(int i=1;i<len;i++)@@ // Loop bound should be i<len-1 to avoid accessing str[i+1] out of bounds; also last character needs separate handling
    {
        if(str[i]=='-')
        {
        if(((str[i-1]-'a')>=0 )&& ((str[i-1]-'a')<=26)){@@ // Range should be <=25, not <=26
            if(((str[i+1]-'a')>=0 && (str[i+1]-'a')<=26)&&(str[i+1]>str[i-1])){@@ // Range should be <=25; also i+1 may be out of bounds when i=len-1
                
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
            if(((str[i-1]-'A')>=0 )&& ((str[i-1]-'A')<=26)){@@ // Range should be <=25, not <=26
            if(((str[i+1]-'A')>=0 && (str[i+1]-'A')<=26)&&(str[i+1]>str[i-1])){@@ // Range should be <=25; also i+1 may be out of bounds
                
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
            if(((str[i+1]-'0')>=0 && (str[i+1]-'0')<=9)&&(str[i+1]>str[i-1])){@@ // Missing else for when expansion condition fails; also missing catch-all else for non-matching types after the three if blocks
                
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