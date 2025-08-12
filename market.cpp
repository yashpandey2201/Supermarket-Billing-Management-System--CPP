#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include "login.h"
#include "feedback.h"
#include <ctime>
#include <iomanip>  

using namespace std;

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

class Bill {
private:
    string Item;
    int Rate, Quantity;
public:
    Bill() : Item(""), Rate(0), Quantity(0) {}

    void setItem(string item) { Item = item; }
    void setRate(int rate) { Rate = rate; }
    void setQuant(int quant) { Quantity = quant; }

    string getItem() { return Item; }
    int getRate() { return Rate; }
    int getQuant() { return Quantity; }
};

double grandTotal = 0;

void showBill() {
    ifstream bill("Bill.txt");
    string line;
    setColor(14);
    cout << "\n================ SUPER MARKET BILL ================\n";
    setColor(7);
    while (getline(bill, line)) {
        cout << line << "\n";
    }
    setColor(14);
    cout << "====================================================\n";
    setColor(7);
    bill.close();
}

void addItem(Bill b) {
    string item;
    int rate, quant;

    setColor(7);
    cout << "Enter Item Name: ";
    setColor(11);
    cin >> item;
    b.setItem(item);

    setColor(7);
    cout << "Enter Rate Of Item: ";
    setColor(11);
    cin >> rate;
    b.setRate(rate);

    setColor(7);
    cout << "Enter Quantity Of Item: ";
    setColor(11);
    cin >> quant;
    b.setQuant(quant);

    int total = b.getRate() * b.getQuant();
    grandTotal += total; 

    ofstream out("Bill.txt", ios::app); 
    if (!out) {
        setColor(12);
        cout << "Error: File Can't Open!\n";
        setColor(7);
    } else {
       
        out.seekp(0, ios::end);
        if (out.tellp() == 0) {
            out << "****************************************************\n";
            out << "*            SUPER MARKET - OFFICIAL BILL           *\n";
            out << "*                 ℙ𝕠𝕨𝕖𝕣𝕖𝕕 𝕓𝕪  𝓑𝓲𝓛𝓛++                *\n";
            out << "****************************************************\n";

            time_t now = time(0);
            tm *ltm = localtime(&now);
            out << "Date: " << 1900 + ltm->tm_year << "-"
                << 1 + ltm->tm_mon << "-"
                << ltm->tm_mday << " "
                << ltm->tm_hour << ":" 
                << ltm->tm_min << ":" 
                << ltm->tm_sec << "\n";
            out << "----------------------------------------------------\n";
            out << left << setw(20) << "Item Name" 
                << setw(10) << "Rate" 
                << setw(10) << "Qty" 
                << setw(10) << "Total" << "\n";
            out << "----------------------------------------------------\n";
        }

       
        out << left << setw(20) << b.getItem()
            << setw(10) << b.getRate()
            << setw(10) << b.getQuant()
            << setw(10) << total << "\n";
    }
    out.close();

    setColor(10);
    cout << "Item Added Successfully ✅\n";
    setColor(7);

    showBill(); 
    Sleep(2000);
}

int main() {
    Login l;
    l.signin();

    Bill b;
    bool exit = false;

    while (!exit) {
        system("cls");
        int val;

        setColor(14);
        cout << "\tWelcome To Supermarket Billing System\n";
        cout << "\t======================================\n";
        setColor(7);
        cout << "1. Add Item\n";
        cout << "2. Exit\n";
        setColor(14);
        cout << "Enter Choice: ";
        setColor(11);
        cin >> val;

        if (val == 1) {
            system("cls");
            addItem(b);
        }
        else if (val == 2) {
            system("cls");


            ofstream out("Bill.txt", ios::app);
            out << "----------------------------------------------------\n";
            out << left << setw(40) << "GRAND TOTAL" 
                << setw(10) << grandTotal << "\n";
            out << "****************************************************\n";
            out.close();

            setColor(14);
            cout << "Running Billrun.bat file...\n";
            setColor(7);
            system("Billrun.bat");
            setColor(10);
            cout << "Returned from Billrun.bat\n";
            setColor(7);
            ofstream clearFile("Bill.txt", ios::trunc);
            clearFile.close();

            int want;
            cout << "Want to fill Feedback Form?\n"
                 << "Enter 1 for Yes\n"
                 << "and 2 for No" << endl;
            cin >> want;

            if (want == 1) {
                Feedback f;
                f.form();
            } 
            else {
                exit = true;  
            }
            exit=true;
            setColor(10);
            cout << "Goodbye!\n";
            setColor(7);
            Sleep(1500);
        }
    }
}
