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
            printf("%c",s[i]); // @@ The loop prints characters starting from the first significant digit, but it includes the decimal point if it hasn't been removed or moved correctly. In the case of 0.9, count is 0. The loop runs for i=1 to 1. s[1] is '9' after shift? No. Original: 0.9. i=2 ('9'). while('9'=='0') false. count=0. Loop i=1 to 1. s[1] is '.'. So it prints '.'. Then prints "e-1". Result: ".e-1" or similar. Wait, let's trace 0.9. s="0.9". count=1 (digit '0'). flag=1. count==1 && s[0]=='0'. i=2. s[2]='9'. while(s[2]=='0') false. count=0. Loop i=1 to 1. c=s[2] ('9'), s[2]=s[1] ('.'), s[1]=c ('9'). s becomes "09.". Then loop i=count+1 (1) to end. s[1]='9', s[2]='.'. Prints "9.". Then "e-1". Output "9.e-1". Expected "9e-1". The error is that the decimal point is not removed.
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