#include <stdint.h>
#include <wchar.h>

// TODO: Read RFC
#define SERVER_PROTOCOL_SIZE	64
#define REMOTE_USER_SIZE	64
#define REMOTE_ADDR_SIZE	64
#define QUERY_STRING_SIZE	4096
#define REQUEST_METHOD_SIZE	32
#define CONTENT_TYPE_SIZE	64

/* Request methods */
enum request_method_enum {
	REQUEST_METHOD_GET,
	REQUEST_METHOD_POST,
	REQUEST_METHOD_HEAD
};

/*
 * A tg_request is received by an action, which returns back a tg_response.
 */
typedef struct _tg_request {
	uint64_t content_length;
	char content_type[CONTENT_TYPE_SIZE];
	char server_protocol[SERVER_PROTOCOL_SIZE];
	char remote_user[REMOTE_USER_SIZE];
	char *query_string;
	enum request_method_enum request_method;
} tg_request;


/* 
 * A tg_response is returned by every action in the system.
 */
typedef struct _tg_response {
	char content_type[CONTENT_TYPE_SIZE];
	uint64_t content_length;
	char *content_buffer;
	FILE *content_fp;
} tg_response;


typedef struct _tg_route {
	char pattern[256];
	tg_response * (*func)(tg_request *);
	int params[256];
} tg_route;

