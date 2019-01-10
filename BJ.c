#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
//Random suit generator
//Should randomly pick a number between 0..3
int randomSuit ()
{
    int x; //variable for random number
    //seed random function
    srand(time(NULL));
    //generate number
    x = rand() % 4;
    // return random number
    return x;
    
}
//random card gnerator
//shuld randomly pick a number between 0..12
int randomCard()
{
    int x; //variable for random number
    //seed random function
    srand(time(NULL));
    //generate number and store in x
    x = rand() % 13;
    //return random number
    return x;
}
// numbers to strings
// should print suit corresponding strings
void suitToString(int suit)
{
    char suitName [21]; //variable for suit string
    // if random number is 0...
    if(suit == 0)
    {
        //print hearts
        printf("Hearts");
    }
    // if random number is 1...
    else if(suit == 1)
    {
        //print diamonds
        printf("Diamonds");
    }
    // if random number is 2...
    else if( suit == 2)
    {
        // print spades
        printf("Spades");
    }
    // if random number is 3...
    else if (suit == 3)
    {
        // print clubs
        printf("Clubs");
    }
    else
    {
        //error has occured
        printf("ERROR(1)!!!");
    }
    
    
}
//card to string
//should print card corresponding strings
void cardToString(int card)
{
    //if random nuber is a 0
    if (card == 0)
    {
        printf("Two");
    }
    //if random number is 1
    else if (card == 1)
    {
        printf("Three");
    }
    //if random number is 2
    else if (card == 2)
    {
        printf("Four");
    }
    // if random number is 3
    else if (card == 3)
    {
        printf("Five");
    }
    //if random number is four
    else if (card == 4)
    {
        printf("Six");
    }
    //if random number is 5
    else if ( card == 5)
    {
        printf("Seven");
    }
    //if random number is 6
    else if (card == 6)
    {
        printf("Eight");
    }
    //if random number is 7
    else if (card == 7)
    {
        printf("Nine");
    }
    //if random number is 8
    else if (card == 8)
    {
        printf("Ten");
    }
    // if random number is 9
    else if( card == 9)
    {
        printf("Jack");
    }
    //if random number is 10
    else if ( card == 10)
    {
        printf("Queen");
    }
    //if random number is 11
    else if (card == 11)
    {
        printf("King");
    }
    //if random number is 12
    else if (card == 12)
    {
        printf("Ace");
    }
    //error has occured
    else
    {
        printf("\n\n\nERROR(2)\n\n\n");
    }                   
}
// card value calculator
int cardValueCalc (int card)
{
    //variable for enter key
    char tmp;
    //variable for card value
    int x;
    // if the card is less than 7 than the value is the random number plus 2
    if (card <= 7)
    {
        x = card +2;
        return x;
    }
    //if the card is in between 12 and 7, the value is 10
    else if((12 > card)&& (card > 7))
    {
        return 10;
    }
    // if the card is an ace, two values are possible and the user gets to choose
    else if(card == 12)
    {
        
        while (1==1)
        {
            //ask the user for the value
            printf("Would you like your ace to be a 1 or an 11 : ");
            //stre the value into x
            scanf("%d",&x);
            //get rid of the enter input
            scanf("%c", &tmp);
            // if the user enters a correct value, break out of the loop
            if((x == 1) || (x == 11))
            {
                break;
            }
            // if user enters an incorrect value, inform them and loop through again
            else
            {
                printf("%d is an incorrect value. \n", x);
            }
            
        }
        //return the user's choice
        return x;
    }    
}
//player turn
int playerTurn(int firstCard, int secondCard, int suit, int card, int suit2, int card2)
{
    //value for standard two cards
    int initialValue;
    //variable for user;s answer
    char* answer;
    //set the initial value from the first two cards
    initialValue =firstCard + secondCard;
    //to start loop we need answer to start at 'h'
    answer = 'h';
    //temporary vaiable for enter input
    char* tmp;
    // vaiable for new card
    int newCard;
    // new random card and suit vairables
    int nSuit =1 ;
    int nCard =1 ;
    //variables to help with loop
    int tmpS =1;
    int tmpC =1;
    //check to see if answer is correct input
    while(answer == 'h' || answer != 's')
    {
        //tell user there value so they can decide whether to stay or hit
        printf("Your card value as of right now is %d.", initialValue);
        //if they hit 21, return
        if(initialValue == 21)
        {
            return 0;
        }    
        //ask the user uf they would like to stay or hit
        printf("Would you like another card (enter h) or would you like to stay(enter s)?  ");
        //scan the answer in and get rid of the enter input
        scanf("%c", &answer);
        scanf("%c", &tmp);
        //if answer is incorrect tell them and should go to beginning of loop
        if(answer != 'h' && answer != 's')
        {
            printf("\nError!! Incorrect input!!\n");
        }
        // if they want to hit 
        if (answer == 'h')
        {
            // make a new card but we don't want any repeat cards
            while((nCard == card && nSuit == suit) || (nCard == card2 && nSuit == suit2) || (nCard == tmpC && nSuit == tmpS))
            {   
                
                nCard = randomCard();
                nSuit = randomSuit();
                
            }
            //let the user know their new card and print if out
            printf("Your next card  is a ");
            cardToString(nCard);
            printf(" of ");
            suitToString(nSuit);
            printf("\n");
            cardPrinter(nCard, nSuit);
            newCard = cardValueCalc(nCard);
            
            
            // update the value
            initialValue = initialValue + newCard;
            // if their new value equal 21 return
            if (initialValue == 21)
            {
                return 0;
            }
            // if their new value is greater than 21 return
            if (initialValue > 21)
            {
                return 1;
            }     
            //continue through the loop
        }
        // stroe the card so that we don't get repeats
        tmpC = nCard;
        tmpS = nSuit;
    }
    //return card value
    return initialValue;  
}     
// card number printer
void cardPrinter( int card, int suit)
{
    int i;
    char numDisplay [26];
    int k;
    char suitDisplay[46];
    if (card ==0)
    {
        numDisplay[0] = ' ';
        numDisplay[1] = '$';
        numDisplay[2] = '$';
        numDisplay[3] = '$';
        numDisplay[4] = ' ';
        numDisplay[5]= ' ';
        numDisplay[6] = ' ';
        numDisplay[7] = ' ';
        numDisplay[8] = '$';
        numDisplay[9] = ' ';
        numDisplay[10] = ' ';
        numDisplay[11] ='$';
        numDisplay[12] = '$';
        numDisplay[13] = '$';
        numDisplay [14] = ' ';
        numDisplay [15] = ' ';
        numDisplay[16] = '$';
        numDisplay[17] = ' ';
        numDisplay[18] = ' ';
        numDisplay[19] = ' ';
        numDisplay[20] = ' ';
        numDisplay[21] = '$';
        numDisplay[22] = '$';
        numDisplay[23] = '$';
        numDisplay[24] = ' ';
        numDisplay[25] = 0;
    }
    else if(card ==1)
    {
        numDisplay[0] = ' ';
        numDisplay[1] = '$';
        numDisplay[2] = '$';
        numDisplay[3] = '$';
        numDisplay[4] = ' ';
        numDisplay[5]= ' ';
        numDisplay[6] = ' ';
        numDisplay[7] = ' ';
        numDisplay[8] = '$';
        numDisplay[9] = ' ';
        numDisplay[10] = ' ';
        numDisplay[11] ='$';
        numDisplay[12] = '$';
        numDisplay[13] = '$';
        numDisplay [14] = ' ';
        numDisplay [15] = ' ';
        numDisplay[16] = ' ';
        numDisplay[17] = ' ';
        numDisplay[18] = '$';
        numDisplay[19] = ' ';
        numDisplay[20] = ' ';
        numDisplay[21] = '$';
        numDisplay[22] = '$';
        numDisplay[23] = '$';
        numDisplay[24] = ' ';
        numDisplay[25] = 0;
    }
    else if(card ==2)
    {
        numDisplay[0] = ' ';
        numDisplay[1] = '$';
        numDisplay[2] = ' ';
        numDisplay[3] = '$';
        numDisplay[4] = ' ';
        numDisplay[5]= ' ';
        numDisplay[6] = '$';
        numDisplay[7] = ' ';
        numDisplay[8] = '$';
        numDisplay[9] = ' ';
        numDisplay[10] = ' ';
        numDisplay[11] ='$';
        numDisplay[12] = '$';
        numDisplay[13] = '$';
        numDisplay [14] = ' ';
        numDisplay [15] = ' ';
        numDisplay[16] = ' ';
        numDisplay[17] = ' ';
        numDisplay[18] = '$';
        numDisplay[19] = ' ';
        numDisplay[20] = ' ';
        numDisplay[21] = ' ';
        numDisplay[22] = ' ';
        numDisplay[23] = '$';
        numDisplay[24] = ' ';
        numDisplay[25] = 0;
    }
    else if (card == 3)
    {
        numDisplay[0] = ' ';
        numDisplay[1] = '$';
        numDisplay[2] = '$';
        numDisplay[3] = '$';
        numDisplay[4] = ' ';
        numDisplay[5]= ' ';
        numDisplay[6] = '$';
        numDisplay[7] = ' ';
        numDisplay[8] = ' ';
        numDisplay[9] = ' ';
        numDisplay[10] = ' ';
        numDisplay[11] ='$';
        numDisplay[12] = '$';
        numDisplay[13] = '$';
        numDisplay [14] = ' ';
        numDisplay [15] = ' ';
        numDisplay[16] = ' ';
        numDisplay[17] = ' ';
        numDisplay[18] = '$';
        numDisplay[19] = ' ';
        numDisplay[20] = ' ';
        numDisplay[21] = '$';
        numDisplay[22] = '$';
        numDisplay[23] = '$';
        numDisplay[24] = ' ';
        numDisplay[25] = 0;
    }
    else if (card ==4)
    {
        numDisplay[0] = ' ';
        numDisplay[1] = '$';
        numDisplay[2] = '$';
        numDisplay[3] = '$';
        numDisplay[4] = ' ';
        numDisplay[5]= ' ';
        numDisplay[6] = '$';
        numDisplay[7] = ' ';
        numDisplay[8] = ' ';
        numDisplay[9] = ' ';
        numDisplay[10] = ' ';
        numDisplay[11] ='$';
        numDisplay[12] = '$';
        numDisplay[13] = '$';
        numDisplay [14] = ' ';
        numDisplay [15] = ' ';
        numDisplay[16] = '$';
        numDisplay[17] = ' ';
        numDisplay[18] = '$';
        numDisplay[19] = ' ';
        numDisplay[20] = ' ';
        numDisplay[21] = '$';
        numDisplay[22] = '$';
        numDisplay[23] = '$';
        numDisplay[24] = ' ';
        numDisplay[25] = 0;
    
    }
    else if (card == 5)
    {
        numDisplay[0] = ' ';
        numDisplay[1] = '$';
        numDisplay[2] = '$';
        numDisplay[3] = '$';
        numDisplay[4] = ' ';
        numDisplay[5]= ' ';
        numDisplay[6] = '$';
        numDisplay[7] = ' ';
        numDisplay[8] = '$';
        numDisplay[9] = ' ';
        numDisplay[10] = ' ';
        numDisplay[11] =' ';
        numDisplay[12] = ' ';
        numDisplay[13] = '$';
        numDisplay [14] = ' ';
        numDisplay [15] = ' ';
        numDisplay[16] = ' ';
        numDisplay[17] = ' ';
        numDisplay[18] = '$';
        numDisplay[19] = ' ';
        numDisplay[20] = ' ';
        numDisplay[21] = ' ';
        numDisplay[22] = ' ';
        numDisplay[23] = '$';
        numDisplay[24] = ' ';
        numDisplay[25] = 0;
    }
    else if(card ==6)
    {
        numDisplay[0] = ' ';
        numDisplay[1] = '$';
        numDisplay[2] = '$';
        numDisplay[3] = '$';
        numDisplay[4] = ' ';
        numDisplay[5]= ' ';
        numDisplay[6] = '$';
        numDisplay[7] = ' ';
        numDisplay[8] = '$';
        numDisplay[9] = ' ';
        numDisplay[10] = ' ';
        numDisplay[11] ='$';
        numDisplay[12] = '$';
        numDisplay[13] = '$';
        numDisplay [14] = ' ';
        numDisplay [15] = ' ';
        numDisplay[16] = '$';
        numDisplay[17] = ' ';
        numDisplay[18] = '$';
        numDisplay[19] = ' ';
        numDisplay[20] = ' ';
        numDisplay[21] = '$';
        numDisplay[22] = '$';
        numDisplay[23] = '$';
        numDisplay[24] = ' ';
        numDisplay[25] = 0;
    }
    else if(card == 7)
    {
        numDisplay[0] = ' ';
        numDisplay[1] = '$';
        numDisplay[2] = '$';
        numDisplay[3] = '$';
        numDisplay[4] = ' ';
        numDisplay[5]= ' ';
        numDisplay[6] = '$';
        numDisplay[7] = ' ';
        numDisplay[8] = '$';
        numDisplay[9] = ' ';
        numDisplay[10] = ' ';
        numDisplay[11] ='$';
        numDisplay[12] = '$';
        numDisplay[13] = '$';
        numDisplay [14] = ' ';
        numDisplay [15] = ' ';
        numDisplay[16] = ' ';
        numDisplay[17] = ' ';
        numDisplay[18] = '$';
        numDisplay[19] = ' ';
        numDisplay[20] = ' ';
        numDisplay[21] = '$';
        numDisplay[22] = '$';
        numDisplay[23] = '$';
        numDisplay[24] = ' ';
        numDisplay[25] = 0;
    }
    else if(card == 8)
    {
        numDisplay[0] = '$';
        numDisplay[1] = ' ';
        numDisplay[2] = '$';
        numDisplay[3] = '$';
        numDisplay[4] = '$';
        numDisplay[5]= '$';
        numDisplay[6] = ' ';
        numDisplay[7] = '$';
        numDisplay[8] = ' ';
        numDisplay[9] = '$';
        numDisplay[10] = '$';
        numDisplay[11] =' ';
        numDisplay[12] = '$';
        numDisplay[13] = ' ';
        numDisplay [14] = '$';
        numDisplay [15] = '$';
        numDisplay[16] = ' ';
        numDisplay[17] = '$';
        numDisplay[18] = ' ';
        numDisplay[19] = '$';
        numDisplay[20] = '$';
        numDisplay[21] = ' ';
        numDisplay[22] = '$';
        numDisplay[23] = '$';
        numDisplay[24] = '$';
        numDisplay[25] = 0;
    }
    else if(card ==9)
    {
        numDisplay[0] = '$';
        numDisplay[1] = '$';
        numDisplay[2] = '$';
        numDisplay[3] = '$';
        numDisplay[4] = '$';
        numDisplay[5]= ' ';
        numDisplay[6] = ' ';
        numDisplay[7] = '$';
        numDisplay[8] = ' ';
        numDisplay[9] = ' ';
        numDisplay[10] = ' ';
        numDisplay[11] =' ';
        numDisplay[12] = '$';
        numDisplay[13] = ' ';
        numDisplay [14] = ' ';
        numDisplay [15] = '$';
        numDisplay[16] = ' ';
        numDisplay[17] = '$';
        numDisplay[18] = ' ';
        numDisplay[19] = ' ';
        numDisplay[20] = '$';
        numDisplay[21] = '$';
        numDisplay[22] = '$';
        numDisplay[23] = ' ';
        numDisplay[24] = ' ';
        numDisplay[25] = 0;
    }
    else if(card == 10)
    {
        numDisplay[0] = '$';
        numDisplay[1] = '$';
        numDisplay[2] = '$';
        numDisplay[3] = '$';
        numDisplay[4] = '$';
        numDisplay[5]= '$';
        numDisplay[6] = ' ';
        numDisplay[7] = ' ';
        numDisplay[8] = ' ';
        numDisplay[9] = '$';
        numDisplay[10] = '$';
        numDisplay[11] =' ';
        numDisplay[12] = '$';
        numDisplay[13] = ' ';
        numDisplay [14] = '$';
        numDisplay [15] = '$';
        numDisplay[16] = '$';
        numDisplay[17] = '$';
        numDisplay[18] = '$';
        numDisplay[19] = '$';
        numDisplay[20] = ' ';
        numDisplay[21] = ' ';
        numDisplay[22] = ' ';
        numDisplay[23] = ' ';
        numDisplay[24] = '$';
        numDisplay[25] = 0;
    }
    else if(card == 11)
    {
        numDisplay[0] = '$';
        numDisplay[1] = ' ';
        numDisplay[2] = ' ';
        numDisplay[3] = ' ';
        numDisplay[4] = '$';
        numDisplay[5]= '$';
        numDisplay[6] = ' ';
        numDisplay[7] = ' ';
        numDisplay[8] = '$';
        numDisplay[9] = ' ';
        numDisplay[10] = '$';
        numDisplay[11] ='$';
        numDisplay[12] = ' ';
        numDisplay[13] = ' ';
        numDisplay [14] = ' ';
        numDisplay [15] = '$';
        numDisplay[16] = ' ';
        numDisplay[17] = ' ';
        numDisplay[18] = '$';
        numDisplay[19] = ' ';
        numDisplay[20] = '$';
        numDisplay[21] = ' ';
        numDisplay[22] = ' ';
        numDisplay[23] = ' ';
        numDisplay[24] = '$';
        numDisplay[25] = 0;
    }
    else if(card == 12)
    {
        numDisplay[0] = '$';
        numDisplay[1] = '$';
        numDisplay[2] = '$';
        numDisplay[3] = '$';
        numDisplay[4] = '$';
        numDisplay[5]= '$';
        numDisplay[6] = ' ';
        numDisplay[7] = ' ';
        numDisplay[8] = ' ';
        numDisplay[9] = '$';
        numDisplay[10] = '$';
        numDisplay[11] ='$';
        numDisplay[12] = '$';
        numDisplay[13] = '$';
        numDisplay [14] = '$';
        numDisplay [15] = '$';
        numDisplay[16] = ' ';
        numDisplay[17] = ' ';
        numDisplay[18] = ' ';
        numDisplay[19] = '$';
        numDisplay[20] = '$';
        numDisplay[21] = ' ';
        numDisplay[22] = ' ';
        numDisplay[23] = ' ';
        numDisplay[24] = '$';
        numDisplay[25] = 0;
    }
    else
    {
        printf("??????ERROR(3)????????????????????");
    }
    if(suit ==0)
    {
        suitDisplay[0] = ' ';
        suitDisplay[1] = '$';
        suitDisplay[2] = '$';
        suitDisplay[3] = ' ';
        suitDisplay[4] = ' ';
        suitDisplay[5] = ' ';
        suitDisplay[6] = '$';
        suitDisplay[7] = '$';
        suitDisplay[8] = ' ';
        suitDisplay[9] = '$';
        suitDisplay[10] = '$';
        suitDisplay[11] = '$';
        suitDisplay[12] = '$';
        suitDisplay[13] = ' ';
        suitDisplay[14] = '$';
        suitDisplay[15] = '$';
        suitDisplay[16] = '$';
        suitDisplay[17] = '$';
        suitDisplay[18] = ' ';
        suitDisplay[19] = '$';
        suitDisplay[20] = '$';
        suitDisplay[21] = '$';
        suitDisplay[22] = '$';
        suitDisplay[23] = '$';
        suitDisplay[24] = '$';
        suitDisplay[25] = '$';
        suitDisplay[26] = ' ';
        suitDisplay[27] = ' ';
        suitDisplay[28] = ' ';
        suitDisplay[29] = '$';
        suitDisplay[30] = '$';
        suitDisplay[31] = '$';
        suitDisplay[32] = '$';
        suitDisplay[33] = '$';
        suitDisplay[34] = ' ';
        suitDisplay[35] = ' ';
        suitDisplay[36] = ' ';
        suitDisplay[37] = ' ';
        suitDisplay[38] = ' ';
        suitDisplay[39] = ' ';
        suitDisplay[40] = '$';
        suitDisplay[41] = ' ';
        suitDisplay[42] = ' ';
        suitDisplay[43] = ' ';
        suitDisplay[44] = ' ';
        suitDisplay[45] = 0; 
        
    }
    else if (suit ==1)
    {
        suitDisplay[0] = ' ';
        suitDisplay[1] = ' ';
        suitDisplay[2] = ' ';
        suitDisplay[3] = ' ';
        suitDisplay[4] = '$';
        suitDisplay[5] = ' ';
        suitDisplay[6] = ' ';
        suitDisplay[7] = ' ';
        suitDisplay[8] = ' ';
        suitDisplay[9] = ' ';
        suitDisplay[10] = ' ';
        suitDisplay[11] = ' ';
        suitDisplay[12] = '$';
        suitDisplay[13] = '$';
        suitDisplay[14] = '$';
        suitDisplay[15] = ' ';
        suitDisplay[16] = ' ';
        suitDisplay[17] = ' ';
        suitDisplay[18] = ' ';
        suitDisplay[19] = ' ';
        suitDisplay[20] = '$';
        suitDisplay[21] = '$';
        suitDisplay[22] = '$';
        suitDisplay[23] = '$';
        suitDisplay[24] = '$';
        suitDisplay[25] = ' ';
        suitDisplay[26] = ' ';
        suitDisplay[27] = ' ';
        suitDisplay[28] = ' ';
        suitDisplay[29] = ' ';
        suitDisplay[30] = '$';
        suitDisplay[31] = '$';
        suitDisplay[32] = '$';
        suitDisplay[33] = ' ';
        suitDisplay[34] = ' ';
        suitDisplay[35] = ' ';
        suitDisplay[36] = ' ';
        suitDisplay[37] = ' ';
        suitDisplay[38] = ' ';
        suitDisplay[39] = ' ';
        suitDisplay[40] = '$';
        suitDisplay[41] = ' ';
        suitDisplay[42] = ' ';
        suitDisplay[43] = ' ';
        suitDisplay[44] = ' ';
        suitDisplay[45] = 0; 
    }
    else if (suit == 2)
    {
        suitDisplay[0] = ' ';
        suitDisplay[1] = ' ';
        suitDisplay[2] = ' ';
        suitDisplay[3] = ' ';
        suitDisplay[4] = '$';
        suitDisplay[5] = ' ';
        suitDisplay[6] = ' ';
        suitDisplay[7] = ' ';
        suitDisplay[8] = ' ';
        suitDisplay[9] = ' ';
        suitDisplay[10] = ' ';
        suitDisplay[11] = ' ';
        suitDisplay[12] = '$';
        suitDisplay[13] = '$';
        suitDisplay[14] = '$';
        suitDisplay[15] = ' ';
        suitDisplay[16] = ' ';
        suitDisplay[17] = ' ';
        suitDisplay[18] = ' ';
        suitDisplay[19] = ' ';
        suitDisplay[20] = '$';
        suitDisplay[21] = ' ';
        suitDisplay[22] = '$';
        suitDisplay[23] = ' ';
        suitDisplay[24] = '$';
        suitDisplay[25] = ' ';
        suitDisplay[26] = ' ';
        suitDisplay[27] = ' ';
        suitDisplay[28] = '$';
        suitDisplay[29] = '$';
        suitDisplay[30] = '$';
        suitDisplay[31] = '$';
        suitDisplay[32] = '$';
        suitDisplay[33] = '$';
        suitDisplay[34] = '$';
        suitDisplay[35] = ' ';
        suitDisplay[36] = ' ';
        suitDisplay[37] = ' ';
        suitDisplay[38] = ' ';
        suitDisplay[39] = ' ';
        suitDisplay[40] = '$';
        suitDisplay[41] = ' ';
        suitDisplay[42] = ' ';
        suitDisplay[43] = ' ';
        suitDisplay[44] = ' ';
        suitDisplay[45] = 0; 
    }
    else if (suit == 3)
    {
        suitDisplay[0] = ' ';
        suitDisplay[1] = ' ';
        suitDisplay[2] = ' ';
        suitDisplay[3] = ' ';
        suitDisplay[4] = '.';
        suitDisplay[5] = ' ';
        suitDisplay[6] = ' ';
        suitDisplay[7] = ' ';
        suitDisplay[8] = ' ';
        suitDisplay[9] = ' ';
        suitDisplay[10] = ' ';
        suitDisplay[11] = ' ';
        suitDisplay[12] = '(';
        suitDisplay[13] = ' ';
        suitDisplay[14] = ')';
        suitDisplay[15] = ' ';
        suitDisplay[16] = ' ';
        suitDisplay[17] = ' ';
        suitDisplay[18] = ' ';
        suitDisplay[19] = ' ';
        suitDisplay[20] = ' ';
        suitDisplay[21] = ' ';
        suitDisplay[22] = ' ';
        suitDisplay[23] = ' ';
        suitDisplay[24] = ' ';
        suitDisplay[25] = ' ';
        suitDisplay[26] = ' ';
        suitDisplay[27] = '(';
        suitDisplay[28] = ' ';
        suitDisplay[29] = ' ';
        suitDisplay[30] = '>';
        suitDisplay[31] = ' ';
        suitDisplay[32] = '<';
        suitDisplay[33] = ' ';
        suitDisplay[34] = ' ';
        suitDisplay[35] = ')';
        suitDisplay[36] = ' ';
        suitDisplay[37] = ' ';
        suitDisplay[38] = ' ';
        suitDisplay[39] = ' ';
        suitDisplay[40] = '|';
        suitDisplay[41] = ' ';
        suitDisplay[42] = ' ';
        suitDisplay[43] = ' ';
        suitDisplay[44] = ' ';
        suitDisplay[45] = 0; 
    }
    else
    {
        printf("ERROR(4)!!\n");
    }
    printf("####################################\n");
    i =0;
    while (i != 25)
    {
        
        
        printf("## %c%c%c%c%c                          ##\n",numDisplay[i],numDisplay[i+1], numDisplay[i+2],numDisplay[i +3], numDisplay[i +4]);
        
        i = i + 5;
    }
    printf("##                                ##\n");
    printf("##                                ##\n");
    printf("##                                ##\n");
    printf("##                                ##\n");
    k = 0;
    while(k != 45)
    {
        printf("##           %c%c%c%c%c%c%c%c%c            ##\n",suitDisplay[k],suitDisplay[k+1],suitDisplay[k+2],suitDisplay[k+3], suitDisplay[k+4], suitDisplay[k+5], suitDisplay[k+6], suitDisplay[k+7], suitDisplay[k+8]);
        k = k + 9;
    }
    printf("##                                ##\n");
    printf("##                                ##\n");
    printf("##                                ##\n");
    printf("##                                ##\n");
    i =0;
    while (i != 25)
    {
        
        
        printf("##                          %c%c%c%c%c ##\n",numDisplay[i],numDisplay[i+1], numDisplay[i+2],numDisplay[i +3], numDisplay[i +4]);
        
        i = i + 5;
    }
    printf("####################################\n");
    
    printf("\n");
}

