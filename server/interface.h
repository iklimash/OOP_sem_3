#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>

class interface : public QWidget
{
    Q_OBJECT

public:
    interface(QWidget *parent = nullptr);
    ~interface();
};
#endif // INTERFACE_H
