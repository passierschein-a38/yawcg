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

#include <opencv/cv.h>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>

#include "IWebCam.h"
#include "Exception.h"

namespace YAWCG {
 
/*
 * @brief WebCamPtr
 *
 * This class implements the IWebCam interface. It uses the OpenCV library
 * to communicate with a webcam.
 */
class CWebcam : public IWebCam
{
	/*
	 * Only the interface IWebCam can construct our class
	 */
	friend  WebCamPtr IWebCam::Create();

public:

	/*
	 * Virtual D'tor
	 */
	virtual ~CWebcam();

	/*@{ Interface IWebCam */
	void Start();
	void Stop();
	ImagePtr Snapshot();
	/*@} end */

private:
	/*
	 * Private constructor
	 */
	CWebcam();

	/*
	 * Hold the capture
	 */
	CvCapture*  m_pCapture;

}; //end class

CWebcam::CWebcam()
: m_pCapture(NULL)
{
}

CWebcam::~CWebcam()
{
	if( m_pCapture )
	{
		cvReleaseCapture( &m_pCapture );
	}
}

void CWebcam::Start()
{
	m_pCapture = cvCaptureFromCAM( -1 );

	if( m_pCapture == NULL )
	{
		throw yawcg_exception( "No Webcam found" );
	}

}

void CWebcam::Stop()
{
	if( m_pCapture != NULL )
	{
		cvReleaseCapture( &m_pCapture );
		m_pCapture = NULL;
	}
}

ImagePtr CWebcam::Snapshot()
{
	IplImage* i = cvQueryFrame( m_pCapture );

	if( i == NULL )
	{
		throw yawcg_exception( "Failed to grab a frame" );
	}

	return IImage::Create( i );
}

WebCamPtr IWebCam::Create()
{
	WebCamPtr ptr;
	ptr.reset( new CWebcam() );
	return ptr;
}

} //end namespace