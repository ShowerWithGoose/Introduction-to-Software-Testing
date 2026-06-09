#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>


int main()
{
    char s[100000],o[100000];
    char *p;
    scanf("%s", s);
    int i=0,j=0,k=0;
    for(i=0;s[i]!='\0';i++){
        if(s[i]=='-'){
            if(s[i-1]<='z'&&s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>='a'&&s[i+1]>s[i-1]){
                p = s;
                strcpy(o,p);
                for(j=i,k=1;k<s[i+1]-s[i-1];k++)
                    o[j++]=s[i-1]+k;
                o[j]='\0';
                p = s+i+1;
                strcat(o,p);
                strcpy(s,o);
                i = j;
            }
            if(s[i-1]<='Z'&&s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>='A'&&s[i+1]>s[i-1]){
                p = s;
                strcpy(o,p);
                for(j=i,k=1;k<s[i+1]-s[i-1];k++)
                    o[j++]=s[i-1]+k;
                o[j]='\0';
                p = s+i+1;
                strcat(o,p);
                strcpy(s,o);
                i = j;
            }
            if(s[i-1]<='9'&&s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>='0'&&s[i+1]>s[i-1]){
                p = s;
                strcpy(o,p);
                for(j=i,k=1;k<s[i+1]-s[i-1];k++)
                    o[j++]=s[i-1]+k;
                o[j]='\0';
                p = s+i+1;
                strcat(o,p);
                strcpy(s,o);
                i = j;
            }
            else
                strcpy(o,s);
        }
    }
    puts(o);
	return 0;
}

