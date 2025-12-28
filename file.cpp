#include <iostream>
#include <fstream>
using namespace std;

struct Student{
    int roll;
    string name;
    string branch;
    int sem;
};

void menu(){
    cout << "\n====== Student ManageMent System ======" << endl;
    cout << "1. Enroll Student" << endl;
    cout << "2. Search Student" << endl;
    cout << "3. Update Student" << endl;
    cout << "4. Display Student" << endl;
    cout << "5. Delete Student" << endl;
    cout << "6. Exit" << endl;
    cout << endl;
}

void enrollStudent(){
    Student s;
    ofstream out("students.txt",ios::app);

    cout << "Enter Your Roll: ";
    cin >> s.roll;
    cout << "Enter Your Name: ";
    cin >> s.name;
    cout << "Enter Your Branch: ";
    cin >> s.branch;
    cout << "Enter Your Semester: ";
    cin >> s.sem;
    out << s.roll << " " << s.name << " " << s.branch << " " << s.sem << endl;

    out.close();
    cout << endl;
}
void searchStudent(){
    Student s;
    ifstream in("students.txt");
    ofstream out("temp.txt");

    int roll;
    cout << "Enter New Roll: ";
    cin >> roll;
    bool found = false;

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
        cout << "Student Not Exist!!" << endl;
    }
}
void updateStudent(){
    Student s;
    ifstream in("students.txt");
    ofstream out("temp.txt");

    int roll;
    cout << "Enter the Roll: ";
    cin >> roll;
    bool found = false;

    while(in >> s.roll >> s.name >> s.branch >> s.sem){
        if(s.roll == roll){
            cout << "Enter New Roll: " << endl;
            cin >> s.roll;
            cout << "Enter New Name: " << endl;
            cin >> s.name;
            cout << "Enter New Branch: " << endl;
            cin >> s.branch;
            cout << "Enter new Semester: " << endl;
            cin >> s.sem;
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
        cout << "Student Not Found!!" << endl;
    }
}
void displayStudent(){
    Student s;
    ifstream in("students.txt");
    ofstream out("temp.txt");

    if(!in || !out){

    }

    cout << "---------------------------------" << endl;
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
}
void deleteStudent(){
    Student s;
    ifstream in("students.txt");
    ofstream out("temp.txt");

    int roll;
    cout << "Enter the Roll to Delete: ";
    cin >> roll;
    bool found = false;

    while(in >> s.roll >> s.name >> s.branch >> s.sem){
        if(s.roll != roll){
            out << s.roll << " " << s.name << " " << s.branch << " " << s.sem << endl;
        }else{
            found = true;
        }
    }

    in.close();
    out.close();

    remove("students.txt");
    rename("temp.txt","students.txt");

    if(found == true){
        cout << "Record Deleted Successfully !!" << endl;
    }else{
        cout << "Student Not Found" << endl;
    }
}
int main(){
    int choice;
    do{
        menu();
        cout << "Enter Your Choice: ";
        cin >> choice;
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
                cout << "Invalid Input" << endl;
                break;
        }
    }while(choice != 6);
    return 0;
}
