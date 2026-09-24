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
double calculateBill(int category,int days,int driver);
void displayRentalRecords();
void displayFleetStatus();

int main()
{
    initializeFleet();
    displayMenu();

    return 0;

}

void displayMenu()
{
    int choice;

    do
    {
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
            displayRentalRecords();
            break;

          case 3:
            displayFleetStatus();
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

    }while(choice != 6);
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

finalBills[customerCount]=
     calculateBill(selectedCategory[customerCount],
                   rentalDays[customerCount],
                   driverOpted[customerCount]);

printf("\nFinal Amount Payable: %.2f LKR\n",
       finalBills[customerCount]);

customerCount++;
}

double calculateBill(int category,int days,int driver)
{
    double baseFee;
    double driverFee;
    double grossCost;
    double discount;
    double netFee;
    double finalAmount;


    baseFee = days * dailyRate[category - 1];


    if (driver == 1)
    {
        driverFee = days * 3500;
    }
    else
    {
        driverFee = 0;
    }


    grossCost = baseFee + driverFee;


    if (days>=7)
    {
        discount = grossCost *0.12;
    }
    else
    {
        discount=0;
    }

    netFee = grossCost - discount;


    finalAmount =
          netFee + securityDeposit[category - 1];


    return finalAmount;
    }


void displayRentalRecords()
{
    if (customerCount == 0)
    {
     printf("\nNo rental records available.\n");
     return;
    }

    printf("\n========== RENTAL RECORDS ==========\n");

    for (int i = 0;i< customerCount; i++)
    {
        printf("\n------ Rental %d -----\n",i + 1);


        printf("Customer Name           : %s\n",customerNames[i]);
        printf("NIC / Passport          : %s\n",nicPassport[i]);
        printf("Driving License         : %s\n",licenseNumber[i]);
        printf("Vehical Category        : %d\n",selectedCategory[i]);
        printf("Rental Days             : %d\n",rentalDays[i]);


        if (driverOpted[i] == 1)
        {
            printf("Driver Required         : Yes\n");
        }
        else
        {
            printf("Driver Required          : No\n");
        }

        printf("Final Amount            : %.2f LKR\n",finalBills[i]);
    }

    printf("\n=====================================\n");
}


void displayFleetStatus()
{
    int available;
    int rented;

    printf("\n========== FLEET STATUS ==========\n");

    for (int i = 0;i < CATEGORIES; i++)
    {
        available = 0;
        rented = 0;

        for (int j = 0; j < fleetLimit[i];j++)
        {
            if (fleetAvailability[i][j] == 0)
            {
                available++;
            }
            else
            {
                rented++;
            }
        }


        printf("\nCategory %d\n",i + 1);
        printf("Total Vehicals       :%d\n",fleetLimit[i]);
        printf("Available Vehicals   :%d\n",available);
        printf("Rented Vehicals      :%d\n",rented);

    }

   printf("\n=====================================\n");
}
