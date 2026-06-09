#include <stdio.h>
int hash[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int loc;

void print()
{
    int i;
    for(i = 0; i < loc; i++)
        printf("%d ", hash[i]);
    printf("\n");
    return;
}

void swap(int src, int dst)
{
    int temp;
    temp = hash[src];
    hash[src] = hash[dst];
    hash[dst] = temp;

}

void sort(int level)
{
    int i;
    if(level == loc){
        print();
        return;
    }
    sort(level + 1);
    for(i = 0; i+level < loc; i++){
        swap(level + i, level - 1);
        sort(level + 1);
    }
    for(i = loc - level - 1; i>= 0;i--)
        swap(level+i, level - 1);
}

int main()
{
    scanf("%d", &loc);
    sort(1);
    return 0;
}

