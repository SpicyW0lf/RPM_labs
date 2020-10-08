#include "photo.h"
#include <QDebug>
#include <QGraphicsScene>
photo::photo(QObject *parent,const QPixmap& map) :
    QObject(parent), QGraphicsPixmapItem(map)
{

}
