#define ERROR_VALUE -1
#define NULL 0
#include<stdlib.h>

struct array{
	int * _arr;
	unsigned long long int _size;
};

struct array* create(const unsigned long long int size){
	if(size==0){
	//	_size=size;
		return NULL;
	}
	struct array *ar=malloc(sizeof(struct array));
	ar->_arr=malloc(sizeof(int)*size);
	ar->_size=size;
	return ar;
}

struct array* create_value(const unsigned long long int size, int value){
	if(size==0){
		//_size=size;
		return NULL;
	}
	struct array *ar=malloc(sizeof(struct array));
	ar->_arr=malloc(sizeof(int)*size);
	for(int i=0; i<size; ++i)
		ar->_arr[i]=value;
	ar->_size=size;
	return ar;
}

void destroy(struct array* ar){
	free(ar->_arr);
	free(ar);
	return;
}

int get_value(struct array* ar, unsigned long long int index){
	if((ar==0) || (index>=ar->_size) ) return ERROR_VALUE;
	return ar->_arr[index];
}

unsigned long long int size(struct array* ar){
	if(ar==NULL) return 0;
	return ar->_size;
}

int set_value(struct array* ar, unsigned long long int index, int value){
	if((ar==NULL) || (index>=ar->_size) ) return ERROR_VALUE;
	ar->_arr[index]=value;
	
}
