#ifndef SIMPLE_GET_HANDLER_HPP
#define SIMPLE_GET_HANDLER_HPP

#include "request.hpp"
#include "request_handler.hpp"
#include "json_worker.hpp"

#include <QJsonValue>

class SimpleGetHandler : public RequestHandler
{
    Q_OBJECT

	public:
		SimpleGetHandler(const QString&);

	public:
		virtual void execute();

		virtual QString get_error_message();
		virtual void set_args(const QString&);
		virtual QString& get_pattern();
		virtual QJsonValue get_response_value(const QString&);

	public slots:
		virtual void on_error(const QJsonObject &);
		virtual void on_pass(const QJsonObject &); 
		
	private:
		Request* m_req;	

		QString m_req_str;
		QString m_pattern_str;
		
		QJsonObject m_response_json;
		//QJsonObject m_err_json;
		//QJsonObject m_ok_json;
		

		JsonWorker m_json_worker;

	signals:
		void sig_error();
		void sig_pass();

};



#endif // SIMPLE_GET_HANDLER_HPP
