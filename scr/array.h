#pragma once
#define ERROR_VALUE -1
//#define NULL 0

struct array;
struct array* create(unsigned long long int size);
struct array* create_value(unsigned long long int size, int value);
unsigned long long int size(struct array* ar);
void destroy(struct array* ar);
int get_value(struct array* ar, unsigned long long int index);
int set_value(struct array* ar, unsigned long long int index, int value);
