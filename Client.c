#include<stdio.h>                                                                                                                                                       
#include<stdlib.h>                                                                                                                                                      
#include<string.h>                                                                                                                                                      
#include<netinet/in.h>                                                                                                                                                  
#include<sys/types.h>                                                                                                                                                   
#include<sys/socket.h>                                                                                                                                                  
int main(int argc,char **argv)                                                                                                                                          
{                                                                                                                                                                       
    int sockfd,n;                                                                                                                                                       
    struct sockaddr_in serv_addr;                                                                                                                                       
    sockfd=socket(AF_INET,SOCK_STREAM,0);                                                                                                                               
    serv_addr.sin_family=AF_INET;                                                                                                                                       
    serv_addr.sin_addr.s_addr=inet_addr("10.5.12.254");                                                                                                                 
    serv_addr.sin_port=htons(atoi(argv[1]));                                                                                                                            
    connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));                                                                                                     

    char buff[500];                                                                                                                                                     
                                                                                                                                                                        
    // strcpy(buff, "a.txt");                                                                                                                                           
    scanf("%s",buff);                                                                                                                                                   
    n=write(sockfd,buff,500);                                                                                                                                           
                                                                                                                                                                        
    n=read(sockfd,buff,500);                                                                                                                                            

    printf("%s",buff);                                                                                                                                                  
    return 0;                                                                                                                                                           
                                                                                                                                                                        
}