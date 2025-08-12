#include <iostream>
#include <windows.h>
#include "login.h"
using namespace std;
void Login::signin() {
    id = "admin";
    pass = 1234;

    while (true) {
        string enteredId;
        int enteredPass;

        setColor(14); 
        cout << "\n===== LOGIN =====\n";
        setColor(7); 

        cout << "Enter ID: ";
        setColor(11); 
        cin >> enteredId;

        setColor(7);
        cout << "Enter Password: ";
        setColor(11);
        cin >> enteredPass;

        if (enteredId == id && enteredPass == pass) {
            setColor(10); 
            cout << "\nLogin successful ✅\n";
            setColor(7);
            break; 
        } 
        else {
            setColor(12); 
            cout << "\nIncorrect credentials ❌\n";
            setColor(14); 
            cout << "Wanna try again? Press 1 or press 2 to reset password: ";
            setColor(11); 
            cin >> forgot;

            if (forgot == 1) {
                continue; 
            } 
            else if (forgot == 2) {
                setColor(7);
                cout << "New ID: ";
                setColor(11);
                cin >> newid;

                setColor(7);
                cout << "New Password: ";
                setColor(11);
                cin >> newpass;

                id = newid;
                pass = newpass;

                setColor(10);
                cout << "\nCredentials updated. Please login again.\n";
                setColor(7);

                continue; 
            }
            else {
                setColor(12);
                cout << "\nInvalid choice. Please try again.\n";
                setColor(7);
            }
        }
    }
}
