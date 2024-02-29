#include "include.h"

class Song 
{
    public:
    //class requirements
    Song(string title, string artist,string album); //default ctor
    ~Song();

    //setters and getters
    string getTitle();
    string getArtist();
    void setTitle(string title);
    void setArtist(string artist);
    void setAlbum(string album);

    //fuctionalities
    Song * SearchBySong(string title);
    Song * SearchByArtist(string artist);
    Song * SearchByAlbum(string album);
    void Add(string title, string artist, string album);
    void BatchAdd(ifstream& file);
    void Remove(string title, string artist);
    void BatchRemove(ifstream& file);
    ofstream& Save();
    void Exit();

    private:
    string m_title;
    string m_artist;
    string m_album;

};