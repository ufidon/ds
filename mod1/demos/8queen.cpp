#include <iostream>
#include <vector>

using namespace std;

// Function to check if placing a queen at board[row][col] is safe
bool isSafe(const vector<vector<int>>& board, int row, int col) {
    int N = board.size();
    // Check if there's a queen in the same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }
    
    // Check upper left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }
    
    // Check upper right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }
    
    return true;
}

// Recursive function to solve the N Queens problem
void solveNQueens(int N, vector<vector<int>>& board, int row, vector<vector<vector<int>>>& solutions) {
    if (row == N) {
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;
            solveNQueens(N, board, row + 1, solutions);
            board[row][col] = 0; // backtrack
        }
    }
}

// Function to print the board
void printBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int cell : row) {
            if (cell == 1)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int N;
    cout << "Enter the number of queens: ";
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N, 0)); // Initialize all elements to 0
    vector<vector<vector<int>>> solutions;
    solveNQueens(N, board, 0, solutions);

    cout << "Number of solutions: " << solutions.size() << endl << endl;
    for (const auto& sol : solutions) {
        printBoard(sol);
    }

    return 0;
}
