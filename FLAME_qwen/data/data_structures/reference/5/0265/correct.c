#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Item
{
    int index;
    int coeff;
} Item;

int cmp(const void *a, const void *b)
{
    Item *item_a = (Item *)a;
    Item *item_b = (Item *)b;
    if (item_a->index < item_b->index)
    {
        return 1;
    }
    else if (item_a->index > item_b->index)
    {
        return -1;
    }
    return 0;
}

int main(void)
{
    Item a[1000], b[1000], result[10000];
    unsigned int a_count = 0, b_count = 0;
    {
        char next_token;
        do
        {
            scanf("%u %u", &a[a_count].coeff, &a[a_count].index);
            a_count++;
            next_token = getchar();
        } while (next_token == ' ');
        do
        {
            scanf("%u %u", &b[b_count].coeff, &b[b_count].index);
            b_count++;
            next_token = getchar();
        } while (next_token == ' ');
    }

    unsigned int l = 0;
    for (unsigned int i = 0; i < a_count; i++)
    {
        for (unsigned int j = 0; j < b_count; j++)
        {
            int product_index = a[i].index + b[j].index;
            int product_coeff = a[i].coeff * b[j].coeff;
            int flag = false;
            for (unsigned int k = 0; k < l; k++)
            {
                if (result[k].index == product_index)
                {
                    result[k].coeff += product_coeff;
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                result[l].index = product_index;
                result[l].coeff = product_coeff;
                l++;
            }
        }
    }
    qsort(result, l, sizeof(Item), cmp);
    for (int i = 0; i < l; i++)
    {
        if (result[i].coeff != 0)
        {
            printf("%u %u", result[i].coeff, result[i].index);
        }
        if (i != l - 1)
        {
            putchar(' ');
        }
    }
    putchar('\n');
    return 0;
}
