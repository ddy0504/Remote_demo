import socket

obj = socket.socket()
obj.connect(("127.0.0.1",5099))

ret = str(obj.recv(1024))
print(ret)
