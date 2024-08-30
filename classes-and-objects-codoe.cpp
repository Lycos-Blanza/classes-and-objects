#include <iostream>
#include <iomanip>
using namespace std;

class Book {
    private:
        string title;  
        string author;  
        int year;      

    public:
        /* 
         * This method /part sets the title, author, and year of the book.
         * It takes three parameters: t (title), a (author), and y (year),
         * and assigns them to the respective private members.
         */
        void setDetails(string t, string a, int y) {
            title = t;
            author = a;
            year = y;
        }

        /*
         * This method displays the details of the book.
         * It prints the title, author, and year in a formatted way.
         */
        void displayDetails() {	
        	cout << left << setw (20) << title << left << setw (20) << author << left << setw (20) << year << endl;
        }

        /*
         * This method returns the title of the book.
         * It is used when searching for a book by title.
         */
        string getTitle() {
            return title;
        }
};

int main() {
    const int MAX_BOOKS = 100;  // Maximum number of books that can be stored
    Book books[MAX_BOOKS];      // Array to store Book objects
    int bookCount = 0;          // Counter of the boks added

	// Variables to store the user's menu choice
    int choice;                
    string inputTitle;          
    string inputAuthor;         
    int inputYear;              

    do {
        // Display the menu
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
                /*
                 * Allows user to enter a book to add.
                 * Then the user is prompted to enter the title, author, and year of the book.
                 * If the bookCount is less than MAX_BOOKS, the book is added to the array.
                 */
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
                /*
                 * This case displays all the books in the list.
                 * It iterates over the books array and calls displayDetails()
                 */
                if (bookCount == 0) {
                    cout << "\nNo books to display!" << endl;
                } else {
                    cout << "\nDisplaying All Books:" << endl;
                    cout << left << setw (20) << "Title" << left << setw (20) << "Author" << left << setw (20) << "Year" << endl;
                    for (int i = 0; i < bookCount; i++) {
                        books[i].displayDetails();
                    }
                }
                break;
            }

            case 3: {
                /*
                 * This case allows the user to search for a book by title.
                 * It then checks each book in the array and displays the details
                 * if a match is found.
                 */
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
                // This case exits the program.
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "\nInvalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
