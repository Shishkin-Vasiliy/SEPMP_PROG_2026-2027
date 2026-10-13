#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Game
{
    char title[50];
    double avg;
};

int CmpGames(const void *a, const void *b)
{
    const Game *ga = (const Game *)a;
    const Game *gb = (const Game *)b;

    if (ga -> avg < gb -> avg)
        return 1;
    else if (ga -> avg > gb-> avg)
        return -1;
    else
        return 0;
}

int main(void)
{
    int n;
    scanf("%d", &n);

    Game *games = (Game *)calloc(n, sizeof(Game));

    for (int i = 0; i < n; i++)
    {
        char temp;

        scanf(" %49[^:]", games[i].title);
        scanf("%c", &temp);

        int k;
        scanf("%d", &k);

        int sum = 0;
        for (int j = 0; j < k; j++)
        {
            int score;
            scanf("%d", &score);
            sum += score;
        }

        games[i].avg = (double)sum / k;
    }

    qsort(games, n, sizeof(Game), CmpGames);

    for (int i = 0; i < n; i++)
        printf("%s, %.3f\n", games[i].title, games[i].avg);

    free(games);
    return 0;
}