#include <stdio.h>
#include <stdbool.h>
#define MAX 20
int board[MAX][MAX];
void printSolution(int n) 
{
for (int i = 0; i < n; i++) 
{
for (int j = 0; j < n; j++) 
{
if (board[i][j]) 
{
printf("Q ");
} 
else 
{
printf(". ");
}
}
printf("\n");
}
printf("\n");
}
bool isSafe(int row, int col, int n) {
int i, j;
for (i = 0; i < col; i++) 
{
if (board[row][i]) {
return false;
}
}
for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
{
if (board[i][j]) {
return false;
}
}
for (i = row, j = col; j >= 0 && i < n; i++, j--) 
{
if (board[i][j]) {
return false;
}
}
return true;
}
bool solveNQueensUtil(int col, int n) 
{
if (col >= n) 
{
printSolution(n);
return true;
}
bool res = false;
for (int i = 0; i < n; i++) 
{
if (isSafe(i, col, n)) 
{
board[i][col] = 1;
res = solveNQueensUtil(col + 1, n) || res;
board[i][col] = 0; 
}
}
return res;
}
void solveNQueens(int n) {
for (int i = 0; i < n; i++) 
{
for (int j = 0; j < n; j++) 
{
board[i][j] = 0;
}
}
if (!solveNQueensUtil(0, n)) 
{
printf("Solution does not exist");
return;
}
}
int main() 
{
int n;
printf("Enter the number of queens: ");
scanf("%d", &n);
solveNQueens(n);
return 0;
}


