#include<stdio.h>
#include<limits.h>
char direct[200010];
int place[200010];
int time=INT_MAX;	//�Ĥ@���o�͸I�����ɶ�

int main(void)
{
	int i;
	int n,haveans=0;
	
	scanf("%d",&n);
	scanf("%s",direct);
	for(i=0;i<n;i++)
		scanf("%d",&place[i]);
	
	for(i=0;i<n-1;i++)
	{
		if(direct[i]=='R' && direct[i+1]=='L'){	//�u��RL�����Τ~���i��|�o�͸I��
			//�յۧ�X�̵u���ɶ�
			if(time > (place[i+1]-place[i])/2 ){	//�p�G�{�b�o�@�諸�ɶ���time�٤p 
				time=(place[i+1]-place[i])/2;	//��stime 
				haveans=1;
			}
		}
	}
	if(!haveans){
		printf("-1\n");
	}else{
		printf("%d\n",time);
	}
	return 0;
}
