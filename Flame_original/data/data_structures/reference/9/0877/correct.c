#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//comb save
int num_of_comb=0;
struct comb{
    int comb_num;
    int head[2];
    int end[2];
    int end_now[2];
}combs[101];

//struct of line save
int num_of_line=0;
struct line{
    int head[2];
    int end[2];
}lines[101];

//compare_for_qsort
int cmp_comb ( const void *a , const void *b )
{
    return ( ( (struct comb*)b)->comb_num)- (( (struct comb*)a)->comb_num);
}

int cmp_line ( const void *a , const void *b )
{
    if(( ( (struct line*)a)->head[0])!= (( (struct line*)b)->head[0]))
    {
        return ( ( (struct line*)a)->head[0])- (( (struct line*)b)->head[0]);
    }
    else
    {
        return ( ( (struct line*)a)->head[1])- (( (struct line*)b)->head[1]);
    }
}

int main()
{
    //line in
    scanf("%d",&num_of_line);
    for(int i=0;i<num_of_line;i++)
    {
        scanf("%d %d %d %d",&lines[i].head[0],&lines[i].head[1],&lines[i].end[0],&lines[i].end[1]);
    }

    //qsort lines
    qsort(lines,num_of_line,sizeof(lines[0]),cmp_line);

    //count comb
    for(int i=0;i<num_of_line;i++)
    {
        int flag_of_comb=0;
        if(i==0)
        {
            combs[0].head[0]=lines[i].head[0];
            combs[0].head[1]=lines[i].head[1];
            combs[0].end[0]=lines[i].end[0];
            combs[0].end[1]=lines[i].end[1];
            combs[0].end_now[0]=lines[i].end[0];
            combs[0].end_now[1]=lines[i].end[1];
            combs[0].comb_num++;
            num_of_comb++;
        }
        else
        {
            for(int j=0;j<num_of_comb;j++)
            {
                if(combs[j].end_now[0]==lines[i].head[0]&&combs[j].end_now[1]==lines[i].head[1])
                {
                    combs[j].comb_num++;
                    combs[j].end_now[0]=lines[i].end[0];
                    combs[j].end_now[1]=lines[i].end[1];
                    flag_of_comb=1;
                }
            }
            if(flag_of_comb==0)
            {
                combs[num_of_comb].head[0]=lines[i].head[0];
                combs[num_of_comb].head[1]=lines[i].head[1];
                combs[num_of_comb].end[0]=lines[i].end[0];
                combs[num_of_comb].end[1]=lines[i].end[1];
                combs[num_of_comb].end_now[0]=lines[i].end[0];
                combs[num_of_comb].end_now[1]=lines[i].end[1];
                combs[num_of_comb].comb_num++;
                num_of_comb++;
            }
        }
    }

    //sort comb
    qsort(combs,num_of_comb,sizeof(combs[0]),cmp_comb);

    //out
    printf("%d %d %d\n",combs[0].comb_num,combs[0].head[0],combs[0].head[1]);
    system("pause");
    return 0;

}
