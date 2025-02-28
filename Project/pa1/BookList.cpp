#include "BookList.h"
#include "Book.h"

BookList::BookList()
{
}

BookList::BookList(const BookList &other)
{
}

BookList::~BookList()
{
}

bool BookList::isEmpty() const
{
}

void BookList::insertBook(Book *book)
{
}

void BookList::removeBook(Book *book)
{
}

void BookList::displayBooks() const
{
}

void BookList::sortBooks(SortCriteria criteria)
{
}

Book *BookList::searchList(int bookId) const
{
}

int BookList::countBooks() const
{
}

void BookList::rateBook(int bookId, double newRating)
{
}

Book *BookList::getBookWithMaxRating() const
{
}

Book *BookList::getBookWithMinRating() const
{
}

void BookList::reverseBooksByRating()
{
}