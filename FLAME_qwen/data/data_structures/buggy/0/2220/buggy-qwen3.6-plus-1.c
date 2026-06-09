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
    for(int i=1;i<len;i++) // @@ Loop condition should be i < len - 1 to prevent out-of-bounds access to str[i+1] when i points to the last character.
    {
        if(str[i]=='-')
        {
        if(((str[i-1]-'a')>=0 )&& ((str[i-1]-'a')<=26)){ // @@ Range check should be <= 25 because 'z' - 'a' is 25; <= 26 incorrectly includes '{'.
            if(((str[i+1]-'a')>=0 && (str[i+1]-'a')<=26)&&(str[i+1]>str[i-1])){ // @@ Range check should be <= 25 for the same reason.
                
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
            if(((str[i-1]-'A')>=0 )&& ((str[i-1]-'A')<=26)){ // @@ Range check should be <= 25 because 'Z' - 'A' is 25.
            if(((str[i+1]-'A')>=0 && (str[i+1]-'A')<=26)&&(str[i+1]>str[i-1])){ // @@ Range check should be <= 25 for the same reason.
                
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
            } // @@ Missing else branch to print '-' when digit expansion conditions are not met, causing the hyphen to be omitted from the output.
            
        }
        }
        else{
            printf("%c",str[i]); 
        } 
    }
return 0;
}