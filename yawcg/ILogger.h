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

#ifndef _ILOGGER_H 
#define _ILOGGER_H 1

#include <string>
#include <boost/noncopyable.hpp> 
#include <boost/shared_ptr.hpp> 

namespace YAWCG {

/*
 * Forward and typedef
 */
class ILogger;
typedef boost::shared_ptr<ILogger> LoggerPtr;


/*
 * @brief ILogger
 *
 * ILogger interface, for logging into files, stdout or somewhere else
 *
 * @code
 *
 * LoggerPtr logger = ILogger::Create( verbose );
 * logger->log( L"Important Message" );
 *
 * @endcode
 */
class ILogger : private boost::noncopyable
{

public:

	/*
	 * Virtual D'tor
	 */ 
	virtual ~ILogger(){};

	/*
	 * Log a message
	 */
	virtual void Log( const std::wstring& msg, bool verbose = false ) = 0;

	/* 
	 * Create an instance, given parameter describes verbose logging or not
	 * Today only a bool verbose is supported, maybe in future a real
	 * loglevel handling is needed instead.
	 *
	 * @param bool verbose logging ?!?
	 */
	static LoggerPtr Create( bool verbose = false );

};//end class ILogger


} //end namespace YAWCG


#endif //_ILOGGER_H 