#include <iostream>
#include <vector>
#include <string>
#include <ctime>

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
   string x;
   cin >> x;

   while (x != "3")
   {
        if(x == "1")
        {
            cout << "Teste opção 1 \n";

        } else if (x == "2")
        {
             cout << "Teste opção 2 \n";

        } else
        {
             cout << "Teste input inválido \n";
        }

        menu();
        cout << "Insira sua opção: ";
        cin >> x;
   }
   

}
