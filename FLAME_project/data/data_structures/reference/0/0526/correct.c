#include<stdio.h>
#include<string.h>
int main()
{
 char s[100]={0};
 char c='-',t;
 gets(s);
 for(int i=0;s[i]!=NULL;i++){
    if(s[i]!=c)
        printf("%c",s[i]);
    else {
       if(s[i-1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1]){
            t=s[i-1]+1;
            for(;t<s[i+1];t++)
                printf("%c",t);
       }
       else if(s[i-1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1]){
            t=s[i-1]+1;
            for(;t<s[i+1];t++)
                printf("%c",t);
       }
       else if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1]){
            t=s[i-1]+1;
            for(;t<s[i+1];t++)
                printf("%c",t);
       }
       else printf("-");
    }
 }

 return 0;
}



