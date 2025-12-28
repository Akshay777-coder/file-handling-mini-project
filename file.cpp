#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

// Defining a Structure to Store Student data
struct Student{
    int roll;
    string name;
    string branch;
    int sem;
};

// menu function show basic operations
void menu(){
    cout << "\n___Student_ManageMent_System___" << endl;
    cout << "\n1. Enroll Student" << endl;
    cout << "2. Search Student" << endl;
    cout << "3. Update Student" << endl;
    cout << "4. Display Student" << endl;
    cout << "5. Delete Student" << endl;
    cout << "6. Exit" << endl;
    cout << endl;
}

// rollExists check if two students are having same roll
bool rollExists(int roll){
    Student s;
    ifstream in("students.txt");

    if(!in){
        return false; // file not present yet
    }
    
    while(in >> s.roll >> s.name >> s.branch >> s.sem){
        if(s.roll == roll){
            in.close();
            return true;
        }
    }
    return false;
}

// Enrolls a Student with Roll, Name, Branch and Semester
void enrollStudent(){
    Student s;
    ofstream out("students.txt",ios::app);

    if(!out){
        cout << "File Not Found !!" << endl;
    }

    cout << "Enter Your Roll: ";
    cin >> s.roll;

    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Invalid Input !!" << endl;
        return;
    }

    if(rollExists(s.roll)){
        cout << "Roll Number already exists, Enrollment Denied !!" << endl;
        return;
    }

    cout << "Enter Your Name: ";
    cin >> s.name;
    cout << "Enter Your Branch: ";
    cin >> s.branch;
    cout << "Enter Your Semester: ";
    cin >> s.sem;

    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Invalid Input !!" << endl;
        return;
    }

    out << s.roll << " " << s.name << " " << s.branch << " " << s.sem << endl;

    out.close();
    cout << endl;
}

// Search for a Student through Roll Number
void searchStudent(){
    Student s;
    ifstream in("students.txt");
    ofstream out("temp.txt");
    
    if(!in || !out){
        cout << "File Not Found !!" << endl;
    }
    
    bool found = false;
    int roll;
    
    cout << "Enter New Roll: ";
    cin >> roll;

    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Invalid Input !!" << endl;
        return;
    }

    while(in >> s.roll >> s.name >> s.branch >> s.sem){
        if(roll == s.roll){
            cout << "\n---------------------------------" << endl;
            cout << "Roll" << "\t" << "Name" << "\t" << "Branch" << "\t" << "Semeester" << endl;
            cout << "---------------------------------" << endl;
            cout << s.roll << "\t" << s.name << "\t" << s.branch << "\t" << s.sem << endl;
            out << s.roll << " " << s.name << " " << s.branch << " " << s.sem << endl;
            found = true;
            break;
        }else{
            out << s.roll << " " << s.name << " " << s.branch << " " << s.sem << endl;
        }
    }

    in.close();
    out.close();

    remove("students.txt");
    rename("temp.txt","students.txt");

    if(found == false){
        cout << "Student Not Exist !!" << endl;
    }
    cout << endl;
}

// Updates a Enrollment Detail of a Student
void updateStudent(){
    Student s;
    ifstream in("students.txt");
    ofstream out("temp.txt");

    if(!in || !out){
        cout << "File Not Found !!" << endl;
    }

    bool found = false;
    int roll;
    
    cout << "Enter Previous Roll: ";
    cin >> roll;

    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Invalid Input !!" << endl;
        return;
    }

    while(in >> s.roll >> s.name >> s.branch >> s.sem){
        if(s.roll == roll){
            cout << "Enter New Roll: ";
            cin >> s.roll;

            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Invalid Input !!" << endl;
                return;
            }

            cout << "Enter New Name: ";
            cin >> s.name;
            cout << "Enter New Branch: ";
            cin >> s.branch;
            cout << "Enter new Semester: ";
            cin >> s.sem;

            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Invalid Input !!" << endl;
                return;
            }

            out << s.roll << " " << s.name << " " << s.branch << " " << s.sem << endl;
            found = true;
        }else{
            out << s.roll << " " << s.name << " " << s.branch << " " << s.sem << endl;
        }
    }

    out.close();
    in.close();

    remove("students.txt");
    rename("temp.txt","students.txt");

    if(found == false){
        cout << "Student Not Found !!" << endl;
    }
    cout << endl;
}

// Displays all Students Enrollments in a Table Format
void displayStudent(){
    Student s;
    ifstream in("students.txt");
    ofstream out("temp.txt");

    if(!in || !out){
        cout << "File Not Found !!" << endl;
    }

    cout << "\n---------------------------------" << endl;
    cout << "Roll" << "\t" << "Name" << "\t" << "Branch" << "\t" << "Semeester" << endl;
    cout << "---------------------------------" << endl;
    
    while(in >> s.roll >> s.name >> s.branch >> s.sem){
        cout << s.roll << "\t" << s.name << "\t" << s.branch << "\t" << s.sem << endl;
        out << s.roll << " " << s.name << " " << s.branch << " " << s.sem << endl;
    }
    
    in.close();
    out.close();

    remove("students.txt");
    rename("temp.txt","students.txt");
    
// Main function Runs a Switch to go through all the menu Functions    
}int main(){
    int choice;
    do{
        menu();
        cout << "Enter Your Choice: ";
        cin >> choice;
        
        // if choice is a letter or a string it clears choice and assign it with 0... ending up running default block of switch
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            choice = 0;
        }
        switch(choice){
            case 1:
                enrollStudent();
                break;
            case 2:
                searchStudent();
                break;
            case 3:
                updateStudent();
                break;
            case 4:
                displayStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                cout << "Exiting Program..." << endl;
                break;
            default:
                cout << "Invalid Input !!" << endl;
                break;
        }
        
        // This block is to Delete unwanted Garbage Student Enrollment with roll = 0... Created during Invalid Imputing!!
        {
            Student s;
            ifstream in("students.txt");
            ofstream out("temp.txt");

            while(in >> s.roll >> s.name >> s.branch >> s.sem){
                if(s.roll != 0){
                    out << s.roll << " " << s.name << " " << s.branch << " " << s.sem << endl;
                }else{
                    continue;
                }
            }

            in.close();
            out.close();

            remove("students.txt");
            rename("temp.txt","students.txt");
        }
    }while(choice != 6);
    return 0;
}
