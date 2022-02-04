/*	TFG:	Base de conocimiento de un robot social: aprendiendo de Internet
			Grado en Ingeniería en Tecnologías Industriales
			Iván Isabel Redondo
			2022

	Tutor:	Daniel Galán Vicente
*/


#pragma once	//	Directiva para asegurar que el código fuente sea incluido una sola vez


//Inclusión de los ficheros de encabezamiento de los demás formularios para poder pasar de uno a otro en un click
#include "ListaBasesDeDatos.h"
#include "NuevaBaseDeDatos.h"
#include "EliminarBaseDeDatos.h"
#include "NuevaColeccion.h"
#include "EliminarColeccion.h"
#include "Consulta.h"
#include "NuevoDocumento.h"
#include "ModificarDocumento.h"
#include "EliminarDocumento.h"
#include "NuevaRelacion.h"
#include "Curiosidad.h"
#include "Multimedia.h"
#include "BuscarEnInternet.h"



namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class PanelDeInicio : public System::Windows::Forms::Form
	{
	public:
		PanelDeInicio(void)
		{
			InitializeComponent();
		}

	protected:
		~PanelDeInicio()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ MensajeBienvenida;
	private: System::Windows::Forms::Label^ PreguntaOperacion;











	private: System::Windows::Forms::GroupBox^ GroupBox_BD_C;
	private: System::Windows::Forms::Button^ BotonEliminarColeccion;
	private: System::Windows::Forms::Button^ BotonAñadirColeccion;
	private: System::Windows::Forms::Button^ BotonEliminarBase;
	private: System::Windows::Forms::Button^ BotonAñadirBase;
	private: System::Windows::Forms::Button^ BotonConsultarListaBases;
	private: System::Windows::Forms::GroupBox^ GroupBox_Documentos;

	private: System::Windows::Forms::Button^ Boton_EliminarTema;

	private: System::Windows::Forms::Button^ Boton_AñadirTema;
	private: System::Windows::Forms::Button^ Boton_ConsultarTema;


	private: System::Windows::Forms::Button^ Boton_EstablecerRelacion;
	private: System::Windows::Forms::Button^ Boton_ModificarTema;

	private: System::Windows::Forms::Button^ Boton_PreguntarCuriosidad;
	private: System::Windows::Forms::Button^ BotonSalir;
	private: System::Windows::Forms::Button^ Boton_Multimedia;
	private: System::Windows::Forms::Button^ BuscarEnInternet;



	private:
		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->MensajeBienvenida = (gcnew System::Windows::Forms::Label());
			this->PreguntaOperacion = (gcnew System::Windows::Forms::Label());
			this->GroupBox_BD_C = (gcnew System::Windows::Forms::GroupBox());
			this->BotonEliminarColeccion = (gcnew System::Windows::Forms::Button());
			this->BotonAñadirColeccion = (gcnew System::Windows::Forms::Button());
			this->BotonEliminarBase = (gcnew System::Windows::Forms::Button());
			this->BotonAñadirBase = (gcnew System::Windows::Forms::Button());
			this->BotonConsultarListaBases = (gcnew System::Windows::Forms::Button());
			this->GroupBox_Documentos = (gcnew System::Windows::Forms::GroupBox());
			this->Boton_EstablecerRelacion = (gcnew System::Windows::Forms::Button());
			this->Boton_ModificarTema = (gcnew System::Windows::Forms::Button());
			this->Boton_EliminarTema = (gcnew System::Windows::Forms::Button());
			this->Boton_AñadirTema = (gcnew System::Windows::Forms::Button());
			this->Boton_ConsultarTema = (gcnew System::Windows::Forms::Button());
			this->Boton_PreguntarCuriosidad = (gcnew System::Windows::Forms::Button());
			this->BotonSalir = (gcnew System::Windows::Forms::Button());
			this->Boton_Multimedia = (gcnew System::Windows::Forms::Button());
			this->BuscarEnInternet = (gcnew System::Windows::Forms::Button());
			this->GroupBox_BD_C->SuspendLayout();
			this->GroupBox_Documentos->SuspendLayout();
			this->SuspendLayout();
			// 
			// MensajeBienvenida
			// 
			this->MensajeBienvenida->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MensajeBienvenida->Location = System::Drawing::Point(175, 25);
			this->MensajeBienvenida->Name = L"MensajeBienvenida";
			this->MensajeBienvenida->Size = System::Drawing::Size(800, 40);
			this->MensajeBienvenida->TabIndex = 4;
			this->MensajeBienvenida->Text = L"Bienvenido a la base de conocimiento para robots sociales";
			this->MensajeBienvenida->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// PreguntaOperacion
			// 
			this->PreguntaOperacion->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 15.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PreguntaOperacion->Location = System::Drawing::Point(375, 80);
			this->PreguntaOperacion->Name = L"PreguntaOperacion";
			this->PreguntaOperacion->Size = System::Drawing::Size(400, 30);
			this->PreguntaOperacion->TabIndex = 5;
			this->PreguntaOperacion->Text = L"¿Qué operación desea llevar a cabo\?";
			this->PreguntaOperacion->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// GroupBox_BD_C
			// 
			this->GroupBox_BD_C->Controls->Add(this->BotonEliminarColeccion);
			this->GroupBox_BD_C->Controls->Add(this->BotonAñadirColeccion);
			this->GroupBox_BD_C->Controls->Add(this->BotonEliminarBase);
			this->GroupBox_BD_C->Controls->Add(this->BotonAñadirBase);
			this->GroupBox_BD_C->Controls->Add(this->BotonConsultarListaBases);
			this->GroupBox_BD_C->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GroupBox_BD_C->Location = System::Drawing::Point(23, 139);
			this->GroupBox_BD_C->Name = L"GroupBox_BD_C";
			this->GroupBox_BD_C->Size = System::Drawing::Size(533, 256);
			this->GroupBox_BD_C->TabIndex = 13;
			this->GroupBox_BD_C->TabStop = false;
			this->GroupBox_BD_C->Text = L"Bases de datos y colecciones";
			// 
			// BotonEliminarColeccion
			// 
			this->BotonEliminarColeccion->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->BotonEliminarColeccion->Location = System::Drawing::Point(298, 180);
			this->BotonEliminarColeccion->Name = L"BotonEliminarColeccion";
			this->BotonEliminarColeccion->Size = System::Drawing::Size(212, 50);
			this->BotonEliminarColeccion->TabIndex = 14;
			this->BotonEliminarColeccion->Text = L"Eliminar colección";
			this->BotonEliminarColeccion->UseVisualStyleBackColor = true;
			this->BotonEliminarColeccion->Click += gcnew System::EventHandler(this, &PanelDeInicio::BotonEliminarColeccion_Click);
			// 
			// BotonAñadirColeccion
			// 
			this->BotonAñadirColeccion->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotonAñadirColeccion->Location = System::Drawing::Point(23, 180);
			this->BotonAñadirColeccion->Name = L"BotonAñadirColeccion";
			this->BotonAñadirColeccion->Size = System::Drawing::Size(212, 47);
			this->BotonAñadirColeccion->TabIndex = 13;
			this->BotonAñadirColeccion->Text = L"Añadir colección";
			this->BotonAñadirColeccion->UseVisualStyleBackColor = true;
			this->BotonAñadirColeccion->Click += gcnew System::EventHandler(this, &PanelDeInicio::BotonAñadirColeccion_Click);
			// 
			// BotonEliminarBase
			// 
			this->BotonEliminarBase->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotonEliminarBase->Location = System::Drawing::Point(298, 111);
			this->BotonEliminarBase->Name = L"BotonEliminarBase";
			this->BotonEliminarBase->Size = System::Drawing::Size(212, 50);
			this->BotonEliminarBase->TabIndex = 12;
			this->BotonEliminarBase->Text = L"Eliminar base de datos";
			this->BotonEliminarBase->UseVisualStyleBackColor = true;
			this->BotonEliminarBase->Click += gcnew System::EventHandler(this, &PanelDeInicio::BotonEliminarBase_Click);
			// 
			// BotonAñadirBase
			// 
			this->BotonAñadirBase->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotonAñadirBase->Location = System::Drawing::Point(23, 111);
			this->BotonAñadirBase->Name = L"BotonAñadirBase";
			this->BotonAñadirBase->Size = System::Drawing::Size(212, 50);
			this->BotonAñadirBase->TabIndex = 11;
			this->BotonAñadirBase->Text = L"Añadir base de datos";
			this->BotonAñadirBase->UseVisualStyleBackColor = true;
			this->BotonAñadirBase->Click += gcnew System::EventHandler(this, &PanelDeInicio::BotonAñadirBase_Click);
			// 
			// BotonConsultarListaBases
			// 
			this->BotonConsultarListaBases->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->BotonConsultarListaBases->Location = System::Drawing::Point(23, 42);
			this->BotonConsultarListaBases->Name = L"BotonConsultarListaBases";
			this->BotonConsultarListaBases->Size = System::Drawing::Size(487, 50);
			this->BotonConsultarListaBases->TabIndex = 10;
			this->BotonConsultarListaBases->Text = L"Consultar lista de bases de datos y colecciones disponibles";
			this->BotonConsultarListaBases->UseVisualStyleBackColor = true;
			this->BotonConsultarListaBases->Click += gcnew System::EventHandler(this, &PanelDeInicio::BotonConsultarListaBases_Click);
			// 
			// GroupBox_Documentos
			// 
			this->GroupBox_Documentos->Controls->Add(this->Boton_EstablecerRelacion);
			this->GroupBox_Documentos->Controls->Add(this->Boton_ModificarTema);
			this->GroupBox_Documentos->Controls->Add(this->Boton_EliminarTema);
			this->GroupBox_Documentos->Controls->Add(this->Boton_AñadirTema);
			this->GroupBox_Documentos->Controls->Add(this->Boton_ConsultarTema);
			this->GroupBox_Documentos->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GroupBox_Documentos->Location = System::Drawing::Point(576, 139);
			this->GroupBox_Documentos->Name = L"GroupBox_Documentos";
			this->GroupBox_Documentos->Size = System::Drawing::Size(533, 256);
			this->GroupBox_Documentos->TabIndex = 15;
			this->GroupBox_Documentos->TabStop = false;
			this->GroupBox_Documentos->Text = L"Documentos";
			// 
			// Boton_EstablecerRelacion
			// 
			this->Boton_EstablecerRelacion->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Boton_EstablecerRelacion->Location = System::Drawing::Point(298, 180);
			this->Boton_EstablecerRelacion->Name = L"Boton_EstablecerRelacion";
			this->Boton_EstablecerRelacion->Size = System::Drawing::Size(212, 50);
			this->Boton_EstablecerRelacion->TabIndex = 19;
			this->Boton_EstablecerRelacion->Text = L"Establecer relación";
			this->Boton_EstablecerRelacion->UseVisualStyleBackColor = true;
			this->Boton_EstablecerRelacion->Click += gcnew System::EventHandler(this, &PanelDeInicio::Boton_EstablecerRelacion_Click);
			// 
			// Boton_ModificarTema
			// 
			this->Boton_ModificarTema->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Boton_ModificarTema->Location = System::Drawing::Point(23, 180);
			this->Boton_ModificarTema->Name = L"Boton_ModificarTema";
			this->Boton_ModificarTema->Size = System::Drawing::Size(212, 50);
			this->Boton_ModificarTema->TabIndex = 18;
			this->Boton_ModificarTema->Text = L"Modificar tema";
			this->Boton_ModificarTema->UseVisualStyleBackColor = true;
			this->Boton_ModificarTema->Click += gcnew System::EventHandler(this, &PanelDeInicio::Boton_ModificarTema_Click);
			// 
			// Boton_EliminarTema
			// 
			this->Boton_EliminarTema->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Boton_EliminarTema->Location = System::Drawing::Point(298, 111);
			this->Boton_EliminarTema->Name = L"Boton_EliminarTema";
			this->Boton_EliminarTema->Size = System::Drawing::Size(212, 50);
			this->Boton_EliminarTema->TabIndex = 16;
			this->Boton_EliminarTema->Text = L"Eliminar tema";
			this->Boton_EliminarTema->UseVisualStyleBackColor = true;
			this->Boton_EliminarTema->Click += gcnew System::EventHandler(this, &PanelDeInicio::Boton_EliminarTema_Click);
			// 
			// Boton_AñadirTema
			// 
			this->Boton_AñadirTema->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Boton_AñadirTema->Location = System::Drawing::Point(23, 111);
			this->Boton_AñadirTema->Name = L"Boton_AñadirTema";
			this->Boton_AñadirTema->Size = System::Drawing::Size(212, 50);
			this->Boton_AñadirTema->TabIndex = 14;
			this->Boton_AñadirTema->Text = L"Añadir tema";
			this->Boton_AñadirTema->UseVisualStyleBackColor = true;
			this->Boton_AñadirTema->Click += gcnew System::EventHandler(this, &PanelDeInicio::Boton_AñadirTema_Click);
			// 
			// Boton_ConsultarTema
			// 
			this->Boton_ConsultarTema->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Boton_ConsultarTema->Location = System::Drawing::Point(23, 42);
			this->Boton_ConsultarTema->Name = L"Boton_ConsultarTema";
			this->Boton_ConsultarTema->Size = System::Drawing::Size(487, 50);
			this->Boton_ConsultarTema->TabIndex = 13;
			this->Boton_ConsultarTema->Text = L"Consultar tema";
			this->Boton_ConsultarTema->UseVisualStyleBackColor = true;
			this->Boton_ConsultarTema->Click += gcnew System::EventHandler(this, &PanelDeInicio::Boton_ConsultarTema_Click);
			// 
			// Boton_PreguntarCuriosidad
			// 
			this->Boton_PreguntarCuriosidad->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Boton_PreguntarCuriosidad->Location = System::Drawing::Point(23, 475);
			this->Boton_PreguntarCuriosidad->Name = L"Boton_PreguntarCuriosidad";
			this->Boton_PreguntarCuriosidad->Size = System::Drawing::Size(533, 50);
			this->Boton_PreguntarCuriosidad->TabIndex = 20;
			this->Boton_PreguntarCuriosidad->Text = L"Preguntar curiosidad";
			this->Boton_PreguntarCuriosidad->UseVisualStyleBackColor = true;
			this->Boton_PreguntarCuriosidad->Click += gcnew System::EventHandler(this, &PanelDeInicio::Boton_PreguntarCuriosidad_Click);
			// 
			// BotonSalir
			// 
			this->BotonSalir->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->BotonSalir->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotonSalir->Location = System::Drawing::Point(23, 531);
			this->BotonSalir->Name = L"BotonSalir";
			this->BotonSalir->Size = System::Drawing::Size(1086, 50);
			this->BotonSalir->TabIndex = 21;
			this->BotonSalir->Text = L"No deseo llevar a cabo ninguna operación";
			this->BotonSalir->UseVisualStyleBackColor = true;
			this->BotonSalir->Click += gcnew System::EventHandler(this, &PanelDeInicio::BotonSalir_Click);
			// 
			// Boton_Multimedia
			// 
			this->Boton_Multimedia->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Boton_Multimedia->Location = System::Drawing::Point(576, 449);
			this->Boton_Multimedia->Name = L"Boton_Multimedia";
			this->Boton_Multimedia->Size = System::Drawing::Size(533, 50);
			this->Boton_Multimedia->TabIndex = 22;
			this->Boton_Multimedia->Text = L"Archivos multimedia";
			this->Boton_Multimedia->UseVisualStyleBackColor = true;
			this->Boton_Multimedia->Click += gcnew System::EventHandler(this, &PanelDeInicio::Boton_Multimedia_Click);
			// 
			// Boton_BuscarEnInternet
			// 
			this->BuscarEnInternet->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BuscarEnInternet->Location = System::Drawing::Point(23, 419);
			this->BuscarEnInternet->Name = L"BuscarEnInternet";
			this->BuscarEnInternet->Size = System::Drawing::Size(533, 50);
			this->BuscarEnInternet->TabIndex = 23;
			this->BuscarEnInternet->Text = L"Buscar en Internet\r\n";
			this->BuscarEnInternet->UseVisualStyleBackColor = true;
			this->BuscarEnInternet->Click += gcnew System::EventHandler(this, &PanelDeInicio::BuscarEnInternet_Click);
			// 
			// PanelDeInicio
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1155, 606);
			this->Controls->Add(this->BuscarEnInternet);
			this->Controls->Add(this->Boton_Multimedia);
			this->Controls->Add(this->BotonSalir);
			this->Controls->Add(this->Boton_PreguntarCuriosidad);
			this->Controls->Add(this->GroupBox_Documentos);
			this->Controls->Add(this->GroupBox_BD_C);
			this->Controls->Add(this->PreguntaOperacion);
			this->Controls->Add(this->MensajeBienvenida);
			this->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name = L"PanelDeInicio";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &PanelDeInicio::OperacionesBasicas_FormClosing);
			this->Load += gcnew System::EventHandler(this, &PanelDeInicio::PanelDeInicio_Load);
			this->GroupBox_BD_C->ResumeLayout(false);
			this->GroupBox_Documentos->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	

	//Botón Consultar lista de bases de datos y colecciones disponibles
		private: System::Void BotonConsultarListaBases_Click(System::Object^ sender, System::EventArgs^ e) {
			//	Sintaxis para pasar en un click de OperacionesBasicas a OperacionCreate
			BaseConocimiento::ListaBasesDeDatos^ ListaBasesDeDatos = gcnew BaseConocimiento::ListaBasesDeDatos();
			this->Visible = false;
			ListaBasesDeDatos->ShowDialog();
			this->Visible = true;
		}


	//Botón Añadir Base de Datos
		private: System::Void BotonAñadirBase_Click(System::Object^ sender, System::EventArgs^ e) {
			//	Sintaxis para pasar en un click de OperacionesBasicas a OperacionRead
			BaseConocimiento::NuevaBaseDeDatos^ NuevaBaseDeDatos = gcnew BaseConocimiento::NuevaBaseDeDatos();
			this->Visible = false;
			NuevaBaseDeDatos->ShowDialog();
			this->Visible = true;
		}


	//Botón Eliminar Base de Datos
		private: System::Void BotonEliminarBase_Click(System::Object^ sender, System::EventArgs^ e) {
			//	Sintaxis para pasar en un click de OperacionesBasicas a OperacionUpdate
			BaseConocimiento::EliminarBaseDeDatos^ EliminarBaseDeDatos = gcnew BaseConocimiento::EliminarBaseDeDatos();
			this->Visible = false;
			EliminarBaseDeDatos->ShowDialog();
			this->Visible = true;
		}


	//Botón Añadir Coleccion
		private: System::Void BotonAñadirColeccion_Click(System::Object^ sender, System::EventArgs^ e) {
			//	Sintaxis para pasar en un click de OperacionesBasicas a OperacionDelete
			BaseConocimiento::NuevaColeccion^ NuevaColeccion = gcnew BaseConocimiento::NuevaColeccion();
			this->Visible = false;
			NuevaColeccion->ShowDialog();
			this->Visible = true;
		}


	//Botón Eliminar Colección
		private: System::Void BotonEliminarColeccion_Click(System::Object^ sender, System::EventArgs^ e) {
			//	Sintaxis para pasar en un click de OperacionesBasicas a OperacionDelete
			BaseConocimiento::EliminarColeccion^ EliminarColeccion = gcnew BaseConocimiento::EliminarColeccion();
			this->Visible = false;
			EliminarColeccion->ShowDialog();
			this->Visible = true;
		}

			   
	//Botón Consultar Tema
		private: System::Void Boton_ConsultarTema_Click(System::Object^ sender, System::EventArgs^ e) {
			//	Sintaxis para pasar en un click de OperacionesBasicas a OperacionDelete
			BaseConocimiento::Consulta^ Consulta = gcnew BaseConocimiento::Consulta();
			this->Visible = false;
			Consulta->ShowDialog();
			this->Visible = true;
		}

			   
	//Botón Añadir Tema
		private: System::Void Boton_AñadirTema_Click(System::Object^ sender, System::EventArgs^ e) {
			//	Sintaxis para pasar en un click de OperacionesBasicas a OperacionDelete
			BaseConocimiento::NuevoDocumento^ NuevoDocumento = gcnew BaseConocimiento::NuevoDocumento();
			this->Visible = false;
			NuevoDocumento->ShowDialog();
			this->Visible = true;
		}


	//Botón Modificar Tema
		private: System::Void Boton_ModificarTema_Click(System::Object^ sender, System::EventArgs^ e) {
			//	Sintaxis para pasar en un click de OperacionesBasicas a OperacionDelete
			BaseConocimiento::ModificarDocumento^ ModificarDocumento = gcnew BaseConocimiento::ModificarDocumento();
			this->Visible = false;
			ModificarDocumento->ShowDialog();
			this->Visible = true;
		}
		
	
	//Botón Eliminar Tema
		private: System::Void Boton_EliminarTema_Click(System::Object^ sender, System::EventArgs^ e) {
			//	Sintaxis para pasar en un click de OperacionesBasicas a OperacionDelete
			BaseConocimiento::EliminarDocumento^ EliminarDocumento = gcnew BaseConocimiento::EliminarDocumento();
			this->Visible = false;
			EliminarDocumento->ShowDialog();
			this->Visible = true;
		}


	//Botón Establecer Relación
		private: System::Void Boton_EstablecerRelacion_Click(System::Object^ sender, System::EventArgs^ e) {
			//	Sintaxis para pasar en un click de OperacionesBasicas a OperacionDelete
			BaseConocimiento::NuevaRelacion^ NuevaRelacion = gcnew BaseConocimiento::NuevaRelacion();
			this->Visible = false;
			NuevaRelacion->ShowDialog();
			this->Visible = true;
		}


	//Botón Preguntar Curiosidad
		private: System::Void Boton_PreguntarCuriosidad_Click(System::Object^ sender, System::EventArgs^ e) {
			//	Sintaxis para pasar en un click de OperacionesBasicas a OperacionDelete
			BaseConocimiento::Curiosidad^ Curiosidad = gcnew BaseConocimiento::Curiosidad();
			this->Visible = false;
			Curiosidad->ShowDialog();
			this->Visible = true;
		}


	//Botón Multimedia
		private: System::Void Boton_Multimedia_Click(System::Object^ sender, System::EventArgs^ e) {
			//Sintaxis para pasar en un click de OperacionesBasicas a OperacionDelete
			BaseConocimiento::Multimedia^ Multimedia = gcnew BaseConocimiento::Multimedia();
			this->Visible = false;
			Multimedia->ShowDialog();
			this->Visible = true;
		}


	//Botón Salir
		private: System::Void BotonSalir_Click(System::Object^ sender, System::EventArgs^ e) {
			if (MessageBox::Show("¿Desea abandonar la base de conocimiento?", "Confirmación",
				MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
				//	Paramos el controlador MongoDB C y liberamos memoria
				mongoc_cleanup();
				//	Cerramos la aplicación
				Application::ExitThread();
			}
		}
	

	//Confirmación de salida cuando se produce el evento pulsar la x para cerrar el formulario
		private: System::Void OperacionesBasicas_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
			if (MessageBox::Show("¿Desea abandonar la base de conocimiento?", "Confirmación",
				MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
				//	Paramos el controlador MongoDB C y liberamos memoria
				mongoc_cleanup();
				//	Cerramos la aplicación
				Application::ExitThread();			
			}
			else e->Cancel = true;	//	Mantenemos abierta la aplicación
		}

	// Boton BuscarEnInternet
		private: System::Void BuscarEnInternet_Click(System::Object^ sender, System::EventArgs^ e) {
			BaseConocimiento::BuscarEnInternet^  BuscarEnInternet= gcnew BaseConocimiento::BuscarEnInternet();
			this->Visible = false;
			BuscarEnInternet->ShowDialog();
			this->Visible = true;
		}


private: System::Void PanelDeInicio_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
