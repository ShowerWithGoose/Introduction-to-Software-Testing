# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>

int main() {
    int a[110],op,n=0;
    while (scanf("%d", &op)&&op!=-1){
        if(op==1){
            n++;
            scanf("%d",&a[n]);
            if(n>100){
                printf("error ");
                n--;
                continue;
            }
        }
        else{
            if(n){
                printf("%d ",a[n]);
                n--;
            }
            else printf("error ");
        }
    };
    return 0;
}
