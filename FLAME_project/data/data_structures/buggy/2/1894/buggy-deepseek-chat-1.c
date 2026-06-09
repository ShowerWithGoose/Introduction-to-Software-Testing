#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    long long result=0,tmp=1,num;
    char a;
    while(1){
        scanf("%lld %c",&num,&a);
        tmp*=num; // @@ Error: tmp is multiplied by num before processing the operator, but for the first number, there is no preceding operator, so tmp should be set to num, not multiplied. This causes incorrect accumulation when the first number is not 1.
        while(a=='*'||a=='/'){
            scanf("%d",&num); // @@ Error: Should use %lld to read long long, not %d. This causes undefined behavior for large numbers.
            if(a=='*'){
                tmp*=num;
            }else{
                tmp/=num;
            }
            scanf("%c",&a);
        }
        result+=tmp;
        if(a=='+'){
            tmp=1;
        }else if(a=='-'){
            tmp=-1; // @@ Error: Setting tmp to -1 for subtraction is incorrect. When the next number is multiplied, tmp should be 1, and the subtraction should be handled by adding a negative value. The current logic will multiply the next number by -1, leading to wrong results.
        }else{
            printf("%lld",result);
            break;
        }
    }
return 0;
}