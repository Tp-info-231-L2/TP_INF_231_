# le nom de l'éxécutable
TARGET = prog

# compilateur
GCC = gcc

# Options de compilations
CFLAGS = -Wall -g -Wextra -Wno-unused-variable

# Fichiers sources et objets
SRCS = main.c somme_matrice.c produit_matrice.c recherche_seq.c tablib.c
OBJS = $(patsubst %.c, %.o, $(SRCS))

# Règle principale
$(TARGET): $(OBJS)
	$(GCC) $(OBJS) -o $(TARGET)


# Règle pour les .o
%.o: %.c
	$(GCC) $(CFLAGS) -c $< -o $@

# Nétoyage
clean: 
	rm -f $(OBJS) $(TARGET)
