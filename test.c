#include <locale.h>
#include <stdio.h>
#include "taiga.h"

extern char **environ;

void
print_env(void)
{
	int i = 0;
	char *env = environ[0];

	printf("<pre>\n");
	while (env != NULL) {
		printf("    %s\n", env);
		env = environ[++i];
	}
	printf("</pre>\n");
}

int
main(int argc, char **argv)
{
	char buf[4096];
	size_t in;
	tg_response *response;
	tg_request *request;
	wchar_t body[] = L"<html><body>Woot</body></html>\n";

	setlocale(LC_ALL, "");

	request = tg_request_new_from_env();
	response = tg_response_new_html();

	tg_response_set_content(response, body, wcslen(body));
	tg_response_print(response);

	/* uploaded files and forms ... tbd */
	in = fread(buf, 1, 4096, stdin);

	print_env();

	printf("test (%d): %s\n", in, buf);

	return 0;
}

/*
 * each controller is its own binary, with its own set of functions. each function
 * takes a request and returns a response.
 *
 * -> does not work, how would we hook these up to a fast cgi server.
 *
 * just like a python module, we create a structure/array with all the action
 * definitions, their function pointer, names and parameters. Parameters are defined
 * as an array of constants defining their types.
 */

{
	{"create",	func_create,	NULL},
	{"edit", 	func_edit,	{ ROUTE_PARAM_TYPE_INTEGER } },
}



/* In a normal CGI context, you just need to define tg_cgi_main() */
tg_reponse *response
tg_cgi_main(tg_request *request)
{
	return NULL;
}

/* In a FCGI env, you need to define tg_fcgi_init
