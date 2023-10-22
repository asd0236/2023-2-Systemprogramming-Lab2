use std::collections::BTreeMap;
use std::io;

#[derive(Debug)]
struct Student {
    name: String,
    midterm_score: i32,
    final_score: i32,
}

fn main() {
    let mut student_map: BTreeMap<i32, Student> = BTreeMap::new();

    println!("Enter the number of students: ");
    let mut num_students = String::new();
    io::stdin().read_line(&mut num_students).expect("Failed to read input");
    let num_students: i32 = num_students.trim().parse().expect("Invalid input");

    for student_id in 1..=num_students {
        println!("Enter student {}'s name: ", student_id);
        let mut name = String::new();
        io::stdin().read_line(&mut name).expect("Failed to read input");

        println!("Enter {}'s midterm score: ", name.trim());
        let mut midterm_score = String::new();
        io::stdin().read_line(&mut midterm_score).expect("Failed to read input");
        let midterm_score: i32 = midterm_score.trim().parse().expect("Invalid input");

        println!("Enter {}'s final score: ", name.trim());
        let mut final_score = String::new();
        io::stdin().read_line(&mut final_score).expect("Failed to read input");
        let final_score: i32 = final_score.trim().parse().expect("Invalid input");

        let student = Student {
            name: name.trim().to_string(),
            midterm_score,
            final_score,
        };

        student_map.insert(student_id, student);
    }

    println!("Enter the student ID to search: ");
    let mut student_id = String::new();
    io::stdin().read_line(&mut student_id).expect("Failed to read input");
    let student_id: i32 = student_id.trim().parse().expect("Invalid input");

    if let Some(student) = student_map.get(&student_id) {
        println!("{:?}", student);
    } else {
        println!("Student not found.");
    }
}

