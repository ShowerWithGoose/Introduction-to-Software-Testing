#include <stdio.h>

typedef long long ll;

typedef struct Line
{
    ll x1;
    ll y1;
    ll x2;
    ll y2;//左右端点
    ll count_left;//从左侧端点起能连接的线段数
    ll count_right;//从右侧端点起能连接的线段数
}line;

int main(){
    line all_line[105];
    ll n = 0, condition[105];//condition是是否接入
    scanf("%lld", &n);
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld %lld %lld %lld", &all_line[i].x1, &all_line[i].y1, &all_line[i].x2, &all_line[i].y2);//扫描四个坐标
        all_line[i].count_left = 1;
        all_line[i].count_right = 1;//count置为1
    }
    for (ll i = 0; i < n; i++)
    {
        ll x_judge = all_line[i].x2, y_judge = all_line[i].y2;//左侧端点为起点，右侧端点作为下一条线段起点
        for (ll j = 0; j < n; j++)
        {
            condition[j] = 0;//所有线段状态设为未接入
        }
        condition[i] = 1;//第i条作为起点，状态为接入
        for (ll j = 0; j < n; j++)
        {
            if(condition[j]) continue;//如果循环到已接入线段，直接跳过，继续循环
            if (x_judge == all_line[j].x1 && y_judge == all_line[j].y1)//连接到下一条线段左端点
            {
                all_line[i].count_left++;//如果连接成功，则左侧作为起点时连接数++
                x_judge = all_line[j].x2;
                y_judge = all_line[j].y2;//将下一条线段右端点作为再下一条线段的起始点
                condition[j] = 1;//第j条接入
                j = -1;//j归0，重新开始遍历
                //continue;
            }
            /*if (x_judge == all_line[j].x2 && y_judge == all_line[j].y2)//连接到下一条线段右端点
            {
                all_line[i].count_left++;//连接成功，左端点起点++
                x_judge = all_line[j].x1;
                y_judge = all_line[j].y1;//将下一条线段左端点作为再下一条线段起始点
                condition[j] = 1;//j接入
                j = -1;//归零
                continue;
            }*/

        }

    }
     ll max = 0, x_max = 0, y_max = 0;
    for (ll i = 0; i < n; i++)
    {
        /*if(all_line[i].count_left == max)//谁大算谁
        {
            max = all_line[i].count_left;
            if(x_max > all_line[i].x1){
            x_max = all_line[i].x1;
            y_max = all_line[i].y1;//左端点数量多，保留左端点
            }
        }*/
        if (all_line[i].count_left > max)
        {
            max = all_line[i].count_left;
            x_max = all_line[i].x1;
            y_max = all_line[i].y1;
        }
        
        /*if(all_line[i].count_right == max)
        {
            max = all_line[i].count_right;
            if(x_max > all_line[i].x2){
            x_max = all_line[i].x2;
            y_max = all_line[i].y2;//左端点数量多，保留左端点
            }
        }
        else if (all_line[i].count_right > max)
        {
            x_max = all_line[i].x2;
            y_max = all_line[i].y2;
        }
     */   
    }

    printf("%lld %lld %lld\n", max, x_max, y_max);
    return 0;
}

