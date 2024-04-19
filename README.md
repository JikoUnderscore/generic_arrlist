# generic_arrlist
A C generic arraylist.
Supports only C23!!

The implementation is roughly based on https://github.com/nothings/stb stb_ds.h  dynamic array.


# USAGE

To define the genereic use #define TYPE_ <your_type_here>    
the type of the array is `ArrayList_<your_type_here>`    

```c
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#define TYPE_ int
#define IMPL_ARRAYLIST_
#include "generic_arr.stb_ds.h"
#define TYPE_ char
#define IMPL_ARRAYLIST_
#include "generic_arr.stb_ds.h"

void arrlist_push_cstring(ArrayList_char arrlist[static 1], char const* const cstr, size_t const str_len) {
    arrlist_set_capacity_char(arrlist, str_len, realloc);
    char const* str_ptr = cstr;
    for (char character = *str_ptr; character != '\0'; character = *++str_ptr) {
        arrlist->data[arrlist->len++] = character;
    }
}

int main() {
    ArrayList_int arr = arrlist_init_int(malloc);
    for (char i = {}; i < 26; ++i) {
        arrlist_put_int(&arr, 'a' + i, realloc);
    }
    arrlist_del_int(&arr, 2); // removes 'c'
    assert(arr.len == 25);
    assert(arr.data[0] == 'a');
    assert(arr.data[1] == 'b');
    assert(arr.data[2] == 'd');
    assert(arr.data[3] == 'e');


    arrlist_deinit_int(&arr); // used `free` from `stdlib.h`

    ArrayList_char str = arrlist_init_empty_char(); // or {};
    arrlist_push_cstring(&str, "hello bitch", 11);
    arrlist_put_char(&str, ' ', realloc);
    arrlist_put_char(&str, 'H', realloc);
    arrlist_put_char(&str, 'e', realloc);
    arrlist_put_char(&str, 'l', realloc);
    arrlist_put_char(&str, 'l', realloc);
    arrlist_put_char(&str, 'o', realloc);
    arrlist_put_char(&str, ' ', realloc);
    arrlist_put_char(&str, 'W', realloc);
    arrlist_put_char(&str, 'o', realloc);
    arrlist_put_char(&str, 'r', realloc);
    arrlist_put_char(&str, 'l', realloc);
    arrlist_put_char(&str, 'd', realloc);
    arrlist_put_char(&str, '\0', realloc);

    printf("%s\n", str.data);

    arrlist_deinit_unmanaged_char(&str, free);
}

```
