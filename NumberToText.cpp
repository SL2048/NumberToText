#include "NumberToText.h"

using namespace std;

NumberToText::NumberToText()
{
    places = new string[7];
    places[0] = " Hundred";
    places[1] = "";
    places[2] = " Thousand";
    places[3] = " Million";
    places[4] = " Billion";
    places[5] = " Trillion";
    places[6] = " Quadrillion";
}

NumberToText::~NumberToText()
{
    delete[] places;
}


string NumberToText::getDigit(char digit){
    string res = "";
    switch(digit){
        case '0':
            res = "Zero";
            break;
        case '1':
            res = "One";
            break;
        case '2':
            res = "Two";
            break;
        case '3':
            res = "Three";
            break;
        case '4':
            res = "Four";
            break;
        case '5':
            res = "Five";
            break;
        case '6':
            res = "Six";
            break;
        case '7':
            res = "Seven";
            break;
        case '8':
            res = "Eight";
            break;
        case '9':
            res = "Nine";
            break;
        default:
            break;
    }
    return res;
}

string NumberToText::getTeens(string tens){
    string res = "";
    if(tens == "10"){
        res = "Ten";
    }
    else if(tens == "11"){
        res = "Eleven";
    }
    else if(tens == "12"){
        res = "Twelve";
    }
    else if(tens == "13"){
        res = "Thirteen";
    }
    else if(tens == "14"){
        res = "Fourteen";
    }
    else if(tens == "15"){
        res = "Fifteen";
    }
    else if(tens == "16"){
        res = "Sixteen";
    }
    else if(tens == "17"){
        res = "Seventeen";
    }
    else if(tens == "18"){
        res = "Eighteen";
    }
    else if(tens == "19"){
        res = "Nineteen";
    }
    else{

    }
    return res;
}

string NumberToText::getTens(string tens){
    string res = "";
    if(tens[0] == two){
        res = "Twenty";
    }
    else if(tens[0] == three){
        res = "Thirty";
    }
    else if(tens[0] == four){
        res = "Forty";
    }
    else if(tens[0] == five){
        res = "Fifty";
    }
    else if(tens[0] == six){
        res = "Sixty";
    }
    else if(tens[0] == seven){
        res = "Seventy";
    }
    else if(tens[0] == eight){
        res = "Eighty";
    }
    else if(tens[0] == nine){
        res = "Ninety";
    }
    else{

    }
    if(tens[1] != zero){
        res = res + " " + getDigit(tens[1]);
    }

    return res;
}

string NumberToText::getHundreds(string num, string big){
    string res = "";
    string hundreds = num.substr(0,1);

    if(hundreds[0] != zero){
        res += getDigit(hundreds[0]);

        if(getDigit(hundreds[0]) == "One"){
            res += big;
        }

        else{
            res = res + big + "s";
        }
    }
    string tens = num.substr(1,2);
    if(tens[0] == zero){
        if(res == ""){
            if(tens[1] != zero){
                res += getDigit(tens[1]);
            }
        }
        else{
            if(tens[1] != zero){
                if(res != ""){
                    res = res + " And " + getDigit(tens[1]);
                }
                else{
                    res = getDigit(tens[1]);
                }
            }
        }
    }
    else if(tens[0] == one){
        if(res != ""){
            res = res + " And " + getTeens(tens);
        }
        else{
            res = getTeens(tens);
        }
    }
    else{
        if(res != ""){
            res = res + " And " + getTens(tens);
        }
        else{
            res = getTens(tens);
        }
    }
    return res;
}

void NumberToText::action(string number){
    while(number.size()%3 != 0){
        number = "0" + number;
    }
    int n = number.size() / 3;
    string res = "";
    int j = 0;
    for(int i = n ; i > 0 ; i--){
        string temp = number.substr(j*3,3);
        string added = getHundreds(temp,places[0]);
        res += added;
        if(added != ""){
            if(added != "One" && i != 1)
                res = res + places[i] + "s ";
            else
                res = res + places[i] + " ";
        }
        j++;
    }
    if(res == "")
        res = "Zero";
    cout << res << endl;
}
