/*
!!! C23 ONLY !!!


How to use
To define the genereic use #define TYPE_ <your_type_here>
the type of the array is `ArrayList_<your_type_here>`

Example:
// array_int.c
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
*/
#include <stddef.h>


#ifdef UNIT_TESTS_
#define TYPE_ int
#endif // UNIT_TESTS_


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#if __STDC_VERSION__ < 202311L
#error "Recommended C23"
#endif


#if !defined(TYPE_)
#error "Define TYPE_ macro to be the type of the array"
#endif // TYPE_


#define struct_arr_2(T) ArrayList_##T
#define struct_arr(T)                                                                                                                                                              \
    typedef struct {                                                                                                                                                               \
        T* data;                                                                                                                                                                   \
        size_t len;                                                                                                                                                                \
        size_t capacity;                                                                                                                                                           \
    } struct_arr_2(T)


#define name_of_arraylist2(T) ArrayList_##T
#define name_of_arraylist(T) name_of_arraylist2(T)

#define arrlist_init29(T) arrlist_init_##T
#define arrlist_init(T) arrlist_init29(T)
#define arrlist_init12(T) arrlist_init_empty_##T
#define arrlist_init1(T) arrlist_init12(T)
#define arrlist_init22(T) arrlist_init2_##T
#define arrlist_init2(T) arrlist_init22(T)
#define arrlist_deinit2(T) arrlist_deinit_##T
#define arrlist_deinit(T) arrlist_deinit2(T)
#define arrlist_deinit_unmanaged2(T) arrlist_deinit_unmanaged_##T
#define arrlist_deinit_unmanaged(T) arrlist_deinit_unmanaged2(T)
#define arrlist_void_deinit2(T) arrlist_void_deinit_##T
#define arrlist_void_deinit(T) arrlist_void_deinit2(T)
#define arrlist_pop2(T) arrlist_pop_##T
#define arrlist_pop(T) arrlist_pop2(T)
#define arrlist_put2(T) arrlist_put_##T
#define arrlist_put(T) arrlist_put2(T)
#define arrlist_put_ptr2(T) arrlist_put_ptr_##T
#define arrlist_put_ptr(T) arrlist_put_ptr2(T)
#define arrlist_meybe_grow2(T) arrlist_meybe_grow_##T
#define arrlist_meybe_grow(T) arrlist_meybe_grow2(T)
#define arrlist_grow2(T) arrlist_grow_##T
#define arrlist_grow(T) arrlist_grow2(T)
#define arrlist_growff2(T) arrlist_growff_##T
#define arrlist_growff(T) arrlist_growff2(T)
#define arrlist_insert2(T) arrlist_insert_##T
#define arrlist_insert(T) arrlist_insert2(T)
#define arrlist_insert_n2(T) arrlist_insert_n_##T
#define arrlist_insert_n(T) arrlist_insert_n2(T)
#define arrlist_add_index_n2(T) arrlist_add_index_n_##T
#define arrlist_add_index_n(T) arrlist_add_index_n2(T)
#define arrlist_add_ptr2(T) arrlist_add_ptr_##T
#define arrlist_add_ptr(T) arrlist_add_ptr2(T)
#define arrlist_del_n2(T) arrlist_del_n_##T
#define arrlist_del_n(T) arrlist_del_n2(T)
#define arrlist_del2(T) arrlist_del_##T
#define arrlist_del(T) arrlist_del2(T)
#define arrlist_del_ret2(T) arrlist_del_ret_##T
#define arrlist_del_ret(T) arrlist_del_ret2(T)
#define arrlist_del_swap2(T) arrlist_del_swap_##T
#define arrlist_del_swap(T) arrlist_del_swap2(T)
#define arrlist_del_swap_ret2(T) arrlist_del_swap_ret_##T
#define arrlist_del_swap_ret(T) arrlist_del_swap_ret2(T)
#define arrlist_set_capacity2(T) arrlist_set_capacity_##T
#define arrlist_set_capacity(T) arrlist_set_capacity2(T)
#define arrlist_set_len2(T) arrlist_set_len_##T
#define arrlist_set_len(T) arrlist_set_len2(T)

struct_arr(TYPE_);

