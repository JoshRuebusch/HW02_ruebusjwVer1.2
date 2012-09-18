#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"
#include "cinder/Vector.h"
#include "Rectangle.h"
#include "cinder/Rect.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Rectangle::Rectangle(int depth, ci::Vec2f position, ci::Vec2f offset, float radius){

	next_ = this;
	prev_ = this;

	position_ = position;
	offset_ = offset;
	radius_ = radius;

}
/*
void insertAfter(Rectangle* therect, Rectangle* newItem){

}*/