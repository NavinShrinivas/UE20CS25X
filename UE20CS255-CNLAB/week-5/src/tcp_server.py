from socket import * 


server_ip = "127.0.0.1"
server_port = 2000

sock = socket(AF_INET,SOCK_STREAM)
sock.bind((server_ip,server_port))
sock.listen(1)

print("Server ready to listen !!")

while True:
    connection_sock , address = sock.accept()
    msg = connection_sock.recv(1024)
    msg = msg.upper()
    connection_sock.send(msg)
    connection_sock.close()
