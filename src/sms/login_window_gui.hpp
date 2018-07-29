#ifndef LOGIN_WINDOW_GUI_HPP
#define LOGIN_WINDOW_GUI_HPP

#include "controller.hpp"
#include "request_handler.hpp"

#include <QString>
#include <QPushButton>
#include <QWidget>


class QLineEdit;

class login_window : public QWidget
{
        Q_OBJECT
		
private:
	enum state { ENABLED = 0, DISABLED };

public:
        login_window(QWidget* = 0);
		bool pre_validate();
		void post_validate(bool,const QString&);

signals:
        void accept_user();
        void change_status_bar(const QString&,bool, bool = false);
		
private slots:
		void login_button_clicked();
		void on_login_ok();
		void on_login_err();
		
		void password_changed(const QString& text);
		void username_changed(const QString& text);
		
		//void on_login_err(const QString&);
		//void post_validate(bool res, const QString& err_msg); 

private:
		void set_state(state);
		void check_can_login();

private:
        QLineEdit* m_username;
        QLineEdit* m_password;
		QPushButton* m_login_button;
		Controller* m_controller;
		RequestHandler* login_handler;
};

#endif
