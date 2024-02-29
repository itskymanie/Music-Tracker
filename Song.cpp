# include "Song.h"

Song::Song(string title, string artist,string album) : m_title(title) , m_artist(artist), m_album(album), m_next(nullptr)
{

}

Song::~Song()
{

}