// name_of_type1(TYPE_) typedef ArrayListOfT;
#define ArrayListOfT name_of_arraylist(TYPE_)


#undef struct_arr_2
#undef struct_arr


ArrayListOfT arrlist_init(TYPE_)(void* (*custom_malloc)(size_t));
ArrayListOfT arrlist_init1(TYPE_)(void);
ArrayListOfT arrlist_init2(TYPE_)(size_t capacity, void* (*custom_malloc)(size_t));
void arrlist_deinit(TYPE_)(ArrayListOfT arrlist[static const restrict 1]);
void arrlist_deinit_unmanaged(TYPE_)(ArrayListOfT arrlist[static const restrict 1], void (*custom_free)(void*));
void arrlist_void_deinit(TYPE_)(void* arrlist);
[[nodiscard]] TYPE_ arrlist_pop(TYPE_)(ArrayListOfT arrlist[static const restrict 1]);
void arrlist_meybe_grow(TYPE_)(ArrayListOfT arrlist[static const restrict 1], size_t n, void* (*custom_realloc)(void* _Block, size_t _Size));
void arrlist_put(TYPE_)(ArrayListOfT arrlist[static const restrict 1], TYPE_ value, void* (*custom_realloc)(void* _Block, size_t _Size));
void arrlist_put_ptr(TYPE_)(ArrayListOfT arrlist[static const restrict 1], TYPE_ const* const value, void* (*custom_realloc)(void* _Block, size_t _Size));
void arrlist_insert(TYPE_)(ArrayListOfT arrlist[static const restrict 1], size_t index, TYPE_ value, void* (*custom_realloc)(void* _Block, size_t _Size));
void arrlist_insert_n(TYPE_)(ArrayListOfT arrlist[static const restrict 1], size_t p, size_t n, void* (*custom_realloc)(void* _Block, size_t _Size));
size_t arrlist_add_index_n(TYPE_)(ArrayListOfT arrlist[static const restrict 1], size_t n, void* (*custom_realloc)(void* _Block, size_t _Size));
void arrlist_del_n(TYPE_)(ArrayListOfT arrlist[static const restrict 1], size_t index, size_t n);
void arrlist_del(TYPE_)(ArrayListOfT arrlist[static const restrict 1], size_t index);
[[nodiscard]] TYPE_ arrlist_del_ret(TYPE_)(ArrayListOfT arrlist[static const restrict 1], size_t index);
TYPE_* arrlist_add_ptr(TYPE_)(ArrayListOfT arrlist[static const restrict 1], size_t n, void* (*custom_realloc)(void* _Block, size_t _Size));
void arrlist_del_swap(TYPE_)(ArrayListOfT arrlist[static const restrict 1], size_t index);
[[nodiscard]] TYPE_ arrlist_del_swap_ret(TYPE_)(ArrayListOfT arrlist[static const restrict 1], size_t index);
void arrlist_grow(TYPE_)(ArrayListOfT arrlist[static const restrict 1], size_t n, size_t cap, void* (*custom_realloc)(void* _Block, size_t _Size));
void arrlist_set_capacity(TYPE_)(ArrayListOfT arrlist[static const restrict 1], size_t cap, void* (*custom_realloc)(void* _Block, size_t _Size));
void arrlist_set_len(TYPE_)(ArrayListOfT arrlist[static const restrict 1], size_t n, void* (*custom_realloc)(void* _Block, size_t _Size));


/// =======================                 =======================
/// ======================= IMPL_ARRAYLIST_ =======================
/// =======================                 =======================
#ifdef IMPL_ARRAYLIST_

TYPE_* arrlist_growff(TYPE_)(ArrayListOfT arrlist[static const restrict 1], size_t elem_size, size_t add_len, size_t min_cap, void* (*custom_realloc)(void* _Block, size_t _Size));


#include <string.h>


ArrayListOfT arrlist_init(TYPE_)(void* (*custom_malloc)(size_t)) {
    size_t const capacity = 8;
    ArrayListOfT array = {
        .data = (TYPE_*)custom_malloc(sizeof(TYPE_) * (capacity)),
        .len = 0,
        .capacity = capacity,
    };
    return array;
}


