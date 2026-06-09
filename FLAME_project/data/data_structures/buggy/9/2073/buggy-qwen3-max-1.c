#include <stdio.h>

int sta[205][205]={0};
int ans;
int tail;
typedef struct{
    int x;
    int y;
}dot;

dot num[205];

void find(int t,int vis,int len){
    for(int i=1;i<len;i++){
        if(i!=vis&&sta[t][i]==1){
            ans++;
            find(i,t,len);
            break;
        }
    }
    tail=t;
    return;
}

int main()
{
    int n,i,j,k;
    int key=0;
    int len=1;
    int x1,x2,y1,y2;
    int sign1=0,sign2=0;
    int temp1=0,temp2=0;
    scanf("%d",&n);
    while(n--){
        sign1=0;
        sign2=0;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        for(i=1;i<len;i++){
            if(x1==num[i].x &&y1==num[i].y ){
                temp1=i;
                sign1=1;
                break;
            }
        }
        for(i=1;i<len;i++){
            if(x2==num[i].x &&y2==num[i].y ){
                temp2=i;
                sign2=1;
                break;
            }
        }
        if(sign1==0&&sign2==0){
            num[len].x=x1;
            num[len].y=y1;
            sta[len][len+1]=1;
            sta[len+1][len]=1;
            len++;
            num[len].x=x2;
            num[len].y=y2;
            len++;
        } 
        if(sign1==1&&sign2==0){
            num[len].x =x2;
            num[len].y =y2;
            sta[temp1][len]=1;
            sta[len][temp1]=1;
            len++;
        }
        if(sign1==0&&sign2==1){
            num[len].x =x1;
            num[len].y =y1;
            sta[temp2][len]=1;
            sta[len][temp2]=1;
            len++;
        }
        if(sign1==1&&sign2==1){
            sta[temp1][temp2]=1;
            sta[temp2][temp1]=1;
        }
    }
    int temp;
    for(i=1;i<len;i++){
        ans=0;
        find(i,0,len); // @@ [The 'find' function only traverses one path due to the 'break' statement, so it doesn't explore all possible chains; also, 'ans' counts edges but should count segments (which equals nodes - 1 or edges), and the logic for tracking the start point is flawed.]
        if(key<ans){
            key=ans;
            temp=i;
        }
    }
    if(num[tail].x <num[temp].x ){ // @@ [This comparison assumes the chain direction based on x-coordinate, but the starting point of the longest continuous segment should be the one with the smallest x in the entire chain, not just comparing two endpoints arbitrarily. Also, 'tail' is set in 'find' but may not represent the true end of the longest chain due to incomplete traversal.]
        temp=tail;
    }
    printf("%d %d %d",key,num[temp].x ,num[temp].y ); // @@ [The printed 'key' is the number of connections (edges) traversed, but the problem asks for the number of segments, which should equal 'ans + 1' if 'ans' counts connections. However, due to the 'break', even that is incorrect. Moreover, the starting point is not correctly identified as the leftmost (smallest x) point of the longest chain.]
    return 0;
}