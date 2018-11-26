#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(500,500);
    piclabel=new QLabel(this);
    piclabel->setFixedSize(120,120);
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("D:\\QT/myproject/minions/minions.jpg");
    painter.drawPixmap(piclabel->x(),piclabel->y(),piclabel->width(),piclabel->height(),pix);
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    int x = 0;
    int y = 0;
    switch(event->key())
    {
        case Qt::Key_Up:
            y = piclabel->y() - 30;
            if(y > -10)
            {
                piclabel->move(piclabel->x(),y);
            }
            break;
        case Qt::Key_Down:
            y = piclabel->y() + 30;
            if(y < this->height() - 40)
            {
                piclabel->move(piclabel->x(),y);
            }
            break;
        case Qt::Key_Right:
            x = piclabel->x() + 30;
            if(x < this->width() - 40)
            {
                piclabel->move(x,piclabel->y());
            }
            break;
        case Qt::Key_Left:
            x = piclabel->x() - 30;
            if(x > -10)
            {
                piclabel->move(x,piclabel->y());
            }
            break;
        default:
            break;
    }
}

void Widget::keyReleaseEvent(QKeyEvent *event)
{

}
Widget::~Widget()
{

}
