#include<stdio.h>
#include<dlfcn.h>


int (*set_value)(struct array* a, unsigned long long int i, int v);

int main(){
	void* dyn_lib=dlopen("./libarray.so", RTLD_LAZY);
	//dlerror
	if(dyn_lib==0){
		printf("DYNAMIC LIBRARY ERROR: %s\n", dlerror());
		return -1;
	}
	struct array* ar;
	int n;
	printf("введите количество элементов массива.\n");
	struct array* (*create)(unsigned long long int l) = dlsym(dyn_lib, "create");
	scanf("%d", &n);
	ar=create(n);
	unsigned long long int (*size)()=dlsym(dyn_lib, "size");
	int (*set_value)(struct array* a, unsigned long long int i, int v) = dlsym(dyn_lib, "set_value");
	printf("введите %d элементов массива.\n", n);
	for(int i=0; i<size(ar); ++i){ 
		scanf("%d", &n);
		set_value(ar, i, n);
	}
	int (*get_value)(struct array* a, unsigned long long int i) = dlsym(dyn_lib, "get_value");
	for(int i=0; i<size(ar); ++i) 
		printf("ar[%d] = %d\n", i, get_value(ar, i) );
	void (*destroy)(struct array* ar) = dlsym(dyn_lib, "destroy"); 
	destroy(ar);
	dlclose(dyn_lib);
	return 0;
}
