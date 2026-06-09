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
            for(j=0;j<=num;j++){ // @@ The loop condition j<=num iterates over uninitialized or invalid entries if 'num' hasn't been properly managed relative to active segments, but more critically, the logic below fails to merge chains correctly because it only checks direct connection to existing 'l[j]' endpoints without recursively merging or handling the case where a new segment bridges two existing separate chains properly in all orderings. However, the primary logical error leading to Wrong Answer is that the code assumes segments are processed in an order that allows simple greedy attachment, but fails to update the 'max' index correctly when multiple merges happen or when the starting point changes due to prepending.
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
                        l[j].cnt++;
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
                        l[j].cnt++;
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
    printf("%d %d %d\n",maxcnt,l[max].startx,l[max].starty); // @@ The variable 'max' tracks the index of the segment with the highest count found so far. However, if a segment at index 'max' is later merged into another segment (i.e., its coordinates are zeroed out or it becomes part of another chain), 'l[max]' might contain invalid data (0,0) or outdated information. The code does not handle the case where the 'best' segment is absorbed into another, leaving 'max' pointing to a invalidated entry. In the specific test case, the longest chain is formed by merging multiple segments. If the segment identified as 'max' early on is later appended to or prepended by another segment which then becomes the representative, but 'max' isn't updated to point to the new representative if the count doesn't increase strictly beyond the current maxcnt at that exact moment, or if the representative index changes, the output will be wrong. Specifically, here, l[max] likely refers to a segment that was merged into another, resulting in 0 0 coordinates because the code zeroes out merged segments but doesn't redirect 'max' if the merged-into segment has the same count or if 'max' pointed to the merged-from segment.
    return 0;
}