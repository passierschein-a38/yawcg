/*
 *	@author: Axel Sauerh�fer <axel@willcodqtforfood.de>
 *  @url: http://www.ohloh.net/projects/YetAnotherWebCamGrabber
 *
 *	This file is part of Yet Another WebCam Grabber.
 *
 *  Yet Another WebCam Grabber is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Yet Another WebCam Grabber is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 *	This software uses the Intel Computer Vision Library
 *
 *    Intel License Agreement
 *                For Open Source Computer Vision Library
 *
 * Copyright (C) 2000, Intel Corporation, all rights reserved.
 * Third party copyrights are property of their respective owners.
 */

#include "IImage.h"
#include "Exception.h"

namespace YAWCG {

/*
 * @brief CImage
 *
 * Concrete implementation of IImage
 */
class CImage : public IImage
{
	/*
	 * Only the interface can create us
	 */
	friend ImagePtr IImage::Create( IplImage* data );

public:
	/*
	 * Virtual D'Tor
	 */
	virtual ~CImage();

	/*@{ Interface IImage */
	void Save( const std::string& name );
	/*@} end*/

private:
	/*
	 * Private C'tor
	 *
	 * @param data is a IplImage
	 */
	CImage( IplImage* data );

	/*
	 * Internal data holder
	 */
	IplImage* m_pImageData;

}; //end class CImage


CImage::CImage( IplImage* data )
: m_pImageData( data )
{	
}

CImage::~CImage()
{
}

void CImage::Save( const std::string& name )
{
	if( !cvSaveImage( name.c_str(), m_pImageData ) )
	{
		throw yawcg_exception( "Save Image failed" );			
	}
}

ImagePtr IImage::Create( IplImage* data )
{
	ImagePtr ptr;
	ptr.reset( new CImage( data ) );
	return ptr;
}

} //end namespace YAWCG
