/*Problem: say we have a population of n llamas. Each year, n/3 llamas are born, and n/4 llamas pass away. 
Example: if we start with 12 llamas and we want to have  13 llamas we need 1 year, 14 llamas 2 years, 
17 llamas 4 years and so on. Be sure that the initial numer of llamas can't no ber less than 9, because
the llamas pupulation will quickly become stagnant 
*/
#include<iostream>
#include<string>
using namespace std;

int main(void){
    int n, nd;
    // ask for number of llamas (n)
    do
    {
        cout<<"Enter the current number of llamaSS: ";
        cin>>n;
    } while (n<=8);
    // ask for wished number of llamas (nd)
    do
    {
        cout<<"How many llamadas do you wanna have? : ";
        cin>>nd;
    } while(nd<n);

    // Adding number of llamas & counting years
    int ys=0;
    int count=0;
    do
    {
        for (count = 0; n <=nd; count ++){// Loop to add pupulation of llamas untill reach nd(numero deseado)
        n=n+(n/3)-(n/4);
        //cout<<n<<"\n";
        ys++; // counting years
        //cout<<ys<<"\n"
        cout<<"Year: "<<ys<<" ; # llamas "<<n<<"\n";
        }
         
    } while (n<nd);    
}
/*CS50 Haravard course. Author: Inti Toalombo Ecudador-Hungary*/