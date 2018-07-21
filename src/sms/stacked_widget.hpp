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
        void status_bar_changed(const QString&, bool = false, bool = false);

		
private slots:
        void on_balance_response_availble(bool, const QString&);
		
		void change_window();
        void update_statusbar(const QString&, bool = false, bool = false);

private:
        login_window* m_login;
        send_window* m_send;
        QStackedLayout* m_layout;
};

#endif
