#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "requester.hpp"

#include <QTimer>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QSslConfiguration>

#include <cassert>
#include <iostream>

class Controller :  public QObject
{
    Q_OBJECT
	
	public:
		static Controller* get_instance() {
			if ( m_instance ) return m_instance;
			m_instance = new Controller;
			return m_instance;
		}
		
	public:
		Controller(); 
		
	public:	
		void get_balance();
		void check_login(const QString& l, const QString& p);

	
		
	public slots:
		//void complete_request(const QString& req);
		void complete_request();
		void on_login_success();
		void on_login_fail(const QString&);
	
	signals:
		void login_successed();
		void login_failed(const QString&);
		
	private:
		bool is_authorized();
		void set_authorized();
		void unset_authorized();

		void schedule_request(const QString& req);
		void print_json(const QJsonObject& j);
		void success_handler(const QJsonObject& j);
		void error_handler(const QJsonObject& j);
		
	private:
		QString m_current_request;
		handleFunc m_current_err_handler;
		handleFunc m_current_ok_handler;
		
		
		QTimer* m_timer;
		QSslConfiguration* ssl;
		Requester* m_requester;
		
		QString m_username;
		QString m_password;
		bool is_auth;
		
		

	public:
		static Controller* m_instance;
};


#endif // CONTROLLER_HPP
