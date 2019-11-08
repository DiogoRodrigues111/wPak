#include "winMain.h"
#include <Windows.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::IO::Compression;
using namespace System::Runtime::InteropServices;
using namespace System::Text;
using namespace wPak;

#ifndef CLRCALL
#define CLRCALL
#else
#define CLRCALL __clrcall
#endif

bool winMain::InitDialog()
{
	if(OpenDlg == nullptr)
		if (OpenDlg = gcnew OpenFileDialog())
			return true;
		else
			MessageBox::Show(
				L"Não foi possivel instanciar a classe Open Dialog",
				L"OpenDlg NULL",
				MessageBoxButtons::OK,
				MessageBoxIcon::Exclamation);

	if (SaveDlg == nullptr)
		if (SaveDlg = gcnew SaveFileDialog())
			return true;
		else
			MessageBox::Show(
				L"Não foi possivel instanciar a classe Save Dialog",
				L"SaveDlg NULL",
				MessageBoxButtons::OK,
				MessageBoxIcon::Exclamation);

	return true;
}

int winMain::AcceptTGetResult()
{
	auto hOpenResult = OpenDlg->ShowDialog();
	auto hSaveResult = SaveDlg->ShowDialog();

	if (InitDialog()) {
		if (hOpenResult == System::Windows::Forms::DialogResult::OK)
			auto idSrc = OpenDlg->FileName;

		if (hSaveResult == System::Windows::Forms::DialogResult::OK)
			auto idSrc = SaveDlg->FileName;
	}

	return 0;
}

void winMain::AllCancelOperation(void)
{
	auto hOpenResult = OpenDlg->ShowDialog();
	auto hSaveResult = SaveDlg->ShowDialog();

	if (InitDialog()) {
		if (hOpenResult == System::Windows::Forms::DialogResult::Cancel)
			return;

		if (hSaveResult == System::Windows::Forms::DialogResult::Cancel)
			return;
	}
}

int winMain::AllItems(void)
{
	int AllocMA = NULL;
	for (int j = 1; j < listBox1->Items->Count +1; j++)
	{
		AllocMA = j;
	}

	return AllocMA;
}

bool winMain::OpenFileSystem()
{
	if (InitDialog())
		auto hResult = OpenDlg->ShowDialog();
	else
		return false;

	return false;
}

STRING^ winMain::TGetResultOpDlg(void)
{
	if (InitDialog())
	{
		for each (STRING^ s in OpenDlg->FileNames)
		{
			listBox1->Items->Add(s);
		}
	}

	return nullptr;
}

bool winMain::SaveFileSystem()
{
	if (InitDialog())
	{
		auto hResult = SaveDlg->ShowDialog();
	}

	return false;
}

bool winMain::CreateZipA(_In_ STRING^ pFilePath)
{
	FileStream^ pFileStream = gcnew FileStream(
										pFilePath,
										FileMode::Create,
										FileAccess::Write);

	if (zip == nullptr) {
		for each (STRING ^ s in OpenDlg->FileNames)
		{
			pFilePath = s;
			zip = gcnew ZipArchive(pFileStream, ZipArchiveMode::Create, true);
			zip = ZipFile::Open(pFilePath, ZipArchiveMode::Update);
			zEntry = zip->CreateEntry(pFilePath, CompressionLevel::Fastest);
		}
	}
	else
		MessageBox::Show(
			L"O valor de ZIP não pode ser igual a NULL",
			L"WAR: ZIPEntryNewHinstance",
			MessageBoxButtons::OK,
			MessageBoxIcon::Warning);

	if (pFilePath == nullptr) {
		for each (STRING ^ s in OpenDlg->FileNames) {
			pFilePath = gcnew STRING(s);
		}
		return true;
	}

	if(AllItems() == 0)
		MessageBox::Show(
			L"Itens NULL",
			L"WAR: Itens",
			MessageBoxButtons::OK,
			MessageBoxIcon::Warning);

	if (AllItems() > 0) {
		MessageBox::Show(
			L"Packaged completado com sucesso",
			L"Sucesso",
			MessageBoxButtons::OK,
			MessageBoxIcon::Information);

		return true;
	}

	return false;
}

STRING^ winMain::TGetResultSvDlg(void)
{
	if (InitDialog())
	{
		for each (STRING ^ s in SaveDlg->FileNames)
		{
			if(s == nullptr)
				MessageBox::Show(
					L"Function NULL",
					L"Func_S_nullptr",
					MessageBoxButtons::OK,
					MessageBoxIcon::Information);
			else {
				auto r = dynamic_cast<STRING^>(s);
				CreateZipA(r);
			}
		}
	}

	return nullptr;
}

bool winMain::ClosePak()
{
	/* Não é necessario */
	return false;
}

VOID CLRCALL winMain::OnSelectButtonClicked(
											_In_ System::Object^ sender,
											_Out_ System::EventArgs^ e)
{
	OpenFileSystem();
	TGetResultOpDlg();
}
VOID CLRCALL winMain::OnBuildButtonClicked(
											_In_ System::Object^ sender,
											_Out_ System::EventArgs^ e)
{
	SaveFileSystem();
	TGetResultSvDlg();
	ClosePak();
}

VOID winMain::UnRefOpDlg( void )
{
	if (InitDialog())
		return;
	else {
		return;
	}
}
VOID winMain::UnRefSvDlg( void )
{ 
	if (InitDialog())
		return;
	else {
		return;
	}
}

void winMain::Destroy(void)
{ /* Sem necessidade */ }

[STAThreadAttribute]
int Main(_In_ array<STRING^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew winMain());

	return 0;
}