#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    char a[105],b[105];
    gets(a);
    int i=0,sum=0,j=0,cot1=0,n[100]={0},k=0;
    for(i=0;a[i]!='\0';i++){
        if(a[i]!=' '){
            b[j]=a[i];
            j++;
        }
    }
    b[j]='\0';
    j=0;
    for(i=0;b[i]!='=';i++){
        if(b[i]=='+'||b[i]=='-'||b[i]=='*'||b[i]=='/')
            cot1++;
    }
    if(cot1==0){
        for(i=0;b[i]!='='&&b[i]!='\0';i++)
            printf("%c",b[i]);
    }
    else{
        for(i=0;b[i]!='\0';i++){
            if(b[i]>'9'||b[i]<'0'){
                int cot2=0;
                for(j=i-1;j>=0&&b[j]<='9'&&b[j]>='0';j--)
                    cot2++;
                cot2--;
                for(j++;j<i;j++){
                    n[k]+=(b[j]-'0')*(pow(10.0,cot2*1.0));
                    cot2--;
                }
                k++;
            }
        }
        k=1;
        for(i=0;b[i]!='=';i++){
            if(b[i]=='*'){
                n[k]*=n[k-1];k++;
            }
            else if(b[i]=='/'){
                n[k]=n[k-1]/n[k];k++;
            }
            else if(b[i]=='+'){
                sum+=n[k-1];k++;
            }
            else if(b[i]=='-'){
                sum+=n[k-1];n[k]*=(-1);k++;
            }
            else if(k>cot1){
                sum+=n[k-1];break;
            }
        }
        printf("%d",sum);
    }
    return 0;
}

