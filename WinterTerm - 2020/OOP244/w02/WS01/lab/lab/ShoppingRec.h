//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF

#pragma once
#ifndef NAMESPACE_SHOPPINGREC_H // replace with relevant names
#define NAMESPACE_SHOPPINGREC_H

namespace sdds {

    const int MAX_TITLE_LENGTH = 50;
    const int MAX_QUANTITY_VALUE = 50;

    struct ShoppingRec {
        char m_title[MAX_TITLE_LENGTH + 1];
        int m_quantity;
        bool m_bought;
    };

    ShoppingRec getShoppingRec();

    void displayShoppingRec(const ShoppingRec* shp);
    void toggleBoughtFlag(ShoppingRec* rec);
    bool isShoppingRecEmpty(const ShoppingRec* shp);

}
#endif