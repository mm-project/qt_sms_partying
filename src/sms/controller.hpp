#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "requester.hpp"
#include "request.hpp"

#include <QTimer>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QSslConfiguration>

#include <cassert>
#include <iostream>
#include <queue>

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
		void request_get_balance();
		void request_check_login(const QString& l, const QString& p);
		void request_check_price_for_country(const QString& cc);
		void request_send_sms();
		
	
		
	public slots:
		//void complete_request(const QString& req);
		void on_request_timer_shot();
		
	//FIMXE shouldn't be public	
	public:	
		void on_login_success();
		void on_login_fail(const QString&);
		void on_balance_recieved(bool, const QString&);
	
	signals:
		//FIXME go with one signal instead, and keep bool
		void login_successed();
		void login_failed(const QString&);
		
		void signal_balance_request_done(bool,const QString&);
		//void balance_successed(const QString&);
		//void balance_failed(const QString&);
		
	private:
		bool is_authorized();
		void set_authorized();
		void unset_authorized();

		
		void schedule_request(const Request& req);
		void complete_request();
		
		//FIXME ELEEN const gives compile error
		void send_request(Request& req);
		/*
		void print_json(const QJsonObject& j);
		void success_handler(const QJsonObject& j);
		void error_handler(const QJsonObject& j);
		*/
		
	private:
		std::queue<Request> m_pending_requests;
		Request m_current_request;
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
