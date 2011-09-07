#include <wchar.h>

#include "taiga.h"


tg_response *
tg_response_new(void)
{
	tg_response *response;

	response = malloc(sizeof(tg_response));

	return response;
}

tg_response *
tg_response_new_html()
{
	tg_response *response;

	response = tg_response_new();
	tg_response_set_content_type("text/html");

	return response;
}

void
tg_response_set_content_type(tg_response *response, wchar_t *content_type)
{
	wcslcpy(response->content_type, content_type, CONTENT_TYPE_SIZE);
}

void
tg_response_set_content(tg_response *response, wchar_t *content, uint64_t len)
{
	response->content_length = len;
	response->content_buffer = malloc(len * sizeof(wchar_t));
	wcslcpy(response->content_buffer, content, len);
}

void
tg_response_print(tg_response *response)
{
	printf("Content-type: %s\r\n\r\n", response->content_type);
	printf("%s", response->content_buffer);
}
