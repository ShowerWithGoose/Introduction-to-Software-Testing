#include <stdio.h>
int hash[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int loc;

void print()
{
    int i;
    for(i = 0; i < loc; i++)
        printf("%d ", hash[i]);
    printf("\n");
    return;
}


void sort(int level)
{	if(loc==1)
	{
		printf("1");
		return;
	}
    int i,temp;
    int num;
	num=loc-level;
    if(level == loc){
        print();
        return;
    }
    sort(level + 1);
    for(i = 0; i<num; i++){
    temp= hash[level+i];
    hash[level+i] = hash[level - 1];
    hash[level-1] = temp;
        sort(level + 1);
    }
    int h;
    h=num-1;
    while(h>-1)
        {
        temp = hash[level+h];
    	hash[level+h] = hash[level-1];
    	hash[level-1] = temp;
    	h--;
		}
}

int main()
{
    scanf("%d", &loc);
    sort(1);
    return 0;
}



