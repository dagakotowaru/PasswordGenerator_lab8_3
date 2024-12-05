#include "MyForm.h"
#include <cstdlib>
#include <ctime>

using namespace PasswordGenerator;

[STAThreadAttribute]
int main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Application::Run(gcnew MyForm());

    return 0;
}

void GeneratePassword(int length, bool useDigits, bool useUppercase, System::Text::StringBuilder^% password)
{
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < length; ++i)
    {
        char ch = 0;

        if (useDigits && useUppercase)
        {
            int choice = rand() % 2;
            if (choice == 0)
            {
                ch = '0' + rand() % 10;
            }
            else
            {
                ch = 'A' + rand() % 26;
            }
        }
        else if (useDigits)
        {
            ch = '0' + rand() % 10;
        }
        else if (useUppercase)
        {
            ch = 'A' + rand() % 26;
        }

        password->Append(gcnew System::String(&ch));
    }
}

void MyForm::GenerateButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        int length = Convert::ToInt32(LengthTextBox->Text);

        if (length < 4 || length > 12)
        {
            PasswordLabel->Text = "Длина пароля должна быть от 4 до 12 символов.";
            return;
        }

        bool useDigits = false, useUppercase = false;
        System::String^ selectedOption = OptionsComboBox->SelectedItem->ToString();

        if (selectedOption == "Только цифры")
        {
            useDigits = true;
        }
        else if (selectedOption == "Только заглавные буквы")
        {
            useUppercase = true;
        }
        else if (selectedOption == "Цифры и заглавные буквы")
        {
            useDigits = true;
            useUppercase = true;
        }

        System::Text::StringBuilder^ password = gcnew System::Text::StringBuilder();
        GeneratePassword(length, useDigits, useUppercase, password);
        PasswordLabel->Text = "Сгенерированный пароль: " + password->ToString();
    }
    catch (System::FormatException^)
    {
        PasswordLabel->Text = "Пожалуйста, введите корректное число для длины пароля.";
    }
    catch (System::Exception^ ex)
    {
        PasswordLabel->Text = "Ошибка: " + ex->Message;
    }
}

void MyForm::CopyButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (PasswordLabel->Text != "Сгенерированный пароль будет здесь")
    {
        Clipboard::SetText(PasswordLabel->Text->Substring(23));
        MessageBox::Show("Пароль скопирован в буфер обмена!", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
    else
    {
        MessageBox::Show("Пожалуйста, сгенерируйте пароль перед копированием.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
