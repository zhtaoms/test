obj=appr.o
target=app
CC=gcc

$(target):$(obj)
	$(CC) $(obj) -o $(target)

%.o:%.c
	$(CC) -c $< -o $@

