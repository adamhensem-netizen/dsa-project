
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
   [DIN]
   SEARCH & SORT
   Functions : searchPackage(), searchBooking(),
               sortPackageByPrice(), sortBookingByDate()
   ============================================================ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/* ============================================================
   CONSTANTS
   ============================================================ */
#define MAX_PACKAGES   20
#define MAX_BOOKINGS   100

#define NAME_LEN       100
#define ID_LEN         15
#define DATE_LEN       20
#define CONTACT_LEN    20
#define LOCATION_LEN   100
#define ITINERARY_LEN  1000

/* ============================================================
   STRUCT: PACKAGE
   ============================================================ */
typedef struct {
    char  packageID[ID_LEN];
    char  packageName[NAME_LEN];
    char  location[LOCATION_LEN];
    char  itinerary[ITINERARY_LEN];

    int   durationNights;
    float pricePerPerson;
    int   maxGuests;
} Package;

/* ============================================================
   STRUCT: BOOKING
   ============================================================ */
typedef struct {
    char  bookingID[ID_LEN];
    char  packageID[ID_LEN];
    char  customerName[NAME_LEN];
    char  departureDate[DATE_LEN];
    char  contact[CONTACT_LEN];

    int   numGuests;
    float totalPrice;
} Booking;

/* ============================================================
   GLOBAL ARRAYS
   ============================================================ */
Package packages[MAX_PACKAGES];
Booking bookings[MAX_BOOKINGS];

int packageCount = 0;
int bookingCount = 0;

/* ============================================================
   FORWARD DECLARATIONS
   ============================================================ */
int parseDateDMY(const char *dateStr, struct tm *out);
int isDateInPast(struct tm *inputDate);
int findPackageByID(const char *pkgID);

/* ============================================================
   INITIALIZE PACKAGES
   ============================================================ */
void initPackages() {

    /* Package 1 */
    strcpy(packages[0].packageID, "KRKBJ08");
    strcpy(packages[0].packageName, "Classical Korea 8D6N");
    strcpy(packages[0].location, "Busan / Gyeongju / Daegu / Seoul");
    strcpy(packages[0].itinerary,
           "Day 1 - Kuala Lumpur to Incheon\n"
           "Day 2 - Incheon - Seoul train to Busan\n"
           "Take KTX Train to Busan [Includes One way luggage truck]\n"
           "Gamcheon Cultural Village | BIFF Street | Jagalchi Market\n"
           "Day 3 - Busan\n"
           "Haeundae Beach Train | Jjimjilbang Experience\n"
           "Day 4 - Busan - Gyeongju\n"
           "Bulguksa Temple | Seokguram Grotto | Hwangnidan Street | Woljeonggyo Bridge\n"
           "Day 5 - Gyeongju - Daegu - Jeongseon\n"
           "Daegu 83 Tower [Includes Observatory Deck] | Jeongseon Arirang Market | Byeongbangchi Skywalk\n"
           "Seasonal Arrangement : If visitation falls between 27Mar - 3Apr & 15Oct - 10Nov, it will be arranged to: Suseong lake\n"
           "Day 6 - Jeongseon - Seoul\n"
           "HAO Wellness Program [Meditation] [Traditional Tea Ceremony] | Hongdae Fashion Street | Nanta Show\n"
           "Seasonal Arrangement : If visitation falls between 15Oct - 10Nov, it will be arranged to: Jeongamsa Temple\n"
           "Day 7 - Seoul\n"
           "Compulsory Shopping Stops [Ginseng Outlet] [Healthy Liver Shop] [Cosmetic Duty Free]\n"
           "Hanbok Touring around Gyeongbokgung\n"
           "Day 8 - Seoul - Incheon to Kuala Lumpur\n"
           "Local Products & Souvenir Store | Transfer to airport for flight back home.\n");

    packages[0].durationNights = 6;
    packages[0].pricePerPerson = 8500.00f;
    packages[0].maxGuests = 16;

    /* Package 2 */
    strcpy(packages[1].packageID, "THBKK05");
    strcpy(packages[1].packageName, "Bangkok in Depth Tour 5D4N");
    strcpy(packages[1].location, "Bangkok / Kanchanaburi");
    strcpy(packages[1].itinerary,
           "Day 1 - Kuala Lumpur to Bangkok\n"
           "Visit Thai-Burma Death Railway | Enjoy Sunset at River Kwai\n"
           "Day 2 - Kanchanaburi Safari Park\n"
           "Photograph with Giraffes | Visit Mallika Ancient Village | Thai Traditional Costume Experience | CHAN Nature Cafe | JJ Green Night Market\n"
           "Day 3 - Kanchanaburi -132km- Bangkok\n"
           "JEATH War Museum | The Erawan Museum | Full Body Thai Massage | The One Ratchada Night Market\n"
           "Day 4 - Bangkok\n"
           "King Power Mahanakhon Skywalk\n"
           "Recommendation Attractions:\n"
           "- Family Fun: SEA LIFE Bangkok Ocean World | Chocolate Ville | ASIATIQUE The Riverfront\n"
           "- Shopping: ICON SIAM | Central Embassy | Platinum Mall | Siam Paragon\n"
           "Day 5 - Bangkok to Kuala Lumpur\n"
           "Spend the day at leisure before transferring to Bangkok airport for your flight home.\n");

    packages[1].durationNights = 4;
    packages[1].pricePerPerson = 3599.00f;
    packages[1].maxGuests = 20;

    /* Package 3 */
    strcpy(packages[2].packageID, "INKNO04");
    strcpy(packages[2].packageName, "DESA BATAK LAKE TOBA 4D3N");
    strcpy(packages[2].location, "Medan/Brastagi/Parapat/Samosir Island");
    strcpy(packages[2].itinerary,
           "Day 1 - Kuala Lumpur to MEDAN to BRASTAGI\n"
           "Gather at KLIA Airport for departure flight to Medan. Arrive at Kualanamu International Airport & meet with Local Tour Guide.\n"
           "Start our journey to Brastagi takes about 3 hours overland transfer.\n"
           "City Tour at Brastagi: Taman Alam Lumbini, Visit Batik House and Pasar Buah. Enjoy evening walk at Brastagi. Check in hotel & Dinner.\n"
           "Day 2 - BRASTAGI to PARAPAT to LAKE TOBA to SAMOSIR ISLAND\n"
           "Stop in Simarjarunjung and Sipiso-piso Waterfall to see the beautiful panorama of Lake Toba. Arrive at Parapat and lunch at local restaurant.\n"
           "From here we will take cruise to Lake Toba for about 45 minutes. Then visit Ambarita Village to see the famous stone chairs and execution place of King Siallagan.\n"
           "Day 3 - SAMOSIR ISLAND - MEDAN\n"
           "Breakfast at hotel and check out. Proceed to Medan passing the highway. Upon arrival in Medan, lunch at local restaurant.\n"
           "After lunch, city tour to visit Maimoon Palace and Grand Mosque. Check in hotel afterward. Overnight stay in Medan. Dinner at local restaurant.\n"
           "Day 4 - MEDAN to Kuala Lumpur\n"
           "Breakfast at hotel & Check out. Transfer to Kualanamu International Airport for flight back to Kuala Lumpur.\n");

    packages[2].durationNights = 3;
    packages[2].pricePerPerson = 1500.00f;
    packages[2].maxGuests = 10;

    packageCount = 3;
}

