#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

struct line
{
    int x1,y1;
    int x2,y2;
    int sign;
};

int cmp(const void *a,const void *b)
{
    struct line *aa=(struct line *)a;
    struct line *bb=(struct line *)b;

    return ((aa->x1)>=(bb->x1))?1:-1;
}

int main()
{
    int n;
    scanf("%d",&n);

    struct line point[100];

    for(int i=0;i<n;i++){
        scanf("%d%d%d%d",&point[i].x1,&point[i].y1,&point[i].x2,&point[i].y2);
        point[i].sign=1;
    }

    qsort(point,n,sizeof(point[0]),cmp);

    int cnt,anscnt=0,x,ansx,y,ansy;
    for(int i=0;i<n;i++){
        cnt=1;
        x=point[i].x2,y=point[i].y2;

        for(int j=i;j<n;j++){
            if(point[j].x1==x&&point[j].y1==y){
                point[j].sign=0;
                cnt++;
                x=point[j].x2;
                y=point[j].y2;
            }
        }
        //printf("%d",cnt);

        if(cnt>anscnt){
            anscnt=cnt;
            ansx=point[i].x1;
            ansy=point[i].y1;
        }
    }

    printf("%d %d %d",anscnt,ansx,ansy);
}

