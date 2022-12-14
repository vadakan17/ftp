#include<netinet/in.h>                                                                                                                                                  
#include<stdio.h>                                                                                                                                                       
#include<stdlib.h>                                                                                                                                                      
#include<sys/types.h>                                                                                                                                                   
#include<sys/socket.h>                                                                                                                                                  
#include <fcntl.h>                                                                                                                                                      
                                                                                                                                                                        
int main(int argc,char **argv){                                                                                                                                         
    int sockfd,newsockfd,cli_len;                                                                                                                                       
    struct sockaddr_in serv_addr,cli_addr;                                                                                                                              
                                                                                                                                                                        
    sockfd = socket(AF_INET,SOCK_STREAM,0);                                                                                                                             
    int port = atoi(argv[1]);                                                                                                                                           

    serv_addr.sin_family = AF_INET;                                                                                                                                     
    serv_addr.sin_addr.s_addr = INADDR_ANY;                                                                                                                             
    serv_addr.sin_port = htons(port);                                                                                                                                   
                                                                                                                                                                        
    if(bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0){                                                                                                 
        printf("Error Binding\n");                                                                                                                                      
    }                                                                                                                                                                   
                                                                                                                                                                        
    listen(sockfd,5);                                                                                                                                                   
                                                                                                                                                                        
    cli_len = sizeof(cli_addr);                                                                                                                                         
    newsockfd  = accept(sockfd,(struct sockaddr *)&cli_addr,&cli_len);                                                                                                  
                                                                                                                                                                        
    char buff[500];                                                                                                                                                     
    int n;                                                                                                                                                              
    n = read(newsockfd,buff,sizeof(buff));                                                                                                                              
    int fd = open(buff,O_RDONLY);                                                                                                                                       
    if(fd<0){                                                                                                                                                           
        printf("File not found\n");                                                                                                                                     
        write(newsockfd,"not found",sizeof("not found"));                                                                                                               
    }else{                                                                                                                                                              
        printf("File found\n");                                                                                                                                         
        read(fd,buff,sizeof(buff));                                                                                                                                     
        write(newsockfd,buff,sizeof(buff));                                                                                                                             
    }                                                                                                                                                                   
                                                                                                                                                                        
    return 0;                                                                                                                                                           
}