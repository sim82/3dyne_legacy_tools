/* 
 * 3dyne Legacy Tools GPL Source Code
 * 
 * Copyright (C) 1996-2012 Matthias C. Berger & Simon Berger.
 * 
 * This file is part of the 3dyne Legacy Tools GPL Source Code ("3dyne Legacy
 * Tools Source Code").
 *   
 * 3dyne Legacy Tools Source Code is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 * 
 * 3dyne Legacy Tools Source Code is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General
 * Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along with
 * 3dyne Legacy Tools Source Code.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * In addition, the 3dyne Legacy Tools Source Code is also subject to certain
 * additional terms. You should have received a copy of these additional terms
 * immediately following the terms and conditions of the GNU General Public
 * License which accompanied the 3dyne Legacy Tools Source Code.
 * 
 * Contributors:
 *     Matthias C. Berger (mcb77@gmx.de) - initial API and implementation
 *     Simon Berger (simberger@gmail.com) - initial API and implementation
 */



// TexRes.hh

#ifndef __TexRes
#define __TexRes

#include "qimage.h"

#include "lib_hobj.h"
#include "lib_containerdefs.h"

#include "texture.h"

QImage * TexIdent_BuildQImage( texident_t *ti );

class TexRes
{
public:         
	friend texident_t * TexIdent_GetByIdent( const char *ident );
                                                
	TexRes( const char *path );
	~TexRes();

	texident_t	* getTexIdentByIdent( const char *ident, bool ignore_multilayer = false );
	void		initIdentListIter( u_list_iter_t *list_iter );

private:

	hmanager_t		*gltexres_hm;
	hmanager_t		*multilayer_hm;

	u_map_t			gltexres_map;		// texident_t
	u_map_t			multilayer_map;		// texident_t

	u_list_t		ident_list;		// multilayers override gltexres in this list
};


#endif
