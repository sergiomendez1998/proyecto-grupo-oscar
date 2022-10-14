#include <iostream>
#include <vector>
using namespace std;

namespace ClasePlanillaEmpresa
{

    class PlanillaEmpresa
    {
    public:
        // -- infomacion de la empresa
        string idEmpresa;
        string codigoPlanillaEmpresa;
        int numeroPatronalEmpresa;
        string nombreEmpresa;
        string direccionEmpresa;
        string periodoEmpresa;
        // -- informacion del empleado
        int idEmpleado;
        int dpiEmpleado;
        string nombreEmpleado;
        string estado;
        string estadoSueldo;
        string estadoContrato;
        int salario;

    public:
        PlanillaEmpresa(string idEmpresa, string codigoPlanillaEmpresa, int numeroPatronalEmpresa, string nombreEmpresa, string direccionEmpresa, string periodoEmpresa, int idEmpleado, int dpiEmpleado, string nombreEmpleado, string estado, string estadoSueldo, string estadoContrato, int salario)
        {
            this->idEmpresa = idEmpresa;
            this->codigoPlanillaEmpresa = codigoPlanillaEmpresa;
            this->numeroPatronalEmpresa = numeroPatronalEmpresa;
            this->nombreEmpresa = nombreEmpresa;
            this->direccionEmpresa = direccionEmpresa;
            this->periodoEmpresa = periodoEmpresa;
            this->idEmpleado = idEmpleado;
            this->dpiEmpleado = dpiEmpleado;
            this->nombreEmpleado = nombreEmpleado;
            this->estado = estado;
            this->estadoSueldo = estadoSueldo;
            this->estadoContrato = estadoContrato;
            this->salario = salario;
        };

    public:
        PlanillaEmpresa(int idEmpleado, int dpiEmpleado, string nombreEmpleado, int salarioEmpleado, string nombreEmpresa)
        {
            this->idEmpleado = idEmpleado;
            this->dpiEmpleado = dpiEmpleado;
            this->nombreEmpleado = nombreEmpleado;
            this->salario = salarioEmpleado;
            this->nombreEmpresa = nombreEmpresa;
        };

    public:
        PlanillaEmpresa(int idEmpleado, int dpiEmpleado, string nombreEmpleado, string estado, string nombreEmpresa)
        {
            this->idEmpleado = idEmpleado;
            this->dpiEmpleado = dpiEmpleado;
            this->nombreEmpleado = nombreEmpleado;
            this->estado = estado;
            this->nombreEmpresa = nombreEmpresa;
        };
    };

    vector<PlanillaEmpresa> ListaPlanillaEmpresa;
    vector<PlanillaEmpresa> listaTemporalPlanillaEmpresa;
    vector<PlanillaEmpresa> sueldosMinimos;
    vector<PlanillaEmpresa> sueldosMayorA3000;
    vector<PlanillaEmpresa> empleadosSuspendidos;
}