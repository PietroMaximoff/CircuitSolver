//Siddhant Ranade 130260002
//Unmesh Phadke 130260006

#include<simplecpp>
#include<sstream>
#include "../include/RCV.h"
#include "getInput.h"

const double rVert[14][2]={{-30,0}, {-25,-5}, {-15,5}, {-5,-5}, {5,5}, {15,-5}, {25,5}, {30,0}, {25,5}, {15,-5}, {5,5}, {-5,-5}, {-15,5}, {-25,-5}};

Node::Node(double cxi, double cyi, double ri) : c(cxi, cyi, ri){
	c.show();
}
Node::Node(Node& tmp) : c(tmp.c.getOrigin().getX(), tmp.c.getOrigin().getY(), tmp.c.getRadius()){
	c.show();
}
bool Node::wasClicked(double x, double y){
	if (pow(x-c.getOrigin().getX(), 2) + pow(y-c.getOrigin().getY(), 2) <= pow(c.getRadius(),2)) return true;
	return false;
}
int Node::getX() {return c.getOrigin().getX();}
int Node::getY() {return c.getOrigin().getY();}


int whoWasClicked(double x, double y, vector<Node*> list){
	for(unsigned int i=0; i<list.size(); i++) if(list[i]->wasClicked(x, y)) return i;
	return -1;
}

Resistance::Resistance(int p, int q, double res, vector<Node*> list, int cx, int cy) : r(res), a(p), b(q), x(cx), y(cy), t(cx, cy, NToS(res)),
resistor(cx, cy, rVert, 14) {
	//l.setColor(COLOR("red"));
	double angle=arctan2((list[q]->c.getOrigin().getY())-(list[p]->c.getOrigin().getY()), (list[q]->c.getOrigin().getX())-(list[p]->c.getOrigin().getX()));
	resistor.right(angle);
	t.move(15*sine(angle), -15*cosine(angle));
	l1.reset(list[p]->c.getOrigin().getX(), list[p]->c.getOrigin().getY(), cx-30*cosine(angle), cy-30*sine(angle));
	l2.reset(cx+30*cosine(angle), cy+30*sine(angle), list[q]->c.getOrigin().getX(), list[q]->c.getOrigin().getY());
}
int Resistance::left() {return a;}
int Resistance::right() {return b;}
double Resistance::res() {return r;}
int Resistance::getX() {return x;}
int Resistance::getY() {return y;}
double Resistance::getAngle(vector<Node*> list) {
	return arctan2((list[b]->c.getOrigin().getY())-(list[a]->c.getOrigin().getY()), (list[b]->c.getOrigin().getX())-(list[a]->c.getOrigin().getX()));
}
bool Resistance::wasClicked(double clx, double cly){
	if (pow(x-clx, 2) + pow(y-cly, 2) <= pow(10,2)) return true;
	return false;
}

int whoWasClicked(double x, double y, vector<Resistance*> list){
	for(unsigned int i=0; i<list.size(); i++) if(list[i]->wasClicked(x, y)) return i;
	return -1;
}

CurrentSource::CurrentSource(int p, int q, double cur, vector<Node*> list, int cx, int cy) : i(cur), a(p), b(q), x(cx), y(cy), t(cx, cy, NToS(cur)+" A"), c(cx, cy, 30) {
	double angle=arctan2((list[q]->c.getOrigin().getY())-(list[p]->c.getOrigin().getY()), (list[q]->c.getOrigin().getX())-(list[p]->c.getOrigin().getX()));
	l1.reset(list[p]->c.getOrigin().getX(), list[p]->c.getOrigin().getY(), cx-30*cosine(angle), cy-30*sine(angle));
	l2.reset(cx+30*cosine(angle), cy+30*sine(angle), list[q]->c.getOrigin().getX(), list[q]->c.getOrigin().getY());
	t1.reset(cx-40*cosine(angle)+10*sine(angle), cy-40*sine(angle)-10*cosine(angle), "+");
	t2.reset(cx+40*cosine(angle)+10*sine(angle), cy+40*sine(angle)-10*cosine(angle), "-");
}
int CurrentSource::left() {return a;}
int CurrentSource::right() {return b;}
double CurrentSource::cur() {return i;}
int CurrentSource::getX() {return x;}
int CurrentSource::getY() {return y;}


VoltageSource::VoltageSource(int p, int q, double vol, vector<Node*> list, int cx, int cy) : v(vol), a(p), b(q), x(cx), y(cy), t(cx, cy, NToS(vol)+" V") {
	double angle=arctan2((list[q]->c.getOrigin().getY())-(list[p]->c.getOrigin().getY()), (list[q]->c.getOrigin().getX())-(list[p]->c.getOrigin().getX()));
	t.move(30*sine(angle), -30*cosine(angle));
	l1.reset(list[p]->c.getOrigin().getX(), list[p]->c.getOrigin().getY(), cx-10*cosine(angle), cy-10*sine(angle));
	l2.reset(cx+10*cosine(angle), cy+10*sine(angle), list[q]->c.getOrigin().getX(), list[q]->c.getOrigin().getY());
	vl1.reset(cx-10*cosine(angle)-15*sine(angle), cy-10*sine(angle)+15*cosine(angle), cx-10*cosine(angle)+15*sine(angle), cy-10*sine(angle)-15*cosine(angle));
	vl2.reset(cx+10*cosine(angle)-30*sine(angle), cy+10*sine(angle)+30*cosine(angle), cx+10*cosine(angle)+30*sine(angle), cy+10*sine(angle)-30*cosine(angle));
}
int VoltageSource::left() {return a;}
int VoltageSource::right() {return b;}
double VoltageSource::vol() {return v;}
int VoltageSource::getX() {return x;}
int VoltageSource::getY() {return y;}
double VoltageSource::getAngle(vector<Node*> list) {
	return arctan2((list[b]->c.getOrigin().getY())-(list[a]->c.getOrigin().getY()), (list[b]->c.getOrigin().getX())-(list[a]->c.getOrigin().getX()));
}

