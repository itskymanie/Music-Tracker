#include "include.h"

class Song 
{
    public:
    //class requirements
    Song(string title, string artist,string album); //default ctor
    Song(const Song& other);
    Song(Song&& other) noexcept;
    Song& operator = (Song&& other) noexcept;
    Song& operator = (const Song& other);
    ~Song();
    void clear();

    // for debugging
    bool operator ==(const Song& other) const;
    string toString()const;

    //getters 
    string getTitle()const;
    string getArtist()const;
    string getAlbum()const;
    string getNextTitle() const;
    Song* getNext()const;

    //setters
    void setNext(Song* nextSong);
    void setTitle(string title);
    void setArtist(string artist);
    void setAlbum(string album);
    

    private:
    string m_title;
    string m_artist;
    string m_album;
    Song* m_next;

};