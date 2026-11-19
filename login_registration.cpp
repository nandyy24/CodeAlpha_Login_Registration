
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool registerUser() {
    string username, password;

    cout << "\n===== REGISTRATION =====\n";

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    string savedUser, savedPassword;

    while (file >> savedUser >> savedPassword) {
        if (savedUser == username) {
            cout << "Username already exists!\n";
            return false;
        }
    }

    file.close();

    ofstream outfile("users.txt", ios::app);

    outfile << username << " " << password << endl;

    outfile.close();

    cout << "Registration successful!\n";

    return true;
}

bool loginUser() {
    string username, password;

    cout << "\n===== LOGIN =====\n";

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");

    string savedUser, savedPassword;

    while (file >> savedUser >> savedPassword) {
        if (savedUser == username &&
            savedPassword == password) {

            cout << "Login successful! Welcome "
                 << username << "!\n";

            file.close();
            return true;
        }
    }

    file.close();

    cout << "Invalid username or password!\n";

    return false;
}

int main() {
    int choice;

    do {
        cout << "\n===== USER AUTHENTICATION SYSTEM =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "Thank you!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}
