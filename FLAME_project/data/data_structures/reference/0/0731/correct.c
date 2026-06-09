#include<stdio.h>
#include<string.h>
char in[10000],out[10000];
int main(void){
    gets(in);
    int j=0;
    for(int i=0;in[i];i++){
        if(in[i]!='-')out[j++]=in[i];
        else{
            if((in[i-1]>='0'&&in[i-1]<='9'&&in[i+1]>='0'&&in[i+1]<='9'&&in[i-1]<in[i+1])||(in[i-1]>='a'&&in[i-1]<='z'&&in[i+1]>='a'&&in[i+1]<='z'&&in[i-1]<in[i+1])||(in[i-1]>='A'&&in[i-1]<='Z'&&in[i+1]>='A'&&in[i+1]<='Z'&&in[i-1]<in[i+1])){
                char inter=in[i-1]+1;
                while(inter!=in[i+1]){
                    out[j++]=inter++;
                }
            }else{
                out[j++]='-';
            }
        }
    }
    out[j]=0;
    puts(out);
    return 0;
}


