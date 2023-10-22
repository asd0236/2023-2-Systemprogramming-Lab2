use std::io;

fn main() {
    // 사용자로부터 행과 열의 개수 입력
    let rows = get_input("Enter the number of rows: ");
    let cols = get_input("Enter the number of columns: ");

    // 두 개의 행렬 생성
    let matrix1 = create_matrix(rows, cols);
    let matrix2 = create_matrix(rows, cols);

    // 두 행렬에 값을 입력
    let matrix1 = input_matrix(matrix1, "Enter values for matrix 1:");
    let matrix2 = input_matrix(matrix2, "Enter values for matrix 2:");

    // 두 행렬을 더한 결과
    let result = add_matrices(&matrix1, &matrix2);

    // 결과 행렬 출력
    println!("Result matrix:");
    display_matrix(&result);
}

fn get_input(prompt: &str) -> usize {
    println!("{}", prompt);
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read input");
    input.trim().parse().expect("Invalid input")
}

fn create_matrix(rows: usize, cols: usize) -> Vec<Vec<i32>> {
    vec![vec![0; cols]; rows]
}

fn input_matrix(mut matrix: Vec<Vec<i32>>, prompt: &str) -> Vec<Vec<i32>> {
    println!("{}", prompt);
    for i in 0..matrix.len() {
        for j in 0..matrix[0].len() {
            let value = get_input(&format!("Enter element at row {} - column {}: ", i, j));
            matrix[i][j] = value as i32;
        }
    }
    matrix
}

fn add_matrices(matrix1: &[Vec<i32>], matrix2: &[Vec<i32>]) -> Vec<Vec<i32>> {
    let rows = matrix1.len();
    let cols = matrix1[0].len();
    
    let mut result = vec![vec![0; cols]; rows];

    for i in 0..rows {
        for j in 0..cols {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    result
}

fn display_matrix(matrix: &[Vec<i32>]) {
    for row in matrix {
        for &element in row {
            print!("{} ", element);
        }
        println!();
    }
}

