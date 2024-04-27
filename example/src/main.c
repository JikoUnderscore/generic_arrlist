#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "dog.h"
#include "vectors.h"



static void arrlist_push_cstring(ArrayList_char arrlist[static const restrict 1], char const* const cstr, size_t const str_len) {
    arrlist_set_capacity_char(arrlist, str_len, realloc);
    char const* str_ptr = cstr;
    for (char character = *str_ptr; character != '\0'; character = *++str_ptr) {
        arrlist->data[arrlist->len++] = character;
    }
}

int main() {
    {
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

        for (size_t i = 0; i < arr.len; ++i) {
            printf("%d %c, ", arr.data[i], arr.data[i]);
        }
        putchar('\n');
        arrlist_deinit_int(&arr); // used `free` from `stdlib.h`
    }
    {
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


    {
        ArrayList_Dog pets = {};
        arrlist_put_Dog(&pets, (Dog){.name="Maximus",.age=5, .breed=Breed_LabradorRetriever}, realloc);
        arrlist_put_Dog(&pets, (Dog){.name="Sunny",.age=4, .breed=Breed_GoldenRetriever}, realloc);
        arrlist_put_Dog(&pets, (Dog){.name="Belle",.age=1, .breed=Breed_FrenchBulldog}, realloc);
        arrlist_put_Dog(&pets, (Dog){.name="Ranger",.age=0, .breed=Breed_GermanShepherdDog}, realloc);
        arrlist_put_Dog(&pets, (Dog){.name="Winston",.age=15, .breed=Breed_Bulldog}, realloc);
        arrlist_put_Dog(&pets, (Dog){.name="Butsa",.age=16, .breed=Breed_Pug}, realloc);


        for (size_t i = 0; i < pets.len; ++i) {
            printf("Dog { name = %s, age = %d, breed = %d }\n", pets.data[i].name, pets.data[i].age, pets.data[i].breed);
        }
    
        arrlist_deinit_Dog(&pets);
    }
}
