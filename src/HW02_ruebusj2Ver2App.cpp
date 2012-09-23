#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Rectangle.h"
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
	Vec2f trans;
	bool pressed;
	int rand1;
	int rand2;

	bool insert;
	bool reverse;
private:
	rectangle* rect_list;
	rectangle* newPoint;
	static const int appWidth=800;
	static const int appHeight=600;
	static const Vec2f x_;
	static const Vec2f y_;
	int frameNum;

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
	rect_list = new rectangle(4, trans, Vec2f(0,0), 50);
	frameNum = 0;
	rand1 = 0;
	rand2 = 0;
}

void HW02_ruebusj2Ver2App::keyDown( KeyEvent event){
	if(event.getChar() == 'q')
		insert = true;

	if(event.getChar() == 'r')
		reverse = true;
}


void HW02_ruebusj2Ver2App::mouseDown( MouseEvent event )
{
	
}



void HW02_ruebusj2Ver2App::update()
{
	if(reverse)
	{
		reverseList(rect_list);
		reverse = false;
	}
	
	rectangle* cur = rect_list;
	if(cur != NULL){
		do{

			if(frameNum%30==0)
	{
		if(cur->position_.x < 50)
		{
			rand1 = 1;
			rand2 = rand()%3-1;
		}
		else if(cur->position_.y < 50)
		{
			rand1 = rand()%3-1;
			rand2 = 1;
		}
		else if(cur->position_.x<50 && cur->position_.y<50)
		{
			rand1 = 1;
			rand2 = 1;
		}
		else
		{
			rand1 = rand()%3-1;
			rand2 = rand()%3-1;
		}
	}

			cur->position_ = cur->position_ + rand1*x_+rand2*y_;
			/*
			if(frameNum==2)
				pressed = true;*/

			if(insert)
			{
				newPoint = new rectangle(3, trans, Vec2f(0,0),50); 

				insertAfter(newPoint, rect_list);
				cur->next_->position_ = 50*x_+50*y_;
				insert = false;
				frameNum++;
			}
			cur = cur->next_;
		} while (cur != rect_list);
	}
	frameNum++;
}

void HW02_ruebusj2Ver2App::draw()
{
	// clear out the window with black
	gl::clear( Color( 255, 255, 255 ) ); 

	rectangle* cur = rect_list;
	if(cur != NULL){
		do{
			if(cur == rect_list)
			{
			}
			else
			{
			cur->draw(cur->position_, 255,0,0);
			}
			cur = cur->next_;
		} while (cur != rect_list);
	}
}

CINDER_APP_BASIC( HW02_ruebusj2Ver2App, RendererGl )
