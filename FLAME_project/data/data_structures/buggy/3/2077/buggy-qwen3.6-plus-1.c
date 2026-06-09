#include<stdio.h>
#include<string.h>
char s[1000],c;
int main()
{
    int count=0,flag=0;
    scanf("%s",s);
    int len=strlen(s);
    int i=0;
    if(s[0]!='-'){
    for(i=0;i<len;i++){
        if(s[i]!='.'){
            count++;
        }else{
            flag++;
            break;
        }
    }   
    if(count==len){
        printf("%se0",s);
    }else{
    if(count==1&&s[0]!='0'){
        printf("%se0\n",s);
    }else if(count>1){
        for(i=count;i>1;i--){
            c=s[i-1];
            s[i-1]=s[i];
            s[i]=c;
        }printf("%se%d\n",s,count-1);
    }else if(count==1&&s[0]=='0'){
        i=2;
        count=0;
        while(s[i]=='0'){
            count++;
            i++;
        }//printf("%d\n",count);
        for(i=1;i<=count+1;i++){
            c=s[i+1];
            s[i+1]=s[i];
            s[i]=c;
        }for(i=count+1;s[i]!='\0';i++)
            printf("%c",s[i]); // @@ The loop prints characters starting from the first significant digit. If the next character is '\0' (end of string), it means there are no decimal digits left, so a trailing '.' was effectively moved or remains. However, the logic here shifts the decimal point. For "0.9", count becomes 0. The loop `for(i=1;i<=1;i++)` swaps s[2] and s[1]. s was "0.9\0". s[1]='.', s[2]='9'. After swap: s[1]='9', s[2]='.'. String is "09.\0". The print loop starts at i=1. It prints '9', then '.', then stops at '\0'. Output "9.e-1". The expected output is "9e-1". The code fails to remove the decimal point when there are no fractional digits remaining after normalization.
        printf("e-%d\n",count+1);
    }
    }
    }else{
        for(i=0;i<len;i++){
        if(s[i]!='.'){
            count++;
        }else{
            flag++;
            break;
        }
    }   
    if(count==len){
        printf("%se0",s);
    }else{count--;
    if(count==1&&s[0]!='0'){
        printf("%se0\n",s);
    }else if(count>1){
        for(i=count+1;i>2;i--){
            c=s[i-1];
            s[i-1]=s[i];
            s[i]=c;
        }printf("%se%d\n",s,count-1);
    }else if(count==1&&s[0]=='0'){
        i=1;
        count=0;
        while(s[i]==0){
            count++;
        }count--;
        for(i=2;i<=count+2;i++){
            c=s[i+1];
            s[i+1]=s[i];
            s[i]=c;
        }printf("-");
        for(i=count+1;s[i]!='\0';i++)
            printf("%c",s[i]);
        printf("e-%d\n",count+1);
    }
    }    
    }return 0;
}