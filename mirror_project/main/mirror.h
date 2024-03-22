#ifndef _MIRROR_H_
#define _MIRROR_H_


static void blink(void *);
static void event_handler(void* arg, esp_event_base_t event_base,
                          int32_t event_id, void* event_data);
static void wifi_init_sta(void);
static void get_device_service_name(char *service_name, size_t max);
esp_err_t custom_prov_data_handler(uint32_t session_id, const uint8_t *inbuf, ssize_t inlen,
                                          uint8_t **outbuf, ssize_t *outlen, void *priv_data);






static void wifi_prov_print_qr(const char *name, const char *username, const char *pop, const char *transport);
void set_blink_status(uint8_t new_blink_status);




#include <esp_https_server.h>
#include "esp_tls.h"

static esp_err_t root_get_handler(httpd_req_t *req);
static httpd_handle_t start_webserver(void);

#endif /* _MIRROR_H_ */