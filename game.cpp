

#ifndef DODGE_CPP_
#define DODGE_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> //that is fine. for basic math functions such as cos, sin, sqrt
#include<time.h>
using namespace std;
void DrawopponentCar();
void DrawuserCar();
void menuList();
void menu();
void _Display();
void level();
void help();
bool moveCar(int, int);
int randomization();
void gameOver();
void lives();
// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */

void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

const int LEFT_LIMIT = 30;
const int RIGHT_LIMIT = 780;
const int BOTTOM_LIMIT = 40;
const int TOP_LIMIT = 780;
float *_colour=colors[GOLD];
int e;   //for randomization
int _i=3;
bool test=true;
int temp=0; //for fooding
int h=0;	//for help
int again=0;
int foodX=60,foodY=40,foodWidth=15,foodHeight=8,flag=0;
int carX = 340,
    carY = 40;
int carBX=450,
    carBY=40;
/*
 * Main Canvas drawing function.
 * */
//Board *b;

void opponentCar(int _a,int _b){
	
	if ((carBY==40)&&(carBX<770))
 	carBX+=10;    
	else  if((carBX==770)&&(carBY<770))
	carBY+=10;
 	else if((carBX>30)&&(carBY==770))
	carBX-=10;
	else if((carBX==30)&&(carBY>40))
        carBY-=10;

	else if((carBX==690) && (carBY<670))
	carBY+=10;
	else if(carBY==670&&carBX>110)
 	carBX-=10;
 	else if(carBX==110&&carBY>120)
	carBY-=10;
	else if(carBY==120&&carBX<690)
	carBX+=10;

	else if(carBX==620&&carBY<590)
	carBY+=10;
	else if(carBY==590&&carBX>180)
	carBX-=10;
	else if(carBX==180&&carBY>200)
	carBY-=10;
	else if(carBY==200&&carBX<620)
	carBX+=10;

	else if(carBX==540&&carBY<510)
	carBY+=10;
	else if(carBY==510&&carBX>260)
	carBX-=10;
	else if(carBX==260&&carBY>280)
	carBY-=10;
	else if(carBY==280&&carBX<590)
	carBX+=10;
//cout<<carBX<<"\t"<<carBY<<endl;
}
//user car
void userCar(int _c,int _d){

	if ((carY==40)&&(carX>30))
 	carX-=10;    
	else  if((carX==30)&&(carY<770))
	carY+=10;
	else if((carX<770)&&(carY==770))
	carX+=10; 
	else if((carX==770)&&(carY>40))
        carY-=10;

	else if(carY==120&&carX>110)
	carX-=10;
 	else if(carX==110&&carY<670)
	carY+=10;
	else if(carY==670&&carX<690)
	carX+=10;
	else if(carX==690&&carY>120)
	carY-=10;

	else if(carX==620&&carY>200)
	carY-=10;
	else if(carY==200&&carX>180)
	carX-=10;
	else if(carX==180&&carY<590)
	carY+=10; 
	else if(carY==590&&carX<620)
	carX+=10;
	
	else if(carX==540&&carY>280)
	carY-=10;
	else if(carY==280&&carX>260)
	carX-=10;
	else if(carX==260&&carY<510)
	carY+=10;
	else if(carY==510&&carX<540)
	carX+=10;
//cout<<carX<<"\t"<<carY<<endl;
}
// for rewards
void rewarding(){
//right
		if(carY>=foodY-20&&carX==foodX+710&&carX<foodX){
		DrawRectangle(foodX+710,foodY+10, foodWidth, foodHeight, colors[BLACK]);
		}
		else {
		DrawRectangle(foodX+710,foodY, foodWidth, foodHeight, colors[YELLOW]);
	        }
	cout<<foodX+720<<endl<<foodY+20<<endl;
	
	DrawRectangle(foodX+720,foodY+100, foodWidth, foodHeight, colors[YELLOW]);
        DrawRectangle(foodX+720,foodY+200, foodWidth, foodHeight, colors[YELLOW]);
        DrawRectangle(foodX+720,foodY+300, foodWidth, foodHeight, colors[YELLOW]);
        DrawRectangle(foodX+720,foodY+400, foodWidth, foodHeight, colors[YELLOW]);
        DrawRectangle(foodX+720,foodY+500, foodWidth, foodHeight, colors[YELLOW]);
        DrawRectangle(foodX+720,foodY+600, foodWidth, foodHeight, colors[YELLOW]);
        DrawRectangle(foodX+720,foodY+675, foodWidth, foodHeight, colors[YELLOW]);
        DrawRectangle(foodX+720,foodY+750, foodWidth, foodHeight, colors[YELLOW]);
	
//left
	DrawRectangle(foodX-15,foodY+20, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX-15,foodY+100, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX-15,foodY+200, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX-15,foodY+300, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX-15,foodY+400, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX-15,foodY+500, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX-15,foodY+600, foodWidth, foodHeight, colors[YELLOW]);
	DrawRectangle(foodX-15,foodY+675, foodWidth, foodHeight, colors[YELLOW]);  
	DrawRectangle(foodX-15,foodY+750, foodWidth, foodHeight, colors[YELLOW]); 
//left-2
	DrawRectangle(foodX+60,foodY+20, foodWidth, foodHeight, colors[YELLOW]);
	DrawRectangle(foodX+60,foodY+100, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX+60,foodY+200, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX+60,foodY+300, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX+60,foodY+400, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX+60,foodY+500, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX+60,foodY+575, foodWidth, foodHeight, colors[YELLOW]);
	DrawRectangle(foodX+60,foodY+650, foodWidth, foodHeight, colors[YELLOW]);
	DrawRectangle(foodX+60,foodY+750, foodWidth, foodHeight, colors[YELLOW]);  
//left-3
	DrawRectangle(foodX+130,foodY+20, foodWidth, foodHeight, colors[YELLOW]);
	DrawRectangle(foodX+130,foodY+100, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX+130,foodY+175, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX+130,foodY+300, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX+130,foodY+400, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX+130,foodY+500, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX+130,foodY+565, foodWidth, foodHeight, colors[YELLOW]);
	DrawRectangle(foodX+130,foodY+650, foodWidth, foodHeight, colors[YELLOW]);  
	DrawRectangle(foodX+130,foodY+750, foodWidth, foodHeight, colors[YELLOW]); 
//left-4
	DrawRectangle(foodX+220,foodY+20, foodWidth, foodHeight, colors[YELLOW]);
	DrawRectangle(foodX+220,foodY+100, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX+220,foodY+175, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX+220,foodY+300, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX+220,foodY+400, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX+220,foodY+490, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX+220,foodY+565, foodWidth, foodHeight, colors[YELLOW]);
	DrawRectangle(foodX+220,foodY+650, foodWidth, foodHeight, colors[YELLOW]);  
	DrawRectangle(foodX+220,foodY+750, foodWidth, foodHeight, colors[YELLOW]); 
//left-5
	DrawRectangle(foodX+300,foodY+20, foodWidth, foodHeight, colors[YELLOW]);
	DrawRectangle(foodX+300,foodY+100, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX+300,foodY+175, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX+300,foodY+260, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX+300,foodY+490, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX+300,foodY+565, foodWidth, foodHeight, colors[YELLOW]);
	DrawRectangle(foodX+300,foodY+650, foodWidth, foodHeight,colors[YELLOW]);  
	DrawRectangle(foodX+300,foodY+750, foodWidth, foodHeight, colors[YELLOW]); 
//left-6
	DrawRectangle(foodX+380,foodY+20, foodWidth, foodHeight, colors[YELLOW]);
	DrawRectangle(foodX+380,foodY+100, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX+380,foodY+175, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX+380,foodY+260, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX+380,foodY+490, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX+380,foodY+565, foodWidth, foodHeight, colors[YELLOW]);
	DrawRectangle(foodX+380,foodY+650, foodWidth, foodHeight, colors[YELLOW]);  
	DrawRectangle(foodX+380,foodY+750, foodWidth, foodHeight, colors[YELLOW]); 
//left-7
	DrawRectangle(foodX+460,foodY+20, foodWidth, foodHeight, colors[YELLOW]);
	DrawRectangle(foodX+460,foodY+100, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX+460,foodY+175, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX+460,foodY+260, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX+460,foodY+400, foodWidth, foodHeight, colors[YELLOW]);	
	DrawRectangle(foodX+460,foodY+490, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX+460,foodY+565, foodWidth, foodHeight, colors[YELLOW]);
	DrawRectangle(foodX+460,foodY+650, foodWidth, foodHeight, colors[YELLOW]);  
	DrawRectangle(foodX+460,foodY+750, foodWidth, foodHeight, colors[YELLOW]); 
//left-8
	DrawRectangle(foodX+560,foodY+20, foodWidth, foodHeight, colors[YELLOW]);
	DrawRectangle(foodX+560,foodY+100, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX+560,foodY+175, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX+560,foodY+260, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX+560,foodY+400, foodWidth, foodHeight, colors[YELLOW]);	
	DrawRectangle(foodX+560,foodY+490, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX+560,foodY+565, foodWidth, foodHeight, colors[YELLOW]);
	DrawRectangle(foodX+560,foodY+650, foodWidth, foodHeight, colors[YELLOW]);  
	DrawRectangle(foodX+560,foodY+750, foodWidth, foodHeight, colors[YELLOW]); 
//left-9
	DrawRectangle(foodX+640,foodY+20, foodWidth, foodHeight, colors[YELLOW]);
	DrawRectangle(foodX+640,foodY+100, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX+640,foodY+175, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX+640,foodY+260, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX+640,foodY+400, foodWidth, foodHeight, colors[YELLOW]);	
	DrawRectangle(foodX+640,foodY+490, foodWidth, foodHeight, colors[YELLOW]); 
	DrawRectangle(foodX+640,foodY+565, foodWidth, foodHeight, colors[YELLOW]);
	DrawRectangle(foodX+640,foodY+650, foodWidth, foodHeight, colors[YELLOW]);  
	DrawRectangle(foodX+640,foodY+750, foodWidth, foodHeight, colors[YELLOW]); 

}
void crashing(int _q,int _w,int _e,int _r){
	if((carX>=(carBX-20)&&carX<=(carBX+20))&&((carY>=carBY-20)&&carY<=carBY+20)){
	carX = 340,carY = 40;
	carBX=450,carBY=40;
	_i--;
	
}
}

