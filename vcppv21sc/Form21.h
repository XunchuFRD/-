#pragma once
#include <windows.h>
#include <MMSystem.h>
#include <vcclr.h>
#include <msclr/marshal_cppstd.h>
#pragma comment(lib, "Winmm.lib")
namespace test {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Reflection;
	using namespace System::Resources;
	using namespace msclr::interop;

	/// <summary>
	/// Form21 ժҪ
	/// </summary>
	public ref class Form21 : public System::Windows::Forms::Form
	{
	public:
		Form21(void)
		{
			InitializeComponent();
			//
			//TODO: �ڴ˴���ӹ��캯������
			//
		}

	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
		/// </summary>
		~Form21()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 

	private:
		/// <summary>
		/// ����������������
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����֧������ķ��� - ��Ҫ
		/// ʹ�ô���༭���޸Ĵ˷��������ݡ�
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form21::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"����", 14.9703F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button1->Location = System::Drawing::Point(425, 352);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(174, 80);
			this->button1->TabIndex = 0;
			this->button1->Text = L"����";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form21::button1_Click);
			// 
			// Form21
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(664, 485);
			this->Controls->Add(this->button1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form21";
			this->Text = L"ϲ��";
			this->Load += gcnew System::EventHandler(this, &Form21::Form21_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 mciSendString(L"close mp3", NULL, 0, NULL);
				 HWND hWnd = FindWindow(NULL, L"ϲ��");
				 PostMessage(hWnd, WM_CLOSE, 0, 0);
			 }
	private: System::Void Form21_Load(System::Object^  sender, System::EventArgs^  e) {
				  // ������Դ�ļ�
    ResourceManager^ rm = gcnew ResourceManager("test.Form21", Assembly::GetExecutingAssembly());

    // ����Դ�ļ��л�ȡ�����ļ����ֽ���
    array<Byte>^ musicBytes = safe_cast<array<Byte>^>(rm->GetObject("bj"));

    // �������ļ����ֽ���д����ʱ�ļ�
	System::String^ tempFilePath = System::Environment::GetEnvironmentVariable("temp") + "\\music2.mp3"; // ��ʱ�ļ�·��
	System::IO::File::WriteAllBytes(tempFilePath, musicBytes);

    // ʹ�� MCI �������ʱ�ļ�
    pin_ptr<const wchar_t> wch = PtrToStringChars(tempFilePath);
    LPCWSTR wstr = wch;
	std::wstring wideString = L"open \"" + std::wstring(wstr) + L"\" type mpegvideo alias mp3";
	LPCWSTR lpcwstr = wideString.c_str();
	mciSendString(lpcwstr, NULL, 0, NULL);
    mciSendString(L"play mp3", NULL, 0, NULL);

    // ��������
			 }
	};
}
