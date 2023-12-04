

#include <iostream>
using namespace std;

int main() {
    int initialMeterReading;
    int finalMeterReading;
    string customerName;
    int monthNumber;
    double spending;
    
    cin >> initialMeterReading;
    cin >> finalMeterReading;
    cin.ignore(10000,'\n');
    getline(cin, customerName);
    cin >> monthNumber;

    cout << "Initial meter reading: " << initialMeterReading << endl;
    cout << "Final meter reading: " << finalMeterReading << endl;
    cout << "Customer name: " << customerName << endl;
    cout << "Month number (1=Jan, 2=Feb, etc.): " << monthNumber << endl;
    cout << "---" << endl;
    
    cout.setf(ios::fixed);
    cout.precision(2);
    int HCF = finalMeterReading - initialMeterReading;
    
    if (initialMeterReading < 0)        // Follow the instruction that if I chose to gather all the                                   information first before checking my error, only the earliest error message will be                                     outputed.
        
        cout << "The initial meter reading must not be negative." << endl ;
    else if (HCF < 0)
        cout << "The final meter reading must be at least as large as the initial reading." << endl;
    else if (customerName == "")
        cout << "You must enter a customer name" << endl;

    else if (monthNumber < 1 || monthNumber > 12)
        cout << "The month number must be in the range 1 through 12." << endl;
    else
        if (monthNumber >= 4 && monthNumber <= 10)
        {
            if (HCF <= 23) {
                    spending = HCF*5.41;
                cout << "The bill for " << customerName << " is $" << spending << endl;
            }
            else {
                    spending = 23*5.41 + (HCF-23)*9.79;
                cout << "The bill for " << customerName << " is $" << spending << endl;
            }
            
        }
        
            
            
        
        else
        {
            if (HCF <= 15) {
                spending = HCF*5.41;
            cout << "The bill for " << customerName << " is $" << spending << endl;
            }
            else {
                spending = 15*5.41 + (HCF - 15)*7.77;
            cout << "The bill for " << customerName << " is $" << spending << endl;
        }
    }
    
    return 0;
}
