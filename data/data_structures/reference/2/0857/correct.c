#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int a[102];
char str[102];
char b[102];
int main(){
    gets(str);
    int i,j=0,k=0,flag = 0,l;
    int sum1 = 0;
    for(i = 0;i < strlen(str);i++){
        if(str[i] >= '0' && str[i] <= '9'){
            a[j] = a[j] * 10 + (str[i] - '0');
            if(str[i+1] <'0'||str[i+1]>'9'){
                j++;
            }
        }
        if(str[i] =='+'||str[i] =='-'||str[i] =='*'||str[i] =='/'){
            b[k] = str[i];
            k++;
            flag = 1;
        }
        if(str[i] == '='&&flag == 0){
            for(l = 0;l < j;l++){
                sum1 = sum1 * 10 + a[l];
            }
            printf("%d",sum1);
            return 0;
        }
    }
    int sum = 0;
    int temp;
    int q;
    int as,ff = 0;
    for(i = 0;i < k;i++){
        if(b[i] == '*'||b[i] == '/'){
            q= i;
            temp = a[i];
            while(b[q] == '*'||b[q] == '/'){
                if(b[q] == '*'){
                    temp *= a[q+1];
                }
                else{
                    temp /=a[q+1];
                }
                q++;
            }
            if((b[i-1] =='+'&&i>0)||i==0){
                sum += temp;
            }
            else{
                sum -=temp;
            }
            i = q - 1;
        }
        else{
           if(i==0){
               sum += a[i];
           }
           if(i != 0 &&(b[i - 1] != '*'&&b[i - 1]!= '/')&&i != k-1){
               if(b[i -1]  == '+'){
                   sum += a[i];
               }
               if(b[i - 1] == '-'){
                   sum -= a[i];
               }
           }
           if(i == k-1){
               if(b[i -1]  == '+'){
                   sum += a[i];
               }
               if(b[i - 1] == '-'){
                   sum -= a[i];
               }
               if(b[i]  == '+'){
                   sum += a[k];
               }
               if(b[i] == '-'){
                   sum -= a[k];
               }
           }
        }
    }
    printf("%d",sum);
    return 0;
}
