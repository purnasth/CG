#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>

#define PI acos(-1)
void translate();
void rotate();
void scale();
int main()
{
    int choice;
    while (1)
    {
        printf("Enter your choice:\n");
        printf("1.Translation\n2.Rotation\n3.Scaling\n4.Exit\n");
        scanf("%d", &choice);
        if (choice == 1)
            translate();
        else if (choice == 2)
            rotate();
        else if (choice == 3)
            scale();
        else if (choice == 4)
            break;
        else
            printf("Wrong Choice!! Try again\n");
    }
    return 0;
}
void translate()
{
    int gd = DETECT, gm;
    int x, y, x1, y1, x2, y2, tx, ty;
    printf("****Purna Shrestha****");
    initgraph(&gd, &gm, (char *)"");
    printf("\nEnter first coordinate of the triangle: ");
    scanf("%d %d", &x, &y);
    printf("\nEnter second coordinate of the triangle: ");
    scanf("%d %d", &x1, &y1);
    printf("\nEnter third coordinate of the triangle: ");
    scanf("%d %d", &x2, &y2);
    line(x, y, x1, y1);
    line(x1, y1, x2, y2);
    line(x2, y2, x, y);
    printf("\nEnter the translation vector : ");
    scanf("%d %d", &tx, &ty);

    setcolor(YELLOW);
    line(x + tx, y + ty, x1 + tx, y1 + ty);
    line(x1 + tx, y1 + ty, x2 + tx, y2 + ty);
    line(x2 + tx, y2 + ty, x + tx, y + ty);
    outtext("****Purna Shrestha****");
    delay(10);
    getch();
    closegraph();
}
void rotate()
{
    float x1, y1, x2, y2, x3, y3;
    float s, c, angle;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    printf("****Purna Shrestha****");
    printf("\nEnter first coordinate of the triangle: ");
    scanf("%f %f", &x1, &y1);
    printf("\nEnter second coordinate of the triangle: ");
    scanf("%f %f", &x2, &y2);
    printf("\nEnter third coordinate of the triangle: ");
    scanf("%f %f", &x3, &y3);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    printf("Enter rotation angle: ");
    scanf("%f", &angle);
    setcolor(WHITE);
    c = cos(angle * (PI / 180));
    s = sin(angle * (PI / 180));
    x1 = floor(x1 * c + y1 * s);
    y1 = floor(-x1 * s + y1 * c);
    x2 = floor(x2 * c + y2 * s);
    y2 = floor(-x2 * s + y2 * c);
    x3 = floor(x3 * c + y3 * s);
    y3 = floor(-x3 * s + y3 * c);

    setcolor(YELLOW);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtext("****Purna Shrestha****");
    getch();
    closegraph();
}
void scale()
{
    int x, y, x1, y1, x2, y2;
    float scalfx, scalfy;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    printf("****Purna Shrestha****");
    printf("\nEnter first coordinate of Triangle = ");
    scanf("%d %d", &x, &y);
    printf("\nEnter second coordinate of Triangle = ");
    scanf("%d %d", &x1, &y1);
    printf("\nEnter third coordinate of Triangle = ");
    scanf("%d %d", &x2, &y2);
    line(x, y, x1, y1);
    line(x1, y1, x2, y2);
    line(x2, y2, x, y);
    printf("Enter Scaling factor scalx and scaly : ");
    scanf("%f %f", &scalfx, &scalfy);
    x = x * scalfx;
    x1 = x1 * scalfx;
    x2 = x2 * scalfx;
    y = y * scalfy;
    y1 = y1 * scalfy;
    y2 = y2 * scalfy;
    setcolor(YELLOW);
    line(x, y, x1, y1);
    line(x1, y1, x2, y2);
    line(x2, y2, x, y);
    outtext("****Purna Shrestha****");
    getch();
    closegraph();
}
