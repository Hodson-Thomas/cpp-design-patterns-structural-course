//
// Created by thoma on 14/02/2025.
//
#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Storage {
public:
    virtual const string getContents() = 0;

    virtual ~Storage() = default;
};

class SecureStorage : public Storage {
public:
    explicit SecureStorage(const string &data) : m_Contents(data) {
    }

    const string getContents() {
        return m_Contents;
    }

private:
    const string m_Contents;
};

class ProtectiveProxy : private Storage {
public:
    ProtectiveProxy(const string &data, const int code) : code(code), storage(make_unique<SecureStorage>(data)) {
    }

    string getContent(const int code) const {
        if (code != this->code) {
            return "Unathorised!";
        }
        return storage->getContents();
    }

private:
    int code;
    unique_ptr<SecureStorage> storage;
};
