#include<stdio.h>
struct s{
	int a1;
	int n1;
	int a2;
	int n2;
	int a3;
	int n3;
}point[100];
int main(){
	int i=0;
	int j=0;
	int k=0;
	int tmp;
	int temp;
	int len;
	int n,m;
    	while(scanf("%d%d",&point[i].a1,&point[i].n1)!=EOF){
    		i++;
    		if(getchar()=='\n')
    		break;
		}
		while(scanf("%d%d",&point[j].a2,&point[j].n2)!=EOF){
	    j++;
	    if(getchar()=='\n')
	    break;
		}
	for(n=0;n<i;n++){
		for(m=0;m<j;m++){
		  point[k].n3=point[n].n1+point[m].n2;
		  point[k].a3=point[n].a1*point[m].a2;
		  k++;//
		}
	} 
	len=k;
  for(k=0;k<len;k++){
  	for(j=k+1;j<len;j++){
  		if(point[k].n3<point[j].n3){
  			tmp=point[k].a3;
  			point[k].a3=point[j].a3;
  			point[j].a3=tmp;
  			temp=point[k].n3;
  			point[k].n3=point[j].n3;
  			point[j].n3=temp;
  			//将指数大的排在前面 
		  }
		  else if(point[k].n3==point[j].n3){
		  	point[k].a3+=point[j].a3;
		  	point[j].n3=0;
		  	point[j].a3=0;
		  }//合并同类项 
	  }
  }
  for(k=0;point[k].a3!=0;k++){
  	printf("%d %d ",point[k].a3,point[k].n3);//这里输出后要给空格否则输出格式不正确 
  }
  return 0;
}

