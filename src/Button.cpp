//Siddhant Ranade 130260002
//Unmesh Phadke 130260006

#include<simplecpp>
#include "../include/Button.h"

Button::Button(double cxi, double cyi, string text) : t(cxi, cyi, text), r(cxi, cyi, textWidth(text)+10, textHeight()+10){
		r.show();
	}
bool Button::wasClicked(double x, double y){
	if (x>=r.getOrigin().getX()-r.getWidth()/2 && x<=r.getOrigin().getX()+r.getWidth()/2 && y>=r.getOrigin().getY()-r.getHeight()/2 && y<=r.getOrigin().getY()+r.getHeight()/2) return true;
		else return false;
}
void Button::hide(){
	r.hide();
	t.hide();
}
void Button::show(){
	r.show();
	t.show();
}
