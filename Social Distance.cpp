#include<bits/stdc++.h>
using namespace std;
struct seg{
	int left,right;
	seg(int l,int r):left(l),right(r){}
};
struct cmp{
	bool operator()(const seg& lhs,const seg& rhs) const {
		int l_len=(lhs.right-lhs.left)/2;
		int r_len=(rhs.right-rhs.left)/2;
		if(l_len!=r_len){
			return l_len>r_len;
		}else{
			return lhs.left<rhs.left;
		}
	}
};
int main(){
	int i;
	char cmd;
	int n,m,s,x,d;
	
	set<int> pos;	//���F���X�F�~
	set<seg,cmp> segment;
	vector<int> seat;
	
	cin>>n>>m>>s;
	d=n+1;	//INF
	seat.resize(m+1,1);	//�Nvector���j�p�ܦ�m+1
	
	pos.insert(0);	//wall�]�ninsert�i�h�A���M�b�����Ĥ@�ӤH���ɭ�it++,it--�ɥi��|������wall��idx�A�y��RE
	pos.insert(n+1);
	segment.insert(seg(0,n+1));	//�@�}�l��segment
	
	for(i=0;i<2*m;i++){
		cin>>cmd>>x;
		if(cmd=='i'){
			auto it=segment.begin();	//�]��set������cmp�ƧǡA�ҥH���X���Ĥ@�Ӥ����@�w�Olen�̤j
			int l=it->left,r=it->right;
			int mid=(l+r)/2;	//�M�w�L�n����
			
			//��o��segment�䤤�@��Owall�@��O�H || ����m�O�H�N�n��sdistance
			if(l!=0){
				d=min(mid-l,d);
			}
			if(r!=n+1){
				d=min(r-mid,d);
			}
			
			segment.erase(it);
			segment.insert(seg(l,mid));
			segment.insert(seg(mid,r));
			seat[x]=mid;
			pos.insert(mid);
		}else{
			int mid=seat[x];	//��Xid=x�o�ӤH���b����
			
			auto it=pos.find(mid);	//��pos��L���F�~
			auto left_it=it,right_it=it;
			int left=*(--left_it);
			int right=*(++right_it);
			
			segment.erase(seg(left,mid));
			segment.erase(seg(mid,right));
			segment.insert(seg(left,right));
			seat[x]=-1;
			pos.erase(mid);
		}
	}
	
	if(d>=s){
		cout<<"YES\n";
	}else{
		cout<<"NO\n";
	}
	if(d==n+1){
		cout<<"INF\n";
	}else{
		cout<<d<<"\n";
	}

	return 0;
}
