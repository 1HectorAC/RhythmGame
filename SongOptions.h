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
    void play();
    void pause();

    QMediaPlayer * currentSong;
    int startCount;
};

#endif // SONGOPTIONS_H
