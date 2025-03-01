#include "User.h"
#include "Book.h"

/*
The default constructor for the User class. 
The default id is 0, 
the name should be blank, 
the number of books borrowed should be 0, 
and the maximum number of books borrowed should be 5.
*/
User::User()
    :
    userId(0),
    name(),
    numBooksBorrowed(0),
    maxBooks(5),
    booksBorrowed(nullptr)
{ return; }

/*
The parametarized constructor for the User class. 
You can assume that the id will be unique for each User.
*/
User::User(int id, const string &n, int borrow, int max)
    :
    userId(id),
    name(n),
    numBooksBorrowed(borrow),
    maxBooks(max),
    booksBorrowed(nullptr)
{ return; }

/*
The destructor of the User class.
*/
User::~User()
{
    delete [] this->booksBorrowed;
    return;
}

/*
The function to allow the user to borrow the book 
if they are not blocked and update the user's list of books.
*/
void User::borrowBook(Book *book)
{
    //exceeding limit
    if (this->numBooksBorrowed >= this->maxBooks)
    {
        std::cout << "You cannot borrow more books." << std::endl;
        return;
    }

    //if the book is unavailable
    if (0 >= book->getInventoryCount())
    {
        std::cout << "This book is currently unavailable." << std::endl;
        return;
    }

    //borrow the book
    Book ** newArr = new Book*[this->numBooksBorrowed + 1];
    for (int i = 0; i < this->numBooksBorrowed; i++) newArr[i] = this->booksBorrowed[i];
    delete [] this->booksBorrowed;
    this->booksBorrowed = newArr;
    this->booksBorrowed[this->numBooksBorrowed] = book;
    this->numBooksBorrowed++;
    //update inventory status
    book->changeInventoryCount(-1);

    //print message
    std::cout << "Successfully borrowed: " << book->getTitle() << std::endl;

    return;
}

/*
The function to allow the user to return a book and update the user's list of books.
*/
void User::returnBook(Book *book)
{
    //find the book first
    int place_in_arr = -1;
    for (int i = 0; i < this->numBooksBorrowed; i++)
    {
        if (book == this->booksBorrowed[i])
        {
            place_in_arr = i;
            break;
        }
    }
    if (-1 == place_in_arr) return; //book not borrowed

    //shink the array
    for (int i = place_in_arr; i < this->numBooksBorrowed - 1; i++) this->booksBorrowed[i] = this->booksBorrowed[i + 1];

    //return the book
    Book ** newArr = new Book*[this->numBooksBorrowed - 1];
    for (int i = 0; i < this->numBooksBorrowed - 1; i++) 
    {
        newArr[i] = this->booksBorrowed[i];
    }
    delete [] this->booksBorrowed;
    this->booksBorrowed = newArr;
    this->numBooksBorrowed--;
    //update inventory status
    book->changeInventoryCount(1);

    //print message
    std::cout << "Successfully returned: " << book->getTitle() << std::endl;

    return;
}

/*
The function to retrieve the number of books borrowed by the user.
*/
int User::getNumBooksBorrowed() const
{
    return (this->numBooksBorrowed);
}

/*
The function to retrieve the user id.
*/
int User::getUserId() const
{
    return (this->userId);
}

/*
The function to retrieve the user's name.
*/
string User::getUserName() const
{
    return (this->name);
}

/*
The function to retrieve information on 
what is the maximum number of books the user can borrow.
*/
int User::getMaxBooks() const
{
    return (this->maxBooks);
}

/*
The function to display information about the borrowed books. 
It should mention the name of the book and its number of copies borrowed.
*/
void User::viewBorrowedBooks() const
{
    //if no book is borrowed
    if (0 >= this->numBooksBorrowed)
    {
        std::cout << this->name << " has not borrowed any books." << std::endl;
        return;
    }

    std::cout
        << this->name << "'s Borrowed Books:"
        << std::endl;
    
    bool duplicateFlag = false;

    for (int i = 0; i < this->numBooksBorrowed; i++)
    {
        int count = 0;
        for (int j = 0; j < this->numBooksBorrowed; j++)
        {
            if (this->booksBorrowed[j]->getId() == this->booksBorrowed[i]->getId())
            {
                if (j < i) { duplicateFlag = true; break;}
                else count++;
            }
        }
        if (duplicateFlag)
        { duplicateFlag = false; continue; }
        else
        {
            std::cout
                << this->booksBorrowed[i]->getTitle()
                << " (x" << count << ")"
                << std::endl;
        }
    }
    return;
}

/*
The function to allow the user to give a rating to a book in the book list using its bookId. 
Note that a user does need to borrow a book to rate it.
*/
void User::giveRating(BookList &list, int bookId, double newRating)
{
    /*
    //find the book first
    int place_in_arr = -1;
    for (int i = 0; i < this->numBooksBorrowed; i++)
    {
        if (bookId == this->booksBorrowed[i]->getId())
        {
            place_in_arr = i;
            break;
        }
    }
    if (-1 == place_in_arr) return; //book not borrowed
    */
   
    list.rateBook(bookId, newRating);
    return;
}

/*
The function to update the maximum number of books the user can borrow. 
The maximum number of books can only increase and never decrease.
*/
void User::updateMaxBooks(int additionalSlots)
{
    if (additionalSlots <= 0) return;
    this->maxBooks += additionalSlots;
    std::cout << "Max books updated to: " << this->maxBooks << std::endl;
    return;
}