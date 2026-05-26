#ifndef BASEWIN_H
#define BASEWIN_H

#include <QWidget>
#include <QVBoxLayout>

class BaseWindow : public QWidget 
{
    Q_OBJECT
    
protected:
    int const WIN_W = 800;
    int const WIN_H = 600;
    QVBoxLayout *mainlayout;

public:
    explicit BaseWindow(QWidget *parent = nullptr) : QWidget(parent) {
        mainlayout = new QVBoxLayout(this);
        setLayout(mainlayout);
        resize(WIN_W, WIN_H);
    }

    virtual ~BaseWindow() {}

    virtual void setupUI() = 0;
    virtual void connectSignals() = 0;
    virtual void applyStyles() {}
    virtual void setupShortcuts() {}
};
#endif