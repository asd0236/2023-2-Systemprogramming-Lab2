#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 학생 정보를 저장하는 구조체
struct Student {
    char name[100];
    int midterm;
    int final;
};

// 학생 트리의 노드 정의
struct TreeNode {
    struct Student data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 새로운 학생 노드를 생성하는 함수
struct TreeNode* createNode(struct Student student) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }
    newNode->data = student;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 학생을 트리에 삽입하는 함수
struct TreeNode* insert(struct TreeNode* root, struct Student student) {
    if (root == NULL) {
        return createNode(student);
    }
    int compare = strcmp(student.name, root->data.name);
    if (compare < 0) {
        root->left = insert(root->left, student);
    } else if (compare > 0) {
        root->right = insert(root->right, student);
    }
    return root;
}

// 학생 정보를 출력하는 함수 (중위 순회)
void inorder(struct TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("Name: %s, Midterm Score: %d, Final Score: %d\n", root->data.name, root->data.midterm, root->data.final);
        inorder(root->right);
    }
}

int main() {
    int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    struct TreeNode* root = NULL;

    for (int i = 0; i < numStudents; i++) {
        struct Student student;
        printf("Enter name for student %d: ", i + 1);
        scanf("%s", student.name);
        printf("Enter midterm score for student %d: ", i + 1);
        scanf("%d", &student.midterm);
        printf("Enter final score for student %d: ", i + 1);
        scanf("%d", &student.final);

        root = insert(root, student);
    }

    printf("\nStudent Information (in-order traversal):\n");
    inorder(root);

    // 메모리 해제 (선택 사항)
    free(root);

    return 0;
}

