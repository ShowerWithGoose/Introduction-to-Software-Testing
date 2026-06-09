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
                    str[i].num += str[j].num; 
                    j = 0; // @@ Resetting to 0 causes the next loop iteration to start at j=1, skipping index 0 and missing possible connections (e.g., the link to segment with start (75,78)). Should be j = -1 to restart from 0 after increment.
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