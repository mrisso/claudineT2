CC = gcc

CFLAGS = -Wall -g

LDFLAGS = -Wall

FONTES_ARVORE = indiceArv.c hash.c arvbb.c palavra.c

FONTES_HASH = indiceArv.c hash.c arvbb.c palavra.c

OBJETOS_ARVORE = $(FONTES_ARVORE:.c=.o)

OBJETOS_HASH = $(FONTES_HASH:.c=.o)

EXECUTAVEL_ARVORE = indiceArv

EXECUTAVEL_HASH = indiceHash

all:	$(EXECUTAVEL_ARVORE) $(EXECUTAVEL_HASH)

$(EXECUTAVEL_ARVORE):	$(OBJETOS_ARVORE)
	$(CC) -o $@ $^ $(LDFLAGS)

$(EXECUTAVEL_HASH):	$(OBJETOS_HASH)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $(CFLAGS) $^

clean:
	rm -rf *.o

rm:	clean
	rm -rf $(EXECUTAVEL_ARVORE) $(EXECUTAVEL_HASH)
