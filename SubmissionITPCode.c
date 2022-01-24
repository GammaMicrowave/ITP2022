#include <stdio.h>
int main()
{
    
    int Matrix_Rows, Matrix_Columns;
    //Code to Assign the number of Rows in the matrix.
    do
    {
        printf("Enter the number of Rows of the Matrix\n");
        scanf("%d", &Matrix_Rows);
    } while (Matrix_Rows<1 && Matrix_Rows > 100);
    //Code to Assign the number of Columns in the matrix.
    do
    {

        printf("Enter the number of Columns of the Matrix\n");
        scanf("%d", &Matrix_Columns);
    } while (Matrix_Columns < 1 && Matrix_Columns > 100);

    //Intializing the 2D array to store the values in the matrix.
    int Matrix[100][100];

    //Taking the values of the matrix as input.
    
    for (int i = 0; i < Matrix_Rows; i++)
    {
        for (int j = 0; j < Matrix_Columns; j++)
        {
            printf("Enter the value for the %dth row and %dth column: ",i+1,j+1);
            scanf("%d", &Matrix[i][j]);
        }
    }
    //Printing the matrix for the end user.
    printf("Given matrix is:\n");
    for (int i = 0; i < Matrix_Rows; i++)
    {
        for (int j = 0; j < Matrix_Columns; j++)
        {
            printf("%d ", Matrix[i][j]);
        }
        printf("\n");
    }

    //Function for printing the Transpose of the given matrix.
    printf("Transposed matrix is:\n");
    for (int j = 0; j < Matrix_Columns; j++)
    {
        for (int i = 0; i < Matrix_Rows; i++)
        {
            printf("%d ", Matrix[i][j]);
        }
        printf("\n");
    }

    long determinant;
    if(Matrix_Columns == 2 && Matrix_Rows == 2){
        determinant = Matrix[0][0]*Matrix[1][1] - Matrix[1][0]*Matrix[0][1];
        printf("\nThe value of the 2x2 Determinant is : %d\n", determinant);
    }
    else if(Matrix_Columns == 3 && Matrix_Rows == 3){
        determinant = Matrix[0][0] * ((Matrix[1][1] * Matrix[2][2]) - (Matrix[2][1] * Matrix[1][2])) - Matrix[0][1] * (Matrix[1][0] * Matrix[2][2] - Matrix[2][0] * Matrix[1][2]) + Matrix[0][2] * (Matrix[1][0] * Matrix[2][1] - Matrix[2][0] * Matrix[1][1]);    
        printf("\nThe value of the 3x3 Determinant is : %d\n",determinant);
    }
    else if(Matrix_Rows != Matrix_Columns){
        printf("Since the matrix is not a square matrix, We cannot find the value of the determinant.\n");
    }
    else if(Matrix_Columns > 3 && Matrix_Rows == Matrix_Columns){
        printf("The value of determinant can not be calculated by the given code.\n");
    }
    return 0;
}
