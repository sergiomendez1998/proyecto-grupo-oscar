#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "ClaseEmpleado.h"
#include "ClaseEmpresa.h"
#include "ClasePlanillaEmpresa.h"

using namespace std;
namespace FuncionGeneral
{
    bool existeEmpleadoAlta = false;
    bool estaSinSueldo = false;
    bool existeEmpleadoRepetido = false;
    bool existePeriodoPlanilla = false;
    bool existeEmpresa = false;
    int contadorEstadoAlta = 0;
    int contadorEstadoNormal = 0;

    void cargarEmpleadosExistentes()
    {
        ifstream archivoEmpleados;
        archivoEmpleados.open("./basededatos/EmpleadosRegistrados.csv");
        if (archivoEmpleados.fail())
        {
            cout << "No se pudo abrir el archivo" << endl;
            /// exit(1);
        }
        string linea = "";
        getline(archivoEmpleados, linea); // omite la cabecera del archivo
        linea = "";
        while (getline(archivoEmpleados, linea))
        {
            int idEmpleado;
            int dpiEmpleado;
            string nombreEmpleado;
            int salarioEmpleado;
            string valorTemporal;

            stringstream archivoEmpleados(linea);
            getline(archivoEmpleados, valorTemporal, ',');
            idEmpleado = stoi(valorTemporal);
            getline(archivoEmpleados, valorTemporal, ',');
            dpiEmpleado = stoi(valorTemporal);
            getline(archivoEmpleados, nombreEmpleado, ',');
            getline(archivoEmpleados, valorTemporal, ',');
            salarioEmpleado = stoi(valorTemporal);
            ClaseEmpleado::Empleado empleado(idEmpleado, dpiEmpleado, nombreEmpleado, salarioEmpleado);
            ClaseEmpleado::ListaEmpleados.push_back(empleado);
        }

        archivoEmpleados.close();
    }
    void cargarEmpresasExistentes()
    {
        ifstream archivoEmpresa;
        archivoEmpresa.open("./basededatos/EmpresasRegistradas.csv");
        if (archivoEmpresa.fail())
        {
            cout << "No se pudo abrir el archivo" << endl;
        }
        string linea = "";
        getline(archivoEmpresa, linea);
        linea = "";
        while (getline(archivoEmpresa, linea))
        {
            string idEmpresa;
            string codigoPlanillaEmpresa;
            int numeroPatronalEmpresa;
            string nombreEmpresa;
            string valortemporal;

            stringstream archivoEmpresa(linea);
            getline(archivoEmpresa, idEmpresa, ',');
            getline(archivoEmpresa, codigoPlanillaEmpresa, ',');
            getline(archivoEmpresa, valortemporal, ',');
            numeroPatronalEmpresa = stoi(valortemporal);
            getline(archivoEmpresa, nombreEmpresa, ',');
            getline(archivoEmpresa, valortemporal, ',');
            ClaseEmpresa::Empresa empresa(idEmpresa, codigoPlanillaEmpresa, numeroPatronalEmpresa, nombreEmpresa);
            ClaseEmpresa::ListaEmpresas.push_back(empresa);
        }
        archivoEmpresa.close();
    }
    void cargarPlanillaEmpresaExistentes()
    {
        ifstream archivoPlanilla;
        ///  archivoPlanilla.open("colgate.csv");
        archivoPlanilla.open("./basededatos/DatosPlanillaPorPeriodo.csv");
        if (archivoPlanilla.fail())
        {
            cout << "No se pudo abrir la planilla" << endl;
        }
        string linea = "";
        getline(archivoPlanilla, linea);
        linea = "";
        while (getline(archivoPlanilla, linea))
        {
            string idEmpresas;
            string codigoPlanillaEmpresa;
            int numeroPatronalEmpresa;
            string nombreEmpresa;
            string direccionEmpresa;
            string periodoEmpresa;
            int idEmpleado;
            int dpiEmpleado;
            string nombreEmpleado;
            string estado;
            string estadoSueldo;
            string estadoContrato;
            int salario;
            string valortemporal;

            stringstream archivoPlanilla(linea);
            getline(archivoPlanilla, idEmpresas, ',');
            getline(archivoPlanilla, codigoPlanillaEmpresa, ',');
            getline(archivoPlanilla, valortemporal, ',');
            numeroPatronalEmpresa = stoi(valortemporal);
            getline(archivoPlanilla, nombreEmpresa, ',');
            getline(archivoPlanilla, direccionEmpresa, ',');
            getline(archivoPlanilla, periodoEmpresa, ',');
            getline(archivoPlanilla, valortemporal, ',');
            idEmpleado = stoi(valortemporal);
            getline(archivoPlanilla, valortemporal, ',');
            dpiEmpleado = stoi(valortemporal);
            getline(archivoPlanilla, nombreEmpleado, ',');
            getline(archivoPlanilla, estado, ',');
            getline(archivoPlanilla, estadoSueldo, ',');
            getline(archivoPlanilla, estadoContrato, ',');
            getline(archivoPlanilla, valortemporal, ',');
            salario = stoi(valortemporal);
            getline(archivoPlanilla, valortemporal, ',');
            ClasePlanillaEmpresa::PlanillaEmpresa planilla(idEmpresas, codigoPlanillaEmpresa, numeroPatronalEmpresa, nombreEmpresa, direccionEmpresa, periodoEmpresa, idEmpleado, dpiEmpleado, nombreEmpleado, estado, estadoSueldo, estadoContrato, salario);
            ClasePlanillaEmpresa::ListaPlanillaEmpresa.push_back(planilla);
        }
        archivoPlanilla.close();
    }
    void cargarNuevosDatosCSV(string nombreArchivo)
    {
        ifstream datosCSV;
        datosCSV.open(nombreArchivo);
        if (datosCSV.fail())
        {
            cout << "No se pudo abrir el archivo" << endl;
            exit(1);
        }
        string linea = "";
        getline(datosCSV, linea); // omite la cabecera del archivo
        linea = "";
        while (getline(datosCSV, linea))
        {
            string idEmpresa;
            string codigoPlanillaEmpresa;
            int numeroPatronalEmpresa;
            string nombreEmpresa;
            string direccionEmpresa;
            string periodoEmpresa;
            //------ informacion del empleado
            int idEmpleado;
            int dpiEmpleado;
            string nombreEmpleado;
            string estado;
            string estadoSueldo;
            string estadoContrato;
            int salario;
            string valorTemporal;
            stringstream datosCSV(linea);

            getline(datosCSV, idEmpresa, ',');
            getline(datosCSV, codigoPlanillaEmpresa, ',');
            getline(datosCSV, valorTemporal, ',');
            numeroPatronalEmpresa = stoi(valorTemporal);
            getline(datosCSV, nombreEmpresa, ',');
            getline(datosCSV, direccionEmpresa, ',');
            getline(datosCSV, periodoEmpresa, ',');
            getline(datosCSV, valorTemporal, ',');
            idEmpleado = stoi(valorTemporal);
            getline(datosCSV, valorTemporal, ',');
            dpiEmpleado = stoi(valorTemporal);
            getline(datosCSV, nombreEmpleado, ',');
            getline(datosCSV, estado, ',');
            getline(datosCSV, estadoSueldo, ',');
            getline(datosCSV, estadoContrato, ',');
            getline(datosCSV, valorTemporal, ',');
            salario = stoi(valorTemporal);

            ClasePlanillaEmpresa::PlanillaEmpresa nuevoDatoPlanilla(
                idEmpresa,
                codigoPlanillaEmpresa,
                numeroPatronalEmpresa,
                nombreEmpresa,
                direccionEmpresa,
                periodoEmpresa,
                idEmpleado,
                dpiEmpleado,
                nombreEmpleado,
                estado,
                estadoSueldo,
                estadoContrato,
                salario);

            ClasePlanillaEmpresa::listaTemporalPlanillaEmpresa.push_back(nuevoDatoPlanilla);
        }
        datosCSV.close();
    }
    void buscarEmpresaPorId(string idEmpresa)
    {
        for (ClaseEmpresa::Empresa empresaRegistrada : ClaseEmpresa::ListaEmpresas)
        {
            if (empresaRegistrada.idEmpresa == idEmpresa)
            {
                existeEmpresa = true;
                cout << "Nombre Empresa: " + empresaRegistrada.nombreEmpresa << endl;
                break;
            }
            else
            {
                cout << "No existe la empresa" << endl;
                existeEmpresa = false;
            }
        }
    }
    void buscarEmpresaPorNumeroPlanilla(string numeroPlanilla)
    {
        for (ClaseEmpresa::Empresa empresaRegistrada : ClaseEmpresa::ListaEmpresas)
        {
            if (empresaRegistrada.codigoPlanillaEmpresa == numeroPlanilla)
            {
                existeEmpresa = true;
                cout << "Nombre Empresa: " + empresaRegistrada.nombreEmpresa << endl;
                break;
            }
            else
            {
                cout << "No existe la empresa" << endl;
                existeEmpresa = false;
            }
        }
    }
    void buscarEmpresaPorNumeroPatronal(int numeroPatronal)
    {
        for (ClaseEmpresa::Empresa empresaRegistrada : ClaseEmpresa::ListaEmpresas)
        {
            if (empresaRegistrada.numeroPatronalEmpresa == numeroPatronal)
            {
                existeEmpresa = true;
                cout << "Nombre Empresa: " + empresaRegistrada.nombreEmpresa << endl;
                break;
            }
            else
            {
                cout << "No existe la empresa" << endl;
                existeEmpresa = false;
            }
        }
    }
    void verificarEmpleadoRepetidoEnPlanilla(vector<ClasePlanillaEmpresa::PlanillaEmpresa> listaTemporal)
    {
        for (ClasePlanillaEmpresa::PlanillaEmpresa registroTemporal : listaTemporal)
        {

            for (ClasePlanillaEmpresa::PlanillaEmpresa registro : listaTemporal)
            {
                if (registro.idEmpleado == registroTemporal.idEmpleado &&
                    registroTemporal.salario != registroTemporal.salario && registroTemporal.estado != registroTemporal.estado)
                {
                    // indica que en la planilla hay un empleado con diferente estado y sueldo
                    existeEmpleadoRepetido = true;
                    break;
                }
                else
                {
                    // indica que no se repite el empleado en la planilla
                    existeEmpleadoRepetido = false;
                }
            }
        }
    }
    void verificarEstadoNormal(vector<ClasePlanillaEmpresa::PlanillaEmpresa> listaTemporal)
    {
        // itera los datos del la lista temporal
        for (ClasePlanillaEmpresa::PlanillaEmpresa datosTemporal : listaTemporal)
        {
            // verifica si hay un estado normal
            if (datosTemporal.estado == "Normal")
            {
                contadorEstadoNormal++;
                // verifica si el empleado ya existe en la lista de empleados
                for (ClasePlanillaEmpresa::PlanillaEmpresa datosRegistrados : ClasePlanillaEmpresa::ListaPlanillaEmpresa)
                {
                    // verifica si el empleado ya existe
                    if (datosTemporal.dpiEmpleado == datosRegistrados.dpiEmpleado && datosRegistrados.estado == "Alta")
                    {
                        // Indica que el empleado ya existe
                        contadorEstadoAlta++;
                        break;
                    }
                }
            }
        }
    }
    void verificarEstadoSuspendido(vector<ClasePlanillaEmpresa::PlanillaEmpresa> listaTemporal)
    {
        // itera los datos del la lista temporal
        for (ClasePlanillaEmpresa::PlanillaEmpresa datosTemporal : listaTemporal)
        {
            // verifica si hay un estado suspendido
            if (datosTemporal.estado == "Suspendido") // datosTemporal.estadoSueldo == "Sin sueldo" && datosTemporal.salario == 0)
            {
                if (datosTemporal.estadoSueldo == "Sin sueldo" && datosTemporal.salario == 0)
                {
                    estaSinSueldo = true;
                }
                else
                {
                    estaSinSueldo = false;
                    break;
                }
            }
        }
    }

