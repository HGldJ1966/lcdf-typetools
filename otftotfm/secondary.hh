#ifndef OTFTOTFM_SECONDARY_HH
#define OTFTOTFM_SECONDARY_HH
#include <efont/otfcmap.hh>
#include <efont/cff.hh>
class DvipsEncoding;
class Setting;

class Secondary { public:
    virtual ~Secondary();
    virtual bool setting(uint32_t uni, Vector<Setting> &, const DvipsEncoding &);
};

class T1Secondary : public Secondary { public:
    T1Secondary(const Efont::Cff::Font *, const Efont::OpenType::Cmap &);
    enum { U_CWM = 0xD800, U_VISIBLESPACE = 0xD801,
	   U_SS = 0xD802, U_IJ = 0x0132, U_ij = 0x0133 };
    bool setting(uint32_t uni, Vector<Setting> &, const DvipsEncoding &);
  private:
    int _xheight;
    int _spacewidth;
    bool two_char_setting(uint32_t uni1, uint32_t uni2, Vector<Setting> &, const DvipsEncoding &);
};

bool char_bounds(int bounds[4], int &width,
		 const Efont::Cff::Font *, const Efont::OpenType::Cmap &,
		 uint32_t uni);

#endif