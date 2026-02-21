#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

class Book{
  private:
    string title;
    string author;
    double price;

    public:
        Book() : title(""), author(""), price(0.0) {}

        Book(string t, string a, double p)
        : title(t), author(a), price(p) {}

    // Input operator
    friend istream& operator>>(istream& is, Book& obj){
        cout<<"Enter title: ";
        getline(is,obj.title);

        cout<<"Enter author: ";
        getline(is,obj.author);

        cout<<"Enter price: ";
        is>>obj.price;

        is.ignore();
        return is;
    }

    // Output operator
    friend ostream& operator<<(ostream& os, const Book& book){
          os << "\nTitle: " << book.title
           << "\nAuthor: " << book.author
           << "\nPrice: $" << book.price << "\n";
        return os;
    }

    // Save book to file
    friend void saveToFile(const Book& book, std::ofstream& ofs){
        ofs << book.title << '\n' 
            << book.author << '\n' 
            << book.price << '\n';
    }

    // Load book from file
    friend Book loadFromFile(ifstream& ifs);

   
};
Book loadFromFile(std::ifstream& ifs);

Book loadFromFile(std::ifstream& ifs){
       string t, a;
        double p;

        getline(ifs, t);
        getline(ifs, a);
        ifs >> p;
        ifs.ignore();

        return Book(t, a, p);
    }

int main(){
   int n;
   cout<<"Enter the number of books\n";
   cin>>n;
   cin.ignore();

   vector<Book> books;

    // Input books
    for (int i = 0; i < n; i++) {
        cout << "\nBook " << i + 1 << ":\n";
        Book b;
        cin >> b;
        books.push_back(b);
    }

    // Save to file
    ofstream ofs("books.txt");
    for (const auto& b : books) {
        saveToFile(b, ofs);
    }
    ofs.close();

    cout << "\nBooks saved to file successfully!\n";

    // Load from file
    ifstream ifs("books.txt");
    vector<Book> loadedBooks;

    while (ifs.peek() != EOF) {
        Book b = loadFromFile(ifs);
        loadedBooks.push_back(b);
    }

    ifs.close();

    // Display loaded books
    cout << "\n--- Loaded Books From File ---\n";
    for (const auto& b : loadedBooks) {
        cout << b;
    }

    return 0;
}