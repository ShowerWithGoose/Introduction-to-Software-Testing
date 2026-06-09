#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    gets(str); // @@ [Using gets() is unsafe and may cause buffer overflow; however, the immediate error is that the program accesses str[i+1] when i can be len-1, leading to out-of-bounds access]
    //printf("%c",str[3]);
    int len=strlen(str);
    //printf("%d",len);
    printf("%c",str[0]); 
    for(int i=1;i<len;i++)
    {
        if(str[i]=='-')
        {
        if(((str[i-1]-'a')>=0 )&& ((str[i-1]-'a')<=26)){ // @@ [Condition (str[i-1]-'a')<=26 allows 'z'+1 (i.e., '{'), which is beyond 'z'; should be <=25. Also, this check doesn't ensure str[i+1] is within bounds]
            if(((str[i+1]-'a')>=0 && (str[i+1]-'a')<=26)&&(str[i+1]>str[i-1])){ // @@ [When i == len-1, str[i+1] is out of bounds (accessing beyond string end), causing undefined behavior]
                
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
            if(((str[i-1]-'A')>=0 )&& ((str[i-1]-'A')<=26)){ // @@ [Same issue: <=26 should be <=25; also no bounds check for str[i+1]]
            if(((str[i+1]-'A')>=0 && (str[i+1]-'A')<=26)&&(str[i+1]>str[i-1])){ // @@ [Accesses str[i+1] when i could be len-1 → out-of-bounds read]
                
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
            if(((str[i+1]-'0')>=0 && (str[i+1]-'0')<=9)&&(str[i+1]>str[i-1])){ // @@ [Again, str[i+1] may be out of bounds when i == len-1]
                
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