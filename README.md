# generic_arrlist
A C generic arraylist.
Supports only C23!!

The implementation is roughly based on https://github.com/nothings/stb stb_ds.h  dynamic array.


# USAGE

```c
#include <assert.h>
#include <stdio.h>
#define TYPE_ int
#define IMPL_ARRAYLIST_
#include "generic_arr.stb_ds.h"
#define TYPE_ char
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
	
	auto str = arrlist_init_char();
	
	arrlist_put_char(&str, 'H');
	arrlist_put_char(&str, 'e');
	arrlist_put_char(&str, 'l');
	arrlist_put_char(&str, 'l');
	arrlist_put_char(&str, 'o');
	arrlist_put_char(&str, ' ');
	arrlist_put_char(&str, 'W');
	arrlist_put_char(&str, 'o');
	arrlist_put_char(&str, 'r');
	arrlist_put_char(&str, 'l');
	arrlist_put_char(&str, 'd');
	arrlist_put_char(&str, '\0');
	
	printf("%s\n", str.data);
}
```
