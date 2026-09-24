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
    int choice;


    printf("\n=====SMART VEHICAL RENTAL SYSTEM=====\n\n\n");
    printf("1.Register New Rental\n");
    printf("2.Display Rental Records\n");
    printf("3.Display Fleet Status\n");
    printf("4.Sort Rental by Oriority\n");
    printf("5.View reports\n");
    printf("6.Exit\n");

    printf("\nEnter your choice:");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        registerRental();
        break;

    case 2:
        printf("Display Rental Records Selected.\n");
        break;

    case 3:
        printf("Display Fleet Status Selected.\n");
        break;

    case 4:
        printf("Sort Rentals Selected.\n");
        break;

    case 5:
        printf("Report selected.\n");
        break;

    case 6:
        printf("Thank you\n");
        break;

    default:
        printf("Invalid choice!\n");


    }
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

    printf("Enter customer full name:\n");
    scanf(" %49[^\n]",customerNames[customerCount]);

    printf("Enter NIC / Passport number:\n");
    scanf("%29s",nicPassport[customerCount]);

    printf("Enter driving license number:\n");
    scanf("%29s",licenseNumber[customerCount]);
do
{
    printf("Enter vehical category (1-4):\n");
    scanf("%d",&selectedCategory[customerCount]);

    if (selectedCategory[customerCount]<1 ||
        selectedCategory[customerCount]>4)

    {
        printf("Invalid category! Please enter 1-4.\n");

    }

} while (selectedCategory[customerCount]<1 ||
         selectedCategory[customerCount]>4);

do
{
    printf("Enter rental days:\n");
    scanf("%d",&rentalDays[customerCount]);

    if (rentalDays[customerCount]<=0)
    {
        printf("Rental days must be freater than 0.\n");
    }
} while(rentalDays[customerCount] <=0);

do
{
    printf("Include driver?(1=Yes,0=No):\n");
    scanf("%d",&driverOpted[customerCount]);

    if (driverOpted[customerCount]!=0 &&
        driverOpted[customerCount]!=1)

    {
        printf("Invalid option! Enter 1 or 0.\n");
    }


}while (driverOpted[customerCount] !=0 &&
        driverOpted[customerCount] !=1);

int categoryIndex;
int vehicleFound = 0;

categoryIndex = selectedCategory[customerCount] - 1;

for (int i = 0; i < fleetLimit[categoryIndex]; i++)
{
    if (fleetAvailability[categoryIndex][i] == 0)
    {
        fleetAvailability[categoryIndex][i] = 1;
        vehicleFound = 1;

        printf("\nVehicle allocated successfully!\n");
        printf("Vehicle number: %d\n", i + 1);

        break;
    }
}

if (vehicleFound == 0)
{
    printf("\nSorry! No vehicles available in this category.\n");
    return;
}

customerCount++;
}
