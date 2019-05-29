#include <iostream>
#include <stdio.h> 
#include <string.h> 
#include <unordered_set>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;
unordered_set<string> foodSet,books, medicalProducts;
void Split(const string& subject, vector<string>& container)
{
    container.clear();
    size_t len = subject.length() + 1;
    char* s = new char[ len ];
    memset(s, 0, len*sizeof(char));
    memcpy(s, subject.c_str(), (len - 1)*sizeof(char));
    for (char *p = strtok(s, " "); p != NULL; p = strtok(NULL, " "))
    {
        container.push_back( p );
    }
    delete[] s;
}

int main() {
    //Insert all Food products present in the store
    foodSet.insert("chocolate");
    foodSet.insert("bar");
    foodSet.insert("chocolates");

    //Insert all books present in the store
    books.insert("book");

    //Insert all medicine products present in the store
    medicalProducts.insert("headache");
    medicalProducts.insert("pills");

    vector<string> inputStrings;
    // map<string, unordered_set<string>> map ;
    /**
    *
        Input using command line**
        to stop execution enter stop as string
    */
    // bool toContinue = true;
    // while(true) {
    //     string s;
    //     getline(cin,s);
    //     if(s=="stop" ){
    //         break;
    //     } else {
    //         // cout<<s<<endl;
    //         inputStrings.push_back(s);
    //     }
    // }
    
    /**
    *
        Using file input 
        replace the  file name to execute
        eg. of file data
            1 book at 12.49
            1 music CD at 14.99
            1 choclate bar at 0.85
    *
    */
        
    string line;
    ifstream myfile ("example.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
        inputStrings.push_back(line);
        }
        myfile.close();
    }
    

    float totalSalesTax =0.0;
    float totalPriceOfProduct = 0.0;
    for(int i=0;i<inputStrings.size();i++) {
        string s = inputStrings.at(i);
        vector<string> result;
        Split( s, result );
        int quantity = stoi(result.at(0));
        float price = stof(result.at(result.size()-1));
        float totalPrice = quantity*price;
        bool isFood =false;
        bool isMedicine = false;
        bool isBook = false;    
        bool isImported = false;   
        int saletaxPercent =0;
        for(int i=0;i<result.size();i++) {
            if (result.at(i)=="imported") {
                isImported = true;
            }
            else if(foodSet.find(result.at(i))!=foodSet.end()) {
                isFood=true;
            }
            else if(medicalProducts.find(result.at(i))!=medicalProducts.end()) {
                isMedicine = true;
            }
            else if(books.find(result.at(i))!=books.end()) {
                isBook = true;
            }
        }
        if(isBook || isMedicine ||isFood) {
            saletaxPercent = 0;
        } else{
            saletaxPercent = 10;
        }
        if(isImported) {
            saletaxPercent+=5;
        }
        if(saletaxPercent>0){
            float tax = (totalPrice*saletaxPercent)/100;
            float roundOfftax = (int)(tax * 100 + .5);
            float expectedTax = (int)roundOfftax%5;
            if(expectedTax>=3) {
                roundOfftax = roundOfftax+(5-expectedTax);
            } else {
                roundOfftax = roundOfftax-(expectedTax);
            }
            float netRoundOfftax = (float)roundOfftax/100;
            totalSalesTax += netRoundOfftax;
            totalPrice =  totalPrice+netRoundOfftax;
        }
        totalPriceOfProduct+=totalPrice;
        string sout = s.substr(0,s.find(" at "));
        cout<<sout<<": "<<totalPrice<<endl;
    }
    cout<<"Sales Taxes: "<<totalSalesTax<<endl;
    cout<<"Total: "<<totalPriceOfProduct<<endl; 
}