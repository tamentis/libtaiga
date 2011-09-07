
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "taiga.h"


tg_response *
tg_response_new(void)
{
	tg_response *response;

	response = malloc(sizeof(tg_response));

	return response;
}

void
tg_response_set_content_type(tg_response *response, wchar_t *content_type)
{
	wcslcpy(response->content_type, content_type, CONTENT_TYPE_SIZE);
}

tg_response *
tg_response_new_html()
{
	tg_response *response;

	response = tg_response_new();
	tg_response_set_content_type(response, L"text/html");

	return response;
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
	wchar_t woutput[4096];
	char output[4096];
	char mb_cts[4096];
	char mb_cbf[4096];
	
	wcstombs(mb_cts, response->content_type, 4096);
	wcstombs(mb_cbf, response->content_buffer, 4096);

	printf("Content-type: %s\r\n\r\n", mb_cts);
	printf("%s", mb_cbf);

}
