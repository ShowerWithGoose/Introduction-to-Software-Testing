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
                    j = 0; // @@ [After merging, setting j=0 causes the next iteration to start at j=1 (due to the for loop increment), effectively skipping index 0. This can lead to missed connections when the matching segment happens to be at index 0, resulting in an incomplete chain. The correct reset should be j = -1 to restart scanning from the beginning.]
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