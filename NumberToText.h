#ifndef NUMBERTOTEXT_H
#define NUMBERTOTEXT_H
#include <string>
#include <iostream>

using namespace std;

#define zero '0'
#define one '1'
#define two '2'
#define three '3'
#define four '4'
#define five '5'
#define six '6'
#define seven '7'
#define eight '8'
#define nine '9'



class NumberToText
{
    public:
        NumberToText();
        virtual ~NumberToText();
        void action(string);
    private:
        string* places;
        string getDigit(char);
        string getTeens(string);
        string getTens(string);
        string getHundreds(string,string);
};

#endif // NUMBERTOTEXT_H
