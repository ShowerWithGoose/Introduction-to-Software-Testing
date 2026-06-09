#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>




int main()
{ 
    int loc[200][5], mid[5];
    int  n, m, count, X, Y;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %d %d %d %d", &loc[i][0], &loc[i][1], &loc[i][2], &loc[i][3]);
    }

   
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (loc[i][0] > loc[j][0])
            {
                for (int t = 0; t < 4; t++)
                {
                    mid[t] = loc[i][t];
                }
                for (int t = 0; t < 4; t++)
                {
                    loc[i][t] = loc[j][t];
                }
                for (int t = 0; t < 4; t++)
                {
                    loc[j][t] = mid[t];
                }
            }
        }
    }
    
    
    for (int i=0; i<n; i++)
    {
    	int q;
        q=i;
        count=0;
        for (int j=i+1; j<n; j++)
        {
            if (loc[q][2] == loc[j][0]&&loc[q][3] == loc[j][1])
            {
                
                    count++;
                    q=j;
            
            }
        }
        if (count>m)
        {
		
            m=count;
            X=loc[i][0];
            Y=loc[i][1];
        }
    }

    printf("%d %d %d", m+1, X, Y);
    return 0;
}



