#include <stdio.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include <netinet/in.h> 

int main(int argc, char* argv[]){
    int MasterSocket = socket(
                AF_INET,
                SOCK_STREM,
                IPPROTO_TCP);
    struct sockaddr_in SockAddr;
    SockAddr.sin_family = AF_INET;    
    SockAddr.sin_port = htons(12345); 
    SockAddr.sin_adr.s_addr = htonl(INADDR_ANY);
    bind(MasterSocket, (struct sockaddr *)(&SockAddr), sizeof(SockAdrr));

    listen(MasterSocket, SOMAXCONN);
    return 0;
 }
