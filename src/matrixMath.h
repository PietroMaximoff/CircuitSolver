//Siddhant Ranade 130260002
//Unmesh Phadke 130260006

#include<simplecpp>

template<class T>
void clear(matrix<T>& A){
	for(int i=0; i<A.rows(); i++) for(int j=0; j<A.columns(); j++) A(i,j)=0;
}

template<class T>
bool multiply(matrix<T> first, matrix<T> second, matrix<T>& result){
	if(first.columns()!=second.rows()) return false;
	
	for(int i=0; i<first.rows(); i++){
		for(int j=0; j<second.columns(); j++){
			T tmp=0;
			for(int k=0; k<first.columns(); k++)tmp+= first(i,k)* second(k,j);
			result(i,j)=tmp;
		}
	}
	return true;
}

template<class T>
void cofactor(int i, int j, matrix<T> A, matrix<T> &ans){
	int a=0, ax=0, b=0, bx=0;
	for(a=0,ax=0; a<A.rows(); a++){
		if(a==i){}
		else{
			for(b=0,bx=0; b<A.columns(); b++){
				if(b==j){}
				else{
					ans(ax, bx)=A(a,b);
					bx++;
				}
			}
			ax++;
		}
	}
	for(int c=0; c<A.columns()-1; c++) ans(0,c)*=pow(-1, i+j);
}

template<class T>
T det(matrix<T>A){
	if(A.rows()==1) return A(0,0);
	T tmp=0;
	for(int j=0; j<A.columns(); j++){
		matrix<T> temp(A.rows()-1,A.columns()-1);
		cofactor(0,j, A, temp);
		tmp+=A(0,j)*det(temp);
	}
	return tmp;
}

template<class T>
bool inverse(matrix<T> A, matrix<T> &ans){
	if(A.rows()!=A.columns()) return false;
	T deta=det(A);
	if(deta==0.0) return false;
	for(int i=0; i<A.rows(); i++){
		for(int j=0; j<A.columns(); j++){
			matrix<T> temp(A.rows()-1,A.columns()-1);
			cofactor(i,j, A, temp);
			ans(j,i)=det(temp)/deta;
		}
	}
	
	return true;
}