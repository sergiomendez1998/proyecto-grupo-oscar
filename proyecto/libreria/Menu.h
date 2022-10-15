#include <iostream>
#include "FuncionGeneral.h"

using namespace std;
namespace Menu
{
    int opcion;
    string idEmpresa;
    string periodo;
    int numeroPatronal;
    string codigoPlanillaEmpresa;
    bool existeError = false;

    void analizarPlanillaNueva()
    {
        FuncionGeneral::verificarEmpleadoRepetidoEnPlanilla(ClasePlanillaEmpresa::listaTemporalPlanillaEmpresa);
        FuncionGeneral::verificarEstadoSuspendido(ClasePlanillaEmpresa::listaTemporalPlanillaEmpresa);
        FuncionGeneral::verificarEstadoNormal(ClasePlanillaEmpresa::listaTemporalPlanillaEmpresa);
        if (FuncionGeneral::existeEmpleadoRepetido == true)
        {
            existeError = true;
            cout << "Error!: existe un empleado repetido en la planilla" << endl;
        }
        else if (!FuncionGeneral::estaSinSueldo)
        {
            existeError = true;
            cout << "Error!: existe un empleado suspendido y tiene sueldo" << endl;
        }
        else if (FuncionGeneral::contadorEstadoNormal != FuncionGeneral::contadorEstadoAlta)
        {
            existeError = true;
            cout << "Error!: hay un estado normal que no se encontro en la planilla existente" << endl;
        }
    }
    void caseIngresarPorNumeroPatronal()
    {
        cout << "Ingrese el codigo de la planilla: ";
        cin >> codigoPlanillaEmpresa;
        FuncionGeneral::buscarEmpresaPorNumeroPlanilla(codigoPlanillaEmpresa);
        if (FuncionGeneral::existeEmpresa)
        {
            idEmpresa = ClasePlanillaEmpresa::listaTemporalPlanillaEmpresa[0].idEmpresa;
            periodo = ClasePlanillaEmpresa::listaTemporalPlanillaEmpresa[0].periodoEmpresa;
            FuncionGeneral::verificarPeriodoPlanilla(periodo, idEmpresa);
            if (FuncionGeneral::existePeriodoPlanilla)
            {
                cout << "El periodo de la planilla ya existe" << endl;
            }
            else
            {
                FuncionGeneral::verificarEstadoDeAlta(ClasePlanillaEmpresa::listaTemporalPlanillaEmpresa);
                FuncionGeneral::verificarEmpleadosNoExistentes(ClasePlanillaEmpresa::listaTemporalPlanillaEmpresa);
                FuncionGeneral::registrarPlanillaNuevas();
                FuncionGeneral::registrarEmpleadosNuevos();
                cout << "La planilla se registro correctamente" << endl;
            }
        }
        else
        {
            cout << "La empresa no existe" << endl;
            cout << "Desea registrar la empresa? (1.si/ 2.no): ";
            cin >> opcion;
            if (opcion == 1)
            {

                FuncionGeneral::registrarEmpresaNueva();
                cout << "Empresa Registrada " << endl;
            }
            else
            {
                cout << "La empresa no se registro" << endl;
            }
        }
    }
    void caseIngresarPorCodigoPlanillaEmpresa()
    {
        cout << "Ingrese el numero patronal: ";
        cin >> numeroPatronal;
        FuncionGeneral::buscarEmpresaPorNumeroPatronal(numeroPatronal);
        if (FuncionGeneral::existeEmpresa)
        {
            idEmpresa = ClasePlanillaEmpresa::listaTemporalPlanillaEmpresa[0].idEmpresa;
            periodo = ClasePlanillaEmpresa::listaTemporalPlanillaEmpresa[0].periodoEmpresa;
            FuncionGeneral::verificarPeriodoPlanilla(periodo, idEmpresa);
            if (FuncionGeneral::existePeriodoPlanilla)
            {
                cout << "El periodo de la planilla ya existe" << endl;
            }
            else
            {
                FuncionGeneral::verificarEstadoDeAlta(ClasePlanillaEmpresa::listaTemporalPlanillaEmpresa);
                FuncionGeneral::verificarEmpleadosNoExistentes(ClasePlanillaEmpresa::listaTemporalPlanillaEmpresa);
                FuncionGeneral::registrarPlanillaNuevas();
                FuncionGeneral::registrarEmpleadosNuevos();
                cout << "La planilla se registro correctamente" << endl;
            }
        }
        else
        {
            cout << "La empresa no existe" << endl;
            cout << "Desea registrar la empresa? (1.si/ 2.no): ";
            cin >> opcion;
            if (opcion == 1)
            {

                FuncionGeneral::registrarEmpresaNueva();
                cout << "Empresa Registrada " << endl;
            }
            else
            {
                cout << "La empresa no se registro" << endl;
            }
        }
    }
    void caseIngresarPorPeriodoEmpresa()
    {
        cout << " Ingrese el ID de la empresa que desea buscar: ";
        cin >> idEmpresa;
        FuncionGeneral::buscarEmpresaPorId(idEmpresa);
        if (FuncionGeneral::existeEmpresa)
        {
            cout << " Ingrese el periodo: ";
            cin >> periodo;
            FuncionGeneral::verificarPeriodoPlanilla(periodo, idEmpresa);
            if (FuncionGeneral::existePeriodoPlanilla)
            {
                cout << "El periodo de la planilla ya existe" << endl;
            }
            else
            {
                FuncionGeneral::verificarEstadoDeAlta(ClasePlanillaEmpresa::listaTemporalPlanillaEmpresa);
                FuncionGeneral::verificarEmpleadosNoExistentes(ClasePlanillaEmpresa::listaTemporalPlanillaEmpresa);
                FuncionGeneral::registrarPlanillaNuevas();
                FuncionGeneral::registrarEmpleadosNuevos();
                cout << "La planilla se registro correctamente" << endl;
            }
        }
        else
        {

            cout << "La empresa no existe" << endl;
            cout << "Desea registrar la empresa? (1.si/ 2.no): ";
            cin >> opcion;
            if (opcion == 1)
            {

                FuncionGeneral::registrarEmpresaNueva();
                cout << "Empresa Registrada " << endl;
            }
            else
            {
                cout << "La empresa no se registro" << endl;
            }
        }
    }
    void El_menu_para_la_carga_de_planillas()
    {

        cout << "------------------------- CARGADOR DE PLANILLA -------------------------" << endl;
        cout << " 1 -> Cargar planilla por Periodo" << endl;
        cout << " 2 -> Cargar planilla por No. de la planilla" << endl;
        cout << " 3 -> Cargar planilla por el numero patronal de la empresa" << endl;
        cout << " 0 -> Salir" << endl;
        cout << " -> ";
        cin >> opcion;
        switch (opcion)
        {
        case 0:
            opcion = 1;
            break;
        case 1:
            caseIngresarPorPeriodoEmpresa();
            break;
        case 2:
            caseIngresarPorCodigoPlanillaEmpresa();
            break;
        case 3:
            caseIngresarPorNumeroPatronal();
            break;
        }
    }
    void El_menu_para_la_creacion_de_reportes()
    {
        cout << "--------------------------- CREACION DE REPORTES ---------------------------" << endl;
        cout << " 1 -> Creacion de reportes de empleados con el sueldo minimo" << endl;
        cout << " 2 -> Creacion de reportes de empleados con el sueldo mayor al minimo" << endl;
        cout << " 3 -> Creacion de reportes de empleados suspendidos" << endl;
        cout << " 0 -> Salir" << endl;
        cout << " -> ";
        cin >> opcion;
        switch (opcion)
        {
        case 0:
            opcion = 1;
            break;
        case 1:
            FuncionGeneral::generarReporteSueldoMimino();
            cout << "reporte generado" << endl;
            break;
        case 2:
            FuncionGeneral::generarReporteSueldoMayorA3000();
            cout << "reporte generado" << endl;
            break;
        case 3:
            FuncionGeneral::generarReporteEmpleadosSuspendidos();
            cout << "reporte generado" << endl;
            break;
        }
    }
    void MenuInicio()
    {

        string nombreArchivo = "colgate2.csv";
        FuncionGeneral::cargarNuevosDatosCSV(nombreArchivo);
        FuncionGeneral::cargarEmpleadosExistentes();
        FuncionGeneral::cargarEmpresasExistentes();
        FuncionGeneral::cargarPlanillaEmpresaExistentes();
        analizarPlanillaNueva();
        if (!existeError)
        {
            do
            {
                cout << "--------------------------- PROYECTO PLANILLA ---------------------------" << endl;
                cout << " 1 -> Cargar Planilla" << endl;
                cout << " 2 -> Crear reporte" << endl;
                cout << " 0 -> Salir" << endl;
                cout << " -> ";
                cin >> opcion;
                switch (opcion)
                {
                case 0:
                    exit(0);
                    break;
                case 1:
                    El_menu_para_la_carga_de_planillas();
                    break;
                case 2:
                    El_menu_para_la_creacion_de_reportes();
                    break;
                }
            } while (opcion != 0);
        }
    }
}
