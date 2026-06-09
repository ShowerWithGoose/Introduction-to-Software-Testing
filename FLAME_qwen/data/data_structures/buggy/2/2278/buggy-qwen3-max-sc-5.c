#include<stdio.h>
int number_change(int num,char digit){
    num=10*num+digit-'0';
    return num;
}
int main(){
    char str1[200];
    int str2[3][200]={},str3[2][200]={};//str2中0对储存数字进行转化,1记录该数字后的符号，2为该处几个乘号
    gets(str1); // @@ [The function 'gets' is unsafe and has been removed from the C standard library in C11; using it may cause compilation errors or warnings with modern compilers. It should be replaced with 'fgets'.]
    int i,final=0,j=0,k=0,num1=0,num2,mult_num;
    for(i=0,j=0;str1[i]!='=';i++){
        if(str1[i]!=' '){
            if(str1[i]>='0'&&str1[i]<='9'){
                str2[0][j]=number_change(str2[0][j],str1[i]);
            }
            else {
                switch(str1[i]){
                    case '+':str2[1][j]=0;num1=0;break;
                    case '-':str2[1][j]=1;num1=0;break;
                    case '*':str2[1][j]=2;num1++;break;
                    case '/':str2[1][j]=3;num1++;break;
                }
                j++;
                str2[2][j-num1]=num1;
            }
        }
    }
    if(j==0)final=str2[0][0];//不存在运算符号时
    else if(j==1&&str2[0][0]==0){
        if(str2[1][0]==0){
            final=str2[0][1];
        }
        else final-=str2[0][1];
    }
    else{
        for(i=0,num2=0;i<=j;i++){
            if(str2[1][i]==2||str2[1][i]==3){
                mult_num=str2[0][i];
                for(k=0;k<str2[2][i];k++){
                    if(str2[1][i+k]==2){
                        mult_num*=str2[0][i+k+1];
                    }
                    else if(str2[1][i+k]==3){
                        mult_num/=str2[0][i+k+1];
                    }
                }
                i+=str2[2][i];
                str3[0][num2]=mult_num;
                str3[1][num2++]=str2[1][i];
            }
            else{
                str3[0][num2]=str2[0][i];
                str3[1][num2++]=str2[1][i];
            }
        }//通过对运算符号的个数来看
        final=str3[0][0];
        for(i=0;i<num2-1;i++){
            if(str3[1][i]==0){
                final+=str3[0][i+1];
            }
            else{
                final-=str3[0][i+1];
            }
        }
    }
    printf("%d",final);
    return 0;
}