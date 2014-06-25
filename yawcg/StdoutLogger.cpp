/*
 *	@author: Axel Sauerhoefer <axel@willcodqtforfood.de>
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

#ifndef _STDOUTLOGGER_H 
#define _STDOUTLOGGER_H 1

#include <iostream>
#include "ILogger.h"

namespace YAWCG {

class CStdoutLogger : public ILogger
{
	/*
	 * Only the interface ILogger can construct our class
	 */
	friend  LoggerPtr ILogger::Create( bool verbose );

public:

	/*
	 * Virtual D'tor
	 */
	virtual ~CStdoutLogger();

	/*@{ Interface ILogger */
	void Log( const std::wstring& msg, bool verbose = false );
	/*@} end */

private:
	
	/*
	 * Private constructor
	 */
	CStdoutLogger( bool verbose = false);

	/*
	 * verbose logging active ?
	 */
	 bool m_bVerbose;

}; //end class CStdoutLogger


CStdoutLogger::CStdoutLogger( bool verbose )
: m_bVerbose( verbose )
{
}

CStdoutLogger::~CStdoutLogger()
{
}

void CStdoutLogger::Log( const std::wstring& msg, bool verbose )
{
	if( m_bVerbose && verbose )
	{
		std::wcout << msg << std::endl;
	}
}

LoggerPtr ILogger::Create( bool verbose )
{
	LoggerPtr ptr;
	ptr.reset( new CStdoutLogger( verbose ) );
	return ptr;
}

} //end namespace YAWCG


#endif // _STDOUTLOGGER_H