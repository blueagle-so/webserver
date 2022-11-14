#include <arpa/inet.h>
#include <sys/socket.h>
int main(){
struct sockaddr_in addr;
int sock=socket(AF_INET, SOCK_STREAM, 0);
addr.sin_family=AF_INET;






return 0;
}
