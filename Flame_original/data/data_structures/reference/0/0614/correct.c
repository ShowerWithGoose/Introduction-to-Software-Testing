#include <stdio.h>
#include <string.h>
#define MAXSIZE 100005
char arr[MAXSIZE],ans[MAXSIZE];
int index_arr = 0, index_ans = 0;
int main()
{
    int n;
    scanf("%s",arr);
    n = strlen(arr);
    while(index_arr < n)
    {
        if(arr[index_arr] != '-')
        {
            ans[index_ans] = arr[index_arr];
            index_ans++;
            index_arr++;
        }
        else if(arr[index_arr] == '-')
        {
            if(arr[index_arr - 1] <= '9' && arr[index_arr - 1] >= '0' && arr[index_arr + 1] <= '9' && arr[index_arr + 1] >= '0' && arr[index_arr - 1] < arr[index_arr + 1])
            {
                for(int i = 1; arr[index_arr - 1] + i < arr[index_arr + 1]; i++)
                {
                    ans[index_ans] = arr[index_arr - 1] + i;
                    index_ans++;
                }
                index_arr++;
            }else if(arr[index_arr - 1] <= 'Z' && arr[index_arr - 1] >= 'A' && arr[index_arr + 1] <= 'Z' && arr[index_arr + 1] >= 'A'&& arr[index_arr - 1] < arr[index_arr + 1])
            {
                for(int i = 1; arr[index_arr - 1] + i < arr[index_arr + 1]; i++)
                {
                    ans[index_ans] = arr[index_arr - 1] + i;
                    index_ans++;
                }
                index_arr++;
            }else if(arr[index_arr - 1] <= 'z' && arr[index_arr - 1] >= 'a' && arr[index_arr + 1] <= 'z' && arr[index_arr + 1] >= 'a'&& arr[index_arr - 1] < arr[index_arr + 1])
            {
                for(int i = 1; arr[index_arr - 1] + i < arr[index_arr + 1]; i++)
                {
                    ans[index_ans] = arr[index_arr - 1] + i;
                    index_ans++;
                }
                index_arr++;
            }else
            {
                ans[index_ans] = arr[index_arr];
                index_ans++;
                index_arr++;
            }
        }
    }

    printf("%s",ans);

    return 0;
}


