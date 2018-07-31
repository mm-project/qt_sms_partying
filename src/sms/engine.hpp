#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <QString>
#include <QVariantMap>

#include "country.hpp"

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
		QList<GenericCountry*> get_country_infos();
		
	private:
		QString m_username;
		QString m_password;
		bool is_auth;
		CountryInfoManager m_info_manager;
		QList<GenericCountry*> m_countries;

};


#endif // ENGINE_HPP
