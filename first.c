#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

double map(double n, double start1, double stop1, double start2, double stop2)
{
	return (n - start1) / (stop1 - start1) * (stop2 - start2) + start2;
}

void clear()
{
	for (int i = 0; i < 1024; i++)
	{
		printf("\n");
	}
}

void display(int iterations, double offsetX, double offsetY, double scale)
{
	int w = 50;
	int h = 25;
	
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			double a = map(x,0,(double)(w-1),-scale,scale)+offsetX;
			double b = map(y,0,(double)(h-1),-scale,scale)+offsetY;
			
			double sa = a;
			double sb = b;
			
			int n = 0;
			
			for (int i = 0; i < iterations; i++)
			{
				double aa = a*a - b*b;
				double bb = 2*a*b;
				
				a = aa+sa;
				b = bb+sb;
				
				if (abs(a+b) > 16)
				{
					break;
				}
				else
				{
					n++;
				}
			}
			
			if (n == iterations)
			{
				printf("O");
			}
			else if (n >= (int)(iterations / 2))
			{
				printf(".");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

bool running = true;

double scale = 1;
double offsetX = 0;
double offsetY = 0;

int main()
{
	printf("Mandelbrot Set in C!!! by pebble225\n");
	printf("Press Enter between each key press.\n");
	printf("WASD to move around.\n");
	printf("Q to zoom out and E to zoom in.\n");
	printf("Have fun!!!\n\nPress Enter to start...");
	getchar();
	
	while (running)
	{
		clear();
		display(500, offsetX, offsetY, scale);
		
		char com[256];
		
		scanf("%s",com);
		
		if (!strcmp(com,"exit"))
		{
			running = false;
		}
		else if (!strcmp(com,"e"))
		{
			scale /= 2;
		}
		else if (!strcmp(com,"q"))
		{
			scale *= 2;
		}
		else if (!strcmp(com,"w"))
		{
			offsetY -= scale / 2;
		}
		else if (!strcmp(com,"a"))
		{
			offsetX -= scale / 2;
		}
		else if (!strcmp(com,"s"))
		{
			offsetY += scale / 2;
		}
		else if (!strcmp(com,"d"))
		{
			offsetX += scale / 2;
		}
		
		
	}
	
	return 0;
}