/* ============================================================
   CASE INSENSITIVE SEARCH
   ============================================================ */
int containsIgnoreCase(const char *haystack, const char *needle) {
    char h[1000];
    char n[1000];

    strncpy(h, haystack, sizeof(h) - 1);
    strncpy(n, needle, sizeof(n) - 1);

    h[sizeof(h) - 1] = '\0';
    n[sizeof(n) - 1] = '\0';

    for (int i = 0; h[i]; i++) h[i] = tolower((unsigned char) h[i]);
    for (int i = 0; n[i]; i++) n[i] = tolower((unsigned char) n[i]);

    return strstr(h, n) != NULL;
}

/* ============================================================
   FIND PACKAGE BY ID
   ============================================================ */
int findPackageByID(const char *pkgID) {
    for (int i = 0; i < packageCount; i++) {
        if (strcmp(packages[i].packageID, pkgID) == 0) {
            return i;
        }
    }
    return -1;
}

/* ============================================================
   DISPLAY FUNCTIONS
   ============================================================ */
void printPackageHeader() {
    printf("\n%-10s %-30s %-35s %-8s %-15s %-12s\n",
           "ID", "Package Name", "Location", "Nights", "Price/Pax", "Max Guests");
    printf("====================================================================================================================\n");
}

void printPackage(const Package *p) {
    printf("%-10s %-30s %-35s %-8d MYR %-11.2f %-12d\n",
           p->packageID, p->packageName, p->location, p->durationNights, p->pricePerPerson, p->maxGuests);
}

/* ============================================================
   PRETTY PRINT ITINERARY WITH DYNAMIC WORD WRAPPING
   ============================================================ */
