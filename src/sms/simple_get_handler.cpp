#include "simple_get_handler.hpp"
#include "controller.hpp"

//void(const QJsonObject &)

//FIXME remove if not debug
#include <iostream>

SimpleGetHandler::SimpleGetHandler(const QString& ptrn):m_pattern_str(ptrn) {
}


void SimpleGetHandler::execute() {
	
	///FIXME check before execute, can be one of the following
	// if (!is_valid()) emit sig_err
	// if (!is_valid()) throw dddd
	// if (!is_valid()) return false
	
	//Request* 
	m_req = new Request(Requester::Type::GET,m_req_str,
								 std::bind(&SimpleGetHandler::on_error, this, std::placeholders::_1),
								 std::bind(&SimpleGetHandler::on_pass, this, std::placeholders::_1)
								 );
								 
	Controller::get_instance()->schedule_request(*m_req);
}
	
void SimpleGetHandler::on_error(const QJsonObject &) {
	//std::cout << "got error" << std::endl;
	//save string
	m_err_msg="--ERROR TO FROM-JSON_TODO";
	emit sig_error();
	emit SimpleGetHandler::sig_error();
	delete m_req;
}

void SimpleGetHandler::on_pass(const QJsonObject &) {
	//save username password
	emit sig_pass();
	emit SimpleGetHandler::sig_pass();
	delete m_req;
}


QString SimpleGetHandler::get_error_message() {
	return m_err_msg;
}


QString& SimpleGetHandler::get_pattern() {
	return m_pattern_str;
}
	
 void SimpleGetHandler::set_args(const QString& s) {
	m_req_str = s;
 }


