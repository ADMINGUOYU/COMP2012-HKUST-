#include "User.h"
#include "Book.h"

User::User()
{
}

User::User(int id, const string &n, int borrow, int max)
{
}

User::~User()
{
}

void User::borrowBook(Book *book)
{
}

void User::returnBook(Book *book)
{
}

int User::getNumBooksBorrowed() const
{
}

int User::getUserId() const
{
}

string User::getUserName() const
{
}

int User::getMaxBooks() const
{
}

void User::viewBorrowedBooks() const
{
}

void User::giveRating(BookList &list, int bookId, double newRating)
{
}

void User::updateMaxBooks(int additionalSlots)
{
}