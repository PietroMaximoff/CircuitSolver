//Siddhant Ranade 130260002
//Unmesh Phadke 130260006

#include<simplecpp>
#include<sstream>
#include "src/solve.h"
#include "src/getInput.h"
#include "src/matrixMath.h"
#include "include/RCV.h"
#include "include/Button.h"

#define HIDE_ALL addNode.hide(); addR.hide(); addI.hide(); addV.hide(); solve.hide(); exit.hide();
#define SHOW_ALL addNode.show(); addR.show(); addI.show(); addV.show(); solve.show(); exit.show();
#define DONE_BUTTON Button done(974, 740, "Done");

int main(){
	initCanvas("CircuitUI", 1024, 768);
	string aN="Add Node", aR="Add Resistance", aI="Add Current Source", aV="Add Battery", slv="Solve";
	
	Button addNode(textWidth(aN)/2+15, 20, aN);
	Button addR(textWidth(aN)+textWidth(aR)/2+30, 20, aR);
	Button addI(textWidth(aN)+textWidth(aR)+textWidth(aI)/2+45, 20, aI);
	Button addV(textWidth(aN)+textWidth(aR)+textWidth(aI)+textWidth(aV)/2+60, 20, aV);
	Button solve(textWidth(aN)+textWidth(aR)+textWidth(aI)+textWidth(aV)+textWidth(slv)/2+75, 20, slv);
	
	Button exit(1009, 18, "X");
	
	int g;
	vector<Node*> nlist;
	vector<Resistance*> rlist;
	vector<CurrentSource*> clist;
	vector<VoltageSource*> vlist;
	while(true){
		g=getClick();
		if(exit.wasClicked(g/65536, g%65536)) break;
		if(addNode.wasClicked(g/65536, g%65536)){
			DONE_BUTTON
			HIDE_ALL
			g=getClick();
			while(!done.wasClicked(g/65536, g%65536)){
				Node* p=new Node(g/65536, g%65536, 5);
				nlist.push_back(p);
				g=getClick();
			}
			SHOW_ALL
		}
		if(addR.wasClicked(g/65536, g%65536)){
			DONE_BUTTON
			int a, b;
			HIDE_ALL
			a=getClick();
			while(!done.wasClicked(a/65536, a%65536)){
				bool exit=false;
				b=getClick();
				int p, q;
				while(whoWasClicked(a/65536, a%65536, nlist)==-1){
					a=getClick();
					if(done.wasClicked(a/65536, a%65536)) {exit=true; break;}
				}
				if(exit) break;
				p=whoWasClicked(a/65536, a%65536, nlist);
				while((whoWasClicked(b/65536, b%65536, nlist)==-1)||(whoWasClicked(b/65536, b%65536, nlist)==whoWasClicked(a/65536, a%65536, nlist))){
					b=getClick();
					if(done.wasClicked(b/65536, b%65536)) {exit=true; break;}
				}
				if(exit) break;
				q=whoWasClicked(b/65536, b%65536, nlist);
				double r;
				r=getInput<double>("Enter resistance value and then click a nearby point: ");
				int j=getClick();
				Resistance* tmp= new Resistance(p, q, r, nlist, j/65536, j%65536);
				rlist.push_back(tmp);
				a=getClick();
			}
			SHOW_ALL
		}
		if(addI.wasClicked(g/65536, g%65536)){
			DONE_BUTTON
			int a, b;
			HIDE_ALL
			a=getClick();
			while(!done.wasClicked(a/65536, a%65536)){
				bool exit=false;
				b=getClick();
				int p, q;
				while(whoWasClicked(a/65536, a%65536, nlist)==-1){
					a=getClick();
					if(done.wasClicked(a/65536, a%65536)) {exit=true; break;}
				}
				if(exit) break;
				p=whoWasClicked(a/65536, a%65536, nlist);
				while((whoWasClicked(b/65536, b%65536, nlist)==-1)||(whoWasClicked(b/65536, b%65536, nlist)==whoWasClicked(a/65536, a%65536, nlist))){
					b=getClick();
					if(done.wasClicked(b/65536, b%65536)) {exit=true; break;}
				}
				if(exit) break;
				q=whoWasClicked(b/65536, b%65536, nlist);
				double i;
				i=getInput<double>("Enter current value and then click a nearby point: ");
				int j=getClick();
				CurrentSource* tmp= new CurrentSource(p, q, i, nlist, j/65536, j%65536);
				clist.push_back(tmp);
				a=getClick();
			}
			SHOW_ALL
		}
		if(addV.wasClicked(g/65536, g%65536)){
			DONE_BUTTON
			int a, b;
			HIDE_ALL
			a=getClick();
			while(!done.wasClicked(a/65536, a%65536)){
				bool exit=false;
				b=getClick();
				int p, q;
				while(whoWasClicked(a/65536, a%65536, nlist)==-1){
					a=getClick();
					if(done.wasClicked(a/65536, a%65536)) {exit=true; break;}
				}
				if(exit) break;
				p=whoWasClicked(a/65536, a%65536, nlist);
				while((whoWasClicked(b/65536, b%65536, nlist)==-1)||(whoWasClicked(b/65536, b%65536, nlist)==whoWasClicked(a/65536, a%65536, nlist))){
					b=getClick();
					if(done.wasClicked(b/65536, b%65536)) {exit=true; break;}
				}
				if(exit) break;
				q=whoWasClicked(b/65536, b%65536, nlist);
				double v;
				v=getInput<double>("Enter voltage value and then click a nearby point: ");
				int j=getClick();
				VoltageSource* tmp= new VoltageSource(p, q, v, nlist, j/65536, j%65536);
				vlist.push_back(tmp);
				a=getClick();
			}
			SHOW_ALL
		}
		if(solve.wasClicked(g/65536, g%65536)){
			
			HIDE_ALL
			DONE_BUTTON
			
			matrix<double> G(nlist.size()+vlist.size()-1, nlist.size()+vlist.size()-1);
			clear(G);
			for(unsigned int p=0; p<rlist.size(); p++){
				int i=rlist[p]->left(), j=rlist[p]->right();
				if(i!=0&&j!=0){
					G(i-1, j-1)+=-1/rlist[p]->res();
					G(j-1, i-1)+=-1/rlist[p]->res();
					G(i-1, i-1)+=1/rlist[p]->res();
					G(j-1, j-1)+=1/rlist[p]->res();
				}
				if(i==0) G(j-1, j-1)+=1/rlist[p]->res();
				if(j==0) G(i-1, i-1)+=1/rlist[p]->res();
			}
			
			for(unsigned int p=0; p<vlist.size(); p++){
				int i=vlist[p]->left(), j=vlist[p]->right();
				if(i!=0&&j!=0){
					G(nlist.size()-1+p, i-1)=G(i-1, nlist.size()-1+p)=-1;
					G(nlist.size()-1+p, j-1)=G(j-1, nlist.size()-1+p)=1;
				}
				if(i==0) G(nlist.size()-1+p, j-1)=G(j-1, nlist.size()-1+p)=1;
				if(j==0) G(nlist.size()-1+p, i-1)=G(i-1, nlist.size()-1+p)=-1;
			}
			
			matrix<double> S(nlist.size()+vlist.size()-1, 1);
			clear(S);
			for(unsigned int p=0; p<clist.size(); p++){
				int i=clist[p]->left(), j=clist[p]->right();
				if(i!=0&&j!=0){
					S(i-1, 0)+=clist[p]->cur();
					S(j-1, 0)-=clist[p]->cur();
				}
				if(i==0) S(j-1, 0)+=-clist[p]->cur();
				if(j==0) S(i-1, 0)+=clist[p]->cur();
			}
			
			for(unsigned int p=0; p<vlist.size(); p++){
				S(nlist.size()-1+p, 0)=vlist[p]->vol();
			}
			
			matrix<double> GI(nlist.size()+vlist.size()-1, nlist.size()+vlist.size()-1);
			clear(GI);
			inverse(G, GI);
			matrix<double> V(nlist.size()+vlist.size()-1, 1);
			clear(V);
			multiply(GI, S, V);
			
			vector<Text*> tlist(nlist.size()+vlist.size()+rlist.size());
			tlist[0]=new Text(nlist[0]->getX(), nlist[0]->getY(), "0 V");
			tlist[0]->setColor(COLOR("red"));
			for (int i=1; i<nlist.size(); i++) {
				Text* p=new Text(nlist[i]->getX(), nlist[i]->getY(), NToS(V(i-1, 0))+" V");
				p->setColor(COLOR("red"));
				tlist[i]=p;
			}
			for (int i=nlist.size(); i<nlist.size()+vlist.size(); i++) {
				Text* p=new Text(vlist[i-nlist.size()]->getX(), vlist[i-nlist.size()]->getY(), NToS(-V(i-1, 0))+" A");
				double a=vlist[i-nlist.size()]->getAngle(nlist);
				p->move(-30*sine(a), 30*cosine(a));
				p->setColor(COLOR("blue"));
				tlist[i]=p;
			}
			for (int i=0; i<rlist.size(); i++) {
				int left=rlist[i]->left(), right=rlist[i]->right();
				double vleft, vright;
				if (left==0) vleft=0;
				else vleft=V(left-1, 0);
				if (right==0) vright=0;
				else vright=V(right-1, 0);
				
				Text* p=new Text(rlist[i]->getX(), rlist[i]->getY(), NToS(abs(vright-vleft)/rlist[i]->res())+" A");
				double a=rlist[i]->getAngle(nlist);
				p->move(-30*sine(a), 30*cosine(a));
				p->setColor(COLOR("blue"));
				p->hide();
				tlist[i+nlist.size()+vlist.size()]=p;
			}
			string noticestr="Click near the centre of any resistor element to see the current through it";
			Text notice(textWidth(noticestr)/2+5, 750, noticestr);
			int l=getClick();
			while (true) {
				if (done.wasClicked(l/65536, l%65536)) {
					for (int i=0; i<nlist.size()+vlist.size()+rlist.size(); i++) {
						delete tlist[i];
					}
					SHOW_ALL
					break;
				}
				int click=whoWasClicked(l/65536, l%65536, rlist);
				if (click!=-1) {
					tlist[nlist.size()+vlist.size()+click]->show();
				}
				l=getClick();
				if (click!=-1) {
					tlist[nlist.size()+vlist.size()+click]->hide();
				}
			}
			
		}
	}
}
