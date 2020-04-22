#include "SongOptions.h"
#include "Game.h"
#include <QtMultimedia/QMediaPlayer>

extern Game * game;

using namespace std;

SongOptions::SongOptions()
{
    currentSong = new QMediaPlayer();

    //Used to delay start the song. Need to adjust how works.
    startCount = 0;

}

//Get a certain song by entering a certain value.
void SongOptions::selectSong(int value)
{
    //Stop current song incase one is already playing.
    currentSong->stop();

    if (value == 1){
            currentSong->setMedia(QUrl::fromLocalFile("songs/song1.mp3"));
    }
    else if (value == 2){
            currentSong->setMedia(QUrl::fromLocalFile("songs/song2.mp3"));
    }
    else if(value == 10){
        currentSong->setMedia(QUrl::fromLocalFile("songs/intro.mp3"));
    }
    else if(value == 11){
        currentSong->setMedia(QUrl::fromLocalFile("songs/outro.mp3"));
    }
    else{
            currentSong->setMedia(QUrl::fromLocalFile("songs/song3.mp3"));
    }
     currentSong->setVolume(60);
}

//Play current song.
void SongOptions::play()
{
    currentSong->play();
}

//Pause current song.
void SongOptions::pause(){
    currentSong->pause();
}



