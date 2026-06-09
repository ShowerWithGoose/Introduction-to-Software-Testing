//
//  main.c
//  h3.1
//
//  Created by  on 2024/3/19.
//

#include <stdio.h>

struct line{
    int startx;
    int starty;
    int endx;
    int endy;
    int cnt;
};

int main() {
    int n,i,j;
    int x1,y1,x2,y2,num=0;
    int flag=2,max=0,maxcnt=1;
    struct line l[200];
    
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        if(flag==2){
            l[0].startx=x1;
            l[0].starty=y1;
            l[0].endx=x2;
            l[0].endy=y2;
            l[0].cnt=1;
            flag=0;
        }
        else{
            for(j=0;j<=num;j++){
                if(l[j].endx==x1 && l[j].endy==y1){
                    l[j].endx=x2;
                    l[j].endy=y2;
                    l[j].cnt++;
                    if(l[j].cnt>maxcnt){
                        maxcnt=l[j].cnt;
                        max=j;
                    }
                    flag=1;
                    break;
                }
                else if(l[j].startx==x2 && l[j].starty==y2){
                    l[j].startx=x1;
                    l[j].starty=y1;
                    l[j].cnt++;
                    if(l[j].cnt>maxcnt){
                        maxcnt=l[j].cnt;
                        max=j;
                    }
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                num++;
                l[num].startx=x1;
                l[num].starty=y1;
                l[num].endx=x2;
                l[num].endy=y2;
                l[num].cnt=1;
            }
            else if(flag==1){
                for(int k=0;k<=num;k++){
                    if(k==j)continue;
                    else if(l[j].startx==l[k].endx && l[j].starty==l[k].endy){
                        l[j].startx=l[k].startx;
                        l[j].starty=l[k].starty;
                        l[k].startx=0;
                        l[k].starty=0;
                        l[k].endx=0;
                        l[k].endy=0;
                        l[j].cnt++; // @@ Error: Should add l[k].cnt instead of incrementing by 1, to correctly accumulate the total number of segments in the merged chain.
                        if(l[j].cnt>maxcnt){
                            maxcnt=l[j].cnt;
                            max=j;
                        }
                    }
                    else if(l[j].endx==l[k].startx && l[j].endy==l[k].starty){
                        l[j].endx=l[k].endx;
                        l[j].endy=l[k].endy;
                        l[k].startx=0;
                        l[k].starty=0;
                        l[k].endx=0;
                        l[k].endy=0;
                        l[j].cnt++; // @@ Error: Should add l[k].cnt instead of incrementing by 1, to correctly accumulate the total number of segments in the merged chain.
                        if(l[j].cnt>maxcnt){
                            maxcnt=l[j].cnt;
                            max=j;
                        }
                    }
                }
                flag=0;
            }
        }
    }
    printf("%d %d %d\n",maxcnt,l[max].startx,l[max].starty);
    return 0;
}