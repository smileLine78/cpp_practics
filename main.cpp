#include <iostream>
#include <stdexcept>

int ** createMatrix(size_t rows, size_t col)
{
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
    catch (...){
        return nullptr;
    }
    return matrix;
}

void printMatrix(int ** mat, size_t rows, size_t col){
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j <col; ++j){
            std::cout << mat[i][j] << " ";
            }
        std::cout << std::endl;
        }
}

void transpose(int ** mat, size_t rows, size_t col){
    std::cout << "транспонированая матрица" << std::endl;
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < col; ++j){
            std::cout << mat[j][i] << " ";
            }
        std::cout << std::endl;
        }
}

int main() {
    size_t rows,col = 0;
    if (!(std::cin >> rows >> col)) {
        return 1;
    }
    try {
        int ** mat = createMatrix(rows,col);
        printMatrix(mat, col, rows);
        transpose(mat, rows,col);
    } 
    catch (const std::bad_alloc &) {
        return 2;
    } 
    return 0;
}
