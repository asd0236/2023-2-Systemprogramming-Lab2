#include <iostream>
#include <vector>

int main() {
    int rows, cols;
    
    // 사용자로부터 행과 열 수 입력
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns: ";
    std::cin >> cols;

    // 두 개의 행렬을 동적으로 할당
    std::vector<std::vector<int>> matrix1(rows, std::vector<int>(cols));
    std::vector<std::vector<int>> matrix2(rows, std::vector<int>(cols));
    std::vector<std::vector<int>> result(rows, std::vector<int>(cols));

     std::cout << "Enter elements of the first matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix1[i][j];
        }
    }

    std::cout << "Enter elements of the second matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix2[i][j];
        }
    }

    // 행렬 덧셈 수행
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // 결과 출력
    std::cout << "Resultant matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << result[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}