ArrayListOfT arrlist_init1(TYPE_)(void) {
    ArrayListOfT array = {};
    return array;
}

ArrayListOfT arrlist_init2(TYPE_)(size_t capacity, void* (*custom_malloc)(size_t)) {
    ArrayListOfT array = {
        .data = (TYPE_*)custom_malloc(sizeof(TYPE_) * (capacity)),
        .len = 0,
        .capacity = capacity,
    };
    return array;
}


void arrlist_deinit(TYPE_)(ArrayListOfT arrlist[static const restrict 1]) {
#include <stdlib.h>
    free(arrlist->data);
    arrlist->data = nullptr;
    arrlist->len = 0;
    arrlist->capacity = 0;
}

void arrlist_deinit_unmanaged(TYPE_)(ArrayListOfT arrlist[static const restrict 1], void (*custom_free)(void*)) {
    custom_free(arrlist->data);
    arrlist->data = nullptr;
    arrlist->len = 0;
    arrlist->capacity = 0;
}


void arrlist_void_deinit(TYPE_)(void* arrlist) {
#include <stdlib.h>
    ArrayListOfT* arli = (ArrayListOfT*)arrlist;
    free(arli->data);
    arli->data = nullptr;
    arli->len = 0;
    arli->capacity = 0;
}

/// #define stbds_arrpop(a)        (stbds_header(a)->length--, (a)[stbds_header(a)->length])
/// T arrpop(T* a)
///   Removes the final element of the array and returns it.
[[nodiscard]] TYPE_ arrlist_pop(TYPE_)(ArrayListOfT arrlist[static const restrict 1]) {
    arrlist->len--;
    return arrlist->data[arrlist->len];
}


/// #define stbds_arrmaybegrow(a, n) ((!(a) || stbds_header(a)->length + (n) > stbds_header(a)->capacity) ? (stbds_arrgrow(a, n, 0), 0) : 0)
void arrlist_meybe_grow(TYPE_)(ArrayListOfT arrlist[static const restrict 1], size_t n, void* (*custom_realloc)(void* _Block, size_t _Size)) {
    if (!arrlist->data || arrlist->len + n > arrlist->capacity) {
        arrlist_grow(TYPE_)(arrlist, n, 0, custom_realloc);
    }
}

///  #define stbds_arrput(a,v)      (stbds_arrmaybegrow(a,1), (a)[stbds_header(a)->length++] = (v))
/// (T) void arrput(T* a, T b);
///   Appends the item b to the end of array a. Returns b.
void arrlist_put(TYPE_)(ArrayListOfT arrlist[static const restrict 1], TYPE_ value, void* (*custom_realloc)(void* _Block, size_t _Size)) {
    arrlist_meybe_grow(TYPE_)(arrlist, 1, custom_realloc);
    arrlist->data[arrlist->len++] = value;
}


/// #define stbds_arrput(a,v)      (stbds_arrmaybegrow(a,1), (a)[stbds_header(a)->length++] = (v))
/// (T) void arrput(T* a, T b);
///   Appends the item b to the end of array a. Returns b.
void arrlist_put_ptr(TYPE_)(ArrayListOfT arrlist[static const restrict 1], TYPE_ const* const value, void* (*custom_realloc)(void* _Block, size_t _Size)) {
    arrlist_meybe_grow(TYPE_)(arrlist, 1, custom_realloc);
    arrlist->data[arrlist->len++] = *value;
}


///  #define stbds_arrins(a, i, v) (stbds_arrinsn((a), (i), 1), (a)[i] = (v))
/// (T) void arrins(T* a, int p, T b);
///   Inserts the item b into the middle of array a, into a[p],
///   moving the rest of the array over. Returns b.
void arrlist_insert(TYPE_)(ArrayListOfT arrlist[static const restrict 1], size_t index, TYPE_ value, void* (*custom_realloc)(void* _Block, size_t _Size)) {
    arrlist_insert_n(TYPE_)(arrlist, index, 1, custom_realloc);
    arrlist->data[index] = value;
}


