#!/usr/bin/env python
#coding: utf-8

import socket
import sys

clientsocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)


port = 50000

clientsocket.bind('', port)
clientsocket.listen(5)


print('server demarre et ecoute sur le port ' + str(port))

while 1:
    (serveursocket, adress) = clientsocket.accept()
    print("nouvelle conexion a partir de : "+str(adress))
    print("envoi de commandes : ")
    while 1:
        r = str(sys.stdin.readline())

        serveursocket.send(r.encode()) 

        r = serveursocket.recv(9999)

        client_answer = str(r.decode("utf-8"), errors = "ignore"))
        
        print(str(client_answer)+"\n")




