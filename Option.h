//
//  Option.h
//  Finance
//
//  Created by Nkechi Iregbulem on 3/1/19.
//  Copyright © 2019 Nkechi Iregbulem. All rights reserved.
//

#ifndef Option_h
#define Option_h

//const double = value cannot be modified once created
class Option {
private:
    void init();
    void copy (const Option& rhs);
double strike_price; // Strike Price
double RFR;  // Risk Free Rate
double mt; // Maturity Time
double asset_price; // Underlying Asset Price
double sigma; // Volatility of underlying asset

public:
Option(); // Default Constructor
Option(const double& _strike_price, const double& _RFM,
       const double&  _mt, const double& _asset_price,
       const double& _sigma);    // Parameter Constructor
Option(const Option& rhs); // Copy Constructor
Option& operator= (const Option& rhs); // Assignment
virtual ~Option(); // Destructor
// "getter" methods for our option parameters
double getStrikePrice() const;
double getRFR() const;
double getMT() const;
double getAssetPrice() const;
double getSigma() const;
//Option price calculation methods
double calc_call_price() const;
double calc_put_price() const;
void info();
};









#endif /* Option_h */
