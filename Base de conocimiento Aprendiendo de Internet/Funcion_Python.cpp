/*	TFG:	Base de conocimiento de un robot social: aprendiendo de Internet
			Grado en Ingeniería en Tecnologías Industriales
			Iván Isabel Redondo
			2022

	Tutor:	Daniel Galán Vicente
*/

#include "pch.h"
#include "Funcion_Python.h"

string Funcion_Python(string nombre_busqueda, string dato_busqueda) {

	string pDato; // Dato obtenido al llamar a la funcion buscar_dato() de Python

	// Convertir tipo string a const char*
	const char* nombre = nombre_busqueda.c_str();
	const char* dato = dato_busqueda.c_str();

	// Conexion con Python
	Py_Initialize();

	//PyRun_SimpleString("import sys");
	//PyRun_SimpleString("sys.path.append(\".\")");
	PyObject* sysPath = PySys_GetObject("path");
	PyList_Append(sysPath, PyUnicode_FromString("C:/TFGv4/Base_Conocimiento_v5/BaseConocimiento")); // Ubicacion de los archivos py y cpp

	PyObject* pNombre, * pModulo, * pFuncion, * pArgumentos, * pValor; 

	pNombre = PyUnicode_FromString("BusquedaInternet");
	pModulo = PyImport_Import(pNombre);

	if (pModulo)
	{
		pFuncion = PyObject_GetAttrString(pModulo, "buscar_dato");
		if (pFuncion && PyCallable_Check(pFuncion))
		{
			pArgumentos = PyTuple_Pack(2, PyUnicode_FromString(nombre), PyUnicode_FromString(dato));
			pValor = PyObject_CallObject(pFuncion, pArgumentos);
			pDato = _PyUnicode_AsString(pValor);
		}
		else
		{
			pDato = "Null";
		}
	}
	else
	{
		pDato = "Null";
	}

	return pDato;
}