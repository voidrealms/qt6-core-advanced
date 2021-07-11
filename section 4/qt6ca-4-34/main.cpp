/*
    What
    SSL Server

    Why
    We want to use the certificate

    How
    Server code

    Create a cert
    https://stackoverflow.com/questions/33198360/qt-with-qsslsocket-not-connecting-properly

    #Step 1: Generate a Private Key
    openssl genrsa -des3 -out server.key 1024

    #Step 2: Generate a CSR (Certificate Signing Request)
    #Common Name (eg, your name or your server's hostname) []:example.com
    openssl req -new -key server.key -out server.csr

    #Step 3: Remove Passphrase from Key
    cp server.key server.key.org
    openssl rsa -in server.key.org -out server.key

    #Step 4: Generating a Self-Signed Certificate
    openssl x509 -req -days 365 -in server.csr -signkey server.key -out server.crt


    Test the connection
    openssl s_client -connect 127.0.0.1:2020

    open a web browser and navigate to 127.0.0.1:2020

*/


#include <QCoreApplication>
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server server;
    server.setKey("/home/rootshell/Code/cert/server.key");
    server.setCert("/home/rootshell/Code/cert/server.crt");

    if(!server.listen(QHostAddress::Any, 2020))
    {
        qInfo() << server.errorString();
    }
    else
    {
        qInfo() << "Listening on " << server.serverAddress() << ":" << server.serverPort();
    }

    return a.exec();
}
