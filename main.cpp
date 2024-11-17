//
//  Created by Hailia Sommerville on 11/17/24.
// c++ terminiology hangman

#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    
    string words[] = {"VECTORS", "ALGORITHM", "STACKOVERFLOW", "DECLARATION", "RECURSION", "VARIABLE", "COMPILER"};
    string guessed = "";
    string hangmanProgress = "_______";
    const string hangmanCheck = "HANGMAN";
    
    const int hangman = 7;
    int wrongGuesses= 0;
    
    int arraySize = sizeof(words) / sizeof(words[0]);
    int randomIndex = rand() % arraySize; //randomize array subscript
    string word = words[randomIndex];
    
    while (wrongGuesses < hangman){
        cout << "\nWord: ";
        bool wordCompleted = true;
        
        for (char c : word){
            if (guessed.find(c) != string::npos){
                cout << c ;
            }
            else{
                cout << "_ ";
                wordCompleted = false;
            }
            
        }
        
        if (wordCompleted){
            cout << "\nCongrats champ!";
            return 0;
        }
        cout << "\n ✗_✗ : " << hangmanProgress;
        cout << "\nGuesses remaining: " << (hangman - wrongGuesses);
        
        cout << "\nEnter a letter: ";
        char guess;
        cin >> guess;
        guess = toupper(guess);
        
        if (guessed.find(guess) != string::npos){
            cout << "You already guessed that letter!\n";
            continue;
        }
        guessed += guess;
        
        if (word.find(guess) == string::npos) {
            hangmanProgress[wrongGuesses] = hangmanCheck[wrongGuesses];
            wrongGuesses++;
            }
        }
    
    
    cout << "\n✗_✗ : " << hangmanProgress;
    cout << "\nGood Game! The word was: " << word << endl;
        
        
    
        
    return 0;
}
