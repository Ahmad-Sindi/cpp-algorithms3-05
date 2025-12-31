#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

/*
 * Algorithm Challenge & Problem Solving
 * Level 3 – Challenge #5
 * Sum of Each Column in a 3x3 Matrix Stored in a Separate Array
 *
 * This program fills a 3x3 matrix with random numbers, calculates the sum of each column, stores the results in a separate 1D array, and prints them.
 *
 * Key concepts reinforced:
 * - Column-wise traversal of 2D arrays
 * - Separation of computation from presentation
 * - Using arrays to store intermediate results
 * - Structured and modular programming
 */

using namespace std;

// Generate a random number between From and To (inclusive)
int RandNumb(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

// Fill 3x3 matrix with random numbers
void FillMatrixRandom(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = RandNumb(1, 99);
        }
    }
}

// Print 3x3 matrix
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(3) << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

// Calculate sum of a specific column
int SumColumn(int arr[3][3], short Rows, short ColIndex)
{
    int Sum = 0;
    for (short i = 0; i < Rows; i++)
    {
        Sum += arr[i][ColIndex];
    }
    return Sum;
}

// Store sum of each column in a separate array
void SumMatrixColumnsInArray(int arr[3][3], int arrSum[3], short Rows, short Cols)
{
    for (short i = 0; i < Cols; i++)
    {
        arrSum[i] = SumColumn(arr, Rows, i);
    }
}

// Print the column sums stored in array
void PrintSumColumnsArray(int arr[3], short Length)
{
    cout << "\nThe following are the sum of each column:\n";
    for (short i = 0; i < Length; i++)
    {
        cout << "Column " << i + 1 << " Sum = "
             << setw(3) << arr[i] << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3]; // 3x3 matrix
    int arrSum[3]; // 1D array to store column sums

    FillMatrixRandom(arr, 3, 3);
    cout << "The following is a 3x3 Random Matrix:\n\n";
    PrintMatrix(arr, 3, 3);

    SumMatrixColumnsInArray(arr, arrSum, 3, 3);
    PrintSumColumnsArray(arrSum, 3);

    return 0;
}
