#ifndef STACKED_WIDGET_HPP
#define STACKED_WIDGET_HPP

class login_window;
class send_window;
class QStackedLayout;

#include <QWidget>

class stacked_widget : public QWidget
{
        Q_OBJECT

public:
        stacked_widget(QWidget* = 0);

signals:
        void status_bar_changed(const QString&, bool);

private slots:
        void change_window();
        void update_statusbar(const QString&);

private:
        login_window* m_login;
        send_window* m_send;
        QStackedLayout* m_layout;
};

#endif