void printPrettyItinerary(const char *itineraryRaw) {
    char copy[ITINERARY_LEN];
    strncpy(copy, itineraryRaw, ITINERARY_LEN - 1);
    copy[ITINERARY_LEN - 1] = '\0';

    printf("+------------------------------------------------------------------------------------------------------------------+\n");
    printf("|                                                 TOUR ITINERARY                                                   |\n");
    printf("+------------------------------------------------------------------------------------------------------------------+\n");

    char *ptr = copy;
    while (*ptr != '\0') {
        char line[ITINERARY_LEN];
        int len = 0;

        while (*ptr != '\0' && *ptr != '\n') {
            line[len++] = *ptr++;
        }
        if (*ptr == '\n') ptr++;
        line[len] = '\0';

        if (len == 0) continue;

        int isDayHeader = (strncmp(line, "Day ", 4) == 0);

        if (isDayHeader) {
            printf("|                                                                                                                  |\n");
            printf("|  %-110s  |\n", line);
            printf("|  --------------------------------------------------------------------------------------------------------------  |\n");
        } else {
            char *walk = line;
            while (strlen(walk) > 0) {
                char chunk[105];
                if (strlen(walk) <= 104) {
                    strcpy(chunk, walk);
                    walk += strlen(walk);
                } else {
                    int cutIndex = 104;
                    while (cutIndex > 0 && walk[cutIndex] != ' ') cutIndex--;
                    if (cutIndex == 0) cutIndex = 104;
                    strncpy(chunk, walk, cutIndex);
                    chunk[cutIndex] = '\0';
                    walk += cutIndex;
                    while (*walk == ' ') walk++;
                }
                printf("|     %-105s  |\n", chunk);
            }
        }
    }

    printf("|                                                                                                                  |\n");
    printf("+------------------------------------------------------------------------------------------------------------------+\n");
}

/* ============================================================
   DISPLAY ALL PACKAGES
   ============================================================ */
void displayAllPackages() {
    if (packageCount == 0) {
        printf("\nNo packages available.\n");
        return;
    }

    printf("\n=============================================== ALL PACKAGES ========================================================");
    printPackageHeader();

    for (int i = 0; i < packageCount; i++) {
        printPackage(&packages[i]);
        printPrettyItinerary(packages[i].itinerary);
        printf("\n");
    }

    printf("Total Packages Available: %d\n", packageCount);
}

/* ============================================================
   SEARCH MENU / ID SEARCH
   ============================================================ */
