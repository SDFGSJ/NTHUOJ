#include<stdio.h>
int main(void){
	/*i,j,w:�j���ܼ�
	n�ӼƦr
	���Lq��
	*/
    int i, j, w, n, q;
    scanf("%d",&n);
    /*arr1:�O�����
	arr2:�O�����X�{����
	arr3:�O�����P�˳̤p�Ȫ���⸹�X 
	*/ 
    int arr1[n], arr2[n], arr3[n];
	
    for(i = 0; i < n; i ++)
        scanf("%d", &arr1[i]);
        
    scanf("%d", &q);
    //���Lq�� 
    for(w = 0; w < q; w ++){
        int a, b, k = 0;//a:�����I,b:�k���I,k:�}�C��index 
        scanf("%d %d", &a, &b);
		//��l�� 
        for(i = 0; i < n; i ++){
        	arr2[i] = 0;
        	arr3[i] = 0;
    	}
    	//����C�ӼƦr�X�{�X���A�ðO����arr2�̭� 
        for(i = a-1; i < b; i ++){
            for(j = a - 1; j < b; j ++){
                if(arr1[i] == arr1[j]){
                    arr2[i] ++;
                }
            }
        }
        //�Narr2���Ĥ@�ӼƦr���w��max 
        int max = arr2[0];
        for(i = 0; i < n; i ++){
            if(arr2[i] > max){
                max = arr2[i];//�p�Garr2���Ʀr��max�٤j�N��smax 
            }
        }
        
        for(i = 0; i < n; i ++){
            if(arr2[i] == max){
                arr3[k] = arr1[i];//�N�֦��ۦP�̤p�Ȫ���⸹�O����arr3�̭� 
                k ++;//k�O�o��s 
            }
        }
        
        int min = arr3[0];//�Narr3���Ĥ@�ӵ�⸹���w��min 
        for(i = 0; i < k; i ++){
            if(arr3[i] < min){
                min = arr3[i];//�p�Garr3����⸹��min�٤p�N��smin 
            }
        }
		printf("%d\n",min);			
    }
    return 0;
}
