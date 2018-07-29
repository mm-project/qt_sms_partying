#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "requester.hpp"
#include "request.hpp"
#include "request_handler.hpp"
#include "engine.hpp"

#include <QTimer>
#include <QString>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QSslConfiguration>

#include <cassert>
#include <iostream>
#include <queue>
#include <map>

//FIXME ICONS , should be moved to application env.
//#define MACRO_ICONS_DIR "C:\\Users\\elen\\Desktop\\qt_sms\\original_sms\\qt_sms_partying\\etc\\icons\\"
#define MACRO_ICONS_DIR "C:\\Users\\levons\\Desktop\\git\\mm_project\\qt_sms_partying\\etc\\icons\\"


//FIXME issue with quotes in macro
//#define MACRO_ICONS_DIR_STR(icon) QString(QString(MACRO_ICONS_DIR)+"\"" #icon "\"")

namespace {
QString MACRO_ICONS_DIR_STR(const QString& name) { return QString(MACRO_ICONS_DIR)+name; }
}

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
		Engine* get_engine();
		void schedule_request(const Request& req);
	
		
	private slots:
		void on_request_timer_shot();
		
		
	private:
		void complete_request();
		void send_request(Request& req);
		
	private:
		//std::map<std::string,RequestHandler*> m_str2handler;
		Engine* m_engine;
		Request m_current_request;
		std::queue<Request> m_pending_requests;
		
		QTimer* m_timer;
		QSslConfiguration* ssl;
		Requester* m_requester;
		

	public:
		static Controller* m_instance;
};


#endif // CONTROLLER_HPP
