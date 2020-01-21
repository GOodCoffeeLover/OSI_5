#include<stdio.h>
#include"array.h"

int main(){
	struct array* ar;
	int n;
	printf("введите количество элементов массива.\n");
	//cin>>n;
	scanf("%d", &n);
	ar=create(n);
	printf("введите %d элементов массива.\n", n);
	for(int i=0; i<size(ar); ++i){ 
		scanf("%d", &n);
		set_value(ar, i, n);
	}
	for(int i=0; i<size(ar); ++i) 
		printf("ar[%d] = %d\n", i, get_value(ar, i) );
	destroy(ar);
	return 0;
}
