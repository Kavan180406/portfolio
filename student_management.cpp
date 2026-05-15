#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
public:
    int id;
    string name;
    float marks;

    Student(int i, string n, float m) {
        id = i;
        name = n;
        marks = m;
    }
};

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name;
            float marks;

            cout << "Enter Student ID: ";
            cin >> id;

            cin.ignore();
            cout << "Enter Student Name: ";
            getline(cin, name);

            cout << "Enter Marks: ";
            cin >> marks;

            students.push_back(Student(id, name, marks));
            cout << "Student Added Successfully!\n";
        }

        else if (choice == 2) {
            if (students.empty()) {
                cout << "No student records found.\n";
            }
            else {
                cout << "\n--- Student Records ---\n";
                for (auto s : students) {
                    cout << "ID: " << s.id << endl;
                    cout << "Name: " << s.name << endl;
                    cout << "Marks: " << s.marks << endl;
                    cout << "----------------------\n";
                }
            }
        }

        else if (choice == 3) {
            int searchId;
            bool found = false;

            cout << "Enter Student ID to search: ";
            cin >> searchId;

            for (auto s : students) {
                if (s.id == searchId) {
                    cout << "\nStudent Found!\n";
                    cout << "ID: " << s.id << endl;
                    cout << "Name: " << s.name << endl;
                    cout << "Marks: " << s.marks << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Student not found.\n";
            }
        }

        else if (choice == 4) {
            cout << "Exiting Program...\n";
        }

        else {
            cout << "Invalid Choice! Try Again.\n";
        }

    } while (choice != 4);

    return 0;
}
