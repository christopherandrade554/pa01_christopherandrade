#include <iostream>
#include "cards.h"
using namespace std;

// Card == overloaded function
bool Hand::Card::operator==(const Card& c){
    if ( (this->suit == c.suit) && (this->rank == c.rank) ){
        return true;
    }
    else {
        return false;
    }
    return false;
}
// Card != overloaded function
bool Hand::Card::operator!=(const Card& c){
    if ( (this->suit != c.suit) || (this->rank != c.rank) ){
        return true;
    }
    else {
        return false;
    }
    return false;
}


/* Hand class functions */
// Constructors
Hand::Hand(){
    this->playerName = "";
    this->firstCard = nullptr;
    this->lastCard = nullptr;
}
Hand::Hand(string n){
    this->playerName = n;
    this->firstCard = nullptr;
    this->lastCard = nullptr;
}
// Copy Constructor
Hand::Hand(Hand& source){
    if ( !source.firstCard ){ // if source is empty, this Hand should be empty too
        this->playerName = "";
        this->firstCard = nullptr;
        this->lastCard = nullptr;
    }
    else { // else iterate through source, appending each Card to this Hand
        this->playerName = source.playerName;

        Card *c = source.firstCard;
        this->firstCard = nullptr;
        while ( c ){
            this->appendCard(c);
            c = c->nextCard;
        }
    }
}
// Copy Assignment Operator
Hand& Hand::operator=(const Hand& source){
    if ( this == &source ){ // this and source are the same, return *this
        return *this;
    }
    else {
        if ( !this->firstCard ){ // if this not empty, delete elements of this
            this->~Hand();
            this->firstCard = nullptr;
            this->lastCard = nullptr;
            this->playerName = "";
        }
        if ( !source.firstCard ) { // if source is empty, return this (empty)
            return *this;
        }
        else { // this list is empty, copy source to it Card by Card
            this->playerName = source.playerName;
            
            // use currCard as placeholder to iterate through source
            Card *currCard = source.firstCard;
            while ( currCard ){
                this->appendCard(currCard);
                currCard = currCard->nextCard;
            }
        }
    }
    return *this;
}
void Hand::setPlayerName(string n){
    this->playerName = n;
}
void Hand::appendCard(Card *newCard){
    Card *c = new Card;
    c->suit = newCard->suit;
    c->rank = newCard->rank;
    // ignore this: c->rank = this->convertFaceCardValue(newCard->rank);
    c->nextCard = nullptr;

    if ( !this->firstCard ){ // Hand is empty, adding first Card to list
        this->firstCard = c;
        this->lastCard = this->firstCard;
    }
    else { // Update previous Card's next pointer as well as Hand's lastCard pointer
        this->lastCard->nextCard = c;
        this->lastCard = c;
    }
}
void Hand::appendCard(char s, int r){
    Card *c = new Card;
    c->suit = s;
    c->rank = r;
    // ignore this: c->rank = this->convertFaceCardValue(r);
    c->nextCard = nullptr;

    if ( !this->firstCard ){ // Hand is empty, adding first Card to list
        this->firstCard = c;
        this->lastCard = this->firstCard;
    }
    else { // Update previous Card's next pointer as well as Hand's lastCard pointer
        this->lastCard->nextCard = c;
        this->lastCard = c;
    }
}
void Hand::appendCard(char s, char r){
    Card *c = new Card;
    c->suit = s;

    // need to convert char from input file to int because I made the member variable rank and int
    c->rank = this->convertFaceCardValue(r);
    c->nextCard = nullptr;

    if ( !this->firstCard ){ // Hand is empty, adding first Card to list
        this->firstCard = c;
        this->lastCard = this->firstCard;
    }
    else { // Update previous Card's next pointer as well as Hand's lastCard pointer
        this->lastCard->nextCard = c;
        this->lastCard = c;
    }
}
// I know, these are impractical.
int Hand::convertFaceCardValue(char f){
    if ( f == '1' ){
        return 1; // convert to int and return it
    }
    else if ( f == '2' ){
        return 2;
    }
    else if ( f == '3' ){
        return 3;
    }
    else if ( f == '4' ){
        return 4;
    }
    else if ( f == '5' ){
        return 5;
    }
    else if ( f == '6' ){
        return 6;
    }
    else if ( f == '7' ){
        return 7;
    }
    else if ( f == '8' ){
        return 8;
    }
    else if ( f == '9' ){
        return 9;
    }
    else if ( f == '0' ){
        return 10;
    }
    else if ( f == 'j' ){
        return 11;
    }
    else if ( f == 'q' ){
        return 12;
    }
    else if ( f == 'k' ){
        return 13;
    }
    else if ( f == 'a' ){
        return 1;
    }
    else {
        return -1;
    }
}
char Hand::convertValueCardFace(int v){
    if ( v == 1 ){
        return 'a'; // convert to char and return it
    }
    else if ( v == 2 ){
        return '2';
    }
    else if ( v == 3 ){
        return '3';
    }
    else if ( v == 4 ){
        return '4';
    }
    else if ( v == 5 ){
        return '5';
    }
    else if ( v == 6 ){
        return '6';
    }
    else if ( v == 7 ){
        return '7';
    }
    else if ( v == 8 ){
        return '8';
    }
    else if ( v == 9 ){
        return '9';
    }
    else if ( v == 10 ){
        return '0';
    }
    else if ( v == 11 ){
        return 'j';
    }
    else if ( v == 12 ){
        return 'q';
    }
    else if ( v == 13 ){
        return 'k';
    }
    else {
        return '\0';
    }
}
Hand::Card* Hand::getCard(Card *c) const{
    if ( !this->firstCard ){ // Hand is empty, Card is not contained
        return nullptr;
    }
    Card *currCard = this->firstCard;
    // find the card, return it, otherwise return nullptr
    while ( (currCard->rank != c->rank) || (currCard->suit != c->suit) ){
        if ( currCard->nextCard != nullptr ){
            currCard = currCard->nextCard;
        }
        else {
            return nullptr;
        }
    }
    return currCard;
}
Hand::Card* Hand::getCard(char s, int r) const{
    if ( !this->firstCard ){ // Hand is empty, Card is not contained
        return nullptr;
    }

    Card *currCard = this->firstCard;
    // find the card, return it, otherwise return nullptr
    while ( (currCard->rank != r) || (currCard->suit != s) ){
        if ( currCard->nextCard != nullptr ){
            currCard = currCard->nextCard;
        }
        else {
            return nullptr;
        }
    }
    return currCard;
}
Hand::Card* Hand::getPrevCard(Card *c) const{
    if ( !this->firstCard || (this->firstCard == this->lastCard) ){ // Hand is empty, or Hand only contains one Card, no prevCard is contained
        return nullptr;
    }

    Card *currCard = this->firstCard;
    // if nextCard is the Card, then return currCard (because currCard is prevCard of nextCard)
    while ( (currCard->nextCard->rank != c->rank) || (currCard->nextCard->suit != c->suit) ){
        if ( currCard->nextCard->nextCard != nullptr ){
            currCard = currCard->nextCard;
        }
        else {
            return nullptr;
        }
    }
    if ( (currCard->nextCard->rank == c->rank) && (currCard->nextCard->suit == c->suit) ){
        return currCard;
    }
    return nullptr;
}
Hand::Card* Hand::getPrevCard(char s, int r) const{
    if ( !this->firstCard || (this->firstCard == this->lastCard) ){ // Hand is empty, or Hand only contains one Card, no prevCard is contained
        return nullptr;
    }

    Card *currCard = this->firstCard;
    // if nextCard is the Card, then return currCard (because currCard is prevCard of nextCard)
    while ( (currCard->nextCard->rank != r) || (currCard->nextCard->suit != s) ){
        if ( currCard->nextCard->nextCard != nullptr ){
            currCard = currCard->nextCard;
        }
        else {
            return nullptr;
        }
    }
    if ( (currCard->nextCard->rank == r) && (currCard->nextCard->suit == s) ){
        return currCard;
    }
    return nullptr;
}
bool Hand::removeCard(Card *c){
    Card *cardToRemove = this->getCard(c);
    if ( cardToRemove ){ // if cardToRemove exists, delete it
        if ( this->firstCard == cardToRemove && this->lastCard == cardToRemove ){ // only one card in Hand, reset firstCard and LastCard
            this->firstCard = nullptr;
            this->lastCard = nullptr;
            delete cardToRemove;
        }
        else if ( this->firstCard == cardToRemove ){ // firstCard is cardToRemove
            this->firstCard = cardToRemove->nextCard;
            delete cardToRemove;
        }
        else if ( this->lastCard == cardToRemove ){ // lastCard is cardToRemove
            Card *prevCard = this->getPrevCard(c);
            prevCard->nextCard = nullptr;
            this->lastCard = prevCard;
            delete cardToRemove;
        }
        else { // cardToRemove is somewhere in the middle of the Hand (ie not firstCard or lastCard)
            Card *prevCard = this->getPrevCard(c);
            prevCard->nextCard = cardToRemove->nextCard;
            delete cardToRemove;
        }
        return true;
    }
    return false;
}
bool Hand::removeCard(char s, int r){
Card *cardToRemove = this->getCard(s, r);
    if ( cardToRemove ){ // if cardToRemove exists, delete it
        if ( this->firstCard == cardToRemove && this->lastCard == cardToRemove ){ // only one card in Hand, reset firstCard and LastCard
            this->firstCard = nullptr;
            this->lastCard = nullptr;
            delete cardToRemove;
        }
        else if ( this->firstCard == cardToRemove ){ // firstCard is cardToRemove
            this->firstCard = cardToRemove->nextCard;
            delete cardToRemove;
        }
        else if ( this->lastCard == cardToRemove ){ // lastCard is cardToRemove
            Card *prevCard = this->getPrevCard(s, r);
            this->lastCard = prevCard;
            delete cardToRemove;
            prevCard->nextCard = nullptr;
        }
        else { // cardToRemove is somewhere in the middle of the Hand (ie not firstCard or lastCard)
            Card *prevCard = this->getPrevCard(s, r);
            prevCard->nextCard = cardToRemove->nextCard;
            delete cardToRemove;
        }
        return true;
    }
    return false;
}
bool Hand::displayMatch(Hand& source){
    Card *c = this->firstCard;
    while ( c ){
        Card *possibleMatch = source.getCard(c);
        // getCard either returns the matching card or it returns nullptr if it is not found
        // Thus, if ( possibleMatch ) evaluates to true if possibleMatch is found
        if ( possibleMatch ){
            // If within this branch, then possibleMatch is in fact a match with c
            // Print the match, then remove matching Card from each player's Hand
            this->printMatch(source, c);
            this->removeCard(c);
            source.removeCard(possibleMatch);
            return true;
        }
        else {
            c = c->nextCard;
        }
    }

    return false;
}
bool Hand::isMatch(Hand& source){
    Card *c = this->firstCard;
    while ( c ){
        Card *possibleMatch = source.getCard(c);
        // getCard either returns the matching card or it returns nullptr if it is not found
        // Thus, if ( possibleMatch ) evaluates to true if possibleMatch is found
        if ( possibleMatch ){
            return true;
        }
        else {
            c = c->nextCard;
        }
    }
    return false;
}
void Hand::printMatch(Hand& source, Card *match){
    // Must convert int member variable back to char (ex. 13 -> 'k')
    char cardVal = convertValueCardFace(match->rank);
    cout << playerName << " picked matching card " << match->suit << " " << cardVal << endl;
}
void Hand::printCards(){
    cout << playerName << "'s cards:" << endl;
    Card *c = this->firstCard;

    while ( c ){
        char cardVal = convertValueCardFace(c->rank);
        cout << c->suit << " " << cardVal << endl;
        c = c->nextCard;
    }
}
bool Hand::isEmpty(){
    if ( !this->firstCard ){
        return true;
    }
    return false;
}
Hand::~Hand(){
    this->playerName = "";
    Card *currCard = this->firstCard;
    while ( currCard ){
        Card *cardToDelete = currCard;
        currCard = currCard->nextCard;
        delete cardToDelete;
    }
    this->firstCard = nullptr;
}









