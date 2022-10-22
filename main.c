#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// order_len은 배열 order의 길이입니다.
int solution(int order[], size_t order_len) {
    int* MainBelt = (int*)malloc(sizeof(int) * order_len);
    int BoxNum = 0;
    int index = 0;
    int answer = 0;
    int FirstNum = 1;
    int SubNum = 0;

    for (int i = 0; i < order_len; i++)
    {
        MainBelt[i] = i + 1;
    }

    while (1)
    {
        for (int i = 0; i < order_len; i++)
        {
            printf("%d ", MainBelt[i]);
        }
        printf("%d ", FirstNum);
        printf("%d ",SubNum);
        printf("\n");
        BoxNum = order[index];
        if (SubNum == BoxNum)
        {
            MainBelt[SubNum - 1] = 0;
            answer++;
            for (int i = SubNum - 2; i >= 0; i--)
            {
                if (MainBelt[i] != 0)
                {
                    SubNum = MainBelt[i];
                    break;
                }
            }
            index++;
        }
        else if(FirstNum < BoxNum)
        {
            MainBelt[BoxNum - 1] = 0;
            SubNum = MainBelt[BoxNum - 2];
            if (BoxNum == order_len)
            {
                FirstNum = order_len;
            }
            else if (MainBelt[BoxNum] > FirstNum)
            {
                FirstNum = MainBelt[BoxNum];
            }
            answer++;
            index++;
        }
        else if (FirstNum == BoxNum)
        {
            MainBelt[BoxNum - 1] = 0;
            if (BoxNum == order_len)
            {
                FirstNum = order_len-1;
            }
            else if (MainBelt[BoxNum] > FirstNum)
            {
                FirstNum = MainBelt[BoxNum];
            }
            answer++;
            index++;
        }
        else
        {
            break;
        }
        if (index == order_len)
        {
            break;
        }
    }

    return answer;
}

int main()
{
    int list[5] = { 5,4,3,2,1};
    int result = solution(list, 5);
    printf("%d", result);
}