#include <arpa/inet.h>
#include <sys/socket.h>
#include <cstddef>
#include <iostream>
#include <unistd.h>
#include <string>
#include <sstream>
int main(){
char buffer[1024];
struct sockaddr_in addr;
int sock=socket(AF_INET, SOCK_STREAM, 0);
addr.sin_family=AF_INET;
addr.sin_port=htons(88);
addr.sin_addr.s_addr=htonl(INADDR_ANY);
bind(sock, (struct sockaddr *)&addr, sizeof(addr));
listen(sock, 3);
int incomm = accept(sock, NULL, NULL);
int result= read(incomm, buffer, sizeof(buffer));
buffer[result]='\0';
std::stringstream response; // сюда будет записываться ответ клиенту
std::stringstream response_body; // тело ответа

    response_body << "<title>Test C++ HTTP Server</title>\n"
        << "<h1>Test page</h1>\n"
        << "<p>This is body of the test page...</p>\n"
        << "<h2>Request headers</h2>\n"
        << "<pre>" << buffer << "</pre>\n"
        << "<em><small>Test C++ Http Server</small></em>\n";

    // Формируем весь ответ вместе с заголовками
    response << "HTTP/1.1 200 OK\r\n"
        << "Version: HTTP/1.1\r\n"
        << "Content-Type: text/html; charset=utf-8\r\n"
        << "Content-Length: " << response_body.str().length()
        << "\r\n\r\n"
        << response_body.str();



send(incomm, response.str().c_str(),response.str().length(),0);
return 0;
}
