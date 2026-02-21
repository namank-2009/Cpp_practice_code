#include<iostream>
#include <stdexcept>
#include <string>
#include <limits>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

class InvalidPriceException : public runtime_error{
    public:
    InvalidPriceException(const char* str): runtime_error(str){}
    InvalidPriceException(const std::string& str):runtime_error(str){}
};

class Product{
    private:
        string name;
        double price;
        int stock;
    public:
        Product(const string& n, double p, int s)
        : name(n), price(p), stock(s) {}

    string getName()const { return name; }
    double getPrice() const { return price; }
    int getStock() const { return stock; }

    void setPrice(double newPrice) { price = newPrice; }

    void display() const{
        cout << left << setw(15) << name
             << " | Price: Rs. " << fixed << setprecision(2) << setw(8) << price
             << " | Stock: " << stock << endl;
    }
};

double getNewPrice(){
    double newPrice;

    cout<<"Enter new price: ";
    cin>>newPrice;

    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        throw InvalidPriceException("Error: Invalid product selection!");
    }

    if(newPrice<=0){
        throw InvalidPriceException("Error: Price must be postive");
    }

    if (newPrice > 10000) {
        throw InvalidPriceException("Error: Price cannot exceed Rs. 10,000.");
    }

    double rounded = round(newPrice * 100.0) / 100.0;
    if (fabs(newPrice - rounded) > 1e-9) {
        throw InvalidPriceException("Error: Price can have at most 2 decimal places.");
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return newPrice;
}

void updateProductPrice(Product& product){
    cout<<"\nCurrent Product Details\n";
    product.display();

    while(true){
        try{
            double newPrice = getNewPrice();
            double currentPrice = product.getPrice();

            double percentageChange =
                fabs((newPrice - currentPrice) / currentPrice) * 100.0;

            if (percentageChange > 50.0) {
                throw InvalidPriceException(
                    "Error: Price change cannot exceed 50% in single update.");
            }
            product.setPrice(newPrice);
            cout << "Price updated successfully!\n";
            break;
        }
        catch (const InvalidPriceException& e) {
            cout << e.what() << endl;
            cout << "Please try again.\n\n";
        }
    }
}
void displayInventory(const vector<Product>& inventory) {
    cout << "\n--------- Inventory -----------\n";
    for (size_t i = 0; i < inventory.size(); ++i) {
        cout << i + 1 << ". ";
        inventory[i].display();
    }
}

int main(){
     vector<Product> inventory = {
        Product("Laptop", 5000.00, 10),
        Product("Headphones", 1500.00, 25),
        Product("Smartphone", 3000.00, 8)
    };

    cout << "----Inventory Management System----\n";

    char continueUpdate;
    
    do{
        try{
            displayInventory(inventory);
            cout<<"Select product number to display the product: ";
            int choice;
            cin>>choice;

            if(cin.fail() || choice<1 || choice>inventory.size()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw InvalidPriceException("Error: Invalid product selection.");
            }
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            updateProductPrice(inventory[choice-1]);
        }
         catch (const InvalidPriceException& e) {
            cout << e.what() << endl;
        }

        cout<<"\n Do you want to update another product?(y/n)";
        cin >> continueUpdate;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }while (continueUpdate == 'y' || continueUpdate == 'Y');

    cout << "\nFinal Inventory:\n";
    displayInventory(inventory);

    cout << "Program exiting!\n";
    return 0;
}