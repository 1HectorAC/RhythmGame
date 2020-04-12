#ifndef SONGOPTIONS_H
#define SONGOPTIONS_H
#include <QtMultimedia/QMediaPlayer>
#include <QObject>
//stuff
class SongOptions
{
public:
    SongOptions();
    void selectSong(int value);
    QMediaPlayer * currentSong;
    void play();
    void pause();
    int startCount;
};

#endif // SONGOPTIONS_H
