#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <limits>

using namespace std;


void menu() 
{
    cout << "[1] Nova sessão de estudos \n";
    cout << "[2] Visualizar estudos anteriores \n";
    cout << "[3] Sair do programa \n";
}

int obterOpcao()
{
    int x;
    cout << "Insira sua opção: ";
    cin >> x;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
    }

    return x;
}

int main()
{
   menu ();
   int x = obterOpcao();

   while (x != 3)
   {
        switch (x)
        {
        case 1:
             cout << "Teste opção 2 \n";
            break;

        case 2:
             cout << "Teste opção 2 \n";
            break;
        
        default:
             cout << "Teste input inválido \n";
            break;
        }

    menu ();
    x = obterOpcao();

   }

}
