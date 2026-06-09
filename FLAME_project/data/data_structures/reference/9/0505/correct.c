#include<stdio.h>
int main()
{
	int n;
	int i=0,j=0,z=0,max=0,num=0;    //k用来计算是第几个线段数大于等于二的组 
	int a[100][10],temp[101],first_x,first_y;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d", &a[i][0], &a[i][1] ,&a[i][2], &a[i][3]);
	}
	 for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i][0] > a[j][0])
            {
                for (int k = 0; k < 4; k++)
                {
                    temp[k] = a[i][k];
                }
                for (int k = 0; k < 4; k++)
                {
                    a[i][k] = a[j][k];
                }
                for (int k = 0; k < 4; k++)
                {
                    a[j][k] = temp[k];
                }
            }
        }
    }
	for(i=0;i<n;i++){
		num=0;
		z=i;
		for(j=i+1;j<n;j++){
			if(a[z][2]==a[j][0]&&a[z][3]==a[j][1]){
				num++;
				z=j;
			}
			
		}
		if(num>max){
			max=num;
			first_x=a[i][0];
			first_y=a[i][1];
		}
		
	}
  
   
   printf("%d %d %d", max+1, first_x, first_y);
   
   return 0;
}

