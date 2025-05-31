#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <limits>
#include "Estudos.hpp"
#include <fstream>

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

void novoEstudo()
{
        Estudos nvEstudo;
        cout << "Insira o nome do seu novo estudo: \n";
        string nome;
        cin >> nome;
        nvEstudo.nomeEstudo = nome;

        time_t timestamp = time(nullptr);
        nvEstudo.inicioEstudo = ctime(&timestamp);

        cout << "Para encerrar sua sessão de estudos aperte qualquer tecla e depois aperte enter. \n" ;
        string n;
        cin >> n;

        time_t timestamp2 = time(nullptr);
        nvEstudo.fimEstudo = ctime(&timestamp2);
       
       cout << "Salvando estudo... \n";

       fstream myFile;
       myFile.open("study-tracker.txt", ios::app); // PARA ESCREVER!!

       if (myFile.is_open())
       {
            myFile << "\n Assunto: ";
            myFile << nvEstudo.nomeEstudo;
            myFile << "Início: ";
            myFile << nvEstudo.inicioEstudo;
            myFile << "Fim: \n";
            myFile << nvEstudo.fimEstudo;
            myFile.close();
       }
     
       cout << "Sessão de estudos finalizada! \n";

       
}

void estudosAnteriores()
{
    fstream myFile;
    myFile.open("study-tracker.txt", ios::in);

    if (myFile.is_open())
    {
        string line;
        while (getline(myFile, line))
        {
            cout << line << endl;
        }
        
        myFile.close();
    }
    
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
             novoEstudo();
            break;

        case 2:
             estudosAnteriores();
            break;
        
        default:
             cout << "Teste input inválido. Insira um número das opções. \n";
            break;
        }

    menu ();
    x = obterOpcao();

   }

   cout << "Salvando informações... \n";
   cout << "Até a próxima sessão de estudos!\n";
   
}
