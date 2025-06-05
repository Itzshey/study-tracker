#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <limits>
#include "Estudos.hpp"
#include <fstream>
#include <filesystem>

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
    string caminhoArquivo;

    cout << "Digite o caminho completo do arquivo (ex: C:\\meus_estudos\\registro.txt):\n";
    cin.ignore();
    getline(cin, caminhoArquivo);

    filesystem::path caminhoPath(caminhoArquivo);
    filesystem::path diretorio = caminhoPath.parent_path();

    if (!filesystem::exists(diretorio)) {
        cout << "Erro: o diretório especificado não existe. Verifique o caminho.\n";
        return;
    }

    Estudos nvEstudo;
    cout << "Insira o nome do seu novo estudo: \n";
    string nome;
    cin.ignore();
    getline(cin, nome);
    nvEstudo.nomeEstudo = nome;

    time_t timestamp = time(nullptr);
    nvEstudo.inicioEstudo = ctime(&timestamp);

    cout << "Para encerrar sua sessão de estudos aperte qualquer tecla e depois aperte enter. \n";
    string fim;
    cin >> fim;

    time_t timestamp2 = time(nullptr);
    nvEstudo.fimEstudo = ctime(&timestamp2);
 
    fstream myFile;
    cout << "Salvando estudo... \n";

    myFile.open(caminhoArquivo, ios::app);

    if (myFile.is_open())
    {
        myFile << "\n Assunto: ";
        myFile << nvEstudo.nomeEstudo;
        myFile << "\n Início: ";
        myFile << nvEstudo.inicioEstudo;
        myFile << "Fim: ";
        myFile << nvEstudo.fimEstudo;
        myFile.close();
        cout << "Sessão de estudos salva em: " << caminhoArquivo << endl;
    }
    else
    {
        cout << "Erro ao abrir o arquivo. Verifique o caminho fornecido.\n";
    }

    cout << "Sessão de estudos finalizada! \n";
}
     

void estudosAnteriores()
{
    cout << "Digite o caminho completo do arquivo que deseja visualizar (ex: C:\\meus_estudos\\registro.txt):\n";
    cin.ignore();
    string caminhoArquivo;
    getline(cin, caminhoArquivo);
    fstream myFile;

    myFile.open(caminhoArquivo, ios::in);

    if (myFile.is_open())
    {
        string line;
        while (getline(myFile, line))
        {
            cout << line << endl;
        }
        
        myFile.close();
    }
    else
    {
         cout << "Não foi possível abrir o arquivo. Verifique se o caminho está correto.\n";
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
   return 0;
   
}
