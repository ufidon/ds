#include <iostream>
#include <vector>

using namespace std;

// Function to check if placing a queen at board[row][col] is safe
bool isSafe(const vector<int>& board, int row, int col) {
    // Check columns and diagonals for any attacking queens
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(i - row) == abs(board[i] - col)) {
            return false;
        }
    }
    return true;
}

// Recursive function to solve the N Queens problem
void solveNQueens(int N, vector<int>& board, int row, vector<vector<int>>& solutions) {
    if (row == N) {
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            solveNQueens(N, board, row + 1, solutions);
        }
    }
}

// Function to print the board
void printBoard(const vector<int>& board) {
    int N = board.size();
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (board[row] == col) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int N;
    cout << "Enter the number of queens: ";
    cin >> N;

    vector<int> board(N, -1); // Initialize all elements to -1
    vector<vector<int>> solutions;
    solveNQueens(N, board, 0, solutions);

    cout << "Number of solutions: " << solutions.size() << endl << endl;
    for (const auto& sol : solutions) {
        printBoard(sol);
    }

    return 0;
}