void searchMenu() {
    char packageID[ID_LEN];
    int found = 0;

    printf("\n=========== SEARCH PACKAGE ===========\n");
    printf("Enter Package ID: ");
    fgets(packageID, sizeof(packageID), stdin);
    packageID[strcspn(packageID, "\n")] = '\0';

    for (int i = 0; i < packageCount; i++) {
        if (strcmp(packages[i].packageID, packageID) == 0) {
            printPackageHeader();
            printPackage(&packages[i]);
            printPrettyItinerary(packages[i].itinerary);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nPackage ID '%s' not found.\n", packageID);
    }
}

/* ============================================================
   PARSE DATE STRING "DD-MMM-YYYY" INTO struct tm
   Returns 1 on success, 0 on failure.
   ============================================================ */
int parseDateDMY(const char *dateStr, struct tm *out) {
    const char *months[] = {
        "jan","feb","mar","apr","may","jun",
        "jul","aug","sep","oct","nov","dec"
    };

    char day[3], mon[4], year[5];
    if (sscanf(dateStr, "%2[^-]-%3[^-]-%4s", day, mon, year) != 3)
        return 0;

    for (int i = 0; mon[i]; i++) mon[i] = tolower((unsigned char)mon[i]);

    int monthIndex = -1;
    for (int i = 0; i < 12; i++) {
        if (strcmp(mon, months[i]) == 0) { monthIndex = i; break; }
    }
    if (monthIndex == -1) return 0;

    memset(out, 0, sizeof(*out));
    out->tm_mday  = atoi(day);
    out->tm_mon   = monthIndex;
    out->tm_year  = atoi(year) - 1900;
    out->tm_isdst = -1;

    return (out->tm_mday >= 1 && out->tm_mday <= 31 &&
            out->tm_year >= 100);
}

/* ============================================================
   CHECK IF A DATE IS IN THE PAST (before today's date)
   Returns 1 if past, 0 if today or future.
   ============================================================ */
int isDateInPast(struct tm *inputDate) {
    time_t now = time(NULL);
    struct tm today = *localtime(&now);

    today.tm_hour = 0; today.tm_min = 0; today.tm_sec = 0;
    today.tm_isdst = -1;

    time_t tInput = mktime(inputDate);
    time_t tToday = mktime(&today);

    return difftime(tInput, tToday) < 0;
}

/* ============================================================
   ADD BOOKING
   ============================================================ */
void addBooking() {
    if (bookingCount >= MAX_BOOKINGS) {
        printf("\nBooking list is full.\n");
        return;
    }

    char targetPkgID[ID_LEN];
    printf("\n=========== BOOK TOUR ===========\n");
    printf("Enter Package ID: ");
    scanf("%s", targetPkgID);
    getchar();

    int pkgIndex = findPackageByID(targetPkgID);
    if (pkgIndex == -1) {
        printf("Package ID not found.\n");
        return;
    }

    Booking *b = &bookings[bookingCount];
    strcpy(b->packageID, targetPkgID);
    sprintf(b->bookingID, "BK%03d", bookingCount + 1);

    printf("Customer Name: ");
    fgets(b->customerName, sizeof(b->customerName), stdin);
    b->customerName[strcspn(b->customerName, "\n")] = '\0';

    /* Departure date with validation */
    struct tm depDate;
    while (1) {
        printf("Departure Date (DD-MMM-YYYY): ");
        fgets(b->departureDate, sizeof(b->departureDate), stdin);
        b->departureDate[strcspn(b->departureDate, "\n")] = '\0';

        if (!parseDateDMY(b->departureDate, &depDate)) {
            printf("Invalid date format. Please use DD-MMM-YYYY (e.g. 25-Dec-2026).\n");
            continue;
        }
        if (isDateInPast(&depDate)) {
            printf("Departure date cannot be in the past. Please enter a future date.\n");
            continue;
        }
        break;
    }

    printf("Contact Number: ");
    fgets(b->contact, sizeof(b->contact), stdin);
    b->contact[strcspn(b->contact, "\n")] = '\0';

    printf("Number of Guests: ");
    scanf("%d", &b->numGuests);

    if (b->numGuests <= 0) {
        printf("Invalid guest number.\n");
        return;
    }

    if (b->numGuests > packages[pkgIndex].maxGuests) {
        printf("Maximum guests allowed for this package is: %d\n", packages[pkgIndex].maxGuests);
        return;
    }

    b->totalPrice = packages[pkgIndex].pricePerPerson * b->numGuests;

    /* Lookup duration from package for the summary */
    int durNights = packages[pkgIndex].durationNights;
    int durDays   = durNights + 1;

    printf("\n=========== BOOKING SUMMARY ===========\n");
    printf("Booking ID      : %s\n", b->bookingID);
    printf("Package ID      : %s\n", b->packageID);
    printf("Customer Name   : %s\n", b->customerName);
    printf("Departure Date  : %s\n", b->departureDate);
    printf("Duration        : %dD%dN\n", durDays, durNights);
    printf("Contact         : %s\n", b->contact);
    printf("Guests          : %d\n", b->numGuests);
    printf("Total Price     : MYR %.2f\n", b->totalPrice);

    bookingCount++;
    printf("\nBooking added successfully!\n");
}

/* ============================================================
   DISPLAY ALL BOOKINGS
   ============================================================ */
void displayBookings() {
    if (bookingCount == 0) {
        printf("\nNo bookings available.\n");
        return;
    }

    printf("\n=========== ALL BOOKINGS ===========\n");
    printf("%-10s %-10s %-25s %-15s %-12s %-8s %-14s\n",
           "Book ID", "Pkg ID", "Customer", "Departure", "Duration", "Guests", "Total");
    printf("-----------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < bookingCount; i++) {
        /* Look up the package to get duration */
        int pkgIdx = findPackageByID(bookings[i].packageID);
        int durNights = (pkgIdx != -1) ? packages[pkgIdx].durationNights : 0;
        int durDays   = durNights + 1;

        char duration[20];
        sprintf(duration, "%dD%dN", durDays, durNights);

        printf("%-10s %-10s %-25s %-15s %-12s %-8d MYR %.2f\n",
               bookings[i].bookingID,
               bookings[i].packageID,
               bookings[i].customerName,
               bookings[i].departureDate,
               duration,
               bookings[i].numGuests,
               bookings[i].totalPrice);
    }
}

/* ============================================================
   MAIN MENU
   ============================================================ */
void mainMenu() {
    int choice;
    do {
        printf("\n=================================================\n");
        printf("                APPLE VACATIONS\n");
        printf("               TOUR BOOKING SYSTEM\n");
        printf("=================================================\n");
        printf("1. View All Packages\n");
        printf("2. Search Packages by ID\n");
        printf("3. Book a Tour\n");
        printf("4. View All Bookings\n");
        printf("0. Exit\n");
        printf("Choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input type.\n");
            while(getchar() != '\n');
            continue;
        }
        getchar();

        switch (choice) {
            case 1: displayAllPackages(); break;
            case 2: searchMenu(); break;
            case 3: addBooking(); break;
            case 4: displayBookings(); break;
            case 0: printf("\nThank you for choosing Apple Vacations!\n"); break;
            default: printf("\nInvalid option.\n");
        }
    } while (choice != 0);
}

/* ============================================================
   MAIN FUNCTION
   ============================================================ */
int main() {
    initPackages();
    mainMenu();
    return 0;
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