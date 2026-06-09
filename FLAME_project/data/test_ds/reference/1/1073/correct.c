#include<stdio.h>
#include<string.h> 
int main()
{
    char s[100];
    int i,len,dif,j;
    gets(s);
    len = strlen(s);
    while(s[i] != '\0')
    {
        if(s[i] == '-'){
			dif = s[i+1] - s[i-1];
            if(s[i-1] < s[i+1] && s[i-1] >= '0' && s[i+1] <= '9')
            {
                for(j = 1 ; j < dif ; j++) printf("%c" , s[i-1] + j);
            }
            else if(s[i-1] < s[i+1] && s[i-1] >= 'A' && s[i+1] <= 'Z')
            {
                for(j = 1 ; j < dif ; j++) printf("%c" , s[i-1] + j);
            }
            else if(s[i-1] < s[i+1] && s[i-1] >= 'a' && s[i+1] <= 'z')
            {
                for(j = 1 ; j < dif ; j++) printf("%c" , s[i-1] + j);
            }
            else printf("%c",s[i]);
            i++;
        }
        else printf("%c",s[i++]);
    }
}

