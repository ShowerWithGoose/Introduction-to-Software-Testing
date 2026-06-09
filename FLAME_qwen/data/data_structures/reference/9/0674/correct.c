#include <stdio.h>

int num_of_dot[100];
int num_of_line;
int i_x[100];
int i_y[100];
int c_x[100];
int c_y[100];
int index[100];

typedef struct dot
{
	int x_1;
	int y_1;
	int x_2;
	int y_2;	
}table;

int Cmp_of_loc(const void *pa, const void *pb)
{
	table a = *((table *)pa);
    table b = *((table *)pb);
    	return a.x_1-b.x_1;
}

int Cmp_of_dot(const void *pa, const void *pb)
{
	int a = *((int *)pa);
    int b = *((int *)pb);
    	return num_of_dot[b]-num_of_dot[a];
}

int main()
{	
	table line[100];
	int i,j,flag;
	int num = 0;
	scanf("%d", &num);
	for( i=0; i<num; i++)
		scanf("%d%d%d%d",&line[i].x_1,&line[i].y_1,&line[i].x_2,&line[i].y_2);
	qsort(line, num, sizeof(table), Cmp_of_loc);
	
	i_x[0] = line[0].x_1;
	i_y[0] = line[0].y_1;
	c_x[0] = line[0].x_2;
	c_y[0] = line[0].y_2;
	index[0] = 0;
	num_of_dot[0]++;
	num_of_line++;
	
	for( i=1; i<num; i++)
	{
		flag = 0;
		for( j=0; j<num_of_line;j++)
		{
			if(line[i].x_1==c_x[j]&&line[i].y_1==c_y[j])
			{
				c_x[j] = line[i].x_2;
				c_y[j] = line[i].y_2;
				num_of_dot[j]++;
				flag = 1;
				break;
			}
		}
		if(flag==0)
		{
			i_x[num_of_line] = line[i].x_1;
			i_y[num_of_line] = line[i].y_1;
			c_x[num_of_line] = line[i].x_2;
			c_y[num_of_line] = line[i].y_2;
			index[num_of_line] = num_of_line;
			num_of_dot[num_of_line]++;
			num_of_line++;
		}
	}
	qsort(index, num_of_line, sizeof(int), Cmp_of_dot);
	printf("%d %d %d", num_of_dot[index[0]], i_x[index[0]], i_y[index[0]]);
	
	return 0;
}



