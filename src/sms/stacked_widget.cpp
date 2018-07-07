#include "stacked_widget.hpp"

#include "login_window_gui.hpp"
#include "send_window_gui.hpp"

#include <QStackedLayout>

stacked_widget::stacked_widget(QWidget* parent)
        : QWidget(parent)
{
        m_layout = new QStackedLayout;
        m_login = new login_window(this);
        m_send = new send_window(this);
        m_layout->addWidget(m_login);
        m_layout->addWidget(m_send);
        m_layout->setCurrentWidget(m_login);
        setLayout(m_layout);

        connect(m_login, SIGNAL(accept_user()), this, SLOT(change_window()));
        connect(m_login, SIGNAL(change_status_bar(const QString&)), this, SLOT(update_statusbar(const QString&)));
}

void stacked_widget::change_window()
{
        m_layout->setCurrentWidget(m_send);
        emit status_bar_changed("Current balance: ", false); //getBalance
}

void stacked_widget::update_statusbar(const QString& s)
{
        emit status_bar_changed(s, true);
}
