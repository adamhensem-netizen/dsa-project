
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKAGES  20
#define MAX_BOOKINGS  100
#define NAME_LEN      50
#define ID_LEN        10
#define DATE_LEN      15
#define CONTACT_LEN   15

/* Struct Package - guna Array */
typedef struct {
    char  packageID[ID_LEN];
    char  packageName[NAME_LEN];
    char  location[NAME_LEN];
    int   durationNights;
    float pricePerNight;
    int   maxGuests;
} Package;

/* Struct Booking - guna Linked List */
typedef struct BookingNode {
    char   bookingID[ID_LEN];
    char   customerName[NAME_LEN];
    char   contactNo[CONTACT_LEN];
    char   packageID[ID_LEN];
    char   checkInDate[DATE_LEN];
    int    numGuests;
    float  totalPrice;
    struct BookingNode *next;
} BookingNode;

/* Global Variables */
Package     packageList[MAX_PACKAGES];
int         packageCount = 0;
BookingNode *bookingHead = NULL;
int         bookingCount = 0;


/* ============================================================
    [adam]
   Bahagian  : ADD DATA
   Functions : addPackage(), addBooking()
   ============================================================ */

void addPackage() {
    /* code */
}

void addBooking() {
    /* code*/
}


/* ============================================================
    [NAMA]
    DISPLAY DATA
   Functions : displayAllPackages(), displayAllBookings()
   ============================================================ */

void displayAllPackages() {
    /*code*/
}

void displayAllBookings() {
    /*code*/
}


/* ============================================================
   [NAMA]
   SEARCH & SORT
   Functions : searchPackage(), searchBooking(),
               sortPackageByPrice(), sortBookingByDate()
   ============================================================ */

void searchPackage() {
    /* code */
}

void searchBooking() {
    /* code */
}

void sortPackageByPrice() {
    /*code*/
}

void sortBookingByDate() {
    /*code */
}


/* ============================================================
   [NAMA]
	UPDATE & REMOVE
   Functions : updateBooking(), removeBooking()
   ============================================================ */

void updateBooking() {
    /* code */
}

void removeBooking() {
    /* code */
}


/* ============================================================
  [NAMA]
   REPORT & CALCULATION
   Functions : calculateTotalRevenue(), calculateAverageGuests(),
               findMostPopularPackage(), generateReport()
   ============================================================ */

float calculateTotalRevenue() {
    /*code */
    return 0;
}

float calculateAverageGuests() {
    /* code */
    return 0;
}

void findMostPopularPackage() {
    /*code */
}

void generateReport() {
    /* code*/
}


/* ============================================================
   takyah tukar bawah ni
   ============================================================ */

void displayMenu() {
    printf("\n  ==========================================\n");
    printf("     RESORT & VACATION PACKAGE SYSTEM\n");
    printf("  ==========================================\n");
    printf("   1. Add New Package\n");
    printf("   2. Add New Booking\n");
    printf("   3. Display All Packages\n");
    printf("   4. Display All Bookings\n");
    printf("   5. Search Package\n");
    printf("   6. Search Booking\n");
    printf("   7. Sort Packages by Price\n");
    printf("   8. Sort Bookings by Date\n");
    printf("   9. Update Booking\n");
    printf("  10. Remove Booking\n");
    printf("  11. Generate Report\n");
    printf("   0. Exit\n");
    printf("  ==========================================\n");
    printf("  Enter choice: ");
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf(" %d", &choice);

        switch (choice) {
            case  1: addPackage();           break;
            case  2: addBooking();           break;
            case  3: displayAllPackages();   break;
            case  4: displayAllBookings();   break;
            case  5: searchPackage();        break;
            case  6: searchBooking();        break;
            case  7: sortPackageByPrice();   break;
            case  8: sortBookingByDate();    break;
            case  9: updateBooking();        break;
            case 10: removeBooking();        break;
            case 11: generateReport();       break;
            case  0: printf("\n  Goodbye!\n\n"); break;
            default: printf("\n  [!] Invalid choice.\n");
        }

    } while (choice != 0);

    return 0;
}