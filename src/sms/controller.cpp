#include "controller.hpp"
#include "requester.hpp"


	/*
	namespace rest_handlers {
		//*
		QString json_to_string(const QJsonObject& j)
		{
			QJsonDocument doc(j);
			QString strJson(doc.toJson(QJsonDocument::Compact));
			//std::cout << strJson.toStdString() << std::endl;	
			return strJson;
		}

		void login_ok_handler(const QJsonObject& j)  
		{
			std::cout << "SUCESS:" << std::endl;
			//print_json(j);
			Controller::get_instance()->on_login_success();
					
		}

		void login_err_handler(const QJsonObject& j)  
		{
			std::cout << "ERROR: " <<  json_to_string(j).toStdString() << std::endl;
			//print_json(j);
			Controller::get_instance()->on_login_fail(json_to_string(j));
				
		}

		void price_ok_handler(const QJsonObject& j)  
		{
			std::cout << "SUCESS:" << std::endl;
			//print_json(j);
			Controller::get_instance()->on_login_success();
					
		}

		void price_err_handler(const QJsonObject& j)  
		{
			std::cout << "ERROR: " <<  json_to_string(j).toStdString() << std::endl;
			//print_json(j);
			Controller::get_instance()->on_login_fail(json_to_string(j));
				
		}
		
		void balance_ok_handler(const QJsonObject& j)  
		{
			//std::cout << "SUCESS:" << std::endl;
			//print_json(j);
			Controller::get_instance()->on_balance_recieved(false,json_to_string(j));
					
		}

		void balance_err_handler(const QJsonObject& j)  
		{
			//std::cout << "ERROR: " <<  json_to_string(j).toStdString() << std::endl;
			//print_json(j);
			Controller::get_instance()->on_balance_recieved(true,json_to_string(j));
				
		}

		
	} 
	*/
	

	Controller::Controller() {
		is_auth = false;
		/*
		m_timer = new QTimer; 
		connect(m_timer, SIGNAL(timeout()), this, SLOT(complete_request()));
		m_timer->setSingleShot(true); 
		m_timer->start(1000);
		complete_request();
		*/
		
		ssl = new QSslConfiguration;
		ssl->setPeerVerifyMode(QSslSocket::VerifyNone);
		ssl->setProtocol(QSsl::TlsV1_0);
		
		m_requester = new Requester(this);
		m_requester->initRequester("rest.nexmo.com", "" , ssl);
		//complete_request();
	
	}

		
	/*
	bool Controller::is_valid_account() {
		
	}
	
	bool Controller::have_sufficient_founds() {
	
	}
	*/

	bool Controller::is_authorized() {
		return is_auth;
	}

	void Controller::set_authorized() {
		is_auth = true;
	}
	
	void Controller::unset_authorized() {
		is_auth = false;
	}
	
	/*
	
	void Controller::request_get_balance() {
		Request r(Requester::Type::GET,"account/get-balance/"+m_username+"/"+m_password,rest_handlers::balance_err_handler,rest_handlers::balance_ok_handler);
		schedule_request(r);
	}

	
	//FIXME CHECK if ok and store username pasword.
	void Controller::request_check_login(const QString& l, const QString& p) {
		m_username = l;
		m_password = p;

		//m_current_request = "account/get-balance/"+l+"/"+p;
		//m_current_err_handler = rest_handlers::login_err_handler;
		//m_current_ok_handler = rest_handlers::login_ok_handler;

		Request r(Requester::Type::GET,"account/get-balance/"+l+"/"+p,rest_handlers::login_err_handler,rest_handlers::login_ok_handler);
		schedule_request(r);
	}
	
	
	
	void Controller::send_sms(const QString& to, const QString& from, const QString& body) {
		assert(is_authorized());
		assert(have_sufficient_founds());

		JsonBody j;
		J.add("from:",);
		J.add("to:");
		J.add("body:");
		
		Request r(Requester::Type::POST,"/sms/json"+m_username+"/"+m_password+"/"+cc,rest_handlers::price_err_handler,rest_handlers::price_ok_handler);
		schedule_request(r);
	
	}
	
	void Controller::request_check_price_for_country(const QString& cc) {
		assert(is_authorized());
		
		
		Request r(Requester::Type::GET,"/account/get-pricing/outbound/"+m_username+"/"+m_password+"/"+cc,rest_handlers::price_err_handler,rest_handlers::price_ok_handler);
		schedule_request(r);

	}
	*/
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
		//FIMXE check current_request not empty
		//m_current_request 
		std::cout << "DELAYER REQUEST: " << m_current_request.get_str().toStdString() << std::endl;
		m_current_request = m_pending_requests.front();
		m_pending_requests.pop();
		send_request(m_current_request);
		//m_requester->sendRequest2(m_current_request);
		//,m_current_ok_handler,m_current_err_handler,Requester::Type::GET);
		
		//ELEN FIXME callable functions should be members of this class 
		// m_requester->sendRequest(m_current_request,&Controller::success_handler,&Controller::error_handler);//,Requester::Type::GET);

		//FIXME
		//m_current_request = "EMPTY";
		delete m_timer;
		m_timer = 0;
		
	}

	void Controller::send_request(Request& r) {
		m_requester->sendRequest(r.get_str(),r.get_ok_handler(),r.get_err_handler(),r.get_type());
	}
	
	/*
	void Controller::on_login_success() {
		set_authorized();
		emit login_successed();
	}
	
	void Controller::on_login_fail(const QString& res) {
		unset_authorized();
		emit login_failed(res);
	}
	
	void Controller::on_balance_recieved(bool res, const QString& balance) {
		emit signal_balance_request_done(res,balance);
		
		//if ( res ) 
		//	emit balance_successed(balance);
		//else	
		//	emit balance_failed(balance);
	}
	*/
	
	/*
	void Controller::print_json(const QJsonObject& j)
	{
		QJsonDocument doc(j);
		QString strJson(doc.toJson(QJsonDocument::Compact));
		std::cout << strJson.toStdString() << std::endl;	
	}

	void Controller::success_handler(const QJsonObject& j)  
	{
		std::cout << "SUCESS:" << std::endl;
		print_json(j);
				
	}


	void Controller::error_handler(const QJsonObject& j)  
	{
		std::cout << "ERROR:" << std::endl;
		print_json(j);
			
	} */
	
	

	