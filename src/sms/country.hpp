#ifndef COUNTRY_HPP
#define COUNTRY_HPP

#include <QString>
#include <QIcon>
#include <QStringList>

#include <tuple>
#include <type_traits>

class GenericCountry 
{
	public:
		virtual QString get_country_name() = 0;
		virtual QString get_phone_code() = 0;
		virtual QIcon get_flag_icon()  = 0;
		virtual QStringList get_mobile_operator_codes() = 0;
};



enum CountryName 
{
	Montserrat,
	Togo,
	Azerbaijan,
	WallisandFutuna,
	Haiti,
	Vietnam,
	Ecuador,
	Vanuatu,
	RussiaRussianFederation,
	Benin,
	Algeria,
	Lithuania,
	Liechtenstein,
	TurksandCaicosIslands,
	Tajikistan,
	Plazasdesoberana,
	Tokelau,
	Jordan,
	Venezuela,
	Lebanon,
	CollectivityofSaintMartin,
	Bermuda,
	Georgia,
	Mongolia,
	TrinidadandTobago,
	Syria,
	CzechRepublic,
	SlovakiaSlovakRepublic,
	Mali,
	FrenchOverseasDepartmentsandTerritories,
	Morocco,
	CookIslands,
	Spain,
	Somalia,
	Ceuta,
	Ethiopia,
	Australia,
	Burma,
	Serbia,
	Mauritius,
	Iraq,
	VaticanCity,
	Swaziland,
	Philippines,
	Suriname,
	Belarus,
	Djibouti,
	Portugal,
	SouthGeorgiaandtheSouthSandwichIslands,
	Greenland,
	RepublicofCongo,
	Oman,
	Nauru,
	Panama,
	Melilla,
	SouthOssetia,
	SahrawiArabDemocraticRepublic,
	Thailand,
	SouthKorea,
	Malaysia,
	Abkhazia,
	AFrenchOverseasDepartmentsandTerritories,
	SanMarino,
	SaintLucia,
	Latvia,
	Belize,
	Slovenia,
	Bangladesh,
	Norway,
	Burundi,
	CentralAfricanRepublic,
	CostaRica,
	DiegoGarcia,
	Estonia,
	Brunei,
	BritishIndianOceanTerritory,
	Croatia,
	Samoa,
	ElSalvador,
	AustralianAntarcticTerritory,
	Niger,
	Taiwan,
	Armenia,
	Paraguay,
	IsleofMan,
	NewCaledonia,
	UnitedStatesUSA,
	PuertoRico,
	Botswana,
	SaintBarthlemy,
	Argentina,
	Guernsey,
	Bonaire,
	Guyana,
	SouthAfrica,
	Laos,
	Guadeloupe,
	NorthKorea,
	Kyrgyzstan,
	Qatar,
	Kazakhstan,
	Cambodia,
	Svalbard,
	Afghanistan,
	NorfolkIsland,
	Germany,
	BFrenchOverseasDepartmentsandTerritories,
	EquatorialGuinea,
	Guam,
	SaintVincentandtheGrenadines,
	Brazil,
	Iceland,
	Israel,
	AAbkhazia,
	Austria,
	Canada,
	CuraaoandtheCaribbeanNetherlands,
	Nicaragua,
	Bolivia,
	PitcairnIslands,
	Iran,
	SaintKittsandNevis,
	Gambia,
	Belgium,
	Gabon,
	Senegal,
	Dominica,
	Ukraine,
	Turkey,
	Ireland,
	Jamaica,
	SaintHelenaandTristandaCunhanotAscenscion,
	Mayotte,
	Saba,
	Bhutan,
	Guinea,
	DominicanRepublic,
	Nigeria,
	Greece,
	FrenchGuiana,
	SaudiArabia,
	Liberia,
	Cyprus,
	Uzbekistan,
	Barbados,
	NorthernMarianaIslands,
	Martinique,
	CocosKeelingIslands,
	Andorra,
	Tunisia,
	Albania,
	Yemen,
	CaymanIslands,
	Maldives,
	FalklandIslands,
	Romania,
	Macau,
	ChagosIslands,
	Libya,
	Namibia,
	England,
	TristandaCunha,
	Mauritania,
	SintMaarten,
	SierraLeone,
	BurkinaFaso,
	NorthernIreland,
	UnitedStatesVirginIslands,
	SintEustatius,
	Anguilla,
	Zimbabwe,
	WesternSahara,
	Runion,
	Myanmar,
	ChristmasIsland,
	Cameroon,
	Italy,
	CapeVerde,
	Monaco,
	GuineaBissau,
	Scotland,
	AmericanSamoa,
	Palau,
	HongKong,
	Montenegro,
	USVirginIslands,
	Zambia,
	Rwanda,
	Uganda,
	MarshallIslands,
	Seychelles,
	Nepal,
	NorthernCyprus,
	Gibraltar,
	Tonga,
	Jersey,
	FederatedStatesofMicronesia,
	France,
	Singapore,
	Kosovo,
	Uruguay,
	IvoryCoast,
	Bahrain,
	Luxembourg,
	Artsakh,
	Sweden,
	FaroeIslands,
	DemocraticRepublicofCongo,
	Angola,
	BosniaandHerzegovinaBosniaHerzegovina,
	Tanzania,
	Prncipe,
	CFrenchOverseasDepartmentsandTerritories,
	Kiribati,
	SaintPierreandMiquelon,
	SolomonIslands,
	EastTimor,
	Ghana,
	Eritrea,
	SouthSudan,
	UnitedKingdom,
	Bulgaria,
	Finland,
	Pakistan,
	Chad,
	Tuvalu,
	Switzerland,
	DFrenchOverseasDepartmentsandTerritories,
	Curaao,
	Japan,
	Fiji,
	BritishVirginIslands,
	JanMayen,
	Cuba,
	Kuwait,
	Hungary,
	Egypt,
	Aruba,
	UnitedArabEmirates,
	Guatemala,
	Chile,
	Denmark,
	Niue,
	Wales,
	Moldova,
	Malta,
	Mexico,
	Madeira,
	Kenya,
	Grenada,
	Hawaii,
	Mozambique,
	Netherlands,
	Turkmenistan,
	PapuaNewGuinea,
	Madagascar,
	CanaryIslands,
	Honduras,
	SriLanka,
	AntiguaandBarbuda,
	SoTomandPrncipe,
	Bahamas,
	Colombia,
	Poland,
	Comoros,
	PeoplesRepublicofChina,
	NewZealand,
	Lesotho,
	RepublicofMacedonia,
	Malawi,
	AscensionIsland,
	Sudan,
	FrenchPolynesia,
	Indonesia,
	Peru,
	EasterIsland,
	Size = 276
};

template <CountryName a>
class CountryInfo;

//FIXME issue with quotes in macro
//#define MACRO_ZICONS_DIR_STR(icon) QString(QString(MACRO_ICONS_DIR)+"\"" #icon "\"")
//#define MACRO_ICONS_DIR "C:\\Users\\levons\\Desktop\\git\\mm_project\\qt_sms_partying\\etc\\icons\\"
#define MACRO1_ICONS_DIR "C:\\Users\\elen\\Desktop\\my_projects\\qt_sms\\original_sms\\qt_sms_partying\\etc\\icons\\"

namespace {
QString ZICONS_DIR_STR(const QString& name) { return QString(MACRO1_ICONS_DIR)+name; }
}

