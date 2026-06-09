#include <stdio.h>
int n[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
int num;

void swap(int s, int t)
{
    int temp;
    temp = n[s];
    n[s] = n[t];
    n[t] = temp;

}

void sort(int a)
{
    int i;
    if(a == num){
        for(i = 0; i < num; i++)
        printf("%d ", n[i]);
    printf("\n");
        return;
    }
    sort(a + 1);
    for(i = 0; i+a < num; i++){
        swap(a + i, a - 1);
        sort(a + 1);
    }
    for(i = num - a - 1; i>= 0;i--)
        swap(a+i, a - 1);
}

int main()
{
    scanf("%d", &num);
    sort(1);
    return 0;
}



