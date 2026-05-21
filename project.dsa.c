#include <stdio.h>
#include <string.h>

#define MAX_DEALS 100

struct StaycationDeal
{
    char packageID[10];
    char destination[30];
    float originalPrice;
    float discountPercent;
    int voucherUsed;
};

struct StaycationDeal dealList[MAX_DEALS];
int totalDeals = 0;


/* Function Header */
void addDeal();
void displayDeals();
void searchDeal();
void updateDeal();
void removeDeal();
void sortDeals();
void generateReport();


int main()
{
    int choice;

    do
    {
        printf("\n=====================================\n");
        printf("     STAYCATION DEAL SYSTEM\n");
        printf("=====================================\n");
        printf("1. Add New Package\n");
        printf("2. Display All Packages\n");
        printf("3. Search Package\n");
        printf("4. Update Package\n");
        printf("5. Remove Package\n");
        printf("6. Sort Packages\n");
        printf("7. Revenue Report\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addDeal();
                break;

            case 2:
                displayDeals();
                break;

            case 3:
                searchDeal();
                break;

            case 4:
                updateDeal();
                break;

            case 5:
                removeDeal();
                break;

            case 6:
                sortDeals();
                break;

            case 7:
                generateReport();
                break;

            case 8:
                printf("\nThank you for using the system.\n");
                break;

            default:
                printf("\nInvalid choice.\n");
        }

    } while(choice != 8);

    return 0;
}


void addDeal()
{
    if(totalDeals >= MAX_DEALS)
    {
        printf("Storage full.\n");
        return;
    }

    printf("\n----- ADD PACKAGE -----\n");

    printf("Enter Package ID: ");
    scanf("%s", dealList[totalDeals].packageID);

    printf("Enter Destination: ");
    scanf(" %[^\n]", dealList[totalDeals].destination);

    printf("Enter Original Price: ");
    scanf("%f", &dealList[totalDeals].originalPrice);

    printf("Enter Discount Percentage: ");
    scanf("%f", &dealList[totalDeals].discountPercent);

    printf("Voucher Used (1=Yes, 0=No): ");
    scanf("%d", &dealList[totalDeals].voucherUsed);

    totalDeals++;

    printf("Package added successfully.\n");
}


void displayDeals()
{
    int i;

    if(totalDeals == 0)
    {
        printf("No data available.\n");
        return;
    }

    printf("\n----- PACKAGE LIST -----\n");

    for(i = 0; i < totalDeals; i++)
    {
        printf("\nPackage %d\n", i + 1);
        printf("ID: %s\n", dealList[i].packageID);
        printf("Destination: %s\n", dealList[i].destination);
        printf("Price: RM%.2f\n", dealList[i].originalPrice);
        printf("Discount: %.2f%%\n", dealList[i].discountPercent);

        if(dealList[i].voucherUsed == 1)
            printf("Voucher: Yes\n");
        else
            printf("Voucher: No\n");
    }
}


void searchDeal()
{
    char searchID[10];
    int i;

    printf("\nEnter Package ID to search: ");
    scanf("%s", searchID);

    for(i = 0; i < totalDeals; i++)
    {
        if(strcmp(searchID, dealList[i].packageID) == 0)
        {
            printf("\nPackage Found.\n");
            printf("ID: %s\n", dealList[i].packageID);
            printf("Destination: %s\n", dealList[i].destination);
            printf("Price: RM%.2f\n", dealList[i].originalPrice);

            return;
        }
    }

    printf("Package not found.\n");
}


void updateDeal()
{
    char searchID[10];
    int i;

    printf("\nEnter Package ID to update: ");
    scanf("%s", searchID);

    for(i = 0; i < totalDeals; i++)
    {
        if(strcmp(searchID, dealList[i].packageID) == 0)
        {
            printf("New Destination: ");
            scanf(" %[^\n]", dealList[i].destination);

            printf("New Price: ");
            scanf("%f", &dealList[i].originalPrice);

            printf("New Discount: ");
            scanf("%f", &dealList[i].discountPercent);

            printf("Updated successfully.\n");
            return;
        }
    }

    printf("Package not found.\n");
}


void removeDeal()
{
    char searchID[10];
    int i, j;

    printf("\nEnter Package ID to remove: ");
    scanf("%s", searchID);

    for(i = 0; i < totalDeals; i++)
    {
        if(strcmp(searchID, dealList[i].packageID) == 0)
        {
            for(j = i; j < totalDeals - 1; j++)
            {
                dealList[j] = dealList[j + 1];
            }

            totalDeals--;

            printf("Package removed successfully.\n");
            return;
        }
    }

    printf("Package not found.\n");
}


void sortDeals()
{
    int i, j;
    struct StaycationDeal temp;

    for(i = 0; i < totalDeals - 1; i++)
    {
        for(j = 0; j < totalDeals - i - 1; j++)
        {
            if(dealList[j].originalPrice >
               dealList[j + 1].originalPrice)
            {
                temp = dealList[j];
                dealList[j] = dealList[j + 1];
                dealList[j + 1] = temp;
            }
        }
    }

    printf("Packages sorted successfully.\n");
}


void generateReport()
{
    int i;
    float revenue;
    float totalRevenue = 0;

    if(totalDeals == 0)
    {
        printf("No data available.\n");
        return;
    }

    printf("\n----- REVENUE REPORT -----\n");

    for(i = 0; i < totalDeals; i++)
    {
        revenue =
            dealList[i].originalPrice -
            (dealList[i].originalPrice *
             dealList[i].discountPercent / 100);

        totalRevenue += revenue;

        printf("%s : RM%.2f\n",
               dealList[i].packageID,
               revenue);
    }

    printf("\nTotal Revenue: RM%.2f\n",
           totalRevenue);
}
//adam taik
