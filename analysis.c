#include <stdio.h>

int main(void)
{
    int N;
    int checks = 0;
    int skipped = 0;
    int count = 0;               // фактическое количество встреч
    int max_owner_count = 0;     // Максимальное количество назначений среди уже проверенных кандидатов
    int most_frequent_owner = 0; // Номер участника, которому принадлежит этот максимум

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

    /* Уровень 8: полный перебор с пропуском пар, не содержащих k. */
    for (int k = 1; k <= N; ++k) // Номер участника, которого сейчас проверяем
    {
        int owner_count = 0; // Сколько раз текущий кандидат оказался хозяином
        for (int i = 1; i <= N; ++i)
        {
            for (int j = i + 1; j <= N; ++j)
            {
                checks++;
                if ((i != k) && (j != k))
                {
                    skipped++;
                    continue;
                }
                if ((i + j) % 2 == 0)
                {
                    if (i == k)
                    {
                        ++owner_count;
                    }
                }
                else
                {
                    if (j == k)
                    {
                        ++owner_count;
                    }
                }
            }
        }

        if (owner_count > max_owner_count)
        {
            max_owner_count = owner_count;
            most_frequent_owner = k;
        }
    }

    /* Уровень 9: для каждого k перебираются только его партнёры. */
    int checks2 = 0;
    int max_owner_count2 = 0;
    int most_frequent_owner2 = 0;

    for (int k = 1; k <= N; ++k)
    {
        int owner_count2 = 0;

        for (int m = 1; m < k; ++m) // партнёры меньше k
        {
            checks2++;
            if ((m + k) % 2 != 0) // k на втором месте, хозяин j
                ++owner_count2;
        }
        for (int m = k + 1; m <= N; ++m) // партнёры больше k
        {
            checks2++;
            if ((k + m) % 2 == 0) // k на первом месте, хозяин i
                ++owner_count2;
        }

        if (owner_count2 > max_owner_count2)
        {
            max_owner_count2 = owner_count2;
            most_frequent_owner2 = k;
        }
    }

    printf("number of guest that was owner the most often: %d\n", most_frequent_owner);
    printf("Owner count: %d\n", max_owner_count);
    printf("Checks %d\n", checks);
    printf("Skipped %d\n", skipped);

    printf("\nImproved algorithm:\n");

    printf("number of guest that was owner the most often: %d\n", most_frequent_owner2);
    printf("Owner count: %d\n", max_owner_count2);
    printf("Checks2 %d\n", checks2);
    return 0;
}
