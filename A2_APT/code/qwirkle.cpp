
#include "LinkedList.h"
#include "GameEngine.h"

#include <iostream>

#define EXIT_SUCCESS      0
#define NUMBER_OF_PLAYERS 2
#define MAX_LENGTH        26
#define MAX_WIDTH         26

void mainMenu();
void printMenu();
void menuSelect(char input);
void newGame();
void loadGame();
void showInfo();
void quit();

bool exitProgram = false;

int main(void) {
  // LinkedList* list = new LinkedList();
  // delete list;
   
   std::cout << "Welcome to Qwirkle!" << std::endl << std::endl;
   while(!exitProgram){
       mainMenu();
   }

   return EXIT_SUCCESS;
}

void mainMenu(){

   printMenu();

   //use this bool to determine if the user has input a valid option
   bool validInput = false;
   char input = '0';
   //while the user hasnt input a valid option

   while(!validInput){
       std::cout << "> ";
       std::cin >> input;
       if(input == '1' || input == '2' || input == '3' || input == '4'){
           validInput = true;
           std::cout << std::endl;
           menuSelect(input);
       }
       else{
           std::cout << "Invalid Input" << std::endl;
       }
   }
}

void printMenu(){

    std::cout << "Menu\n";
    std::cout << "----\n";
    std::cout << "1. New Game\n";
    std::cout << "2. Load Game\n";
    std::cout << "3. Show student information\n";
    std::cout << "4. Quit\n";

}

void menuSelect(char input){
    if(input == '1'){
        newGame();
    }
    else if (input == '2'){
        loadGame();
    }
    else if (input == '3'){
        showInfo();
    }
    else{
        quit();
    }
}

void newGame(){
    //TO DO
    bool validName = false;
    std::string playerNames[NUMBER_OF_PLAYERS] = {"", ""};
    std::regex nameFormat("^[a-zA-Z]+");
    std::cout << "Starting A New Game\n\n";
    for(int i = 0; i < NUMBER_OF_PLAYERS; i++){
        std::cout << "Enter a name for player " << i + 1 << "\n";
        while(!validName){
            std::cout << ">";
            std::cin >> playerNames[i];
            if(std::regex_match(playerNames[i], nameFormat)){
                validName = true;
            }
            else{
                std::cout << "Only letters allowed \n";
            }
        }
        validName = false;
    }
    std::cout << std::endl;
    std::cout << "Let's Play\n";
    //These are just test values to be changed with the real objects
    std::string bag = "I'm a bag";
    TilePtr** board = new TilePtr*[MAX_LENGTH];
    for(int i = 0; i < MAX_LENGTH; ++i)
            board[i] = new TilePtr[MAX_WIDTH];
    TilePtr*** boardPtr = &board;
    //changes ALL values to nullptr
    for(int i = 0; i < MAX_WIDTH; i++){
        for(int j = 0; j < MAX_LENGTH; j++){
            board[i][j] = nullptr;
        }
    }
    std::cout << "test2\n";
    //make the whole board nullptr
    GameEngine* gameEnginePtr = new GameEngine(playerNames[0],playerNames[1] , boardPtr, bag);
    gameEnginePtr->newGame();
    delete gameEnginePtr;
    //loop through to delete?
    delete board;

    
}

void loadGame(){
    //TO DO
    std::string fileName = "";
    std::cout << "Enter the filename you wish to load" << "\n" << ">";
    std::cin >> fileName;
}

void showInfo(){
    //TO DO
    std::cout << "--------------------------------\n";
    std::cout << "Name: Duy Nguyen\n";
    std::cout << "Student ID: s3429599\n";
    std::cout << "Email: s3429599@student.rmit.edu.au\n\n";
    std::cout << "Name: Justin Cooper\n";
    std::cout << "Student ID: s3720189\n";
    std::cout << "Email: s3720189@student.rmit.edu.au\n\n";
    std::cout << "Name: Koby Gean\n";
    std::cout << "Student ID: s3681583\n";
    std::cout << "Email: s3681583@student.rmit.edu.au\n\n";
    std::cout << "Name: Jack Kelly\n";
    std::cout << "Student ID: s3707748\n";
    std::cout << "Email: s3707748@student.rmit.edu.au\n\n";
    std::cout << "--------------------------------\n\n";
}

void quit(){
    //TO DO
    std::cout << "smell ya later" << "\n";
    exitProgram = true;
}
