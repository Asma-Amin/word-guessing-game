#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>

using namespace std;

class WordBank {
public:
    string getRandomWord(int levelChoice) {
        string easyWords[35] = {
            "dog", "cat", "sun", "pen", "hat",
            "book", "star", "moon", "car", "tree",
            "bat", "fan", "bag", "map",
            "Keys", "fish", "bird", "desk", "lamp", "shoe",
            "box", "wall", "door", "pen","best", "game", "play", "code", "test",
            "love", "life", "work", "time"
        };

        string  mediumWords[30] = {
            "apple", "chair", "banana", "orange", "bottle",
            "camera", "garden", "market", "doctor", "family",
            "friend", "holiday", "vacation", "kitchen", "library",
            "planet", "rocket", "school", "cloud", "pencil", "glasses",
            "phone", "watch", "table", "window", "future"
            "guitar", "piano" , "problem"
        };

        string hardWords[40] = {
            "microscope", "electricity", "dictionary", "telescope", "government",
            "elephant", "umbrella", "hospital", "mountain", "language",
            "programming", "university", "motorcycle", "technology", "calculation",
            "microbiology", "anthropology", "sociology", "literature", "engineering",
            "psychology", "philosophy", "architecture", "astronomy", "geography", "biology",
            "chemistry", "mathematics", "physics", "economics", "cooking", "cartoon", "microwave",
			"computer", "internet", "television", "generation" 
        };

        int index;
        if (levelChoice == 1) {
            index = rand() % 35;
            return easyWords[index];
        } else if (levelChoice == 2) {
            index = rand() % 30;
            return mediumWords[index];
        } else if (levelChoice == 3) {
            index = rand() % 30;
            return hardWords[index];
        }
    }

    static int getMaxAttempts(int levelChoice) {
        if (levelChoice == 1) return 10;
        else if (levelChoice == 2) return 7;
        else if (levelChoice == 3) return 5;
        return 0;
    }
};

class WordGame : public WordBank {
private:
    string wordToGuess;
    string guessedWord;
    int maxAttempts;
    char guessedLetters[26];
    int guessedCount;
    int score;

    string toLower(string str) {
        for (int i = 0; i < str.length(); i++) {
            str[i] = tolower(str[i]);
        }
        return str;
    }

public:
    WordGame() {
        guessedCount = 0;
        score=0;
    }

    void setDifficulty(int levelChoice) {
        wordToGuess = getRandomWord(levelChoice);
        maxAttempts = getMaxAttempts(levelChoice);
        guessedWord = string(wordToGuess.length(), '_');
	    guessedCount = 0;   /* reseting guessed leters and score 
	                               other rounds */
        score=0;
        
    }

    void playGame() {
        int attempts = 0;
        char guess;

        while (attempts < maxAttempts && guessedWord != wordToGuess) {
            cout << "\nWord: " << guessedWord << endl;
            cout << "Guessed Letters: ";
            for (int i = 0; i < guessedCount; i++) {
                cout << guessedLetters[i] << " ";
            }
            cout << "\nGuess a letter: ";
            cin >> guess;
            guess = tolower(guess);

            bool alreadyGuessed = false;
            for (int i = 0; i < guessedCount; i++) {
                if (guessedLetters[i] == guess) {
                    alreadyGuessed = true;
                    break;
                }
            }
            if (alreadyGuessed) {
                cout << "You already guessed that letter!" << endl;
                continue;
            }

            guessedLetters[guessedCount++] = guess;

            bool correct = false;
            for (int i = 0; i < wordToGuess.length(); i++) {
                if (wordToGuess[i] == guess && guessedWord[i] != guess) {
                    guessedWord[i] = guess;
                    correct = true;
                }
            }
            

            if (!correct) {
                attempts++;
                score -= 1;
                cout << "Wrong guess! Attempts lef: " << (maxAttempts - attempts) << "   |  Score: " << score;
                cout << endl;
            } else {
                score += 2;
                cout << "Correct guess!    |  Score: " << score;
                cout << endl;
            }
        }
    
        if (guessedWord == wordToGuess) {
            cout << "\n Congratulations! You guessed the word: " << wordToGuess << endl;
        } else {
            cout << "\n Game Over! The word was: " << wordToGuess << endl;
        }
        cout << " Your final score is: " << score << endl;
    }

};


int main() { int r=0;
    char playAgain;         
    srand(time(0));  // Seed for random generator
    WordGame game;
    int choice;
    do {
    cout<<"\n\t\t\t\t\t-------------------------------" << endl;
    cout << "\t\t\t\t\t===== WORD GUESSING GAME =====  " << endl;
    cout<<"\t\t\t\t\t-------------------------------" << endl;
    do{
    cout << "\n Choose difficulty level:" << endl;
    cout << "\n 1. Easy" << endl;
    cout << " 2. Medium" << endl;
    cout << " 3. Hard" << endl;
    cout << "\n Enter your choice: ";
    cin >> choice;
    cout<<endl;

    if (choice<1 || choice>3) {
        cout << "Invalid choice! Again choose the difficulty level (1-3): ";
        cin >> choice;
    }
    
    system("cls");
    cout<<"\n\t\t\t    Storm your Brain and Win the Score"<<endl<<endl;
}
    while (choice<1 || choice>3);

    game.setDifficulty(choice);
    game.playGame();  


    cout<<" \n Do you want to play again (Y/N): ";
    cin >> playAgain;
    system("cls");
    cout << endl;
    r++;
   } while (playAgain == 'Y' || playAgain == 'y');
   
   cout<<"\n  Rounds played by the user is/are :"<<r<<endl<<endl;

   cout << " \n \t\t\tThank you for playing!" << endl<<endl;
     system("pause");
     cout<<endl<<endl;
}
