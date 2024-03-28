# generic_arrlist
A C generic arraylist.
Supports only C23!!

The implementation is based on https://github.com/nothings/stb stb_ds.h  dynamic array.


# USAGE

`c
#define TYPE_ int
#define IMPL_ARRAYLIST_
#include "generic_arr.stb_ds.h"


int main(){
	auto arr = arrlist_init_int();
	for (char i = {}; i < 26; ++i) {
		arrlist_put_int(&arr, 'a' + i);
	}
	arrlist_del_int(&arr, 2); // removes 'c'
	assert(arr.len == 25);
	assert(arr.data[0] == 'a');
	assert(arr.data[1] == 'b');
	assert(arr.data[2] == 'd');
	assert(arr.data[3] == 'e');
	arrlist_void_deinit_int(&arr);
}
`
