#include <iostream>
#include <map>
#include <string>

struct Student {
    std::string name;
    int midtermScore;
    int finalScore;
};

int main() {
    std::map<int, Student> studentMap;
    int numStudents;

    std::cout << "Enter the number of students: ";
    std::cin >> numStudents;

    for (int i = 1; i <= numStudents; ++i) {
        Student student;
        std::cout << "Enter student " << i << "'s name: ";
        std::cin >> student.name;
        std::cout << "Enter " << student.name << "'s midterm score: ";
        std::cin >> student.midtermScore;
        std::cout << "Enter " << student.name << "'s final score: ";
        std::cin >> student.finalScore;
        studentMap[i] = student;
    }

    int studentID;
    std::cout << "Enter the student ID to search: ";
    std::cin >> studentID;

    auto it = studentMap.find(studentID);
    if (it != studentMap.end()) {
        Student student = it->second;
        std::cout << "Student ID: " << studentID << std::endl;
        std::cout << "Name: " << student.name << std::endl;
        std::cout << "Midterm Score: " << student.midtermScore << std::endl;
        std::cout << "Final Score: " << student.finalScore << std::endl;
    } else {
        std::cout << "Student not found." << std::endl;
    }

    return 0;
}

