#include <iostream>
#include <string>
#include <cctype>
#include<bitset>

std::string XOREncryptDecrypt(const std::string& text, const std::string& gamma)        // encryption and decryption function
{
    std::string result = text;
    for (int i = 0; i < text.length(); ++i)
    {
        result[i] = char((text[i] ^ gamma[i % gamma.length()]));                  // XOR

    }
    return result;
}
bool IsString(const std::string& text)                                          // is encrypting string correct
{
    bool result = true;
    for (char c : text) {
        if (std::isdigit(c) || std::isalpha(c) || std::ispunct(c) || c == ' ') {
            result *= 1;
        }
        else return false;
    }
    return result;
}
bool IsInt(std::string& key)                                                    // check is gamma string fully int
{
    auto it = key.begin();
    while (it != key.end() && isdigit(*it)) {
        it++;
    }
    return !key.empty() && it == key.end();
}
int main()
{

    std::string InputString = "";
    std::cout << "input string for encrypting >> ";
    getline(std::cin, InputString);
    while (!IsString(InputString)) {
        std::cin.clear();
        std::cout << "Wrong string, re-enter" << std::endl;
        getline(std::cin, InputString);
    }

    std::string Gamma = "";
    std::cout << "input gamma string >> ";
    getline(std::cin, Gamma);
    while (!IsInt(Gamma)) {
        std::cout << "Wrong gamma string, re-enter" << std::endl;
        getline(std::cin, Gamma);
    }

    std::string EncryptedString = XOREncryptDecrypt(InputString, Gamma);
    std::cout << "encrypted string: " << EncryptedString << std::endl;

    std::cout << "decrypt this encrypted string by program (choose 0) or decrypt your new string (choose 1)? >> ";
    short choose = 0;
    std::cin >> choose;
    if (choose == 0) {
        std::string DecryptedString = XOREncryptDecrypt(EncryptedString, Gamma);
        std::cout << std::endl << "decrypted string: " << DecryptedString;
        std::cout << std::endl;
    }
    else {
        std::cout << "input your string for decryption >> ";
        std::string StringForDecryption = "";
        getline(std::cin, StringForDecryption);
        std::cout << "input your gamma string >> ";
        std::string GammaUsr = "";
        getline(std::cin, GammaUsr);
        std::string DecryptedString = XOREncryptDecrypt(StringForDecryption, GammaUsr);
        std::cout << "your decrypted string: " << DecryptedString;
    }
}


