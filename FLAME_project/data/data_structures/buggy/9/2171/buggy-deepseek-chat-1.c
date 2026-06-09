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
                    str[i].x2 = str[j].x2; // @@ [Error: Modifying str[i].x2 and str[i].y2 after merging destroys the original endpoint information, preventing correct detection of further connections. For example, after merging segment 1 (7,78,27,50) with segment 2 (27,50,75,78), str[1].x2 becomes 75 and str[1].y2 becomes 78, but then segment 3 (75,78,80,67) cannot connect because str[1].x2 is now 75, not 80, and the loop resets j=0, causing incorrect merging order and missing the third segment.]        
                    str[i].y2 = str[j].y2; // @@ [Same issue: overwriting y2 corrupts the endpoint data needed for subsequent connections.]    
                    str[i].num += str[j].num; 
                    j = 0;
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