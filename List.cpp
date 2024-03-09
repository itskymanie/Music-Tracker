#include "List.h"

List::List() : m_head(nullptr)
{

}

List::List(const List & copy) :m_head(nullptr)  // copy ctor
{
    if(copy.m_head != nullptr)
    {
        m_head= new Song(*(copy.m_head));
        //next to be copied
        Song* currentCopy = copy.m_head->getNext();
        //current being appended to
        Song* currentNew = m_head;

        while (currentCopy != nullptr)
        {
            //while not at end
            //set the next song to be same as the current to be copied
            currentNew->setNext(new Song(*(currentCopy)));
            //sets to be copied to next in line
            currentCopy = currentCopy->getNext();
            //appends next to the end of the list
            currentNew = currentNew->getNext();
        }
    }
}

List::List(List&& other) noexcept : m_head(nullptr)
{
    m_head = std::exchange(other.m_head, nullptr);
}


List& List::operator = (List&& rhs) noexcept : m_head(nullptr)// move assignement
{
    if(this != &rhs)
    {
        m_head= std::exchange(rhs.m_head, nullptr)
    }
    return *this;
}

List& List::operator = (const List & rhs) : m_head (nullptr) // = assignnemnt operator
{
    if (this != &rhs)
    {
        //clear existing list
        delete m_head;

        if (rhs.m_head != nullptr)
        {
             // Create a deep copy of the linked list
            m_head = new Song(*rhs.m_head);

            //next to be copied
            Song* currentCopy = rhs.m_head->getNext();
            //current being appended to
            Song* currentNew = m_head;

            while (currentCopy != nullptr)
            {
                //while not at end
                //set the next song to be same as the current to be copied
                currentNew->setNext(new Song(*(currentCopy)));
                //sets to be copied to next in line
                currentCopy = currentCopy->getNext();
                //appends next to the end of the list
                currentNew = currentNew->getNext();
            }
        }
    }
    return *this;
}

List::~List() // dtor
{
    while (m_head != nullptr)
    {
        Song* current = m_head;
        m_head = m_head->getNext();
        delete current;  // This will call the destructor of the Song class
    };  
}