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
 *
 *	This software uses the Intel Computer Vision Library
 *
 *    Intel License Agreement
 *                For Open Source Computer Vision Library
 *
 * Copyright (C) 2000, Intel Corporation, all rights reserved.
 * Third party copyrights are property of their respective owners.
 */

#ifndef _IIMAGE_H
#define _IIMAGE_H 1

#include <string>

#include <boost/shared_ptr.hpp>
#include <boost/noncopyable.hpp>

#include <opencv/cv.h>
#include <opencv/cxcore.h>

#ifdef _WINDOWS
#include <cvcam.h>
#endif

#include <opencv/highgui.h>

namespace YAWCG{

/*
 * Forward and typedef
 */
class IImage;
typedef boost::shared_ptr<IImage> ImagePtr;

/*
 * @brief IImage
 *
 * Interface declration for an image
 *
 * @code
 *
 * ImagePtr img = IImage::Create( data );
 * 
 * @endcode
 */
class IImage : private boost::noncopyable
{
public:

	/*
	 * Virtual D'tor
	 */
	virtual ~IImage() {}

	/*
	 * Create an image with given IplImage data
	 */
	static ImagePtr Create( IplImage* data );

	/*
	 * Save the image in jpg format.
	 *
	 * @name the filename for the image
	 */
	virtual void Save( const std::string& name ) = 0;

}; //end class IImage

} //end namespace

#endif //_IIMAGE_H
