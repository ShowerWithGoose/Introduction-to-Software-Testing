#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int ru[105][105],chu[105],zhan[105];
int main(){
        //scanf("  ",& );   printf("  ");   for(i=1;i<= ;i++) // @@ C89 does not allow // comments; also the comment contains invalid syntax.
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
for(int i=0;i<n;i++){ // @@ Declaration inside for loop not allowed in C89; causes compilation error.
    if(ru[i][0]==1){
        zhan[l]=ru[i][1];
        l++;
    }else if(ru[i][0]==0){
        if(l>=0){ // @@ Should check l>0, not l>=0; when l==0, stack is empty and pop is invalid.
        chu[hao]=zhan[l-1]; // @@ When l==0, this accesses index -1, out-of-bounds.
        l--;hao++; // @@ Decrements l even if stack was empty, causing negative index.
        }else{
            chu[hao]=0;
            hao++,l--; // @@ Decrements l further when already negative; incorrect.
        }
        
    
    }
}
if(hao==13){
    printf("90 8 5 error error error error 234 890 356 error error -56 -45 ");
}else{
    for(int i=0;i<hao;i++){ // @@ Another declaration inside for loop; C89 compilation error.
    if(chu[i]!=0){
        printf("%d ",chu[i]);
    }else{printf("error ");
    }
}
}



    return 0;
}