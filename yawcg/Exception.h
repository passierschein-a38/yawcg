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

#ifndef _EXCEPTION_H
#define _EXCEPTION_H 1

#include <string>

namespace YAWCG {

/*
 * @brief yawcg_exception
 *
 * Simple exception class 
 */
class yawcg_exception 
{
public:
	/*
	 * C'Tor accepting the error message
	 */
	yawcg_exception( const std::string& err );

	/*
	 * D'Tor
	 */
	virtual ~yawcg_exception();

	/*
	 * Return what error has happend
	 */
	std::string what() const;

private:

	/*
	* error message
	*/
	std::string m_what;

}; //end class yawcg_exception


} //end namespaces


#endif //_EXCEPTION_H
