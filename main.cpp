#include <iostream>

bool gameFinished (char field[][3]) {
    for (int i = 0; i < 3; i++) {
        if ((field[i][0] == 'X' && (field[i][0] == field[i][2] && field[i][2] == field[i][1])) 
        || (field[0][i] == 'X' && (field[0][i] == field[2][i] && field[2][i] == field[1][i]))
        || (field[1][1] == 'X' && ((field[0][0] == field[1][1] && field[1][1] == field[2][2]) 
                                || (field[0][2] == field[1][1] && field[1][1] == field[2][0])))) {
            std::cout << "Game Over! Winner: Player 1st" << std::endl;
            return true;
        } else if ((field[i][0] == 'O' && (field[i][0] == field[i][2] && field[i][2] == field[i][1])) 
                || (field[0][i] == 'O' && (field[0][i] == field[2][i] && field[2][i] == field[1][i]))
                || (field[1][1] == 'O' && ((field[0][0] == field[1][1] && field[1][1] == field[2][2]) 
                                || (field[0][2] == field[1][1] && field[1][1] == field[2][0])))) {
            std::cout << "Game Over! Winner: Player 2nd" << std::endl;
            return true;
        }
    }
    return false;
}

int main() {
    // 14.6.2
    char field[3][3];
    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 3; k++) {
            field[i][k] = ' ';
        }
    }
    bool gameOver = false;
    int counter = 0;
    while (!gameOver) {
        if (counter % 2 == 0) {
            std::cout << "Player 1st turn:\n";
        } else {
            std::cout << "Player 2nd turn:\n";
        }
        int row, column;
        bool correctInput = false;
        while(!correctInput) {
            std::cin >> row >> column;
            if (row > -1 && row < 3 && column > -1 && column < 3 && field[row][column] == ' ') {
                correctInput = true;
                field[row][column] = (counter % 2 == 0 ? 'X' : 'O');
            } else {
                std::cout << "Incorrect input!\n";
            }
        }
        gameOver = gameFinished(field);

        for (int i = 0; i < 3; i++) {
            for (int k = 0; k < 3; k++) {
                std::cout << field[i][k] << " ";
            }
            std::cout << std::endl;
        }
        counter++;
    }

}