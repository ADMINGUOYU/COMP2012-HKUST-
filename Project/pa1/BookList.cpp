#include "BookList.h"
#include "Book.h"

/*
The default constructor for BookList class.
*/
BookList::BookList()
    :
    head(nullptr)
{ return; }

/*
The copy constructor for BookList class. 
Copy constructor should be implemented as a deep copy constructor. 
Note that the book is not deep copied since there is no dynamic memory allocation in its class.
*/
BookList::BookList(const BookList &other)
{
    if (nullptr == other.head) return;

    Node* ptrTmp_other = other.head;

    //Now creates the new head
    this->head = new Node(ptrTmp_other->data);
    Node* ptrTmp_this = this->head;

    //Now creates other nodes
    while (nullptr != ptrTmp_other->next)
    {
        ptrTmp_this->next = new Node(ptrTmp_other->next->data);
        ptrTmp_this = ptrTmp_this->next;
        ptrTmp_other = ptrTmp_other->next;
    }
    return;
}

/*
The destruction function to deallocate all dynamic data.
*/
BookList::~BookList()
{
    Node* tmp = this->head;

    while (nullptr != this->head)
    {
        this->head = this->head->next;
        delete tmp;
        tmp = this->head;
    }
    
    return;
}

/*
To check whether the list of books is empty.
*/
bool BookList::isEmpty() const
{
    return ( (nullptr == this->head) ? true : false );
}

/*
To insert a Book object into the BookList data structure 
and increasing the book's inventory count if a copy already exists.
*/
void BookList::insertBook(Book *book)
{
    if (this->isEmpty())
    {
        //Empty then creates new head node
        this->head = new Node(book);
    }
    else
    {
        //BookList NOT empty
        Book* alreadyHave = this->searchList(book->getId());
        if (nullptr == alreadyHave)
        {
            //This is a new book
            //Add this book to the back of the link list
            Node* tail = this->head;
            while (nullptr != tail->next) tail = tail->next;
            Node* tmp = new Node(book);
            tail->next = tmp;
        }
        else
        {
            //This book already exists
            alreadyHave->changeInventoryCount(1);
        }
    }
    return;
}

/*
To remove a Book object from the BookList data structure. 
Note that the function needs to take into account multiple copies of the book. 
Once the number of copies reach 0, the entire book need to be removed from the list
*/
void BookList::removeBook(Book *book)
{
    Book* alreadyHave = this->searchList(book->getId());
    if (nullptr == alreadyHave)
    {
        //No such book
        //Do nothing
    }
    else
    {
        //Found the book
        alreadyHave->changeInventoryCount(-1);
        if (0 == alreadyHave->getInventoryCount())
        {
            // No book left -> the original code here cause segmentation fault
            Node* tmp = this->head;
            while ((nullptr != tmp->next) && (alreadyHave != tmp->next->data))
            { tmp = tmp->next; }
            if (tmp == this->head)
            {
                //the head
                /* corrected on the original -> test 'head' first */
                this->head = tmp->next;
                delete tmp;
            }
            else if (nullptr == tmp->next->next)
            {
                //the tail
                delete tmp->next;
                tmp->next = nullptr;
            }
            else
            {
                //in the middle
                Node* to_delete = tmp->next;
                tmp->next = tmp->next->next;
                delete to_delete;
            }

            // // corrected code
            // Node* tmp = this->head;
            // if (tmp->data == alreadyHave)
            // {
            //     //the head
            //     this->head = tmp->next;
            //     delete tmp;
            //     return;
            // }
            // while ((nullptr != tmp->next->next) && (alreadyHave != tmp->next->data))
            // { tmp = tmp->next; }
            // if (nullptr == tmp->next->next)
            // {
            //     //the tail
            //     delete tmp->next;
            //     tmp->next = nullptr;
            //     return;
            // }
            // else
            // {
            //     //in the middle
            //     Node* to_delete = tmp->next;
            //     tmp->next = tmp->next->next;
            //     delete to_delete;
            //     return;
            // }
        }
    }

    return;
}

