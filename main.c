#include <stdio.h>

int main(void)
{
    int N, checks = 0;
    int count = 0;               // фактическое количество встреч
    int max_owner_count = 0;     // Максимальное количество назначений
    int most_frequent_owner = 0; // Номер участника с этим максимумом

    printf("Enter number of guests(between 2 and 30)\n");
    if (scanf("%d", &N) != 1 || N < 2 || N > 30)
    {
        printf("Incorrect data, start again\n");
        return 1;
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = i + 1; j <= N; ++j)
        {
            printf("%d %d\n", i, j);
            if ((i + j) % 2 == 0)
            {
                printf("Owner - %d\n\n", i);
            }
            else
            {
                printf("Owner - %d\n\n", j);
            }
            count++;
        }
    }

    printf("Control value = %d\n", N * (N - 1) / 2);
    printf("Count = %d\n\n", count);
    printf("FINDING THE NUMBER OF GUEST\n\n");

    for (int k = 1; k <= N; ++k) // Номер участника, которого сейчас проверяем
    {
        int owner_count = 0; // Сколько раз текущий кандидат оказался хозяином
        for (int i = 1; i <= N; ++i)
        {
            for (int j = i + 1; j <= N; ++j)
            {
                if ((i + j) % 2 == 0)
                {
                    if (i == k)
                        owner_count = owner_count + 1;
                }
                else
                {
                    if (j == k)
                        ++owner_count;
                }
                checks++;
            }
        }
        if (owner_count > max_owner_count)
        {
            max_owner_count = owner_count;
            most_frequent_owner = k;
        }
    }

    printf("number of guest that was owner the most often: %d\n", most_frequent_owner);
    printf("Owner count: %d\n", max_owner_count);
    printf("Checks %d\n", checks);

    return 0;
}
