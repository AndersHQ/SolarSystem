#include "Headers.h"


//Virtual Print functions
int XBee::availableForWrite() {
    return port->availableForWrite();
}
void XBee::flush() {
    port->flush();
}
size_t XBee::write(uint8_t b) {
    return port->write(b);
}
size_t XBee::write(const uint8_t *buffer, size_t size) {
    return port->write(buffer, size);
}
//AT commands
bool XBee::enterATmode() {
    String response; 
    for (byte i = 0; response == "" && (i < 10); i++) {
        print("+++");
        delay(1000);
        response = readStringUntil('\r');
    } 
    return response.equals("OK");
}
bool XBee::exitATmode() {
    String response = atCommand("ATWR"); 
    atCommand("ATCN"); 
    return response.equals("OK");
}
String XBee::atCommand(String command) {
    print(command); 
    write('\r'); 
    return readStringUntil('\r'); 
}