    void verificarPeriodoPlanilla(string periodo, string idEmpresa)
    {
        // itera los datos del la lista temporal
        for (ClasePlanillaEmpresa::PlanillaEmpresa datosRegistrados : ClasePlanillaEmpresa::ListaPlanillaEmpresa)
        {
            // verifica si el periodo de la planilla ya existe
            if (datosRegistrados.periodoEmpresa == periodo && datosRegistrados.idEmpresa == idEmpresa)
            {
                // indica que el periodo de la planilla ya existe
                existePeriodoPlanilla = true;
                break;
            }
            else
            {
                // indica que el periodo de la planilla no existe
                existePeriodoPlanilla = false;
            }
        }
    }
    void buscarEmpleadoPorDPI(int dpi)
    {
        for (ClaseEmpleado::Empleado empleadoRegistrado : ClaseEmpleado::ListaEmpleados)
        {
            if (empleadoRegistrado.dpiEmpleado == dpi)
            {
                existeEmpleadoRepetido = true;
                break;
            }
        }
    }

    void verificarEstadoDeAlta(vector<ClasePlanillaEmpresa::PlanillaEmpresa> listaTemporal)
    {
        // itera los datos del la lista temporal
        for (ClasePlanillaEmpresa::PlanillaEmpresa datosTemporal : listaTemporal)
        {
            // verifica si hay un estado de alta
            if (datosTemporal.estado == "Alta")
            {
                // oscar
                //  verifica si el empleado ya existe en la lista de empleados
                for (ClasePlanillaEmpresa::PlanillaEmpresa datosRegistrados : ClasePlanillaEmpresa::ListaPlanillaEmpresa)
                {
                    // verifica si el empleado ya existe

                    if (datosTemporal.dpiEmpleado != datosRegistrados.dpiEmpleado)
                    {
                        // guarda los datos del empleado en la lista de empleados Temporal
                        // para luego guardarlos en el archivo de empleados

                        ClaseEmpleado::Empleado empleado(datosTemporal.idEmpleado, datosTemporal.dpiEmpleado, datosTemporal.nombreEmpleado, datosTemporal.salario);
                        buscarEmpleadoPorDPI(datosTemporal.dpiEmpleado);
                        if (existeEmpleadoRepetido == false)
                        {
                            cout << "empleado no existia con estado de alta" << endl;
                            cout << "Nombre: " + datosTemporal.nombreEmpleado + " registro Guardado!" << endl;
                            ClaseEmpleado::listaTemporalEmpleados.push_back(empleado);
                        }
                    }
                }
            }
        }
    }
    void verificarEmpleadosNoExistentes(vector<ClasePlanillaEmpresa::PlanillaEmpresa> listaTemporal)
    {
        for (ClasePlanillaEmpresa::PlanillaEmpresa datosTemporal : listaTemporal)
        {
            for (ClasePlanillaEmpresa::PlanillaEmpresa datosRegistrados : ClasePlanillaEmpresa::ListaPlanillaEmpresa)
            {
                if (datosTemporal.dpiEmpleado != datosRegistrados.dpiEmpleado &&
                    datosTemporal.estado != "Alta" && datosTemporal.nombreEmpresa != datosRegistrados.nombreEmpresa)
                {
                    ClaseEmpleado::Empleado empleado(datosTemporal.idEmpleado, datosTemporal.dpiEmpleado, datosTemporal.nombreEmpleado, datosTemporal.salario);
                    buscarEmpleadoPorDPI(datosTemporal.dpiEmpleado);
                    if (existeEmpleadoRepetido == false)
                    {
                        ClaseEmpleado::listaTemporalEmpleados.push_back(empleado);
                    }
                }
            }
        }
    }
    void registrarEmpresaNueva()
    {
        ofstream datosEmpresa;
        datosEmpresa.open("./basededatos/EmpresasRegistradas.csv", ios::app);
        datosEmpresa << ClasePlanillaEmpresa::listaTemporalPlanillaEmpresa[0].idEmpresa << ","
                     << ClasePlanillaEmpresa::listaTemporalPlanillaEmpresa[0].codigoPlanillaEmpresa << ","
                     << ClasePlanillaEmpresa::listaTemporalPlanillaEmpresa[0].numeroPatronalEmpresa << ","
                     << ClasePlanillaEmpresa::listaTemporalPlanillaEmpresa[0].nombreEmpresa
                     << endl;
        datosEmpresa.close();
        cargarEmpresasExistentes();
    }
    void registrarEmpleadosNuevos()
    {
        ofstream datosEmpleados;
        datosEmpleados.open("./basededatos/EmpleadosRegistrados.csv", ios::app);
        for (ClaseEmpleado::Empleado empleado : ClaseEmpleado::listaTemporalEmpleados)
        {
            datosEmpleados << empleado.idEmpleado << ","
                           << empleado.dpiEmpleado << ","
                           << empleado.nombreEmpleado << ","
                           << empleado.salarioEmpleado << ","
                           << endl;
        }
        datosEmpleados.close();
    }
    void registrarPlanillaNuevas()
    {
        ofstream datosPlanilla;
        datosPlanilla.open("./basededatos/DatosPlanillaPorPeriodo.csv", ios::app);
        for (ClasePlanillaEmpresa::PlanillaEmpresa planilla : ClasePlanillaEmpresa::listaTemporalPlanillaEmpresa)
        {
            datosPlanilla << planilla.idEmpresa
                          << "," << planilla.codigoPlanillaEmpresa
                          << "," << planilla.numeroPatronalEmpresa
                          << "," << planilla.nombreEmpresa
                          << "," << planilla.direccionEmpresa
                          << "," << planilla.periodoEmpresa
                          << "," << planilla.idEmpleado
                          << "," << planilla.dpiEmpleado
                          << "," << planilla.nombreEmpleado
                          << "," << planilla.estado
                          << "," << planilla.estadoSueldo
                          << "," << planilla.estadoContrato
                          << "," << planilla.salario
                          << endl;
        }
        datosPlanilla.close();
    }

