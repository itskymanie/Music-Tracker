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
    if(this != &rhs)
    {
        m_title = std::move(rhs.m_title);
        m_album = std::move(rhs.m_album);
        m_artist = std::move(rhs.m_artist);

        delete m_next;
        m_next = std::exchange(rhs.m_next, nullptr);
    }
    return *this;
}

Song& Song::operator = (const Song& rhs) 
{
    if (this != &rhs)
    {
        m_title = rhs.m_title;
        m_artist = rhs.m_artist;
        m_album = rhs.m_album;
    }

        if (rhs.m_next != nullptr)
        {
            if (m_next == nullptr)
            {
                m_next = new Song;  
            }
            *m_next = *(rhs.m_next);  
        }
        else
        {
            delete m_next;  
            m_next = nullptr;
        }
        return *this;
}
    
Song::~Song()
{
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
    delete m_next;
    m_next = nullptr;
}

bool Song::operator==(const Song& other) const 
{
    return this == &other || (this->getArtist() == other.getArtist() && this->getTitle() == other.getTitle());
}

string Song::toString()const
{
    string complete = this->getTitle() + " - " + this->getArtist() + " - " + this->getAlbum();

    return  complete;
}
   
string Song::getTitle()const
{
    return m_title;
}

string Song::getArtist()const
{
    return m_artist;
}

string Song::getAlbum()const
{
    return m_album;
}

string Song::getNextTitle() const
{
    return m_title;
}

Song* Song::getNext()const
{
    return m_next;
}

void Song::setNext(Song* nextSong)
{
    m_next = nextSong;
}

void Song::setTitle(string title)
{
    m_title = title;
}

void Song::setArtist(string artist)
{
    m_artist = artist;
}
void Song::setAlbum(string album)
{
    m_album = album;
}