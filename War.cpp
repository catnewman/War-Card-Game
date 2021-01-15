#include <iostream>
#include <string>

using namespace std;

int PlaceCard() {
   //jack-11, queen-12, king-13, ace-14
   int card = rand()%12 + 2;
   return card;
}
//returns true if a player loses
bool PlayerOut(int pNumCards) {
   if (pNumCards >= 0) {
      return false;
   }
   else {
      return true;
   }
}
//returns true if a player wins
bool PlayerWins(int total, int pNumCards) {
   if (pNumCards == total) {
      return true;
   }
   else {
      return false;
   }
}
void CardsEqual(int& player1, int& player2, int& p1NumCards, int& p2NumCards) {
   while(player1==player2) {
      string next;
      cout << "Cards were equal. Type go to place 3 cards face down and then 1 face up: ";
      cin >> next;
      if (next == "go") {
         int numTries = 1;
         player1 = PlaceCard();
         player2 = PlaceCard();
         cout << "Your card is " << player1 << endl;
         cout << "Opponent's card is " << player2 << endl;
         if (player1 > player2) {
            p1NumCards = 1 + p1NumCards + (numTries * 4);
            p2NumCards = p2NumCards - (numTries * 4) - 1;
         }
         else if(player2 > player1) {
            p2NumCards = 1 + p2NumCards + (numTries * 4);
            p1NumCards = p1NumCards - (numTries * 4) - 1;
         }
         numTries = numTries + 1;
      }
   }
}
void PlayGame(int& player1, int& player2, int& p1NumCards, int& p2NumCards, const int& TOTAL_CARDS) {
   while (PlayerWins(TOTAL_CARDS, p1NumCards) == false && PlayerWins(TOTAL_CARDS, p2NumCards) == false) {
         string place;
         cout << "Type go to place a card: ";
         cin >> place;
         if(place == "go") {
            cout << "Your card is " << player1 << endl;
            cout << "Opponent's card is " << player2 << endl;
            if (player1 > player2) {
               p1NumCards = p1NumCards + 1;
               p2NumCards = p2NumCards - 1;
            }
            else if (player2 > player1) {
               p2NumCards = p2NumCards + 1;
               p1NumCards = p1NumCards - 1;
            }
            else if (player1 == player2) {
               CardsEqual(player1, player2, p1NumCards, p2NumCards);
            }
            cout << "You now have " << p1NumCards << " cards " << endl;
            cout << "Opponent now has " << p2NumCards << " cards " << endl;
            cout << " " << endl;
            player1 = PlaceCard();
            player2 = PlaceCard();
         }
      }

}

int main () {
   int player1;
   int player2;
   const int TOTAL_CARDS = 52;
   int p1NumCards = TOTAL_CARDS/2;
   int p2NumCards = TOTAL_CARDS/2;
   player1 = PlaceCard();
   player2 = PlaceCard();
   //Let's user start the game
   string go;
   cout << "Type go to begin game: ";
   cin >> go;
   if (go == "go") {
      PlayGame(player1, player2, p1NumCards, p2NumCards, TOTAL_CARDS);
   }
   else {
      cout << "You did not type go";
   }
   if(PlayerWins(TOTAL_CARDS, p1NumCards) == true && PlayerOut(p2NumCards) == true) {
      cout << "You win!" << endl;
   }
   else {
      cout << "You lose!" << endl;
   }
return 0;
}
