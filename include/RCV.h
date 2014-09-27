//Siddhant Ranade 130260002
//Unmesh Phadke 130260006

#include<simplecpp>

class Node{
friend class Resistance;
friend class CurrentSource;
friend class VoltageSource;
Circle c;
public:
Node(double, double, double);
Node(Node&);
bool wasClicked(double, double);
int getX();
int getY();
};

class Resistance{
	double r;
	Line l1, l2;
	int a, b, x, y;
	Text t;
	Polygon resistor;
public:
	Resistance(int p, int q, double res, vector<Node*> list, int cx, int cy);
	int left();
	int right();
	double res();
	int getX();
	int getY();
	double getAngle(vector<Node*> list);
	bool wasClicked(double clx, double cly);
};

class CurrentSource{
	double i;
	Line l1, l2;
	int a, b, x, y;
	Text t, t1, t2;
	Circle c;
public:
	CurrentSource(int p, int q, double cur, vector<Node*> list, int cx, int cy);
	int left();
	int right();
	double cur();
	int getX();
	int getY();
};

class VoltageSource{double v;
	Line l1, l2, vl1, vl2;
	int a, b, x, y;
	Text t;
public:
	VoltageSource(int p, int q, double vol, vector<Node*> list, int cx, int cy);
	int left();
	int right();
	double vol();
	int getX();
	int getY();
	double getAngle(vector<Node*> list);
};

int whoWasClicked(double x, double y, vector<Node*> list);
int whoWasClicked(double x, double y, vector<Resistance*> list);