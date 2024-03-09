#pragma once
#include "include.h"
#include "Song.h"

class List
{
public:
    // class requirements
    List();// default ctor
    List(const List & copy); // copy ctor
    List(List&& other) noexcept; //move ctor
    List& operator = (List&& rhs) noexcept; // move assignement
    List& operator = (const List & rhs); // = assignnemnt operator
    ~List(); // dtor

    //fuctionalities
    Song *SearchBySong(const string& title) const;
    Song *SearchByArtist(const string& artist) const;
    Song *SearchByAlbum(const string& album) const;

    void Add(const string& title, const string& artist, const string& album);
    void Remove(const string& title, const string& artist);

    void BatchAdd(ifstream& file);
    void BatchRemove(ifstream& file);

    bool isEmpty() const;
    size_t Size() const;

    void Save(ostream& os) const;
    void Exit();
    ostream& operator<<(ostream& os) const;

private:
    Song * m_head;
};