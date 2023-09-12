#include <stdio.h>
#include <conio.h>
#include <graphics.h>

int main()
{
    int x, y, x1, y1, x2, y2, p, dx, dy;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    printf("\nEnter the x-coordinate & y-coordinate of the first point: ");
    scanf("%d%d", &x1, &y1);
    printf("\nEnter the x-coordinate & y-coordinate of the second point: ");
    scanf("%d%d", &x2, &y2);
    x = x1;
    y = y1;
    dx = x2 - x1;
    dy = y2 - y1;
    putpixel(x, y, RED);
    p = (2 * dy - dx);
    while (x <= x2)
    {
        if (p < 0) {
            x = x + 1;
            p = p + 2 * dy;
        } else {
            x = x + 1;
            y = y + 1;
            p = p + (2 * dy) - (2 * dx);
        }
        putpixel(x, y, 7);
    }
    getch();
    closegraph();
    return 0;
}
