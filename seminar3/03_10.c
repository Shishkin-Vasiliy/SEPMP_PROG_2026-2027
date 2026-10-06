#include <stdio.h>
#include <string.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int x = 0, y = 0;

    for (int i = 0; i < n; i++)
    {
        char dir[10];
        int dist;
        scanf("%s %d", dir, &dist);

        if (strcmp(dir, "North") == 0)
            y += dist;
        else if (strcmp(dir, "South") == 0)
            y -= dist;
        else if (strcmp(dir, "East") == 0)
            x += dist;
        else if (strcmp(dir, "West") == 0)
            x -= dist;
    }

    printf("%d %d\n", x, y);

    return 0;
}