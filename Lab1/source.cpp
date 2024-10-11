//#include <iostream>
//#include <vector>
//#include <fstream>
//#include "Product.h"
//int main() {
//	std::vector<Product> products;
//
//	for (std::ifstream fisier("product.probd");!fisier.eof();/*empty*/) {
//		uint16_t id;
//		std::string name;
//		float price;
//		uint16_t VAT;
//		std::string expDatemOrType;
//		//se recomanda sa le declaram in interior
//		//deoarece vor fi tinute in memoria cache(pentru ca durata de viata sa fie cat mai mica)
//		if (!fisier) {
//			std::cout << "File is wrong";
//		}
//		fisier >> id>> name>> price>> VAT>> expDatemOrType;
//		//Product p{ id,name,price,VAT,expDatemOrType };
//		products.emplace_back( id,name,price,VAT,expDatemOrType );
//		//emplace_back() cand cream acum obiectul
//		//push_back cand exista obiectul
//		
//	}
//	return 0;
//}
//tema suplimentara
//std::variant
//specificam 2 tipuri de date si in functie de context alege una sau alta pentru produs
//tema
//instalam smartgit si git
//


#include <iostream>
#include <vector>
#include <fstream>
#include <variant>
#include "Product.h"
#include "ProductType.h"

int main() {
    std::vector<Product> products;
    std::ifstream fisier("product.probd");

	for (std::ifstream fisier("product.probd");!fisier.eof();/*empty*/) {
		uint16_t id;
		std::string name;
		float price;
		uint16_t VAT;
        std::variant<std::string, ProductType> expDateOrType;
		if (!fisier) {
			std::cout << "file is wrong";
		}
     
        fisier >> id >> name >> price >> VAT;

        std::string typeOrDate;
        fisier >> typeOrDate;

        if (typeOrDate == "PersonalHygiene") {
            expDateOrType = ProductType::PersonalHygiene;
        }
        else if (typeOrDate == "SmallAppliances") {
            expDateOrType = ProductType::SmallAppliances;
        }
        else if (typeOrDate == "Clothing") {
            expDateOrType = ProductType::Clothing;
        }
        else {
            expDateOrType = typeOrDate; 
        }

        products.emplace_back(id, name, price, VAT, expDateOrType);
    }

    for (int i = 0; i < products.size(); i++) {
        std::cout << "Product ID: " << products[i].getId() << "\n";

        auto expDateOrType = products[i].getExpDateOrProductType();
        if (std::holds_alternative<std::string>(expDateOrType)) {
            std::cout << "Expiration Date: " << std::get<std::string>(expDateOrType) << "\n";
        }
        else if (std::holds_alternative<ProductType>(expDateOrType)) {
            ProductType type = std::get<ProductType>(expDateOrType);
            std::cout << "Product Type: ";
            switch (type) {
            case ProductType::PersonalHygiene:
                std::cout << "Personal Hygiene\n";
                break;
            case ProductType::SmallAppliances:
                std::cout << "Small Appliances\n";
                break;
            case ProductType::Clothing:
                std::cout << "Clothing\n";
                break;
            default:
                std::cout << "Unknown Product Type\n";
                break;
            }
        }
    }

    return 0;
}
