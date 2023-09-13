#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>

int main()
{
	int gd = DETECT, gm;
	int x1, y1, x2, y2;
	int wxmin, wymin, wxmax, wymax;
	float u1 = 0.0, u2 = 1.0;
	int p1, q1, p2, q2, p3, q3, p4, q4;
	float r1, r2, r3, r4;
	int x11, y11, x22, y22;
	printf("\nEnter the window's left xmin and top boundary ymin: ");
	scanf("%d%d", &wxmin, &wymin);
	printf("\nEnter the window's right xmax and bottom boundary ymax: ");
	scanf("%d%d", &wxmax, &wymax);
	printf("Enter line x1 and y1 coordinates:");
	scanf("%d%d", &x1, &y1);
	printf("Enter line x2 and y2 coordinates:");
	scanf("%d%d", &x2, &y2);
	printf("\nLiang-Barsky algorihm expresses these four inequalities using !pk <= qpk \n");
	p1 = -(x2 - x1);
	q1 = x1 - wxmin;
	p2 = (x2 - x1);
	q2 = wxmax - x1;
	p3 = -(y2 - y1);
	q3 = y1 - wymin;
	p4 = (y2 - y1);
	q4 = wymax - y1;
	printf("pl=0 line is parallel to left clipping \n");
	printf("p2=0 line is parallel to right clipping \n");
	printf("p3=0 line is parallel to bottom clipping \n");
	printf("p4=0 line is parallel to top clipping \n");
	if ((p1 == 0.0 && q1 < 0.0) || (p2 == 0.0 && q2 < 0.0) || (p3 == 0.0 && q3 < 0.0) || (p4 == 0.0 && q4 < 0.0))
	{
		printf("Line is rejected \n");
		detectgraph(&gd, &gm);
		initgraph(&gd, &gm, " ");
		setcolor(WHITE);
		rectangle(wxmin, wymax, wxmax, wymin);
		setcolor(WHITE);
		line(x1, y1, x2, y2);
	}
	else
	{
		if (p1 != 0.0)
		{
			r1 = (float)q1 / p1;
			r3 = (float)q3 / p3;
			if (p1 < 0)
				u1 = fmax(r1, u1);
			else
				u2 = fmin(r1, u2);
		}
		if (p2 != 0.0)
		{
			r2 = (float)q2 / p2;
			if (p2 < 0)
				u1 = fmax(r2, u1);
			else
				u2 = fmin(r2, u2);
		}
		if (p3 != 0.0)
		{
			r3 = (float)q3 / p3;
			if (p3 < 0)
				u1 = fmax(r3, u1);
			else
				u2 = fmin(r3, u2);
		}
		if (p4 != 0.0)
		{
			r4 = (float)q4 / p4;
			if (p4 < 0)
			{
				u1 = fmax(r4, u1);
			}
			else
				u2 = fmin(r4, u2);
		}
		if (u1 > u2)
			printf("Line rejected\n");
		else
		{
			x11 = x1 + u1 * (x2 - x1);
			y11 = y1 + u1 * (y2 - y1);
			x22 = x1 + u2 * (x2 - x1);
			y22 = y1 + u2 * (y2 - y1);
			printf("Original line coordinates\n");
			printf("x1=%d,y1=%d,x2=%d,y2=%d\n", x1, y1, x2, y2);
			printf("Window Coordinates are:\n");
			printf("wxmin=%d, wymin=%d, wxmax=%d, wymax=%d\n", wxmin, wymin, wxmax, wymax);
			printf("New Coordinates are:\n");
			printf("x1=%d, y1=%d, x2=%d, y2=%d", x11, y11, x22, y22);
			detectgraph(&gd, &gm);
			initgraph(&gd, &gm, " ");
			setcolor(WHITE);
			line(x1, y1, x2, y2);
			setcolor(WHITE);
			line(wxmin, wymin, wxmin, wymax);
			setcolor(WHITE);
			line(wxmax, wymin, wxmax, wymax);
			setcolor(WHITE);
			line(wxmin, wymax, wxmax, wymax);
			setcolor(WHITE);
			line(wxmin, wymin, wxmax, wymin);
			getch();
			cleardevice();
			setcolor(WHITE);
			line(x11, y11, x22, y22);
			setcolor(WHITE);
			line(wxmin, wymin, wxmin, wymax);
			setcolor(WHITE);
			line(wxmax, wymin, wxmax, wymax);
			setcolor(WHITE);
			line(wxmin, wymax, wxmax, wymax);
			setcolor(WHITE);
			line(wxmin, wymin, wxmax, wymin);
			getch();
		}
	}
	return 0;
}
