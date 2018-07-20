/*
Author:Minhaz Uddin
ID:15101056
University Of AsiaPacific
*/
#define _CRT_SECURE_NO_WARNINGS

#include "iGraphics.h"
#include<stdlib.h>
#include<string.h>
#include<conio.h>
	int flag;
	char *n;//=(char*)malloc(50);Author:Minhaz Uddin
	static int number_of_car;
	static int max_number_of_car=4;
	static int speed=3;
	int resume;
	int enter;
	int exitNotification;
	static int sbox1x=0,sbox2x=900,sbox3x=0,sbox4x=900,sbox5x,sbox6x;
	static int sbox1y=600,sbox2y=500,sbox3y=400,sbox4y=300,sbox5y,sbox6y;
	int i,j,k,l;
	int mod[4];
	int mod_car1_x[4], mod_car1_y[4];
	int collide_tag[4];
	int score_tag[4];
	 int score;
	double life;
	char buffer[30];
	static int choice=0;
	int highscore;
	int highscoremain;
	FILE *save,*savep;
	static int ground;
	static int position_car1_x[4];
	static int position_car1_y[4];

	int position_mycar_x;
	int position_mycar_y;
	static long int mxo;
	static long int myo;

	int a;
    int state_of_text = 0,color_state=0;
	static int  scoretag[4];
	static int  collidetag[4];
	int highscoretag=1;
	static int cp;
	int xlength=300;
	int ywidth=50;
	int diffa =30;
	static int anim;




struct component_discription
{
	int x;
	int y;
	int length;
	int width;
	int number_of_component;
	int radious;
	int distance;
	int distance_x;
	int distance_y;
	char name[100];
	int score;

};



void restart()
{






}
struct component{

	struct component_discription main_structure;
	struct component_discription engine;
	struct component_discription wheel;
	struct component_discription main_glass;
	struct component_discription head_light_1;
	struct component_discription head_light_2;
	struct component_discription race_track;
	struct component_discription left_side_of_race_track;
	struct component_discription right_side_of_race_track;
	struct component_discription lane;//Author:Minhaz Uddin
	struct component_discription divider;
	struct component_discription side;
	struct component_discription scoreboard;
	struct component_discription scorebox;
	struct component_discription highscore;
	struct component_discription highscore_box;
	struct component_discription lifebox;
	struct component_discription Scorer;
};

