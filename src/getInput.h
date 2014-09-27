//Siddhant Ranade 130260002
//Unmesh Phadke 130260006

#include<simplecpp>

template <class T>
string NToS(T N){
	stringstream ss;
	ss << N;
	return ss.str();
}

template<class T>
T getInput(string s){
	Text m(textWidth(s)/2+5, 750, s);
	XEvent event;
	stringstream ss;
	Text t(textWidth(s)+5+textWidth(ss.str())/2, 750, ss.str());
	while (true) {
		nextEvent(event);
		if (keyPressEvent(event)) {
			char e=charFromEvent(event);
			if (e==13) break;
			if ((e>='0' && e<='9')||e=='.') ss<<e;
			if (e==8) {
				string a=ss.str();
				a=a.substr(0, a.size()-1);
				ss.str(string());
				ss<<a;
			}
			t.reset(textWidth(s)+5+textWidth(ss.str())/2, 750, ss.str());
		}
	}
	T ans;
	ss>>ans;
	return ans;
}
