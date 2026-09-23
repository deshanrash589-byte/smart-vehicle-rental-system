#include <stdio.h>

void initializeFleet();
void displayMenu();

#define CATEGORIES 4
#define MAX_VEHICLES 15

int fleetAvailability[CATEGORIES][MAX_VEHICLES];

int fleetLimit[4]={15,10,8,5};

double dailyRate[4]={
   5000,
   10000,
   22000,
   16000
};

double securityDeposit[4]= {
   15000,
   30000,
   50000,
   40000
};
char customerNames[100][50];
char nicPassport[100][30];
char licenseNumber[100][30];


int selectedCategory[100];
int rentalDays[100];
int driverOpted[100];

double finalBills[100];

int customerCount = 0;

void displayMenu();
void initializeFleet();
void registerRental();

int main()
{
    initializeFleet();
    displayMenu();

    return 0;

}

void displayMenu()
{
    printf("\n=====SMART VEHICAL RENTAL SYSTEM=====\n\n\n");
    printf("1.Register New Rental\n");
    printf("2.Display Rental Records\n");
    printf("3.Display Fleet Status\n");
    printf("4.Sort Rental by Oriority\n");
    printf("5.View reports\n");
    printf("6.Exit\n");
}

void initializeFleet()
{
    for (int i = 0;i<CATEGORIES;i++)
    {
        for (int j = 0;j<fleetLimit[i];j++)
        {
            fleetAvailability[i][j] = 0;
        }
    }
}

void registerRental()
{
    printf("\n===== CUSTOMER REGISTRATION =====\n");

    printf("Enter customer full name:");
    scanf("%[^\n]",customerNames[customerCount]);

    printf("Enter NIC / Passport number:");
    scanf("%29s",nicPassport[customerCount]);

    printf("Enter driving license number:");
    scanf("%29s",licenseNumber[customerCount]);

    printf("Enter vehical category (1-4):");
    scanf("%d",&selectedCategory[customerCount]);

    printf("Enter rental days:");
    scanf("%d",&rentalDays[customerCount]);

    printf("Include driver?(1=Yes,0=No):");
    scanf("%d",&driverOpted[customerCount]);

}
