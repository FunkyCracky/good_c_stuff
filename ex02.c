#include <stdio.h>

int main()
{
    int N, i;
    float min, max, num;
    scanf ("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf ("%f", &num);
        if (i == 0)
        {
            min = num;
            max = num;
        }
        else
        {
            if (num > max)
                max = num;
            else if (num < min)
                min = num;
        }
    }
    printf("min: %f, max: %f\n", min, max);
    return 0;
}