#include <stdio.h>
#include <string.h>
char s[105];
int main(){
    int x,j,y=0,i;
    gets(s);
    x=strlen(s);
    if(s[0]=='-'){
        printf("-");
        for(i=0,j=1;j<=x-1;j++,i++){
            s[i]=s[j];
        }
        s[x-1]=0;
        x=strlen(s);
    }
    for(j=0;j<=x-1;j++){
        if(s[j]=='.'){
            y=j;
            break;
        }
        else{
            y=0;
        }
    }
    if(y==1){
        if(s[0]>'0'){
            printf("%se0",s);
        }
        else{
            for(i=2;i<=x-1;i++){
                if(s[i]!='0'){
                    break;
                }
            }
            if(i==x-1){
                printf("%ce-%d",s[x-1],i-1);
            }
            else{
                printf("%c.",s[i]);
                for(j=i+1;j<=x-1;j++){
                    printf("%c",s[j]);
                }
                printf("e-%d",i-1);
            }
        }
    }
    else{
        printf("%c.",s[0]);
        for(j=1;j<=x-1;j++){
            if(s[j]=='.'){
                j++;
            }
            else{
                printf("%c",s[j]); // @@ The loop condition `j<=x-1` combined with the logic fails to print all significant digits correctly when the decimal point is skipped, specifically it stops one character early or mishandles the index increment relative to the string length, causing the last digit '9' in the test case to be missed. The loop should iterate through all characters except the decimal point, but the boundary condition or index handling is flawed for long strings.
            }
        }
        printf("e%d",y-1);
    }
    return 0;
}