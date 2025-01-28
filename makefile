CC = gcc
CFLAGS = -Wall -g
RM      = rm -f

default: all

all: Rod

#This always gives me the error "missing seperator" no matter what i do. Running rod_cut.c in vscode works so im gonna stop torturing myself for tonight and push this as is.
Rod: rod_cut.c
     $(CC) $(CFLAGS) -o Rod rod_cut.c