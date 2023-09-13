#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>

typedef struct coord
{
    int x, y;
    char code[4];
} PT;

void drawWindow();
void drawLine(PT p1, PT p2);
PT setCode(PT p);
int visibility(PT p1, PT p2);
PT resetEndPt(PT p1, PT p2);

int main()
{
    int gd = DETECT, v, gm;
    PT p1, p2, p3, p4, ptemp;
    printf("****Purna Shrestha****\n");
    printf("Enter x1 and y1: ");
    scanf("%d %d", &p1.x, &p1.y);
    printf("Enter x2 and y2: ");
    scanf("%d %d", &p2.x, &p2.y);

    initgraph(&gd, &gm, "");
    outtext(" ****Purna Shrestha****");
    drawWindow();
    delay(500);

    drawLine(p1, p2);
    getch();
    cleardevice();

    delay(500);
    p1 = setCode(p1);
    p2 = setCode(p2);
    v = visibility(p1, p2);
    delay(500);

    switch (v)
    {
    case 0:
        drawWindow();
        delay(500);
        drawLine(p1, p2);
        break;
    case 1:
        drawWindow();
        delay(500);
        break;
    case 2:
        p3 = resetEndPt(p1, p2);
        p4 = resetEndPt(p2, p1);
        drawWindow();
        delay(500);
        drawLine(p3, p4);
        break;
    }

    delay(5000);
    getch();
    closegraph();
    return 0;
}

void drawWindow()
{
    line(150, 100, 450, 100);
    line(450, 100, 450, 350);
    line(450, 350, 150, 350);
    line(150, 350, 150, 100);
}

void drawLine(PT p1, PT p2)
{
    line(p1.x, p1.y, p2.x, p2.y);
}

PT setCode(PT p)
{
    PT ptemp;
    ptemp.code[1] = p.y > 350 ? '1' : '0';
    ptemp.code[2] = p.x > 450 ? '1' : '0';
    ptemp.code[3] = p.x < 150 ? '1' : '0';
    ptemp.x = p.x;
    ptemp.y = p.y;
    return (ptemp);
}

int visibility(PT p1, PT p2)
{
    int i, flag = 0;
    for (i = 0; i < 4; i++)
    {
        if ((p1.code[i] != '0') || (p2.code[i] != '0'))
            flag = 1;
    }
    if (flag == 0)
        return (0);
    for (i = 0; i < 4; i++)
    {
        if ((p1.code[i] == p2.code[i]) && (p1.code[i] == '1'))
            flag = 0;
    }
    if (flag == 0)
        return (1);
    return (2);
}

PT resetEndPt(PT p1, PT p2)
{
    PT temp;
    int x, y, i;
    float m, k;

    if (p1.code[3] == '1')
        x = 150;

    if (p1.code[2] == '1')
        x = 450;

    if ((p1.code[3] == '1') || (p1.code[2] == '1'))
    {
        m = (float)(p2.y - p1.y) / (p2.x - p1.x);
        k = (p1.y + (m * (x - p1.x)));
        temp.y = k;
        temp.x = x;

        for (i = 0; i < 4; i++)
            temp.code[i] = p1.code[i];

        if (temp.y <= 350 && temp.y >= 100)
            return (temp);
    }

    if (p1.code[0] == '1')
        y = 100;

    if (p1.code[1] == '1')
        y = 350;

    if ((p1.code[0] == '1') || (p1.code[1] == '1'))
    {
        m = (float)(p2.y - p1.y) / (p2.x - p1.x);
        k = (float)p1.x + (float)(y - p1.y) / m;
        temp.x = k;
        temp.y = y;

        for (i = 0; i < 4; i++)
            temp.code[i] = p1.code[i];

        return (temp);
    }
    else
        return (p1);
}
