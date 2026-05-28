#include <mainpage.h>

MenuPage::MenuPage(QWidget *parent) : BasePage(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    
    addButton = new QPushButton("Add notes", this);
    showButton = new QPushButton("Show notes", this);
    exitButton = new QPushButton("Exit", this);

    addButton->setFixedSize(200, 50);
    showButton->setFixedSize(200, 50);
    exitButton->setFixedSize(200, 50);
    
    watermark = new QLabel("Vingog's Production");

    QHBoxLayout *helpHLayout1 = new QHBoxLayout();
    helpHLayout1->addStretch();
    helpHLayout1->addWidget(watermark);

    titelText = new QLabel("ToDo-List");
    titelText->setStyleSheet("font: bold 24px;");

    QHBoxLayout *helpHLayout2 = new QHBoxLayout();
    helpHLayout2->addWidget(titelText, 0, Qt::AlignCenter);

    layout->addLayout(helpHLayout2);
    layout->addStretch();
    layout->addWidget(addButton, 0, Qt::AlignCenter);
    layout->addWidget(showButton, 0, Qt::AlignCenter);
    layout->addWidget(exitButton, 0, Qt::AlignCenter);
    layout->addStretch();
    layout->addLayout(helpHLayout1);
    
    setLayout(layout);

    connect(addButton, &QPushButton::clicked, this, &MenuPage::addRequested);
    connect(showButton, &QPushButton::clicked, this, &MenuPage::showRequested);
    connect(exitButton, &QPushButton::clicked, this, &MenuPage::exitRequested);
}