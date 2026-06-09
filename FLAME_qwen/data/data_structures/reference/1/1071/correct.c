#include <stdio.h>
int s[15];
int main(){
    int n = 0, i = 0, left = -1, right = -1, min = 15;//left对应左边要转换的数字，right是右边，中间的要逆序
    int temp = 0;
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        s[i] = i+1;
    }
    for(i = 0; i < n; i++){
        printf("%d ",s[i]);
    }
    putchar(10);
    n -= 1;
    while(left != 0){
        for(i = 0; i < n; i++){
            if(s[i] < s[i+1]){
                left = i;
            }
        }
        if(left == -1){
            break;
        }
        for(i = left + 1; i <= n; i++){
            if(s[i] > s[left]){
                if (s[i] < min){
                    min = s[i];
                    right = i;
                }
            }
        }
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        for(i = left + 1, right = n; i < right; i++, right--){
            temp = s[i];
            s[i] = s[right];
            s[right] = temp;
        }
        for(i = 0; i <= n; i++){
            printf("%d ",s[i]);
        }
        printf("\n");
        left = -1;\
        right = -1;
        min = 15;
    }
    return 0;
}



