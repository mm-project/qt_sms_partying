#include "login_window_gui.hpp"

#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSizePolicy>
#include <QGroupBox>

login_window::login_window(QWidget* parent)
        : QWidget(parent)
{
        QGridLayout* layout = new QGridLayout;
        m_username = new QLineEdit(this);
        m_password = new QLineEdit(this);
        QPushButton* button = new QPushButton("Login", this);
        button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        QLabel* username_label = new QLabel("Username:", this);
        QLabel* password_label = new QLabel("Password:", this);
        layout->addWidget(username_label, 0, 0, Qt::AlignRight);
        layout->addWidget(m_username, 0, 1);
        layout->addWidget(password_label, 1, 0, Qt::AlignRight);
        layout->addWidget(m_password, 1, 1);
        layout->addWidget(button, 2, 1, Qt::AlignRight);
        layout->rowStretch(4);
        QVBoxLayout* main_layout =  new QVBoxLayout;
        main_layout->addLayout(layout);
        QGroupBox* box = new QGroupBox("add me!");
        box->setLayout(main_layout);
        box->setFlat(false);
        QHBoxLayout* l = new QHBoxLayout;
        l->addWidget(box);
        setLayout(l);

        connect(button, SIGNAL(clicked()), this, SLOT(validate()));
}

void login_window::validate()
{
        // engine . if true
        //emit accept_user();

        //if flase update status bar
        emit change_status_bar("Error!");
}
