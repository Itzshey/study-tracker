#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <limits>

using namespace std;

class Estudos 
{
    public:
    string nomeDoAssunto;
    string tempoInicio;
    string tempoFim;
};

void menu() 
{
    cout << "[1] Nova sessão de estudos \n";
    cout << "[2] Visualizar estudos anteriores \n";
    cout << "[3] Sair do programa \n";
}

int main()
{
   menu();
   cout << "Insira sua opção: ";
   int x;
   cin >> x;

   if(cin.fail())
   {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
   }
    
   while (x != 3)
   {
        switch (x)
        {
        case 1:
            cout << "Teste opção 1 \n";
            break;

        case 2:
             cout << "Teste opção 2 \n";
            break;
        
        default:
             cout << "Teste input inválido \n";
            break;
        }

        menu();
        cout << "Insira sua opção: ";
        cin >> x;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
   }
   

}
