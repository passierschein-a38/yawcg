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

#ifndef _IWEBCAM_H
#define _IWEBCAM_H 1

#include <string>

#include <boost/shared_ptr.hpp>
#include <boost/noncopyable.hpp>

#include "IImage.h"

namespace YAWCG {

/*
 * Forward and typedef
 */
class IWebCam;
typedef boost::shared_ptr<IWebCam> WebCamPtr;

/*
 * @brief IWebCam
 *
 * Interface declaration for a webcam
 *
 * @code
 *
 * WebCamPtr webcam = IWebCam::Create();
 * webcam->Start();
 * webcam->Snapshot();
 * webcam->Stop();
 *
 * @endcode
 *
 */
class IWebCam : private boost::noncopyable
{
public:

	/*
	 * Vritual D'tor
	 */
	virtual ~IWebCam() {}

	/*
	 * Start the Webcam
	 */
	virtual void Start() = 0;

	/*
	 * Take a snapshot from the camera
	 */
	virtual ImagePtr Snapshot() = 0;
	
	/*
	 * Create an instance 
	 */
	static WebCamPtr Create();

	/*
	 * Stop the Webcam
	 */
	virtual void Stop() = 0;

};//end class IWebCam



}//end namespace

#endif //_IWEBCAM_H