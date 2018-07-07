#include "controller.hpp"
#include "requester.hpp"


	/**/
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
		
	} 
	/**/
	

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
		m_requester->initRequester("rest.nexmo.com", 80 , ssl);
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
	
	
	
	void Controller::get_balance() {
		//std::cout <<  "requester " << m_requester << std::endl;
		//m_requester->sendRequest(req,rest_handlers::success_handler,rest_handlers::error_handler);//,Requester::Type::GET);
	}

	
	//FIXME CHECK if ok and store username pasword.
	void Controller::check_login(const QString& l, const QString& p) {
		m_username = l;
		m_password = p;

		m_current_request = "account/get-balance/"+l+"/"+p;
		m_current_err_handler = rest_handlers::login_err_handler;
		m_current_ok_handler = rest_handlers::login_err_handler;

		schedule_request("FIXME REDUDEDANT");
	}
	
	
	void Controller::schedule_request(const QString& req) {
		//FIMXE delete timer
		m_timer = new QTimer; 
		//m_timer->setObjectName(req);
		
		connect(m_timer, SIGNAL(timeout()), this, SLOT(complete_request()));
		m_timer->setSingleShot(true); 
		m_timer->start(1000);

	}
	
	void Controller::complete_request() {
		//FIMXE check current_request not empty
		//m_current_request 
		std::cout << "DELAYER REQUEST: " << m_current_request.toStdString() << std::endl;
		
		m_requester->sendRequest(m_current_request,m_current_err_handler,m_current_ok_handler,Requester::Type::GET);
		
		//ELEN FIXME callable functions should be members of this class 
		// m_requester->sendRequest(m_current_request,&Controller::success_handler,&Controller::error_handler);//,Requester::Type::GET);

		m_current_request = "EMPTY";
		delete m_timer;
		m_timer = 0;
		
	}

	void Controller::on_login_success() {
		set_authorized();
		emit login_successed();
	}
	
	void Controller::on_login_fail(const QString& res) {
		unset_authorized();
		emit login_failed(res);
	}
	
	
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
	
	

	