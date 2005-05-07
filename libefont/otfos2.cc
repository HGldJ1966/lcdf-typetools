// -*- related-file-name: "../include/efont/otfos2.hh" -*-

/* otfos2.{cc,hh} -- OpenType OS/2 table
 *
 * Copyright (c) 2005 Eddie Kohler
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version. This program is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details.
 */

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif
#include <efont/otfos2.hh>
#include <lcdf/error.hh>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

namespace Efont { namespace OpenType {

Os2::Os2(const Data &data, ErrorHandler *errh)
    : _data(data)
{
    _error = parse_header(errh ? errh : ErrorHandler::silent_handler());
    fprintf(stderr, "%u %d %d\n", _data.u16(4), typo_ascender(), x_height());
    if (_error < 0)
	_data = Data();
}

int
Os2::parse_header(ErrorHandler *errh)
{
    // HEADER FORMAT:
    // USHORT	version
    // USHORT	numTables
    if (HEADER_SIZE > _data.length())
	return errh->error("OTF OS/2 too small for header"), -EFAULT;
    if (_data.u16(0) > 3)
	return errh->error("bad OS/2 version number"), -ERANGE;
    return 0;
}

}}