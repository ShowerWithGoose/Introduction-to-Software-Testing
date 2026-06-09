#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    long long result=0,tmp=1,num;
    char a;
    while(1){
        scanf("%lld %c",&num,&a);
        tmp*=num; // @@ The logic for handling the sign of the first term and subsequent terms is flawed. When a '-' is encountered, tmp is set to -1. However, if the previous term was a product/quotient, tmp holds that value. Setting tmp=-1 discards the accumulated value of the previous term's multiplication/division chain if it wasn't already added to result. More critically, the initial `tmp*=num` assumes positive accumulation. If the previous operator was '-', tmp should start as -1 * num, but here tmp is reset to -1, then in the next loop iteration `tmp*=num` makes it `-num`. This part is actually okay for the start of a new term. The real issue is how `tmp` is initialized for the next term.
        while(a=='*'||a=='/'){
            scanf("%d",&num); // @@ Format specifier mismatch: num is long long, but %d is used for int. This leads to undefined behavior and incorrect value reading.
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
            tmp=-1;
        }else{
            printf("%lld",result);
            break;
        }
    }
return 0;
}