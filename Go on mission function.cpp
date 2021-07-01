#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
class BigInt
{
private:
    constexpr static int N = 150;
    constexpr static int WIDTH = 8, BASE = 100000000;
    bool sign;	//true�N��+,false�N��- 
    int bigInt[N];	//�C�@��̭�����8��ơA�̦h150��
public:
    // constructor
    BigInt();
    BigInt(char*);
    BigInt(const BigInt&);
    
    // copy assignment operator
    BigInt &operator = (const BigInt&);
    
    // comparison operator
    bool operator < (BigInt);
    bool operator > (BigInt);
    bool operator == (BigInt);
    bool operator >= (BigInt);
    bool operator <= (BigInt);
    
    // arithmetic operator
    BigInt operator + (BigInt);
    BigInt operator - (BigInt);
    
    // insertion & extraction operator
    friend istream& operator >> (istream&, BigInt&);
    friend ostream& operator << (ostream&, BigInt&);
};
// constructor
BigInt::BigInt():sign(true){
	int i;
	for(i=0;i<N;i++){
		bigInt[i]=0;
	}
}
BigInt::BigInt(char* str):sign(true){
	int i,j;
	for(i=0;i<N;i++){
		bigInt[i]=0;
	}
	
	int len=strlen(str);
	int bigint_idx=0;
	for(i=len-1;i>7;i-=8){	//���q����p����ơB�C8�ӼƦr�}�l�B�z
		int n=0;
		for(j=i-7;j<=i;j++){
			n=n*10+str[j]-'0';
		}
		bigInt[bigint_idx++]=n;
	}
	
	int n=0;	//�A�B�z�ѤU����8�쪺�Ʀr
	for(j=0;j<=i;j++){
		n=n*10+str[j]-'0';
	}
	bigInt[bigint_idx]=n;
}
BigInt::BigInt(const BigInt& bi){
	*this=bi;
}
// copy assignment operator
BigInt& BigInt::operator = (const BigInt& bi){
	if(this == &bi){	//�p�G�O�P�@�Ӫ���N����return
		return *this;
	}
	
	int i;
	sign=bi.sign;
	for(i=0;i<N;i++){
		bigInt[i]=bi.bigInt[i];
	}
	return *this;
}
// comparison operator
bool BigInt::operator < (BigInt right){	//this < right(?)
	int i;
	if(sign==true && right.sign==false){	//+ < -
		return false;
	}else if(sign==false && right.sign==true){	//- < +
		return true;
	}else if(sign==true && right.sign==true){	//+ +
		for(i=N-1;i>=0;i--){	//�q�̰���ƶ}�l��
			if(bigInt[i] > right.bigInt[i]){	//this > right
				return false;
			}else if(bigInt[i] < right.bigInt[i]){	//this < right
				return true;
			}
		}
	}else if(sign==false && right.sign==false){	//- -
		for(i=N-1;i>=0;i--){	//�q�̰���ƶ}�l��
			if(bigInt[i] > right.bigInt[i]){	//�`�N�t��:this < right
				return true;
			}else if(bigInt[i] < right.bigInt[i]){	//�`�N�t��:this > right
				return false;
			}
		}
	}
	
	//�����۵�
	return false;
}
bool BigInt::operator > (BigInt right){	//this > right(?)
	int i;
	if(sign==true && right.sign==false){	//+ > -
		return true;
	}else if(sign==false && right.sign==true){	//- > +
		return false;
	}else if(sign==true && right.sign==true){	//+ +
		for(i=N-1;i>=0;i--){	//�q�̰���ƶ}�l��
			if(bigInt[i] > right.bigInt[i]){	//this > right
				return true;
			}else if(bigInt[i] < right.bigInt[i]){	//this < right
				return false;
			}
		}
	}else if(sign==false && right.sign==false){	//- -
		for(i=N-1;i>=0;i--){	//�q�̰���ƶ}�l��
			if(bigInt[i] > right.bigInt[i]){	//�`�N�t��:this < right
				return false;
			}else if(bigInt[i] < right.bigInt[i]){	//�`�N�t��:this > right
				return true;
			}
		}
	}
	
	//�����۵�
	return false;
}
bool BigInt::operator == (BigInt right){
	int i;
	if(sign!=right.sign){	//�Ÿ����@�ˡA���藍�@��
		return false;
	}
	for(i=N-1;i>=0;i--){
		if(bigInt[i]!=right.bigInt[i]){
			return false;
		}
	}
	return true;
}
bool BigInt::operator >= (BigInt right){
	if(*this > right || *this == right){
		return true;
	}else{
		return false;
	}
}
bool BigInt::operator <= (BigInt right){
	if(*this < right || *this == right){
		return true;
	}else{
		return false;
	}
}
// arithmetic operator
BigInt BigInt::operator + (BigInt right){
	int i;
	BigInt ans;	//���إX�@��bigint
	for(i=0;i<N;i++){	//�q����p����ƶ}�l+
		ans.bigInt[i] = bigInt[i] + right.bigInt[i];
		if(ans.bigInt[i] >= BASE){	//�i��
			ans.bigInt[i]-=BASE;
			bigInt[i+1]+=1;	//����g��ans.bigInt[i+1]+=1�A�]���U�@��j��|�ﱼ�o��1
		}
	}
	return ans;
}
BigInt BigInt::operator - (BigInt right){	//this - right(right>=0)
	int i;
	BigInt ans;
	if(sign==true){	//this > 0
		if(*this==right){
			ans.sign=true;
			for(i=0;i<N;i++){
				ans.bigInt[i]=0;
			}
		}else if(*this > right){
			ans.sign=true;
			for(i=0;i<N;i++){
				if(bigInt[i] > right.bigInt[i]){
					ans.bigInt[i] = bigInt[i] - right.bigInt[i];
				}else if(bigInt[i] < right.bigInt[i]){
					bigInt[i+1]-=1;
					ans.bigInt[i] = BASE + bigInt[i] - right.bigInt[i];
				}else{
					ans.bigInt[i]=0;
				}
			}
		}else if(*this < right){	//�ܦ�right - this
			ans.sign=false;
			for(i=0;i<N;i++){
				if(bigInt[i] > right.bigInt[i]){
					right.bigInt[i+1]-=1;
					ans.bigInt[i] = BASE + right.bigInt[i] - bigInt[i];
				}else if(bigInt[i] < right.bigInt[i]){
					ans.bigInt[i] = right.bigInt[i] - bigInt[i];
				}else{
					ans.bigInt[i]=0;
				}
			}
		}
	}else{	//-a-b=-(a+b)
		//�`�N�o��檺���ǡA�]��+���ɭԷ|�h�I�sdefault constructor�A�q�Өϱosign�ܬ�true�N�|WA
		ans = *this + right;
		ans.sign = false;
	}
	return ans;
}
// insertion & extraction operator
istream& operator >> (istream& input,BigInt& num){
	char str[1205];
	cin>>str;
	num=BigInt(str);	//��copy constructor
	return input;
}
ostream& operator << (ostream& output,BigInt& num){
	int i;
	if(num.sign==false){
		cout<<"-";
	}
	bool start=false;
	bool first=true;
	for(i=149;i>=0;i--){
		if(num.bigInt[i]!=0){	//�J��Ĥ@�ӫD0���Ʀr�H��N�i�H�}�l�L�F
			start=true;
		}
		if(start){
			if(first){	//�J��Ĥ@�ӫD0���Ʀr�i�H�����L�X�ӡA���κ�setwidth,setfill
				cout<<num.bigInt[i];
				first=false;
			}else{	//�]���ѤU���Ʀr���i�ण��8��ơA�ҥH�nsetwidth,setfill
				cout<<setw(8)<<setfill('0')<<num.bigInt[i];
			}
		}
	}
	
	//�p�GbigInt�}�C�������O0�n�B�~�B�z
	if(!start){
		cout<<"0";
	}
	
	return output;
}

void solution(BigInt &tanjiro, BigInt &zenitsu, BigInt &inosuke, int n){
	int i;
	for(i=0;i<n;i++){
		BigInt mission;
		cin>>mission;
		if(inosuke>=tanjiro && inosuke>=zenitsu){
			inosuke = inosuke - mission;
		}else if(tanjiro>=zenitsu && tanjiro>=inosuke){
			tanjiro = tanjiro - mission;
		}else if(zenitsu>=tanjiro && zenitsu>=inosuke){
			zenitsu = zenitsu - mission;
		}
	}
}
