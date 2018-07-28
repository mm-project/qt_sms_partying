#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <QString>
#include <QVariantMap>

class Engine   
{
		
	public:
		Engine(); 
		
		
	public:
		bool is_authorized();
		void set_authorized(const QString& u, const QString& p);
		void unset_authorized();
		QString get_username();
		QString get_password();
		QVariantMap create_qvariant_for_sms(const QString&,const QString&,const QString&);

		
	private:
		QString m_username;
		QString m_password;
		bool is_auth;

};


#endif // ENGINE_HPP
