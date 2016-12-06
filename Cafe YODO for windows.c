#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*#define BOLDYELLOW  "\033[1m\033[33m"
#define BOLDBLUE    "\033[1m\033[34m"
#define BOLDMAGENTA "\033[1m\033[35m"
#define BOLDCYAN    "\033[1m\033[36m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDRED     "\033[1m\033[31m"
#define BOLDBLACK   "\033[1m\033[30m"
#define BOLDWHITE   "\033[1m\033[37m"
#define green   "\033[32m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define RESET   "\033[0m"
#define maxSize 50*/
int COUNT = 0;
int GROSSTOTAL = 0;
double VAT = 0.00;
double SERVICE_CHARGE = 0.00;
double NET_TOTAL = 0.00;

typedef struct StackItemsName
{
        char *name;
        struct StackItemsName *Stackaddress;
        int sizeOfstack;

}stackitemsname;


stackitemsname *HeadOfStack = NULL;
void push(char *value)
{

        stackitemsname *entry = (stackitemsname*)malloc(sizeof(stackitemsname));
        if (HeadOfStack==NULL) entry->sizeOfstack = -1;
        entry->name = value;
        entry->sizeOfstack++;
        entry->Stackaddress = HeadOfStack;
        HeadOfStack = entry;

}
char *CodeOfItems(int itemsCode)
{
        if(itemsCode==11) return "Burger              ";
        else if(itemsCode==12) return "Chicken Pizza       ";
        else if(itemsCode==13) return "Fried Chicken Bucket";
        else if(itemsCode==14) return "Grilled Chicken     ";
        else if(itemsCode==15) return "Noodles             ";
        else if(itemsCode==16) return "Pasta               ";
        else if(itemsCode==17) return "Oreo Shake          ";
        else if(itemsCode==18) return "Cold Coffee         ";
        else if(itemsCode==19) return "Cappuccino          ";
        else if(itemsCode==20) return "Coke                ";
        else if(itemsCode==21) return "Singara             ";
        else if(itemsCode==22) return "Somusa              ";
        else return 0;

}
char *top()
{
        if (HeadOfStack != NULL)
                return HeadOfStack->name;
        else
                return NULL;
}
void pop()
{
        stackitemsname *theStack;
        theStack = HeadOfStack;
        if (theStack != NULL)
        {
                stackitemsname *tmp = theStack;
                theStack = theStack->Stackaddress;
                free(tmp);
                theStack->sizeOfstack--;
                HeadOfStack = theStack;

        }
}


//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//

typedef struct CustomerName
{
        char CustomerName[50];
        struct CustomerName *next;

}name;
name *headOfCustomerName=NULL;
typedef struct NodeTaka
{
        int QTY;
        int TotalPrice;
        char CustomerName[50];
        struct NodeTaka *itemsAddress;
}nodeTaka;

nodeTaka *HeadOfNodeTaka = NULL;
nodeTaka *TailOfNodeTaka = NULL;

int EnterBillInLinkedList(int InTotalTaka,int quantity)
{
        nodeTaka *newnode = (nodeTaka*)malloc(sizeof(nodeTaka));

        newnode->QTY = quantity;
        newnode->TotalPrice = InTotalTaka*quantity;
        newnode->itemsAddress = HeadOfNodeTaka;
        HeadOfNodeTaka = newnode;

        if(TailOfNodeTaka==NULL) TailOfNodeTaka = HeadOfNodeTaka;
        return 0;

}
void Print()
{
        nodeTaka *temp = HeadOfNodeTaka;

        while(temp!=NULL)
        {
                printf("%d\t\t",temp->QTY);

                printf("%s\t\t",top());


                printf("%d\n",temp->TotalPrice);
                GROSSTOTAL += temp->TotalPrice;
                VAT = (GROSSTOTAL*15)/100;
                SERVICE_CHARGE = (GROSSTOTAL*5)/100;
                NET_TOTAL= GROSSTOTAL+VAT+SERVICE_CHARGE;
                temp = temp->itemsAddress;
                if(COUNT>=2) pop();
                COUNT--;

        }

}

