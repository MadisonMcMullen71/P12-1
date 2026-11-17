#include <iostream>
#include <string>
using namespace std;

const int ROWS = 6;
const int COLUMNS = 13;
const int ERROR = -1;

int findRowIndex(int thisRow) {

    if (thisRow >= 1 && thisRow <= 13) {
        return thisRow - 1;
    }

    return ERROR;
}

int findSeatIndex(char thisSeat) {

    if (thisSeat == 'D') {
        return 0;
    }
    else if (thisSeat == 'C') {
        return 1;
    }
    else if (thisSeat == 'B') {
        return 4;
    }
    else if (thisSeat == 'A') {
        return 5;
    }

    return ERROR;
}

void displaySeatColumn(char seats[][ROWS], int column) {

    for (int i = 0; i < COLUMNS; i++) {
        cout << seats[i][column] << " ";
    }

    cout << endl;
}

int main() {

    char seats[COLUMNS][ROWS]{};

    // Fill D seats
    for (int i = 0; i < 12; i++) {
        seats[i][0] = 'D';
    }

    // Fill C seats
    for (int i = 0; i < 12; i++) {
        seats[i][1] = 'C';
    }

    // Fill the four 1s above the seat numbers
    for (int i = 9; i < 13; i++) {
        seats[i][2] = '1';
    }

    for (int i = 0; i < 9; i++) {
        seats[i][2] = ' ';
    }

    // Fill seat numbers
    for (int i = 0; i < 13; i++) {
        if (i < 9) {
            seats[i][3] = '1' + i;
        }
        else {
            seats[i][3] = '0' + (i - 9);
        }
    }

    // Fill B seats
    for (int i = 0; i < 13; i++) {
        seats[i][4] = 'B';
    }

    // Fill A seats
    for (int i = 0; i < 13; i++) {
        seats[i][5] = 'A';
    }

    // Display initial seating chart
    for (int i = 0; i < ROWS; i++) {
        displaySeatColumn(seats, i);
    }
    seats[12][0] = ' ';
    seats[12][1] = ' ';

    string seatChoice;
    int thisRow;
    char thisSeat;
    int rowIndex;
    int seatIndex;

    while (true) {

        cout << "Enter a seat or Q to quit: ";
        cin >> seatChoice;

        if (seatChoice == "Q" || seatChoice == "q") {
            break;
        }

        // Separate seat number and letter
        thisRow = stoi(seatChoice.substr(0, seatChoice.length() - 1));
        thisSeat = seatChoice[seatChoice.length() - 1];

        rowIndex = findRowIndex(thisRow);
        seatIndex = findSeatIndex(thisSeat);

        // Check if seat exists
        if (rowIndex == ERROR || seatIndex == ERROR) {
            cout << "Sorry, no such seat exists on the CRJ 200." << endl;
        }
        else if (seats[rowIndex][seatIndex] == ' ') {
            cout << "Sorry, no such seat exists on the CRJ 200." << endl;
        }
        else if (seats[rowIndex][seatIndex] == 'X') {
            cout << "Sorry, that seat is already occupied." << endl;
        }
        else {
            seats[rowIndex][seatIndex] = 'X';
        }

        // Display updated seating chart
        for (int i = 0; i < ROWS; i++) {
            displaySeatColumn(seats, i);
        }
    }

    return 0;
}
