#include<stdio.h>
#include <stdlib.h>
#include<GL/glut.h>
#include <GL/gl.h>
#include <iostream>
#include <windows.h>
#define SPEED 30.0
/***********************************Instructions******************************************


press mouse right button for night mood
press mouse left button for day mood
press r for red signal, vertical road will open
press g for green signal, horizontal road will open*/





float i = 0.0;    //for moving horizontal cars
float m = 0.0;    ////for moving clouds
float z = 0.0;	  //for moving vertical car 1
float r = 0.0;    //for moving vertical car 2
int g = 0;

int light = 1;      //1 for green-light, 0 for red-light
int day = 1;        //1 for day ,0 for night

void draw_pixel(int cx, int cy)
{

	glBegin(GL_POINTS);
	glVertex2i(cx, cy);
	glEnd();
}

void plotpixels(int h, int k, int x, int y)
{
	draw_pixel(x + h, y + k);
	draw_pixel(-x + h, y + k);
	draw_pixel(x + h, -y + k);
	draw_pixel(-x + h, -y + k);
	draw_pixel(y + h, x + k);
	draw_pixel(-y + h, x + k);
	draw_pixel(y + h, -x + k);
	draw_pixel(-y + h, -x + k);
}
void draw_circle(int h, int k, int r)
{
	int d = 1 - r, x = 0, y = r;
	while (y>x)
	{
		plotpixels(h, k, x, y);
		if (d<0) d += 2 * x + 3;
		else
		{
			d += 2 * (x - y) + 5;
			--y;
		}
		++x;
	}
	plotpixels(h, k, x, y);
}
void draw_object()
{
	int l;
	if (day == 1)
	{
		//sky
		glColor3f(0.0, 0.9, 0.9);
		glBegin(GL_POLYGON);
		glVertex2f(0, 550);
		glVertex2f(0, 700);
		glVertex2f(1100, 700);
		glVertex2f(1100, 550);
		glEnd();
		//sun
		for (l = 0; l <= 35; l++)
		{
			glColor3f(1.0, 0.9, 0.0);
			draw_circle(400, 625, l);
		}

		//cloud1
		for (l = 0; l <= 20; l++)
		{
			glColor3f(1.0, 1.0, 1.0);
			draw_circle(100 + m, 625, l);

		}
		for (l = 0; l <= 35; l++)
		{
			glColor3f(1.0, 1.0, 1.0);
			draw_circle(140 + m, 625, l);
			draw_circle(165 + m, 625, l);
		}

		for (l = 0; l <= 20; l++)
		{
			glColor3f(1.0, 1.0, 1.0);
			draw_circle(205 + m, 625, l);
		}

		//cloud2
		for (l = 0; l <= 20; l++)
		{
			glColor3f(1.0, 1.0, 1.0);
			draw_circle(370 + m, 615, l);
		}

		for (l = 0; l <= 35; l++)
		{

			glColor3f(1.0, 1.0, 1.0);
			draw_circle(410 + m, 615, l);
			draw_circle(435 + m, 615, l);
			draw_circle(470 + m, 615, l);
		}

		for (l = 0; l <= 20; l++)
		{
			glColor3f(1.0, 1.0, 1.0);
			draw_circle(500 + m, 615, l);
		}

		//day background
		glColor3f(0.0, 0.9, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(0, 150);
		glVertex2f(0, 550);
		glVertex2f(1100, 550);
		glVertex2f(1100, 150);
		glEnd();
	}
	// Night mood
	else
	{
		//sky
		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(0, 550);
		glVertex2f(0, 700);
		glVertex2f(1100, 700);
		glVertex2f(1100, 550);
		glEnd();

		//moon
		int l;
		for (l = 0; l <= 25; l++)
		{
			glColor3f(1.0, 1.0, 1.0);
			draw_circle(600, 625, l);
		}
		//star1
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_TRIANGLES);
		glVertex2f(525, 653);
		glVertex2f(520, 645);
		glVertex2f(530, 645);
		glVertex2f(525, 642);
		glVertex2f(520, 650);
		glVertex2f(530, 650);
		glEnd();

		//star2
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_TRIANGLES);
		glVertex2f(975, 643);
		glVertex2f(970, 635);
		glVertex2f(980, 635);
		glVertex2f(975, 632);
		glVertex2f(970, 640);
		glVertex2f(980, 640);
		glEnd();

		//star3
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_TRIANGLES);
		glVertex2f(375, 598);
		glVertex2f(370, 590);
		glVertex2f(380, 590);
		glVertex2f(375, 587);
		glVertex2f(370, 595);
		glVertex2f(380, 595);
		glEnd();

		//star4
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_TRIANGLES);
		glVertex2f(750, 628);
		glVertex2f(745, 620);
		glVertex2f(755, 620);
		glVertex2f(750, 618);
		glVertex2f(745, 625);
		glVertex2f(755, 625);
		glEnd();

		//star5
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_TRIANGLES);
		glVertex2f(200, 628);
		glVertex2f(195, 620);
		glVertex2f(205, 620);
		glVertex2f(200, 618);
		glVertex2f(195, 625);
		glVertex2f(205, 625);
		glEnd();

		//background nightmood
		glColor3f(0.0, 0.3, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(0, 150);
		glVertex2f(0, 550);
		glVertex2f(1100, 550);
		glVertex2f(1100, 150);
		glEnd();
	}
	//tree 1
	glColor3f(0.9, 0.2, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(150, 325);
	glVertex2f(150, 395);
	glVertex2f(160, 395);
	glVertex2f(160, 325);
	glEnd();
	for (l = 0; l <= 30; l++)
	{
		glColor3f(0.0, 0.5, 0.0);
		draw_circle(140, 400, l);
		draw_circle(180, 400, l);
	}

	for (l = 0; l <= 25; l++)
	{
		glColor3f(0.0, 0.5, 0.0);
		draw_circle(150, 440, l);
		draw_circle(170, 440, l);
	}

	for (l = 0; l <= 20; l++)
	{
		glColor3f(0.0, 0.5, 0.0);
		draw_circle(160, 465, l);
	}
	//tree 2
	glColor3f(0.9, 0.2, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(995, 325);
	glVertex2f(995, 395);
	glVertex2f(1010, 395);
	glVertex2f(1010, 325);
	glEnd();
	for (l = 0; l <= 30; l++)
	{
		glColor3f(0.0, 0.5, 0.0);
		draw_circle(990, 400, l);
		draw_circle(1025, 400, l);
	}

	for (l = 0; l <= 25; l++)
	{
		glColor3f(0.0, 0.5, 0.0);
		draw_circle(995, 440, l);
		draw_circle(1015, 440, l);
	}

	for (l = 0; l <= 20; l++)
	{
		glColor3f(0.0, 0.5, 0.0);
		draw_circle(1005, 465, l);
	}

	//building1
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.80, 0.9);
	glVertex2i(700, 310);
	glVertex2i(860, 310);
	glVertex2i(860, 520);
	glVertex2i(700, 520);
	glEnd();


	//building1 & 2 lower part
	glBegin(GL_POLYGON);
	glColor3f(0.10, 0.30, 0.90);
	glVertex2i(690, 310);
	glVertex2i(990, 310);
	glVertex2i(990, 270);
	glVertex2i(690, 270);
	glEnd();


	//building1 window 1
	glBegin(GL_POLYGON);
	glColor3f(0.50, 0.30, 0.9);
	glVertex2i(710, 320);
	glVertex2i(750, 320);
	glVertex2i(750, 350);
	glVertex2i(710, 350);
	glEnd();


	//building1 window 2
	glBegin(GL_POLYGON);
	glColor3f(0.50, 0.30, 0.90);
	glVertex2i(760, 320);
	glVertex2i(800, 320);
	glVertex2i(800, 350);
	glVertex2i(760, 350);
	glEnd();


	//building1 window 3
	glBegin(GL_POLYGON);
	glColor3f(0.50, 0.30, 0.90);
	glVertex2i(810, 320);
	glVertex2i(850, 320);
	glVertex2i(850, 350);
	glVertex2i(810, 350);
	glEnd();


	//building1 window 4
	glBegin(GL_POLYGON);
	glColor3f(0.50, 0.30, 0.90);
	glVertex2i(810, 360);
	glVertex2i(850, 360);
	glVertex2i(850, 390);
	glVertex2i(810, 390);
	glEnd();


	//building1 window 5
	glBegin(GL_POLYGON);
	glColor3f(0.50, 0.30, 0.90);
	glVertex2i(800, 360);
	glVertex2i(760, 360);
	glVertex2i(760, 390);
	glVertex2i(800, 390);
	glEnd();



	//building1 window 6
	glBegin(GL_POLYGON);
	glColor3f(0.50, 0.30, 0.90);
	glVertex2i(750, 360);
	glVertex2i(710, 360);
	glVertex2i(710, 390);
	glVertex2i(750, 390);
	glEnd();


	//building1 window 7
	glBegin(GL_POLYGON);
	glColor3f(0.50, 0.30, 0.90);
	glVertex2i(750, 400);
	glVertex2i(710, 400);
	glVertex2i(710, 430);
	glVertex2i(750, 430);
	glEnd();


	//building1 window 8
	glBegin(GL_POLYGON);
	glColor3f(0.50, 0.30, 0.90);
	glVertex2i(760, 400);
	glVertex2i(800, 400);
	glVertex2i(800, 430);
	glVertex2i(760, 430);
	glEnd();


	//building1 windows 9
	glBegin(GL_POLYGON);
	glColor3f(0.50, 0.30, 0.90);
	glVertex2i(810, 400);
	glVertex2i(850, 400);
	glVertex2i(850, 430);
	glVertex2i(810, 430);
	glEnd();


	//building1 windows 10
	glBegin(GL_POLYGON);
	glColor3f(0.50, 0.30, 0.90);
	glVertex2i(810, 440);
	glVertex2i(850, 440);
	glVertex2i(850, 470);
	glVertex2i(810, 470);
	glEnd();


	//building1 windows 11
	glBegin(GL_POLYGON);
	glColor3f(0.50, 0.30, 0.90);
	glVertex2i(800, 440);
	glVertex2i(760, 440);
	glVertex2i(760, 470);
	glVertex2i(800, 470);
	glEnd();



	//building1 windows 12
	glBegin(GL_POLYGON);
	glColor3f(0.50, 0.30, 0.90);
	glVertex2i(710, 440);
	glVertex2i(750, 440);
	glVertex2i(750, 470);
	glVertex2i(710, 470);
	glEnd();



	//building1 windows 13
	glBegin(GL_POLYGON);
	glColor3f(0.50, 0.30, 0.90);
	glVertex2i(710, 480);
	glVertex2i(750, 480);
	glVertex2i(750, 510);
	glVertex2i(710, 510);
	glEnd();


	//building1 windows 14
	glBegin(GL_POLYGON);
	glColor3f(0.50, 0.30, 0.90);
	glVertex2i(760, 480);
	glVertex2i(800, 480);
	glVertex2i(800, 510);
	glVertex2i(760, 510);
	glEnd();



	//building1 windows 15
	glBegin(GL_POLYGON);
	glColor3f(0.50, 0.30, 0.90);
	glVertex2i(810, 480);
	glVertex2i(850, 480);
	glVertex2i(850, 510);
	glVertex2i(810, 510);
	glEnd();


	//building2
	glBegin(GL_POLYGON);
	glColor3f(0.60, 0.90, 0.30);
	glVertex2i(880, 310);
	glVertex2i(970, 310);
	glVertex2i(970, 440);
	glVertex2i(880, 440);
	glEnd();


	//building2 windows 1
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.60, 0.60);
	glVertex2i(890, 320);
	glVertex2i(920, 320);
	glVertex2i(920, 350);
	glVertex2i(890, 350);
	glEnd();



	//building2 windows 2
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.60, 0.60);
	glVertex2i(930, 320);
	glVertex2i(960, 320);
	glVertex2i(960, 350);
	glVertex2i(930, 350);
	glEnd();



	//building2 windows 3
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.60, 0.60);
	glVertex2i(930, 360);
	glVertex2i(960, 360);
	glVertex2i(960, 390);
	glVertex2i(930, 390);
	glEnd();



	//building2 windows 4
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.60, 0.60);
	glVertex2i(920, 360);
	glVertex2i(890, 360);
	glVertex2i(890, 390);
	glVertex2i(920, 390);
	glEnd();



	//building2 windows 5
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.60, 0.60);
	glVertex2i(920, 400);
	glVertex2i(890, 400);
	glVertex2i(890, 430);
	glVertex2i(920, 430);
	glEnd();


	//building2 windows 6
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.60, 0.60);
	glVertex2i(930, 400);
	glVertex2i(960, 400);
	glVertex2i(960, 430);
	glVertex2i(930, 430);
	glEnd();


	//vertical road
	glColor3f(0.2, 0.2, 0.2);
	glBegin(GL_POLYGON);
	glVertex2f(360, 550);
	glVertex2f(360, 150);
	glVertex2f(600, 150);
	glVertex2f(600, 550);
	glEnd();

	//divider
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(470, 460);
	glVertex2f(470, 400);
	glVertex2f(480, 400);
	glVertex2f(480, 460);
	glEnd();

	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(470, 380);
	glVertex2f(470, 320);
	glVertex2f(480, 320);
	glVertex2f(480, 380);
	glEnd();

	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(470, 300);
	glVertex2f(470, 240);
	glVertex2f(480, 240);
	glVertex2f(480, 300);
	glEnd();
	//horizontal road
	glColor3f(0.2, 0.2, 0.2);
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(0, 150);
	glVertex2f(1100, 150);
	glVertex2f(1100, 0);
	glEnd();
	//divider
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(75, 75);
	glVertex2f(195, 75);
	glVertex2f(195, 65);
	glVertex2f(75, 65);
	glEnd();

	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(255, 75);
	glVertex2f(375, 75);
	glVertex2f(375, 65);
	glVertex2f(255, 65);
	glEnd();

	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(615, 75);
	glVertex2f(735, 75);
	glVertex2f(735, 65);
	glVertex2f(615, 65);
	glEnd();

	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(855, 75);
	glVertex2f(975, 75);
	glVertex2f(975, 65);
	glVertex2f(855, 65);
	glEnd();
	//signal
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(330, 150);
	glVertex2f(330, 350);
	glVertex2f(340, 350);
	glVertex2f(340, 150);
	glEnd();

	glColor3f(0.7, 0.7, 0.7);
	glBegin(GL_POLYGON);
	glVertex2f(310, 350);
	glVertex2f(310, 500);
	glVertex2f(360, 500);
	glVertex2f(360, 350);
	glEnd();

	//signal partition
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(310, 415);
	glVertex2f(310, 435);
	glVertex2f(360, 435);
	glVertex2f(360, 415);
	glEnd();

	for (l = 0; l <= 20; l++)
	{
		glColor3f(0.0, 0.0, 0.0);
		draw_circle(335, 475, l);
		//glColor3f(1.0, 1.0, 0.0);
		//draw_circle(335, 425, l);
		glColor3f(0.0, 0.0, 0.0);
		draw_circle(335, 375, l);
	}
	//car 1
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(25 + i, 50);
	glVertex2f(25 + i, 125);
	glVertex2f(75 + i, 170);
	glVertex2f(175 + i, 170);
	glVertex2f(200 + i, 125);
	glVertex2f(250 + i, 100);
	glVertex2f(250 + i, 50);
	glEnd();

	// back window
	glColor3f(0.1, 0.1, 0.1);
	glBegin(GL_POLYGON);
	glVertex2f(35 + i, 125);
	glVertex2f(80 + i, 165);
	glVertex2f(115 + i, 165);
	glVertex2f(115 + i, 125);
	glEnd();

	//front window
	glColor3f(0.1, 0.1, 0.1);
	glBegin(GL_POLYGON);
	glVertex2f(125 + i, 125);
	glVertex2f(125 + i, 165);
	glVertex2f(170 + i, 165);
	glVertex2f(190 + i, 125);
	glEnd();

	for (l = 0; l<20; l++)
	{
		glColor3f(0.0, 0.0, 0.0);
		//front tyre
		draw_circle(190 + i, 50, l);
		//back tyre
		draw_circle(75 + i, 50, l);
	}
	//car2
	glColor3f(0.9, 0.2, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(-470 + i, 50);
	glVertex2f(-470 + i, 112);
	glVertex2f(-400 + i, 125);
	glVertex2f(-372 + i, 190);
	glVertex2f(-210 + i, 190);
	glVertex2f(-180 + i, 125);
	glVertex2f(-135 + i, 112);
	glVertex2f(-110 + i, 50);
	glEnd();

	//back window
	glColor3f(0.1, 0.1, 0.1);
	glBegin(GL_POLYGON);
	glVertex2f(-410 + i, 125);
	glVertex2f(-372 + i, 180);
	glVertex2f(-300 + i, 180);
	glVertex2f(-300 + i, 125);
	glEnd();
	//front window
	glColor3f(0.1, 0.1, 0.1);
	glBegin(GL_POLYGON);
	glVertex2f(-290 + i, 125);
	glVertex2f(-290 + i, 180);
	glVertex2f(-217 + i, 180);
	glVertex2f(-192 + i, 125);
	glEnd();

	for (l = 0; l<30; l++)
	{
		glColor3f(0.0, 0.0, 0.0);
		//front tyre
		draw_circle(-200 + i, 50, l);
		//back tyre
		draw_circle(-370 + i, 50, l);
	}
	//bus
	glColor3f(0.5, 0.9, 0.2);
	glBegin(GL_POLYGON);
	glVertex2f(350 + i, 50);
	glVertex2f(350 + i, 225);
	glVertex2f(722 + i, 225);
	glVertex2f(750 + i, 145);
	glVertex2f(750 + i, 50);
	glEnd();

	//front window
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(615 + i, 145);
	glVertex2f(615 + i, 220);
	glVertex2f(690 + i, 220);
	glVertex2f(715 + i, 145);
	glEnd();

	//middle window
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(500 + i, 145);
	glVertex2f(500 + i, 220);
	glVertex2f(575 + i, 220);
	glVertex2f(575 + i, 145);
	glEnd();

	//last window
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(380 + i, 145);
	glVertex2f(380 + i, 220);
	glVertex2f(455 + i, 220);
	glVertex2f(455 + i, 145);
	glEnd();

	for (l = 0; l<30; l++)
	{
		glColor3f(0.0, 0.0, 0.0);
		//back tyre
		draw_circle(450 + i, 60, l);
		//front tyre
		draw_circle(655 + i, 60, l);
	}
	//car 4
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(402, 508 + z);
	glVertex2f(402, 413 + z);
	glVertex2f(447, 413 + z);
	glVertex2f(447, 508 + z);
	glEnd();

	//car back mirror
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(410, 500 + z);
	glVertex2f(416, 488 + z);
	glVertex2f(433, 488 + z);
	glVertex2f(438, 500 + z);
	glEnd();

	//front mirror
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(414, 440 + z);
	glVertex2f(410, 428 + z);
	glVertex2f(438, 428 + z);
	glVertex2f(431, 440 + z);
	glEnd();

	//side mirror
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(408, 485 + z);
	glVertex2f(408, 438 + z);
	glVertex2f(414, 445 + z);
	glVertex2f(414, 480 + z);
	glEnd();

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(431, 445 + z);
	glVertex2f(437, 438 + z);
	glVertex2f(437, 485 + z);
	glVertex2f(431, 480 + z);
	glEnd();

	//looking glass right
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(455, 438 + z);
	glVertex2f(447, 438 + z);
	glVertex2f(447, 444 + z);
	glVertex2f(455, 444 + z);
	glEnd();

	//looking glass left
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(410, 438 + z);
	glVertex2f(395, 438 + z);
	glVertex2f(395, 444 + z);
	glVertex2f(410, 444 + z);
	glEnd();

	//car 5
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(508, 508 + r);
	glVertex2f(508, 413 + r);
	glVertex2f(553, 413 + r);
	glVertex2f(553, 508 + r);
	glEnd();

	//car back mirror
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(516, 500 + r);
	glVertex2f(522, 488 + r);
	glVertex2f(539, 488 + r);
	glVertex2f(544, 500 + r);
	glEnd();

	//front mirror
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(520, 440 + r);
	glVertex2f(516, 428 + r);
	glVertex2f(544, 428 + r);
	glVertex2f(537, 440 + r);
	glEnd();

	//side mirror
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(514, 485 + r);
	glVertex2f(514, 438 + r);
	glVertex2f(520, 445 + r);
	glVertex2f(520, 480 + r);
	glEnd();

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(537, 445 + r);
	glVertex2f(543, 438 + r);
	glVertex2f(543, 485 + r);
	glVertex2f(537, 480 + r);
	glEnd();

	//looking glass right
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(561, 438 + r);
	glVertex2f(553, 438 + r);
	glVertex2f(553, 444 + r);
	glVertex2f(561, 444 + r);
	glEnd();

	//looking glass left
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(516, 438 + r);
	glVertex2f(501, 438 + r);
	glVertex2f(501, 444 + r);
	glVertex2f(516, 444 + r);
	glEnd();
	glFlush();
}
void traffic_light()
{
	int l;
	if (light == 1)
	{
		for (l = 0; l <= 20; l++)
		{

			glColor3f(0.0, 0.0, 0.0);
			draw_circle(335, 475, l);

			glColor3f(0.0, 0.7, 0.0);
			draw_circle(335, 375, l);
		}
	}

	else
	{

		for (l = 0; l <= 20; l++)
		{
			glColor3f(1.0, 0.0, 0.0);
			draw_circle(335, 475, l);

			glColor3f(0.0, 0.0, 0.0);
			draw_circle(335, 375, l);
		}
	}
}


