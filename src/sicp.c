#include <stdbool.h>
#include "version.h"
#include "strbldr.h"
#include "parser.h"
#include "error.h"

#include "eval.h"
#include "output.h"

static struct inport *parseargs(int argc, char *argv[]);
static struct inport *version(void);
static struct inport *expr(int argc, char *argv[]);
static struct inport *usage(void);

int main(int argc, char *argv[])
{
	// display should return unspec/error

	obj dat;
	struct inport *port = parseargs(argc, argv);
	if (port == NULL)
		return 0;
	while (!iserr(dat = readp(port)) && !Obj.iseof(dat)) {
		write((dat));
		newline();
	}
	return 0;
}

static struct inport *parseargs(int argc, char *argv[])
{
	char *s;
	bool haveoptions;

	if (argc <= 1)
		return openin_ptr(stdin);
	s = argv[1];
	haveoptions = (*s == '-' || *s == '/' || *s == '?');
	if (!haveoptions)
		return (argc == 2) ? openin_file(argv[1]) : usage();

	while (*s == '-' || *s == '/')
		s++;
	switch (*s) {
	case 'v':
	case 'V':
		return version();
	case 'e':
	case 'E':
		return expr(argc, argv);
	case 'h':
	case 'H':
	case '?':
	default:
		return usage();
	}
}

static struct inport *version(void)
{
	printf("sicp version %s\n", SICP_VERSION);
	return NULL;
}

static struct inport *expr(int argc, char *argv[])
{
	struct strbldr *sb;
	int i;

	if (argc <= 2)
		return NULL;
	if ((sb = new_strbldr()) == NULL)
		return NULL;
	for (i = 2; i < argc; i++) {
		if (i > 2)
			sb->addc(sb, ' ');
		sb->adds(sb, argv[i]);
	}
	return openin_string(sb->string(sb));
}

static struct inport *usage(void)
{
	printf("usage: [<path> | --expr <expression> | --version| --help]\n"
	       "  <path>                    evaluate contents of file <path>\n"
	       "  -e, --expr <expression>   evaluate expression <expression>\n"
	       "  -v, --version             display version information\n"
	       "  -h, --help                display this usage information\n"
	       "\n"
	       "If there are no arguments, will read and evaluate standard in.\n");
	return NULL;
}
