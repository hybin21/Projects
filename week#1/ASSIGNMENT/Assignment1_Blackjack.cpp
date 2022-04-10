/******************************************************************
 * AUTHOR    : Jessica
 * LAB #00   : Assignment 1: Blackjack
 * CLASS     : CS003A
 * SECTION   : 32276
 * DUE DATE  : 01/19/2021
******************************************************************/
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

/******************************************************************
 *Assignment 1: BlackjackLab 2 - CS 002 Review - Arrays - Histogram
 *_________________________________________________________________
 * <description>
 * This program is a single-player version of the BlackJack
 *_________________________________________________________________
 * INPUTS:
 *  int playerBet: the amount of the player's bet
 *  int draw: user's choice to draw a card or not
 *  int play: user's chocie to play another game or not
 * OUTPUTS:
 *  int playerTotal: the user's total score
 *  int dealerTotal: the dealer's total score
 *  int betTotal: the money that user has to play a game
******************************************************************/

const int SEED_VALUE = 333;                                                                                                     // constant variable for the seed value
const string CARD_RANK[] = {"Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};        // constant variable for the card rank
const string CARD_SUIT[] = {"Spades","Clubs","Diamonds","Hearts"};                                                              // constant variable for the card suit

// FUNCTION PROTOTYPES
/******************************************************************
 * Name: getBet(int betTotal)
 * Description: Gets the bet amount from the user
 * Returns: Returns the amount of bet 
******************************************************************/
int getBet(int betTotal);                                                       // IN - the total of users's bet   

/******************************************************************
 * Name: askDraw(void)
 * Description: Asks the user to draw a card
 * Returns: Returns the number corresponding to the user's choice
******************************************************************/
int askDraw(void);                                                              

/******************************************************************
 * Name: playAgain(void)
 * Description: Asks user to play again 
 * Returns: Returns the number corresponding to the user's choice
******************************************************************/
int playAgain(void); 

/******************************************************************
 * Name: draw_card(string &card, int drawer_points)
 * Description: Draws a card using a random number generator
 * Returns: Returns the point from the card
******************************************************************/       
int draw_card(string &card,                                                     // IN - card value
             int drawer_points);                                                // IN - user's current point

/******************************************************************
 * Name: getSuit(int suit)
 * Description: Converts the int(suit) to name of the suit
 * Returns: Returns the name of the suit
******************************************************************/
string getSuit(int suit);                                                       // IN - random generated number from 0 to 3

/******************************************************************
 * Name: getRank(int rank)
 * Description: Converts the int(rank) to name of the rank
 * Returns: Returns the name of the rank
******************************************************************/
string getRank(int rank);                                                       // IN - random generated number from 0 to 12

/******************************************************************
 * Name: assing_card(string &card, int& playerTotal)
 * Description: Draws a card and calculates the total of the player 
 * Returns: Returns the name of the card and player's total
******************************************************************/
void assign_card(string &card,                                                  // CALC&OUT - card value
                 int& playerTotal);                                             // CALC&OUT - Output of the player's total calculation

int main(void)
{
    string card;                                                                // CALC&OUT: Output of the name of card
    int gainPoint;                                                              // CACL&OUT: Output of the point that player/dealer gets
    int playerTotal;                                                            // CALC&OUT: Output of the sum of player's points
    int dealerTotal;                                                            // CALC&OUT: Output of the sum of dealer's points
    int betTotal;                                                               // CALC&OUT: Output of the money that user has to play the game
    int playerBet;                                                              // IN: User inputs the amount to bet
    int draw;                                                                   // IN: User inptus to draw a card
    int drawCount;                                                              // CALC&OUT: Output of the couting for the number of draws
    int count;                                                                  // CALC&OUT: Output of the number of user playing game
    int play;                                                                   // IN: User inputs to play another game

    srand(SEED_VALUE);
    draw = 1;
    play = 1;
    count = 0;
    betTotal = 100;
    playerTotal = 0;
    dealerTotal = 0;
    
    // PROCESSING -- play games until user choses to play or the money is in a range(0-$1000)
    while(betTotal > 0 && betTotal <= 1000 && play == 1)                    
    {
        drawCount = 0;

        // INPUT -- User enters the bet amount
        playerBet = getBet(betTotal);       
        cout << "Your cards are: \n";
        playerTotal = 0;
        count++;
        for(int i = 0; i < 2; i++)
        {
            // PROCESSING -- draw a card
            assign_card(card, playerTotal);
            drawCount++;
        }

        // PROCESSING -- when it's the first round
        if(count == 1)
            cout << endl << endl;
        else
        {
            cout << "Your total is "<< playerTotal << ". ";

            // PROCESSING - player can draw a card until its total is less than 21
            while(playerTotal <= 21)
            {
                draw = askDraw();
                drawCount++;

                // PROCESSING -- player choses to contintue the game
                if(draw == 1)
                {
                    cout << "You draw a: \n";
                    assign_card(card, playerTotal);
                    drawCount++;
                    cout << "Your total is "<< playerTotal << ". ";
                }
                // PROCESSING -- player choses to stop sthe game
                else if(draw == 2)
                {
                    cout << endl << endl;
                    // PROCESSING -- finish the game
                    break;
                }
            }
        }
        
        // PROCESSING -- when player total is exceeds 21, player busted
        if(playerTotal > 21)
        {
            cout << "You busted!\n";
            betTotal -= playerBet;
            play = playAgain();
        }
        else
        {   
            dealerTotal = 0;
            
            // PROCESSING -- dealer opend its card
            cout << "The dealer's cards are: \n";
            for(int i = 0; i < 2; i++)
                assign_card(card,dealerTotal);

            cout << "The dealer's total is "<< dealerTotal << ".\n";
            
            // PROCESSING -- dealer continue drawing a card if the total is less than 17 
            while(dealerTotal <= 16 && drawCount - 2 > 0)
            {
                cout << "The dealer draws a card.\n";
                assign_card(card,dealerTotal);
                drawCount--;
                if(dealerTotal > 16 || drawCount - 2 == 0)
                    cout << "The dealer's total is "<< dealerTotal << ".\n";
            }

            // PROCESSING -- when player's total is closer to 21 than dealer's  
            if(21 - dealerTotal > 21 - playerTotal)
            {
                cout << "You win $" << playerBet << ".\n";
                betTotal += playerBet;
            }
            
            //  PROCESSING -- when dealer's total is closer to 21 than player's
            else if(21 - dealerTotal < 21 - playerTotal)
            {
                cout << "You lose $" << playerBet << ".\n";
                betTotal -= playerBet;
            }
            // PROCESSING -- when their total is the same 
            else if(21 - dealerTotal == 21 - playerTotal)
                cout << "A draw! You get back your $"<< playerBet << ".\n";
            play = playAgain();
        }
    }
    
    return 0;
}

/******************************************************************
 * getBet(int betTotal)
 *_________________________________________________________________
 * This function gets the bet anmount from the user
 *  - returns the bet from the user
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   int betTotal: the money that user has so far
 *
 * POSTCONDITIONS:
 *  int newBet: the bet amount that user input
******************************************************************/
int getBet(int betTotal)                                                        // IN: the total of users's bet 
{
    int newBet;                                                                 // INPUT: the user's bet amount for new round

    // INPUT: get the bet amount from the user
    cout << "You have $" << betTotal << ". Enter bet: ";
    cin >> newBet;

    return newBet;
}

/******************************************************************
 * askDraw(void)
 *_________________________________________________________________
 * This function asks the user to draw a card
 *  - returns the correspoinding number to user's choice
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   N/A
 *
 * POSTCONDITIONS:
 *  the program draws or not draw another card
******************************************************************/
int askDraw(void)
{
    char yesOrNo;                                                                  // INPUT: the user's choice to draw another card

    // INPUT: user decides to draw another card
    cout << "Do you want another card (y/n)? ";
    cin >> yesOrNo;
    if(yesOrNo == 'y')
        return 1;
    else if(yesOrNo == 'n')
        return 2;
    else
        return 0;
}


/******************************************************************
 * playAgain(void)
 *_________________________________________________________________
 * This function asks the user to play another game
 *  - returns the corresponding number to user's choice
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   N/A
 *
 * POSTCONDITIONS:
 *  the program stops or continues the game
******************************************************************/
int playAgain(void)
{
    char yesOrNo;                                                                      //INPUT: the user's choice to continue the game

    // INPUT: asks the user to continue the game
    cout << "\nPlay again? (y/n): ";
    cin >> yesOrNo;
    if(yesOrNo == 'y')
        return 1;
    else if(yesOrNo == 'n')
        return 2;
    else
        return 0;
}

/******************************************************************
 * getSuit(int suit)
 *_________________________________________________________________
 * This function converts the int from random generater to its name
 *  - returns the name of the suit
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   int suit: the output of the random generated number from 0 to 3
 *
 * POSTCONDITIONS:
 *  string cardSuit: the name of the suit
******************************************************************/
string getSuit(int suit)                                                                // INPUT: the suit numebr from drawing the card
{
    string cardSuit;

    // PROCESSING -- find the correspoinding name from the CARD_SUIT 
    cardSuit = CARD_SUIT[suit];
    return cardSuit;
}

/******************************************************************
 * getRank(int rank)
 *_________________________________________________________________
 * This function converts the suit number to its name
 *  - returns the name of the rank
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   int rank: the output of the random generated number from 0 to 12
 *
 * POSTCONDITIONS:
 *  string cardRank: the name of the rank
******************************************************************/
string getRank(int rank)                                                                // INPUT: the rank number from drawing the card
{
    string cardRank;

    // PROCESSING -- find the corresponding name from the CARD_RANK
    cardRank = CARD_RANK[rank];
    return cardRank;
}

/******************************************************************
 * draw_card(string &card, int drawer_points)
 *_________________________________________________________________
 * This function uses two random number generators to draw a card
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   string &card: the string version of the card value(suit and rank)
 *   int drawer_points: the drawer's ponts to decide the value of ACE
 *
 * POSTCONDITIONS:
 *  int point: the point that drawer gets from the card
******************************************************************/
int draw_card(string &card, int drawer_points)
{
    int cardRank,                                                                       // CALC&OUT: random number for the rank
         cardSuit,                                                                      // CALC&OUT: random number for the suit 
         point;                                                                         // CALC&OUT: the point that user earns from the card

    cardRank = rand()%13;
    cardSuit = rand()%4;

    // PROCESSING -- add the rank and suit together
    card += getRank(cardRank) + " of " + getSuit(cardSuit);

    // PROCESSING -- when the card rank is Ace
    if(cardRank == 0)
    {
        // PROCESSING -- decide the point for the ace
        if(drawer_points + 11 > 21)
            return 1;
        else
            return 11;
    }

    // PROCESSING -- when the card rank is Jack, Queen, and King
    if(cardRank == 10 || cardRank == 11 || cardRank == 12)
        return 10;

    // PROCESSING -- since the random number starts from 0, should add 1
    point = cardRank +1; 
    return point;
}

/******************************************************************
 * assing_card(string &card, int& playerTotal)
 *_________________________________________________________________
 * This function assigns a card for the player anc calculate the total
 *  - returns the card value in string and the total score 
 *_________________________________________________________________
 * PRECONDITIONS:
 *  The following needs previous defined values:
 *   int& playertotal: player's total
 *   string &card: card's name
 *
 * POSTCONDITIONS:
 *  string &card: drawn card's name
 *  int& playerTotal: player's total score after drawing the card
******************************************************************/
void assign_card(string &card,                                                          // CALC&OUT: name of the card                      
                int& playerTotal)                                                       // CALC&OUT: Output of the player's total calculation
{
    int gainPoint;

    // PROCESSING -- draw a card for the drawer
    gainPoint = draw_card(card,playerTotal);
    cout << "  " << card << endl;
    card.clear();

    // PROCESSING -- calculate the total score
    playerTotal += gainPoint;
}