#include "../inc/c_x.h"
#include "../../common/inc/oscore_edhoc_error.h"
#include "../inc/memcpy_s.h"

void c_x_init(struct c_x *c, uint8_t *buf, uint32_t buf_len)
{
	byte_array_init(buf, buf_len, &c->mem.c_x_bstr);
}

enum err c_x_set(enum c_x_type t, const uint8_t *c_x_raw_buf,
		 uint32_t c_x_raw_buf_len, int c_x_int, struct c_x *out)
{
	if (t == INT) {
		out->type = INT;
		out->mem.c_x_int = c_x_int;
		return ok;
	} else {
		out->type = BSTR;
		out->mem.c_x_bstr.len = c_x_raw_buf_len;
		return _memcpy_s(out->mem.c_x_bstr.ptr, out->mem.c_x_bstr.len,
				 c_x_raw_buf, c_x_raw_buf_len);
	}
}

