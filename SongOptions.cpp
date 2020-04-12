#include "SongOptions.h"
#include "Game.h"
#include <QtMultimedia/QMediaPlayer>
extern Game * game;
using namespace std;
SongOptions::SongOptions()
{
    currentSong = new QMediaPlayer();
    startCount = 0;

//    currentSong->setMedia(QUrl::fromLocalFile("songs/intro.mp3"));
//    currentSong->setVolume(60);
//    currentSong->play();
}

void SongOptions::selectSong(int value)
{
    currentSong->stop();
    //remember to shorten later
    if (value == 1){
            currentSong->setMedia(QUrl::fromLocalFile("songs/21 - Veiled in Black (Arrangement).mp3"));
    }
    else if (value == 2){
            currentSong->setMedia(QUrl::fromLocalFile("songs/02 Battle of Oblivion.mp3"));
    }
    else if(value == 10){
        currentSong->setMedia(QUrl::fromLocalFile("songs/intro.mp3"));
    }
    else if(value == 11){
        currentSong->setMedia(QUrl::fromLocalFile("songs/outro.mp3"));
    }
    else{
            currentSong->setMedia(QUrl::fromLocalFile("songs/21 Waltzing Gallop.mp3"));
    }
     currentSong->setVolume(60);
}

void SongOptions::play()
{
    currentSong->play();
}
void SongOptions::pause(){
    currentSong->pause();
}



