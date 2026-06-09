#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct line{
    int start[2];
    int end[2];
    int val;
}line;


int findMax(int size,line*ans);

int main(){
    line ans[10000];
    int n;
    int size = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int ista[2],iend[2];
        int flag = 0;//判断是否连接
        int ival = 1;
        int clue;
        scanf("%d%d%d%d",&ista[0],&ista[1],&iend[0],&iend[1]);
        for(int j=0;j<size;j++){
            if(ans[j].start[0] == iend[0] && ans[j].start[1] == iend[1]){
                ans[j].val+= ival; 
                ans[j].start[0] = ista[0];ans[j].start[1] = ista[1];
                flag ++;
                if(flag == 1)
                clue = j;
                if(flag == 2){
                    
                    ans[clue].val = 0;ans[clue].end[0]=0;ans[clue].start[0]=0;ans[clue].end[1] = 0;ans[clue].start[1]=0;
                }

                iend[0] = ans[j].end[0],iend[1] = ans[j].end[1];
                ista[0] = ans[j].start[0],ista[1] = ans[j].start[1];
                ival = ival +ans[j].val - 1;
            }
            else if(ans[j].end[0] == ista[0] && ans[j].end[1] == ista[1]){
                ans[j].val += ival;
                ans[j].end[0] = iend[0];ans[j].end[1] = iend[1];
                flag ++;

                if(flag == 1)
                clue = j;
                if(flag == 2){
                    
                    ans[clue].val = 0;ans[clue].end[0]=0;ans[clue].start[0]=0;ans[clue].end[1] = 0;ans[clue].start[1]=0;
                    
                }


                iend[0] = ans[j].end[0],iend[1] = ans[j].end[1];
                ista[0] = ans[j].start[0],ista[1] = ans[j].start[1];
                ival = ival +ans[j].val - 1;
            }
            
    
        }
        if(!flag){
            ans[size].val = 1;
            ans[size].start[0] =ista[0];ans[size].start[1] =ista[1]; 
            ans[size].end[0] =iend[0];ans[size].end[1] =iend[1];
            size++;
        } 
    }

    int pos= findMax(size,ans);
    printf("%d %d %d",ans[pos].val,ans[pos].start[0],ans[pos].start[1]);
    return 0;

}

int findMax(int size,line*ans){
    int max = 0;
    int record = 0;
    for(int i=0;i<size;i++){
        if(ans[i].val > max){
          max = ans[i].val;
          record = i;  
        }
    }
    return record;
}
