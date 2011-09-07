#include <stdio.h>
#include "taiga.h"

int
main(int argc, char **argv)
{
	tg_response *response = tg_response_new_html();
	tg_request request;

	tg_response_set_content("<html><body>Woot</body></html>\n");
	tg_response_print(response);

	return 0;
}
