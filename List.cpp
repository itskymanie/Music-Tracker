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


List& List::operator = (List&& rhs) noexcept // move assignement
{
    if(this != &rhs)
    {
        m_head= std::exchange(rhs.m_head, nullptr);
    }
    return *this;
}

List& List::operator = (const List & rhs) // = assignnemnt operator
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

Song* List::SearchBySong(const string& title) const
{
    bool found = false;
    Song* current = m_head;

    while(current && found == false)
    {
        if (_stricmp(current->getTitle().c_str(), title.c_str()) == 0 )
        {
            found = true;
        }
        current = current->getNext();
    }
    return current;
}

Song* List::SearchByArtist(const string& artist) const
{
    bool found = false;
    Song* current = m_head;

    while(current && found == false)
    {
        if (_stricmp(current->getArtist().c_str(), artist.c_str()) == 0 )
        {
            found = true;
        }
        current = current->getNext();
    }
    return current;
}
Song* List::SearchByAlbum(const string& album) const
{
    bool found = false;
    Song* current = m_head;

    while(current && found == false)
    {
        if (_stricmp(current->getAlbum().c_str(), album.c_str()) == 0 )
        {
            found = true;
        }
        current = current->getNext();
    }
    return current;
}

void List::Add(const string& title, const string& artist, const string& album)
{
    Song* newSong  = new Song(title, artist, album);

    if(m_head)
    {
        Song* travel = m_head;
        Song* trail = nullptr;
        while (travel && (_stricmp(travel->getTitle().c_str(),title.c_str()) <=0 ))
        {
            trail = travel;
            travel =travel->getNext();
        }
        newSong->setNext(travel);
        trail->setNext(newSong); 
    }
    else 
    {
        m_head = newSong;
    }
}


void List::Remove(const string& title, const string& artist)
{
    if(!m_head)
    {
        cout << "\nList is empty" << endl;
    }
    else if((_stricmp(m_head->getTitle().c_str(), title.c_str()) ==0 ) 
         && (_stricmp(m_head->getArtist().c_str(), artist.c_str()) ==0 ))
    {
        Song* trail = m_head;
        m_head = m_head->getNext();
        delete trail;
    }
    else
    {
        Song* travel = m_head;
        Song* trail = nullptr;
        while (travel && (_stricmp(travel->getTitle().c_str(),title.c_str()) !=0 ) 
               && (_stricmp(travel->getArtist().c_str(), artist.c_str()) !=0 ))
        {
            trail = travel;
            travel =travel->getNext();
        }

        if (travel)
        {
            trail->setNext(travel->getNext()) ;
            delete travel;
        }
        else
        {
            cout<< "\nSong not found!!" << endl;
        }
    }
    
}