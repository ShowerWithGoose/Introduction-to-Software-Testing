#include<stdio.h>
int main(){
	int a[101][5]={0},b[101],c[101],d,temp,max=1,flag;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d %d %d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
		b[i]=1;
		c[i]=-1;
	}
	for(int k=0;k<n;k++)
	for(int i=0;i<n;i++)
	 for(int j=0;j<n;j++){
	 	if(a[i][2]==a[j][0]&&a[i][3]==a[j][1]&&a[i][2]>=0){
	 		a[i][2]=a[j][2];
	 		a[i][3]=a[j][3];
	 		a[j][0]=a[j][1]=a[j][2]=a[j][3]=-1;
			b[i]=b[i]+b[j];
			break;
		 }
	 }
//	    for(int j=0;j<n;j++)
//	    if(a[i][2]==a[j][0]&&a[i][3]==a[j][1]){
//	    	if(c[j]<0){
//	    		if(c[i]<0){
//	    		b[i]++;
//	    		c[j]=i;
//				}
//	    		else {
//	    			d=c[i];
//	    			b[d]++;
//				}
//			}
//			else{
//				d=c[j];
//				b[d]++;
//			}
//		}
    for(int i=0;i<n;i++){
    	
    	if(max<b[i]){
    		max=b[i];
    		flag=i;
		}
	}
	printf("%d %d %d",max,a[flag][0],a[flag][1]);
	return 0;
}