void idle()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	if (light == 0 && z > -466 && g == 1 && i > 750)
	{
		z--;
	}
	else
	{
		z = 0;
		z--;
	}
	if (light == 0 && r > -466 && g == 1 && i>1100)
	{
		r--;
	}

	else
	{
		r = 0;
		r--;
	}
	if (light == 0 && (i >= 330 && i <= 1400)) //value of i when first vehicle is near the traffic-signal
	{
		i += SPEED / 10;
		++m;

	}

	if (light == 0 && (i >= 830 && i <= 1100)) //value of i when second vehicle is near the traffic-signal
	{
		i += SPEED / 10;
		++m;

	}

	if (light == 0 && (i >= 1200 && i <= 1620))// value of i when third vehicle is near the traffic signal
	{
		i += SPEED / 10;
		++m;

	}

	if (light == 0)
	{
		i = i;
		++m;

	}

	else
	{
		i += SPEED / 10;
		++m;

	}
	if (i > 1630)
	{
		i = 0.0;
	}
	if (m > 1100)
	{
		m = 0.0;
	}

	glutPostRedisplay();

}
void mouse(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		day = 1;
	}
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_UP)
	{
		day = 0;
	}
}

void keyboardFunc(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'g':
	case 'G':
		light = 1;
		g = 0;
		break;

	case 'r':
	case 'R':
		light = 0;
		g = 1;
		break;
	};

}

void myinit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 1.0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1100.0, 0.0, 700.0);
}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	draw_object();
	traffic_light();
	glFlush();
}


int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1100.0, 768.0);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("Traffic Control");
	glEnable(GL_BLEND);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboardFunc);
	glutMouseFunc(mouse);
	myinit();
	glutMainLoop();
	return 0;
}
