#include "request_handler.hpp"


//void(const QJsonObject &)

LoginHandler::LoginHandler() {
		m_req_str = "account/get-balance/%1/%2";
}


void LoginHandler::execute() {
	//Request m_req = new Request(Requester::Type::GET,m_req_str,reinterpret_cast<handleFunc>(&(LoginHandler::on_error)),reinterpret_cast<handleFunc>(&(LoginHandler::on_pass)));
	
	Request m_req = new Request(Requester::Type::GET,m_req_str,std::bind(on_error),std::bind(on_pass);
	Controller::get_instance()->schedule_request(*m_req);
}
	
void LoginHandler::on_error(const QJsonObject &) {
	emit sig_err();
}

void LoginHandler::on_pass(const QJsonObject &) {
	emit sig_pass();
}

/*
QString get_error_message() {
	return m_err_msg;
}
*/

void LoginHandler::add_param(const QString& s) {
	m_req_str.arg(s);
}
	



