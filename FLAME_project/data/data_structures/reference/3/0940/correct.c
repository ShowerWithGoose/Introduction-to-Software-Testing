#include<stdio.h>
#include<string.h>
int main(){
int i=0,a=0,m=2,n=2,p=2;
char s[105]={'\0'},ch[105]={'\0'},ch1[105]={'\0'},ch2[105]={'\0'};
gets(s);
ch2[0]=s[0];
ch2[1]='.';
    while(s[i]!='\0'){
        ch2[p]=s[i+1];
        i++;
        a++;
        p++;
        if(s[i]=='.')
            break;
    }
    if(s[i]=='\0'&&s[1]!='\0')
            printf("%se%d",ch2,a-1);
    else if(s[i]=='\0'&&s[1]=='\0')
        printf("%ce0",s[0]);
    else{
    i=0;
    a=0;
    if(s[1]=='.'){
        if(s[0]!='0'){
            printf("%se0",s);
        }
        else if(s[0]=='0'){
            i=2;
            while(s[i]=='0'){
                a++;
                i++;
            }
            a++;
            ch[0]=s[i];
            if(s[i+1]!='\0'){
                ch[1]='.';
                i++;
                while(s[i]!='\0'){
                ch[m]=s[i];
                m++;
                i++;
            }
            }
            printf("%se-%d\n",ch,a);
        }
    }
    else{
       i=0;
       a=1;
       ch1[0]=s[0];
       ch1[1]='.';
        while(s[i+1]!='.'){
            ch1[n]=s[i+1];
            i++;
            a++;
            n++;
        }
        i++;
        while(s[i]!='\0'){
        ch1[n]=s[i+1];
        i++;
        n++;
       }
       printf("%se%d\n",ch1,a-1);
    }
    }
return 0;
}

