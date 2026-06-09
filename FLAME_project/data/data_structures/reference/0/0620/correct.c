#include<stdio.h>

int judge(char c[],int i){
int j=i-1,k=i+1;
if(c[j]<c[k]){
    if((c[j]>='a'&&c[k]<='z')||(c[j]>='A'&&c[k]<='Z')||(c[j]>='0'&&c[k]<='9'))
        return 1;
}
return 0;
}
int main(){
char c[10000];
scanf("%s",&c);
for(int i=0;i<strlen(c);i++){
    if(c[i+1]=='-'){
        if(judge(c,i+1)==1){
            for(int o=c[i+2]-c[i],j=c[i-1]=='-'?1:0;j<=o;j++)
                printf("%c",c[i]+j);
            i++;
        }
        else
            printf("%c",c[i]);
    }
    else if((judge(c,i-1)==0&&c[i-1]=='-')||c[i-1]!='-')
        printf("%c",c[i]);
}
return 0;
}