/* Can Ignore these member functions */

void Hand::insertCard(Card *newCard){
    Card *c = new Card;
    c->suit = newCard->suit;
    c->rank = newCard->rank;
    c->nextCard = nullptr;

    if ( !this->firstCard ){ // Hand is empty, adding first Card to list
        this->firstCard = c;
        this->lastCard = this->firstCard;
    }
    else if ( c->rank >= this->lastCard->rank ){ // Hand is not empty and newCard is highest value, insert at end of list
        this->lastCard->nextCard = c;
        this->lastCard = c;
    }
    else if ( c->rank <= this->firstCard->rank ){ // Hand is not empty and newCard is lowest value, insert at beginning of list
        c->nextCard = this->firstCard;
        this->firstCard = c;
    }
    else { // Hand not empty and newCard is to be inserted in middle of Hand somewhere (ie no neec to update firstCard or lastCard)
        // Find place to be inserted
        Card *currCard = this->firstCard;
        while ( currCard ){
            if ( (c->rank > currCard->rank && c->rank) <= (currCard->nextCard->rank) ){ // location found, insert newCard
                c->nextCard = currCard->nextCard;
                currCard->nextCard = c;
                currCard = nullptr;
            }
            else {
                currCard = currCard->nextCard;
            }
        }
    }
}
void Hand::insertCard(char s, int r){
    Card *c = new Card;
    c->suit = s;
    c->rank = r;
    c->nextCard = nullptr;

    if ( !this->firstCard ){ // Hand is empty, adding first Card to list
        this->firstCard = c;
        this->lastCard = this->firstCard;
    }
    else if ( c->rank >= this->lastCard->rank ){ // Hand is not empty and newCard is highest value, insert at end of list
        this->lastCard->nextCard = c;
        this->lastCard = c;
    }
    else if ( c->rank <= this->firstCard->rank ){ // Hand is not empty and newCard is lowest value, insert at beginning of list
        c->nextCard = this->firstCard;
        this->firstCard = c;
    }
    else { // Hand not empty and newCard is to be inserted in middle of Hand somewhere (ie no neec to update firstCard or lastCard)
        // Find place to be inserted
        Card *currCard = this->firstCard;
        while ( currCard ){
            if ( (c->rank > currCard->rank) && (c->rank <= currCard->nextCard->rank) ){ // location found, insert newCard
                c->nextCard = currCard->nextCard;
                currCard->nextCard = c;
                currCard = nullptr;
            }
            else {
                currCard = currCard->nextCard;
            }
        }
    }
}
string Hand::getPlayerName() const{
    return playerName;
}
int Hand::getRank() const{
    return this->firstCard->rank;
}
char Hand::getSuit() const{
    return this->firstCard->suit;
}
Hand::Card* Hand::getNextCard() const{
    return this->firstCard->nextCard;
}