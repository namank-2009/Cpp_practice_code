#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* =========================
   Abstract Base Class: Item
   ========================= */
class Item {
private:
    string title;
    int id;

protected:
    // Protected setters allow derived classes to validate via base logic
    void setTitle(const string& t) {
        if (!t.empty())
            title = t;
        else
            cout << "Invalid title!" << endl;
    }

    void setId(int i) {
        if (i > 0)
            id = i;
        else
            cout << "Invalid ID!" << endl;
    }

public:
    Item(const string& title, int id) {
        setTitle(title);
        setId(id);
    }

    string getTitle() const { return title; }
    int getId() const { return id; }

    // Pure virtual function → abstraction
    virtual void display() const = 0;

    // Virtual destructor (important for polymorphism)
    virtual ~Item() {}
};

//  Derived Class: Book
class Book : public Item {
private:
    int pages;

public:
    Book(const string& title, int id, int pages)
        : Item(title, id) {
        setPages(pages);
    }

    void setPages(int p) {
        if (p > 0)
            pages = p;
        else
            cout << "Invalid number of pages!" << endl;
    }

    void display() const override {
        cout << "Book | ID: " << getId()
             << ", Title: " << getTitle()
             << ", Pages: " << pages << endl;
    }
};

/* Derived Class: Magazine */
class Magazine : public Item {
private:
    int issue;

public:
    Magazine(const string& title, int id, int issue)
        : Item(title, id) {
        setIssue(issue);
    }

    void setIssue(int i) {
        if (i > 0)
            issue = i;
        else
            cout << "Invalid issue number!" << endl;
    }

    void display() const override {
        cout << "Magazine | ID: " << getId()
             << ", Title: " << getTitle()
             << ", Issue: " << issue << endl;
    }
};

/* Derived Class: DVD */
class DVD : public Item {
private:
    double duration; // in minutes

public:
    DVD(const string& title, int id, double duration)
        : Item(title, id) {
        setDuration(duration);
    }

    void setDuration(double d) {
        if (d > 0)
            duration = d;
        else
            cout << "Invalid duration!" << endl;
    }

    void display() const override {
        cout << "DVD | ID: " << getId()
             << ", Title: " << getTitle()
             << ", Duration: " << duration << " mins" << endl;
    }
};

/* Main */
int main() {
    vector<Item*> library;

    library.push_back(new Book("C++ Primer", 101, 970));
    library.push_back(new Magazine("Tech Monthly", 102, 45));
    library.push_back(new DVD("Inception", 103, 148));

    cout << "Library Items:\n";
    for (const Item* item : library) {
        item->display();   // Polymorphic call
    }

    // Clean up
    for (Item* item : library)
        delete item;

    return 0;
}
