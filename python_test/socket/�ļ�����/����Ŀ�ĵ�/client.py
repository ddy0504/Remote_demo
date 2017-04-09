import socket
import os

obj = socket.socket()

obj.connect(("127.0.0.1",8080))

ret_bytes = obj.recv(1024)
ret_str = str(ret_bytes,encoding="utf-8")
print(ret_str)

size = os.stat("dce.png").st_size
print ("要发送文件大小：",size)
obj.sendall(bytes(str(size),encoding="utf-8"))

ret_bytes = obj.recv(1024)
ret_str = str(ret_bytes,encoding="utf-8")
print(ret_str)

with open("dce.png","rb") as f:
    for line in f:
        obj.sendall(line)
