#pragma once


#include <stdint.h>
typedef enum {
    Breed_LabradorRetriever = 0,
    Breed_GoldenRetriever,
    Breed_FrenchBulldog,
    Breed_GermanShepherdDog,
    Breed_Bulldog,
    Breed_Pug,
} Breed;


typedef struct {
    char const* name;
    uint8_t age;
    Breed breed;
} Dog;
