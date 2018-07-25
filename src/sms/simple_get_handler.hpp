#ifndef SIMPLE_GET_HANDLER_HPP
#define SIMPLE_GET_HANDLER_HPP

#include "request.hpp"
#include "request_handler.hpp"

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

	public slots:
		virtual void on_error(const QJsonObject &);
		virtual void on_pass(const QJsonObject &); 
		
	private:
		Request* m_req;	

		QString m_req_str;
		QString m_pattern_str;
		
		QString m_err_msg;

	signals:
		void sig_error();
		void sig_pass();

};



#endif // SIMPLE_GET_HANDLER_HPP
