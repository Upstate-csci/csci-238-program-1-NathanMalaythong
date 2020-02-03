/********
 Author: NATHAN MALAYTHONG
 Program: Money class - program assignment #1
 Due Date: FEB 3
 Purpose: DO LOGIC IN THE MONEY.CPP CLASS
 Turn in money.cpp and money.h in the github repository
 give him the github account ID (csci-238-program-1-NathanMalaythong)
 select grade version you want to test
 ********/
#include "money.h"
using namespace std;

//******--------should output "0 hundreds, 5 twentys, 7 tens, etc..."------********
// convert current currency values to a string
string Money::toString() {

    stringstream result;
   // result << total << endl;
    result << hundreds << "Hundreds: " << tens << "Tens: " << fives << "fives: " << ones << "Ones: " << "Quarters: " << quarters << "Dimes: " << dimes << "Nickels: " << nickels << "Cents: " << cents;
}

// format amount as a local currency and return
string Money::toCurrency(double amount) {
    stringstream ss;

    ss.imbue(locale(""));
   // ss << showbase <<put_money(amount*100);
    ss << "$" << left << setfill('0') << setw(4) << amount;
    return ss.str();
}

// convert currency to float
// read currency values from stdin and compute value
// return results
string Money::processChange() {
cin >> hundreds >> tens >> fives >> ones >> quarters >> dimes >> nickels >> cents;
    //add the total amount of money
    total = (hundreds * 100) + (tens * 10) + (fives * 5) + (ones * 1) + (quarters * 0.25) + (dimes * 0.10) + (nickels * 0.05) + (cents * .01);

    return to_string(hundreds) + " hundreds " + to_string(tens) + " tens " + to_string(fives) + " fives " + to_string(ones) + " ones " + to_string(quarters) + " quarters " + to_string(dimes) + " dimes " + to_string(nickels) + " nickels " + to_string(cents) + " cents = " +  toCurrency(total);
}


// read from stdin and process float command
// convert float to change
// return result
string Money::processFloat() {

    float input;
    cin >> input;
    int inputToInteger = (int) (input*100);

    std::ostringstream decimalPlaces;
    decimalPlaces << fixed << std::setprecision(2);
    decimalPlaces << input;
    std::string strObj = decimalPlaces.str();

    hundreds = inputToInteger / 10000;

    tens = (inputToInteger % 10000) / 1000;

    fives = ((inputToInteger % 10000) % 1000) / 500;

    ones = (((inputToInteger % 10000) % 1000) % 500) / 100;

    quarters = ((((inputToInteger % 10000) % 1000) % 500) % 100) / 25;

    dimes = (((((inputToInteger % 10000) % 1000) % 500) % 100) % 25) / 10;

    nickels = ((((((inputToInteger % 10000) % 1000) % 500) % 100) % 25) % 10) / 5;

    cents = (((((((inputToInteger % 10000) % 1000) % 500) % 100) % 25) % 10) % 5) ;





    return toCurrency(input) + " = " + to_string(hundreds) + " hundreds " + to_string(tens) + " tens "  + to_string(fives) + " fives " +  to_string(ones) + " ones " + to_string(quarters) + " quarters " + to_string(dimes) + " dimes " + to_string(nickels) + " nickels " + to_string(cents) + " cents. ";

}

// read from stdin and process check command
// convert float to dollar words & cents
// return results
string Money::processCheck() {

    double checkToBeChecked, fractional , integer;
    cin >> checkToBeChecked;

    fractional = modf(checkToBeChecked, &integer);

    printf("Check for $%g = %g dollars %g cents  ",checkToBeChecked, integer, fractional);







return "";

  //return "Check For " +  toCurrency(checkToBeChecked) + " = " + to_string(firstHalf) + " dollars " + to_string(lastHalf) + " cents " ;
}

