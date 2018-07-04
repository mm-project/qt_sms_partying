#include "send_window_gui.hpp"

#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSizePolicy>
#include <QGroupBox>
#include <QTextEdit>

send_window::send_window(QWidget* parent)
        : QWidget(parent)
{
        QGridLayout* grid = new QGridLayout;

        QLineEdit* from = new QLineEdit(this);
        QLineEdit* to = new QLineEdit(this);
        QLabel* from_l = new QLabel("From:", this);
        QLabel* to_l = new QLabel("To:", this);
        QLabel* message_l = new QLabel("Message:", this);
        QTextEdit* text = new QTextEdit(this);
        QPushButton* button = new QPushButton("Send", this);
        button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

        grid->addWidget(from_l, 0, 0, Qt::AlignRight);
        grid->addWidget(from, 0, 1);
        grid->addWidget(to_l, 1, 0, Qt::AlignRight);
        grid->rowStretch(60);
        grid->addWidget(to, 1, 1);
        grid->addWidget(message_l, 2, 0);
        grid->addWidget(text, 3, 0, 1, 2);
        grid->addWidget(button, 4, 1, Qt::AlignRight);

        QVBoxLayout* v_l = new QVBoxLayout;
        v_l->addLayout(grid);
        setLayout(v_l);
}


