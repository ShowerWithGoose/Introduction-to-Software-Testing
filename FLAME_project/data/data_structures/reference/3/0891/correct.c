#include<stdio.h>
#include<string.h>
char s[120],in[120],i;
int main(){
    gets(s);
    if(s[1]=='.'){
        if(s[0]=='0'){
            for(i=2;s[i]=='0';i++);
            if((i+1)==strlen(s)){
                printf("%ce-%d",s[i],i-1);
                return 0;
            }
            else{
                in[0]=s[i],in[1]='.';
                strcat(in,&s[i+1]);
                printf("%se-%d",in,i-1);
                return 0;
            }
        }
        else{
            printf("%se0",s);
            return 0;
        }
    }
    else{
        for(i=2;s[i]!='.';i++);
        in[0]=s[0],in[1]='.';
        for(int j=1,k=2;j<strlen(s);j++){
            if(s[j]!='.'){
                in[k]=s[j];
                k++;
            }
        }
        printf("%se%d",in,i-1);
    }

}

