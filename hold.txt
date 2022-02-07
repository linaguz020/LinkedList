//
// By: Angelina Guzman and Mashrul Shifat
//

#ifndef PLAYLIST_H
#define PLAYLIST_H
using namespace std;
#include <string>

class PlaylistNode {
public:
    PlaylistNode();
    PlaylistNode(string id, string songname, string artist, int length);
    void InsertAfter(PlaylistNode* ptr1);
    void SetNext(PlaylistNode* ptr);
    string GetID() const;
    string GetSongName() const;
    string GetArtistName() const;
    int GetSongLength() const;
    PlaylistNode* GetNext() const;
    void PrintPlaylistNode();

// private data members
private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;
};

class Playlist
{
private:
    PlaylistNode *head;
    PlaylistNode *tail;

public:
    Playlist();
    void AddSong(const string& id, const string& songname, const string& artistname, int length);
    void RemoveSong(const string& id);
    void PrintList();
    void ChangePosition(int oldPos, int newPos);
    void SongsByArtist(const string& artist);
    int TotalTime();
};


#endif //PLAYLIST_H
