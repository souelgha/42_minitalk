# Code a small data exchange program using UNIX signals
Create a communication program int the form of a client and a server
- client takes 2 parameters server PID and string to send. the client send the string to server
- server must print it.
- signals allowed : SIGUSR1 & SIGUSR2

## usage
run a make :
```bash
make
```
start server
```bash
./server
```
start client 
```bash
./client <server PID> <string to send>
```
