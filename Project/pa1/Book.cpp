#include "Book.h"

/*
The default constructor for book class. 
The default book id is 0, 
the title and author's name should be blank, 
it should be available with 1 copy, 
and its rating should be 0.
*/
Book::Book()
    :
    bookId(0),
    title(),
    author(),
    inventoryCount(1),
    rating(0),
    ratingCount(0)
{ return; }

/*
The parametarized constructor for the book class. 
You can assume that the id will be unique for each book.
*/
Book::Book(int id, const string &t, const string &a, int count, double rat, int ratCount)
    :
    bookId(id),
    title(t),
    author(a),
    inventoryCount(count),
    rating(rat),
    ratingCount(ratCount)
{ return; }

/*
To retrieve the bookId for the Book object.
*/
int Book::getId() const
{
    return (this->bookId);
}

/*
To retrieve the inventory (number of copies) of the Book object.
*/
int Book::getInventoryCount() const
{
    return (this->inventoryCount);
}

/*
To increment the inventory (number of copies) of the Book object by c. ???
*/
void Book::changeInventoryCount(int c)
{
    this->inventoryCount += c;
    return;
}

/*
To retrieve the title of the Book object.
*/
string Book::getTitle() const
{
    return (this->title);
}

/*
To retrieve the author's name from the Book object.
*/
string Book::getAuthor() const
{
    return (this->author);
}

/*
To retrieve the rating of the Book object.
*/
double Book::getRating() const
{
    return (this->rating);
}

/*
To modify the rating of the Book object. 
The rating value should be between 0.0 and 5.0 and 
it should represent the average of all user ratings.
*/
void Book::addRating(double newRating)
{
    if (newRating < 0.0f || newRating > 5.0f) 
    {
        std::cout << "Rating must be between 0 and 5." << std::endl;
    }
    else
    {
        this->rating = ((this->rating * this->ratingCount) + newRating) / (this->ratingCount + 1);
        this->ratingCount++;
    }
    
    return;
}