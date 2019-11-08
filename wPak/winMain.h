#pragma once

namespace wPak {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::IO::Compression;
	using namespace System::Drawing;

	typedef System::Void VOID;
	typedef System::String STRING;

	/// <summary>
	/// Sumário para winMain
	/// </summary>
	public ref class winMain : public System::Windows::Forms::Form
	{
	public:
		winMain(void)
		{
			InitializeComponent();
			//
			//TODO: Adicione o código do construtor aqui
			//
		}

	protected:
		/// <summary>
		/// Limpar os recursos que estão sendo usados.
		/// </summary>
		~winMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ listBox1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;

	private:
		/// <summary>
		/// Variável de designer necessária.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necessário para suporte ao Designer - não modifique 
		/// o conteúdo deste método com o editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(12, 12);
			this->listBox1->MultiColumn = true;
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(223, 225);
			this->listBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button1->AutoSize = true;
			this->button1->BackColor = System::Drawing::Color::LawnGreen;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(12, 240);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(67, 32);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Build";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &winMain::OnBuildButtonClicked);
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button2->AutoSize = true;
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Location = System::Drawing::Point(85, 240);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 32);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Select";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &winMain::OnSelectButtonClicked);
			// 
			// winMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(247, 284);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listBox1);
			this->Name = L"winMain";
			this->Text = L"winMain";
			this->ResumeLayout(false);
			this->PerformLayout();

			//
			// OpenFileDialog
			//
			//this->OpenDlg->Disposed += gcnew System::EventHandler(this, &winMain::UnRefOpDlg);

			//
			// SaveFileDialog
			//
			//this->SaveDlg->Disposed += gcnew System::EventHandler(this, &winMain::UnRefSvDlg);
		}
#pragma endregion
	private: VOID __clrcall OnSelectButtonClicked(System::Object^ sender, System::EventArgs^ e);
	private: VOID __clrcall OnBuildButtonClicked(System::Object^ sender, System::EventArgs^ e);
	private: VOID UnRefOpDlg();
	private: VOID UnRefSvDlg();
	public: 
		OpenFileDialog^ OpenDlg;
		SaveFileDialog^ SaveDlg;
		ZipArchive^ zip;
		ZipArchiveEntry^ zEntry;
	private: 
		STRING^ TGetResultSvDlg();
		STRING^ TGetResultOpDlg();
		bool OpenFileSystem();
		bool SaveFileSystem();
		bool InitDialog();
		int  AllItems();
		int AcceptTGetResult();
		void AllCancelOperation();
		bool CreateZipA(STRING^ pFilePath);
		bool ClosePak();
		VOID Destroy();

};

	
}
