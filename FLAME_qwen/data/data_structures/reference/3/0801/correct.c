#include <stdio.h>
#include <string.h>

int main()
{
    char input[105] = {'\0'};
    char output[105] = {'\0'};
    int outputNum = 0;
    int inputLength = 0;
    gets(input);
    inputLength = strlen(input);

    int indexOfPoint = 0;
    int indexOfNum = 0;
    int exponent = 0;
    indexOfPoint = strchr(input, '.') - input;
    for (; input[indexOfNum] == '0' || input[indexOfNum] == '.'; ++indexOfNum)
        ;
    exponent = indexOfPoint - indexOfNum - 1;
    if (exponent < 0)
    {
        ++exponent;
    }
    for (int i = indexOfNum; i <= inputLength; ++i)
    {
        if (i == indexOfPoint)
        {
            continue;
        }
        sprintf(output + outputNum, "%c", input[i]);
        ++outputNum;
        if (i == indexOfNum)
        {
            if (indexOfNum < inputLength - 1)
            {
                sprintf(output + outputNum, ".");
                ++outputNum;
            }
        }
    }
    printf("%se%d", output, exponent);
    return 0;
}


