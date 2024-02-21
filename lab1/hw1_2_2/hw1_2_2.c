/* 
    error encount
        error1: forget that matrix is double pointer, use one dimention
                access pattern(matrix[i*col+j]) get compiled error
 */
void setZeroes(int** matrix, int matrixSize, int* matrixColSize)
{
    int row_total = matrixSize;
    int col_total = (*matrixColSize);
    
    //For record which row or col should be set to zero (0: no, 1: yes)
    int row_record[row_total];
    int col_record[col_total];
    for(int i = 0; i < row_total; i++)
    {
        row_record[i] = 0;
    }
    for(int i = 0; i < col_total; i++)
    {
        col_record[i] = 0;
    }

    //Record which row & col should be set to zero
    for(int i = 0; i < row_total; i++)
    {
        for(int j = 0; j < col_total; j++)
        {
            if(matrix[i][j] == 0)
            {
                row_record[i] = 1;
                col_record[j] = 1;
            }
        }
    }

    //Set row
    for(int i = 0; i < row_total; i++)
    {
        if(row_record[i] == 1)
        {
            for(int j = 0; j < col_total; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    //Set col
    for(int i = 0; i < col_total; i++)
    {
        if(col_record[i] == 1)
        {
            for(int j = 0; j < row_total; j++)
            {
                matrix[j][i] = 0;
            }
        }
    }
    return;
}
