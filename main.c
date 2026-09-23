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
