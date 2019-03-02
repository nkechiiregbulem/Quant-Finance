//
//  main.cpp
//  Finance
//
//  Created by Nkechi Iregbulem on 3/1/19.
//  Copyright © 2019 Nkechi Iregbulem. All rights reserved.
//

#include <iostream>
#include "Option.h"
#include <string>
using namespace std;
#include <cmath>


void Option::init() {
    strike_price = 100.0;
    RFR = 0.05; // 5% interest rate
    mt = 1.0; // One year until maturity
    asset_price = 100.0; //Option is "at the money" as spot equals the strike
    sigma = 0.2; // Volatility is 20%
}
// The next implemented method is copy, a return type of void, because it does not need to return any values.
// The copy method is helper method used by the copy constructor and assigntment operator, designed to stop repeat code
// Copies the member data
void Option::copy(const Option& rhs) {
    strike_price = rhs.getStrikePrice();
    RFR = rhs.getRFR();
    mt = rhs.getMT();
    asset_price = rhs.getAssetPrice();
    sigma = rhs.getSigma();
}
// Constructors are special methods for classes, identified by their lack of return type (void)
// Here we will have two contructors: Default(calls the init helper method) and parameter-based(takes in all five parameters required to price an option and then initialises the underlying member data)

    Option::Option() { init (); }
    
Option::Option(const double& _strike_price, const double& _RFR,
               const double& _mt, const double& _asset_price,
               const double& _sigma) {
    
    strike_price = _strike_price;
    RFR = _RFR;
    mt = _mt;
    asset_price = _asset_price;
    sigma = _sigma;
}
// the "=" operator is used to assign an object to itself
// "this" always points to the undelying object, only available within the scope of a class
// *this means "get me a reference to the underlying object which this method belongs to"

// Copy Constructor
Option::Option(const Option& rhs) {
    copy(rhs);
}
// Assignment operator
Option& Option::operator=(const Option& rhs) {
    if (this == &rhs) return *this;
    copy(rhs);
    return *this;
}
//Destructor
Option::~Option() {
    // This will be empty because the compiler does the work of cleaning up the simple types for you
}
// Public access for the strike price: strike_price
double Option::getStrikePrice() const { return strike_price; }
double Option::getAssetPrice() const { return asset_price; }
//Quantitative Analysis Formulae (Derivatives Pricing Theory)
double Option::calc_call_price() const {
    double sigma_sqrt_mt = sigma * sqrt(mt);
    double d_1 = ( log(asset_price/strike_price) + (RFR + sigma * sigma * 0.5 ) * mt) / sigma_sqrt_mt;
    double d_2 = d_1 - sigma_sqrt_mt;
    return asset_price * erfc(d_1) - strike_price * exp(-RFR*mt) * erfc(d_2);
}
double Option::calc_put_price() const {
    double sigma_sqrt_mt = sigma * sqrt(mt);
    double d_1 = ( log(asset_price/strike_price) + (RFR + sigma * sigma * 0.5 ) * mt ) / sigma_sqrt_mt;
    double d_2 = d_1 - sigma_sqrt_mt;
    return strike_price * exp(RFR*mt) * erfc(-d_2) - asset_price * erf(-d_1);
}
void Option::info() {
     cout << "Underlying: " << endl;
    cout << "Strike Price: " << Option::getStrikePrice() << endl;
    cout << "Risk Free-Rate: " << RFR*100 << "%" << endl;
    cout << "Asset Price: " << Option::getAssetPrice() << endl;
    cout << "Volatility: " << sigma * 100 << "%" <<endl;
    cout << "Maturity: " << mt << endl;
    cout << "Calculated Call Price... : " << Option::calc_call_price() << endl;
    cout << "Calculated Put Price.... : " << Option::calc_put_price() << endl;
    
}
    

void week1main() {
    Option option = Option();
    option.getAssetPrice();
    option.getStrikePrice();
    option.getMT();
    option.getRFR();
    option.getSigma() ;
    option.calc_call_price();
    option.calc_put_price();
    option.info();
    
    
}

int main() {
    
    week1main();
    
    return 0;
}
