#include<iostream>
#include<map>
#include <string>
#include <limits>

void clearInputBuffer(){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool getProductStock(int productId, int& currentStock, const std::map<int, int>& inventoryMap){
    auto it = inventoryMap.find(productId);
    if (it != inventoryMap.end()) {
        currentStock = it->second;
        return true;
    }
    currentStock = 0;
    return false;
}

void displayInventory(const std::map<int, int>& inventoryMap, const std::string& title){
    std::cout << "\n--- " << title << " ---\n";

    if (inventoryMap.empty()) {
        std::cout << "Inventory is empty.\n";
        return;
    }

    for(auto &it:inventoryMap){
        int productId = it.first;
        int stock = it.second;
        std::cout<<"ProductID: "<<productId<<" CurrentStock: "<<stock<<std::endl;
    }
}

void addNewProduct(std::map<int, int>& inventory){
   int id, stock;

    std::cout << "Enter Product ID: ";
    std::cin >> id;

    if (std::cin.fail()) {
        std::cout << "Invalid input!\n";
        clearInputBuffer();
        return;
    }

    if (inventory.count(id)) {
        std::cout << "Product already exists! Use restock.\n";
        return;
    }

    std::cout << "Enter Initial Stock: ";
    std::cin >> stock;

    if (std::cin.fail() || stock < 0) {
        std::cout << "Invalid stock value!\n";
        clearInputBuffer();
        return;
    }

    inventory[id] = stock;
    std::cout << "Product added successfully!\n";
}

void performSale(std::map<int, int>& inventory){
    int id, qty;

    std::cout << "Enter Product ID: ";
    std::cin >> id;

    std::cout << "Enter Quantity to Sell: ";
    std::cin >> qty;

    if (std::cin.fail() || qty <= 0) {
        std::cout << "Invalid quantity!\n";
        clearInputBuffer();
        return;
    }

    int stock;
    if (!getProductStock(id, stock, inventory)) {
        std::cout << "Product not found!\n";
        return;
    }

    if (stock < qty) {
        std::cout << "Not enough stock!\n";
        return;
    }

    inventory[id] -= qty;
    std::cout << "Sale successful!\n";
}

void performRestock(std::map<int, int>& inventory){
     int id, qty;

    std::cout << "Enter Product ID: ";
    std::cin >> id;

    std::cout << "Enter Quantity to Restock: ";
    std::cin >> qty;

    if (std::cin.fail() || qty <= 0) {
        std::cout << "Invalid quantity!\n";
        clearInputBuffer();
        return;
    }

    if (inventory.count(id)) {
        inventory[id] += qty;
        std::cout << "Restocked successfully!\n";
    } else {
        inventory[id] = qty;
        std::cout << "Product didn't exist. Added as new product.\n";
    }
}

void checkProductStatus(const std::map<int, int>& inventory){
    int id;
    std::cout << "Enter Product ID: ";
    std::cin >> id;

    int stock;
    if (getProductStock(id, stock, inventory)) {
        std::cout << "Stock: " << stock << std::endl;
    } else {
        std::cout << "Product not found!\n";
    }
}

void discontinueProduct(std::map<int, int>& inventory){
    int id;
    std::cout << "Enter Product ID to remove: ";
    std::cin >> id;

    if (inventory.erase(id)) {
        std::cout << "Product removed successfully!\n";
    } else {
        std::cout << "Product not found!\n";
    }
}

void ActionToPerform(std::map<int, int>& inventory) {
    int choice;

    do {
        std::cout << "\n===== MENU =====\n";
        std::cout << "1. Add New Product\n";
        std::cout << "2. Perform Sale\n";
        std::cout << "3. Perform Restock\n";
        std::cout << "4. Check Product Status\n";
        std::cout << "5. Discontinue Product\n";
        std::cout << "6. Display All Products\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";

        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input!\n";
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1: addNewProduct(inventory); break;
            case 2: performSale(inventory); break;
            case 3: performRestock(inventory); break;
            case 4: checkProductStatus(inventory); break;
            case 5: discontinueProduct(inventory); break;
            case 6: displayInventory(inventory, "Current Inventory"); break;
            case 0: std::cout << "Exiting...\n"; break;
            default: std::cout << "Invalid choice!\n";
        }

    } while (choice != 0);
}

int main(){
    // Map for productId  and stockQuantity
    std::map<int,int>productInventory;
    productInventory[101] = 50; 
    productInventory[102] = 25;
    productInventory[103] = 100; 
    productInventory[104] = 10; 
    productInventory[105] = 75;

    displayInventory(productInventory, "Initial Inventory");

    ActionToPerform(productInventory);

    std::cout << "\nProgram Completed Successfully!\n";
}