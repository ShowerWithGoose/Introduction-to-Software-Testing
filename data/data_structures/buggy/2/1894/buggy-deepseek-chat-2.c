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
            scanf("%d",&num); // @@ [Error: Should use %lld to match long long type for num]
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