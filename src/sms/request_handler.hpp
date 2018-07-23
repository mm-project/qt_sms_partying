#ifndef REQUESTER_HANDLER_HPP
#define REQUESTER_HANDLER_HPP

#include "request.hpp"
#include "requester.hpp"
#include "controller.hpp"


typedef std::function<void(const QJsonObject &)> handleFunc;
typedef std::function<void()> finishFunc;



class RequestHandler : public QObject
{
    Q_OBJECT
	
public:
		virtual void execute() = 0;

public slots:

	virtual void on_error(const QJsonObject &) = 0;
	virtual void on_pass(const QJsonObject &) = 0;
	virtual void add_param(const QString& ) = 0;

signals:
	void sig_err()	;
	void sig_pass();

};




class LoginHandler : public RequestHandler
{
    Q_OBJECT

	public:
		LoginHandler();

	public:

		virtual void execute();

	public slots:
	
			
		virtual void on_error(const QJsonObject &);
		
		virtual void on_pass(const QJsonObject &); 
	
		void add_param(const QString& s);
		
	private:
		Request* m_req;
		QString m_req_str;
		QString m_err_msg;

};



#endif // REQUESTER_HANDLER_HPP
