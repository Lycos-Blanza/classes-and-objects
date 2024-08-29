#include <iostream>
using namespace std;

class Book {
    private:
        string title;
        string author;
        int year;

    public:
        void setDetails(string t, string a, int y) {
            title = t;
            author = a;
            year = y;
        }

        void displayDetails() {
        	cout << "Title  " << "   Author  " << "   Year" << endl;
            cout << title << "\t" << author << "\t" <<  year << endl;
        }

        string getTitle() {
            return title;
        }
};

int main() {
    const int MAX_BOOKS = 100;  
    Book books[MAX_BOOKS];      
    int bookCount = 0;         

    int choice;
    string inputTitle;
    string inputAuthor;
    int inputYear;

    do {
        cout << "\nMenu" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Display All Books" << endl;
        cout << "3. Search Book" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter Choice [1/2/3/4]: ";
        cin >> choice;
        cin.ignore();  

        switch (choice) {
            case 1: {
                if (bookCount < MAX_BOOKS) {
                    cout << "\nEnter Title: ";
                    getline(cin, inputTitle);
                    cout << "Enter Author: ";
                    getline(cin, inputAuthor);
                    cout << "Enter Year: ";
                    cin >> inputYear;
                    cin.ignore(); 

                    books[bookCount].setDetails(inputTitle, inputAuthor, inputYear);
                    bookCount++;
                    cout << "\nBook added successfully!" << endl;
                } else {
                    cout << "\nCannot add more books, storage is full!" << endl;
                }
                break;
            }

            case 2: {
                if (bookCount == 0) {
                    cout << "\nNo books to display!" << endl;
                } else {
                    cout << "\nDisplaying All Books:" << endl;
                    for (int i = 0; i < bookCount; i++) {
                        books[i].displayDetails();
                        cout << "---------------------" << endl;
                    }
                }
                break;
            }

            case 3: {
                cout << "\nEnter Title to Search: ";
                getline(cin, inputTitle);
                
                bool found = false;
                for (int i = 0; i < bookCount; i++) {
                    if (books[i].getTitle() == inputTitle) {
                        cout << "\nBook found:" << endl;
                        books[i].displayDetails();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "\nBook not found!" << endl;
                }
                break;
            }

            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "\nInvalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
