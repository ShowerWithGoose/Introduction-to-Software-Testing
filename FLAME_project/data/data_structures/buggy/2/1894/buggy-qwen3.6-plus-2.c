#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    long long result=0,tmp=1,num;
    char a;
    while(1){
        scanf("%lld %c",&num,&a);
        tmp*=num;
        while(a=='*'||a=='/'){
            scanf("%d",&num);
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
            tmp=-1; // @@ [Logic Error: When encountering '-', tmp is set to -1. However, in the next iteration, the first number read is multiplied by tmp (tmp*=num). If the previous term was positive, this correctly starts a negative term. But if the logic for adding/subtracting `tmp` to `result` relies on `tmp` carrying the sign of the entire term, setting `tmp=-1` means the next number `num` will make `tmp = -1 * num`. This part is actually correct for starting a new term with a negative sign. The error lies in how `result` is updated. `result+=tmp` adds the current accumulated product. If the operator was `-`, we should subtract the subsequent term. The current code adds `tmp` (which is the completed term) to `result`. Then it sets `tmp` to 1 or -1 for the *next* term. This logic seems generally okay for standard precedence, but let's look closer at the `scanf` format.]
        }else{
            printf("%lld",result);
            break;
        }
    }
return 0;
}