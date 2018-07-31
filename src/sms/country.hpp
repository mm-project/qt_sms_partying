#ifndef COUNTRY_HPP
#define COUNTRY_HPP

//#include "controller.hpp"
#include <QString>
#include <QIcon>
#include <QStringList>

#include <iostream>

#define MACRO1_ICONS_DIR "C:\\Users\\levons\\Desktop\\git\\mm_project\\qt_sms_partying\\etc\\icons\\"


//FIXME issue with quotes in macro
//#define MACRO_ICONS_DIR_STR(icon) QString(QString(MACRO_ICONS_DIR)+"\"" #icon "\"")

namespace {
QString ICONS_DIR_STR(const QString& name) { return QString(MACRO1_ICONS_DIR)+name; }
}


class CountryInfoManager;

class GenericCountry 
{
	public:
		//GenericCountry() {
		//	m_manager->add_to_list(this);
		//}
		
		virtual QString get_country_name() = 0;
		virtual QString get_phone_code() = 0;
		virtual QIcon get_flag_icon()  = 0;
		virtual QStringList get_mobile_operator_codes() = 0;
			
	//private:
		//CountryInfoManager* m_manager;
};


class CountryInfoManager 
{
	
	public: 
		//CountryInfoManager() { }
		
		static add_to_list(GenericCountry* c) {
			m_countries.push_back(c);
		}
		
		static QList<GenericCountry*> get_list() {
			//new CountryInfo<Armenia>();
			//new CountryInfo<Russia>();

			return m_countries;
		}
		
	public:
		static QList<GenericCountry*> m_countries;
		
};

enum CountryName 
{
		Armenia,
		Russia,
		Georgia
};


template <CountryName a>
class CountryInfo 
{
	
};


template <>
class CountryInfo<Armenia> : public GenericCountry , public CountryInfoManager
{
	public:
		CountryInfo<Armenia>(){ CountryInfoManager::add_to_list(this); }
		
		QString get_country_name() { return "Armenia"; }
		QString get_phone_code() { return "+374"; }
		QIcon get_flag_icon() { return QIcon(ICONS_DIR_STR("armenia.png")); }
		QStringList get_mobile_operator_codes() {
			QStringList z;
			//z << "55" << "95" << "91" <<;
			
			return z;
		}
};




template <>
class CountryInfo<Russia> : public GenericCountry
{
	public:

		QString get_country_name() { return "Russia"; }
		QString get_phone_code() { return "+7"; }
		QIcon get_flag_icon() { return QIcon(ICONS_DIR_STR("russia.png")); }
		QStringList get_mobile_operator_codes() {
			QStringList z;
			//z << "55" << "95" << "91" <<;
			
			return z;
		}
};



template <>
class CountryInfo<Georgia> : public GenericCountry
{
	public:

		QString get_country_name() { return "Georgia"; }
		QString get_phone_code() { return "+955"; }
		QIcon get_flag_icon() { return QIcon(ICONS_DIR_STR("georgia.png")); }
		QStringList get_mobile_operator_codes() {
			QStringList z;
			//z << "55" << "95" << "91" <<;
			
			return z;
		}
};



#endif 