int main()
{
    //all my variables...
    int suit;
    int card;
    int suit2;
    int card2;
    int cSuit;
    int cCard;
    int cSuit2;
    int cCard2;
    char suitString [21];
    int cardValue1;
    int cardValue2;
    int finalValue;
    int cCardValue1;
    int cCardValue2;
    int cFinalValue;
    int nCCard;
    int nCSuit;
    suit = randomSuit();
    card = randomCard();
    suit2 = randomSuit();
    card2 = randomCard();
    cSuit = randomSuit();
    cCard = randomCard();
    cSuit2 = randomSuit();
    cCard2= randomCard();
    //make sure we don't repeat cards
    while ((suit2 == suit) && (card2 == card))
    {
        suit2 = randomSuit();
        
        card2 = randomCard();
    }
    //let the user know what's going on
    printf("Your first card  is a ");
    cardToString(card);
    printf(" of ");
    suitToString(suit);
    printf("\n");
    cardPrinter(card,suit);
    cardValue1 = cardValueCalc(card);
    printf("Your card's value is: %d \n", cardValue1);
    printf("Your second card is a ");
    cardToString(card2);
    printf(" of ");
    suitToString(suit2);
    printf("\n");
    cardPrinter(card2,suit2);
    cardValue2 = cardValueCalc(card2);
    printf("Your card's value is: %d \n", cardValue2 );
    finalValue =playerTurn(cardValue1, cardValue2, suit, card, suit2, card2);
    // first make sure they haven't won or busted already
    if (finalValue ==0)
    {
        printf("You got 21!! You win!!\n");
        return 0;
    }
    else if (finalValue == 1)
    {
        printf("BUSTED!! You lose!\n");
        return 0;
    }    
    else
    {
        printf("Your final score is %d. Now for the dealer's turn...\n", finalValue);
    }
    //make two new cards for dealer and make sure they aren't repeats
    while ((cSuit == cSuit2) && (cCard == cCard2))
    {
        cSuit2 = randomSuit();
        cCard2= randomCard();
        
        if((cSuit2 == suit && cCard2 == card) || (cSuit2 == suit2 && cCard2 == card2))
        {
            
            cSuit2 = randomSuit();
            cCard2= randomCard();
        }
        if((cSuit == suit && cCard == card) || (cSuit == suit2 && cCard == card2))
        {
            
            cSuit = randomSuit();
            cCard= randomCard();
        }
        
        
    }
    //Let the user know what's going on...
    printf("Dealer's first card  is a ");
    cardToString(cCard);
    printf(" of ");
    suitToString(cSuit);
    printf("\n");
    cCardValue1 = cardValueCalc(cCard);
    printf("Dealer's card's value is: %d \n", cCardValue1);
    printf("Dealer's second card is a ");
    cardToString(cCard2);
    printf(" of ");
    suitToString(cSuit2);
    printf("\n");
    cCardValue2 = cardValueCalc(cCard2);
    printf("Dealer's card's value is: %d \n", cCardValue2 );
    cFinalValue = cCardValue1+ cCardValue2;
    printf("Dealer's value as of right now is %d.\n", cFinalValue);
    //check to make sure dealer hasn't won or busted already
    if(cFinalValue > 21)
        {
            printf("Dealer busts! You win!! \n");
            return 0;
        }
        else if( cFinalValue == 21)
        {
            printf("Dealer hit 21! You lose!\n");
            return 0;
        }
    // the dealer either has to win or bust    
    while( finalValue >= cFinalValue)
    {
        if(finalValue>= cFinalValue)
        {
            nCCard = randomCard();
            nCSuit = randomSuit();
            while((nCCard == cCard && nCSuit == cSuit) || (nCCard == cCard2 && nCSuit == cSuit2))
            {
                nCCard = randomCard();
                nCSuit = randomSuit();
                if((nCCard == card && nCSuit == suit) || nCCard == card2 && nCSuit == suit2)
                {
                    nCCard = randomCard();
                    nCSuit = randomSuit();
                }
            }
        }
        //tell the user what's going on
        printf("Dealer's next card is a ");
        cardToString(nCCard);
        printf(" of ");
        suitToString(nCSuit);
        printf("\n");
        cFinalValue = cFinalValue+cardValueCalc(nCCard); 
        printf("Dealer's value as of right now is %d\n", cFinalValue);
        ////wait for user to win or bust
        if(cFinalValue > 21)
        {
            printf("Dealer busts! You win!! \n");
            return 0;
        }
        else if( cFinalValue == 21)
        {
            printf("Dealer hit 21! You lose!\n");
            return 0;
        }
        
    }
    printf("Dealer's value beats yours! You Lose!\n");
    
    
}

