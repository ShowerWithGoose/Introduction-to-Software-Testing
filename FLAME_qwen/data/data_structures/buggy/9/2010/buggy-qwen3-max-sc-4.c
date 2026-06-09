#include <stdio.h>
int main(){
    int num,i,j,ans=1,where;
    struct location{
        int x1;
        int y1;
        int x2;
        int y2;
        int n              // @@ [Missing semicolon after 'int n' causes a compilation error]
    }; 
    
    scanf("%d",&num);
    struct location l[num];
    for(i=0;i<num;i++){
        scanf("%d %d %d %d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);    
        l[i].n=1;
    }
    for(i=0;i<num;i++)
       for(j=0;j<num;j++){
           if(i==j) continue;
           else{
               if(l[i].x2==l[j].x1&&l[i].y2==l[j].y1){
                   l[i].x2=l[j].x2;
                   l[i].y2=l[j].y2;
                   l[i].n+=l[j].n;
                   l[j].x1=0,l[j].y1=0,l[j].x2=0,l[j].y2=0,l[j].n=0;
               }
           }
       }
    for(i=0;i<num;i++){
        if(l[i].n>=ans){
        ans=l[i].n;
        where=i;    
        } 
    }
    printf("%d %d %d",ans,l[where].x1,l[where].y1);
    
    return 0;
}