//randomization
int randomization(){
	srand(time(NULL));
	e=rand()%4+1;
	return e;
}
void changingRoads(){
//left gap	
	int z=randomization();
	if((carBX==770)&&(carBY==400)&&z==4){
 	  carBX=690;
	  carBY=400;
          }
	 if(carBX==690&&carBY==400&&z==3){
	carBX=620;
	carBY=400;	
	}
	if(carBX==620&&carBY==400&&z==1){
	carBX=540;
	carBY=400;	
	}
//upper gap
	if((carBX==400)&&(carBY==770)&&z==2){
 	  carBX=400;
	  carBY=670;
          }
	 if(carBX==400&&carBY==670&&z==3){
	carBX=400;
	carBY=590;	
	}
	if(carBX==400&&carBY==590&&z==1){
	carBX=400;
	carBY=510;	
	}
//right gap
	if(carBX==30&&carBY==410&&z==4){
	carBX=110;
	carBY=410;
	}
	if(carBX==110&&carBY==410&&z==2){
	carBX=180;
	carBY=410;
	}
	if(carBX==180&&carBY==410&&z==1){
	carBX=260;
	carBY=410;
	}
//lower gap
	if(carBX==400&&carBY==40&&z==3){
	carBX=400;
	carBY=120;
	}
	if(carBX==400&&carBY==120&&z==1){
	carBX=400;
	carBY=200;
	}
	if(carBX==400&&carBY==200&&z==4){
	carBX=400;
	carBY=280;
	}
}
//for help and instruction
void help(){
	glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1.0/*Blue Component*/, 1 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors	
	DrawString( 50, 600, "The game is played in a racing arena where the player drives his car to pick ", colors[RED]);
	DrawString(50,550,"the maximum rewards,avoiding a head-on collision with the opponent car(s)",colors[RED]);
	DrawString(50,500,"run by the computer.\n The player car moves clockwise while the opponent car(s) move counter-clockwise only.",colors[RED]);
	DrawString(50,450,"When the game starts, the player is awarded three lives to collect the rewards from the arena.",colors[RED]);
	DrawString(50,400," The player gets one reward point when his/her car picks up any rectangular-shaped gift-boxes placed at equal distances ",colors[RED]);
	DrawString(50,350,"in the arena. When the player car hits the opponent car, one life is lost and the game arena is refilled with the reward gift-",colors[RED]);
	DrawString(50,300,"boxes. The score and the number of lives left are visible on the top of the screen.",colors[RED]);

 	glutPostRedisplay();
}
void lives(){
               
	if (_i==3){
	DrawString( 700, 850, "Lives=3", colors[RED]);
	}	
	if(_i==2){
	DrawString( 700, 850, "Lives=2", colors[RED]);
	}	
	if(_i==1){
	DrawString( 700, 850, "Lives=1", colors[RED]);
	}
	if(_i<=0){
	gameOver();
	//menu();
	
		}
glutPostRedisplay();
	}
