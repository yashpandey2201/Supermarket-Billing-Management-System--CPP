#include <iostream>
#include <limits> 
#include <fstream> 
#include <windows.h>
#include "feedback.h"
using namespace std;

void Feedback::form() {
    setColor(14);
    cout << "\n===== Feedback Form =====\n";
    setColor(7);

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Your Name: ";
    getline(cin, Name);

    cout << "Your Address: ";
    getline(cin, Address);

    cout << "Your Contact Number: ";
    while (!(cin >> contact)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid number. Enter Contact Number again: ";
    }

    cout << "Overall Experience (1 - 5): ";
    while (!(cin >> shopreview) || shopreview < 1 || shopreview > 5) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid rating. Enter 1 - 5: ";
    }

    cout << "Billing Speed (1 - 5): ";
    while (!(cin >> billingspeed) || billingspeed < 1 || billingspeed > 5) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid rating. Enter 1 - 5: ";
    }

    cout << "Staff Friendliness (1 - 5): ";
    while (!(cin >> staffriendliness) || staffriendliness < 1 || staffriendliness > 5) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid rating. Enter 1 - 5: ";
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Any Suggestion: ";
    getline(cin, anysuggestion);

    setColor(14);
    cout << "\n===== Your Feedback =====\n";
    setColor(7);
    cout << "Name: " << Name << "\n"
         << "Address: " << Address << "\n"
         << "Contact: " << contact << "\n"
         << "Overall Experience: " << shopreview << "\n"
         << "Billing Speed: " << billingspeed << "\n"
         << "Staff Friendliness: " << staffriendliness << "\n"
         << "Suggestion: " << anysuggestion << "\n";

    string filePath = "C:\\Users\\yashp\\OneDrive\\Documents\\Management System\\feedback.csv";
    ofstream csv(filePath, ios::app);
    if (csv.tellp() == 0) { 
        csv << "Name,Address,Contact,Overall Experience,Billing Speed,Staff Friendliness,Suggestion\n";
    }
    csv << "\"" << Name << "\","
        << "\"" << Address << "\","
        << contact << ","
        << shopreview << ","
        << billingspeed << ","
        << staffriendliness << ","
        << "\"" << anysuggestion << "\"\n";
    csv.close();

    setColor(10);
    cout << "Thank you for your feedback! ✅\n";
    setColor(7);
}
