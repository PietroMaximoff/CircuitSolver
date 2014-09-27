//Siddhant Ranade 130260002
//Unmesh Phadke 130260006

#include<simplecpp>

class Button{
	Text t;
	Rectangle r;
public:
	Button(double cxi, double cyi, string text);
	bool wasClicked(double x, double y);
	void hide();
	void show();
};
