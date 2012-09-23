#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"
#include "rectangle.h"
#include "cinder/Rand.h";

using namespace ci;
using namespace ci::app;
using namespace std;

rectangle::rectangle(int depth, ci::Vec2f position, ci::Vec2f offset, float radius, int xDir, int yDir){

	next_ = this;
	prev_ = this;

	position_ = position;
	offset_ = offset;
	radius_ = radius;
	xDir_ = xDir;
	yDir_=yDir;
}

void insertAfter(rectangle* newItem, rectangle* insertHere){
	newItem->next_ = insertHere->next_;
	newItem->prev_= insertHere;
	insertHere->next_->prev_ = newItem;
	insertHere->next_=newItem;
}

void rectangle::draw(Vec2i mp, int red, int green, int blue){
	
	gl::drawSolidRect(Rectf(position_.x-radius_,position_.y-radius_,position_.x+radius_,position_.y+radius_));
	gl::color(Color8u(red,green,blue));
	gl::drawSolidRect(Rectf(position_.x-radius_+1, position_.y-radius_+1,position_.x+radius_-1,position_.y+radius_-1));
	gl::color(Color8u(0,0,0));
}

void reverseList(rectangle* first_node){
	rectangle* cur = first_node;
	do{
		rectangle* temp = cur->next_;
		cur->next_=cur->prev_;
		cur->prev_=temp;
		cur = cur->prev_;
	}
	while(cur!=first_node);
}

