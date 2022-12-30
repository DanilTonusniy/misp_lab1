#include "modAlphaCipher.h"
bool isValid(const string& s)
{
    std::locale loc("ru_RU.UTF-8");
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;
    std::wstring ws = codec.from_bytes(s);
    std::string numAlpha = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    std::wstring wA = codec.from_bytes(numAlpha);
    for(unsigned int i = 0; i < ws.size(); i++) {
        if (wA.find(ws[i]) == string::npos) {
            return false;
        }
    }
    return true;
}
int main(int argc, char **argv)
{
    string key;
    string text;
    unsigned op;
    cout << "Введите ключ для шифрования: ";
    cin >> key;
    if(!isValid(key)) {
        cerr << "Ключ не подходит\n";
        return 1;
    }
    cout << "Ключ действителен\n";
    modAlphaCipher cipher(key);
    do {
        cout << "Шифр готов. Возможные для выполнения операции (0 - выход, 1 - шифрование, 2 - Расшифрование): ";
        cin >> op;
        if(op > 2) {
            cout << "Ошибка. Была выбрана неверная операция\n";
        } else if(op > 0) {
            cout << "Введите текст: ";
            cin >> text;
            if(isValid(text)) {
                if(op==1) {
                    cout << "Зашифрованный текст: "<<cipher.encrypt(text)<<endl;
                } else {
                    cout << "Расшифрованный текст: "<<cipher.decrypt(text)<<endl;
                }
            } else {
                cout << "Операция прервана, был введен некорректный текст\n";

            }
        }
    } while (op!=0);

    return 0;
}