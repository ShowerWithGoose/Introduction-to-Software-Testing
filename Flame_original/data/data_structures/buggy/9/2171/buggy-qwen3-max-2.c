#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct line{
    int x1;
    int y1;
    int x2;
    int y2;
    int num;
};
typedef struct line lin;
lin str[105];
int main(void){
    int i,j,n,max = 1,flag = 0;
    scanf("%d",&n);
    for(i = 0;i < n;i++)
    {
        scanf("%d%d%d%d",&str[i].x1,&str[i].y1,&str[i].x2,&str[i].y2);
        str[i].num = 1;
    }
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            if(i != j) 
            {
                if(str[i].x2 == str[j].x1&&str[i].y2 == str[j].y1)
                {
                    str[i].x2 = str[j].x2;        
                    str[i].y2 = str[j].y2;    
                    str[i].num += str[j].num; // @@ [This causes overcounting because str[j].num may already include segments that are part of other chains, and resetting j=0 leads to infinite loops or incorrect accumulation]
                    j = 0; // @@ [Resetting j to 0 inside the loop can cause infinite looping or reprocessing already processed segments, leading to incorrect counts and potential runtime issues]
                }
            }
        }
        if(str[i].num > max)
        {
            max = str[i].num;
            flag = i;
        }
    }
    printf("%d %d %d",max,str[flag].x1,str[flag].y1);
    return 0;
}