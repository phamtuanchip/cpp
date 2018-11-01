gcc -c server.c
gcc -c mongoose.c
gcc -c sqlite3.c
gcc -o server.out server.o mongoose.o sqlite3.o -ldl -lpthread -lmxml -L . 