#include"function.h"
int max(int a,int b){
	if(a>b)	return a;
	else	return b;
}
std::ostream &operator<<(std::ostream & os, const Polynomial & p){
	int i;
	os<<p.coefficients[p.greatestPower];
	for(i=p.greatestPower-1;i>=0;i--){
		os<<" "<<p.coefficients[i];
	}
	return os;
}
Polynomial::Polynomial(const int& maxpow, const int ar[51]){
	int i;
	greatestPower=maxpow;
	for(i=0;i<101;i++){
		coefficients[i]=0;
	}
	for(i=0;i<=maxpow;i++){
		coefficients[i]=ar[i];
	}
	
}
Polynomial Polynomial::operator+( const Polynomial & p) const{
	int i,j,k;
	int c=max(this->greatestPower,p.greatestPower);

	Polynomial q;
	q.greatestPower=max(this->greatestPower,p.greatestPower);
	
	for(i=0,j=0,k=0 ; i<=greatestPower && j<=p.greatestPower/* && k<=c */; i++,j++,k++){
		q.coefficients[k]=coefficients[i]+p.coefficients[j];
		//printf("%d=%d+%d\n",coef[k] , coefficients[i] , p.coefficients[j]);
	}
	for(;i<=greatestPower/* && k<=c*/;i++,k++){
		q.coefficients[k]=coefficients[i];
	}
	for(;j<=p.greatestPower;j++,k++){
		q.coefficients[k]=p.coefficients[j];
	}
	
	return q;
}
Polynomial Polynomial::operator-( const Polynomial & p) const{
	int i,j,k;
	int c=max(greatestPower,p.greatestPower);

	Polynomial q;
	q.greatestPower=max(greatestPower,p.greatestPower);
	
	for(i=0,j=0,k=0 ; i<=greatestPower && j<=p.greatestPower/* && k<=c */; i++,j++,k++){
		q.coefficients[k] = coefficients[i] - p.coefficients[j];
		//printf("%d=%d-%d\n",coef[k] , coefficients[i] , p.coefficients[j]);
	}
	for(;i<=greatestPower/* && k<=c*/;i++,k++){
		q.coefficients[k] = coefficients[i];
	}
	for(;j<=p.greatestPower;j++,k++){
		q.coefficients[k] = -p.coefficients[j];
	}
	
	return q;
}
