#include "Product.h"
//2 copieri
//Product::Product(uint16_t id, std::string name, float price, uint16_t VAT, std::string expDate)
//	:m_id{ id },
//	m_name{name},
//	m_price{price},
//	m_VAT{ VAT },
//	m_expDate{ expDate }
//{
//}
//3 copieri
//Product::Product(uint16_t id, std::string name, float price, uint16_t VAT, ProductType productType)
//	:m_id{ id },
//	m_name{ name },
//	m_price{ price },
//	m_VAT{ VAT }, 
//	m_productType{ productType }
//{
//	/*m_id=id;
//	m_name=name;
//	m_price=price;
//	m_VAT=VAT;
//	m_productType = productType;*/
////	ctrl k c comentare
////	ctrl k u decomentare
//}

Product::Product(uint16_t id, std::string name, float price, uint16_t VAT, std::variant<std::string, ProductType> expDateOrProductType):
	m_id{ id },
	m_name{name},
	m_price{price},
	m_VAT{ VAT },
	m_expDateOrProductType{ expDateOrProductType }
{
}

uint16_t Product::getId()
{
	return m_id;
}

std::variant<std::string, ProductType> Product::getExpDateOrProductType()
{
	return m_expDateOrProductType;
}
