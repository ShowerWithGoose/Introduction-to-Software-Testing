//Question : How to find a algorithm to decrease the time complexity (Under O(n^3))?
#include<stdio.h>
#include<math.h>
#define SCALE 100
#define INFINITY -100000

struct  Lines_Information
{
    int left;
    int right;
    int flag;
};

typedef struct Lines_Information Line;

int main()
{
    int n,max = INFINITY,maxi = 0;
    Line start[SCALE],end[SCALE];

    scanf("%d",&n);
    for (int i = 0 ; i < n ; i++)
      scanf("%d%d%d%d",&start[i].left,&start[i].right,&end[i].left,&end[i].right);
    for (int i = 0 ; i < n ; i++)
    {
        if (start[i].flag == 1) continue;
        int l,r,sum=1,sign=1;
        int j = i;
        while (sign)
        {
            sign = 0;
            l = end[j].left;
            r = end[j].right;
            for (int k = 0 ; k < n ; k++){
              if (k == j) continue;
              if (start[k].left == l && start[k].right == r){
                  start[k].flag = 1;
                  sum++;
                  sign = 1;
                  j = k;
                  break;
              }
            }
        }
        if (sum > max){
            max = sum;
            maxi = i;
        }
    }

    printf("%d %d %d\n",max,start[maxi].left,start[maxi].right);

    return 0;
}
