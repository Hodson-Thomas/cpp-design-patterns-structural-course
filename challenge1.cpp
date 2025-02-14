//
// Created by thoma on 14/02/2025.
//
#include <iostream>
#include <string>
#include <memory>
#include <cstdio>

using namespace std;

class CloudStorage {
public:
    virtual bool uploadContents(const string &content) = 0;

    virtual int getFreeSpace() = 0;

    virtual ~CloudStorage() = default;
};

class CloudDrive : public CloudStorage {
public:
    bool uploadContents(const string &content) override {
        cout << "Uploading " << content.length() << " bytes to CloudDrive: " << endl;

        return true;
    }

    int getFreeSpace() override {
        // Implement the logic for getting the free space on CloudDrive here.
        const int size = rand() % 20 + 1;
        cout << "Available CloudDrive storage: " << size << "GB" << endl;
        return size;
    }
};

class FastShare : public CloudStorage {
public:
    bool uploadContents(const string &content) override {
        cout << "Uploading " << content.length() << " bytes to FastShare: " << endl;
        return true;
    }

    int getFreeSpace() override {
        const int size = rand() % 10 + 1;
        cout << "Available FastShare storage: " << size << "GB" << endl;
        return size;
    }
};

// 3rd party service
class VirtualDrive {
public:
    bool uploadData(const string &data, const int uniqueID) {
        cout << "Uploading to VirtualDrive: \"" << data << "\" ID: " << uniqueID << endl;
        return true;
    }

    int usedSpace() {
        return rand() % 10 + 1;
    }

    const int totalSpace = 15;
};

class LegacyClassAdapter : public CloudStorage, private VirtualDrive {
public:
    bool uploadContents(const string &content) override {
        cout << "Uploading via LegacyClassAdapter: Calling VirtualDrive::uploadDat\n";
        return uploadData(content, rand() % 10 + 1);
    }

    int getFreeSpace() override {
        return totalSpace - usedSpace();
    }
};

// int main() {
//     // Create an array of pointers to CloudStorage objects.
//     const std::unique_ptr<CloudStorage> cloudServices[]
//     {
//         std::make_unique<CloudDrive>(),
//         std::make_unique<FastShare>(),
//         std::make_unique<LegacyClassAdapter>()
//     };
//
//     // Iterate through the array and invoke the uploadContents and getFreeSpace
//     // methods on each object.
//     const string content = "Beam me up, Scotty!";
//     for (const auto &service: cloudServices) {
//         service->uploadContents(content);
//         service->getFreeSpace();
//         cout << endl;
//     }
//
//     return 0;
// }
