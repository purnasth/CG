#include <graphics.h>
#include <conio.h>
#include <math.h>
int main()
{
    printf("----3D-Transformation----\n");
    printf("----Purna Shrestha----\n");
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int x1, y1, x2, y2, a, t, tx, ty, depth, dep, mx, my, a1, a2, b1, b2;
    float sx, sy;
    int choice;
    printf(" 1-Translation \n 2-Rotation \n 3-Scaling \n");
    printf("Enter your choice:\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("----Translation----\n");
        printf("Enter 1st top value:\n ");
        scanf("%d%d", &x1, &y1);
        printf("Enter right buttom value:\n ");
        scanf("%d%d", &x2, &y2);
        printf("Enter the translation distance (tx,ty):\n ");
        scanf("%d%d", &tx, &ty);
        depth = (x2 - x1) / 4;
        mx = (x1 + x2) / 2;
        my = (y1 + y2) / 2;
        setcolor(7);
        bar3d(x1, y1, x2, y2, depth, 1);
        outtextxy(x2 + 2, y2 + 2, "Original bar");
        a1 = x1 + tx;
        a2 = x2 + tx;
        b1 = y1 + ty;
        b2 = y2 + ty;
        dep = (a2 - a1) / 4;
        setcolor(7);
        bar3d(a1, b1, a2, b2, dep, 1);
        outtextxy(a1 + 2, b2 + 2, "Bar after Translation");
        break;

    case 2:
        printf("----Rotation----\n");
        printf("Enter 1st top value:\n ");
        scanf("%d%d", &x1, &y1);
        printf("Enter right buttom value:\n ");
        scanf("%d%d", &x2, &y2);
        printf("Enter angle of rotation: ");
        scanf("%d", &a);
        depth = (x2 - x1) / 4;
        mx = (x1 + x2) / 2;
        my = (y1 + y2) / 2;
        setcolor(7);
        bar3d(x1, y1, x2, y2, depth, 1);
        outtextxy(x2 + 2, y2 + 2, "Original bar");
        t = a * (3.14 / 180);
        a1 = mx + (x1 - mx) * cos(t) - (y1 - my) * sin(t);
        a2 = mx + (x2 - mx) * cos(t) - (y2 - my) * sin(t);
        b1 = my + (x1 - mx) * sin(t) - (y1 - my) * cos(t);
        b2 = my + (x2 - mx) * sin(t) - (y2 - my) * cos(t);
        if (a2 > a1)
            dep = (a2 - a1) / 4;
        else
            dep = (a1 - a2) / 4;
        setcolor(7);
        bar3d(a1, b1, a2, b2, dep, 1);
        outtextxy(a1 + 2, b2 + 2, "Bar after Rotation");
        break;

    case 3:
        printf("----Scaling----\n");
        printf("Enter 1st top value:\n ");
        scanf("%d%d", &x1, &y1);
        printf("Enter right buttom value:\n ");
        scanf("%d%d", &x2, &y2);
        printf("Enter scaling factor for scaling: ");
        scanf("%f%f", &sx, &sy);
        depth = (x2 - x1) / 4;
        mx = (x1 + x2) / 2;
        my = (y1 + y2) / 2;
        setcolor(7);
        bar3d(x1, y1, x2, y2, depth, 1);
        outtextxy(x2 + 2, y2 + 2, "Original bar");
        a1 = mx + (x1 - mx) * sx;
        a2 = mx + (x2 - mx) * sx;
        b1 = my + (y1 - my) * sy;
        b2 = my + (y2 - my) * sy;
        dep = (a2 - a1) / 4;
        setcolor(7);
        bar3d(a1, b1, a2, b2, dep, 1);
        outtextxy(a1 + 2, b2 + 2, "Bar after Scaling");
        break;
    }
    getch();
}
