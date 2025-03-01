#include "Library.h"

// Constructor
/*
The default constructor for Library class, 
assigning the number of users to 0, 
capacity to initialCapacity, 
and total revenue to 0.
*/
Library::Library(int initialCapacity)
    :
    users(nullptr),
    userCount(0),
    capacity(initialCapacity),
    totalRevenue(0),
    libraryInventory()
{ 
    this->users = new User*[this->capacity];
    return; 
}

// Destructor
/*
The destructor of the Library class.
*/
Library::~Library()
{
    for (int i = 0; i < this->userCount; i++)
    {
        delete this->users[i];
    }
    delete [] this->users;
    return;
}

/*
The function to add a user to the library assigning it an id and name. 
If the library has reached its maximum capacity, 
the function should dynamically allocate extra memory by doubling it. 
Additionally, for each user added, increase the total revenue by 5 dollars.
*/
void Library::addUser(int id, const string &name)
{
    //try to find if the id exists
    if (nullptr != this->getUserById(id)) return; //the user id already exists

    //if no space available
    if (this->userCount >= this->capacity)
    {
        User** newArr = new User*[this->capacity * 2];
        for (int i = 0; i < this->capacity; i++) newArr[i] = this->users[i];
        delete [] this->users;
        this->users = newArr;
        this->capacity *= 2;
    }

    //create new user
    this->users[this->userCount] = new User(id, name);
    this->userCount++;

    //increase total revenue
    this->totalRevenue += 5;

    return;
}

/*
The function to increase the number of maximum books for a user in the library. 
For each increment, the library gets an additional 1 dollar in revenue.
*/
void Library::upgradeUserSlots(int userId, int additionalSlots)
{
    //find that user first
    User* target = this->getUserById(userId);

    if (nullptr == target) return; //not found

    //add slots
    target->updateMaxBooks(additionalSlots);

    //add revenue
    this->totalRevenue += (1 * additionalSlots);

    //print message
    std::cout << "User ID " << userId << " upgraded by " << additionalSlots << " slots." << std::endl;

    return;
}

/*
The function to retrieve the total revenue of the library.
*/
double Library::getTotalRevenue() const
{
    return (this->totalRevenue);
}

/*
The function to display all the users in the library. 
The function should display information, 
including the user's id, name, the number of books they have borrowed, and the maximum number of books they can borrow.
*/
void Library::displayUsers() const
{
    for (int i = 0; i < this->userCount; i++)
    {
        std::cout
            << "User ID: " << this->users[i]->getUserId() << ", "
            << "Name: " << this->users[i]->getUserName() << ", "
            << "Borrowed Books: " << this->users[i]->getNumBooksBorrowed() << ", "
            << "Max Books: " << this->users[i]->getMaxBooks()
            << std::endl;
    }
    return;
}

/*
The function to retrieve the user in the library by their id.
*/
User *Library::getUserById(int userId) const
{
    //find that user first
    int target_user = -1;
    for (int i = 0; i < this->userCount; i++)
    {
        if (userId == this->users[i]->getUserId())
        {
            target_user = i;
            break;
        }
    }
    if (-1 == target_user) return nullptr; //not found

    return this->users[target_user];
}

/*
The function to add a new book to the library. 
For each new book added, the library needs to pay 2 dollars.
*/
void Library::addNewBook(Book *book)
{
    this->libraryInventory.insertBook(book);
    this->totalRevenue -=2;
    std::cout << "Book '" << book->getTitle() << "' added to the library." << std::endl;
    return;
}

/*
The function to remove the book (including all its copies) from the library. 
For <each book> removed, the library earns back 1 dollar.
*/
void Library::removeBook(int bookId)
{
    Book* bookPtr = this->libraryInventory.searchList(bookId);
    int count = bookPtr->getInventoryCount();
    for (int i = 0; i < count; i++)
    {
        this->libraryInventory.removeBook(bookPtr);
        this->totalRevenue += 1;
    }
    return;
}

/*
The function to display all the books in the library. 
Note the library only has one big collection of books.
*/
void Library::displayBooks() const
{
    std::cout << "Library Book Details:" << std::endl;
    this->libraryInventory.displayBooks();
    return;
}

/*
The function to retrieve the list of books in the library. 
This function returns a reference to that list of books.
*/
BookList &Library::getLibraryInventory()
{
    return (this->libraryInventory);
}