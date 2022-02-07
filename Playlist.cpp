//
// By: Angelina Guzman and Mashrul Shifat
//

#include "Playlist.h"
#include <iostream>
using namespace std;

PlaylistNode::PlaylistNode() {
    // provide default values
    this->uniqueID = "none";
    this->songName = "none";
    this->artistName = "none";
    this->songLength = 0;
    this->nextNodePtr = nullptr;
}
// PLaylistNode(id, songname, artist, length, ///////);
PlaylistNode::PlaylistNode(string id, string songname, string artist, int length) {
    // assign values to private data members
    uniqueID = id;
    songName = songname;
    artistName = artist;
    songLength = length;
    nextNodePtr = nullptr;
}
void PlaylistNode::InsertAfter(PlaylistNode *ptr1) {
    if (uniqueID == "none") { // if inserting after empty node
        this->uniqueID = ptr1->uniqueID;
        this->songName = ptr1->songName;
        this->artistName = ptr1->artistName;
        this->songLength = ptr1->songLength;
        this->nextNodePtr = ptr1->nextNodePtr;
    } else if (nextNodePtr == nullptr) { // if inserting after the tail node
        nextNodePtr = ptr1;
    } else { // inserting anywhere else
        ptr1->SetNext(nextNodePtr);
        nextNodePtr->SetNext(ptr1);
    }
}
void PlaylistNode::SetNext(PlaylistNode* ptr) {
    nextNodePtr = ptr;
}
string PlaylistNode::GetID() const {
    return uniqueID;
}
string PlaylistNode::GetSongName() const {
    return songName;
}
string PlaylistNode::GetArtistName() const {
    return artistName;
}
int PlaylistNode::GetSongLength() const {
    return songLength;
}
PlaylistNode* PlaylistNode::GetNext() const{
    return nextNodePtr;
}
void PlaylistNode::PrintPlaylistNode() {
    cout << "Unique ID: " << this->uniqueID << endl;
    cout << "Song Name: " << this->songName << endl;
    cout << "Artist Name: " << this->artistName << endl;
    cout << "Song Length (in seconds): " << this->songLength << endl;
}

Playlist::Playlist() {
    // when a new playlist is made it is empty
    head = tail = nullptr;
}

void Playlist::AddSong(const string& id, const string& songname, const string& artistname, int length) {
    // assign the parameters to a new song node
    PlaylistNode *new_song = new PlaylistNode(id, songname, artistname, length);

    if(this->head == nullptr) { // if you try to add a song to an empty playlist
        head = tail = new_song;
    } else { // otherwise the default is to append the song to the list
        tail->SetNext(new_song);
        tail = new_song; // new tail is the song that was just added
    }
}

void Playlist::RemoveSong(const string& id) {
    PlaylistNode *i;
    if (head == nullptr) { // attempting to remove from empty list
        cout << "Playlist is empty" << endl;
    } else if (head->GetID() == id) { // removing the first song
        cout << "\"" << head->GetSongName() << "\"" << " removed" << endl;
        head = head->GetNext();
    } else { // all other cases
        for (i = head; i->GetNext() != nullptr; i = i->GetNext()) { // for loop keep track of the nodes
            if (i->GetNext()->GetID() == id) {
                cout << "\"" << i->GetNext()->GetSongName() << "\"" << " removed." << endl;
                if (i->GetNext() == tail) { // removing the tail
                    tail = i;
                    i->SetNext(nullptr);
                    break;
                } else {
                    PlaylistNode *hold = i->GetNext()->GetNext();
                    i->SetNext(hold);
                }
            }
        }
    }
    cout << "\n";
}
void Playlist::PrintList() {
    if (head == nullptr) { // the head is only nullptr when it is first created (aka empty)
        cout << "Playlist is empty" << endl;
    } else {
        PlaylistNode *i;
        int count = 1; // labels for the songs in the playlist
        for (i = head; i != nullptr; i = i->GetNext()) {
            cout << count << "." << endl;
            count++;
            i->PrintPlaylistNode();
            if (i->GetNext() != nullptr) {
                cout << "\n";
            }
        }
    }
    cout << "\n";
}

void Playlist::ChangePosition(int oldPos, int newPos) {
    PlaylistNode *i;
    int numSongs = 0;
    for (i = head; i != nullptr; i = i->GetNext()) {
        numSongs++;
    }

    // check the boundaries
    if (oldPos < 1) {
        oldPos = 1;
    }
    if (newPos > numSongs) {
        newPos = numSongs;
    }
    // keeping track of all of the positions
    PlaylistNode *remove;
    PlaylistNode *middle;
    PlaylistNode *endNode;
    PlaylistNode *keep;
    int count = 0;
    for (i = head; i != nullptr; i = i->GetNext()) {
        count++;
        if (count == (oldPos - 1)) {
            keep = i;
        }
        if (count == oldPos) {
            remove = i;
        }
        if ((count == newPos - 1) && (newPos != 1)) {
            middle = i;
        }
        if (count == newPos) {
            endNode = i;
        }
    }
    PlaylistNode *newnode = new PlaylistNode(remove->GetID(), remove->GetSongName(), remove->GetArtistName(), remove->GetSongLength());
    bool flag = false;
    if (newPos - oldPos > 0) {
        flag = true;
    }

    if (remove == head) {
        head = head->GetNext();
    } else if (remove == tail) {
        tail = keep;
        tail->SetNext(nullptr);
    } else {
        PlaylistNode *hold = remove->GetNext();
        keep->SetNext(hold);
    }

    if (endNode == tail) {
        tail->SetNext(newnode);
        tail = newnode;
    } else if (endNode == head) {
        newnode->SetNext(head);
        head = newnode;
    } else {
        if (flag) {
            PlaylistNode *hold = endNode->GetNext();
            endNode->SetNext(newnode);
            newnode->SetNext(hold);
        } else {
            PlaylistNode *hold = middle->GetNext();
            middle->SetNext(newnode);
            newnode->SetNext(hold);
        }

    }
    cout << "\"" << remove->GetSongName() << "\"" << " moved to position " << newPos << endl;
    cout << "\n";
}

void Playlist::SongsByArtist(const string& artist) {
    cout << "\n";
    PlaylistNode *i;
    int count = 1; // prints out the labels
    for (i = head; i != nullptr; i = i->GetNext()) {
        if (i->GetArtistName() == artist) {
            cout << count << "." << endl;
            i->PrintPlaylistNode();
            cout << endl;
        }
        count++; // increment label regardless
    }
}

int Playlist::TotalTime() {
    PlaylistNode *i;
    int sum = 0;
    for (i = head; i != nullptr; i = i->GetNext()) {
        sum += i->GetSongLength();
    }
    return sum;
}