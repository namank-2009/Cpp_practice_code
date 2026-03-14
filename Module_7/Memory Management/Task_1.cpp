#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace std;

class Book{
    public:
    string title;
    string author;
    Book(const string &t, const string &a){
        this->title = t;
        this->author = a;
    }
    void print(){
        cout<<"Book: "<<title<<" by author: "<<author<<endl;
    }
};


class Library{
    std::vector<std::unique_ptr<Book>> books;
    public:
    void addBook(const string &title, const string &author){
        books.push_back(std::make_unique<Book>(title, author));
    }

    Book* bookfind(const string &title){
        for (auto& book : books) {
            if (book->title == title) return book.get();
        }
        return nullptr;
    }

    void removeBook(const std::string& title) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if ((*it)->title == title) {
                books.erase(it);  // unique_ptr automatically deletes the Book
                return;
            }
        }
    }
};

int main(){
    Library lib;
    lib.addBook("1984", "George Orwell");
    lib.addBook("Brave New World", "Aldous Huxley");

    // Find a book and keep its pointer
    Book* bookPtr = lib.bookfind("1984");
    if (bookPtr) {
        bookPtr->print();
    }

    // Remove the book from the library
    lib.removeBook("1984");

    // bookPtr is now dangling! Do NOT use it.
    bookPtr = nullptr;  // good practice
    std::cout << "After removal, pointer reset to nullptr.\n";
    
    // Dangling pointer: bookPtr now points to deleted memory!
    // std::cout << "Trying to access deleted book:" << std::endl;
    // if (bookPtr) {
    //     bookPtr->print(); // Undefined behavior!
    // }

    return 0;
}