#include "controller.hpp"
#include "requester.hpp"

Controller::Controller() {
	ssl = new QSslConfiguration;
	ssl->setPeerVerifyMode(QSslSocket::VerifyNone);
	ssl->setProtocol(QSsl::TlsV1_0);
	
	m_requester = new Requester(this);
	m_requester->initRequester("rest.nexmo.com", "" , ssl);
	
	m_engine = new Engine();
}


Engine* Controller::get_engine() {
	//if(!m_engine) ?
	
	return m_engine;
}

//we want application to be responsive during request
//also usually servers doesn't support too many request without delay
void Controller::schedule_request(const Request& req) {
	//FIMXE delete timer
	//m_current_request = req;
	m_pending_requests.push(req);
	m_timer = new QTimer; 
	//m_timer->setObjectName(req);
	connect(m_timer, SIGNAL(timeout()), this, SLOT(on_request_timer_shot()));
	m_timer->setSingleShot(true); 
	m_timer->start(1000);

}

void Controller::on_request_timer_shot() {
	complete_request();
}


void Controller::complete_request() {
	std::cout << "DELAYED REQUEST: " << m_current_request.get_str().toStdString() << std::endl;
	m_current_request = m_pending_requests.front();
	m_pending_requests.pop();
	send_request(m_current_request);

	delete m_timer;
	m_timer = 0;
	
}

void Controller::send_request(Request& r) {
	m_requester->sendRequest(r.get_str(),r.get_ok_handler(),r.get_err_handler(),r.get_type());
}




