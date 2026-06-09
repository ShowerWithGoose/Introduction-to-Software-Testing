//
//  main.c
//  text  2
//
//  Created by  on 2021/11/5.
//
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
int main(int argc, char *argv[])
{char s[1000],ans[5000],c;
    scanf("%s",s);
    int len,k=0;
    len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i+1]!='-')
            ans[k++]=s[i];
        else{
            if(s[i]>='0'&&s[i]<='9'&&s[i+2]>='0'&&s[i+2]<='9'&&s[i+2]>s[i])
            {c=s[i];while(c<s[i+2]){ans[k++]=c;c+=1; } i+=1;}
         else   if(s[i]>='a'&&s[i]<='z'&&s[i+2]>='a'&&s[i+2]<='z'&&s[i+2]>s[i])
         {c=s[i];while(c<s[i+2]){ans[k++]=c;c+=1; } i+=1;}
           else if(s[i]>='A'&&s[i]<='Z'&&s[i+2]>='A'&&s[i+2]<='Z'&&s[i+2]>s[i])
           {c=s[i];while(c<s[i+2]){ans[k++]=c;c+=1; } i+=1;}
            else
            {ans[k++]=s[i];ans[k++]=s[i+1];ans[k++]=s[i+2];i+=2; }
        }
        
    }
    ans[k]='\0';
    printf("%s",ans);
  return 0;
}


