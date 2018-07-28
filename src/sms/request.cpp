#include "requester.hpp"
#include "request.hpp"


Request::Request(Requester::Type t, const QString& str, handleFunc errhnd, handleFunc okhnd ) {

	m_type = t;
	m_request_str = str;
	m_err_hndl = errhnd;
	m_ok_hndl = okhnd;
	m_have_data = false;
	
}

Request::Request(Requester::Type t, const QString& str, handleFunc errhnd, handleFunc okhnd, const QVariantMap& data  ) {

	m_type = t;
	m_request_str = str;
	m_err_hndl = errhnd;
	m_ok_hndl = okhnd;
	m_post_data = data;
	m_have_data	= true;
}


bool Request::have_data() { return m_have_data; }
QString Request::get_str() { return m_request_str; }
Requester::Type Request::get_type() { return m_type; }
handleFunc Request::get_ok_handler() { return m_ok_hndl; }
handleFunc Request::get_err_handler() { return m_err_hndl; }
QVariantMap Request::get_post_data() { return m_post_data; };
		
				