/// #define stbds_arraddnindex(a, n) (stbds_arrmaybegrow(a, n), (n) ? (stbds_header(a)->length += (n), stbds_header(a)->length - (n)) : stbds_arrlen(a))
/// size_t arraddnindex(T* a, int n)
///   Appends n uninitialized items onto array at the end.
///   Returns the index of the first uninitialized item added.
size_t arrlist_add_index_n(TYPE_)(ArrayListOfT arrlist[static const restrict 1], size_t n, void* (*custom_realloc)(void* _Block, size_t _Size)) {
    arrlist_meybe_grow(TYPE_)(arrlist, n, custom_realloc);
    if (n) {
        arrlist->len += n;
        return arrlist->len - n;
    }
    return arrlist->len;
}


/// #define stbds_arrinsn(a, i, n) (stbds_arraddn((a), (n)), memmove(&(a)[(i) + (n)], &(a)[i], sizeof *(a) * (stbds_header(a)->length - (n) - (i))))
/// void arrinsn(T* a, int p, int n);
///   Inserts n uninitialized items into array a starting at a[p],
///   moving the rest of the array over.
void arrlist_insert_n(TYPE_)(ArrayListOfT arrlist[static const restrict 1], size_t p, size_t n, void* (*custom_realloc)(void* _Block, size_t _Size)) {
    arrlist_add_index_n(TYPE_)(arrlist, n, custom_realloc);
    memmove(&arrlist->data[p + n], &arrlist->data[p], sizeof(TYPE_) * (arrlist->len - n - p));
}


/// #define stbds_arrdeln(a,i,n)   (memmove(&(a)[i], &(a)[(i)+(n)], sizeof *(a) * (stbds_header(a)->length-(n)-(i))), stbds_header(a)->length -= (n))
/// void arrdeln(T* a, int p, int n);
///     Deletes n elements starting at a[p], moving the rest of the array over.
void arrlist_del_n(TYPE_)(ArrayListOfT arrlist[static const restrict 1], size_t index, size_t n) {
    memmove(&arrlist->data[index], &arrlist->data[index + n], sizeof(TYPE_) * (arrlist->len - n - index));
    arrlist->len -= n;
}


// #define stbds_arrdel(a, i) stbds_arrdeln(a, i, 1)
/// void arrdel(T* a, int p);
///   Deletes the element at a[p], moving the rest of the array over.
void arrlist_del(TYPE_)(ArrayListOfT arrlist[static const restrict 1], size_t index) {
    arrlist_del_n(TYPE_)(arrlist, index, 1);
}


///   Deletes the element at a[p], moving the rest of the array over.
///   Return the element.
[[nodiscard]] TYPE_ arrlist_del_ret(TYPE_)(ArrayListOfT arrlist[static const restrict 1], size_t index) {
    TYPE_ moved_element = arrlist->data[index];
    arrlist_del_n(TYPE_)(arrlist, index, 1);
    return moved_element;
}


/// #define stbds_arraddnptr(a, n) (stbds_arrmaybegrow(a, n), (n) ? (stbds_header(a)->length += (n), &(a)[stbds_header(a)->length - (n)]) : (a))
/// T* arraddnptr(T* a, int n)
///   Appends n uninitialized items onto array at the end.
///   Returns a pointer to the first uninitialized item added.
TYPE_* arrlist_add_ptr(TYPE_)(ArrayListOfT arrlist[static const restrict 1], size_t n, void* (*custom_realloc)(void* _Block, size_t _Size)) {
    arrlist_meybe_grow(TYPE_)(arrlist, n, custom_realloc);
    if (n) {
        arrlist->len += n;
        return &arrlist->data[arrlist->len - n];
    }
    return arrlist->data;
}


/// #define stbds_arrdelswap(a,i)  ((a)[i] = stbds_arrlast(a), stbds_header(a)->length -= 1)
/// void arrdelswap(T* a, int p);
///   Deletes the element at a[p], replacing it with the element from
///   the end of the array. O(1) performance.
void arrlist_del_swap(TYPE_)(ArrayListOfT arrlist[static const restrict 1], size_t index) {
    arrlist->data[index] = arrlist->data[arrlist->len - 1];
    arrlist->len -= 1;
}

///   Deletes the element at a[p], replacing it with the element from
///   the end of the array. O(1) performance.
[[nodiscard]] TYPE_ arrlist_del_swap_ret(TYPE_)(ArrayListOfT arrlist[static const restrict 1], size_t index) {
    TYPE_ moved_element = arrlist->data[index];
    arrlist->data[index] = arrlist->data[arrlist->len - 1];
    arrlist->len -= 1;
    return moved_element;
}


