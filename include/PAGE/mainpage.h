#ifndef MAINPAGE_H
#define MAINPAGE_H

#include "basepage.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

class MenuPage : public BasePage 
{
    Q_OBJECT

public:
    explicit MenuPage(QWidget *parent = nullptr);
    
    QPushButton *addButton;
    QPushButton *showButton;
    QPushButton *exitButton;
    QLabel *watermark;
    QLabel *titelText;

};
#endif