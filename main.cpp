#include <arpa/inet.h>
#include <sys/socket.h>
#include <cstddef>
#include <iostream>
#include <unistd.h>
int main(){
char * buffer[1024];
struct sockaddr_in addr;
int sock=socket(AF_INET, SOCK_STREAM, 0);
addr.sin_family=AF_INET;
addr.sin_port=htons(88);
addr.sin_addr.s_addr=htonl(INADDR_ANY);
bind(sock, (struct sockaddr *)&addr, sizeof(addr));
listen(sock, 3);
int incomm = accept(sock, NULL, NULL);
std::cout << read(incomm, buffer, sizeof(buffer))<<std::endl;
return 0;
}
