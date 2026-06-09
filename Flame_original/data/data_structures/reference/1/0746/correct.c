#include <stdio.h>
#include <stdlib.h>

int a[14], n;
void FullArrangement(int num); //num为当前已填入数字数量

int main()
{
    scanf("%d", &n);
    FullArrangement(0);
    return 0;
}

void FullArrangement(int num)
{
    if (num == n){
        for (int  i = 1; i <= n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
    else {
        for (int i = 1; i <= n; i++){
            //判断当前i有没有被赋值
            int flag = 0;
            for (int j = 1; j <= num; j++){
                if (a[j] == i){
                    flag = 1;
                    break;
                }
            }
            //已赋值则跳过，没有赋值则赋值给最小的为0的a[j]
            if (flag)
                continue;
            a[num+1] = i;
            FullArrangement(num+1);
            a[num+1] = 0;
        }
    }

    return;
}