/*
To display all the books in the BookList. 
The function should display the Book object's ID, title, author name, and rating.
*/
void BookList::displayBooks() const
{
    if (nullptr == this->head)
    {
        std::cout << "The book list is empty." << std::endl;
        return;
    }

    Node* tmp = this->head;
    while (nullptr != tmp)
    {
        std::cout 
        << "ID: " << tmp->data->getId() << " - "
        << "Title: " << tmp->data->getTitle() << " - "
        << "Author: " << tmp->data->getAuthor() << " - "
        << "Rating: " << tmp->data->getRating()
        << std::endl;

        tmp = tmp->next;
    }
    return;
}

/*
To sort the books in the BookList 
in either alphabetic order or by rating (descending order). 
The choice of whether to sort in alphabetic or by rating depends on the enum value, 
criteria.
*/
void BookList::sortBooks(SortCriteria criteria)
{
    //return if there is no or only 1 book
    if (nullptr == this->head &&
        nullptr == this->head->next)
        return;

    //Prepare working pointers
    Node* workingPtr_sorted_head = this->head;
    Node* workingPtr_sorted_tail = this->head;
    Node* workingPtr_unsorted_head = this->head->next;

    switch (criteria)
    {
    case SortCriteria::BY_RATING:
    {
        while (nullptr != workingPtr_unsorted_head)
        {
            //while inside this loop, there is/are unsorted node(s)
            if (workingPtr_sorted_tail->data->getRating() >= workingPtr_unsorted_head->data->getRating())
            {
                //we shall add the unsorted node to the end
                //if fact, the unsorted node is behind the sorted_tail
                //so, do nothing but to update working pointers
                workingPtr_unsorted_head = workingPtr_unsorted_head->next;
                workingPtr_sorted_tail = workingPtr_sorted_tail->next;
            }
            else if (workingPtr_sorted_head->data->getRating() < workingPtr_unsorted_head->data->getRating())
            {
                //we shall add the unsorted node to the head
                Node* toSort = workingPtr_unsorted_head;
                Node* start = workingPtr_sorted_head;
                Node* end = workingPtr_sorted_tail;

                end->next = workingPtr_unsorted_head->next;
                toSort->next = workingPtr_sorted_head;

                //update working pointers
                workingPtr_sorted_head = toSort;
                workingPtr_sorted_tail = end;   //does not change
                workingPtr_unsorted_head = end->next;
            }
            else
            {
                //here we shall find a right spot for the unsorted node in between
                Node* toSort = workingPtr_unsorted_head;
                Node* start = workingPtr_sorted_head;
                Node* end = workingPtr_sorted_tail;

                //update working pointers first
                end->next = workingPtr_unsorted_head->next;
                workingPtr_unsorted_head = end->next;

                Node* tmp = start;
                while (tmp->next->data->getRating() >= toSort->data->getRating()) tmp = tmp->next;
                toSort->next = tmp->next;
                tmp->next = toSort;
            }

        }

    }
        break;
    case SortCriteria::BY_TITLE:
    {
        while (nullptr != workingPtr_unsorted_head)
        {
            //while inside this loop, there is/are unsorted node(s)
            if (workingPtr_sorted_tail->data->getTitle() <= workingPtr_unsorted_head->data->getTitle())
            {
                //we shall add the unsorted node to the end
                //if fact, the unsorted node is behind the sorted_tail
                //so, do nothing but to update working pointers
                workingPtr_unsorted_head = workingPtr_unsorted_head->next;
                workingPtr_sorted_tail = workingPtr_sorted_tail->next;
            }
            else if (workingPtr_sorted_head->data->getTitle() > workingPtr_unsorted_head->data->getTitle())
            {
                //we shall add the unsorted node to the head
                Node* toSort = workingPtr_unsorted_head;
                Node* start = workingPtr_sorted_head;
                Node* end = workingPtr_sorted_tail;

                end->next = workingPtr_unsorted_head->next;
                toSort->next = workingPtr_sorted_head;

                //update working pointers
                workingPtr_sorted_head = toSort;
                workingPtr_sorted_tail = end;   //does not change
                workingPtr_unsorted_head = end->next;
            }
            else
            {
                //here we shall find a right spot for the unsorted node in between
                Node* toSort = workingPtr_unsorted_head;
                Node* start = workingPtr_sorted_head;
                Node* end = workingPtr_sorted_tail;

                //update working pointers first
                end->next = workingPtr_unsorted_head->next;
                workingPtr_unsorted_head = end->next;

                Node* tmp = start;
                while (tmp->next->data->getTitle() <= toSort->data->getTitle()) tmp = tmp->next;
                toSort->next = tmp->next;
                tmp->next = toSort;
            }

        }
    }
        break;
    default:
        //Unrecognized enum value
        return;
    }

    //update new head
    this->head = workingPtr_sorted_head;
    return;
}

