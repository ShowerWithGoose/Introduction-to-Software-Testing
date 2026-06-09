#include<stdio.h>
#include<string.h>
int main(){
    char s[111];
    gets(s);
    int n=strlen(s),i,j=0,k;
    for(i=0;i<n;i++)
       if(s[i]>'0'&&s[i]<='9') break;
    j=n-i;
    if(j==1){
        printf("%ce-%d",s[n-1],n-2);
    }else{
        for(i=0;i<n;i++)
            if(s[i]=='.') break;
        if(s[0]=='0'){
            printf("%c.",s[n-j]);
            for(k=n-j+1;k<n;k++)
                printf("%c",s[k]);
            printf("e-%d",n-j-1);
        }else{
            printf("%c.",s[0]);
            for(k=1;k<i;k++)
                printf("%c",s[k]);
            for(k=i+1;k<n;k++)
                printf("%c",s[k]);
            printf("e%d",i-1);
        }
    }
    return 0;
}
