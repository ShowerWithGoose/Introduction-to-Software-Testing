#include<stdio.h>
int main(){
    char c[1000]="\0";
    long long num[100];
    int tem[100]={0};
    char sign[100];
    int i=0,j=0;
    while(1){  
        scanf("%lld",&num[i]);
        scanf("%c",&sign[j]);
        while(sign[j]==' '){
            scanf("%c",&sign[j]);
        }
        if(sign[j]=='='){
            break;
        }
        i++;
        j++;
    }
    for(int m=0;m<j;m++){
        if(sign[m]=='*'||sign[m]=='/'){
            if(sign[m]=='*'){
                num[m+1]=num[m]*num[m+1];
                num[m]=0;
            }
            else{
                num[m+1]=num[m]/num[m+1];
                num[m]=0;
            }
            tem[m]=1;
        }
    }
    long long sum=0;
    int k=0;
    while(num[k]==0){ // @@ This loop incorrectly skips all zeros, including valid zero values from input like "0 =", causing sum to start from the wrong index.
        k++;
    }
    sum+=num[k];
    char temc;
    for(int l=k;l<i;l++){
        if(sign[l]=='+'){
            temc='+';
        }
        if(sign[l]=='-'){
            temc='-';
        }
        if(temc=='+'&&tem[l+1]==0){ // @@ The condition tem[l+1]==0 incorrectly filters out numbers that were set to 0 by multiplication/division, but also fails to handle cases where sign array indices don't align with num array indices after skipping zeros.
            sum+=num[l+1];
        }
        else if(temc=='-'&&tem[l+1]==0){
            sum-=num[l+1];
        }
    }
    printf("%lld",sum);
    return 0;
}