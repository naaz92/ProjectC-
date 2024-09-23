#include <iostream>
using namespace std;
struct Product  //structure for data.
{
    string name;
    int price;
    int quantity;
};
void adding(Product record[], int& count) //function for adding product and count.
{
    if (count < 100) {
        cout << "Enter product name: ";
        cin >> record[count].name;

        cout << "Enter product price: Rs.";
        cin >> record[count].price;

        cout << "Enter quantity available: ";
        cin >> record[count].quantity;

        count++;

        cout << "\t-----Product added-----\n";
    } else {
        cout << "Sorry, the range is full.\n";
    }
}
void displaying(const Product record[], int count) //function for displaying product which are added.
{
    if (count == 0) {
        cout << "No products available.\n";
        return;
    }
	cout << "Product Name" << "\t" << "Price" << "\t\t" << "Quantity" << endl;
    for (int i = 0; i < count; ++i) {
        cout << record[i].name << "\t\t" << "Rs." << record[i].price << "\t\t" << record[i].quantity << endl;
    }
}
double TotalValue(const Product record[], int count) //funtion to calculate total value of product. 
{
    double total= 0.0;
    for (int i = 0; i < count; ++i) {
        total += record[i].price * record[i].quantity;
    }
    return total;
}

int main() {
    Product record[100]; //assigned variable to structure.
    int count = 0;
    int choice;
    do {
        cout<<"*************************************\n";
		cout << "--- Shop Menu ---\n";
        cout << "1. Add a new product\n";
        cout << "2. Display product details\n";
        cout << "3. Calculate total value\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout<<"*************************************\n";
        switch (choice) {
            case 1: adding(record, count);break; //calling adding function.
            case 2: displaying(record, count);break; //calling displaying function.
            case 3: cout << "Total value of stock: Rs." << TotalValue(record, count) << endl;break; //calling total value function.
            case 4: cout << "Closed";break;
        }
    } while (choice != 4); 
}