// read from stdin and process change-float command
// read float of customer payment
// read float of transaction cost
// calculate difference and compute change values
// return the results
string Money::processChangeFloat() {
    double firstNumber, secondNumber, answer;
    cin >> firstNumber;
    cin >> secondNumber;

    answer = firstNumber - secondNumber;

    int answerToInteger = (int) (answer * 100);


    std::ostringstream decimalPlaces;
    decimalPlaces << fixed << std::setprecision(2);
    decimalPlaces << answer;
    std::string strObj = decimalPlaces.str();

    hundreds = answerToInteger / 10000;

    tens = (answerToInteger % 10000) / 1000;

    fives = ((answerToInteger % 10000) % 1000) / 500;

    ones = (((answerToInteger % 10000) % 1000) % 500) / 100;

    quarters = ((((answerToInteger % 10000) % 1000) % 500) % 100) / 25;

    dimes = (((((answerToInteger % 10000) % 1000) % 500) % 100) % 25) / 10;

    nickels = ((((((answerToInteger % 10000) % 1000) % 500) % 100) % 25) % 10) / 5;

    cents = (((((((answerToInteger % 10000) % 1000) % 500) % 100) % 25) % 10) % 5) ;




    return "Change back on $" + to_string(firstNumber) + " for purchase of " + toCurrency(secondNumber) + " is " +toCurrency(answer) + " which is " +
     " = " + to_string(hundreds) + " hundreds " + to_string(tens) + " tens "  + to_string(fives) + " fives " +  to_string(ones) + " ones " + to_string(quarters) + " quarters " + to_string(dimes) + " dimes " + to_string(nickels) + " nickels " + to_string(cents) + " cents. ";
}

// read from stdin and process change-change command
// read change of customer payment
// read float of transaction cost
// calculate difference and compute change values
// output the results
string Money::processChangeChange() {

    double theSecondInput, changeAnswer;
    cin >> hundreds >> tens >> fives >> ones >> quarters >> dimes >> nickels ;
    cin >> theSecondInput;
    //add the total amount of money
    total = (hundreds * 100) + (tens * 10) + (fives * 5) + (ones * 1) + (quarters * 0.25) + (dimes * 0.10) + (nickels * 0.05);



    changeAnswer = total - theSecondInput;

    double finalChangeAnswer = changeAnswer;
    int answerAnswerToInteger = (int) (changeAnswer * 100);

    int hundreds1, tens1, fives1, ones1, quarters1, dimes1, nickels1, cents1;

    std::ostringstream decimalPlaces;
    decimalPlaces << fixed << std::setprecision(2);
    decimalPlaces << answerAnswerToInteger;
    std::string strObj = decimalPlaces.str();

    hundreds1 = answerAnswerToInteger / 10000;

    tens1 = (answerAnswerToInteger % 10000) / 1000;

    fives1 = ((answerAnswerToInteger % 10000) % 1000) / 500;

    ones1 = (((answerAnswerToInteger % 10000) % 1000) % 500) / 100;

    quarters1 = ((((answerAnswerToInteger % 10000) % 1000) % 500) % 100) / 25;

    dimes1 = (((((answerAnswerToInteger % 10000) % 1000) % 500) % 100) % 25) / 10;

    nickels1 = ((((((answerAnswerToInteger % 10000) % 1000) % 500) % 100) % 25) % 10) / 5;

    cents1 = (((((((answerAnswerToInteger % 10000) % 1000) % 500) % 100) % 25) % 10) % 5) ;




    return  "The change back on " +  to_string(hundreds) + " hundreds " + to_string(tens) + " tens " + to_string(fives) + " fives " + to_string(ones) + " ones " + to_string(quarters) + " quarters " + to_string(dimes) + " dimes " + to_string(nickels) + " nickels" + " for purchase of " + toCurrency(theSecondInput)+ " is " + toCurrency(finalChangeAnswer) + " which is " +
            to_string(hundreds1) + " hundreds " + to_string(tens1) + " tens "  + to_string(fives1) + " fives " +  to_string(ones1) + " ones " + to_string(quarters1) + " quarters " + to_string(dimes1) + " dimes " + to_string(nickels1) + " nickels " + to_string(cents1) + " cents. ";
}
