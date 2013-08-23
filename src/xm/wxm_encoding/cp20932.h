///////////////////////////////////////////////////////////////////////////////
// vim:         ts=4 sw=4
// Name:        xm/wxm_encoding/cp20932.h
// Description: define the Double-byte Encoding CP20932
// Author:      wxmedit@gmail.com
// Licence:     GPL
///////////////////////////////////////////////////////////////////////////////

#ifndef _WXM_ENCODING_CP20932_H_
#define _WXM_ENCODING_CP20932_H_

#include "doublebyte.h"

#ifdef _MSC_VER
# pragma warning( push )
# pragma warning( disable : 4250 )
#endif

namespace wxm
{

struct EUCJPMSConverter: public ICUConverter
{
	EUCJPMSConverter(const std::string& encname)
		:ICUConverter(encname)
	{
	}

	virtual size_t MB2WC(UChar32& ch, const char* src, size_t src_len);
	virtual size_t WC2MB(char* dest, size_t dest_len, const UChar32& ch);
};

struct EUCJPMSTableFixer: public DoubleByteEncodingTableFixer
{
	virtual void fix();
};

struct WXMEncodingEUCJPMS: public WXMEncodingDoubleByteISO646Compatible
{
private:
	friend WXMEncoding* WXMEncodingCreator::CreateWxmEncoding(ssize_t idx);
	~WXMEncodingEUCJPMS(){}

	virtual void InitMBConverter()
	{
		m_mbcnv = new EUCJPMSConverter(m_innername);
	}

	virtual DoubleByteEncodingTableFixer* CreateDoubleByteEncodingTableFixer()
	{
		return new EUCJPMSTableFixer();
	}
};

};// namespace wxm

#ifdef _MSC_VER
# pragma warning( pop )
#endif

#endif // _WXM_ENCODING_CP20932_H_
