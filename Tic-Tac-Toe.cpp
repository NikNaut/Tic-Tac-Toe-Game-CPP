#include <iostream>
#include <ctime>

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main() {
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';

    drawBoard(spaces);

    while (true) {
        playerMove(spaces, player);
        drawBoard(spaces);
        if(checkWinner(spaces, player, computer)) {
            break;
        }
        else if (checkTie(spaces)) {
            break;
        }

        computerMove(spaces, computer);
        drawBoard(spaces);
        if(checkWinner(spaces, player, computer)) {
            break;
        }
        else if (checkTie(spaces)) {
            break;
        }
    }
    std::cout << "Thanks for Playing!";

    return 0;
}

void drawBoard(char *spaces) {
    std::cout << "\n";
    std::cout << "     |     |     " << "\n";
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << "\n";
    std::cout << "_____|_____|_____" << "\n";
    std::cout << "     |     |     " << "\n";
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << "\n";
    std::cout << "_____|_____|_____" << "\n";
    std::cout << "     |     |     " << "\n";
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << "\n";
    std::cout << "     |     |     " << "\n";
}

void playerMove(char *spaces, char player) {
    int num;
    do {
    std::cout << "Enter a spot to place your marker(1-9): ";
    std::cin >> num;
    num--;
    if(spaces[num] == ' ') {
        spaces[num] = player;
        break;
    }
    }while (!(num < 0) || !(num > 8));

}

void computerMove(char *spaces, char computer) {
    srand(time(0));
    
    while(true) {
        int num = rand() % 9;
        if (spaces[num] == ' ') {
            spaces[num] = computer;
            break;
        }
    }
}

bool checkWinner(char *spaces, char player, char computer) {
    if ((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])) {
        spaces[0] == player ? std::cout << "You Win!\n" : std::cout << "You Lose!\n";
    }
    else if ((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])) {
        spaces[3] == player ? std::cout << "You Win!\n" : std::cout << "You Lose!\n";
    }
    else if ((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])) {
        spaces[6] == player ? std::cout << "You Win!\n" : std::cout << "You Lose!\n";
    }
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])) {
        spaces[0] == player ? std::cout << "You Win!\n" : std::cout << "You Lose!\n";
    }
    else if ((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])) {
        spaces[1] == player ? std::cout << "You Win!\n" : std::cout << "You Lose!\n";
    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])) {
        spaces[2] == player ? std::cout << "You Win!\n" : std::cout << "You Lose!\n";
    }
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])) {
        spaces[0] == player ? std::cout << "You Win!\n" : std::cout << "You Lose!\n";
    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])) {
        spaces[2] == player ? std::cout << "You Win!\n" : std::cout << "You Lose!\n";
    }
    else {
        return false;
    }
    return true;
}

bool checkTie(char *spaces) {
    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' '){
            return false;
        }
    }
    std::cout << "It's a Draw!\n";
    return true; 
}