#include "conio2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crs.h"

int main()
{
    int i=0,count,k,choice,cCar;
    User *usr;
    int Eresult,carResult;
    gotoxy(35,15);
    textcolor(BLUE);
    printf("Welcome To Car Rental System");
    gotoxy(32,18);
    textcolor(RED);
    printf("**Rent A Car Go Wherever You Need**");
    getch();

    addAdmin();
    while(1)
    {
        clrscr();
        gotoxy(41,2);
        textcolor(LIGHTBLUE);
        printf("Car Rental System");

        for(i = 1; i < 105; i++)
        {
            gotoxy(i,11);
            textcolor(RED);
            printf("*");
        }
        for(i = 1; i < 105; i++)
        {
            gotoxy(i,23);
            textcolor(RED);
            printf("*");
        }

        gotoxy(41,15);
        textcolor(YELLOW);
        printf("1.Admin");

        gotoxy(41,17);
        textcolor(YELLOW);
        printf("2.User");

        gotoxy(41,19);
        textcolor(YELLOW);
        printf("3.Quit");

        gotoxy(41,21);
        textcolor(YELLOW);
        printf("Select your role:");

        do
        {
            scanf("%d",&count);
            k=0;
            if(count==1)
            {
                do
                {
                   usr = getInput();

                   if(usr==NULL)
                        break;
                    else
                    {
                        k=checkUserExist(*usr,"admin");
                    }
                }while(k==0);
                if(k==-1)
                {
                    break;
                }
                if(k==1)
                {
                    gotoxy(1,20);
                    textcolor(WHITE);
                    printf("press any key to continue");
                    _getch();
                    while(1)
                    {
                        clrscr();
                        choice = adminMenu();
                        if(choice == 7)
                            break;
                        switch(choice)
                        {
                        case 1:
                            clrscr();
                            addEmployee();
                            break;
                        case 2:
                            clrscr();
                            addcarDetails();
                            break;
                        case 3:
                            clrscr();
                            viewEmployee();
                            break;
                        case 4:
                            clrscr();
                            showCarDetais();
                            break;
                        case 5:
                            clrscr();
                            Eresult = deleteEMP();
                            gotoxy(33,20);
                            if(Eresult == 0)
                            {
                                textcolor(LIGHTRED);
                                printf("Sorry,No record of given emp found");

                            }
                            else if(Eresult==1)
                            {
                                textcolor(LIGHTGREEN);
                                printf("record delete successfully");

                            }
                            else if(Eresult == 2)
                            {
                                textcolor(LIGHTRED);
                                printf("Error in deletion");

                            }
                            textcolor(WHITE);
                            printf("\n\n press any key to go back");

                            getch();
                            break;
                        case 6:
                            clrscr();
                            carResult = deleteCarModel();
                            gotoxy(33,20);
                            if(carResult == 0)
                            {
                                textcolor(LIGHTRED);
                                printf("Sorry,No record of given emp found");

                            }
                            else if(carResult==1)
                            {
                                textcolor(LIGHTGREEN);
                                printf("record delete successfully");

                            }
                            else if(carResult == 2)
                            {
                                textcolor(LIGHTRED);
                                printf("Error in deletion");

                            }
                            textcolor(WHITE);
                            printf("\n\n press any key to go back");

                            getch();


                            break;
                        default:

                            break;

                        }
                    }

                }

            }
            else if(count==2)
            {

                do
                {
                    usr = getInput();

                        if(usr==NULL)
                            break;
                        else
                        {
                            k=checkUserExist(*usr,"emp");
                        }
                    }while(k==0);
                    if(k==-1)
                    {
                        break;
                    }
                    if(k==1)
                    {
                        gotoxy(1,20);
                        textcolor(WHITE);
                        printf("Press any key to continue");
                        getch();
                        while(1)
                        {
                            clrscr();
                            choice = empMenu();
                            if(choice == 6)
                            {
                                clrscr();
                                break;
                            }
                            switch(choice)
                            {
                                case 1:
                                    clrscr();
                                    int rentresp;
                                    rentresp = rentCar();
                                    if(rentresp==-2)
                                    {
                                        gotoxy(44,9);
                                        textcolor(LIGHTRED);
                                        printf("Sorry! All cars booked. Try later");
                                        getch();
                                    }
                                    else if(rentresp==1)
                                    {
                                       gotoxy(38,18);
                                       textcolor(LIGHTRED);
                                       printf("your booking done!");
                                       getch();
                                    }
                                    else
                                    {
                                       gotoxy(38,18);
                                       textcolor(LIGHTRED);
                                       printf("you did not choose any car");
                                       getch();
                                    }
                                    break;
                                case 2:
                                    clrscr();
                                    bookedCarDetails();
                                    break;
                                case 3:
                                    clrscr();
                                    availCarDetails();
                                    break;
                                case 4:
                                    clrscr();
                                    showCarDetais();
                                    break;
                                case 5:
                                    clrscr();
                                    cCar=cancleCar();
                                    gotoxy(37,25);

                                    if(cCar == 0)
                                    {
                                        textcolor(LIGHTRED);
                                        printf("Sorry,No record of given found");

                                    }
                                    else if(cCar==1)
                                    {
                                        textcolor(LIGHTGREEN);
                                        printf("Booking Cancel ");

                                    }
                                    else if(cCar == 2)
                                    {
                                        textcolor(LIGHTRED);
                                        printf("Error in deletion");

                                    }
                                    textcolor(WHITE);
                                    printf("\n\n press any key to go back");

                                    getch();



                                    break;
                                default:
                                    printf("Incorrect Choice:");

                            }

                        }
                    }
                }
            else if(count==3)
            {
                clrscr();
                gotoxy(42,18);
                textcolor(GREEN);
                printf("Thank you using the app");
                getch();
                exit(0);
            }
            else
            {
               gotoxy(41,25);
                textcolor(RED);
                printf("INVALID CHOICE");
                getch();
                gotoxy(41,25);
                printf("\t\t\t");
                gotoxy(69,16);
                printf("\t\t\t");
                textcolor(WHITE);
            }
        }while(1);

        getch();
    }

    return 0;
}

