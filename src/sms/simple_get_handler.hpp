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

	public slots:
		virtual void on_error(const QJsonObject &);
		virtual void on_pass(const QJsonObject &); 
		virtual QString& get_pattern();
		
	private:
		Request* m_req;
		QString m_req_str;
		QString m_err_msg;

};



#endif // SIMPLE_GET_HANDLER_HPP
