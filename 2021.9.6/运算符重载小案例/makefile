obj=app.o
target=app
CC=g++

$(target):$(obj)
	$(CC) $(obj) -o $(target)

%.o:%.c
	$(CC) -c $< -o $@

