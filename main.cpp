#include <iostream>
#include <cstdlib>

int ** createMatrix(int& rows, int& col)
{
    std::cout << "размер матрицы:" << std::endl;
    std::cin >> rows >> col;
    if(std::cin.fail() || rows < 0 || col < 0){
        return nullptr;
    }

    int ** matrix;
    try{
        matrix = new int*[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new int[col];
        }

        for (int i = 0; i < rows; ++i) {
            std::cout << i+1 << " " << "строка:";
            for (int j = 0; j < col; ++j) {
                std::cin >> matrix[i][j];
                if(std::cin.fail())
                {
                    for (int k = 0; k <= i; k++){
                        delete[] matrix[k];
                    }
                    delete[] matrix;
                    return nullptr;
                }
            }
        }

    }
    catch (const std::bad_alloc){
        return nullptr;
    }
    return matrix;
}

void printMatrix(int ** mat, int rows, int col){
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j <col; ++j){
            std::cout << mat[i][j] << " ";
            }
        std::cout << std::endl;
        }
}

void transpose(int ** mat, int rows, int col){
    std::cout << "транспонированая матрица" << std::endl;
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < col; ++j){
            std::cout << mat[j][i] << " ";
            }
        std::cout << std::endl;
        }
}

int main() {
    int rows,col = 0;
    int ** mat = createMatrix(rows,col);
    if (mat == nullptr){
        return 1;
    }
    printMatrix(mat,rows,col);
    transpose(mat, rows,col);
}


