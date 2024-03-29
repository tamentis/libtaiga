
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "taiga.h"


tg_request *
tg_request_new(void)
{
	tg_request *request;

	request = malloc(sizeof(tg_request));
	request->query_string = NULL;

	return request;
}

void
tg_request_set_query_string(tg_request *request, const char *value)
{
	request->query_string = strdup(value);
}

tg_request *
tg_request_new_from_env()
{
	tg_request *request;
	const char *qs;

	request = tg_request_new();
	qs = getenv("QUERY_STRING");
	if (qs != NULL)
		request->query_string = strdup(qs);

	return request;
}

