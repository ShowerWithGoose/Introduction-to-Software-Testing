#include<stdio.h>
#include<string.h>



int main()
{
    int i,j,ex[1000]={0};
    char in[1000],out[1000];
    scanf("%s",in);
    for(i=j=0;in[i]!='\0';i++){
        if(in[i+1]=='-' && in[i+2]!='\0') {

            out[j++]=in[i];

            if(in[i]>='a' && in[i]<='z' && in[i+2]>='a' && in[i+2]<='z' && in[i+2]>in[i]){
                for(int k=1;k<(in[i+2]-in[i]);k++){
                    out[j++]=in[i]+k;
                }
            }
            else if(in[i]>='A' && in[i]<='Z' && in[i+2]>='A' && in[i+2]<='Z' && in[i+2]>in[i]){
                for(int k=1;k<(in[i+2]-in[i]);k++){
                    out[j++]=in[i]+k;
                }
            }
            else if(in[i]>='0' && in[i]<='9' && in[i+2]>='0' && in[i+2]<='9' && in[i+2]>in[i]){
                for(int k=1;k<(in[i+2]-in[i]);k++){
                    out[j++]=in[i]+k;
                }
            }
            else out[j++]=in[i+1];

            i++;
        }

        else out[j++]=in[i];
    }

    printf("%s",out);


    return 0;
}


