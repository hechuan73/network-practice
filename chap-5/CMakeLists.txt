add_executable(tcpclient tcp_client.c)
target_link_libraries(tcpclient yolanda)

add_executable(tcpserver tcp_server.c)
target_link_libraries(tcpserver yolanda)