template <>                                                                 
class CountryInfo<Montserrat> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Montserrat"; }                       
		QString get_phone_code() { return "+1"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Montserrat.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "664";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Togo> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Togo"; }                       
		QString get_phone_code() { return "+228"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Togo.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "90";         			
	        	z << "91";         			
	        	z << "92";         			
	        	z << "97";         			
	        	z << "98";         			
	        	z << "99";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Azerbaijan> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Azerbaijan"; }                       
		QString get_phone_code() { return "+994"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Azerbaijan.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "40";         			
	        	z << "50";         			
	        	z << "51";         			
	        	z << "55";         			
	        	z << "70";         			
	        	z << "77";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<WallisandFutuna> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Wallis and Futuna"; }                       
		QString get_phone_code() { return "+681"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("WallisandFutuna.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Haiti> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Haiti[2]"; }                       
		QString get_phone_code() { return "+509"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Haiti.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "34";         			
	        	z << "39";         			
	        	z << "35";         			
	        	z << "36";         			
	        	z << "37";         			
	        	z << "38";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Vietnam> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Vietnam"; }                       
		QString get_phone_code() { return "+84"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Vietnam.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Ecuador> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Ecuador"; }                       
		QString get_phone_code() { return "+593"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Ecuador.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "8";         			
	        	z << "9";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Vanuatu> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Vanuatu"; }                       
		QString get_phone_code() { return "+678"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Vanuatu.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "4";         			
	        	z << "5";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<RussiaRussianFederation> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Russia (Russian Federation)"; }                       
		QString get_phone_code() { return "+7"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("RussiaRussianFederation.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "901";         			
	        	z << "902";         			
	        	z << "903";         			
	        	z << "904";         			
	        	z << "905";         			
	        	z << "906";         			
	        	z << "908";         			
	        	z << "909";         			
	        	z << "950";         			
	        	z << "951";         			
	        	z << "952";         			
	        	z << "953";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Benin> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Benin"; }                       
		QString get_phone_code() { return "+229"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Benin.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Algeria> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Algeria"; }                       
		QString get_phone_code() { return "+213"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Algeria.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "5";         			
	        	z << "6";         			
	        	z << "7";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Lithuania> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Lithuania"; }                       
		QString get_phone_code() { return "+370"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Lithuania.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Liechtenstein> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Liechtenstein"; }                       
		QString get_phone_code() { return "+423"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Liechtenstein.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "7";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<TurksandCaicosIslands> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Turks and Caicos Islands"; }                       
		QString get_phone_code() { return "+1"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("TurksandCaicosIslands.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "649";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Tajikistan> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Tajikistan"; }                       
		QString get_phone_code() { return "+992"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Tajikistan.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "9";         			
	        	z << "90";         			
	        	z << "910";         			
	        	z << "911";         			
	        	z << "912";         			
	        	z << "913";         			
	        	z << "914";         			
	        	z << "915";         			
	        	z << "916";         			
	        	z << "917";         			
	        	z << "918";         			
	        	z << "919";         			
	        	z << "92";         			
	        	z << "93";         			
	        	z << "95";         			
	        	z << "96";         			
	        	z << "97";         			
	        	z << "98";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Plazasdesoberana> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Plazas de soberan?a"; }                       
		QString get_phone_code() { return "+34"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Plazasdesoberana.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Tokelau> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Tokelau"; }                       
		QString get_phone_code() { return "+690"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Tokelau.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Jordan> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Jordan"; }                       
		QString get_phone_code() { return "+962"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Jordan.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "77";         			
	        	z << "79";         			
	        	z << "78";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Venezuela> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Venezuela"; }                       
		QString get_phone_code() { return "+58"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Venezuela.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "412";         			
	        	z << "414";         			
	        	z << "416";         			
	        	z << "424";         			
	        	z << "426";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Lebanon> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Lebanon"; }                       
		QString get_phone_code() { return "+961"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Lebanon.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "3";         			
	        	z << "70";         			
	        	z << "71";         			
	        	z << "76";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<CollectivityofSaintMartin> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Collectivity of Saint Martin"; }                       
		QString get_phone_code() { return "+590"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("CollectivityofSaintMartin.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "6";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Bermuda> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Bermuda"; }                       
		QString get_phone_code() { return "+1"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Bermuda.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "441";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Georgia> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Georgia"; }                       
		QString get_phone_code() { return "+995"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Georgia.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "544";         			
	        	z << "514";         			
	        	z << "551";         			
	        	z << "555";         			
	        	z << "557";         			
	        	z << "558";         			
	        	z << "568";         			
	        	z << "571";         			
	        	z << "574";         			
	        	z << "577";         			
	        	z << "579";         			
	        	z << "591";         			
	        	z << "592";         			
	        	z << "593";         			
	        	z << "595";         			
	        	z << "596";         			
	        	z << "597";         			
	        	z << "598";         			
	        	z << "599";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Mongolia> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Mongolia"; }                       
		QString get_phone_code() { return "+976"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Mongolia.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<TrinidadandTobago> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Trinidad and Tobago"; }                       
		QString get_phone_code() { return "+1"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("TrinidadandTobago.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "868";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Syria> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Syria"; }                       
		QString get_phone_code() { return "+963"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Syria.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "93";         			
	        	z << "98";         			
	        	z << "99";         			
	        	z << "94";         			
	        	z << "95";         			
	        	z << "96";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<CzechRepublic> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Czech Republic"; }                       
		QString get_phone_code() { return "+420"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("CzechRepublic.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "601";         			
	        	z << "602";         			
	        	z << "603";         			
	        	z << "604";         			
	        	z << "605";         			
	        	z << "606";         			
	        	z << "607";         			
	        	z << "608";         			
	        	z << "702";         			
	        	z << "790";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<SlovakiaSlovakRepublic> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Slovakia (Slovak Republic)"; }                       
		QString get_phone_code() { return "+421"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("SlovakiaSlovakRepublic.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "901";         			
	        	z << "902";         			
	        	z << "903";         			
	        	z << "904";         			
	        	z << "905";         			
	        	z << "906";         			
	        	z << "907";         			
	        	z << "908";         			
	        	z << "910";         			
	        	z << "911";         			
	        	z << "912";         			
	        	z << "914";         			
	        	z << "915";         			
	        	z << "916";         			
	        	z << "917";         			
	        	z << "918";         			
	        	z << "940";         			
	        	z << "944";         			
	        	z << "948";         			
	        	z << "949";         			
	        	z << "950";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Mali> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Mali"; }                       
		QString get_phone_code() { return "+223"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Mali.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "3";         			
	        	z << "4";         			
	        	z << "5";         			
	        	z << "6";         			
	        	z << "7";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<FrenchOverseasDepartmentsandTerritories> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "French Overseas Departments and Territories"; }                       
		QString get_phone_code() { return "+590"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("FrenchOverseasDepartmentsandTerritories.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Morocco> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Morocco"; }                       
		QString get_phone_code() { return "+212"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Morocco.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<CookIslands> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Cook Islands"; }                       
		QString get_phone_code() { return "+682"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("CookIslands.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Spain> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Spain"; }                       
		QString get_phone_code() { return "+34"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Spain.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "6";         			
	        	z << "7";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Somalia> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Somalia"; }                       
		QString get_phone_code() { return "+252"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Somalia.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Ceuta> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Ceuta"; }                       
		QString get_phone_code() { return "+34"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Ceuta.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Ethiopia> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Ethiopia"; }                       
		QString get_phone_code() { return "+251"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Ethiopia.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Australia> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Australia"; }                       
		QString get_phone_code() { return "+61"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Australia.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "4";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Burma> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Burma"; }                       
		QString get_phone_code() { return "+95"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Burma.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Serbia> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Serbia"; }                       
		QString get_phone_code() { return "+381"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Serbia.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "60";         			
	        	z << "61";         			
	        	z << "62";         			
	        	z << "63";         			
	        	z << "64";         			
	        	z << "65";         			
	        	z << "66";         			
	        	z << "68";         			
	        	z << "69";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Mauritius> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Mauritius"; }                       
		QString get_phone_code() { return "+230"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Mauritius.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "57";         			
	        	z << "58";         			
	        	z << "59";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Iraq> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Iraq"; }                       
		QString get_phone_code() { return "+964"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Iraq.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<VaticanCity> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Vatican City"; }                       
		QString get_phone_code() { return "+39"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("VaticanCity.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Swaziland> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Swaziland"; }                       
		QString get_phone_code() { return "+268"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Swaziland.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "7";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Philippines> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Philippines"; }                       
		QString get_phone_code() { return "+63"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Philippines.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "973";         			
	        	z << "974";         			
	        	z << "905";         			
	        	z << "906";         			
	        	z << "977";         			
	        	z << "915";         			
	        	z << "916";         			
	        	z << "926";         			
	        	z << "927";         			
	        	z << "935";         			
	        	z << "936";         			
	        	z << "937";         			
	        	z << "996";         			
	        	z << "997";         			
	        	z << "917";         			
	        	z << "979";         			
	        	z << "920";         			
	        	z << "930";         			
	        	z << "938";         			
	        	z << "939";         			
	        	z << "907";         			
	        	z << "908";         			
	        	z << "909";         			
	        	z << "910";         			
	        	z << "912";         			
	        	z << "919";         			
	        	z << "921";         			
	        	z << "928";         			
	        	z << "929";         			
	        	z << "947";         			
	        	z << "948";         			
	        	z << "949";         			
	        	z << "989";         			
	        	z << "918";         			
	        	z << "999";         			
	        	z << "922";         			
	        	z << "923";         			
	        	z << "932";         			
	        	z << "933";         			
	        	z << "942";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Suriname> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Suriname"; }                       
		QString get_phone_code() { return "+597"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Suriname.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "8";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Belarus> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Belarus"; }                       
		QString get_phone_code() { return "+375"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Belarus.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "25";         			
	        	z << "33";         			
	        	z << "44";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Djibouti> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Djibouti"; }                       
		QString get_phone_code() { return "+253"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Djibouti.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "8";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Portugal> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Portugal"; }                       
		QString get_phone_code() { return "+351"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Portugal.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "91";         			
	        	z << "921";         			
	        	z << "922";         			
	        	z << "924";         			
	        	z << "925";         			
	        	z << "926";         			
	        	z << "927";         			
	        	z << "9290";         			
	        	z << "9291";         			
	        	z << "9292";         			
	        	z << "9293";         			
	        	z << "9294";         			
	        	z << "93";         			
	        	z << "96";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<SouthGeorgiaandtheSouthSandwichIslands> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "South Georgia and the South Sandwich Islands"; }                       
		QString get_phone_code() { return "+500"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("SouthGeorgiaandtheSouthSandwichIslands.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Greenland> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Greenland"; }                       
		QString get_phone_code() { return "+299"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Greenland.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<RepublicofCongo> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Republic of Congo"; }                       
		QString get_phone_code() { return "+242"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("RepublicofCongo.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "4";         			
	        	z << "5";         			
	        	z << "6";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Oman> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Oman"; }                       
		QString get_phone_code() { return "+968"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Oman.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "91";         			
	        	z << "91";         			
	        	z << "92";         			
	        	z << "93";         			
	        	z << "94";         			
	        	z << "95";         			
	        	z << "96";         			
	        	z << "97";         			
	        	z << "98";         			
	        	z << "99";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Nauru> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Nauru"; }                       
		QString get_phone_code() { return "+674"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Nauru.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "555";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Panama> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Panama"; }                       
		QString get_phone_code() { return "+507"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Panama.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "6";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Melilla> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Melilla"; }                       
		QString get_phone_code() { return "+34"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Melilla.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<SouthOssetia> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "South Ossetia"; }                       
		QString get_phone_code() { return "+995"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("SouthOssetia.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<SahrawiArabDemocraticRepublic> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Sahrawi Arab Democratic Republic"; }                       
		QString get_phone_code() { return "+212"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("SahrawiArabDemocraticRepublic.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Thailand> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Thailand"; }                       
		QString get_phone_code() { return "+66"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Thailand.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "6";         			
	        	z << "8";         			
	        	z << "9";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<SouthKorea> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "South Korea"; }                       
		QString get_phone_code() { return "+82"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("SouthKorea.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "10";         			
	        	z << "11";         			
	        	z << "16";         			
	        	z << "17";         			
	        	z << "18";         			
	        	z << "19";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Malaysia> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Malaysia"; }                       
		QString get_phone_code() { return "+60"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Malaysia.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "10";         			
	        	z << "11";         			
	        	z << "12";         			
	        	z << "13";         			
	        	z << "142";         			
	        	z << "143";         			
	        	z << "146";         			
	        	z << "149";         			
	        	z << "16";         			
	        	z << "17";         			
	        	z << "18";         			
	        	z << "19";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

                                                                       

                                                                      

template <>                                                                 
class CountryInfo<SanMarino> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "San Marino"; }                       
		QString get_phone_code() { return "+378"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("SanMarino.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "66";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<SaintLucia> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Saint Lucia"; }                       
		QString get_phone_code() { return "+1"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("SaintLucia.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "758";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Latvia> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Latvia"; }                       
		QString get_phone_code() { return "+371"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Latvia.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Belize> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Belize"; }                       
		QString get_phone_code() { return "+501"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Belize.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "6";         			
	        	z << "6";         			
	        	z << "6";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Slovenia> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Slovenia"; }                       
		QString get_phone_code() { return "+386"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Slovenia.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "20";         			
	        	z << "21";         			
	        	z << "30";         			
	        	z << "31";         			
	        	z << "40";         			
	        	z << "41";         			
	        	z << "49";         			
	        	z << "50";         			
	        	z << "51";         			
	        	z << "60";         			
	        	z << "61";         			
	        	z << "64";         			
	        	z << "70";         			
	        	z << "71";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Bangladesh> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Bangladesh"; }                       
		QString get_phone_code() { return "+880"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Bangladesh.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Norway> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Norway"; }                       
		QString get_phone_code() { return "+47"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Norway.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "4";         			
	        	z << "59";         			
	        	z << "9";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Burundi> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Burundi"; }                       
		QString get_phone_code() { return "+257"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Burundi.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<CentralAfricanRepublic> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Central African Republic"; }                       
		QString get_phone_code() { return "+236"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("CentralAfricanRepublic.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<CostaRica> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Costa Rica"; }                       
		QString get_phone_code() { return "+506"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("CostaRica.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "6";         			
	        	z << "7";         			
	        	z << "8";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<DiegoGarcia> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Diego Garcia"; }                       
		QString get_phone_code() { return "+246"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("DiegoGarcia.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "387";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Estonia> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Estonia"; }                       
		QString get_phone_code() { return "+372"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Estonia.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Brunei> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Brunei"; }                       
		QString get_phone_code() { return "+673"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Brunei.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<BritishIndianOceanTerritory> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "British Indian Ocean Territory"; }                       
		QString get_phone_code() { return "+246"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("BritishIndianOceanTerritory.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "387";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Croatia> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Croatia"; }                       
		QString get_phone_code() { return "+385"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Croatia.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "91";         			
	        	z << "92";         			
	        	z << "95";         			
	        	z << "97";         			
	        	z << "98";         			
	        	z << "99";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Samoa> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Samoa"; }                       
		QString get_phone_code() { return "+685"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Samoa.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "77";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<ElSalvador> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "El Salvador"; }                       
		QString get_phone_code() { return "+503"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("ElSalvador.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "6";         			
	        	z << "7";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<AustralianAntarcticTerritory> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Australian Antarctic Territory"; }                       
		QString get_phone_code() { return "+672"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("AustralianAntarcticTerritory.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Niger> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Niger"; }                       
		QString get_phone_code() { return "+227"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Niger.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "9";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Taiwan> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Taiwan"; }                       
		QString get_phone_code() { return "+886"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Taiwan.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "9";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Armenia> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Armenia"; }                       
		QString get_phone_code() { return "+374"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Armenia.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "55";         			
	        	z << "95";         			
	        	z << "41";         			
	        	z << "77";         			
	        	z << "93";         			
	        	z << "94";         			
	        	z << "98";         			
	        	z << "91";         			
	        	z << "99";         			
	        	z << "43";         			
	        	z << "97";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Paraguay> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Paraguay"; }                       
		QString get_phone_code() { return "+595"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Paraguay.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<IsleofMan> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Isle of Man"; }                       
		QString get_phone_code() { return "+44"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("IsleofMan.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<NewCaledonia> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "New Caledonia"; }                       
		QString get_phone_code() { return "+687"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("NewCaledonia.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "7";         			
	        	z << "8";         			
	        	z << "9";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<UnitedStatesUSA> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "United States (USA)"; }                       
		QString get_phone_code() { return "+1"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("UnitedStatesUSA.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<PuertoRico> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Puerto Rico"; }                       
		QString get_phone_code() { return "+1"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("PuertoRico.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "787";         			
	        	z << "939";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Botswana> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Botswana"; }                       
		QString get_phone_code() { return "+267"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Botswana.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "7";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<SaintBarthlemy> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Saint Barth?lemy"; }                       
		QString get_phone_code() { return "+590"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("SaintBarthlemy.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "6";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Argentina> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Argentina"; }                       
		QString get_phone_code() { return "+54"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Argentina.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Guernsey> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Guernsey"; }                       
		QString get_phone_code() { return "+44"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Guernsey.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Bonaire> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Bonaire"; }                       
		QString get_phone_code() { return "+599"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Bonaire.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Guyana> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Guyana"; }                       
		QString get_phone_code() { return "+592"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Guyana.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "6";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<SouthAfrica> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "South Africa"; }                       
		QString get_phone_code() { return "+27"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("SouthAfrica.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "60";         			
	        	z << "710";         			
	        	z << "711";         			
	        	z << "712";         			
	        	z << "713";         			
	        	z << "714";         			
	        	z << "715";         			
	        	z << "716";         			
	        	z << "717";         			
	        	z << "718";         			
	        	z << "719";         			
	        	z << "72";         			
	        	z << "73";         			
	        	z << "74";         			
	        	z << "741";         			
	        	z << "76";         			
	        	z << "78";         			
	        	z << "79";         			
	        	z << "811";         			
	        	z << "812";         			
	        	z << "813";         			
	        	z << "814";         			
	        	z << "82";         			
	        	z << "83";         			
	        	z << "84";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Laos> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Laos"; }                       
		QString get_phone_code() { return "+856"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Laos.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "20";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Guadeloupe> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Guadeloupe"; }                       
		QString get_phone_code() { return "+590"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Guadeloupe.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "690";         			
	        	z << "700";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<NorthKorea> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "North Korea"; }                       
		QString get_phone_code() { return "+850"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("NorthKorea.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Kyrgyzstan> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Kyrgyzstan"; }                       
		QString get_phone_code() { return "+996"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Kyrgyzstan.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Qatar> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Qatar"; }                       
		QString get_phone_code() { return "+974"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Qatar.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "33";         			
	        	z << "55";         			
	        	z << "66";         			
	        	z << "77";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Kazakhstan> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Kazakhstan"; }                       
		QString get_phone_code() { return "+7"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Kazakhstan.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "700";         			
	        	z << "701";         			
	        	z << "702";         			
	        	z << "705";         			
	        	z << "707";         			
	        	z << "777";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Cambodia> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Cambodia"; }                       
		QString get_phone_code() { return "+855"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Cambodia.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "92";         			
	        	z << "12";         			
	        	z << "11";         			
	        	z << "77";         			
	        	z << "99";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Svalbard> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Svalbard"; }                       
		QString get_phone_code() { return "+47"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Svalbard.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "79";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Afghanistan> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Afghanistan"; }                       
		QString get_phone_code() { return "+93"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Afghanistan.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "70";         			
	        	z << "71";         			
	        	z << "74";         			
	        	z << "75";         			
	        	z << "77";         			
	        	z << "76";         			
	        	z << "78";         			
	        	z << "73";         			
	        	z << "79";         			
	        	z << "72";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<NorfolkIsland> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Norfolk Island"; }                       
		QString get_phone_code() { return "+672"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("NorfolkIsland.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "38";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Germany> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Germany"; }                       
		QString get_phone_code() { return "+49"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Germany.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "160";         			
	        	z << "162";         			
	        	z << "163";         			
	        	z << "170";         			
	        	z << "171";         			
	        	z << "172";         			
	        	z << "173";         			
	        	z << "174";         			
	        	z << "175";         			
	        	z << "176";         			
	        	z << "177";         			
	        	z << "178";         			
	        	z << "179";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

                                                                     

template <>                                                                 
class CountryInfo<EquatorialGuinea> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Equatorial Guinea"; }                       
		QString get_phone_code() { return "+240"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("EquatorialGuinea.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "2";         			
	        	z << "7";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Guam> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Guam"; }                       
		QString get_phone_code() { return "+1"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Guam.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "671";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<SaintVincentandtheGrenadines> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Saint Vincent and the Grenadines"; }                       
		QString get_phone_code() { return "+1"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("SaintVincentandtheGrenadines.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "784";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Brazil> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Brazil"; }                       
		QString get_phone_code() { return "+55"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Brazil.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Iceland> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Iceland"; }                       
		QString get_phone_code() { return "+354"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Iceland.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "6";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Israel> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Israel"; }                       
		QString get_phone_code() { return "+972"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Israel.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "50";         			
	        	z << "52";         			
	        	z << "53";         			
	        	z << "54";         			
	        	z << "556";         			
	        	z << "558";         			
	        	z << "559";         			
	        	z << "58";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Abkhazia> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Abkhazia"; }                       
		QString get_phone_code() { return "+995"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Abkhazia.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Austria> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Austria"; }                       
		QString get_phone_code() { return "+43"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Austria.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "650";         			
	        	z << "660";         			
	        	z << "664";         			
	        	z << "676";         			
	        	z << "680";         			
	        	z << "677";         			
	        	z << "681";         			
	        	z << "688";         			
	        	z << "699";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Canada> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Canada"; }                       
		QString get_phone_code() { return "+1"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Canada.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<CuraaoandtheCaribbeanNetherlands> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Cura?ao and the Caribbean Netherlands"; }                       
		QString get_phone_code() { return "+599"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("CuraaoandtheCaribbeanNetherlands.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Nicaragua> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Nicaragua"; }                       
		QString get_phone_code() { return "+505"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Nicaragua.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "8";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Bolivia> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Bolivia"; }                       
		QString get_phone_code() { return "+591"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Bolivia.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "6";         			
	        	z << "7";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<PitcairnIslands> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Pitcairn Islands"; }                       
		QString get_phone_code() { return "+64"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("PitcairnIslands.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Iran> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Iran"; }                       
		QString get_phone_code() { return "+98"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Iran.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "901";         			
	        	z << "902";         			
	        	z << "903";         			
	        	z << "920";         			
	        	z << "921";         			
	        	z << "922";         			
	        	z << "930";         			
	        	z << "931";         			
	        	z << "932";         			
	        	z << "933";         			
	        	z << "934";         			
	        	z << "935";         			
	        	z << "936";         			
	        	z << "937";         			
	        	z << "938";         			
	        	z << "939";         			
	        	z << "990";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<SaintKittsandNevis> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Saint Kitts and Nevis"; }                       
		QString get_phone_code() { return "+1"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("SaintKittsandNevis.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "869";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Gambia> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Gambia"; }                       
		QString get_phone_code() { return "+220"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Gambia.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Belgium> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Belgium"; }                       
		QString get_phone_code() { return "+32"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Belgium.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Gabon> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Gabon"; }                       
		QString get_phone_code() { return "+241"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Gabon.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "2";         			
	        	z << "3";         			
	        	z << "4";         			
	        	z << "5";         			
	        	z << "6";         			
	        	z << "7";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Senegal> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Senegal"; }                       
		QString get_phone_code() { return "+221"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Senegal.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "76";         			
	        	z << "77";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Dominica> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Dominica"; }                       
		QString get_phone_code() { return "+1"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Dominica.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Ukraine> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Ukraine"; }                       
		QString get_phone_code() { return "+380"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Ukraine.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "39";         			
	        	z << "50";         			
	        	z << "63";         			
	        	z << "66";         			
	        	z << "67";         			
	        	z << "68";         			
	        	z << "91";         			
	        	z << "92";         			
	        	z << "93";         			
	        	z << "94";         			
	        	z << "95";         			
	        	z << "96";         			
	        	z << "97";         			
	        	z << "98";         			
	        	z << "99";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Turkey> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Turkey"; }                       
		QString get_phone_code() { return "+90"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Turkey.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "50";         			
	        	z << "53";         			
	        	z << "54";         			
	        	z << "55";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Ireland> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Ireland"; }                       
		QString get_phone_code() { return "+353"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Ireland.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "83";         			
	        	z << "85";         			
	        	z << "86";         			
	        	z << "87";         			
	        	z << "89";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Jamaica> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Jamaica"; }                       
		QString get_phone_code() { return "+1"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Jamaica.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "876";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<SaintHelenaandTristandaCunhanotAscenscion> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Saint Helena and Tristan da Cunha (not Ascenscion)"; }                       
		QString get_phone_code() { return "+290"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("SaintHelenaandTristandaCunhanotAscenscion.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Mayotte> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Mayotte"; }                       
		QString get_phone_code() { return "+262"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Mayotte.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Saba> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Saba"; }                       
		QString get_phone_code() { return "+599"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Saba.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Bhutan> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Bhutan"; }                       
		QString get_phone_code() { return "+975"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Bhutan.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "17";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Guinea> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Guinea"; }                       
		QString get_phone_code() { return "+224"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Guinea.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "6";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<DominicanRepublic> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Dominican Republic"; }                       
		QString get_phone_code() { return "+1"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("DominicanRepublic.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "809";         			
	        	z << "829";         			
	        	z << "849";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Nigeria> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Nigeria"; }                       
		QString get_phone_code() { return "+234"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Nigeria.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "804";         			
	        	z << "805";         			
	        	z << "803";         			
	        	z << "802";         			
	        	z << "809";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Greece> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Greece"; }                       
		QString get_phone_code() { return "+30"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Greece.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "690";         			
	        	z << "693";         			
	        	z << "694";         			
	        	z << "695";         			
	        	z << "697";         			
	        	z << "698";         			
	        	z << "699";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<FrenchGuiana> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "French Guiana"; }                       
		QString get_phone_code() { return "+594"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("FrenchGuiana.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "694";         			
	        	z << "700";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<SaudiArabia> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Saudi Arabia"; }                       
		QString get_phone_code() { return "+966"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("SaudiArabia.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "50";         			
	        	z << "51";         			
	        	z << "53";         			
	        	z << "54";         			
	        	z << "55";         			
	        	z << "56";         			
	        	z << "57";         			
	        	z << "58";         			
	        	z << "59";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Liberia> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Liberia"; }                       
		QString get_phone_code() { return "+231"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Liberia.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "46";         			
	        	z << "47";         			
	        	z << "5";         			
	        	z << "64";         			
	        	z << "65";         			
	        	z << "7";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Cyprus> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Cyprus"; }                       
		QString get_phone_code() { return "+357"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Cyprus.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "94";         			
	        	z << "95";         			
	        	z << "96";         			
	        	z << "97";         			
	        	z << "99";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Uzbekistan> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Uzbekistan"; }                       
		QString get_phone_code() { return "+998"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Uzbekistan.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "90";         			
	        	z << "91";         			
	        	z << "93";         			
	        	z << "94";         			
	        	z << "97";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Barbados> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Barbados"; }                       
		QString get_phone_code() { return "+1"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Barbados.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "246";         			
	        	z << "246";         			
	        	z << "246";         			
	        	z << "246";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<NorthernMarianaIslands> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Northern Mariana Islands"; }                       
		QString get_phone_code() { return "+1"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("NorthernMarianaIslands.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "670";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Martinique> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Martinique"; }                       
		QString get_phone_code() { return "+596"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Martinique.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "696";         			
	        	z << "700";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<CocosKeelingIslands> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Cocos (Keeling) Islands"; }                       
		QString get_phone_code() { return "+61"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("CocosKeelingIslands.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Andorra> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Andorra"; }                       
		QString get_phone_code() { return "+376"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Andorra.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "3";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Tunisia> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Tunisia"; }                       
		QString get_phone_code() { return "+216"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Tunisia.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "2";         			
	        	z << "3";         			
	        	z << "4";         			
	        	z << "5";         			
	        	z << "9";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Albania> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Albania"; }                       
		QString get_phone_code() { return "+355"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Albania.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "66";         			
	        	z << "67";         			
	        	z << "68";         			
	        	z << "69";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Yemen> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Yemen"; }                       
		QString get_phone_code() { return "+967"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Yemen.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "70";         			
	        	z << "71";         			
	        	z << "73";         			
	        	z << "77";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<CaymanIslands> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Cayman Islands"; }                       
		QString get_phone_code() { return "+1"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("CaymanIslands.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "345";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Maldives> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Maldives"; }                       
		QString get_phone_code() { return "+960"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Maldives.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "7";         			
	        	z << "9";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<FalklandIslands> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Falkland Islands"; }                       
		QString get_phone_code() { return "+500"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("FalklandIslands.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "5";         			
	        	z << "6";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Romania> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Romania"; }                       
		QString get_phone_code() { return "+40"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Romania.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "711";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Macau> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Macau"; }                       
		QString get_phone_code() { return "+853"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Macau.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "6";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<ChagosIslands> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Chagos Islands"; }                       
		QString get_phone_code() { return "+246"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("ChagosIslands.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "387";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Libya> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Libya"; }                       
		QString get_phone_code() { return "+218"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Libya.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "91";         			
	        	z << "92";         			
	        	z << "94";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Namibia> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Namibia"; }                       
		QString get_phone_code() { return "+264"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Namibia.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "60";         			
	        	z << "81";         			
	        	z << "85";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<England> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "England"; }                       
		QString get_phone_code() { return "+44"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("England.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<TristandaCunha> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Tristan da Cunha"; }                       
		QString get_phone_code() { return "+290"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("TristandaCunha.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "8";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Mauritania> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Mauritania"; }                       
		QString get_phone_code() { return "+222"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Mauritania.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "6";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<SintMaarten> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Sint Maarten"; }                       
		QString get_phone_code() { return "+1"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("SintMaarten.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "721";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<SierraLeone> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Sierra Leone"; }                       
		QString get_phone_code() { return "+232"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("SierraLeone.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "23";         			
	        	z << "30";         			
	        	z << "33";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<BurkinaFaso> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Burkina Faso"; }                       
		QString get_phone_code() { return "+226"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("BurkinaFaso.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "70";         			
	        	z << "71";         			
	        	z << "72";         			
	        	z << "74";         			
	        	z << "75";         			
	        	z << "77";         			
	        	z << "78";         			
	        	z << "79";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<NorthernIreland> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Northern Ireland"; }                       
		QString get_phone_code() { return "+44"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("NorthernIreland.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<UnitedStatesVirginIslands> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "United States Virgin Islands"; }                       
		QString get_phone_code() { return "+1"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("UnitedStatesVirginIslands.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "340";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<SintEustatius> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Sint Eustatius"; }                       
		QString get_phone_code() { return "+599"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("SintEustatius.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Anguilla> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Anguilla"; }                       
		QString get_phone_code() { return "+1"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Anguilla.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Zimbabwe> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Zimbabwe"; }                       
		QString get_phone_code() { return "+263"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Zimbabwe.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "71";         			
	        	z << "73";         			
	        	z << "77";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<WesternSahara> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Western Sahara"; }                       
		QString get_phone_code() { return "+212"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("WesternSahara.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "5288";         			
	        	z << "5289";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Runion> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "R?union"; }                       
		QString get_phone_code() { return "+262"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Runion.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "700";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Myanmar> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Myanmar"; }                       
		QString get_phone_code() { return "+95"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Myanmar.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<ChristmasIsland> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Christmas Island"; }                       
		QString get_phone_code() { return "+61"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("ChristmasIsland.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Cameroon> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Cameroon"; }                       
		QString get_phone_code() { return "+237"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Cameroon.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "7";         			
	        	z << "9";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Italy> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Italy"; }                       
		QString get_phone_code() { return "+39"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Italy.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "310";         			
	        	z << "31100";         			
	        	z << "31101";         			
	        	z << "31105";         			
	        	z << "313";         			
	        	z << "319";         			
	        	z << "320";         			
	        	z << "322";         			
	        	z << "323";         			
	        	z << "324";         			
	        	z << "327";         			
	        	z << "328";         			
	        	z << "329";         			
	        	z << "330";         			
	        	z << "331";         			
	        	z << "333";         			
	        	z << "334";         			
	        	z << "335";         			
	        	z << "336";         			
	        	z << "337";         			
	        	z << "338";         			
	        	z << "339";         			
	        	z << "340";         			
	        	z << "341";         			
	        	z << "342";         			
	        	z << "343";         			
	        	z << "344";         			
	        	z << "345";         			
	        	z << "346";         			
	        	z << "347";         			
	        	z << "348";         			
	        	z << "349";         			
	        	z << "3505";         			
	        	z << "3510";         			
	        	z << "3512";         			
	        	z << "360";         			
	        	z << "361";         			
	        	z << "362";         			
	        	z << "363";         			
	        	z << "366";         			
	        	z << "368";         			
	        	z << "370";         			
	        	z << "3710";         			
	        	z << "3711";         			
	        	z << "373";         			
	        	z << "377";         			
	        	z << "380";         			
	        	z << "381";         			
	        	z << "382";         			
	        	z << "383";         			
	        	z << "385";         			
	        	z << "388";         			
	        	z << "389";         			
	        	z << "390";         			
	        	z << "391";         			
	        	z << "392";         			
	        	z << "393";         			
	        	z << "397";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<CapeVerde> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Cape Verde"; }                       
		QString get_phone_code() { return "+238"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("CapeVerde.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "9";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Monaco> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Monaco"; }                       
		QString get_phone_code() { return "+377"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Monaco.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "4";         			
	        	z << "6";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<GuineaBissau> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Guinea-Bissau"; }                       
		QString get_phone_code() { return "+245"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("GuineaBissau.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "6";         			
	        	z << "7";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Scotland> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Scotland"; }                       
		QString get_phone_code() { return "+44"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Scotland.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<AmericanSamoa> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "American Samoa"; }                       
		QString get_phone_code() { return "+1"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("AmericanSamoa.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "684";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Palau> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Palau"; }                       
		QString get_phone_code() { return "+680"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Palau.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<HongKong> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Hong Kong"; }                       
		QString get_phone_code() { return "+852"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("HongKong.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Montenegro> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Montenegro"; }                       
		QString get_phone_code() { return "+382"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Montenegro.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "60";         			
	        	z << "63";         			
	        	z << "66";         			
	        	z << "67";         			
	        	z << "68";         			
	        	z << "69";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<USVirginIslands> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "U.S. Virgin Islands"; }                       
		QString get_phone_code() { return "+1"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("USVirginIslands.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "340";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Zambia> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Zambia"; }                       
		QString get_phone_code() { return "+260"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Zambia.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Rwanda> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Rwanda"; }                       
		QString get_phone_code() { return "+250"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Rwanda.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "07";         			
	        	z << "08";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Uganda> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Uganda"; }                       
		QString get_phone_code() { return "+256"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Uganda.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<MarshallIslands> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Marshall Islands"; }                       
		QString get_phone_code() { return "+692"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("MarshallIslands.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Seychelles> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Seychelles"; }                       
		QString get_phone_code() { return "+248"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Seychelles.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "5";         			
	        	z << "7";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Nepal> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Nepal"; }                       
		QString get_phone_code() { return "+977"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Nepal.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<NorthernCyprus> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Northern Cyprus"; }                       
		QString get_phone_code() { return "+90"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("NorthernCyprus.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "533";         			
	        	z << "542";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Gibraltar> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Gibraltar"; }                       
		QString get_phone_code() { return "+350"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Gibraltar.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Tonga> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Tonga"; }                       
		QString get_phone_code() { return "+676"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Tonga.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "15";         			
	        	z << "16";         			
	        	z << "17";         			
	        	z << "18";         			
	        	z << "19";         			
	        	z << "87";         			
	        	z << "88";         			
	        	z << "89";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Jersey> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Jersey"; }                       
		QString get_phone_code() { return "+44"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Jersey.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<FederatedStatesofMicronesia> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Federated States of Micronesia"; }                       
		QString get_phone_code() { return "+691"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("FederatedStatesofMicronesia.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "92";         			
	        	z << "93";         			
	        	z << "95";         			
	        	z << "97";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<France> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "France"; }                       
		QString get_phone_code() { return "+33"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("France.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "6";         			
	        	z << "700";         			
	        	z << "73";         			
	        	z << "74";         			
	        	z << "75";         			
	        	z << "76";         			
	        	z << "77";         			
	        	z << "78";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Singapore> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Singapore"; }                       
		QString get_phone_code() { return "+65"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Singapore.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "8";         			
	        	z << "9";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Kosovo> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Kosovo"; }                       
		QString get_phone_code() { return "+383"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Kosovo.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "44";         			
	        	z << "45";         			
	        	z << "49";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Uruguay> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Uruguay"; }                       
		QString get_phone_code() { return "+598"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Uruguay.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "91";         			
	        	z << "93";         			
	        	z << "94";         			
	        	z << "95";         			
	        	z << "96";         			
	        	z << "97";         			
	        	z << "98";         			
	        	z << "99";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<IvoryCoast> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Ivory Coast"; }                       
		QString get_phone_code() { return "+225"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("IvoryCoast.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Bahrain> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Bahrain"; }                       
		QString get_phone_code() { return "+973"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Bahrain.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "31";         			
	        	z << "322";         			
	        	z << "33";         			
	        	z << "340";         			
	        	z << "341";         			
	        	z << "343";         			
	        	z << "344";         			
	        	z << "345";         			
	        	z << "353";         			
	        	z << "355";         			
	        	z << "36";         			
	        	z << "377";         			
	        	z << "383";         			
	        	z << "384";         			
	        	z << "388";         			
	        	z << "39";         			
	        	z << "663";         			
	        	z << "666";         			
	        	z << "669";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Luxembourg> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Luxembourg"; }                       
		QString get_phone_code() { return "+352"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Luxembourg.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "621";         			
	        	z << "628";         			
	        	z << "661";         			
	        	z << "668";         			
	        	z << "691";         			
	        	z << "698";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Artsakh> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Artsakh"; }                       
		QString get_phone_code() { return "+3714"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Artsakh.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "97";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Sweden> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Sweden"; }                       
		QString get_phone_code() { return "+46"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Sweden.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "70";         			
	        	z << "72";         			
	        	z << "76";         			
	        	z << "79";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<FaroeIslands> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Faroe Islands"; }                       
		QString get_phone_code() { return "+298"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("FaroeIslands.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "21";         			
	        	z << "22";         			
	        	z << "23";         			
	        	z << "24";         			
	        	z << "25";         			
	        	z << "26";         			
	        	z << "27";         			
	        	z << "28";         			
	        	z << "29";         			
	        	z << "71";         			
	        	z << "72";         			
	        	z << "73";         			
	        	z << "74";         			
	        	z << "75";         			
	        	z << "76";         			
	        	z << "77";         			
	        	z << "78";         			
	        	z << "79";         			
	        	z << "91";         			
	        	z << "92";         			
	        	z << "93";         			
	        	z << "94";         			
	        	z << "95";         			
	        	z << "96";         			
	        	z << "97";         			
	        	z << "98";         			
	        	z << "99";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<DemocraticRepublicofCongo> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Democratic Republic of Congo"; }                       
		QString get_phone_code() { return "+243"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("DemocraticRepublicofCongo.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "22";         			
	        	z << "78";         			
	        	z << "81";         			
	        	z << "84";         			
	        	z << "85";         			
	        	z << "86";         			
	        	z << "88";         			
	        	z << "89";         			
	        	z << "90";         			
	        	z << "94";         			
	        	z << "95";         			
	        	z << "96";         			
	        	z << "97";         			
	        	z << "98";         			
	        	z << "99";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Angola> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Angola"; }                       
		QString get_phone_code() { return "+244"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Angola.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "91";         			
	        	z << "92";         			
	        	z << "93";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<BosniaandHerzegovinaBosniaHerzegovina> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Bosnia and Herzegovina (Bosnia-Herzegovina)"; }                       
		QString get_phone_code() { return "+387"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("BosniaandHerzegovinaBosniaHerzegovina.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "60";         			
	        	z << "61";         			
	        	z << "62";         			
	        	z << "63";         			
	        	z << "64";         			
	        	z << "65";         			
	        	z << "66";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Tanzania> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Tanzania"; }                       
		QString get_phone_code() { return "+255"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Tanzania.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Prncipe> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Pr?ncipe"; }                       
		QString get_phone_code() { return "+239"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Prncipe.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "90";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

                                                                       

template <>                                                                 
class CountryInfo<Kiribati> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Kiribati"; }                       
		QString get_phone_code() { return "+686"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Kiribati.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<SaintPierreandMiquelon> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Saint Pierre and Miquelon"; }                       
		QString get_phone_code() { return "+508"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("SaintPierreandMiquelon.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<SolomonIslands> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Solomon Islands"; }                       
		QString get_phone_code() { return "+677"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("SolomonIslands.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "74";         			
	        	z << "75";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<EastTimor> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "East Timor"; }                       
		QString get_phone_code() { return "+670"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("EastTimor.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "77";         			
	        	z << "78";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Ghana> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Ghana"; }                       
		QString get_phone_code() { return "+233"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Ghana.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "20";         			
	        	z << "23";         			
	        	z << "24";         			
	        	z << "26";         			
	        	z << "27";         			
	        	z << "28";         			
	        	z << "54";         			
	        	z << "57";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Eritrea> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Eritrea"; }                       
		QString get_phone_code() { return "+291"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Eritrea.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "7";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<SouthSudan> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "South Sudan"; }                       
		QString get_phone_code() { return "+211"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("SouthSudan.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<UnitedKingdom> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "United Kingdom[4]"; }                       
		QString get_phone_code() { return "+44"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("UnitedKingdom.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "7624";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Bulgaria> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Bulgaria"; }                       
		QString get_phone_code() { return "+359"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Bulgaria.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "48";         			
	        	z << "87";         			
	        	z << "88";         			
	        	z << "89";         			
	        	z << "988";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Finland> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Finland"; }                       
		QString get_phone_code() { return "+358"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Finland.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "457";         			
	        	z << "50";         			
	        	z << "500";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Pakistan> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Pakistan"; }                       
		QString get_phone_code() { return "+92"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Pakistan.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Chad> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Chad"; }                       
		QString get_phone_code() { return "+235"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Chad.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "66";         			
	        	z << "63";         			
	        	z << "65";         			
	        	z << "99";         			
	        	z << "95";         			
	        	z << "93";         			
	        	z << "90";         			
	        	z << "77";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Tuvalu> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Tuvalu"; }                       
		QString get_phone_code() { return "+688"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Tuvalu.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Switzerland> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Switzerland"; }                       
		QString get_phone_code() { return "+41"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Switzerland.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "74";         			
	        	z << "76";         			
	        	z << "77";         			
	        	z << "78";         			
	        	z << "79";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          


template <>                                                                 
class CountryInfo<Curaao> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Cura?ao"; }                       
		QString get_phone_code() { return "+599"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Curaao.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Japan> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Japan"; }                       
		QString get_phone_code() { return "+81"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Japan.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "70";         			
	        	z << "80";         			
	        	z << "90";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Fiji> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Fiji"; }                       
		QString get_phone_code() { return "+679"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Fiji.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "3";         			
	        	z << "7";         			
	        	z << "9";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<BritishVirginIslands> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "British Virgin Islands"; }                       
		QString get_phone_code() { return "+1"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("BritishVirginIslands.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "284";         			
	        	z << "284";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<JanMayen> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Jan Mayen"; }                       
		QString get_phone_code() { return "+47"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("JanMayen.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "79";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Cuba> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Cuba"; }                       
		QString get_phone_code() { return "+53"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Cuba.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "5";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Kuwait> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Kuwait"; }                       
		QString get_phone_code() { return "+965"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Kuwait.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "5";         			
	        	z << "6";         			
	        	z << "9";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Hungary> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Hungary"; }                       
		QString get_phone_code() { return "+36"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Hungary.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "20";         			
	        	z << "30";         			
	        	z << "31";         			
	        	z << "70";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Egypt> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Egypt"; }                       
		QString get_phone_code() { return "+20"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Egypt.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "10";         			
	        	z << "11";         			
	        	z << "12";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Aruba> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Aruba"; }                       
		QString get_phone_code() { return "+297"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Aruba.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<UnitedArabEmirates> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "United Arab Emirates"; }                       
		QString get_phone_code() { return "+971"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("UnitedArabEmirates.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "50";         			
	        	z << "52";         			
	        	z << "54";         			
	        	z << "55";         			
	        	z << "56";         			
	        	z << "58";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Guatemala> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Guatemala"; }                       
		QString get_phone_code() { return "+502"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Guatemala.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "231";         			
	        	z << "2324";         			
	        	z << "2326";         			
	        	z << "2327";         			
	        	z << "2328";         			
	        	z << "2329";         			
	        	z << "2428";         			
	        	z << "2429";         			
	        	z << "30";         			
	        	z << "310";         			
	        	z << "311";         			
	        	z << "448";         			
	        	z << "449";         			
	        	z << "45";         			
	        	z << "46";         			
	        	z << "478";         			
	        	z << "479";         			
	        	z << "480";         			
	        	z << "481";         			
	        	z << "49";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Chile> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Chile"; }                       
		QString get_phone_code() { return "+56"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Chile.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "9";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Denmark> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Denmark"; }                       
		QString get_phone_code() { return "+45"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Denmark.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "30";         			
	        	z << "31";         			
	        	z << "40";         			
	        	z << "41";         			
	        	z << "42";         			
	        	z << "50";         			
	        	z << "51";         			
	        	z << "52";         			
	        	z << "53";         			
	        	z << "60";         			
	        	z << "61";         			
	        	z << "71";         			
	        	z << "81";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Niue> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Niue"; }                       
		QString get_phone_code() { return "+683"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Niue.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "1";         			
	        	z << "3";         			
	        	z << "4";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Wales> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Wales"; }                       
		QString get_phone_code() { return "+44"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Wales.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Moldova> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Moldova"; }                       
		QString get_phone_code() { return "+373"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Moldova.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Malta> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Malta"; }                       
		QString get_phone_code() { return "+356"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Malta.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "77";         			
	        	z << "79";         			
	        	z << "98";         			
	        	z << "99";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Mexico> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Mexico"; }                       
		QString get_phone_code() { return "+52"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Mexico.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "1";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Madeira> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Madeira"; }                       
		QString get_phone_code() { return "+351"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Madeira.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Kenya> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Kenya"; }                       
		QString get_phone_code() { return "+254"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Kenya.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "763";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Grenada> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Grenada"; }                       
		QString get_phone_code() { return "+1"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Grenada.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Hawaii> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Hawaii"; }                       
		QString get_phone_code() { return "+1"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Hawaii.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "808";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Mozambique> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Mozambique"; }                       
		QString get_phone_code() { return "+258"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Mozambique.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Netherlands> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Netherlands"; }                       
		QString get_phone_code() { return "+31"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Netherlands.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "6";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Turkmenistan> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Turkmenistan"; }                       
		QString get_phone_code() { return "+993"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Turkmenistan.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "65";         			
	        	z << "66";         			
	        	z << "67";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<PapuaNewGuinea> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Papua New Guinea"; }                       
		QString get_phone_code() { return "+675"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("PapuaNewGuinea.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "68";         			
	        	z << "69";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Madagascar> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Madagascar"; }                       
		QString get_phone_code() { return "+261"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Madagascar.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<CanaryIslands> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Canary Islands"; }                       
		QString get_phone_code() { return "+34"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("CanaryIslands.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Honduras> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Honduras"; }                       
		QString get_phone_code() { return "+504"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Honduras.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "3";         			
	        	z << "7";         			
	        	z << "8";         			
	        	z << "9";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<SriLanka> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Sri Lanka"; }                       
		QString get_phone_code() { return "+94"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("SriLanka.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "70";         			
	        	z << "71";         			
	        	z << "72";         			
	        	z << "75";         			
	        	z << "76";         			
	        	z << "77";         			
	        	z << "78";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<AntiguaandBarbuda> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Antigua and Barbuda"; }                       
		QString get_phone_code() { return "+1"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("AntiguaandBarbuda.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<SoTomandPrncipe> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "S?o Tom? and Pr?ncipe"; }                       
		QString get_phone_code() { return "+239"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("SoTomandPrncipe.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "90";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Bahamas> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Bahamas"; }                       
		QString get_phone_code() { return "+1"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Bahamas.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Colombia> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Colombia"; }                       
		QString get_phone_code() { return "+57"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Colombia.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "310";         			
	        	z << "311";         			
	        	z << "312";         			
	        	z << "313";         			
	        	z << "314";         			
	        	z << "315";         			
	        	z << "316";         			
	        	z << "317";         			
	        	z << "318";         			
	        	z << "319";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Poland> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Poland"; }                       
		QString get_phone_code() { return "+48"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Poland.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Comoros> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Comoros"; }                       
		QString get_phone_code() { return "+269"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Comoros.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "3";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<PeoplesRepublicofChina> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "People's Republic of China"; }                       
		QString get_phone_code() { return "+86"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("PeoplesRepublicofChina.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<NewZealand> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "New Zealand"; }                       
		QString get_phone_code() { return "+64"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("NewZealand.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "20";         			
	        	z << "21";         			
	        	z << "22";         			
	        	z << "24";         			
	        	z << "25";         			
	        	z << "27";         			
	        	z << "280";         			
	        	z << "28";         			
	        	z << "283";         			
	        	z << "28";         			
	        	z << "29";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Lesotho> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Lesotho"; }                       
		QString get_phone_code() { return "+266"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Lesotho.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "58";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<RepublicofMacedonia> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Republic of Macedonia"; }                       
		QString get_phone_code() { return "+389"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("RepublicofMacedonia.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "70";         			
	        	z << "71";         			
	        	z << "72";         			
	        	z << "79";         			
	        	z << "75";         			
	        	z << "76";         			
	        	z << "77";         			
	        	z << "78";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Malawi> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Malawi"; }                       
		QString get_phone_code() { return "+265"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Malawi.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "8";         			
	        	z << "9";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<AscensionIsland> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Ascension Island"; }                       
		QString get_phone_code() { return "+247"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("AscensionIsland.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Sudan> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Sudan"; }                       
		QString get_phone_code() { return "+249"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Sudan.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "9";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<FrenchPolynesia> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "French Polynesia"; }                       
		QString get_phone_code() { return "+689"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("FrenchPolynesia.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Indonesia> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Indonesia"; }                       
		QString get_phone_code() { return "+62"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Indonesia.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "811";         			
	        	z << "812";         			
	        	z << "813";         			
	        	z << "814";         			
	        	z << "815";         			
	        	z << "816";         			
	        	z << "817";         			
	        	z << "818";         			
	        	z << "819";         			
	        	z << "838";         			
	        	z << "852";         			
	        	z << "853";         			
	        	z << "855";         			
	        	z << "856";         			
	        	z << "858";         			
	        	z << "859";         			
	        	z << "878";         			
	        	z << "896";         			
	        	z << "897";         			
	        	z << "898";         			
	        	z << "899";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<Peru> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Peru"; }                       
		QString get_phone_code() { return "+51"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("Peru.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "9";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                                                          

template <>                                                                 
class CountryInfo<EasterIsland> : public GenericCountry                            
{                                                                           
	public:                                                                    
		                                                                       
		QString get_country_name() { return "Easter Island"; }                       
		QString get_phone_code() { return "+56"; }                         
		QIcon get_flag_icon() { return QIcon(ZICONS_DIR_STR("EasterIsland.png")); }  
		QStringList get_mobile_operator_codes() {                              
			QStringList z;                                                     
	        	z << "32";         			
			                                                                   
			return z;                                                          
		}                                                                      
};                                         

/*
template <std::size_t ... Is>
auto iterateCountry (std::index_sequence<Is...> const &)
 { return std::make_tuple(CountryInfo<static_cast<CountryName>(Is)>{}...); }
 
 */

class CountryInfoManager 
{
	
	public: 
		/*
			void create() {
			auto ict { iterateCountry(
					 std::make_index_sequence<static_cast<std::size_t>(
						CountryName::Size)>{}) };

		}
		*/
		
		CountryInfoManager() { 
			
			   
			/**/
			add_to_list(new CountryInfo<PitcairnIslands>());
			add_to_list(new CountryInfo<Samoa>());
			add_to_list(new CountryInfo<Ethiopia>());
			add_to_list(new CountryInfo<CaymanIslands>());
			add_to_list(new CountryInfo<Guam>());
			add_to_list(new CountryInfo<Seychelles>());
			add_to_list(new CountryInfo<Prncipe>());
			add_to_list(new CountryInfo<Saba>());
			add_to_list(new CountryInfo<Cyprus>());
			add_to_list(new CountryInfo<MarshallIslands>());
			add_to_list(new CountryInfo<Romania>());
			add_to_list(new CountryInfo<TrinidadandTobago>());
			add_to_list(new CountryInfo<England>());
			add_to_list(new CountryInfo<CocosKeelingIslands>());
			add_to_list(new CountryInfo<Nigeria>());
			add_to_list(new CountryInfo<Iran>());
			add_to_list(new CountryInfo<IvoryCoast>());
			add_to_list(new CountryInfo<SolomonIslands>());
			add_to_list(new CountryInfo<Japan>());
			add_to_list(new CountryInfo<CollectivityofSaintMartin>());
			add_to_list(new CountryInfo<Bahamas>());
			add_to_list(new CountryInfo<Djibouti>());
			add_to_list(new CountryInfo<FrenchOverseasDepartmentsandTerritories>());
			add_to_list(new CountryInfo<Guinea>());
			add_to_list(new CountryInfo<Libya>());
			add_to_list(new CountryInfo<SaintBarthlemy>());
			add_to_list(new CountryInfo<Comoros>());
			add_to_list(new CountryInfo<BritishIndianOceanTerritory>());
			add_to_list(new CountryInfo<BosniaandHerzegovinaBosniaHerzegovina>());
			add_to_list(new CountryInfo<Cuba>());
			add_to_list(new CountryInfo<VaticanCity>());
			add_to_list(new CountryInfo<Dominica>());
			add_to_list(new CountryInfo<Mexico>());
			add_to_list(new CountryInfo<NorthernCyprus>());
			add_to_list(new CountryInfo<Bhutan>());
			add_to_list(new CountryInfo<Albania>());
			add_to_list(new CountryInfo<Niue>());
			add_to_list(new CountryInfo<Brazil>());
			add_to_list(new CountryInfo<Belarus>());
			add_to_list(new CountryInfo<Kosovo>());
			add_to_list(new CountryInfo<Benin>());
			add_to_list(new CountryInfo<Taiwan>());
			add_to_list(new CountryInfo<UnitedKingdom>());
			add_to_list(new CountryInfo<Abkhazia>());
			add_to_list(new CountryInfo<Malaysia>());
			add_to_list(new CountryInfo<Yemen>());
			add_to_list(new CountryInfo<FrenchOverseasDepartmentsandTerritories>());
			add_to_list(new CountryInfo<AntiguaandBarbuda>());
			add_to_list(new CountryInfo<Wales>());
			add_to_list(new CountryInfo<Montserrat>());
			add_to_list(new CountryInfo<Nicaragua>());
			add_to_list(new CountryInfo<Canada>());
			add_to_list(new CountryInfo<Mozambique>());
			add_to_list(new CountryInfo<Maldives>());
			add_to_list(new CountryInfo<SouthKorea>());
			add_to_list(new CountryInfo<Guatemala>());
			add_to_list(new CountryInfo<Gambia>());
			add_to_list(new CountryInfo<Armenia>());
			add_to_list(new CountryInfo<TristandaCunha>());
			add_to_list(new CountryInfo<Namibia>());
			add_to_list(new CountryInfo<Lithuania>());
			add_to_list(new CountryInfo<SouthGeorgiaandtheSouthSandwichIslands>());
			add_to_list(new CountryInfo<Cambodia>());
			add_to_list(new CountryInfo<Kazakhstan>());
			add_to_list(new CountryInfo<Oman>());
			add_to_list(new CountryInfo<SintMaarten>());
			add_to_list(new CountryInfo<Lesotho>());
			add_to_list(new CountryInfo<Andorra>());
			add_to_list(new CountryInfo<Algeria>());
			add_to_list(new CountryInfo<SaintPierreandMiquelon>());
			add_to_list(new CountryInfo<EastTimor>());
			add_to_list(new CountryInfo<Pakistan>());
			add_to_list(new CountryInfo<DominicanRepublic>());
			add_to_list(new CountryInfo<Guernsey>());
			add_to_list(new CountryInfo<Kiribati>());
			add_to_list(new CountryInfo<Guadeloupe>());
			add_to_list(new CountryInfo<BritishVirginIslands>());
			add_to_list(new CountryInfo<NorthKorea>());
			add_to_list(new CountryInfo<Ecuador>());
			add_to_list(new CountryInfo<SaudiArabia>());
			add_to_list(new CountryInfo<Qatar>());
			add_to_list(new CountryInfo<NewZealand>());
			add_to_list(new CountryInfo<FrenchOverseasDepartmentsandTerritories>());
			add_to_list(new CountryInfo<Denmark>());
			add_to_list(new CountryInfo<CuraaoandtheCaribbeanNetherlands>());
			add_to_list(new CountryInfo<AustralianAntarcticTerritory>());
			add_to_list(new CountryInfo<Kuwait>());
			add_to_list(new CountryInfo<Kenya>());
			add_to_list(new CountryInfo<AmericanSamoa>());
			add_to_list(new CountryInfo<Scotland>());
			add_to_list(new CountryInfo<Morocco>());
			add_to_list(new CountryInfo<Jamaica>());
			add_to_list(new CountryInfo<Colombia>());
			add_to_list(new CountryInfo<CentralAfricanRepublic>());
			add_to_list(new CountryInfo<Moldova>());
			add_to_list(new CountryInfo<Monaco>());
			add_to_list(new CountryInfo<BurkinaFaso>());
			add_to_list(new CountryInfo<Curaao>());
			add_to_list(new CountryInfo<Runion>());
			add_to_list(new CountryInfo<Belgium>());
			add_to_list(new CountryInfo<Uganda>());
			add_to_list(new CountryInfo<FalklandIslands>());
			add_to_list(new CountryInfo<Mali>());
			add_to_list(new CountryInfo<Abkhazia>());
			add_to_list(new CountryInfo<Greenland>());
			add_to_list(new CountryInfo<Bulgaria>());
			add_to_list(new CountryInfo<Bermuda>());
			add_to_list(new CountryInfo<Hawaii>());
			add_to_list(new CountryInfo<PuertoRico>());
			add_to_list(new CountryInfo<France>());
			add_to_list(new CountryInfo<Ireland>());
			add_to_list(new CountryInfo<RepublicofCongo>());
			add_to_list(new CountryInfo<Svalbard>());
			add_to_list(new CountryInfo<Burma>());
			add_to_list(new CountryInfo<ElSalvador>());
			add_to_list(new CountryInfo<Syria>());
			add_to_list(new CountryInfo<Portugal>());
			add_to_list(new CountryInfo<SierraLeone>());
			add_to_list(new CountryInfo<Germany>());
			add_to_list(new CountryInfo<Tunisia>());
			add_to_list(new CountryInfo<CapeVerde>());
			add_to_list(new CountryInfo<FaroeIslands>());
			add_to_list(new CountryInfo<CostaRica>());
			add_to_list(new CountryInfo<Turkmenistan>());
			add_to_list(new CountryInfo<Italy>());
			add_to_list(new CountryInfo<Senegal>());
			add_to_list(new CountryInfo<UnitedArabEmirates>());
			add_to_list(new CountryInfo<Suriname>());
			add_to_list(new CountryInfo<Angola>());
			add_to_list(new CountryInfo<Uzbekistan>());
			add_to_list(new CountryInfo<Luxembourg>());
			add_to_list(new CountryInfo<HongKong>());
			add_to_list(new CountryInfo<NorthernIreland>());
			add_to_list(new CountryInfo<Somalia>());
			add_to_list(new CountryInfo<Gibraltar>());
			add_to_list(new CountryInfo<FrenchPolynesia>());
			add_to_list(new CountryInfo<Mongolia>());
			add_to_list(new CountryInfo<NorthernMarianaIslands>());
			add_to_list(new CountryInfo<Bahrain>());
			add_to_list(new CountryInfo<Guyana>());
			add_to_list(new CountryInfo<Kyrgyzstan>());
			add_to_list(new CountryInfo<Swaziland>());
			add_to_list(new CountryInfo<Chad>());
			add_to_list(new CountryInfo<Hungary>());
			add_to_list(new CountryInfo<Greece>());
			add_to_list(new CountryInfo<Belize>());
			add_to_list(new CountryInfo<Tonga>());
			add_to_list(new CountryInfo<WesternSahara>());
			add_to_list(new CountryInfo<CzechRepublic>());
			add_to_list(new CountryInfo<Madeira>());
			add_to_list(new CountryInfo<Mauritius>());
			add_to_list(new CountryInfo<Latvia>());
			add_to_list(new CountryInfo<SouthSudan>());
			add_to_list(new CountryInfo<SriLanka>());
			add_to_list(new CountryInfo<Laos>());
			add_to_list(new CountryInfo<Botswana>());
			add_to_list(new CountryInfo<FrenchOverseasDepartmentsandTerritories>());
			add_to_list(new CountryInfo<Bangladesh>());
			add_to_list(new CountryInfo<Israel>());
			add_to_list(new CountryInfo<Australia>());
			add_to_list(new CountryInfo<Azerbaijan>());
			add_to_list(new CountryInfo<EquatorialGuinea>());
			add_to_list(new CountryInfo<DemocraticRepublicofCongo>());
			add_to_list(new CountryInfo<Bolivia>());
			add_to_list(new CountryInfo<Palau>());
			add_to_list(new CountryInfo<Zimbabwe>());
			add_to_list(new CountryInfo<NorfolkIsland>());
			add_to_list(new CountryInfo<Melilla>());
			add_to_list(new CountryInfo<ChagosIslands>());
			add_to_list(new CountryInfo<Martinique>());
			add_to_list(new CountryInfo<Malawi>());
			add_to_list(new CountryInfo<WallisandFutuna>());
			add_to_list(new CountryInfo<FrenchOverseasDepartmentsandTerritories>());
			add_to_list(new CountryInfo<Nauru>());
			add_to_list(new CountryInfo<Ghana>());
			add_to_list(new CountryInfo<Switzerland>());
			add_to_list(new CountryInfo<Sweden>());
			add_to_list(new CountryInfo<FrenchGuiana>());
			add_to_list(new CountryInfo<Grenada>());
			add_to_list(new CountryInfo<Zambia>());
			add_to_list(new CountryInfo<Jordan>());
			add_to_list(new CountryInfo<Plazasdesoberana>());
			add_to_list(new CountryInfo<Jersey>());
			add_to_list(new CountryInfo<IsleofMan>());
			add_to_list(new CountryInfo<Brunei>());
			add_to_list(new CountryInfo<Madagascar>());
			add_to_list(new CountryInfo<Finland>());
			add_to_list(new CountryInfo<Ukraine>());
			add_to_list(new CountryInfo<Spain>());
			add_to_list(new CountryInfo<Venezuela>());
			add_to_list(new CountryInfo<AscensionIsland>());
			add_to_list(new CountryInfo<Poland>());
			add_to_list(new CountryInfo<Ceuta>());
			add_to_list(new CountryInfo<SaintHelenaandTristandaCunhanotAscenscion>());
			add_to_list(new CountryInfo<Chile>());
			add_to_list(new CountryInfo<Netherlands>());
			add_to_list(new CountryInfo<SaintKittsandNevis>());
			add_to_list(new CountryInfo<PeoplesRepublicofChina>());
			add_to_list(new CountryInfo<USVirginIslands>());
			add_to_list(new CountryInfo<SlovakiaSlovakRepublic>());
			add_to_list(new CountryInfo<ChristmasIsland>());
			add_to_list(new CountryInfo<Norway>());
			add_to_list(new CountryInfo<CookIslands>());
			add_to_list(new CountryInfo<Mayotte>());
			add_to_list(new CountryInfo<Turkey>());
			add_to_list(new CountryInfo<CanaryIslands>());
			add_to_list(new CountryInfo<RepublicofMacedonia>());
			add_to_list(new CountryInfo<Barbados>());
			add_to_list(new CountryInfo<Egypt>());
			add_to_list(new CountryInfo<Tuvalu>());
			add_to_list(new CountryInfo<Slovenia>());
			add_to_list(new CountryInfo<RussiaRussianFederation>());
			add_to_list(new CountryInfo<PapuaNewGuinea>());
			add_to_list(new CountryInfo<Vanuatu>());
			add_to_list(new CountryInfo<Philippines>());
			add_to_list(new CountryInfo<Montenegro>());
			add_to_list(new CountryInfo<Tokelau>());
			add_to_list(new CountryInfo<Artsakh>());
			add_to_list(new CountryInfo<Eritrea>());
			add_to_list(new CountryInfo<Gabon>());
			add_to_list(new CountryInfo<Haiti>());
			add_to_list(new CountryInfo<Tanzania>());
			add_to_list(new CountryInfo<SahrawiArabDemocraticRepublic>());
			add_to_list(new CountryInfo<Georgia>());
			add_to_list(new CountryInfo<SaintVincentandtheGrenadines>());
			add_to_list(new CountryInfo<Singapore>());
			add_to_list(new CountryInfo<Burundi>());
			add_to_list(new CountryInfo<Liberia>());
			add_to_list(new CountryInfo<TurksandCaicosIslands>());
			add_to_list(new CountryInfo<FederatedStatesofMicronesia>());
			add_to_list(new CountryInfo<Peru>());
			add_to_list(new CountryInfo<Paraguay>());
			add_to_list(new CountryInfo<Panama>());
			add_to_list(new CountryInfo<Iceland>());
			add_to_list(new CountryInfo<SaintLucia>());
			add_to_list(new CountryInfo<SintEustatius>());
			add_to_list(new CountryInfo<Aruba>());
			add_to_list(new CountryInfo<Malta>());
			add_to_list(new CountryInfo<SanMarino>());
			add_to_list(new CountryInfo<Thailand>());
			add_to_list(new CountryInfo<SoTomandPrncipe>());
			add_to_list(new CountryInfo<Cameroon>());
			add_to_list(new CountryInfo<Tajikistan>());
			add_to_list(new CountryInfo<NewCaledonia>());
			add_to_list(new CountryInfo<JanMayen>());
			add_to_list(new CountryInfo<Macau>());
			add_to_list(new CountryInfo<Uruguay>());
			add_to_list(new CountryInfo<Nepal>());
			add_to_list(new CountryInfo<GuineaBissau>());
			add_to_list(new CountryInfo<Bonaire>());
			add_to_list(new CountryInfo<SouthAfrica>());
			add_to_list(new CountryInfo<UnitedStatesUSA>());
			add_to_list(new CountryInfo<Mauritania>());
			add_to_list(new CountryInfo<Myanmar>());
			add_to_list(new CountryInfo<Indonesia>());
			add_to_list(new CountryInfo<Niger>());
			add_to_list(new CountryInfo<Austria>());
			add_to_list(new CountryInfo<Argentina>());
			add_to_list(new CountryInfo<Lebanon>());
			add_to_list(new CountryInfo<UnitedStatesVirginIslands>());
			add_to_list(new CountryInfo<Honduras>());
			add_to_list(new CountryInfo<Serbia>());
			add_to_list(new CountryInfo<Iraq>());
			add_to_list(new CountryInfo<SouthOssetia>());
			add_to_list(new CountryInfo<Croatia>());
			add_to_list(new CountryInfo<DiegoGarcia>());
			add_to_list(new CountryInfo<Sudan>());
			add_to_list(new CountryInfo<Togo>());
			add_to_list(new CountryInfo<EasterIsland>());
			add_to_list(new CountryInfo<Vietnam>());
			add_to_list(new CountryInfo<Afghanistan>());
			add_to_list(new CountryInfo<Rwanda>());
			add_to_list(new CountryInfo<Liechtenstein>());
			add_to_list(new CountryInfo<Fiji>());
			add_to_list(new CountryInfo<Estonia>());
			add_to_list(new CountryInfo<Anguilla>());
			/**/
		}
		
		/*
		static void  create() {
			for(auto i=0; i<CountryName::Size; ++i) {
				const int j=  i;
				 CountryInfo<(static_cast<CountryName>(j))>();
				//new CountryInfo<(static_cast<CountryName>(j))>();
			}
		}
		
		constexpr auto
		all_countries() {
		return countries(std::make_index_sequence<Size>());
		}
		
		*/
		void add_to_list(GenericCountry* c) {
			m_countries.push_back(c);
		}
		
		static QList<GenericCountry*> get_list() {
		
			return m_countries;
		}
		
	public:
		static QList<GenericCountry*> m_countries;
		
};

#endif
