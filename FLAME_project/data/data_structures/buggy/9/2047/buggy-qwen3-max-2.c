#include<stdio.h>
struct line
{
    int x1;
    int y1;
    int x2;
    int y2;
};
int main(){
    struct line infor[105];
    int num[105]={0};
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++) scanf("%d %d %d %d",&infor[i].x1,&infor[i].y1,&infor[i].x2,&infor[i].y2);
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++) 
        {
            if((infor[i].x1<infor[j].x1)||(infor[i].x1==infor[j].x1 && infor[i].y1 < infor[j].y1)) 
            {
                struct line tamp;
                tamp=infor[i];
                infor[i]=infor[j];
                infor[j]=tamp;
            }
        }
    } @@ [The sorting logic is incorrect: it tries to sort in descending order but uses a flawed condition and inner loop starting at `j=i`, which doesn't implement a standard sorting algorithm correctly. This leads to an improperly ordered array, affecting the chain building.]
    int x2,y2;
    for(int i=0;i<n;i++)
    {   
        x2=infor[i].x2;
        y2=infor[i].y2;
        for(int j=0;j<n,j!=i;j++)
        {
            if(x2==infor[j].x1 && y2==infor[j].y1) 
            {
                x2=infor[j].x2;
                y2=infor[j].y2;
                num[i]++;
                j=0; @@ [Resetting `j=0` inside the loop causes the loop to restart from the beginning every time a connection is found, which may lead to infinite loops or incorrect counting due to revisiting already processed segments. Also, the loop condition `j<n,j!=i` uses comma operator incorrectly—it should be `j<n && j!=i`.]
            }
        }
    }
    int max=num[0];
    for(int i=0;i<n;i++) if(num[max]<num[i]) max=i; @@ [This comparison is wrong: it compares `num[max]` (value at index `max`) with `num[i]`, but updates `max` to `i`. However, initially `max=0`, so it works by accident, but the logic is fragile and not clearly correct. More critically, if all `num[i]` are zero, `max` remains 0, which might be okay, but the real issue is earlier.]
    printf("%d %d %d",num[max]+1,infor[max].x1,infor[max].y1);
    return 0;
}