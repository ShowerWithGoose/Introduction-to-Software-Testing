#include<stdio.h>
#include<string.h>
char s[101];
int main(){
    int j=0;
    char t;
    gets(s);
    if(s[0]!='0'){

    for(int i=0;i<strlen(s);i++){
        
        if(s[i]=='.')
        {
        j=i;break;}
        
    }
        for(int i=0;i<j;i++)
    {
        if(i==1)
        printf(".");
        printf("%c",s[i]);
    }
    
        if(j==1)
        printf(".");
        for(int i=j+1;i<strlen(s);i++)
    {
        printf("%c",s[i]);
    }
        printf("e%d",j-1);
    
}
    else
    {
        for(int i=0;i<strlen(s);i++){
        
        if(s[i]!='0'&&s[i]!='.')
        {
        j=i;break;}
        
    }
    
    for(int i=j;i<strlen(s);i++)
    {
        printf("%c",s[i]);
        if(i==j+1)
        printf(".");
        
    }
    printf("e-%d",j-1); // @@ [Error: The exponent calculation is incorrect. For input "0.00000009123456789012", j is the index of the first non-zero digit '9' (j=8), but the exponent should be -8, not -(j-1) which gives -7. The correct exponent is -(j-2) because the decimal point is at index 1, so the number of leading zeros after the decimal point is j-2, and the exponent is -(j-2).]
    }
    return 0;}