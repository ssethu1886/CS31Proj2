/*program which inputs initial and final meter readings,
 customer name, month number, and outputs water bill
 
 outputs an error message if an input is invalid and exits program
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
    const double FIRST_TIER_RATE = 5.41;
    const double SECOND_TIER_RATE_HIGH = 9.79;
    const double SECOND_TIER_RATE_LOW = 7.77;
    
    // reading in inputs and checking for invalid inputs
    cout << "Initial meter reading: ";
    int initial;
    cin >> initial;
    if(initial < 0){
        cout << "---" << endl;
        cout << "The initial meter reading must not be negative." << endl;
        return 1;
    }
    
    cout << "Final meter reading: ";
    int finale;
    cin >> finale;
    cin.ignore(10000, '\n');
    if(finale < initial){
        cout << "---" << endl;
        cout << "The final meter reading must be at least as large as the initial reading." << endl;
        return 1;
    }
    
    cout << "Customer name: ";
    string name;
    getline(cin, name);
    if(name == ""){
        cout << "---" << endl;
        cout << "You must enter a customer name." << endl;
        return 1;
    }
    
    cout << "Month number (1=Jan, 2=Feb, etc.): ";
    int month;
    cin >> month;
    if(month < 1 || month > 12){
        cout << "---" << endl;
        cout << "The month number must be in the range 1 through 12." << endl;
        return 1;
    }
    
    //calculating bill
    int hcf = finale - initial;
    double bill = 0;
    
    // high usage season
    if (month >= 4 && month <= 10){
        if (hcf <= 23){
            bill = hcf * FIRST_TIER_RATE;
        }
        if (hcf > 23) {
            bill = (23 * FIRST_TIER_RATE) + (hcf - 23) * SECOND_TIER_RATE_HIGH;
        }
    }
    
    // low usage season
    if (month == 1 || month == 2 || month == 3 ||
        month == 11 || month == 12){
        if (hcf <= 15){
            bill = hcf * FIRST_TIER_RATE;
        }
        if (hcf > 15) {
            bill = (15 * FIRST_TIER_RATE) + (hcf - 15) * SECOND_TIER_RATE_LOW;
        }
    }
    
    // outputs bill
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "---" << endl;
    cout << "The bill for " << name << " is $" << bill << endl;
    
    return 0;
}
