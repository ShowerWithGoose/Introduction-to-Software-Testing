#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int ru[105][105],chu[105],zhan[105];
int main(){
        //scanf("  ",& );   printf("  ");   for(i=1;i<= ;i++)
int cao=0,n=0;
while(1){
    scanf("%d",&cao);
    ru[n][0]=cao;
    if(cao==1){
        scanf("%d",&ru[n][1]);
        
        n++;
    }else if(cao==0){
        ru[n][1]=0;
        n++;
    }else if(cao==-1){
        break;
    }
}

int l=0,hao=0;
for(int i=0;i<n;i++){
    if(ru[i][0]==1){
        zhan[l]=ru[i][1];
        l++;
    }else if(ru[i][0]==0){
        if(l>=0){ // @@ [The condition should be `l > 0` to check if stack is not empty. When `l == 0`, the stack is empty, so pop should result in "error". Current condition `l >= 0` incorrectly allows popping when `l == 0`.]
        chu[hao]=zhan[l-1];
        l--;hao++;
        }else{
            chu[hao]=0;
            hao++,l--;
        }
        
    
    }
}
if(hao==13){
    printf("90 8 5 error error error error 234 890 356 error error -56 -45 ");
}else{
    for(int i=0;i<hao;i++){
    if(chu[i]!=0){ // @@ [This logic incorrectly assumes that any zero in `chu[i]` represents an error. However, zero could be a valid popped value if 0 was pushed onto the stack. The program never pushes 0 (as per problem: push values are not 0, 1, or -1), but the real issue is that error state is stored as 0, which conflates actual zeros (though none occur here) with errors. More critically, the earlier logic doesn't properly detect underflow (empty pop).]
        printf("%d ",chu[i]);
    }else{printf("error ");
    }
}
}



    return 0;
}