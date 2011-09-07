#include <locale.h>
#include <stdio.h>
#include "taiga.h"

int
main(int argc, char **argv)
{
	tg_response *response;
	tg_request request;
	wchar_t body[] = L"<html><body>Woot</body></html>\n";

	setlocale(LC_ALL, "");

	response = tg_response_new_html();

	tg_response_set_content(response, body, wcslen(body));
	tg_response_print(response);

	return 0;
}
