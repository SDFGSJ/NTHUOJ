#include<cstdio>
class Polynomial
{
public:
    Polynomial();
    Polynomial(const int,const int [51]);
    Polynomial add(const Polynomial) const;
    Polynomial subtract(const Polynomial) const;
    Polynomial multiplication(const Polynomial) const;
    void output() const;
private:
    int coefficients[101];
    int greatestPower;
};

int max(int a,int b){
	if(a>b)	return a;
	else return b;
}

Polynomial::Polynomial(){}
Polynomial::Polynomial(const int maxpow,const int ar[51]){
	int i;
	greatestPower=maxpow;
	for(i=0;i<=maxpow;i++){
		coefficients[i]=ar[i];
	}
}
Polynomial Polynomial::add(const Polynomial p) const{
	int i,j,k;
	int c=max(this->greatestPower,p.greatestPower);
	int coef[51];
	
	for(i=0,j=0,k=0 ; i<=greatestPower && j<=p.greatestPower && k<=c ; i++,j++,k++){
		coef[k]=coefficients[i]+p.coefficients[j];
		//printf("%d=%d+%d\n",coef[k] , coefficients[i] , p.coefficients[j]);
	}
	for(;i<=greatestPower && k<=c;i++,k++){
		coef[k]=coefficients[i];
	}
	for(;j<=p.greatestPower;j++,k++){
		coef[k]=p.coefficients[j];
	}
	Polynomial q(c,coef);
	return q;
}
Polynomial Polynomial::subtract(const Polynomial p) const{
	int i,j,k;
	int c=max(greatestPower,p.greatestPower);
	int coef[51];
	
	for(i=0,j=0,k=0 ; i<=greatestPower && j<=p.greatestPower && k<=c ; i++,j++,k++){
		coef[k]=coefficients[i] - p.coefficients[j];
		//printf("%d=%d-%d\n",coef[k] , coefficients[i] , p.coefficients[j]);
	}
	for(;i<=greatestPower && k<=c;i++,k++){
		coef[k] = -coefficients[i];
	}
	for(;j<=p.greatestPower;j++,k++){
		coef[k] = -p.coefficients[j];
	}
	Polynomial q(c,coef);
	return q;
}
Polynomial Polynomial::multiplication(const Polynomial p) const{
	int i,j,k;
	int c = greatestPower + p.greatestPower;
	int coef[101];
	for(i=0;i<101;i++)	coef[i]=0;
	
	for(i=0;i<=greatestPower;i++){
		for(j=0;j<=p.greatestPower;j++){
			coef[i+j] += coefficients[i] * p.coefficients[j];
			//printf("%d=%d*%d\n",coef[i+j] , coefficients[i] , p.coefficients[j]);
		}
	}
	
	Polynomial q(c,coef);
	return q;
}
void Polynomial::output() const{
	int i;
	printf("%d",coefficients[greatestPower]);
	for(i=greatestPower-1;i>=0;i--){
		printf(" %d",coefficients[i]);
	}
}

