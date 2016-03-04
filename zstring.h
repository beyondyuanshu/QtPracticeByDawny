#ifndef ZSTRING_H
#define ZSTRING_H

/// Test
//ZString str("Hello Qt!");
//ZString str2 = str;

#include <stdio.h>
#include <string.h>

class ZString {
public:
    ZString(const char *str = NULL);
    ZString(const ZString &another);
    ~ZString();

//    ZString & operater = (const String &rhs);

private:
    char *m_data;
};

ZString::ZString(const char *str) {
    if (NULL == str) {
        m_data = new char[1];
        m_data[0] = '\0';
    } else {
        m_data = new char[strlen(str) + 1];
        strcpy(m_data, str);
    }
}

ZString::ZString(const ZString &another) {
    m_data = new char[strlen(another.m_data) + 1];
    strcpy(m_data, another.m_data);
}

//ZString &ZString::operator = (const ZString &rhs) {
//    if (this == &rhs) {
//        return *this;
//    } else {
//        delete []m_data;
//        m_data = new char[strlen(rhs) + 1];
//        strcpy(m_data, rhs);
//        return *this;
//    }
//}

ZString::~ZString() {
    delete []m_data;
}

#endif // ZSTRING_H
