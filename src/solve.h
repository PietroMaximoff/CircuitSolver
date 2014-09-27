//Siddhant Ranade 130260002
//Unmesh Phadke 130260006

#include<simplecpp>

template<class T>
bool matrixsolve(matrix<T> A, matrix<T> B, matrix<T>& res) {
	for(int h=0;h<B.rows();h++) {
		res(h,0)=B(h,0);
	}
	for(int i=0;i<A.rows();i++){
		if(A(i,i)==0) {
			bool check=false;
			for(int a=i+1;a<A.rows();a++){ 
				if(A(a,i)!=0){
					for(int b=0;b<A.columns();b++){
						A(i,b)+=A(a,b);
					}
					res(i,0)+=res(a,0);
					check=true;
					break;
				}
			}			
			if(check==false){
				return false;
			}
			//cout<<A<<res<<"added"<<endl;			//DEBUG
		}
		double tmp=A(i,i);
		for(int j=0; j<A.columns(); j++){
			A(i,j)=A(i,j)/tmp;
		}
		res(i,0)=res(i,0)/tmp;
		//cout<<A<<res<<"divided"<<endl<<endl;		//DEBUG
		
		for(int k=0;k<A.rows();k++){
			double z=A(k,i);
			for(int l=0;l<A.columns();l++){
				if(k!=i) A(k,l)=A(k,l)-A(i,l)*z;
			}
			if(k!=i) res(k,0)=res(k,0)-res(i,0)*z;
			//cout<<A<<"subtracted "<<k<<endl;		//DEBUG
		}
		//cout<<A<<"subtracted"<<endl;				//DEBUG
	}
	//cout<<A<<endl<<res<<endl;						//DEBUG
	return true;
}