#define XBEE_BAUD 9600

class XBee : public Stream {
    //Connection used to communicate with XBee (eg. Serial1, SoftwareSerial, etc.)
    Stream* port;
  public:
    //Constructor and Destructor
    XBee(Stream* port):port(port) {}
    virtual ~XBee(){};
    //Virtual Stream functions
    int available() {return port->available();}
    int peek() {return port->peek();}
    int read() {return port->read();}
    
    //Virtual Print functions
    int availableForWrite();
    void flush();
    size_t write(uint8_t b);
    size_t write(const uint8_t *buffer, size_t size);
    //AT commands
    bool enterATmode();
    bool exitATmode();
    String atCommand(String command);
};
