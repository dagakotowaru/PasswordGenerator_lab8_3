#pragma once

namespace PasswordGenerator
{
    using namespace System;
    using namespace System::Windows::Forms;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::TextBox^ LengthTextBox;
        System::Windows::Forms::ComboBox^ OptionsComboBox;
        System::Windows::Forms::Button^ GenerateButton;
        System::Windows::Forms::Button^ CopyButton;
        System::Windows::Forms::Label^ PasswordLabel;

        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            this->LengthTextBox = (gcnew System::Windows::Forms::TextBox());
            this->OptionsComboBox = (gcnew System::Windows::Forms::ComboBox());
            this->GenerateButton = (gcnew System::Windows::Forms::Button());
            this->PasswordLabel = (gcnew System::Windows::Forms::Label());
            this->CopyButton = (gcnew System::Windows::Forms::Button());

            this->SuspendLayout();

            // LengthTextBox
            this->LengthTextBox->Location = System::Drawing::Point(160, 20);
            this->LengthTextBox->Name = L"LengthTextBox";
            this->LengthTextBox->Size = System::Drawing::Size(200, 22);
            this->LengthTextBox->TabIndex = 0;
            this->LengthTextBox->Text = L"4";

            // OptionsComboBox
            this->OptionsComboBox->FormattingEnabled = true;
            this->OptionsComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Только цифры", L"Только заглавные буквы", L"Цифры и заглавные буквы" });
            this->OptionsComboBox->Location = System::Drawing::Point(160, 60);
            this->OptionsComboBox->Name = L"OptionsComboBox";
            this->OptionsComboBox->Size = System::Drawing::Size(200, 24);
            this->OptionsComboBox->TabIndex = 1;

            // GenerateButton
            this->GenerateButton->Location = System::Drawing::Point(160, 100);
            this->GenerateButton->Name = L"GenerateButton";
            this->GenerateButton->Size = System::Drawing::Size(200, 30);
            this->GenerateButton->TabIndex = 2;
            this->GenerateButton->Text = L"Генерировать пароль";
            this->GenerateButton->UseVisualStyleBackColor = true;
            this->GenerateButton->Click += gcnew System::EventHandler(this, &MyForm::GenerateButton_Click);

            // PasswordLabel
            this->PasswordLabel->AutoSize = true;
            this->PasswordLabel->Location = System::Drawing::Point(160, 140);
            this->PasswordLabel->Name = L"PasswordLabel";
            this->PasswordLabel->Size = System::Drawing::Size(160, 17);
            this->PasswordLabel->TabIndex = 3;
            this->PasswordLabel->Text = L"Сгенерированный пароль будет здесь";

            // CopyButton
            this->CopyButton->Location = System::Drawing::Point(160, 180);
            this->CopyButton->Name = L"CopyButton";
            this->CopyButton->Size = System::Drawing::Size(200, 30);
            this->CopyButton->TabIndex = 4;
            this->CopyButton->Text = L"Копировать в буфер обмена";
            this->CopyButton->UseVisualStyleBackColor = true;
            this->CopyButton->Click += gcnew System::EventHandler(this, &MyForm::CopyButton_Click);

            // MyForm
            this->ClientSize = System::Drawing::Size(400, 250);
            this->Controls->Add(this->CopyButton);
            this->Controls->Add(this->PasswordLabel);
            this->Controls->Add(this->GenerateButton);
            this->Controls->Add(this->OptionsComboBox);
            this->Controls->Add(this->LengthTextBox);
            this->Name = L"MyForm";
            this->Text = L"Генератор пароля";
            this->ResumeLayout(false);
            this->PerformLayout();
        }

        void GenerateButton_Click(System::Object^ sender, System::EventArgs^ e);
        void CopyButton_Click(System::Object^ sender, System::EventArgs^ e);
    };
}
