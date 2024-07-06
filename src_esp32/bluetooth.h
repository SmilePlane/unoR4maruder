#ifndef BLUETOOTH_H
class bt{
    public:
    void connect();
    bool write(const char* message);
    char print;
};
#endif