/*
To search the BookList for the book, given by its bookId. 
The function returns a pointer to the Book object.
*/
Book *BookList::searchList(int bookId) const
{
    Node* tmp = this->head;
    while (nullptr != tmp)
    {
        if (bookId == tmp->data->getId()) return tmp->data;
        tmp = tmp->next;
    }
    //in case of not finding the book
    return nullptr;
}

/*
To count the total number of books (including the copies) and return an integer.
*/
int BookList::countBooks() const
{
    int totalCount = 0;
    Node* tmp = this->head;
    while (nullptr != tmp)
    {
        totalCount += tmp->data->getInventoryCount();
        tmp = tmp->next;
    }
    return totalCount;
}

/*
To find the book in the BookList and modify its rating. 
You also need to display a message 
to let the user if the book exists and what its new rating is.
*/
void BookList::rateBook(int bookId, double newRating)
{
    Book* book_to_rate = this->searchList(bookId);
    if (nullptr != book_to_rate) 
    {
        book_to_rate->addRating(newRating);
        
        //prints message
        std::cout
        << "Rating updated for Book " << book_to_rate->getId() << ". "
        << "New rating: " << book_to_rate->getRating()
        << std::endl;
    }
    else
    {
        std::cout << "Book with ID " << bookId << " not found." << std::endl;
    }
    return;
}

/*
To retrieve the book from the BookList with the highest rating.
*/
Book *BookList::getBookWithMaxRating() const
{
    if (nullptr == this->head)
    {
        std::cout << "The book list is empty." << std::endl;
        return nullptr;
    }

    Node* tmp = this->head;
    int highRating = tmp->data->getRating();
    Book* toReturn = tmp->data;
    while (nullptr != tmp)
    {
        if (highRating < tmp->data->getRating())
        {
            highRating = tmp->data->getRating();
            toReturn = tmp->data;
        }
        tmp = tmp->next;
    }
    return toReturn;
}

/*
To retrieve the book from the BookList with the lowest rating.
*/
Book *BookList::getBookWithMinRating() const
{
    if (nullptr == this->head)
    {
        std::cout << "The book list is empty." << std::endl;
        return nullptr;
    }

    Node* tmp = this->head;
    int lowRating = tmp->data->getRating();
    Book* toReturn = tmp->data;
    while (nullptr != tmp)
    {
        if (lowRating > tmp->data->getRating())
        {
            lowRating = tmp->data->getRating();
            toReturn = tmp->data;
        }
        tmp = tmp->next;
    }
    return toReturn;
}

/*
To reverse the list of books where the final result is 
the list of books in <ascending> order of ratings.
*/
void BookList::reverseBooksByRating()
{
    this->sortBooks(SortCriteria::BY_RATING);
    
    Node* workingPtr = this->head;
    Node* tmpPtr = nullptr;

    while (nullptr != workingPtr)
    {
        Node* tmp = workingPtr->next;
        workingPtr->next = tmpPtr;
        tmpPtr = workingPtr;
        workingPtr = tmp;
    }
    
    this->head = tmpPtr;
    return;
}