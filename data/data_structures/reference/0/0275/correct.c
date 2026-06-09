#include <stdio.h>
#include <string.h>
#include <ctype.h>
void expand(char *s,int place){
    char temp[1000]="";
    if(place==0 || s[place+1]=='\0')return;
    if(s[place-1]-s[place+1]>=-1)return;
    char a=s[place-1],b=s[place+1];
    if(!(isdigit(a)&&isdigit(b) || islower(a)&&islower(b) || isupper(a)&&isupper(b)))return;
    strncat(temp, s, place);
    int k=strlen(temp);
    for(int i=0;i<=s[place+1]-s[place-1]-1;i++){
        temp[k+i-1]=s[place-1]+i;
    }
    strcat(temp, &s[place+1]);
    strcpy(s, temp);
    return;
}

int main() {
    char s[1000];
    scanf("%s",s);
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='-')expand(s,i);
    }
    printf("%s",s);
}

