#ifndef PHOTO_H
#define PHOTO_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>
class photo : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit photo(QObject *parent = 0,const QPixmap& map = {});
};

#endif // PHOTO_H
