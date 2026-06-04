
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

void addPackage()
{
    if (packageCount >= MAX_PACKAGES)
    {
        printf("\nPackage list is full!\n");
        return;
    }

    printf("\n===== ADD PACKAGE =====\n");

    printf("Package ID: ");
    scanf("%s", packageList[packageCount].packageID);

    getchar();

    printf("Package Name: ");
    fgets(packageList[packageCount].packageName, NAME_LEN, stdin);
    packageList[packageCount].packageName[
        strcspn(packageList[packageCount].packageName, "\n")
    ] = '\0';

    printf("Location: ");
    fgets(packageList[packageCount].location, NAME_LEN, stdin);
    packageList[packageCount].location[
        strcspn(packageList[packageCount].location, "\n")
    ] = '\0';

    printf("Duration (Nights): ");
    scanf("%d", &packageList[packageCount].durationNights);

    printf("Price Per Night: ");
    scanf("%f", &packageList[packageCount].pricePerNight);

    printf("Maximum Guests: ");
    scanf("%d", &packageList[packageCount].maxGuests);

    packageCount++;

    printf("\nPackage added successfully!\n");
}

void addBooking()
{
    BookingNode *newBooking;

    newBooking = (BookingNode*)malloc(sizeof(BookingNode));

    if (newBooking == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("\n===== ADD BOOKING =====\n");

    printf("Booking ID: ");
    scanf("%s", newBooking->bookingID);

    getchar();

    printf("Customer Name: ");
    fgets(newBooking->customerName, NAME_LEN, stdin);
    newBooking->customerName[
        strcspn(newBooking->customerName, "\n")
    ] = '\0';

    printf("Contact Number: ");
    fgets(newBooking->contactNo, CONTACT_LEN, stdin);
    newBooking->contactNo[
        strcspn(newBooking->contactNo, "\n")
    ] = '\0';

    printf("Package ID: ");
    scanf("%s", newBooking->packageID);

    printf("Check-in Date (DD/MM/YYYY): ");
    scanf("%s", newBooking->checkInDate);

    printf("Number of Guests: ");
    scanf("%d", &newBooking->numGuests);

    printf("Total Price: ");
    scanf("%f", &newBooking->totalPrice);

    newBooking->next = NULL;

    if (bookingHead == NULL)
    {
        bookingHead = newBooking;
    }
    else
    {
        BookingNode *current = bookingHead;

        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = newBooking;
    }

    bookingCount++;

    printf("\nBooking added successfully!\n");
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
   [ALIP]
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