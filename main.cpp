#include <iostream>
#include <fstream>
#include "cards.h"
using namespace std;

int main(int argv, char** argc){
  if(argv != 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail()){
    cout << "Could not open file " << argc[1];
    return 1;
  }

  if (cardFile2.fail()){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  // Create two objects of the class you defined 
  // to contain two sets of cards in two input files
  Hand firstPlayer;
  firstPlayer.setPlayerName("Alice");
  Hand secondPlayer;
  secondPlayer.setPlayerName("Bob");

  // Read each file and store cards
  while (getline (cardFile1, line) && (line.length() > 0)){
    firstPlayer.appendCard(line[0], line[2]);
  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
    secondPlayer.appendCard(line[0], line[2]);
  }
  cardFile2.close();

  // Start the game
  int whoseTurnIsIt = 0; // evens mean Alice's turn, odds mean Bob's turn
  while ( firstPlayer.isMatch(secondPlayer) ){ // while there are matching cards left, search for those cards
    if ( whoseTurnIsIt % 2 == 0 ){ // Alice's turn
      firstPlayer.displayMatch(secondPlayer);
      whoseTurnIsIt +=1;
    }
    else { // Bob's turn
      secondPlayer.displayMatch(firstPlayer);
      whoseTurnIsIt +=1;
    }
  }

  cout << endl;
  firstPlayer.printCards();
  cout << endl;
  secondPlayer.printCards();

  return 0;
}