TYPE_* arrlist_growff(TYPE_)(ArrayListOfT arrlist[static const restrict 1], size_t elem_size, size_t add_len, size_t min_cap, void* (*custom_realloc)(void* _Block, size_t _Size)) {
    size_t min_len = arrlist->len + add_len;

    // compute the minimum capacity needed
    if (min_len > min_cap) {
        min_cap = min_len;
    }

    if (min_cap <= arrlist->capacity) {
        return arrlist->data;
    }

    // increase needed capacity to guarantee O(1) amortized
    if (min_cap < 2 * arrlist->capacity) {
        min_cap = 2 * arrlist->capacity;
    }
    else if (min_cap < 4) {
        min_cap = 4;
    }

    TYPE_* b_data = custom_realloc(arrlist->data, elem_size * min_cap);
    if (arrlist->data == nullptr) {
        arrlist->len = 0;
    }
    arrlist->capacity = min_cap;

    return b_data;
}


/// #define stbds_arrgrow(a,b,c)   ((a) = stbds_arrgrowf_wrapper((a), sizeof *(a), (b), (c)))
void arrlist_grow(TYPE_)(ArrayListOfT arrlist[static const restrict 1], size_t n, size_t cap, void* (*custom_realloc)(void* _Block, size_t _Size)) {
    arrlist->data = arrlist_growff(TYPE_)(arrlist, sizeof(TYPE_), n, cap, custom_realloc);
}

/// #define stbds_arrsetcap(a,cap)   (stbds_arrgrow(a,0,cap))
/// (size_t) void arrsetcap(T* a, int cap);
///   Sets the length of allocated storage to at least `cap`. It will not
///   change the length of the array.
void arrlist_set_capacity(TYPE_)(ArrayListOfT arrlist[static const restrict 1], size_t cap, void* (*custom_realloc)(void* _Block, size_t _Size)) {
    arrlist_grow(TYPE_)(arrlist, 0, cap, custom_realloc);
}


/// #define stbds_arrsetlen(a,len)   ((stbds_arrcap(a) < (size_t) (len) ? \
///     stbds_arrsetcap((a),(size_t)(len)) ,0 : 0), (a) ? stbds_header(a)->length = (size_t) (len) : 0)
/// void arrsetlen(T* a, int len);
///   Changes the length of the array to n. Allocates uninitialized
///   slots at the end if necessary.
void arrlist_set_len(TYPE_)(ArrayListOfT arrlist[static const restrict 1], size_t len, void* (*custom_realloc)(void* _Block, size_t _Size)) {
    if (arrlist->capacity < len) {
        arrlist_set_capacity(TYPE_)(arrlist, len, custom_realloc);
    }
    if (arrlist->data) {
        arrlist->len = len;
    }
}


#undef name_of_arraylist2
#undef name_of_arraylist
#undef arrlist_init29
#undef arrlist_init
#undef arrlist_init12
#undef arrlist_init1
#undef arrlist_init22
#undef arrlist_init2
#undef arrlist_deinit2
#undef arrlist_deinit
#undef arrlist_void_deinit2
#undef arrlist_void_deinit
#undef arrlist_pop2
#undef arrlist_pop
#undef arrlist_put2
#undef arrlist_put
#undef arrlist_put_ptr2
#undef arrlist_put_ptr
#undef arrlist_meybe_grow2
#undef arrlist_meybe_grow
#undef arrlist_grow2
#undef arrlist_grow
#undef arrlist_growff2
#undef arrlist_growff
#undef arrlist_insert2
#undef arrlist_insert
#undef arrlist_insert_n2
#undef arrlist_insert_n
#undef arrlist_add_index_n2
#undef arrlist_add_index_n
#undef arrlist_add_ptr2
#undef arrlist_add_ptr
#undef arrlist_del_n2
#undef arrlist_del_n
#undef arrlist_del2
#undef arrlist_del
#undef arrlist_del_ret2
#undef arrlist_del_ret
#undef arrlist_del_swap2
#undef arrlist_del_swap
#undef arrlist_del_swap_ret2
#undef arrlist_del_swap_ret
#undef arrlist_set_capacity2
#undef arrlist_set_capacity
#undef arrlist_set_len2
#undef arrlist_set_len
#undef TYPE_
#undef IMPL_ARRAYLIST_


