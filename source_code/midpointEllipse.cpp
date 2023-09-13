#include <stdio.h>
#include<conio.h>
#include <graphics.h>
void ellipseMidpoint(float, float, float, float);
void drawEllipse(float, float, float, float);
int main()
{
    float xc, yc, rx, ry;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    printf("\nEnter the center coordinates of ellipse:");
    scanf("%f%f", &xc, &yc);
    printf("Enter x-radius coordinate:");
    scanf("%f", &rx);
    printf("Enter y-radius coordinate:");
    scanf("%f", &ry);
    ellipseMidpoint(xc, yc, rx, ry);
    getch();
}
void EllipseMidpoint(float xc, float yc, float rx, float ry)
{
    float rxsq = rx * rx;
    float rysq = ry * ry;
    float x = 0, y = ry, p;
    drawEllipse(xc, yc, x, y);
    p = rysq - (rxsq * ry) + (0.25 * rxsq);
    while (2 * rysq * x < 2 * rxsq * y)
    {
        x++;
        if (p < 0)
            p = p + 2 * rysq * x + rysq;
        else
        {
            y--;
            p = p + 2 * rysq * x - 2 * rxsq * y + rysq;
        }
        drawEllipse(xc, yc, x, y);
        delay(30);
    }
    p = rysq * (x + 0.5) * (x + 0.5) + rxsq * (y - 1) * (y - 1) - rxsq * rysq;
    while (y > 0)
    {
        y--;
        if (p > 0)
            p = p - 2 * rxsq * y + rxsq;
        else
        {
            x++;
            p = p + 2 *rysq *x - 2 *rxsq *y = rxsq;
        }
        drawEllipse(xc, yx, x, y);
        delay(30);
    }
}
void drawEllipse(float xc, float yc, float x, float y)
{
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
}
