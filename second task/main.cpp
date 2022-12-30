#include "modAlphaCipher.h"
bool isValid(const string& s)
{
    for(const auto &c:s)
        if(!isalpha(c))
            return false;
    return true;
}
int main(int argc, char **argv)
{
    int key;
    string st;
    unsigned operation;
    cout << "Введите ключ (число): ";
    cin >> key;
    if(!cin.good()) {
        clog << "Ключ не подходит\n";
        return 1;
    }
    cout << "Ключ действителен\n";
    modAlphaCipher cipher(key);
    do {
        cout << "Шифр готов, выберите операцию для выполнения (0 - выход, 1 - зашифровать, 2 - расшифровать): ";
        cin >> operation;
        if(operation > 2) {
            cout << "Ошибка, была выбрана неверная операция\n";
        } else if(operation > 0) {
            cout << "Введите строку, состоящую из латинских букв: ";
            cin >> st;
            if(isValid(st)) {
                if (operation == 1) {
                    cout << "Зашифрованный текст: " << cipher.coder(st) << endl;
                } else {
                    cout << "Расшифрованный текст: " << cipher.decoder(st) << endl;
                }
            } else {
                cout << "Операция прервана, был введен некорректный текст\n";
            }
        }
    } while (operation != 0);
    return 0;
}