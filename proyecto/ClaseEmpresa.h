#include <iostream>
#include <vector>
using namespace std;
namespace ClaseEmpresa
{
    class Empresa
    {
    public:
        string idEmpresa;
        string codigoPlanillaEmpresa;
        int numeroPatronalEmpresa;
        string nombreEmpresa;

    public:
        Empresa(string idEmpresa, string codigoPlanillaEmpresa, int numeroPatronalEmpresa, string nombreEmpresa)
        {
            this->idEmpresa = idEmpresa;
            this->codigoPlanillaEmpresa = codigoPlanillaEmpresa;
            this->numeroPatronalEmpresa = numeroPatronalEmpresa;
            this->nombreEmpresa = nombreEmpresa;
        };
    };

    vector<Empresa> ListaEmpresas;

}