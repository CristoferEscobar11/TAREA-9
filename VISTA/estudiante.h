#pragma once
#include "Persona.h"
#include "conexiond.cpp"
#include <iostream>
#include <mysql.h>
#include <string>
#include "conexiond.cpp"

using namespace std;


// los dos puntos : quiere decir que hereda de la clase persona 
class estudiante : Persona{
	//atributos
private: string codigo;
	   int id_estudiante = 0;

	
	//constructor
public :
	estudiante (){}
	estudiante(string nom, string ape, string dir, int tel, string fn, int id_ts,string cod, int id_e) : Persona (nom,ape,dir,tel,fn,id_ts) {
		codigo = cod;
		id_estudiante = id_e;


	}
	//metodos get y set 
	// set (modificar un atributo)
	void setId_estudiante(int e) { id_estudiante = e; }
	void setcodigo(string c) { codigo  = c; }
	void setNombres(string n) { nombres = n; }
	void setApellidos(string a) { apellidos = a; }
	void setDireccion(string  d) { direccion = d; }
	void setIdTelefono(int t) {telefeno= t; }
	void setFecha_nacimiento( string  f) { fecha_nacimiento= f; }
	void setid_Tipo_Sangre(int ts) { id_tipo_sangre = ts; }
	// get (mostrar el contenido del atributo)
	int  getId_estudiante () {return id_estudiante; }
	string getNombres  () { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono    () { return telefeno; }
	string getFecha_nacimiento () { return fecha_nacimiento;}
	int getid_Tipo_Sangre () { return id_tipo_sangre;}
	
	//metodos
	void crear() {
		int q_estado = 0;
		conexiond cn = conexiond();
		cn.abrir_conexion();
		if (cn.getConector()); {
			string t = to_string(telefeno);
			string id_ts = to_string(id_tipo_sangre);
			string consulta = "INSERT INTO estudiantes(codigo,nombres,apellidos,direccion,telefono,fecha_nacimiento,id_tipo_sangre) VALUES ('" + codigo + "','" + nombres + "','" + apellidos + "','" + direccion + "'," + t + ",'" + fecha_nacimiento + "'," + id_ts + ")";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConector(), c);
			if (!q_estado) {
				cout << "Ingreso de Datos Exitoso..." <<endl;
			
		    }
			else {
				cout << "XXX Consulta Fallida xxx"<<endl;
			}
		
		}
		cn.cerrar_conexion();

	}
	void leer() {
			int q_estado = 0;
			conexiond cn = conexiond();
			MYSQL_ROW fila;
			MYSQL_RES* resultado;
			cn.abrir_conexion();
			if (cn.getConector()) {
				cout << "__________Datos del Estudiante______________" << endl;
				string consulta = "select * from estudiantes;";
				const char* c = consulta.c_str();
				q_estado = mysql_query(cn.getConector(), c);
				if (!q_estado) {
					resultado = mysql_store_result(cn.getConector());
					while (fila = mysql_fetch_row(resultado)) {
						cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << endl;
					}
					cn.cerrar_conexion();
					}
				}
				else {
					cout << "xxx fallo la conexion xx" << endl;

				}
			}
			void actualizar() {}
			void borrar() {
				int q_estado = 0;
					conexiond cn = conexiond();
					cn.abrir_conexion();
					if (cn.getConector()); {
						string t = to_string(telefeno);
						string id_ts = to_string(id_tipo_sangre);
						string consulta = "delete from estudiantes where id_estudiante = "+id_e+"";
						const char* c = consulta.c_str();
						q_estado = mysql_query(cn.getConector(), c);
						if (!q_estado) {
							cout << "Eliminacion de Datos Exitoso..." << endl;

						}
						else {
							cout << "XXX Consulta Fallida xxx" << endl;
						}

					}
					cn.cerrar_conexion();

				}
			};


		

		