#include <stdio.h>
int getTheDeterminantOfMatrix(int row, int col, int matrix[row][col]);
int matrix_complex_laplace_algorithm(int row, int col, int matrix[row][col]);
int matrix_find_1x1_determinant(int row, int col, int matrix[row][col]);
int matrix_find_2x2_determinant(int row, int col, int matrix[row][col]);
int matrix_find_3x3_determinant(int row, int col, int matrix[row][col]);
int matrix_find_4x4_determinant(int row, int col, int matrix[row][col]);
int matrix_find_4x4_complex_way(int row, int col, int matrix[row][col]);
int main(void){
int rows,cols;
printf("Write a format of matrix which need to be solved(correct type format: ex.(3x3)) \n");
scanf("%dx%d",&rows,&cols);
int matrix[rows][cols];
printf("Type values into written matrix format starting from m[i], thus continuing from there m[i+1] till you successufuly assign values to all rows and it's collumns \n");
int temporary_loop_asign_value = 0;
for(int i = 0; i<rows; i++){
    for(int j = 0; j<cols; j++){
        printf("Write value for row: %d column %d \n",i,j);
        scanf(" %d",&temporary_loop_asign_value);
        matrix[i][j] = temporary_loop_asign_value;
    }
}

printf("Assuming you've passed correct values your matrix looks like : \n");

for(int i = 0; i < rows; i++){
    printf("\n");
    for(int j = 0; j < cols; j++){
        printf("  %d",matrix[i][j]);
    }
}
printf("\n");

printf("Given your matrix, and assuming it is correct. What do you need to do with it? \n");
printf("Type: 1 - in order to count determinant(The way to count determinant differs from length of Matrix!)) \n");
printf("Type: 0 - Terminate the program\n");
int temporary_user_input_holder = 0;
scanf(" %d",&temporary_user_input_holder);
switch (temporary_user_input_holder)
{
case 1:
    getTheDeterminantOfMatrix(rows,cols,matrix);
    break;
case 0:
    printf("Terminating the program");
    break;
}

}

int getTheDeterminantOfMatrix(int row, int col, int matrix[row][col]){

    printf("Hoho, let me see what is your matrix format... \n");
    printf("Rows: %d Cols: %d \n",row,col);
    if(row!=col){
        printf("In order to count a determinant of matrix, it needs to be square(have the same length!)\n");
        printf("Since no operations are possible in this case, program is immediatelly terminated \n");
        return 0;
    }
    printf("Based on your size of matrix we're able to do it this way: \n");
    if(row == 1 && col == 1){
        matrix_find_1x1_determinant(row,col,matrix);
    }
    else if(row == 2 && col == 2){
        matrix_find_2x2_determinant(row,col,matrix);
    }
    else if(row == 3 && col == 3){
        matrix_find_3x3_determinant(row,col,matrix);
    }
    else if(row >=4 && col >=4){
        matrix_find_4x4_determinant(row,col,matrix);
    }
    return 1;
}