int order()
{
        name names[50];

        int numberOfItems,itemsCode,quantity,InTotalTaka;
        int sizeOfItem;


        char *NameOfitemSet;

        printf("Enter your name: ");
        scanf("%s",names->CustomerName);
        getchar();


        names->next = NULL;
        headOfCustomerName = names;
        printf ("Number of items want to order:  ");
        scanf ("%d", &numberOfItems);
        COUNT += numberOfItems;


        while (numberOfItems--) {
                printf ("Enter chosen item code: ");
                scanf ("%d", &itemsCode);
                getchar();


                NameOfitemSet = CodeOfItems(itemsCode);
                push(NameOfitemSet);

                switch (itemsCode) {
                case 11:
                        printf ("Enter the size of burger. Enter 1 for 200gm / 2 for 300gm : ");

                        scanf ("%d", &sizeOfItem);

                        if(sizeOfItem==1) InTotalTaka = 130;
                        else if(sizeOfItem==2) InTotalTaka = 180;


                        printf ("Please enter the quantity: ");
                        scanf ("%d", &quantity);
                        printf("\n\n");



                        EnterBillInLinkedList(InTotalTaka,quantity);
                        break;

                case 12:
                        printf ("Enter the size of Chicken Pizza. Enter 1 for 12inch / 2 for 14inch / 3 for 16inch : ");

                        scanf ("%d",&sizeOfItem);

                        if(sizeOfItem==1) InTotalTaka = 750;
                        else if(sizeOfItem==2) InTotalTaka = 975;
                        else if(sizeOfItem==3) InTotalTaka = 1250;

                        printf ("Please enter the quantity: ");
                        scanf ("%d", &quantity);
                        printf("\n\n");


                        EnterBillInLinkedList(InTotalTaka,quantity);

                        break;

                case 13:
                        printf ("Enter the amount of fried chicken Buckety. Enter 1 for 1 pcs / 2 for 4 pcs / 3 for 10 pcs : ");

                        scanf ("%d", &sizeOfItem);


                        if(sizeOfItem==1) InTotalTaka = 85;
                        else if(sizeOfItem==2) InTotalTaka = 320;
                        else if(sizeOfItem==3) InTotalTaka = 790;

                        printf ("Please enter the quantity: ");
                        scanf ("%d", &quantity);
                        printf("\n\n");


                        EnterBillInLinkedList(InTotalTaka,quantity);
                        break;

                case 14:
                        printf ("Enter the size of grilled chicken. Enter 1 for quarter / 2 for half / 3 for full : ");

                        scanf ("%d", &sizeOfItem);

                        if(sizeOfItem==1) InTotalTaka = 70;
                        else if(sizeOfItem==2) InTotalTaka = 140;
                        else if(sizeOfItem==3) InTotalTaka = 250;

                        printf ("Please enter the quantity: ");
                        scanf ("%d", &quantity);
                        printf("\n\n");


                        EnterBillInLinkedList(InTotalTaka,quantity);
                        break;

                case 15:
                        printf ("Enter the size of Noodles. Enter 1 for half / 2 for full : ");

                        scanf ("%d", &sizeOfItem);

                        if(sizeOfItem==1) InTotalTaka = 130;
                        else if(sizeOfItem==2) InTotalTaka = 250;

                        printf ("Please enter the quantity: ");
                        scanf ("%d", &quantity);
                        printf("\n\n");


                        EnterBillInLinkedList(InTotalTaka,quantity);

                        break;

                case 16:
                        printf ("Enter the size of pasta. 1 for half / 2 for full : ");

                        scanf ("%d", &sizeOfItem);

                        if(sizeOfItem==1) InTotalTaka =  120;
                        else if(sizeOfItem==2) InTotalTaka = 240;

                        printf ("Please enter the quantity: ");
                        scanf ("%d", &quantity);
                        printf("\n\n");


                        EnterBillInLinkedList(InTotalTaka,quantity);
                        break;

                case 17:
                        printf ("250 ml of OREO SHAKE.\n\n");
                        InTotalTaka = 180;
                        printf ("Please enter the quantity: ");
                        scanf ("%d", &quantity);
                        printf("\n\n");


                        EnterBillInLinkedList(InTotalTaka,quantity);
                        break;

                case 18:
                        printf ("250 ml of COLD COFFEE.\n\n");
                        InTotalTaka = 65;
                        printf ("Please enter the quantity: ");
                        scanf ("%d", &quantity);
                        printf("\n\n");


                        EnterBillInLinkedList(InTotalTaka,quantity);
                        break;

                case 19:
                        printf ("250 ml of CAPPUCCINO.\n\n");
                        InTotalTaka = 70;
                        printf ("Please enter the quantity: ");
                        scanf ("%d", &quantity);
                        printf("\n\n");


                        EnterBillInLinkedList(InTotalTaka,quantity);

                        break;

                case 20:
                        printf ("Enter the size of Coke. 1 for 250ml / 2 for 500ml : ");
                        scanf ("%d", &sizeOfItem);


                        if(sizeOfItem==1) InTotalTaka = 20;
                        else if(sizeOfItem==2) InTotalTaka =35;

                        printf ("Please enter the quantity: ");
                        scanf ("%d", &quantity);
                        printf("\n\n");


                        EnterBillInLinkedList(InTotalTaka,quantity);
                        break;

                case 21:
                        printf ("SINGARA.\n\n");
                        printf ("Please enter the quantity: ");
                        scanf ("%d",&quantity);
                        printf("\n\n");

                        InTotalTaka = 10;


                        EnterBillInLinkedList(InTotalTaka,quantity);
                        break;

                case 22:
                        printf("SOMUSA.\n\n");
                        printf("Please enter the quantity: ");
                        scanf("%d",&quantity);
                        printf("\n\n");

                        InTotalTaka = 10;


                        EnterBillInLinkedList(InTotalTaka,quantity);
                        break;

                }
        }


}
void DisplayBill()
{
        nodeTaka names[50];

        srand(time(NULL));
        int r = rand();

        printf("\n\n                              CAFE YODO\n");
        printf("                           ROAD=45,PLOT=33\n");
        printf("                        RAYERBAG-4,DHAKA-9999\n");
        printf("               PHONE#01911223344,029992244,01522667799\n\n");

        printf("INVOICE NO- 38789\n");
        printf("Vat Reg: 181211011556\n");
        printf("MUSAK-00(KHA)\n\n");

        printf("Customer Name: ");
        printf("%s\n",headOfCustomerName->CustomerName);

        printf("Bill Number: ");
        printf("%d\n",r/100);

        char randomletter = 'A' + (rand()%26);
        printf("TABLE: ");
        printf("%c\n",randomletter);

        printf("DATE: ");
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        printf("%d-%d-%d\n",tm.tm_mday,tm.tm_mon + 1,tm.tm_year+1900);

        printf("-------------------------------------------------------\n");
        printf("QTY\t\t");
        printf("ITEM NAME\t\t\t");
        printf("TOTAL PRICE\n");

        Print();


        printf("-----------------------------------------------------\n");
        printf("GROSS TOTAL:\t\t\t\t\t%d\n",GROSSTOTAL);

        printf("-----------------------------------------------------\n");
        printf("VAT 15%%:   \t\t\t\t\t%.2lf\n",VAT);
        printf("SERVICE CHARGE 5%%:\t\t\t\t%.2lf\n",SERVICE_CHARGE);

        printf("-----------------------------------------------------\n");
        printf("NET TOTAL:   \t\t\t\t\t%.2lf\n\n\n",NET_TOTAL);
        printf("-----------------------------------------------------\n");
        printf("-----------------------------------------------------\n");






}
void DisplayItems ()
{
        printf("--------------------------------------------------------------------------------\n\n");
        printf("ITEM  CODE#  ");
        printf("NAME                       ");
        printf("SIZE                       ");
        printf("PRICE(tk)\n\n");
        printf("[11]");
        printf("---------Burger---------------------200/300gm------------------130/180\n");
        printf("[12]");
        printf("---------Chicken Pizza--------------12/14/16inch---------------750/975/1250\n");
        printf("[13]");
        printf("---------Fried Chicken Bucket-------1/4/10pcs------------------85/320/790\n");
        printf("[14]");
        printf("---------Grilled Chicken------------quarter/half/full----------70/140/250\n");
        printf("[15]");
        printf("---------Noodles--------------------Half/Full------------------130/250\n");
        printf("[16]");
        printf("---------Pasta----------------------Half/Full------------------120/240\n");
        printf("[17]");
        printf("---------Oreo Shake-----------------250ml----------------------180\n");
        printf("[18]");
        printf("---------Cold Coffee----------------250ml----------------------65\n");
        printf("[19]");
        printf("---------Cappuccino-----------------250ml----------------------70\n");
        printf("[20]");
        printf("---------Coke-----------------------250/500ml------------------20/30\n");
        printf("[21]");
        printf("---------Singara--------------------1/2/3pcs-------------------10/Per Piece\n");
        printf("[22]");
        printf("---------Somusa---------------------1/2/3pcs-------------------10/Per Piece\n\n");
        order();
}
int main (int argc, char const *argv[])
{

    printf ("    ____   ___  ______ _____  __   _____________ _____  \n");
printf ("   / __ \\ / _ \\ |  ___|  ___| \\ \\ / /  _  |  _  \\  _  | \n");
printf ("  | /  \\// /_\\ \\| |_  | |__    \\ V /| | | | | | | | | | \n");
printf ("  | |    |  _  ||  _| |  __|    \\ / | | | | | | | | | | \n");
printf ("  | \\__/\| | | || |   | |___    | | \\ \\_/ / |/ /\\ \\_/ / \n");
printf ("   \\____/\\_| |_/\\_|   \\____/    \\_/  \\___/|___/  \\___/  \n");





        while (1) {
                printf ("1. Order\n2. Bill\n3. Exit the program\n");
                printf("ENTER 1 or 2 or 3: ");

                int in;
                scanf ("%d", &in);
                getchar ();
                switch (in) {
                case 1: {
                        DisplayItems();
                        break;
                }
                case 2: {
                        DisplayBill();
                        HeadOfNodeTaka = NULL;
                        HeadOfStack = NULL;
                        COUNT=0;
                        GROSSTOTAL=0;
                        VAT = 0.00;
                        SERVICE_CHARGE = 0.00;
                        NET_TOTAL = 0.00;

                        break;
                }
                case 3: {
                          system("COLOR 3");

                        printf ("          We are closed come by again\n\n");
                        printf ("  Project submitted by Ashik Ahamed Aman Rafat\n\n");
                        printf ("  My hearty gratitude to honorable teacher\n\n");
                        printf ("           Seraj Al Mahmud Mostafa       \n");
                        return 0;
                }
                }
        }
        return 0;
}
