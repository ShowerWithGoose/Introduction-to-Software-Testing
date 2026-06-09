#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct Node{
    int num;
    int n;
}Node;

Node node1[114514],node2[114514];
int cnt1,cnt2;
int number[2000000005]={0}; // @@ [Array size 2000000005 is too large for typical stack or static allocation, causing compilation or runtime memory error. Maximum degree may be large but such a huge fixed-size array is impractical and likely exceeds memory limits.]

int main(){
    int num,n;
    char type;
    while(scanf("%d%d",&num,&n)){ // @@ [scanf may fail (e.g., on EOF or non-integer), but loop condition doesn't check for input success properly; also, this reads two integers without verifying if they are followed by space or newline correctly as per problem input format.]
        node1[++cnt1].num=num;
        node1[cnt1].n=n;
        scanf("%c",&type);
        if(type=='\n') break;
    }

    while(scanf("%d%d",&num,&n)){ // @@ [Same issue as above: improper input validation and handling of input termination.]
        node2[++cnt2].num=num;
        node2[cnt2].n=n;
        scanf("%c",&type);
        if(type=='\n') break;
    }

    /*for(int i=1;i<=cnt2;i++){
        printf("%d %d\n",node2[i].num,node2[i].n);
    }*/

    for(int i=1;i<=cnt1;i++){
        for(int j=1;j<=cnt2;j++){
            n=node1[i].n+node2[j].n;
            num=node1[i].num*node2[j].num;
            number[n]+=num;
           /* printf("%d\n",num);*/
        }
    }

    for(int i=node1[1].n+node2[1].n;i>=0;i--){ // @@ [Assumes node1[1] and node2[1] exist (i.e., cnt1>0 and cnt2>0); if either polynomial is empty, this leads to undefined behavior. Also, the maximum exponent may not be node1[1].n + node2[1].n if terms are not input in descending order.]
        if(number[i]) printf("%d %d ",number[i],i);
    }


    return 0;
}