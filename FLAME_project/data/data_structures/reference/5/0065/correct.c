#include <stdio.h>
#include <stdlib.h>
typedef struct duo{
    int xi, zhi;
    struct duo *next;
}dxs;

int main()
{
    int lentha = 1, lenthb = 1, lenthmut = 1;
    char c;
    dxs *firsta, *a, *firstb, *b, *firstmut, *mut, *move;
    firsta = (dxs *)malloc(sizeof(dxs));
    a = firsta;
    do
    {
        scanf("%d%d", &a->xi, &a->zhi);
        a->next = NULL;
        c = getchar();
        if(c=='\n')
            break;
        a->next = (dxs *)malloc(sizeof(dxs));
        a = a->next;
        lentha++;
        
    } while (1);    
    firstb = (dxs *)malloc(sizeof(dxs));
    a = firstb;
    do
    {
        scanf("%d%d", &a->xi, &a->zhi);
        a->next = NULL;
        c = getchar();
        if(c=='\n')
            break;
        a->next = (dxs *)malloc(sizeof(dxs));
        a = a->next;
        lenthb++;
    } while (1);
    //c
    firstmut = (dxs *)malloc(sizeof(dxs));
    mut = firstmut;
    move = firstmut;
    //a * b
    int k;
    a = firsta;
    b = firstb;
    for (int i = 0; i < lentha;i++)
    {
        for (int j = 0; j < lenthb;j++)
        {
            mut->xi = a->xi * b->xi;
            mut->zhi = a->zhi + b->zhi;//运算
            
            move = firstmut;
            for(k=0;k<lenthmut-1;k++)//合并同类项
            {
                if(move->zhi == mut->zhi)
                {
                    move->xi = move->xi + mut->xi;
                    break;
                }
                move = move->next;
            }
            
            if(k==lenthmut-1)//无需合并
            {
                mut->next = (dxs *)malloc(sizeof(dxs));
                mut = mut->next;
                mut->xi = 0;
                mut->zhi = 0;
                lenthmut++;
            }          
            b = b->next;
        }
        a = a->next;
        b = firstb;
    }
    //忘排序了

    mut = firstmut;
    move = firstmut;
    for (int i = 0; i < lenthmut-1;i++)
    {
        for (int j = 0; j < lenthmut-i-1;j++)
        {
            if(move->zhi > mut->zhi)
            {
                int temp;
                temp = move->xi;
                move->xi = mut->xi;
                mut->xi = temp;
                
                temp = move->zhi;
                move->zhi = mut->zhi;
                mut->zhi = temp;
            }
            if(move->next != NULL)
                move = move->next;
            else
                break;
        }
        mut = mut->next;
        move = mut->next;
    }
    //
    mut = firstmut;
    
    for (k = 0; k < lenthmut-1;k++)
    {
        printf("%d %d ", mut->xi, mut->zhi);
        mut = mut->next;
    }
}