    void evaluarEmpleadosDuplicadosSueldoMinimo(int dpi, int sueldo, string nombreEmpresa)
    {
        for (ClasePlanillaEmpresa::PlanillaEmpresa datosSueldoMimino : ClasePlanillaEmpresa::sueldosMinimos)
        {
            if (datosSueldoMimino.dpiEmpleado == dpi && datosSueldoMimino.salario == sueldo && datosSueldoMimino.nombreEmpresa == nombreEmpresa)
            {
                existeEmpleadoRepetido = true;
                break;
            }
            else
            {
                existeEmpleadoRepetido = false;
            }
        }
    }
    void evaluarEmpleadosDuplicadosSueldoM3000(int dpi, int sueldo, string nombreEmpresa)
    {
        for (ClasePlanillaEmpresa::PlanillaEmpresa datosSueldoM3000 : ClasePlanillaEmpresa::sueldosMayorA3000)
        {
            if (datosSueldoM3000.dpiEmpleado == dpi && datosSueldoM3000.salario == sueldo && datosSueldoM3000.nombreEmpresa == nombreEmpresa)
            {
                existeEmpleadoRepetido = true;
                break;
            }
            else
            {
                existeEmpleadoRepetido = false;
            }
        }
    }
    void filtrosueldomayoralminimo()
    {
        for (ClasePlanillaEmpresa::PlanillaEmpresa planilla : ClasePlanillaEmpresa::ListaPlanillaEmpresa)
        {
            if (planilla.salario != 0)
            {
                if (planilla.salario > 3000)
                {
                    evaluarEmpleadosDuplicadosSueldoM3000(planilla.dpiEmpleado, planilla.salario, planilla.nombreEmpresa);
                    if (!existeEmpleadoRepetido)
                    {
                        ClasePlanillaEmpresa::PlanillaEmpresa empleadoNuevo(planilla.idEmpleado, planilla.dpiEmpleado, planilla.nombreEmpleado, planilla.salario, planilla.nombreEmpresa);
                        ClasePlanillaEmpresa::sueldosMayorA3000.push_back(empleadoNuevo);
                    }
                }
            }
        }
    }
    void filtrarSueldosMinimos()
    {
        for (ClasePlanillaEmpresa::PlanillaEmpresa planilla : ClasePlanillaEmpresa::ListaPlanillaEmpresa)
        {
            if (planilla.salario != 0)
            {
                if (planilla.salario < 2900)
                {

                    evaluarEmpleadosDuplicadosSueldoMinimo(planilla.dpiEmpleado, planilla.salario, planilla.nombreEmpresa);
                    if (!existeEmpleadoRepetido)
                    {
                        ClasePlanillaEmpresa::PlanillaEmpresa empleadoNuevo(planilla.idEmpleado, planilla.dpiEmpleado, planilla.nombreEmpleado, planilla.salario, planilla.nombreEmpresa);
                        ClasePlanillaEmpresa::sueldosMinimos.push_back(empleadoNuevo);
                    }
                }
            }
        }
    }

