#include<stdio.h>
#include"function.h"
unsigned random_seed=7122;
unsigned Random(){
	return random_seed=random_seed*0xdefaced+1;
}
int main(){
	int n,m,k,_;	//_:number of tests
	scanf("%d%d%d%d%u",&_,&n,&m,&k,&random_seed);
	while(_--){
		unsigned ***arr=new_3d_array(n,m,k);
		int i,j,l;
		for(i=0;i<n;++i){	//���}�C�̶�� 
			for(j=0;j<m;++j){
				for(l=0;l<k;++l){
					arr[i][j][l]=Random();
				}
			}
		}
		for(i=0;i<5;++i){	//�L�X���ӼƦr 
			unsigned a,b,c;
			a=Random()%n;
			b=Random()%m;
			c=Random()%k;
			if(i)putchar(' ');	//i�D0�ɴN�L�ť� 
			printf("%u",arr[a][b][c]);
		}
		puts("");
		delete_3d_array(arr);
	}
	return 0;
}

