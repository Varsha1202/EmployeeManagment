// C++ program for the Employee Management System
#include <iostream>
#define max 20
using namespace std;

// Structure of Employee
struct employee {
    string name;
    long int code;
    string position;
    int exp;
    int age;
    int salary;
    
};

int num;

// Function prototypes
void showMenu();
void build();
void insert();
void deleteIndex(int i);
void deleteRecord();
void searchRecord();

// Array of Employees to store the data in the form of the Structure
employee emp[max], tempemp[max], sortemp[max], sortemp1[max];

// Function to build the table of employees
void build() {
    cout << "Build The Table\n";
    cout << "Maximum Entries can be " << max << "\n";
    cout << "Enter the number of Entries required: ";
    cin >> num;

    if (num > max) {
        cout << "Maximum number of Entries are 20\n";
        num = max;
    }

    cout << "Enter the following data:\n";
    for (int i = 0; i < num; i++) {
        cout << "Name: ";
        cin >> emp[i].name;
        cout << "Employee ID: ";
        cin >> emp[i].code;
        cout << "Position: ";
        cin >> emp[i].position;
        cout << "Experience: ";
        cin >> emp[i].exp;
        cout << "Age: ";
        cin >> emp[i].age;
        cout << "Salary: ";
        cin >> emp[i].salary;
    }

    showMenu();
}

// Function to insert data into the table
void insert() {
    if (num < max) {
        int i = num;
        num++;
        cout << "Enter the information of the Employee:\n";
        cout << "Name: ";
        cin >> emp[i].name;
        cout << "Employee ID: ";
        cin >> emp[i].code;
        cout << "Position: ";
        cin >> emp[i].position;
        cout << "Experience: ";
        cin >> emp[i].exp;
        cout << "Age: ";
        cin >> emp[i].age;
        cout << "Salary: ";
        cin >> emp[i].salary;
    } else {
        cout << "Employee Table Full\n";
    }

    showMenu();
}

// Function to delete record at index i
void deleteIndex(int i) {
    for (int j = i; j < num - 1; j++) {
        emp[j].name = emp[j + 1].name;
        emp[j].code = emp[j + 1].code;
        emp[j].position = emp[j + 1].position;
        emp[j].exp = emp[j + 1].exp;
        emp[j].age = emp[j + 1].age;
        emp[j].salary = emp[j + 1].salary;
    }
}

// Function to delete record
void deleteRecord() {
    cout << "Enter the Employee ID to Delete Record: ";
    int code;
    cin >> code;

    for (int i = 0; i < num; i++) {
        if (emp[i].code == code) {
            deleteIndex(i);
            num--;
            break;
        }
    }

    showMenu();
}

// Function to search for a record based on Employee ID
void searchRecord() {
    cout << "Enter the Employee ID to Search Record: ";
    int code;
    cin >> code;

    for (int i = 0; i < num; i++) {
        if (emp[i].code == code) {
            cout << "Name: " << emp[i].name << "\n";
            cout << "Employee ID: " << emp[i].code << "\n";
            cout << "Position: " << emp[i].position << "\n";
            cout << "Experience: " << emp[i].exp << "\n";
            cout << "Age: " << emp[i].age << "\n";
            cout << "Salary: " << emp[i].salary << "\n";
            break;
        }
    }

    showMenu();
}

// Function to show the main menu
void showMenu() {
    cout << "-------------------------\n";
    cout << "Employee Management System\n";
    cout << "-------------------------\n\n";
    cout << "Available Options:\n\n";
    cout << "1. Build Table\n";
    cout << "2. Insert New Entry\n";
    cout << "3. Delete Entry\n";
    cout << "4. Search a Record\n";
    cout << "5. Exit\n";

    int option;
    // Input Options
    cin >> option;
    // Call function based on the above option
    if (option == 1) {
        build();
    } else if (option == 2) {
        insert();
    } else if (option == 3) {
        deleteRecord();
    } else if (option == 4) {
        searchRecord();
    } else if (option == 5) {
        return;
    } else {
        cout << "Expected Options are 1/2/3/4/5\n";
        showMenu();
    }
}

// Driver Code
int main() {
    showMenu();
    return 0;
}
