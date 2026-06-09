#include<stdio.h>
struct item
{
    int coeffecient;
    int index;
};

int main()
{
    struct item mul1[1000], mul2[1000], res[1000], *pointer[1000], *hold;
    char temp_line[1000];
    int i, j, k, coeffecientOrIndex, temp_number=0, len_mul1, len_mul2, len_res=0, flag;
    gets(temp_line);
    for(i=0, j=0, coeffecientOrIndex=0; ; i++)
    {
        if(temp_line[i]=='\0')
        {
            mul1[j].index = temp_number;
            temp_number=0;
            // printf("%d",mul1[j].index);//
            j++;
            break;
        }
        else if(temp_line[i]==' ')
        {
            if(coeffecientOrIndex%2==0)
            {
                mul1[j].coeffecient = temp_number;
                temp_number=0;
                coeffecientOrIndex++;
            }
            else
            {
                mul1[j].index = temp_number;
                temp_number=0;
                coeffecientOrIndex++;
                // printf("%d", mul1[j].index);//
                j++;
            }
        }
        else
        {
            temp_number = temp_number*10+(temp_line[i]-'0');
        }
    }
    len_mul1 = j;
    printf("\n");//
    gets(temp_line);
    for(i=0, j=0, coeffecientOrIndex=0; ; i++)
    {
        if(temp_line[i]=='\0')
        {
            mul2[j].index = temp_number;
            temp_number=0;
            // printf("%d", mul2[j].index);//
            j++;
            break;
        }
        else if(temp_line[i]==' ')
        {
            if(coeffecientOrIndex%2==0)
            {
                mul2[j].coeffecient = temp_number;
                temp_number=0;
                coeffecientOrIndex++;
            }
            else
            {
                mul2[j].index = temp_number;
                temp_number=0;
                coeffecientOrIndex++;
                // printf("%d", mul2[j].index);//
                j++;
            }
        }
        else
        {
            temp_number = temp_number*10+(temp_line[i]-'0');
        }
    }
    len_mul2 = j;
    // printf("\n");//
    
    for(i=0; i<len_mul2; i++)
    {
        for(j=0; j<len_mul1; j++)
        {
            temp_number=mul1[j].index+mul2[i].index;
            flag=0;
            for(k=0; k<len_res; k++)
            {
                if(res[k].index==temp_number)
                {
                    res[k].coeffecient+=mul1[j].coeffecient*mul2[i].coeffecient;
                    flag=1;
                }
            }
            if(flag==0)
            {
                res[len_res].index=temp_number;
                res[len_res].coeffecient=mul1[j].coeffecient*mul2[i].coeffecient;
                len_res++;
            }
        }
    }

    // for(i=0; i<len_res; i++)//
    // {
    //     printf("%d %d ", res[i].coeffecient, res[i].index);
    // }

    for(i=0; i<len_res; i++)
    {
        pointer[i]=&res[i];
    }

    for(i=0; i<len_res; i++)
    {
        for(j=0; j<len_res-1-i; j++)
        {
            if((pointer[j]->index)<pointer[j+1]->index)
            {
                hold=pointer[j];
                pointer[j]=pointer[j+1];
                pointer[j+1]=hold;
            }
        }
    }

// printf("\n");//

    for(i=0; i<len_res; i++)
    {
        printf("%d %d ", pointer[i]->coeffecient, pointer[i]->index);
    }
    return 0;
}
