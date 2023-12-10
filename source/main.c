#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAXCASE 15

void showCases(long int a[15], int isOpen[15]);

int main(){
   long int a[MAXCASE]={0,1,5,10,50,100,500,750,1000,5000,
      10000,25000,50000,75000,100000};
   long int bankerOffer;
   int isOpen[16];
   int remainingCase,choice,mainBriefcase,toChoose;
   char chchoice;

   int i,j,deal,roundNum,sum,temp,youWon;

   for(i=0;i<MAXCASE;i++) {
      isOpen[i]=0;
   }

   srand(time(NULL));
   for(i=15;i>0;--i) {  //randomize the briefcase values
      j = rand() % (MAXCASE-1)+1;
      temp = a[j];
      a[j] = a[i];
      a[i] = temp;
   }
   printf("\n");
   for(i=1;i<MAXCASE;i++ )
      printf("%7d ",a[i]);
   printf("\n");

   printf("LET'S PLAY. . .\n");
   printf("\n*********************");
   printf("\n****    DEAL    *****");
   printf("\n****     OR     *****");
   printf("\n****   NO DEAL  *****");
   printf("\n*********************\n\n");

   printf("\nSo what's your main briefcase? ");
   scanf("%d",&mainBriefcase);
   isOpen[mainBriefcase]=1;

   printf("You have chosen your briefcase.\n\n");
   printf("Press any key to continue...\n");
   _getch();

   bankerOffer=0;
   roundNum=0;
   deal=0;
   toChoose=6;
   remainingCase=MAXCASE-2;
   youWon=0;
   while (remainingCase != 0 && deal == 0) {
      printf("Welcome to round %d of Deal or No Deal\n",++roundNum);
      for(i=0;i<toChoose;i++) {
         printf("\nChoose your next briefcase to open: ");
         scanf("%d",&choice);
         printf("\nPlease open briefcase number %d: $%ld dollars\n",choice,a[choice]);
         isOpen[choice]=1; //0=not opened, 1=opened
         showCases(a,isOpen);
      }
      remainingCase-=toChoose;
      --toChoose;
      printf("Now we'll see what the banker will offer. Here's the phone call now\a\a\a\n");
      sum=0;
      for(i=1,j=0;i<MAXCASE;i++) {
         if(isOpen[i]==0)
            sum+=a[i];
            j++;
      }
      bankerOffer = sum/j;
      printf("\nBanker is offering: $%ld dollars\n",bankerOffer);
      printf("Now the question to you is: Deal, or No Deal [y/n]: ");
      scanf(" %c",&chchoice);
      getchar();
      if(chchoice=='y' || chchoice=='Y') {
         deal=1;
         youWon=bankerOffer;
      }
   }

   printf("Thanks for playing Deal or No Deal ");
   if(deal==0) {
      printf("You won %ld", bankerOffer);
   }
   else {
      printf("You won : %ld", a[mainBriefcase]);
   }
   printf("\nPrint Any Key to Continue\n");
   _getch();


   return(0);
}
void showCases(long int a[MAXCASE], int isOpen[MAXCASE]) {
   int i;
   printf("\n\n");
   for(i=1;i<MAXCASE;i++) {
      if(isOpen[i]==0) {
         printf("[ %2d ] ",i);
         printf("%7ld                ",a[i]);
      }
      else {
         printf("[ %2d ]                        ",i);
      }
      if(i%2==0)
         printf("\n");
   }
}
