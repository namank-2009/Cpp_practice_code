#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Book{
  private:
    string title;
    string author;
    double price;

    public:
        Book(){}

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

    friend ostream& operator<<(ostream& os, const Book& book){
          os << "\nTitle: " << book.title
           << "\nAuthor: " << book.author
           << "\nPrice: $" << book.price << "\n";
        return os;
    }

};

int main(){
   int n;
   cout<<"Enter the number of books\n";
   cin>>n;
   cin.ignore();

   vector<Book>books(n);

   //Input books
   for(int i=0; i<n; i++){
    cout<<"\nBooks "<<i+1<<": \n";
    cin>>books[i];
   }

   // Output books
   cout << "\n--- Book List ---\n";
    for (const auto& b : books) {
        cout<<b;
    }

    return 0;
}