/*	TFG:	Base de conocimiento de un robot social: aprendiendo de Internet
			Grado en Ingeniería en Tecnologías Industriales
			Iván Isabel Redondo
			2022

	Tutor:	Daniel Galán Vicente
*/

#pragma once

#include "Botones_Documento.h"
#include "Funcion_Python.h"


extern string Base_Sel;
extern string Coleccion_Sel;
extern string documento_curiosidad;
extern string clave_curiosidad;
extern string confianza_info;


namespace BaseConocimiento {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class BuscarEnInternet : public System::Windows::Forms::Form
	{
	public:
		BuscarEnInternet(void)
		{
			InitializeComponent();
		}

	protected:
		~BuscarEnInternet()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:





	private: System::Windows::Forms::Button^ Boton_RealizarBusqueda;
	private: System::Windows::Forms::Label^ Label_PreguntaCompleta;

	private:
		System::ComponentModel::Container^ components;


#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->Boton_RealizarBusqueda = (gcnew System::Windows::Forms::Button());
			this->Label_PreguntaCompleta = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Boton_RealizarBusqueda
			// 
			this->Boton_RealizarBusqueda->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Boton_RealizarBusqueda->Location = System::Drawing::Point(23, 150);
			this->Boton_RealizarBusqueda->Name = L"Boton_RealizarBusqueda";
			this->Boton_RealizarBusqueda->Size = System::Drawing::Size(549, 47);
			this->Boton_RealizarBusqueda->TabIndex = 6;
			this->Boton_RealizarBusqueda->Text = L"Realizar Búsqueda en Internet";
			this->Boton_RealizarBusqueda->UseVisualStyleBackColor = true;
			this->Boton_RealizarBusqueda->Click += gcnew System::EventHandler(this, &BuscarEnInternet::Boton_RealizarBusqueda_Click);
			// 
			// Label_PreguntaCompleta
			// 
			this->Label_PreguntaCompleta->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Label_PreguntaCompleta->Location = System::Drawing::Point(19, 32);
			this->Label_PreguntaCompleta->Name = L"Label_PreguntaCompleta";
			this->Label_PreguntaCompleta->Size = System::Drawing::Size(543, 20);
			this->Label_PreguntaCompleta->TabIndex = 7;
			this->Label_PreguntaCompleta->Text = L"Pregunta";
			// 
			// Buscar en Internet
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 224);
			this->Controls->Add(this->Label_PreguntaCompleta);
			this->Controls->Add(this->Boton_RealizarBusqueda);
			this->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name = L"Internet";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"BUSCAR EN INTERNET";
			this->Load += gcnew System::EventHandler(this, &BuscarEnInternet::Internet_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void Internet_Load(System::Object^ sender, System::EventArgs^ e) {
		string datos = PreguntarCuriosidad();
		int pos = datos.find('#');
		string pregunta = datos.substr(0, pos);
		datos = datos.substr(pos + 1, strlen(datos.c_str()));
		pos = datos.find('#');
		clave_curiosidad = datos.substr(0, pos);
		datos = datos.substr(pos + 1, strlen(datos.c_str()));
		pos = datos.find('#');
		documento_curiosidad = datos.substr(0, pos);
		datos = datos.substr(pos + 1, strlen(datos.c_str()));
		pos = datos.find('#');
		Coleccion_Sel = datos.substr(0, pos);
		Base_Sel = datos.substr(pos + 1, strlen(datos.c_str()));

		if (strcmpi(datos.c_str(), "Todos los documentos están completos") == 0) {
			MessageBox::Show("Todos los documentos están completos");
			//this->TextBox_Respuesta->Visible = false;
			this->Boton_RealizarBusqueda->Visible = false;
			//this->Boton_NoTiene->Visible = false;

		}
		String^ Pregunta_Completa = gcnew String(pregunta.c_str());
		this->Label_PreguntaCompleta->Text = Pregunta_Completa;
	}


	private: System::Void Boton_RealizarBusqueda_Click(System::Object^ sender, System::EventArgs^ e) {
		string pregunta = toStandardString(this->Label_PreguntaCompleta->Text);
		string valor = Funcion_Python(documento_curiosidad, clave_curiosidad);
		String^ clave_str = gcnew String(clave_curiosidad.c_str());
		String^ valor_str = gcnew String(valor.c_str());
		String^ documento_str = gcnew String(documento_curiosidad.c_str());
		if (MessageBox::Show("El/la " + clave_str + " de " + documento_str + " es " + valor_str + ".\n¿Desea añadir esta información a la Base de Conocimiento?", "",
			MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			AñadirAtributoADocumento(documento_curiosidad, clave_curiosidad, valor, Base_Sel, Coleccion_Sel, confianza_info);
		}
		this->Visible = false;
	}
	};
}