    void filtrarEstadosSuspendidosDelPresenteMes()
    {

        for (ClasePlanillaEmpresa::PlanillaEmpresa planilla : ClasePlanillaEmpresa::ListaPlanillaEmpresa)
        {
            if (planilla.estado == "Suspendido" && planilla.periodoEmpresa == "09/01/2022-09/31/2022")
            {
                for (ClasePlanillaEmpresa::PlanillaEmpresa datosSuspendidos : ClasePlanillaEmpresa::empleadosSuspendidos)
                {
                    if (planilla.dpiEmpleado == datosSuspendidos.dpiEmpleado && planilla.nombreEmpresa == datosSuspendidos.nombreEmpresa)
                    {
                        existeEmpleadoRepetido = true;
                        break;
                    }
                    else
                    {
                        existeEmpleadoRepetido = false;
                    }
                }

                if (!existeEmpleadoRepetido)
                {
                    ClasePlanillaEmpresa::PlanillaEmpresa empleadoNuevo(planilla.idEmpleado, planilla.dpiEmpleado, planilla.nombreEmpleado, planilla.estado, planilla.nombreEmpresa);
                    ClasePlanillaEmpresa::empleadosSuspendidos.push_back(empleadoNuevo);
                }
            }
        }
    }
    void generarReporteSueldoMimino()
    {
        filtrarSueldosMinimos();
        ofstream reporteHtml;
        reporteHtml.open("./reportes/ReporteSueldoMinimo.html");
        reporteHtml << "<!DOCTYPE html>" << endl;
        reporteHtml << "<html lang='en'>" << endl;
        reporteHtml << "<head>" << endl;
        reporteHtml << "<title>Reporte</title>" << endl;
        reporteHtml << "</head>" << endl;
        reporteHtml << "<body>" << endl;
        reporteHtml << "<h1>Reporte de Sueldos minimos</h1>" << endl;
        reporteHtml << "<table border='1' width = '100%'>" << endl;
        reporteHtml << " <thead>" << endl;
        reporteHtml << "<tr>" << endl;
        reporteHtml << "<th> Id Empleado  </th>" << endl;
        reporteHtml << "<th> DPI Empleado </th>" << endl;
        reporteHtml << "<th> Nombre Empleado </th>" << endl;
        reporteHtml << "<th> Salario </th>" << endl;
        reporteHtml << "<th> Nombre Empresa </th>" << endl;
        reporteHtml << "</tr>" << endl;
        reporteHtml << "</thead>" << endl;
        reporteHtml << "<tbody>" << endl;
        for (ClasePlanillaEmpresa::PlanillaEmpresa planilla : ClasePlanillaEmpresa::sueldosMinimos)
        {
            reporteHtml << "<tr>" << endl;
            reporteHtml << "<td>" << planilla.idEmpleado << "</td>" << endl;
            reporteHtml << "<td>" << planilla.dpiEmpleado << "</td>" << endl;
            reporteHtml << "<td>" << planilla.nombreEmpleado << "</td>" << endl;
            reporteHtml << "<td>" << planilla.salario << "</td>" << endl;
            reporteHtml << "<td>" << planilla.nombreEmpresa << "</td>" << endl;
            reporteHtml << "</tr>" << endl;
        }
        reporteHtml << "</table>" << endl;
        reporteHtml << "</tbody>" << endl;
        reporteHtml << "</body>" << endl;
        reporteHtml << "</html>" << endl;
        reporteHtml.close();
    }
    void generarReporteSueldoMayorA3000()
    {
        filtrosueldomayoralminimo();
        ofstream reporteHtml;
        reporteHtml.open("./reportes/ReporteSueldoMayoralminimo.html");
        reporteHtml << "<!DOCTYPE html>" << endl;
        reporteHtml << "<html lang='en'>" << endl;
        reporteHtml << "<head>" << endl;
        reporteHtml << "<title>Reporte</title>" << endl;
        reporteHtml << "</head>" << endl;
        reporteHtml << "<body>" << endl;
        reporteHtml << "<h1>Reporte de Sueldos Mayores a al sueldo minimo</h1>" << endl;
        reporteHtml << "<table border='1' width = '100%'>" << endl;
        reporteHtml << " <thead>" << endl;
        reporteHtml << "<tr>" << endl;
        reporteHtml << "<th> Id Empleado  </th>" << endl;
        reporteHtml << "<th> DPI Empleado </th>" << endl;
        reporteHtml << "<th> Nombre Empleado </th>" << endl;
        reporteHtml << "<th> Salario </th>" << endl;
        reporteHtml << "<th> Nombre Empresa </th>" << endl;
        reporteHtml << "</tr>" << endl;
        reporteHtml << "</thead>" << endl;
        reporteHtml << "<tbody>" << endl;
        for (ClasePlanillaEmpresa::PlanillaEmpresa planilla : ClasePlanillaEmpresa::sueldosMayorA3000)
        {
            reporteHtml << "<tr>" << endl;
            reporteHtml << "<td>" << planilla.idEmpleado << "</td>" << endl;
            reporteHtml << "<td>" << planilla.dpiEmpleado << "</td>" << endl;
            reporteHtml << "<td>" << planilla.nombreEmpleado << "</td>" << endl;
            reporteHtml << "<td>" << planilla.salario << "</td>" << endl;
            reporteHtml << "<td>" << planilla.nombreEmpresa << "</td>" << endl;
            reporteHtml << "</tr>" << endl;
        }
        reporteHtml << "</table>" << endl;
        reporteHtml << "</tbody>" << endl;
        reporteHtml << "</body>" << endl;
        reporteHtml << "</html>" << endl;
        reporteHtml.close();
    }
    void generarReporteEmpleadosSuspendidos()
    {
        filtrarEstadosSuspendidosDelPresenteMes();
        ofstream reporteHtml;
        reporteHtml.open("./reportes/ReporteEmpleadosSuspendidos.html");
        reporteHtml << "<!DOCTYPE html>" << endl;
        reporteHtml << "<html lang='en'>" << endl;
        reporteHtml << "<head>" << endl;
        reporteHtml << "<title>Reporte</title>" << endl;
        reporteHtml << "</head>" << endl;
        reporteHtml << "<body>" << endl;
        reporteHtml << "<h1>Empleados Suspendidos</h1>" << endl;
        reporteHtml << "<table border='1' width = '100%'>" << endl;
        reporteHtml << " <thead>" << endl;
        reporteHtml << "<tr>" << endl;
        reporteHtml << " <th>Id Empleado</th>" << endl;
        reporteHtml << "<th> DPI Empleado </th>" << endl;
        reporteHtml << " <th> Nombre Empleado </th>" << endl;
        reporteHtml << "<th> Estado</th>" << endl;
        reporteHtml << "<th> Nombre Empresa</th>" << endl;
        reporteHtml << "</tr>" << endl;
        reporteHtml << "</ thead>" << endl;
        reporteHtml << "<tbody>" << endl;
        for (ClasePlanillaEmpresa::PlanillaEmpresa planilla : ClasePlanillaEmpresa::empleadosSuspendidos)
        {
            reporteHtml << "<tr>" << endl;
            reporteHtml << "<td>" << planilla.idEmpleado << "</td>" << endl;
            reporteHtml << "<td>" << planilla.dpiEmpleado << "</td>" << endl;
            reporteHtml << "<td>" << planilla.nombreEmpleado << "</td>" << endl;
            reporteHtml << "<td>" << planilla.estado << "</td>" << endl;
            reporteHtml << "<td>" << planilla.nombreEmpresa << "</td>" << endl;
            reporteHtml << "</tr>" << endl;
        }
        reporteHtml << "</trable>" << endl;
        reporteHtml << "</tbody>" << endl;
        reporteHtml << "</body>" << endl;
        reporteHtml << "</html>" << endl;
        reporteHtml.close();
    }
}
