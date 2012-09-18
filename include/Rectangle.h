class Rectangle{
public:
	Rectangle(int depth, ci::Vec2f position, ci::Vec2f offset, float radius);
	Rectangle* next_;
	Rectangle* prev_;
	

	ci::Vec2f position_;
	ci::Vec2f velocity_;
	float radius_;
	ci::Vec2f offset_;
	void draw(ci::Vec2i mouse_pos);

};

//void insertAfter(Rectangle* therect);
