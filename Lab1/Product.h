#pragma once
#include <string>
#include <cstdint>
#include <variant>
#include "ProductType.h"
class Product
{
public:
	Product() = default;
	//Product(uint16_t id, std::string name,float price,uint16_t VAT, std::string expDate);
	Product(uint16_t id, std::string name,float price,uint16_t VAT, std::variant<std::string, ProductType>expDateOrProductType);
private:
	uint16_t m_id;
	std::string m_name;
	float m_price;
	uint16_t m_VAT;
	std::variant<std::string, ProductType>m_expDateOrProductType;

public:
	uint16_t getId();
	std::variant<std::string, ProductType> getExpDateOrProductType();
};
//
//uint8_t pentru caractere 