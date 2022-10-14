#include <iostream>
#include <vector>
using namespace std;
namespace ClaseEmpleado
{
    class Empleado
    {
    public:
        int idEmpleado;
        int dpiEmpleado;
        string nombreEmpleado;
        int salarioEmpleado;

    public:
        Empleado(int idEmpleado, int dpiEmpleado, string nombreEmpleado, int salarioEmpleado)
        {
            this->idEmpleado = idEmpleado;
            this->dpiEmpleado = dpiEmpleado;
            this->nombreEmpleado = nombreEmpleado;
            this->salarioEmpleado = salarioEmpleado;
        };
    };

    vector<Empleado> ListaEmpleados;
    vector<Empleado> listaTemporalEmpleados;
}