struct component car1[4],mycar,track;
int highscore__checker()
{

	save =fopen("save.txt","r");
	fscanf(save,"%d %[^\n]s",&highscoremain,&track.highscore.name);
	fclose(save);

printf("%d",highscoremain);
	return highscoremain;




}
void show_highscore()
{
	iClear();
	iSetColor(250,250,250);
	iText(200,260,"Click(Mouse) Anywhere To Go Main Menu",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(300,420,"High Score",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(200,360,"Name",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(400,360,"Score",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(200,320,track.highscore.name,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(400,320,itoa(highscore,buffer,10),GLUT_BITMAP_TIMES_ROMAN_24);
}


void racetrack( struct component track )
{
    iSetColor(205,133,63);

	iFilledRectangle(track.left_side_of_race_track.width,track.left_side_of_race_track.y,track.divider.width,track.left_side_of_race_track.length);
    iFilledRectangle(track.divider.x,track.left_side_of_race_track.y,track.divider.width,track.left_side_of_race_track.length);
    iSetColor(20,20,20);
    iFilledRectangle(track.race_track.x,track.left_side_of_race_track.y,track.race_track.width,track.left_side_of_race_track.length);

    iSetColor(0,128,0);
	iFilledRectangle(track.left_side_of_race_track.x,track.left_side_of_race_track.y,track.left_side_of_race_track.width,track.left_side_of_race_track.length);
    iFilledRectangle(track.right_side_of_race_track.x,track.left_side_of_race_track.y,track.left_side_of_race_track.width,track.left_side_of_race_track.length);
	iSetColor(255,255,255);
	for(i=0;i<=track.left_side_of_race_track.length;i=i+50)
		{

			iFilledRectangle(track.lane.x,track.left_side_of_race_track.y+i,track.lane.width,track.lane.length);
			iFilledRectangle(track.lane.x +track.lane.distance,track.left_side_of_race_track.y+i,track.lane.width,track.lane.length);

		}
	iSetColor(117,139,0);
	iFilledRectangle(track.scoreboard.x,track.left_side_of_race_track.y,track.scoreboard.width,track.left_side_of_race_track.length);
    iSetColor(0,0,0);
	iFilledRectangle(track.scorebox.x,track.scorebox.y,track.scorebox.width,track.scorebox.length);
	iFilledRectangle(track.lifebox.x,track.lifebox.y,track.lifebox.width,track.lifebox.length);
	iFilledRectangle(track.scorebox.x,track.highscore_box.y,track.scorebox.width,track.scorebox.length);
	iSetColor(255,255,255);
	iFilledRectangle(track.scorebox.x+20,track.highscore_box.y +40,track.scorebox.width-40,3);
	iFilledRectangle(track.scorebox.x+20,/*Author:Minhaz Uddin*/track.scorebox.y +40,track.scorebox.width-40,3);
	iText(830, 750,"High Score",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(5,720,"Press ""HOME"" Button to pause",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(5,680,"Press ""END"" Button to Exit",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(850, 650,"Score",GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(250 ,250 ,250);
	iText(800, 100,"FUEL",GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(0, 0,0);

}



void aexit(){

	savep =fopen("savep.txt","r");
	fprintf(savep,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",number_of_car,choice,mycar.main_structure.x,
	mycar.main_structure.y,life ,track.left_side_of_race_track.y,score,position_car1_x[0],position_car1_x[1],position_car1_x[2],position_car1_x[3],mod_car1_y[0],mod_car1_y[1],mod_car1_y[2],mod_car1_y[3],speed);
	fclose(savep);

}

void bexit(){



	track.highscore.score=score;
	savep =fopen("textp.txt","w");
	fprintf(savep,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",number_of_car,choice,mycar.main_structure.x,
	mycar.main_structure.y,life ,track.left_side_of_race_track.y,score,position_car1_x[0],position_car1_x[1],position_car1_x[2],position_car1_x[3],mod_car1_y[0],mod_car1_y[1],mod_car1_y[2],mod_car1_y[3],speed);
	fclose(savep);
	remove("savep.txt");
	rename("textp.txt","savep.txt");
	enter=1;

}




void all_declaration()
{

	flag;
	number_of_car=0;
	mod[4];
	score=0;
	life=5;
	choice=0;
    highscore = highscore__checker();
	ground=-0;
	//position_car1_x[0]= 280;
	//position_car1_x[1]=  300;Author:Minhaz Uddin
	///position_car1_x[2]=  330;
	//position_car1_x[3]=  360;
	collide_tag[0]=1;
	collide_tag[1]=1;
	collide_tag[2]=1;
	collide_tag[3]=1;
	position_mycar_x=400;
	position_mycar_y=400;
	track.left_side_of_race_track.x =0;
	track.left_side_of_race_track.y=0;
	track.left_side_of_race_track.width =290;
	track.left_side_of_race_track.length=2800;
	track.divider.width=10;
	track.race_track.x=track.left_side_of_race_track.width +track.divider.width;
	track.race_track.width=400;
	track.divider.x=track.left_side_of_race_track.width+track.divider.width+track.race_track.width;
	track.right_side_of_race_track.x=(track.divider.x+track.divider.width);
	track.lane.distance=130;
	track.lane.y=5;
	track.lane.width=8;
	track.lane.x= track.race_track.x + track.lane.distance;
	track.lane.length=30;
	track.scoreboard.x=track.right_side_of_race_track.x +50;
	track.scoreboard.width=300;
	track.scorebox.width=210;
	track.scorebox.length=80;
	track.scorebox.x= track.scoreboard.x +20;
	track.scorebox.y=600;
	track.highscore_box.y=700;
	track.lifebox.x= track.right_side_of_race_track.x +80;
	track.lifebox.length= 250;
	track.lifebox.width = 80;
	track.lifebox.y=100;
	track.lifebox.distance=0;
	mycar.main_structure.x =450;
	mycar.main_structure.y=50;
	mycar.main_structure.width=80;
	mycar.main_structure.length=150;
	scoretag[0]=1;
	scoretag[1]=1;
	scoretag[2]=1;
	scoretag[3]=1;
	collidetag[0]=1;
	collidetag[1]=1;
	collidetag[2]=1;
	collidetag[3]=1;
	resume=0;
	exitNotification=0;
	cp=0;
	enter =1;
	if(n){free(n);}
	n=(char*)malloc(100);
	sbox1x=0;sbox2x=900;sbox3x=0;sbox4x=900;
	sbox1y=600;sbox2y=500;sbox3y=400;sbox4y=300;
	anim=1;
}
void mainMenu()
{
	iClear();
	enter=1;
	choice=0;
	iSetColor(250, 250, 250);

	if(sbox1x<=300 && sbox3x<=300)
	{
		sbox1x++;
		sbox3x++;
	}
		if( sbox2x>=300 && sbox4x>=300)
	{
		sbox2x=sbox2x-2;
		sbox4x=sbox4x-2;

	}
	iLine(sbox1x,sbox1y,sbox1x+xlength, sbox1y);
	iLine(sbox1x-10,sbox1y+5,sbox1x+xlength+10, sbox1y+5);
	iLine(sbox1x-diffa,sbox1y-ywidth+5,sbox1x+xlength-diffa,sbox1y-ywidth+5);
	iLine(sbox1x-diffa-10,sbox1y-50,sbox1x-diffa+xlength+10, sbox1y-50);

	iLine(sbox1x,sbox1y,sbox1x-diffa,sbox1y-ywidth+5);
	iLine(sbox1x-10,sbox1y+5,sbox1x-diffa-10,sbox1y-50);
	iLine(sbox1x+xlength, sbox1y,sbox1x+xlength-diffa,sbox1y-ywidth+5);
	iLine(sbox1x+xlength+10, sbox1y+5,sbox1x-diffa+xlength+10, sbox1y-50);




	iLine(sbox2x,sbox2y,sbox2x+xlength, sbox2y);
	iLine(sbox2x-10,sbox2y+5,sbox2x+xlength+10, sbox2y+5);
	iLine(sbox2x-diffa,sbox2y-ywidth+5,sbox2x+xlength-diffa,sbox2y-ywidth+5);
	iLine(sbox2x-diffa-10,sbox2y-50,sbox2x-diffa+xlength+10, sbox2y-50);
	iLine(sbox2x,sbox2y,sbox2x-diffa,sbox2y-ywidth+5);
	iLine(sbox2x-10,sbox2y+5,sbox2x-diffa-10,sbox2y-50);
	iLine(sbox2x+xlength, sbox2y,sbox2x+xlength-diffa,sbox2y-ywidth+5);
	iLine(sbox2x+xlength+10, sbox2y+5,sbox2x-diffa+xlength+10, sbox2y-50);





	iLine(sbox3x,sbox3y,sbox3x+xlength, sbox3y);
	iLine(sbox3x-10,sbox3y+5,sbox3x+xlength+10, sbox3y+5);
	iLine(sbox3x-diffa,sbox3y-ywidth+5,sbox3x+xlength-diffa,sbox3y-ywidth+5);
	iLine(sbox3x-diffa-10,sbox3y-50,sbox3x-diffa+xlength+10,sbox3y-50);

	iLine(sbox3x,sbox3y,sbox3x-diffa,sbox3y-ywidth+5);
	iLine(sbox3x-10,sbox3y+5,sbox3x-diffa-10,sbox3y-50);
	iLine(sbox3x+xlength, sbox3y,sbox3x+xlength-diffa,sbox3y-ywidth+5);
	iLine(sbox3x+xlength+10, sbox3y+5,sbox3x-diffa+xlength+10, sbox3y-50);




	iLine(sbox4x,sbox4y,sbox4x+xlength, sbox4y);
	iLine(sbox4x-10,sbox4y+5,sbox4x+xlength+10, sbox4y+5);
	iLine(sbox4x-diffa,sbox4y-ywidth+5,sbox4x+xlength-diffa,sbox4y-ywidth+5);
	iLine(sbox4x-diffa-10,sbox4y-50,sbox4x-diffa+xlength+10, sbox4y-50);
	iLine(sbox4x,sbox4y,sbox4x-diffa,sbox4y-ywidth+5);
	iLine(sbox4x-10,sbox4y+5,sbox4x-diffa-10,sbox4y-50);
	iLine(sbox4x+xlength,sbox4y,sbox4x+xlength-diffa,sbox4y-ywidth+5);
	iLine(sbox4x+xlength+10,sbox4y+5,sbox4x-diffa+xlength+10, sbox4y-50);









	if(choice==0 && myo <= 620 && myo >= 570 && mxo >=270 && mxo<=590)
	{
		iSetColor(250, 0, 0);
	}
	else
	{iSetColor(20, 200, 0);}

	iText(sbox1x+80,sbox1y-30,"Play",GLUT_BITMAP_TIMES_ROMAN_24);
	if(choice==0 && myo <= 520 && myo >= 470 && mxo >=270 && mxo<=590)
	{
		iSetColor(250, 0, 0);
	}
	else
	{iSetColor(20, 200, 0);}
	iText(sbox2x+80,sbox2y-30,"Difficulty",GLUT_BITMAP_TIMES_ROMAN_24);
	if(choice==0 && myo <= 420 && myo >= 370 && mxo >=270 && mxo<=590)
	{
		iSetColor(250, 0, 0);
	}
	else
	{iSetColor(20, 200, 0);}
	iText(sbox3x+80,sbox3y-30,"High Score!!!",GLUT_BITMAP_TIMES_ROMAN_24);
		if(choice==0 && myo <= 320 && myo >= 270 && mxo >=270 && mxo<=590)
	{
		iSetColor(250, 0, 0);
	}
	else
	{iSetColor(20, 200, 0);}
	iText(sbox4x+80,sbox4y-30,"Exit",GLUT_BITMAP_TIMES_ROMAN_24);

}

void frame(){

	sbox1x=0;sbox2x=900;sbox3x=0;sbox4x=900;
	sbox1y=600;sbox2y=500;sbox3y=400;sbox4y=300;
	anim=1;


}

void Dynamic_car(struct component mycar)
{

    iSetColor(200, 0, 0);
	iFilledRectangle(mycar.main_structure.x  ,mycar.main_structure.y,mycar.main_structure.width,mycar.main_structure.length);//Engine.
    iSetColor(0, 120, 255);
    iFilledRectangle(mycar.main_structure.x+15,mycar.main_structure.y+20,50,25);//RoofTop.
    iFilledRectangle(mycar.main_structure.x+10,mycar.main_structure.y+90,60,20);
    iFilledEllipse(mycar.main_structure.x+40, mycar.main_structure.y+113,30,12,50);//Main Glass.
    iSetColor(107, 107, 107);
    iFilledEllipse(mycar.main_structure.x+40,mycar.main_structure.y+150,40,15,10);//Front Circle.
    iFilledEllipse(mycar.main_structure.x+40,mycar.main_structure.y+1,40,10,10);
    iFilledRectangle(mycar.main_structure.x+5,mycar.main_structure.y+45,5,40);
    iFilledRectangle(mycar.main_structure.x+70,mycar.main_structure.y+45,5,40);
    iSetColor(200, 0, 0);
    iFilledEllipse(mycar.main_structure.x+40,mycar.main_structure.y+10,40,10,10);
    iSetColor(0, 0, 0);
    iLine(mycar.main_structure.x+15,mycar.main_structure.y+50,mycar.main_structure.x+15,mycar.main_structure.y+85);
    iLine(mycar.main_structure.x+65,mycar.main_structure.y+50,mycar.main_structure.x+65,mycar.main_structure.y+85);
    iLine(mycar.main_structure.x+15,mycar.main_structure.y+50,mycar.main_structure.x+65,mycar.main_structure.y+50);
    iLine(mycar.main_structure.x+5,mycar.main_structure.y+1,mycar.main_structure.x+12,mycar.main_structure.y+19);
    iLine(mycar.main_structure.x+80,mycar.main_structure.y+1,mycar.main_structure.x+70,mycar.main_structure.y+19);
    iLine(mycar.main_structure.x+15,mycar.main_structure.y+120,mycar.main_structure.x+10,mycar.main_structure.y+140);
	iLine(mycar.main_structure.x+65,mycar.main_structure.y+120,mycar.main_structure.x+70,mycar.main_structure.y+140);
    iFilledRectangle(mycar.main_structure.x-5,mycar.main_structure.y+15,4,25);//wheel
    iFilledRectangle(mycar.main_structure.x+80,mycar.main_structure.y+15,4,25);//wheel
    iFilledRectangle(mycar.main_structure.x-5,mycar.main_structure.y+115,4,25);//wheel
    iFilledRectangle(mycar.main_structure.x+80,mycar.main_structure.y+115,4,25);//wheel
    iSetColor(225,1236,134);
    iFilledCircle(mycar.main_structure.x+75,mycar.main_structure.y+150,7,10);//Head Light
    iFilledCircle(mycar.main_structure.x+7,mycar.main_structure.y+148,7,10);//Head Light

}






void Enemy_car(struct component car1[],int j)
{

    iSetColor(200, 0, 0);
    iFilledRectangle(car1[j].main_structure.x,car1[j].main_structure.y,55,105);//Engine.
    iSetColor(0, 20, 0);
    iFilledRectangle(car1[j].main_structure.x+7,car1[j].main_structure.y+10,40,20);//RoofTop.
    iSetColor(200, 0, 0);
    iFilledEllipse(car1[j].main_structure.x+28,car1[j].main_structure.y+100,28,15,50);//Front Circle.
    iSetColor(0, 0, 0);
    iFilledEllipse(car1[j].main_structure.x+28,car1[j].main_structure.y+70,28,15,50);//Main Glass.Author:Minhaz Uddin
    iSetColor(139,131,134);
    iFilledCircle(car1[j].main_structure.x+5,car1[j].main_structure.y+103,5,100);//Head Light.
    iFilledCircle(car1[j].main_structure.x+50,car1[j].main_structure.y+103, 5,100); //Head Light.
    iSetColor(20, 20, 20);
    iFilledEllipse(car1[j].main_structure.x+2,car1[j].main_structure.y-1,8,5,3);//Back_corner  light.
    iFilledEllipse(car1[j].main_structure.x+52,car1[j].main_structure.y-1,-8,-5,3);//Back_Corner light.
    iSetColor(200, 200,200);
    iFilledRectangle(car1[j].main_structure.x+15,car1[j].main_structure.y-2,20,1);//Back light.

}



void highscore_saver()
{
	n[cp]='\0';
	track.highscore.score=score;

	save =fopen("text.txt","w");
	fprintf(save,"%d %s",track.highscore.score,n);
	fclose(save);
	remove("save.txt");
	rename("text.txt","save.txt");
	enter=1;

}
void myexit()
{

	iClear();




if(sbox1x<=300 && sbox3x<=300)
	{
		sbox1x++;
		sbox3x++;
	}
		if( sbox2x>=300 )
	{
		sbox2x=sbox2x-2;
		sbox4x=sbox4x-2;

	}




	iSetColor(250, 250, 250);

	if(sbox1x<=300 && sbox3x<=300)
	{
		sbox1x++;
		sbox3x++;
	}
		if( sbox2x>=300 && sbox4x>=300)
	{
		sbox2x=sbox2x-2;
		sbox4x=sbox4x-2;

	}
	iLine(sbox1x,sbox1y,sbox1x+xlength, sbox1y);
	iLine(sbox1x-10,sbox1y+5,sbox1x+xlength+10, sbox1y+5);
	iLine(sbox1x-diffa,sbox1y-ywidth+5,sbox1x+xlength-diffa,sbox1y-ywidth+5);
	iLine(sbox1x-diffa-10,sbox1y-50,sbox1x-diffa+xlength+10, sbox1y-50);

	iLine(sbox1x,sbox1y,sbox1x-diffa,sbox1y-ywidth+5);
	iLine(sbox1x-10,sbox1y+5,sbox1x-diffa-10,sbox1y-50);
	iLine(sbox1x+xlength, sbox1y,sbox1x+xlength-diffa,sbox1y-ywidth+5);
	iLine(sbox1x+xlength+10, sbox1y+5,sbox1x-diffa+xlength+10, sbox1y-50);




	iLine(sbox2x,sbox2y,sbox2x+xlength, sbox2y);
	iLine(sbox2x-10,sbox2y+5,sbox2x+xlength+10, sbox2y+5);
	iLine(sbox2x-diffa,sbox2y-ywidth+5,sbox2x+xlength-diffa,sbox2y-ywidth+5);
	iLine(sbox2x-diffa-10,sbox2y-50,sbox2x-diffa+xlength+10, sbox2y-50);
	iLine(sbox2x,sbox2y,sbox2x-diffa,sbox2y-ywidth+5);
	iLine(sbox2x-10,sbox2y+5,sbox2x-diffa-10,sbox2y-50);
	iLine(sbox2x+xlength, sbox2y,sbox2x+xlength-diffa,sbox2y-ywidth+5);
	iLine(sbox2x+xlength+10, sbox2y+5,sbox2x-diffa+xlength+10, sbox2y-50);





	iLine(sbox3x,sbox3y,sbox3x+xlength, sbox3y);
	iLine(sbox3x-10,sbox3y+5,sbox3x+xlength+10, sbox3y+5);
	iLine(sbox3x-diffa,sbox3y-ywidth+5,sbox3x+xlength-diffa,sbox3y-ywidth+5);
	iLine(sbox3x-diffa-10,sbox3y-50,sbox3x-diffa+xlength+10,sbox3y-50);

	iLine(sbox3x,sbox3y,sbox3x-diffa,sbox3y-ywidth+5);
	iLine(sbox3x-10,sbox3y+5,sbox3x-diffa-10,sbox3y-50);
	iLine(sbox3x+xlength, sbox3y,sbox3x+xlength-diffa,sbox3y-ywidth+5);
	iLine(sbox3x+xlength+10, sbox3y+5,sbox3x-diffa+xlength+10, sbox3y-50);




		iSetColor(20, 200, 0);
		iText(sbox1x,sbox1y-30,"Do You Really Want To Exit",GLUT_BITMAP_TIMES_ROMAN_24);



	if(choice==8 && myo <= 520 && myo >= 470 && mxo >=270 && mxo<=590)
	{
		iSetColor(250, 0, 0);
	}
	else
	{iSetColor(20, 200, 0);}
	iText(sbox2x+80,sbox2y-30,"YES",GLUT_BITMAP_TIMES_ROMAN_24);

	if(choice==8 && myo <= 420 && myo >= 370 && mxo >=270 && mxo<=590)
	{
		iSetColor(250, 0, 0);
	}
	else
	{iSetColor(20, 200, 0);}
	iText(sbox3x+80,sbox3y-30,"NO",GLUT_BITMAP_TIMES_ROMAN_24);


}
void highscorer()

{
		iClear();
	iSetColor(250, 250, 250);
	iText(300, 380,"--Congratulation--",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(250, 350,"Enter Your Name",GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(216,191,216);
	iRectangle(405,255,140,30);
	iRectangle(400,250,150,40);
	if(choice==7 && mxo>=400 && mxo<= 550 && myo > 290 && myo <325 && cp!=0)
	{
		iSetColor(250, 0, 0);
	}
	else
	{iSetColor(20, 200, 0);}

	iText(435, 263,"Enter",GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(250,250, 250);
	iFilledRectangle(250,300,300,40);
	iSetColor(0,0,0);
	iText(250,310,n,GLUT_BITMAP_TIMES_ROMAN_24);
	if(enter==1){
		highscore_saver();
	}

}
void gameover()
{
		iClear();
		iSetColor(255,255,255);
		if(score>=highscore && highscoretag==1)
			{
				highscore_saver();
				highscoretag=0;
			}
		iText(200,260,"Click(Mouse) Anywhere To Go Main Menu",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(250, 400,"Game Over!!!",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(250, 370,"Your Score",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(280, 340,itoa(score,buffer,10),GLUT_BITMAP_TIMES_ROMAN_24);

}



void lavel()
{


	iClear();

	if(sbox1x>=300 && anim==1){
	sbox1x=0;sbox2x=900;sbox3x=0;sbox4x=900;
	sbox1y=600;sbox2y=500;sbox3y=400;sbox4y=300;
	anim=0;
	}
	choice=2;
	iSetColor(250, 250, 250);

	if(sbox1x<=300 && sbox3x<=300)
	{
		sbox1x++;
		sbox3x++;
	}
		if( sbox2x>=300 )
	{
		sbox2x=sbox2x-2;
		sbox4x=sbox4x-2;

	}
	iLine(sbox1x,sbox1y,sbox1x+xlength, sbox1y);
	iLine(sbox1x-10,sbox1y+5,sbox1x+xlength+10, sbox1y+5);
	iLine(sbox1x-diffa,sbox1y-ywidth+5,sbox1x+xlength-diffa,sbox1y-ywidth+5);
	iLine(sbox1x-diffa-10,sbox1y-50,sbox1x-diffa+xlength+10, sbox1y-50);

	iLine(sbox1x,sbox1y,sbox1x-diffa,sbox1y-ywidth+5);
	iLine(sbox1x-10,sbox1y+5,sbox1x-diffa-10,sbox1y-50);
	iLine(sbox1x+xlength, sbox1y,sbox1x+xlength-diffa,sbox1y-ywidth+5);
	iLine(sbox1x+xlength+10, sbox1y+5,sbox1x-diffa+xlength+10, sbox1y-50);




	iLine(sbox2x,sbox2y,sbox2x+xlength, sbox2y);
	iLine(sbox2x-10,sbox2y+5,sbox2x+xlength+10, sbox2y+5);
	iLine(sbox2x-diffa,sbox2y-ywidth+5,sbox2x+xlength-diffa,sbox2y-ywidth+5);
	iLine(sbox2x-diffa-10,sbox2y-50,sbox2x-diffa+xlength+10, sbox2y-50);
	iLine(sbox2x,sbox2y,sbox2x-diffa,sbox2y-ywidth+5);
	iLine(sbox2x-10,sbox2y+5,sbox2x-diffa-10,sbox2y-50);
	iLine(sbox2x+xlength, sbox2y,sbox2x+xlength-diffa,sbox2y-ywidth+5);
	iLine(sbox2x+xlength+10, sbox2y+5,sbox2x-diffa+xlength+10, sbox2y-50);





		iLine(sbox3x,sbox3y,sbox3x+xlength, sbox3y);
	iLine(sbox3x-10,sbox3y+5,sbox3x+xlength+10, sbox3y+5);
	iLine(sbox3x-diffa,sbox3y-ywidth+5,sbox3x+xlength-diffa,sbox3y-ywidth+5);
	iLine(sbox3x-diffa-10,sbox3y-50,sbox3x-diffa+xlength+10,sbox3y-50);

	iLine(sbox3x,sbox3y,sbox3x-diffa,sbox3y-ywidth+5);
	iLine(sbox3x-10,sbox3y+5,sbox3x-diffa-10,sbox3y-50);
	iLine(sbox3x+xlength, sbox3y,sbox3x+xlength-diffa,sbox3y-ywidth+5);
	iLine(sbox3x+xlength+10, sbox3y+5,sbox3x-diffa+xlength+10, sbox3y-50);














	iSetColor(20, 200, 0);

	if(choice==2 && myo <= 620 && myo >= 570 && mxo >=270 && mxo<=590)
	{
		iSetColor(250, 0, 0);
	}
	else
	{iSetColor(20, 200, 0);}
	iText(sbox1x+80,sbox1y-30,"Easy",GLUT_BITMAP_TIMES_ROMAN_24);

	if(choice==2 && myo <= 520 && myo >= 470 && mxo >=270 && mxo<=590)
	{
		iSetColor(250, 0, 0);
	}
	else
	{iSetColor(20, 200, 0);}
	iText(sbox2x+80,sbox2y-30,"Medium",GLUT_BITMAP_TIMES_ROMAN_24);

	if(choice==2 && myo <= 420 && myo >= 370 && mxo >=270 && mxo<=590)
	{
		iSetColor(250, 0, 0);
	}
	else
	{iSetColor(20, 200, 0);}
	iText(sbox3x+80,sbox3y-30,"Hard",GLUT_BITMAP_TIMES_ROMAN_24);




}


void play()
{

		iClear();
racetrack(track);
car1[0].main_structure.y=track.left_side_of_race_track.y+mod_car1_y[0];
car1[1].main_structure.y=track.left_side_of_race_track.y+mod_car1_y[1];
car1[2].main_structure.y=track.left_side_of_race_track.y+mod_car1_y[2];
car1[3].main_structure.y=track.left_side_of_race_track.y+mod_car1_y[3];
car1[0].main_structure.x =position_car1_x[0];
car1[1].main_structure.x =position_car1_x[1];
car1[2].main_structure.x =position_car1_x[2];
car1[3].main_structure.x =position_car1_x[3];
 if(track.left_side_of_race_track.y <=-1800)
 {
	scoretag[0]=1;
	scoretag[1]=1;
	scoretag[2]=1;
	scoretag[3]=1;
	collidetag[0]=1;
	collidetag[1]=1;
	collidetag[2]=1;
	collidetag[3]=1;

         track.left_side_of_race_track.y=0;
         number_of_car=rand()% max_number_of_car;
         for(i=0;i<=number_of_car;i++)
		 {
                mod_car1_x[i]=rand()%330;
				mod_car1_y[i]=900+rand()%500;
                position_car1_x[i]=mod_car1_x[i]+330;
		 }

 }
 if(resume==0)
 {

	track.left_side_of_race_track.y -=speed;

 }
     for(j=0;j<=number_of_car && mod_car1_x[0] != mod_car1_x[1]	&&  mod_car1_x[0] != mod_car1_x[2] && mod_car1_x[0] != mod_car1_x[3] && mod_car1_x[1] != mod_car1_x[2] &&  mod_car1_x[1] != mod_car1_x[3] && mod_car1_x[2] != mod_car1_x[3]
 ;j++)


     {      Enemy_car(car1,j);
				//if((mycar.main_structure.y + mycar.main_structure.length)>=  car1[j].main_structure.y && (mycar.main_structure.x - 55)<= car1[j].main_structure.x   && (mycar.main_structure.x  + mycar.main_structure.width) >= car1[j].main_structure.x )
			if((mycar.main_structure.y + mycar.main_structure.length-speed)<=  car1[j].main_structure.y && (mycar.main_structure.y + mycar.main_structure.length)>  car1[j].main_structure.y  && (mycar.main_structure.x - 55)<= car1[j].main_structure.x   && (mycar.main_structure.x  + mycar.main_structure.width) >= car1[j].main_structure.x )

				{
				//collidetag[j]=0;
				iDelay(1);
				life--;

			}

     }

for(i=0;i<=number_of_car;i++)
{

	//if(mycar.main_structure.y >= car1[i].main_structure.y  && scoretag[i]==1)
	if((mycar.main_structure.y+speed)>= car1[i].main_structure.y && mycar.main_structure.y < car1[i].main_structure.y && track.divider.x >= car1[i].main_structure.x && car1[i].main_structure.x >= track.left_side_of_race_track.width)
		{
			score +=1;
			///scoretag[i]=0;

		}
}

     Dynamic_car(mycar);
	 for(i=0;i<life*15*5;i=i+5)
	 {
		 if(life==0)
		 {
			  iSetColor(176,23,31);
		 }
		 else if(life==1)
		 {
			 iSetColor(176,23,31);
		 }
		 else if(life==2)
		 {
			iSetColor(205,205,0);
		 }
		 else
		 {
			iSetColor(61,145,64);
		 }

			iLine(track.lifebox.x ,track.lifebox.y+i+25,track.lifebox.x + track.lifebox.width,track.lifebox.y+i+25);

	     }
	  if(score>=highscore)
	  {
		 highscore=score;
		iSetColor(176,23,31);
		iText(870, 610,itoa(score,buffer,10),GLUT_BITMAP_TIMES_ROMAN_24);
		iText(800, 730,"New Highscore");
		iText(870, 710,itoa(highscore,buffer,10),GLUT_BITMAP_TIMES_ROMAN_24);
	  }
	  else
	 iSetColor(176,23,31);
     iText(870, 610,itoa(score,buffer,10),GLUT_BITMAP_TIMES_ROMAN_24);
	 iText(870, 710,itoa(highscore,buffer,10),GLUT_BITMAP_TIMES_ROMAN_24);



	 if(life <= 0 && score>=highscore)
	 {
		choice=7;

	 }
	 else if(life<=0){
		choice =3;
	 }


}
void iDraw() {

	    switch(choice)
		{
			case 0:mainMenu();
				break;
			case 1: play();
				break;
			case 2:lavel();
				break;
			case 3: gameover();
				break;
			case 4: exit(0);
				break;
			case 6: show_highscore();
				break;
			case 7: highscorer();
				break;
			case 8: myexit();
				break;
			default:mainMenu();
		}

}

void iMouseMove(int mx, int my) {

		printf("x=%d\ty=%d\n",mx,my);
}

void iPassiveMouseMove(int mx,int my)
{

mxo=mx;
myo=my;

}


void iMouse(int button, int state, int mx, int my) {

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN  && choice==0 && my <= 620 && my >= 570 && mx >=270 && mx<=590) {
			choice=1;

		}
	else if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN  && choice == 3  ){

		all_declaration();

	}
		else if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN  && choice == 6  ){
		all_declaration();
	}

	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN  && choice ==0 && my <= 520 && my >= 470 && mx >=270 && mx<=590) {
		choice=2;
	}

else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && choice==2 &&  my <= 620 && my >= 570 && mx >=270 && mx<=590 ) {
			speed =3;
			max_number_of_car=2;
			choice=0;
			frame();
	}
else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && choice == 2 && my <= 520 && my >= 470 && mx >=270 && mx<=590  ) {
			speed =4;
			max_number_of_car=3;
			choice=0;
			frame();

	}
else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && choice==2 &&  my <= 420 && my >= 370 && mx >=270 && mx<=590   ) {
			speed =5;
			max_number_of_car=4;
			choice=0;
			frame();
	}

else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && choice==5 ) {
				choice=1;
	}


else if (button == GLUT_LEFT_BUTTON  && state == GLUT_DOWN &&  choice==0 && my <= 420 && my >= 370 && mx >=270 && mx<=590 ) {
			choice= 6;


	}
else if (button == GLUT_LEFT_BUTTON  && state == GLUT_DOWN && choice==0 && my <= 320 && my >= 270 && mx >=270 && mx<=590 ) {
			choice= 4;


	}
else if (button == GLUT_LEFT_BUTTON  && state == GLUT_DOWN && choice==1 && mx >900  && my > 0 && my <30) {
		if(resume==1)
		{
			resume=0;
		}
		else
			resume=1;

	}


else if (button == GLUT_LEFT_BUTTON  && state == GLUT_DOWN && choice==1 && mx>=250 && mx<= 300 && my > 400 && my <800) {

	choice= 0;

	}
else if (button == GLUT_LEFT_BUTTON  && state == GLUT_DOWN && choice==7 && mx>=400 && mx<= 550 && my > 290 && my <325 && cp!=0 ) {


	enter=1;
	choice= 3;

	}

else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && choice == 8 && my <= 520 && my >= 470 && mx >=270 && mx<=590  ) {

			all_declaration();

	}
else if (button == GLUT_LEFT_BUTTON  && state == GLUT_DOWN && choice==8 && my <= 420 && my >= 370 && mx >=270 && mx<=590 ) {
			choice= 1;
			resume=0;


	}


}

void iKeyboard(unsigned char key) {


	if(key == 'a' && choice ==7)
{
	if(cp==0){
		n[cp]='A';
	}
	else
	n[cp]='a';
}
	else if(key == 'b' && choice ==7)
{
	if(cp==0){
		n[cp]='B';
	}
	else
	n[cp]='b';

}

	else if(key == 'c' && choice ==7)
{	if(cp==0){
		n[cp]='C';
	}
	else
	n[cp]='c';

}
	else if(key == 'd' && choice ==7)
{	if(cp==0){
		n[cp]='D';
	}
	else
	n[cp]='d';

}
	else if(key == 'e' && choice ==7)
{	if(cp==0){
		n[cp]='E';
	}
	else
	n[cp]='e';

}
	else if(key == 'f' && choice ==7)
{
		if(cp==0){
		n[cp]='F';
	}
	else
	n[cp]='f';

}


	else if(key == 'g' && choice ==7)
{	if(cp==0){
		n[cp]='G';
	}
	else
	n[cp]='g';

}
	else if(key == 'h' && choice ==7)
{	if(cp==0){
		n[cp]='H';
	}
	else
	n[cp]='h';

}
		else if(key == 'i' && choice ==7)
{	if(cp==0){
		n[cp]='I';
	}
	else
	n[cp]='i';

}

	else if(key == 'j' && choice ==7)
{	if(cp==0){
		n[cp]='J';
	}
	else
	n[cp]='j';


}
	else if(key == 'k' && choice ==7)
{	if(cp==0){
		n[cp]='K';
	}
	else
	n[cp]='k';

}
	else if(key == 'l' && choice ==7)
{	if(cp==0){
		n[cp]='L';
	}
	else
	n[cp]='l';


}
	else if(key == 'm' && choice ==7)
{	if(cp==0){
		n[cp]='M';
	}
	else
	n[cp]='m';

}
	else if(key == 'n' && choice ==7)
{	if(cp==0){
		n[cp]='N';
	}
	else
	n[cp]='n';


}
	else if(key == 'o' && choice ==7)
{	if(cp==0){
		n[cp]='O';
	}
	else
	n[cp]='o';

}
	else if(key == 'p' && choice ==7)
{	if(cp==0){
		n[cp]='P';
	}
	else
	n[cp]='p';

}

	else if(key == 'q' && choice ==7)
{	if(cp==0){
		n[cp]='Q';
	}
	else
	n[cp]='q';


}
	else if(key == 'r' && choice ==7)
{	if(cp==0){
		n[cp]='R';
	}
	else
	n[cp]='r';

}
	else if(key == 's' && choice ==7)
{	if(cp==0){
		n[cp]='S';
	}
	else
	n[cp]='s';


}
	else if(key == 't' && choice ==7)
{	if(cp==0){
		n[cp]='T';
	}
	else
	n[cp]='t';

}


	else if(key == 'u' && choice ==7)
{	if(cp==0){
		n[cp]='U';
	}
	else
	n[cp]='u';


}
	else if(key == 'v' && choice ==7)
{	if(cp==0){
		n[cp]='V';
	}
	else
	n[cp]='v';

}
	else if(key == 'w' && choice ==7)
{	if(cp==0){
		n[cp]='W';
	}
	else
	n[cp]='w';

}

	else if(key == 'x' && choice ==7)
{	if(cp==0){
		n[cp]='X';
	}
	else
	n[cp]='x';



}
	else  if(key == 'y' && choice ==7)
{	if(cp==0){
		n[cp]='Y';
	}
	else
	n[cp]='y';

}
	else if(key == 'z' && choice ==7)
{	if(cp==0){
		n[cp]='Z';
	}
	else
	n[cp]='z';


}
	else if(key==' ' && choice==7){
			n[cp]=' ';

	}
	else{}
	cp++;









if(key == ' ' &&  mycar.main_structure.y + mycar.main_structure.width<=700 && choice==1){

		mycar.main_structure.y +=300;

	}









}





























/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/

void iSpecialKeyboard(unsigned char key) {

	if ( key == GLUT_KEY_RIGHT &&  mycar.main_structure.x  < track.divider.x - mycar.main_structure.width ) {

		mycar.main_structure.x += 50;

	}
	else if( key == GLUT_KEY_LEFT  &&mycar.main_structure.x  > track.race_track.x  ){

		mycar.main_structure.x  -= 50 ;

	}
	else if ( key == GLUT_KEY_UP && (mycar.main_structure.y + mycar.main_structure.width )<= 700) {

		 mycar.main_structure.y += 50;

	}
	else if( key == GLUT_KEY_DOWN  && mycar.main_structure.y >= 0){

		mycar.main_structure.y -= 50  ;

	}
		else if( key ==GLUT_KEY_HOME  && (choice==1 || choice==8)){


		 if(resume==1 && choice==1)
		 {
			 resume=0;
		 }
		 else if(resume==0 && choice==1)
		 {
			 resume=1;

		 }
		}

		else if( key == GLUT_KEY_END && choice==1){

			choice=8;
			resume=0;
			frame();


	}





}

int main() {

	all_declaration();
	iInitialize(1000, 800, "Car Racing");

	return 0;
}
