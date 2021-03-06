#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define BOLDYELLOW  "\033[1m\033[33m"
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
#define maxSize 50
int COUNT = 0;

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
        if(itemsCode==11) return "Burger";
        else if(itemsCode==12) return "Chicken Pizza";
        else if(itemsCode==13) return "Fried Chicken Bucket";
        else if(itemsCode==14) return "Grilled Chicken";
        else if(itemsCode==15) return "Noodles";
        else if(itemsCode==16) return "Pasta";
        else if(itemsCode==17) return "Oreo Shake";
        else if(itemsCode==18) return "Cold Coffee";
        else if(itemsCode==19) return "Cappuccino";
        else if(itemsCode==20) return "Coke";
        else if(itemsCode==21) return "Singara";
        else if(itemsCode==22) return "Somusa";
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
                return 0;
        }
        else return NULL;
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
                printf("%d                ",temp->QTY);

                printf("%s                        ",top());

                printf("%d\n",temp->TotalPrice);
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
        COUNT = numberOfItems;


        while (numberOfItems--) {
                printf ("Enter chosen item code: ");
                scanf ("%d", &itemsCode);
                getchar();

                NameOfitemSet = CodeOfItems(itemsCode);
                push(NameOfitemSet);

                switch (itemsCode) {
                case 11:
                        printf ("Enter the size of burger: 1. 200gm  2. 300gm   ---->");

                        scanf ("%d", &sizeOfItem);

                        if(sizeOfItem==1) InTotalTaka = 130;
                        else if(sizeOfItem==2) InTotalTaka = 180;


                        printf ("Please enter the quantity: ");
                        scanf ("%d", &quantity);



                        EnterBillInLinkedList(InTotalTaka,quantity);
                        break;

                case 12:
                        printf ("Enter the size of Chicken Pizza: 1. 12inch  2. 14inch  3. 16inch   ---->");

                        scanf ("%d",&sizeOfItem);

                        if(sizeOfItem==1) InTotalTaka = 750;
                        else if(sizeOfItem==2) InTotalTaka = 975;
                        else if(sizeOfItem==3) InTotalTaka = 1250;

                        printf ("Please enter the quantity: ");
                        scanf ("%d", &quantity);


                        EnterBillInLinkedList(InTotalTaka,quantity);

                        break;

                case 13:
                        printf ("Enter the amount of fried chicken Buckety: 1. 1 pcs  2. 4 pcs  3. 10 pcs  ---->");

                        scanf ("%d", &sizeOfItem);


                        if(sizeOfItem==1) InTotalTaka = 85;
                        else if(sizeOfItem==2) InTotalTaka = 320;
                        else if(sizeOfItem==3) InTotalTaka = 790;

                        printf ("Please enter the quantity: ");
                        scanf ("%d", &quantity);


                        EnterBillInLinkedList(InTotalTaka,quantity);
                        break;

                case 14:
                        printf ("Enter the size of grilled chicken: 1. quantityarter  2. half  3. full   ---->");

                        scanf ("%d", &sizeOfItem);

                        if(sizeOfItem==1) InTotalTaka = 70;
                        else if(sizeOfItem==2) InTotalTaka = 140;
                        else if(sizeOfItem==3) InTotalTaka = 250;

                        printf ("Please enter the quantity: ");
                        scanf ("%d", &quantity);


                        EnterBillInLinkedList(InTotalTaka,quantity);
                        break;

                case 15:
                        printf ("Enter the size of Noodles: 1. half  2. full   ---->\n");

                        scanf ("%d", &sizeOfItem);

                        if(sizeOfItem==1) InTotalTaka = 130;
                        else if(sizeOfItem==2) InTotalTaka = 250;

                        printf ("Please enter the quantity: ");
                        scanf ("%d", &quantity);


                        EnterBillInLinkedList(InTotalTaka,quantity);

                        break;

                case 16:
                        printf ("Enter the size of pasta: 1. half  2. full   ---->");

                        scanf ("%d", &sizeOfItem);

                        if(sizeOfItem==1) InTotalTaka =  120;
                        else if(sizeOfItem==2) InTotalTaka = 240;

                        printf ("Please enter the quantity: ");
                        scanf ("%d", &quantity);


                        EnterBillInLinkedList(InTotalTaka,quantity);
                        break;

                case 17:
                        printf ("250 ml of OREO SHAKE\n");
                        InTotalTaka = 180;
                        printf ("Please enter the quantity: ");
                        scanf ("%d", &quantity);


                        EnterBillInLinkedList(InTotalTaka,quantity);
                        break;

                case 18:
                        printf ("250 ml of Cold Coffee\n");
                        InTotalTaka = 65;
                        printf ("Please enter the quantity: ");
                        scanf ("%d", &quantity);


                        EnterBillInLinkedList(InTotalTaka,quantity);
                        break;

                case 19:
                        printf ("250 ml of Cappuccino\n");
                        InTotalTaka = 70;
                        printf ("Please enter the quantity: ");
                        scanf ("%d", &quantity);


                        EnterBillInLinkedList(InTotalTaka,quantity);

                        break;

                case 20:
                        printf ("Enter the size of Coke: 1. 250ml  2. 500ml  ---->");
                        scanf ("%d", &sizeOfItem);


                        if(sizeOfItem==1) InTotalTaka = 20;
                        else if(sizeOfItem==2) InTotalTaka =35;

                        printf ("Please enter the quantity: ");
                        scanf ("%d", &quantity);


                        EnterBillInLinkedList(InTotalTaka,quantity);
                        break;

                case 21:
                        printf ("Singara\n");
                        printf ("Please enter the quantity: ");
                        scanf ("%d",&quantity);
                        InTotalTaka = 10;


                        EnterBillInLinkedList(InTotalTaka,quantity);
                        break;

                case 22:
                        printf("Somusa\n");
                        printf("Please enter the quantity: ");
                        scanf("%d",&quantity);

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

        printf(BOLDCYAN "                              CAFE Y O D O\n\n\n"RESET);
        printf(BOLDCYAN "Customer Name: "RESET);

        printf("%s\n",headOfCustomerName->CustomerName);

        printf(BOLDCYAN "Bill Number: "RESET);
        printf("%d\n",r/100000);

        char randomletter = 'A' + (random()%26);
        printf(BOLDCYAN "TABLE: "RESET);
        printf("%c\n",randomletter);

        printf(BOLDCYAN "DATE: "RESET);
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        printf("%d-%d-%d\n",tm.tm_mday,tm.tm_mon + 1,tm.tm_year+1900);

        printf("-------------------------------------------------------\n");
        printf(BOLDCYAN "QTY               "RESET);
        printf(BOLDCYAN "ITEM NAME                         "RESET);
        printf(BOLDCYAN "TOTAL PRICE\n"RESET);

        Print();

        printf("-----------------------------------------------------\n");
        printf("-----------------------------------------------------\n");
        printf(BOLDCYAN "GROSS TOTAL:\n"RESET);
        printf("-----------------------------------------------------\n");
        printf("-----------------------------------------------------\n");
        printf(BOLDCYAN "-VAT\n"RESET);
        printf(BOLDCYAN "SERVICE CHARGE\n"RESET);
        printf("-----------------------------------------------------\n");
        printf("-----------------------------------------------------\n");
        printf(BOLDCYAN "NET TOTAL\n\n\n"RESET);






}
void DisplayItems ()
{
        printf("--------------------------------------------------------------------------------\n\n");
        printf(BOLDMAGENTA "ITEM  CODE#  "RESET);
        printf(BOLDBLUE "NAME                       "RESET);
        printf(BOLDYELLOW "SIZE                       "RESET);
        printf(BOLDCYAN "PRICE(tk)\n\n"RESET);
        printf(green "[11]"RESET);
        printf("---------Burger---------------------200/300gm------------------130/180\n");
        printf(green "[12]"RESET);
        printf("---------Chicken Pizza--------------12/14/16inch---------------750/975/1250\n");
        printf(green "[13]"RESET);
        printf("---------Fried Chicken Bucket-------1/4/10pcs------------------85/320/790\n");
        printf(green "[14]"RESET);
        printf("---------Grilled Chicken------------quarter/half/full----------70/140/250\n");
        printf(green "[15]"RESET);
        printf("---------Noodles--------------------Half/Full------------------130/250\n");
        printf(green "[16]"RESET);
        printf("---------Pasta----------------------Half/Full------------------120/240\n");
        printf(green "[17]"RESET);
        printf("---------Oreo Shake-----------------250ml----------------------180\n");
        printf(green "[18]"RESET);
        printf("---------Cold Coffee----------------250ml----------------------65\n");
        printf(green "[19]"RESET);
        printf("---------Cappuccino-----------------250ml----------------------70\n");
        printf(green "[20]"RESET);
        printf("---------Coke-----------------------250/500ml------------------20/30\n");
        printf(green "[21]"RESET);
        printf("---------Singara--------------------1/2/3pcs-------------------10/Per Piece\n");
        printf(green "[22]"RESET);
        printf("---------Somusa---------------------1/2/3pcs-------------------10/Per Piece\n\n");
        order();
}
int main (int argc, char const *argv[])
{

        printf("  ██████╗ █████╗ ███████╗███████╗\n");
        printf("  ██╔════╝██╔══██╗██╔════╝██╔════╝\n");
        printf("  ██║     ███████║█████╗  █████╗  \n");
        printf("  ██║     ██╔══██║██╔══╝  ██╔══╝  \n");
        printf("  ╚██████╗██║  ██║██║     ███████╗\n");
        printf("  ╚═════╝╚═╝  ╚═╝╚═╝     ╚══════╝\n\n");

        printf("         ██╗   ██╗ ██████╗ ██████╗  ██████╗\n");
        printf("         ╚██╗ ██╔╝██╔═══██╗██╔══██╗██╔═══██╗\n");
        printf("          ╚████╔╝ ██║   ██║██║  ██║██║   ██║\n");
        printf("           ╚██╔╝  ██║   ██║██║  ██║██║   ██║\n");
        printf("            ██║   ╚██████╔╝██████╔╝╚██████╔╝\n");
        printf("            ╚═╝    ╚═════╝ ╚═════╝  ╚═════╝\n\n");


        while (1) {
                printf ("1. Order\n2. Bill\n3. Exit the program\n");

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
                        break;
                }
                case 3: {

                        printf (BOLDBLUE "          We are closed come by again\n\n");
                        printf ("  Project submitted by Ashik Ahamed Aman Rafat\n\n");
                        printf ("  My hearty gratitude to honorable teacher\n\n");
                        printf ("           Seraj Al Mahmud Mostafa       \n"RESET);
                        return 0;
                }
                }
        }
        return 0;
}
