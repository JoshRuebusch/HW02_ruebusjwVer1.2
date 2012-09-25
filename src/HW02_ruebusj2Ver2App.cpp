#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "rectangle.h"           
//Lucy: "What you defined before 'Rectangle.h' will not work under Mac and other versions, only under windows. So I think it is important to change the beginning letter to lowercase."
#include "cinder/app/KeyEvent.h"


using namespace ci;
using namespace ci::app;
using namespace std;

class HW02_ruebusj2Ver2App : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void keyDown( KeyEvent event );
	void update();
	void draw();
	void prepareSettings(Settings* settings);

	//Lucy:"I will suggest to move all these variables to private part because we may not want others to change them."
	
private:
	rectangle* rect_list;
	rectangle* newPoint;
	static const int appWidth=800;
	static const int appHeight=600;
	static const Vec2f x_;
	static const Vec2f y_;
	int counter;
	int frameNum;

	Vec2f trans;
	bool pressed;

	int xPos;
	int yPos;

	int rand1;
	int rand2;

	int cRed;
	int cGreen;
	int cBlue;

	bool insert;
	bool reverse;
	bool solid;

};

const Vec2f HW02_ruebusj2Ver2App::x_ = Vec2f(1.0f,0.0f);
const Vec2f HW02_ruebusj2Ver2App::y_ = Vec2f(0.0f,1.0f);

void HW02_ruebusj2Ver2App::prepareSettings(Settings* settings){
	settings->setWindowSize(appWidth,appHeight);
	settings->setResizable(false);
}

void HW02_ruebusj2Ver2App::setup()
{
	insert = false;
	reverse = false;
	pressed = false;
	trans = 55*x_ + 55*y_;
	rect_list = new rectangle(255, trans, Vec2f(0,0), 50,0,0);
	frameNum = 0;
	rand1 = 0;
	rand2 = 0;

	xPos = 50;
	yPos = 50;
	counter = 0;

	//Lucy: "From my own perspective, I may consider to create Color8u color = Color8u(r,g,b) directly instead of creating three variables separately. It may be easier and save code. "
	cRed = 255;
	cGreen = 0;
	cBlue = 0;
}

void HW02_ruebusj2Ver2App::keyDown( KeyEvent event){
	if(event.getChar() == 'q')
		insert = true;

	if(event.getChar() == 'r')
		reverse = true;
}


void HW02_ruebusj2Ver2App::mouseDown( MouseEvent event )
{//Lucy: "You did nothing by using mouseDown method, so I think we probably do not need getPos() method here. That is why I removed that line. 
}



void HW02_ruebusj2Ver2App::update()
{// Lucy: "Great way to reverse linked list by using boolean expression --> implement main goal E."
	if(reverse)
	{
		reverseList(rect_list);
		reverse = false;
	}
	
	// Lucy: "Make all the rectangles keep moving. I really love this creative idea! --> implement main goal D"
	rectangle* cur = rect_list;
	if(cur != NULL){
		do{
			if(frameNum%50==0)
	{
		if(cur->position_.x < 50)       
		{								
			rand1=cur->xDir_ = 2;		
			rand2=cur->yDir_= rand()%3-1;
		}
		else if(cur->position_.y < 50)
		{
			rand1 =cur->xDir_= rand()%3-1;
			rand2 =cur->yDir_= 2;
		}
		else if(cur->position_.x<50 && cur->position_.y<50)
		{
			rand1=cur->xDir_ = 2;
			rand2 =cur->yDir_= 2;
		}
		else
		{
			rand1 =cur->xDir_= rand()%3-1;
			rand2 =cur->yDir_= rand()%3-1;
		}
	}
			// Lucy: "Implement main goal A. I love your idea that keeping drawing one rectangle in different positions! Also creative to use only one variable for many rectangles."
			if(insert)
			{
				newPoint = new rectangle(cur->depth_-counter, trans, Vec2f(0,0),50, rand1, rand2); 
				insertAfter(newPoint, rect_list);
				cur->next_->position_ = xPos*x_+yPos*y_;
				if(yPos <=51 && xPos <= appWidth-51)
					xPos= xPos+10;
				else if(xPos>appWidth-51 && yPos<=appHeight-51)
					yPos= yPos+10;
				else if(yPos>appHeight-51 && xPos>= 51)
					xPos = xPos - 10;
				else
					yPos =yPos-10;
				counter++;

				insert = false;
			}

			

			cur->position_ = cur->position_ + cur->xDir_*x_+cur->yDir_*y_;
			/*
			if(frameNum==2)
				pressed = true;*/

			
			cur = cur->next_;
		} while (cur != rect_list);
	}
	frameNum++;
}

void HW02_ruebusj2Ver2App::draw()
{
	// clear out the window with white
	//Lucy: "This line's job is to clear out the window with white, not black. But it is not a big deal."
	gl::clear( Color( 255, 255, 255 ) ); 

	rectangle* cur = rect_list;
	if(cur != NULL){
		do{
			if(cur == rect_list)
			{//Lucy: "If there is nothing under this if statement, then we probably do not need it."
			}
			else
			{
			cur->draw(cur->position_, cur->depth_,cGreen,cBlue);
			}
			cur = cur->next_;
		} while (cur != rect_list);
	}
}

CINDER_APP_BASIC( HW02_ruebusj2Ver2App, RendererGl )
