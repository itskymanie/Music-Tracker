#include "include.h"

class Song 
{
    public:
    //class requirements
    Song(string title, string artist); //default ctor

    //setters and getters
    string getTitle();
    string getArtist();
    void setTitle()

    //fuctionalities
    Song * SearchBySong(string title);
    Song * SearchByArtist(string artist);
    void Add(string title, string artist);
    void BatchAdd(ifstream& file);
    void Remove(string title,string artist);
    void BatchRemove(ifstream& file);
    ofstream& Save();
    void Exit();

    private:
    string m_title;
    string m_artist;
}