class rectangle{
public:
	rectangle(int depth, ci::Vec2f position, ci::Vec2f offset, float radius);
	
	rectangle* next_;
	rectangle* prev_;
	
	ci::Vec2f offset_;
	ci::Vec2f position_;
	float radius_;
	
	bool isInside(float x, float y);
	void draw(ci::Vec2i position, int red, int green, int blue);
	void update(ci::Vec2f parent_position, float parent_r);
};

void insertAfter(rectangle* therect, rectangle* insert_here);
void bringToFront(rectangle* selected, rectangle* insert_here);
void reverseList(rectangle* from_front);
