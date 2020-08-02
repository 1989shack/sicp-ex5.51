#ifndef IN_PORT_H
#define IN_PORT_H 1

#include <stdio.h>

struct in_port {
	int kind;
	char *name;
	FILE *file;
	char *text;
	char *next;
	int peeked;
	long read_count;

	int (*readc)(struct in_port *);
	int (*peek)(struct in_port *);
	int (*close)(struct in_port *);
};

struct in_port *openin_ptr(FILE *);
struct in_port *openin_file(char *);
struct in_port *openin_string(char *);

#endif