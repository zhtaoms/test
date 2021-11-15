all:appw appr
obj_w=appw.o appr.o
obj_r=appr.o
CC=gcc

$(all):$(obj)
	$(CC) $(obj) -o $(target)

%.o:%.c
	$(CC) -c $< -o $@

.PHONY:all clean
