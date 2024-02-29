# include "Song.h"


Song::Song() : m_title() , m_artist(), m_album(), m_next(nullptr)
{

}

Song::Song(string title, string artist,string album) : m_title(title) , m_artist(artist), m_album(album), m_next(nullptr)
{

}

Song::Song(const Song& other) : m_title(other.m_title) , m_artist(other.m_artist), m_album(other.m_album)
{
    // Create a deep copy of the linked list
    if (other.m_next) {
        m_next = new Song(*(other.m_next));
    }
}

Song::Song(Song&& other) noexcept : m_title(std::move(other.m_title)) , m_artist(std::move(other.m_artist)), 
                                    m_album(std::move(other.m_album)), m_next(std::exchange(other.m_next, nullptr)) 
{

}

Song& Song::operator = (Song&& rhs) noexcept
{

}
Song& Song::operator = (const Song& rhs) 
{
    if (this != &rhs) //self-assignement check
    {
         // Copy the non-pointer members
        m_title = rhs.m_title;
        m_artist = rhs.m_artist;
        m_album = rhs.m_album;
    }

        if (rhs.m_next != nullptr)
        {
            if (m_next == nullptr)
            {
                m_next = new Song;  // If m_next is null, create a new node
            }
            *m_next = *(rhs.m_next);  // Recursively copy the linked list
        }
        else
        {
            delete m_next;  // If rhs has a null m_next, make sure to delete the existing one
            m_next = nullptr;
        }
}
    
Song::~Song()
{
    // Traverse the linked list and delete each node
    Song* current = m_next;
    while (current != nullptr)
    {
        Song* next = current->m_next;
        delete current;
        current = next;
    }
}


void Song::clear()
{

}