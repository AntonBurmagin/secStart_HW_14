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

void initField (bool field[][12]) {
    for (int i = 0; i < 12; i++) {
        for (int k = 0; k < 12; k++) {
            field[i][k] = true;
        }
    }
}

bool fieldPopped (bool field[][12]) {
    for (int i = 0; i < 12; i++) {
        for (int k = 0; k < 12; k++) {
            if (field[i][k])
                return false;
        }
    }
    return true;
}

void showField (bool field[][12]) {
    for (int i = 0; i < 12; i++) {
        for (int k = 0; k < 12; k++) {
            if (field[i][k]) {
                std::cout << "o";
            } else {
                std::cout << "x";
            }
        }
        std::cout << std::endl;
    }
}

void popping (bool field[][12], int x1, int y1, int x2, int y2) {
    if (x1 > x2)
        std::swap(x1, x2);
    if (y1 > y2)
        std::swap(y1, y2);
    for (int i = x1; i <= x2; i++) {
        for (int k = y1; k <= y2; k++) {
            if (field[i][k]) {
                std::cout << "Pop! ";
                field[i][k] = false;
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    // 14.6.2
    /*
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
    */

    // 14.6.5
    /*
    bool field[12][12];
    initField(field);
    
    int x1, y1, x2, y2;
    while(!fieldPopped(field)) {
        bool correctInput = false;
        while(!correctInput) {
                std::cin >> x1 >> y1 >> x2 >> y2;
                if (x1 > -1 && x1 < 12 && y1 > -1 && y1 < 12 && x2 > -1 && x2 < 12 && y2 > -1 && y2 < 12) {
                    correctInput = true;
                    popping(field, x1, y1, x2, y2);
                } else {
                    std::cout << "Incorrect input!\n";
                }
        }
        showField(field);
    }
    std::cout << "GameOver!" << std::endl;
    */

    // 14.6.6
    /*
    int arr[5][5];
    int number = 0;
    for (int i = 0; i < 5; i++) {
        for (int k = 0; k < 5; k++) {
            arr[i][(4 - k) * (i % 2) + k * ((i + 1) % 2)] = number;
            number++;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int k = 0; k < 5; k++) {
            std::cout << arr[i][k] << "\t";
        }
        std::cout << std::endl;
    }
    */

}