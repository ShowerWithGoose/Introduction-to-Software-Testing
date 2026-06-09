#include<stdio.h>
#include<string.h>
int main(){
    char s[100],in[100];
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='-'&&(s[i-1]>='a'&&s[i+1]<='z')){
            strcpy(in,s);
            in[i]='\0';
            int ii=i;
            int m=s[i-1],t=s[i+1];
            for(int j=1;j<(t-m);j++){
                in[ii++]=m+j;
            }
            in[ii]='\0';
            strcat(in,&s[i+1]);
            strcpy(s,in);
        }
        else if(s[i]=='-'&&(s[i-1]>='A'&&s[i+1]<='Z')){
            strcpy(in,s);
            in[i]='\0';
            int ii=i;
            int m=s[i-1],t=s[i+1];
            for(int j=1;j<(t-m);j++){
                in[ii++]=m+j;
            }
            in[ii]='\0';
            strcat(in,&s[i+1]);
            strcpy(s,in);
        }
        else if(s[i]=='-'&&(s[i-1]>='0'&&s[i+1]<='9')){
            strcpy(in,s);
            in[i]='\0';
            int ii=i;
            int m=s[i-1],t=s[i+1];
            for(int j=1;j<(t-m);j++){
                in[ii++]=m+j;
            }
            in[ii]='\0';
            strcat(in,&s[i+1]);
            strcpy(s,in);
        }
    }
    printf("%s",s);

}



