#include "simple_get_handler.hpp"
#include "controller.hpp"

//void(const QJsonObject &)


SimpleGetHandler::SimpleGetHandler(const QString& ptrn):m_req_str(ptrn) {
}


void SimpleGetHandler::execute() {
	
	///FIXME check before execute, can be one of the following
	// if (!is_valid()) emit sig_err
	// if (!is_valid()) throw dddd
	// if (!is_valid()) return false
	
		
	Request* m_req = new Request(Requester::Type::GET,m_req_str,
								 std::bind(&SimpleGetHandler::on_error, this, std::placeholders::_1),
								 std::bind(&SimpleGetHandler::on_pass, this, std::placeholders::_1)
								 );
								 
	Controller::get_instance()->schedule_request(*m_req);
}
	
void SimpleGetHandler::on_error(const QJsonObject &) {
	//save string
	emit sig_err();
}

void SimpleGetHandler::on_pass(const QJsonObject &) {
	//save username password
	emit sig_pass();
}

/*
QString get_error_message() {
	return m_err_msg;
}
*/

QString& SimpleGetHandler::get_pattern() {
	return m_req_str;
}
	



