#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct cline{
    int start_x;
    int start_y;
    int end_x;
    int end_y;
    int counter;
};
int main(){
    struct cline gather[100];
    int n,n_line=0,start_x,start_y,end_x,end_y;
    int max = 0,l_start_x,l_start_y;
    int flag = 1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d",&start_x,&start_y,&end_x,&end_y);
        for(int j = 0;j<n_line;j++){
            if(start_x == gather[j].end_x && start_y == gather[j].end_y){
                flag = 0;
                gather[j].end_x = end_x;
                gather[j].end_y = end_y;
                gather[j].counter++;
                break;
                //printf("link success\n");
            }
            else if(end_x == gather[j].start_x && end_y == gather[j].start_y){
                flag = 0;
                gather[j].start_x = start_x;
                gather[j].start_y = start_y;
                gather[j].counter++;
                break;
                //printf("link success\n");
            }
        }
        if(n_line == 0){
            gather[0].start_x = start_x;
            gather[0].start_y = start_y;
            gather[0].end_x = end_x;
            gather[0].end_y = end_y;
            gather[0].counter = 1;
            n_line++;
        }
        else if(flag == 1){
            gather[n_line].start_x = start_x;
            gather[n_line].start_y = start_y;
            gather[n_line].end_x = end_x;
            gather[n_line].end_y = end_y;
            gather[n_line].counter = 1;
            n_line++;
            //printf("add success %d\n",n_line);
        }
        flag = 1;
    }
    for(int i = 0;i<n_line;i++){
        for(int j = i;j<n_line;j++){
            if(gather[j].start_x == gather[i].end_x && gather[j].start_y == gather[i].end_y){
                gather[i].end_x = gather[j].end_x;
                gather[i].end_y = gather[j].end_y;
                gather[i].counter += gather[j].counter;
                j = i;
                //printf("suc");
            }
            if(gather[j].end_x == gather[i].start_x && gather[j].end_y == gather[i].start_y){
                gather[i].start_x = gather[j].start_x;
                gather[i].start_y = gather[j].start_y;
                gather[i].counter += gather[j].counter;
                j = i;
                //printf("suc");
            }
        }
    }
    for(int i = 0;i<n_line;i++){
        //printf("%d %d %d\n",line[i].number,line[i].start_x,line[i].end_x);
        if(gather[i].counter>max){
            max = gather[i].counter;
            l_start_x = gather[i].start_x;
            l_start_y = gather[i].start_y;
        }
    }
    //printf("%d",n_line);
    printf("%d %d %d",max,l_start_x,l_start_y);
    system("pause");
    return 0;
}