void gameOver(){

glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1.0/*Blue Component*/, 1 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	DrawString( 300, 700, "GAME OVER", colors[RED]);
	
}
void menuList(){
	DrawString( 50, 650, "1.press s to start new game", colors[RED]);
	DrawString( 50, 500, "2.press a for high score", colors[RED]);
	DrawString( 50, 350, "3.press h for help", colors[RED]);
	DrawString( 50, 200, "4.press e to exit", colors[RED]);
glutPostRedisplay();
}
void DrawopponentCar(){
	float x = carBX; 
	float y = carBY; 
	float width = 10; 
	float height = 8;
	float* color = colors[BLUE_VIOLET]; 
	float radius = 3.0;
	DrawRoundRect(x,y,width,height,color,radius); // bottom left tyre
	DrawRoundRect(x+width*3,y,width,height,color,radius); // bottom right tyre
	DrawRoundRect(x+width*3,y+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(x,y+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(x, y+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(x+width, y+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(x+width*3, y+height*2, width, height, color, radius/2); // body right rect		
	}
void DrawuserCar(){
	float i = carX; 
	float j = carY; 
	float wdth = 10; 
	float hight = 8;
	float* colour = colors[BROWN]; 
	float radi = 3.0;
	DrawRoundRect(i,j,wdth,hight,colour,radi); // bottom left tyre
	DrawRoundRect(i+wdth*3,j,wdth,hight,colour,radi); // bottom right tyre
	DrawRoundRect(i+wdth*3,j+hight*4,wdth,hight,colour,radi); // top right tyre
	DrawRoundRect(i,j+hight*4,wdth,hight,colour,radi); // top left tyre
	DrawRoundRect(i, j+hight*2, wdth, hight, colour, radi/2); // body left rect
	DrawRoundRect(i+wdth, j+hight, wdth*2, hight*3, colour, radi/2); // body center rect
	DrawRoundRect(i+wdth*3, j+hight*2, wdth, hight, colour, radi/2); // body right rect

	}
void level(){
// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	// calling some functions from util.cpp file to help students
	 DrawString( 50, 850, "Score=0", colors[RED]);	//for displaying score
       	
	//Square at 400,20 position
	//DrawSquare( 400 , 20 ,40,colors[RED]); 
	//Square at 250,250 position
	//DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	//Display Score
	
	//Triangle at 300, 450 position
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//Circle at 50, 670 position
	
	//Line from 550,50 to 550,480 with width 10
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	
	
	// Drawing opponent car
	DrawopponentCar();
	DrawuserCar();
	// Drawing Arena
	int gap_turn = 60;
	int sx = 20;
	int sy = 10;
	int swidth = 800/2 - gap_turn/2; // half width
	int sheight = 10;

	float *scolor = colors[MAROON];
	
	
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+swidth+gap_turn+sheight, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+810, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+810, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+swidth+gap_turn+sheight*2, sheight*2, swidth, scolor); //left up
	DrawRectangle(sx-sheight*2, sy+sheight*2,sheight*2, swidth, scolor); // left down

        //inner 
	DrawRectangle(sx+80, sy+80, swidth-80, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy+80, swidth-80, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn-80, sy+sheight+80, sheight*2, swidth-80, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn-80, sy+swidth+gap_turn+sheight, sheight*2, swidth-80, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+810-80, swidth-80, sheight, scolor); // top left
	DrawRectangle(sx+80, sy+810-80, swidth-80, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2+80, sy+swidth+gap_turn+sheight*2, sheight*2, swidth-80, scolor); //left up
	DrawRectangle(sx-sheight*2+80, sy+sheight*2+80,sheight*2, swidth-80, scolor); // left down
	//inner 2
	DrawRectangle(sx+160, sy+160, swidth-160, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy+160, swidth-160, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn-160, sy+sheight+160, sheight*2, swidth-160, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn-160, sy+swidth+gap_turn+sheight, sheight*2, swidth-160, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+810-160, swidth-160, sheight, scolor); // top left
	DrawRectangle(sx+160, sy+810-160, swidth-160, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2+160, sy+swidth+gap_turn+sheight*2, sheight*2, swidth-160, scolor); //left up
	DrawRectangle(sx-sheight*2+160, sy+sheight*2+160,sheight*2, swidth-160, scolor); // left down
	//inner 3
	DrawRectangle(sx+240, sy+240, swidth-240, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy+240, swidth-240, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn-240, sy+sheight+240, sheight*2, swidth-240, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn-240, sy+swidth+gap_turn+sheight, sheight*2, swidth-240, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+810-240, swidth-240, sheight, scolor); // top left
	DrawRectangle(sx+240, sy+810-240, swidth-240, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2+240, sy+swidth+gap_turn+sheight*2, sheight*2, swidth-240, scolor); //left up
	DrawRectangle(sx-sheight*2+240, sy+sheight*2+240,sheight*2, swidth-240, scolor); // left down      
	//inner4
	DrawRectangle(sx+320, sy+320, swidth-320+100, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy+320, swidth-320, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn-320, sy+sheight+320, sheight*2, swidth-320+100, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn-320, sy+swidth+gap_turn+sheight, sheight*2, swidth-320, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+810-320, swidth-320, sheight, scolor); // top left
	DrawRectangle(sx+320, sy+810-320, swidth-320+100, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2+320, sy+swidth+gap_turn+sheight*2-10, sheight*2, swidth-320, scolor); //left up
	DrawRectangle(sx-sheight*2+320, sy+sheight*2+320-10,sheight*2, swidth-320+100, scolor); // left down    
	
	 	opponentCar(carBX,carBY);	//calling function for random movement of opponent car
	 	userCar(carX,carY);		//calling function for movement of user car
		crashing(carX,carBX,carY,carBY);//calling function for crashing of car
	
				changingRoads(); 		//calling function for changing of path
				rewarding();	//for fooding

}
void menu(){
	//glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,		
	//		0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	//glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	if(h==0){

	menuList();
}   
// glutPostRedisplay();

}
void _Display(){
	if(test==false&&temp==0&&h==0){
		menu();
		}
		else if(test==true&&temp==1&&h==0){
		level();
}
	else if(h==1){
	help();	
	}		
			
	glutPostRedisplay();
}
void GameDisplay()/**/{
	 _Display();
 	glutPostRedisplay();
 	glutSwapBuffers(); // do not modify this line.. or draw anything below this line
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */
 /*int validPositions[4][4] = {
	{ 0,  100, 110, 180 },
	{ 0, -100, -200, -300 },
	{ 0, -640, -560, -480 },
	{ 0,  640, 540, 440 }
 };
int level = 0;

int*	BL = &validPositions[0][level],
   *	BR = &validPositions[1][level],
   *	TL = &validPositions[2][level],
   *	TR = &validPositions[3][level];

void incrlevel() {
	if (level < 4) {
		::level++;
		BL = &validPositions[0][level],
   		BR = &validPositions[1][level],
   		TL = &validPositions[2][level],
   		TR = &validPositions[3][level];
	}
}

void decrlevel() {
	if (level >= 0) {
		::level--;
		BL = &validPositions[0][level],
   		BR = &validPositions[1][level],
   		TL = &validPositions[2][level],
   		TR = &validPositions[3][level];
	}
}
*///opponent car
  
void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		if(carX==770&&carY>=370&&carY<=430){
		carX=690;
		carY=400;			
		}
		else if(carX==690&&carY>=360&&carY<=450){
		carX=620;
		carY=400;			
		}
		else if(carX==620&&carY>=360&&carY<=440){
		carX=540;
		carY=400;			
		}
		else if(carX==260&&carY>=380&&carY<=440){
		carX=180;
		carY=410;			
		}
		else if(carX==180&&carY>=370&&carY<=440){
		carX=110;
		carY=410;			
		}
		else if(carX==110&&carY>=380&&carY<=450){
		carX=30;
		carY=410;			
		}
	//moveCar(-10,0);
	} else if (key
			== GLUT_KEY_DOWN /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		if(carY==770&&carX>=360&&carX<=440){
		carX=400;
		carY=670;
		}
		else if(carY==670&&carX>=360&&carX<=440){
		carX=400;
		carY=590;
		}
		else if(carY==590&&carX>=360&&carX<=440){
		carX=400;
		carY=510;
		}
		else if(carY==280&&carX>=350&&carX<=440){
		carX=400;
		carY=200;
		}
		else if(carY==200&&carX>=350&&carX<=440){
		carX=400;
		carY=120;
		}
		else if(carY==120&&carX>=350&&carX<=440){
		carX=400;
		carY=40;
		}
	//moveCar(0,-10);
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		if(carY==40&&carX<=430&&carX>=330){
		carX=400;
		carY=120;
		}
		else if(carY==120&&carX<=440&&carX>=350){
		carX=400;
		carY=200;
		}
		else if(carY==200&&carX<=440&&carX>=350){
		carX=400;
		carY=280;
		}
		else if(carY==510&&carX<=440&&carX>=360){
		carX=400;
		carY=590;
		}
		else if(carY==590&&carX<=440&&carX>=360){
		carX=400;
		carY=670;
		}
		else if(carY==670&&carX<=440&&carX>=360){
		carX=400;
		carY=770;
		}



	//moveCar(0,10);
	}
	else if (key
			== GLUT_KEY_RIGHT/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		//incrlevel();
		if(carX==30&&carY>=380&&carY<=440){
		carX=110;
		carY=410;
		}
		else if(carX==110&&carY>=380&&carY<=440){
		carX=180;
		carY=410;
		}
		else if(carX==180&&carY>=380&&carY<=440){
		carX=260;
		carY=400;
		}
		else if(carX==540&&carY>=380&&carY<=450){
		carX=620;
		carY=400;
		}
		else if(carX==620&&carY>=360&&carY<=440){
		carX=690;
		carY=400;
		}
		else if(carX==690&&carY>=360&&carY<=450){
		carX=770;
		carY=400;
		}


	//moveCar(10,0);
	}
	/*else if (key == 'a' || key == 'A') {
		incrlevel();
		moveCar(0, 0);
	}
	else if (key == 'z' || key == 'Z') {
		decrlevel();
		moveCar(0, 0);
	}
	*/	

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') {
		//do something if b is pressed
		cout << "b pressed" << endl;

	}
	if(key==' '){
	if ((carY==40)&&(carX>30))
 	carX-=10;    
	else  if((carX==30)&&(carY<770))
	carY+=10;
	else if((carX<770)&&(carY==770))
	carX+=10; 
	else if((carX==770)&&(carY>40))
        carY-=10;

	else if(carY==120&&carX>110)
	carX-=10;
 	else if(carX==110&&carY<670)
	carY+=10;
	else if(carY==670&&carX<690)
	carX+=10;
	else if(carX==690&&carY>120)
	carY-=10;

	else if(carX==620&&carY>200)
	carY-=10;
	else if(carY==200&&carX>180)
	carX-=10;
	else if(carX==180&&carY<590)
	carY+=10;
	else if(carY==590&&carX<620)
	carX+=10;
	
	else if(carX==540&&carY>280)
	carY-=10;
	else if(carY==280&&carX>260)
	carX-=10;
	else if(carX==260&&carY<510)
	carY+=10;
	else if(carY==510&&carX<540)
	carX+=10;
//
	if ((carY==40)&&(carX>30))
 	carX-=10;    
	else  if((carX==30)&&(carY<770))
	carY+=10;
	else if((carX<770)&&(carY==770))
	carX+=10; 
	else if((carX==770)&&(carY>40))
        carY-=10;

	else if(carY==120&&carX>110)
	carX-=10;
 	else if(carX==110&&carY<670)
	carY+=10;
	else if(carY==670&&carX<690)
	carX+=10;
	else if(carX==690&&carY>120)
	carY-=10;

	else if(carX==620&&carY>200)
	carY-=10;
	else if(carY==200&&carX>180)
	carX-=10;
	else if(carX==180&&carY<590)
	carY+=10;
	else if(carY==590&&carX<620)
	carX+=10;
	
	else if(carX==540&&carY>280)
	carY-=10;
	else if(carY==280&&carX>260)
	carX-=10;
	else if(carX==260&&carY<510)
	carY+=10;
	else if(carY==510&&carX<540)
	carX+=10;

	}
	if(key=='s'||key=='S'){
	test=true;
	temp=1;
	}
	if(key=='e'||key=='E'){
	exit(1);
	}
	if(key=='h'||key=='H'){
	h=1;
	}
	glutPostRedisplay();
}

bool moveCar(int _x, int _y) {
	
	bool valueChanged = false;
	if ((carX + _x) >=LEFT_LIMIT && (carX + _x <= RIGHT_LIMIT)) {
		carX = carX  + _x;
		valueChanged = true;
	}

	if ((carY + _y) >= BOTTOM_LIMIT && (carY + _y <= TOP_LIMIT)) {
		carY = carY + _y;
		valueChanged = true;
	}
	cout << carX << "\t" << carY << endl;
	
		
//cout << carX << "\t" << carY << endl;
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {
	 menu();
	_Display();
	 lives();	//for displaying lives
	
	// implement your functionality here
	
	// once again we tell the library to call our Timer function after next 1000/FPS
//GameDisplay();
glutSwapBuffers();
glutPostRedisplay();
glutTimerFunc(100.0, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << "\n" << y << "\n";
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	//b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 840, height = 900; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	//fooding();
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Centipede"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	//glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