int matrix_find_1x1_determinant(int row, int col, int matrix[row][col]){
    printf("Your determinant is equal to: %d \n",matrix[0][0]);
    return matrix[0][0];
}
int matrix_find_2x2_determinant(int row, int col, int matrix[row][col]){
    //printf("When matrix'es are 2x2(as well as 3x3) we're using proceeding algorithm: A[1][1] * A[2][2] - A[1][2] * A[2][1] where A is our matrix \n");
    int temp_2x2_determinant = ((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]));
    printf("Your determinant is equal to : %d",temp_2x2_determinant);
    return temp_2x2_determinant;
}
int matrix_find_3x3_determinant(int row, int col, int matrix[row][col]){
    //printf("As mentioned, on 2x2 matrix, we're doing the same BUT, we need to add two additionals rows, which are A[1][1] A[1][2] A[1][3] A[2][1] A[2][2] A[2][3] \n");
    //printf("The reason why we need to add those two beggining matrix'es is that, we wouldn't be able to count it properly without doing so(we can, just it's easier while writing on paper). \n");
    //printf("The algorithm looks like: A[1][1] * A[2][2] * A[3][3] + A[2][1] * A[3][2] * A[1][3] + A[3][1] * A[2][1] * A[2][3] - A[1][3] * A[2][2] * A[3][1] - A[2][3] * A[3][2]*A[1][1]-A[3][3]*A[1][2]*A[2][1] \n");
    //printf("While the algorithm may look unclean, while you take out the paper, and write for example the written matrix here on your paper, then simply rewrite two first lines of your matrix to the last, it makes perfect sense \n");
    int temp_3x3_determinant = (((matrix[0][0] * matrix[1][1] * matrix[2][2]) +
                             (matrix[1][0] * matrix[2][1] * matrix[0][2]) +
                             (matrix[2][0] * matrix[0][1] * matrix[1][2])) -
                            ((matrix[0][2] * matrix[1][1] * matrix[2][0])) -
                            ((matrix[1][2] * matrix[2][1] * matrix[0][0])) -
                            ((matrix[2][2] * matrix[0][1] * matrix[1][0])));
    printf("Your determinant is equal to : %d \n", temp_3x3_determinant);
    return temp_3x3_determinant;
}
int matrix_find_4x4_determinant(int row, int col, int matrix[row][col]){
    printf("Pick a method: 1 - Complex : 2 - Quick \n");
    int user_temp_input = 0;
    scanf("%d",&user_temp_input);
    switch (user_temp_input)
    {
    case 1:
    matrix_find_4x4_complex_way(row,col,matrix);
        break;
    case 2:
        break;
    default:
        break;
    }
    return 0;
}
int matrix_find_4x4_complex_way(int row, int col, int matrix[row][col]){
    printf("Select one method: Expansion along a first row : r  / Expansion along a first column : c \n");
    char user_temp_input = 'a';
    scanf(" %c",&user_temp_input);
    if(user_temp_input == 'r'){
        int matrix_4x4_determinant_result = 0;
        for (int i = 0; i < 4; i++){
            int temporary_3x3_matrix_holder[3][3];
            int minorRow = 0;
            int minorColumn = 0;
            for (int j = 0; j < 4; j++){
                if(j == i) continue;
                minorColumn = 0;
                for (int k = 0; k < 4; k++){
                    if(k == i) continue;
                    temporary_3x3_matrix_holder[minorRow][minorColumn] = matrix[j][k];
                    minorColumn++;
                }
                minorRow++;
            }
            int minor_determinant = 0;
            minor_determinant = matrix_find_3x3_determinant(3,3,temporary_3x3_matrix_holder);
            matrix_4x4_determinant_result += (i % 2 == 0 ? 1 : -1) * matrix[0][i] * minor_determinant;
        }
        printf("Your result of 4x4 matrix is : %d ", matrix_4x4_determinant_result);
    }
    else if(user_temp_input == 'c'){
        int matrix_4x4_determinant_result = 0;
        for (int i = 0; i < 4; i++){
            int temporary_3x3_matrix_holder[3][3];
            int minorRow = 0;
            int minorColumn = 0;
            for (int j = 0; j < 4; j++){
                if(j == i) continue;
                minorColumn = 0;
                for (int k = 0; k < 4; k++){
                    if(k == i) continue;
                    temporary_3x3_matrix_holder[minorRow][minorColumn] = matrix[j][k];
                    minorColumn++;
                }
                minorRow++;
            }
            int minor_determinant = matrix_find_3x3_determinant(3, 3, temporary_3x3_matrix_holder);
            matrix_4x4_determinant_result += (i % 2 == 0 ? 1 : -1) * matrix[i][0] * minor_determinant;
        }
        printf("Your result of 4x4 matrix is : %d\n", matrix_4x4_determinant_result);
    }
    return 1;
}