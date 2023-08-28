#include <sockets.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define SOCKET_BUFFER_SIZE  200u




short socketCreate(void)
{
    short hSocket;
    printf("Created the socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}


int bindCreatedSocket(int hSocket) 
{
    int iRetval=-1;
    int clientPort = 12345;

   struct sockaddr_in  remote= {0};

   /* Internet address family */
   remote.sin_family = AF_INET;

   /* Any incoming interface */
   remote.sin_addr.s_addr = htonl(INADDR_ANY);
   remote.sin_port = htons(clientPort); /* Local port */

   iRetval = bind(hSocket,(struct sockaddr *)&remote,sizeof(remote));
   return iRetval;
}

int socketConnect(int hSocket)
{
    int iRetval = -1;
    int clientPort = 12345;

    struct sockaddr_in remote = {0};

    remote.sin_family = AF_INET;
    remote.sin_addr.s_addr = inet_addr("127.0.0.1");
    remote.sin_port = htonl(clientPort);

    iRetval = connect(hSocket, (const struct sockaddr *)&remote, sizeof(remote));

    return iRetval;

}
// Send the data to the server and set the timeout of 20 seconds
int socketSend(int hSocket, char * rqst, short length)
{
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20;  /* 20 Secs Timeout */
    tv.tv_usec = 0;

    if(setsockopt(hSocket,SOL_SOCKET,SO_SNDTIMEO,(char *)&tv,sizeof(tv)) < 0) {
        printf("Time Out\n");
        return -1;
    }
    shortRetval = send(hSocket, rqst, length, 0);
    return shortRetval;

}

int run_server_socket(void)
{
   int socket_desc = 0, sock = 0, clientLen = 0;
   struct sockaddr_in client;
   char client_message[SOCKET_BUFFER_SIZE] = {0};
   char message[100] = {0};

   // Create socket
   socket_desc = socketCreate();

   if (socket_desc == -1)
   {
       printf("Could not create socket");
       return 1;
    }

    printf("Socket created\n");

    //Bind
    if( bindCreatedSocket(socket_desc) < 0) {
        //print the error message
        perror("bind failed.");
        return 1;
    }

    printf("bind done\n");

    //Listen

    while(1)
    {
        listen(socket_desc, 3);
        printf("Waiting for incoming connections...\n");
        clientLen = sizeof(struct sockaddr_in);

        // accept connection from an incoming client
        sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&clientLen);

        if (sock < 0)
        {
            perror("accept failed");
            return 1;
        }

        printf("Connection accepted\n");
        memset(client_message, '\0', sizeof client_message);
        memset(message, '\0', sizeof message);

        // Receive a reply from the client
        if (recv(sock, client_message, SOCKET_BUFFER_SIZE, 0) < 0)
        {
            printf("recv failed");
        }

        printf("Received from Client: %s\n", client_message);

        // int i = atoi(client_message);
        close(sock);


        if (strstr(client_message, "quit" ) != NULL)
        {
            break;
        }
    }

    close(socket_desc);
    shutdown(socket_desc, SHUT_RDWR);
    
}


int run_client_socket(void)
{
   int socket_desc = 0, sock = 0, clientLen = 0;
   struct sockaddr_in client;
   char client_message[SOCKET_BUFFER_SIZE] = {0};
   char message[100] = {0};

   // Create socket
   socket_desc = socketCreate();

   if (socket_desc == -1)
   {
       printf("Could not create socket");
       return 1;
    }

    printf("Socket created\n");

    //Bind
    if( bindCreatedSocket(socket_desc) < 0) {
        //print the error message
        perror("bind failed.");
        return 1;
    }

    printf("bind done\n");

    //Listen
    listen(socket_desc, 3);

    while(1)
    {
        printf("Waiting for incoming connections...\n");
        clientLen = sizeof(struct sockaddr_in);

        // accept connection from an incoming client
        sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&clientLen);

        if (sock < 0)
        {
            perror("accept failed");
            return 1;
        }

        printf("Connection accepted\n");
        memset(client_message, '\0', sizeof client_message);
        memset(message, '\0', sizeof message);

        // Receive a reply from the client
        if (recv(sock, client_message, SOCKET_BUFFER_SIZE, 0) < 0)
        {
            printf("recv failed");
        }

        printf("Received from Client: %s\n", client_message);

        // int i = atoi(client_message);
    }
}