#endif // IMPL_ARRAYLIST_

#ifdef UNIT_TESTS_
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void more_tests(void) {
    {
        printf("[TEST] running arrlist_put\n");
        auto arr = arrlist_init_int(malloc);
        arrlist_put_int(&arr, 96, realloc);
        arrlist_put_int(&arr, 0, realloc);
        arrlist_put_int(&arr, 23, realloc);
        arrlist_put_int(&arr, 42, realloc);
        assert(arr.len == 4);
        assert(arr.data[0] == 96);
        assert(arr.data[1] == 0);
        assert(arr.data[2] == 23);
        assert(arr.data[3] == 42);

        arrlist_deinit_unmanaged_int(&arr, free);
    }
    {
        printf("[TEST] running arrlist_put\n");
        auto arr = arrlist_init_int(malloc);
        arrlist_put_int(&arr, 96, realloc);
        arrlist_put_int(&arr, 0, realloc);
        arrlist_put_int(&arr, 23, realloc);
        arrlist_put_int(&arr, 42, realloc);
        assert(arr.len == 4);
        assert(arr.data[0] == 96);
        assert(arr.data[1] == 0);
        assert(arr.data[2] == 23);
        assert(arr.data[3] == 42);

        (void)arrlist_pop_int(&arr);

        arrlist_deinit_unmanaged_int(&arr, free);
    }
    {
        printf("[TEST] running arrlist_put\n");
        auto arr = arrlist_init_int(malloc);

        for (int i = 0; i < 1000; ++i) {
            arrlist_put_int(&arr, i * 2, realloc);
        }
        assert(arr.data[1] == 2);
        assert(arr.data[999] == 999 * 2);

        arrlist_deinit_unmanaged_int(&arr, free);
    }
    {
        printf("[TEST] running arrlist_put\n");
        auto arr = arrlist_init_int(malloc);
        arrlist_put_int(&arr, 123, realloc);
        arrlist_put_int(&arr, 456, realloc);
        arrlist_put_int(&arr, 789, realloc);

        assert(arrlist_pop_int(&arr) == 789);
        assert(arrlist_pop_int(&arr) == 456);
        assert(arrlist_pop_int(&arr) == 123);
        arrlist_deinit_unmanaged_int(&arr, free);
    }
    {
        printf("[TEST] running arrlist_pop\n");
        auto arr = arrlist_init_int(malloc);

        for (int i = 0; i < 1000; ++i) {
            arrlist_insert_int(&arr, 0, i, realloc);
        }

        assert(arr.data[0] == 999);
        assert(arr.data[arr.len - 1] == 0);
        arrlist_insert_int(&arr, 10, 123, realloc);
        assert(arr.data[10] == 123);
        assert(arr.len == 1001);
        arrlist_insert_int(&arr, arr.len - 2, 678, realloc);
        assert(arr.data[999] == 678);
        arrlist_insert_int(&arr, 10, 123, realloc);
        arrlist_insert_int(&arr, arr.len, 789, realloc);
        assert(arr.data[arr.len - 1] == 789);

        // for (size_t i = {}; i < arr.len; ++i) {
        //     printf(", %d", arr.data[i]);
        // }
        // printf("\n");

        arrlist_deinit_int(&arr);
    }
    {
        printf("[TEST] running arrlist_remove\n");

        auto arr = arrlist_init_int(malloc);
        for (char i = {}; i < 26; ++i) {
            arrlist_put_int(&arr, 'a' + i, realloc);
        }
        arrlist_del_int(&arr, 2);

        assert(arr.len == 25);
        assert(arr.data[0] == 'a');
        assert(arr.data[1] == 'b');
        assert(arr.data[2] == 'd');
        assert(arr.data[3] == 'e');


        arrlist_void_deinit_int(&arr);
    }
}
#endif // UNIT_TESTS_


#ifdef __cplusplus
}
#endif //__cplusplus
