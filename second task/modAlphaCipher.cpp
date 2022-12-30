#include "modAlphaCipher.h"
string modAlphaCipher::decoder(const std::string& cipher_st)
{
    string n_s = cipher_st;
    int length, number_of_lines, position, a;
    length = cipher_st.size();
    number_of_lines = (length - 1) / newkey + 1;
    a = 0;
    for(int colum_number = newkey; colum_number > 0; colum_number--) {
        for(int line_number = 0; line_number < number_of_lines; line_number++) {
            position = newkey*line_number+colum_number;
            if(position-1 < length) {
                n_s[position-1] = cipher_st[a];
                a++;
            }
        }
    }
    return n_s;
}
string modAlphaCipher::coder(const string& open_st)
{
    string n_s = open_st;
    int length, number_of_lines, position, a;
    length = open_st.size();
    number_of_lines = (length - 1) / newkey + 1;
    a = 0;
    for(int colum_number = newkey; colum_number > 0; colum_number--) {
        for(int line_number = 0; line_number < number_of_lines; line_number++) {
            position = colum_number + newkey*line_number;
            if(position-1 < length) {
                n_s[a] = open_st[position-1];
                a++;
            }
        }
    }
    return n_s;
}