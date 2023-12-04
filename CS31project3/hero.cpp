#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
using namespace std;

bool hasProperSyntax(string tune)
{ for (int i=0; i != tune.size(); i++)
    { if (isalpha(tune.at(i)))
       { if (tune.at(i) != 'g' && tune.at(i) != 'G' && tune.at(i) != 'r' && tune.at(i) != 'R' && tune.at(i) != 'y' && tune.at(i) != 'Y' && tune.at(i) != 'b' && tune.at(i) != 'B' && tune.at(i) != 'o' && tune.at(i) != 'O')
       {return false;}
           i++;
           if (i == tune.size()) {return false;}
           if (isalpha(tune.at(i))) {return false;}
           
       }
     if (isdigit(tune.at(i)))
     { if ( i==0 || i == tune.size()-1) {return false;}
         i--;
         if (tune.at(i) == '/') {return false;}
         i +=2;
         if (isalpha(tune.at(i))) {return false;}
         
         if ( i != tune.size()-1 && isdigit(tune.at(i)))
             i++;
         {  if (isdigit(tune.at(i))) { return false;}
            
         }
         
     }
         }
    return true;
     }
        

int convertTune(string tune, string& instructions, int& badBeat)
{
    if (!hasProperSyntax(tune))
    {return 1;}
    
    if (hasProperSyntax(tune))
    {
        for (int i=0; i != tune.size(); i++)
        {  int number = 0;
            if (isdigit(tune.at(i)) && isdigit(tune.at(i+1)))
            {number += ((tune.at(i) - '0')*10 + (tune.at(i+1) - '0'));
                i +=2 ;
                
                int numOfSlash =0;
                for ( int j = i; j < i + number; j++)
                {
                    if (tune.at(j)== '/') {
                        numOfSlash++;}
                    else if (tune.at(j)!= '/')
                        return 3;                            //cases for returning back 3: some alpha existed after the                                         number instead of the '/'
                        
                    }
                    
                    if (numOfSlash < number) {return 4;}     // cases for returning back 4: the amount of slashes after the                                          number is smaller than the number.
           
                numOfSlash =0 ;
            if (isdigit(tune.at(i)))
           {number += ((tune.at(i)- '0'));}
                    i += 1;
                    for ( int k = i; k < i + number; k++)
                    { int numOfSlash =0;
                        if (tune.at(k)== '/') { numOfSlash++;}
                        else if (tune.at(k)!= '/')
                            return 3;
                        if (numOfSlash < number) {return 4;}
                            }
                      }
                 }
        for (int i=0; i != tune.size(); i++)
        {
            if(tune.at(i) == '0' || tune.at(i) == '1')
                return 2;}
        }
    
    return 0;                                                   //case when everything passes and conversion get executed.
}
    
   

  
    




int main()
    {
        string t;
        for (;;)
        {
            cout << "Enter tune: ";
        getline(cin, t);
        if (t == "quit")
            break;
        cout << "hasProperSyntax returns ";
        if (hasProperSyntax(t))
            cout << "true" << endl;
            else
            cout << "false" << endl;
        }
    }
