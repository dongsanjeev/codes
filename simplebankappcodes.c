#include<stdio.h>

void login();
void menu();
void Balancecheck();
void withdraw();
void deposit();
void proceed();
void write(int n);
int read();

void main()
{
    login();
}
void proceed()
{
    char ch;
    printf("\nDo you want to continue? Press Y to continue.....\nPress N to quit......\n");
    scanf(" %c",&ch);
    if((ch=='Y')||(ch=='y'))
    {
        menu();
    }
    else if((ch=='N')||(ch=='n'))
    {
        exit(0);
    }
    else{
        proceed();
    }
}
void deposit()
{
    int d;
    int n=read();
    system("cls");
    printf("Enter the amount you want to deposit= ");
    scanf("%d",&d);
    if(d<50000)
    {
       n=n+d;
       printf("\nDeposited amount= %d\n",d);
       printf("Total Amount=%d",n);
       write(n);
    }
    else{
        printf("Amount more than 50000 cannot be deposited at once!\nplease try again with lower amount\n");
        deposit();
    }
}
void withdraw()
{
    int w;
    int n=read();
    system("cls");
    printf("Enter the amount you want to withdraw= ");
    scanf("%d",&w);
    if(w<=n)
    {


     if(w%500==0)
         {
         if(w<=30000)
           {
             n=n-w;
             printf("Withdrawn Amount=%d\n",w);
             printf("Total Balance=%d",n);
             write(n);
            }
         else{
            printf("Amount above 30000 cannot be withdrawn at once!\nPlease try Again!\n");
            withdraw();
             }
         }
     else {
        printf("\nAmount divisible by 500 can only be withdrawn!\nPlease try again bicth!\n");
        withdraw();
        }
     }
     else{
        printf("\nInsufficient Balance!\nPlease try again!");
        withdraw();
     }
}
void Balancecheck()
{
    printf("\nYour Balance is %d\n",read());
}
int read()
{
    int n;
    FILE *fp;
    fp=fopen("balance.txt","r");
    if(fp==NULL){
        printf("\nFile not found!");
        exit(0);
    }
    while(fscanf(fp,"%d",&n)==1);
    fclose(fp);
    return n;
}
void write(int n)
{
    FILE *fp;
    fp=fopen("balance.txt","a");
    fprintf(fp,"\n%d",n);
    fclose(fp);
}
void menu()
{
    int n;
    system("cls");
    printf("\nPress:: \n1.Balance Check\n2.Balance Withdraw\n3.Balance Deposit\n4.Exit\nChoose:: ");
    scanf("%d",&n);
    switch(n)
    {
 case 1:Balancecheck();
    break;
 case 2:withdraw();
    break;
 case 3:deposit();
    break;
    case 4:exit(0);
    break;
    default:printf("\nInvalid Option!\nTry again bicth!\n");
    menu();
    }
    proceed();
}
void login()
{
    char user[100],pass[100];
    printf("Enter your username= ");
    gets(user);
    printf("\nEnter your password= ");
    gets(pass);
    if(strcmp(user, "admin")==0)
    {
        if(strcmp(pass, "123")==0)
        {
            menu();
        }
        else{
                system("cls");
            printf("\nYour password or username is incorrect!\n");
        }
    }

    else{
            system("cls");
        printf("\nUsername is incorrect! please try again!\n");
        login();
    }
}

