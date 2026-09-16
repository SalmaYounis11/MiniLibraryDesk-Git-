#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include"Item.h"
#include "Book.h"
#include "Device.h"

using namespace std;


// Find item by ID
Item* findById(vector<Item*>& shelf, int id)
{
    for (int i = 0; i < shelf.size(); i++)
    {
        if (shelf[i]->getId() == id)
        {
            return shelf[i];
        }
    }

    return nullptr;
}


// Delete all items
void freeShelf(vector<Item*>& shelf)
{
    for (int i = 0; i < shelf.size(); i++)
    {
        delete shelf[i];
    }

    shelf.clear();
}


int main()
{


    vector<Item*> shelf;

    int choice;

    do
    {
        cout << "1. Add book" << endl;
        cout << "2. Add device" << endl;
        cout << "3. List all" << endl;
        cout << "4. Find by ID" << endl;
        cout << "5. Borrow" << endl;
        cout << "6. Return" << endl;
        cout << "7. Delete" << endl;
        cout << "8. Save" << endl;
        cout << "9. Load" << endl;
        cout << "0. Quit" << endl;

        cout << "Choice: ";
        cin >> choice;


        if (choice == 1)
        {
            int id;
            string title;
            string author;

            cout << "ID: ";
            cin >> id;

            if (findById(shelf, id) != nullptr)
            {
                cout << "ID already exists" << endl;
            }
            else
            {
                cout << "Title: ";
                cin >> title;

                cout << "Author: ";
                cin >> author;

                shelf.push_back(new Book(id, title, author));

                cout << "Added." << endl;
            }
        }


        else if (choice == 2)
        {
            int id;
            string title;
            string location;

            cout << "ID: ";
            cin >> id;

            if (findById(shelf, id) != nullptr)
            {
                cout << "ID already exists" << endl;
            }
            else
            {
                cout << "Title: ";
                cin >> title;

                cout << "Location: ";
                cin >> location;

                shelf.push_back(new Device(id, title, location));

                cout << "Added." << endl;
            }
        }


        else if (choice == 3)
        {
            if (shelf.empty())
            {
                cout << "Shelf is empty." << endl;
            }
            else
            {
                for (int i = 0; i < shelf.size(); i++)
                {
                    shelf[i]->display();
                }
            }
        }


        else if (choice == 4)
        {
            int id;

            cout << "ID: ";
            cin >> id;

            Item* item = findById(shelf, id);

            if (item == nullptr)
            {
                cout << "ID not found" << endl;
            }
            else
            {
                item->display();
            }
        }


        else if (choice == 5)
        {
            int id;

            cout << "ID: ";
            cin >> id;

            Item* item = findById(shelf, id);

            if (item == nullptr)
            {
                cout << "ID not found" << endl;
            }
            else if (item->isBorrowed())
            {
                cout << "Already borrowed" << endl;
            }
            else
            {
                item->borrow();

                cout << "Borrowed." << endl;
            }
        }


        else if (choice == 6)
        {
            int id;

            cout << "ID: ";
            cin >> id;

            Item* item = findById(shelf, id);

            if (item == nullptr)
            {
                cout << "ID not found" << endl;
            }
            else if (!item->isBorrowed())
            {
                cout << "Not borrowed" << endl;
            }
            else
            {
                item->giveBack();

                cout << "Returned." << endl;
            }
        }


        else if (choice == 7)
        {
            int id;

            cout << "ID: ";
            cin >> id;

            bool found = false;

            for (int i = 0; i < shelf.size(); i++)
            {
                if (shelf[i]->getId() == id)
                {
                    delete shelf[i];

                    shelf.erase(shelf.begin() + i);

                    found = true;

                    break;
                }
            }

            if (found)
            {
                cout << "Removed." << endl;
            }
            else
            {
                cout << "ID not found" << endl;
            }
        }


        else if (choice == 8)
        {
            ofstream file("library.csv");

            for (int i = 0; i < shelf.size(); i++)
            {
                file << shelf[i]->toCsv() << endl;
            }

            file.close();

            cout << "Saved." << endl;
        }


        else if (choice == 9)
        {
            freeShelf(shelf);

            ifstream file("library.csv");

            if (!file)
            {
                cout << "No library file yet." << endl;
            }
            else
            {
                string line;

                while (getline(file, line))
                {
                    stringstream ss(line);

                    string type;
                    string idText;
                    string title;
                    string extra;
                    string borrowedText;

                    getline(ss, type, ',');
                    getline(ss, idText, ',');
                    getline(ss, title, ',');
                    getline(ss, extra, ',');
                    getline(ss, borrowedText, ',');

                    int id = stoi(idText);
                    int borrowed = stoi(borrowedText);

                    if (type == "B")
                    {
                        Book* book = new Book(id, title, extra);

                        if (borrowed == 1)
                        {
                            book->borrow();
                        }

                        shelf.push_back(book);
                    }
                    else if (type == "D")
                    {
                        Device* device = new Device(id, title, extra);

                        if (borrowed == 1)
                        {
                            device->borrow();
                        }

                        shelf.push_back(device);
                    }
                }

                file.close();

                cout << "Loaded." << endl;
            }
        }


        else if (choice == 0)
        {
            freeShelf(shelf);
        }


        else
        {
            cout << "Invalid choice." << endl;
        }

    } while (choice != 0);


    return 0;
}