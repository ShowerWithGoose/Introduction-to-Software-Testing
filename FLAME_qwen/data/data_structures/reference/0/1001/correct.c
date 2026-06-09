#include<stdio.h>
#include<string.h>
char s[10000000],s1[10000000];

int main()
{
    int len;
    gets(s);
    len=strlen(s);
    for(int i=0;i<len-1;i++){
        if(s[i]=='-'&&s[i-1]<s[i+1])
            if((s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='A'&&s[i+1]<='Z')||(s[i-1]>='0'&&s[i+1]<='9')){
                for(int j=0;j<s[i+1]-s[i-1];j++){
                    s1[j]=s[i-1]+j;
                    if(j==s[i+1]-s[i-1]-1)
                        s1[j+1]='\0';
                }
                strcat(s1,&s[i+1]);
                s[i-1]='\0';
                strcat(s,s1);
            }
    len=strlen(s);
    }
    puts(s);
    return 0;
}



