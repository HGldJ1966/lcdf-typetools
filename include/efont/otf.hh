#ifndef EFONT_OTF_HH
#define EFONT_OTF_HH
#include "t1cs.hh"			/* for uintXX_t definitions */
class ErrorHandler;

class EfontOTF { public:

    EfontOTF(const String &, ErrorHandler * = 0);
    ~EfontOTF();

    bool ok() const			{ return _error >= 0; }
    int error() const			{ return _error; }

    const String &data_string() const	{ return _data_string; }
    const uint8_t *data() const		{ return _data; }
    int length() const			{ return _len; }

    String table(const char *) const;

  private:

    String _data_string;
    const uint8_t *_data;
    int _len;

    int _error;

    enum { HEADER_SIZE = 12, TABLE_DIR_ENTRY_SIZE = 16 };

    int parse_header(ErrorHandler *);
    
};

#endif
