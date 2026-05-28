
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
/* --- Constants --- */
#define MAX_PACKAGES  20
#define MAX_BOOKINGS  100
#define NAME_LEN      50
#define ID_LEN        10
#define DATE_LEN      15
#define CONTACT_LEN   15

/* --- Struct: Package (stored using Array) --- */
typedef struct {
    char  packageID[ID_LEN];
    char  packageName[NAME_LEN];
    char  location[NAME_LEN];
    int   durationNights;
    float pricePerNight;
    int   maxGuests;
} Package;
 