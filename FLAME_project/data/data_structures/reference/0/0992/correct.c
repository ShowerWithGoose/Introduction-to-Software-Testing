#include <stdio.h>
void expand(char s[])
{
    char str[100];
    int i,j;
    for(i=0,j=0;s[i]!='\0';i++){
        if(s[i]!='-') str[j++]=s[i];
        else {
            if(s[i+1]-s[i-1]>9&&!(s[i-1]>='a'&&s[i+1]<='z')){
                str[j++]=s[i];
                continue;
            }
            while(s[i+1]-str[j-1]>1){
                str[j]=str[j-1]+1;
                j++;
            }
        }
    }
    str[j]='\0';
    printf("%s",str);
    return;
}
int main()
{
    char s[100];
    scanf("%s",s);
    expand(s);
    return 0;
}
