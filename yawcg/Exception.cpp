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


#include "Exception.h"

namespace YAWCG {

yawcg_exception::yawcg_exception( const std::string& err )
: m_what( err )
{
}

yawcg_exception::~yawcg_exception()
{
}

std::string yawcg_exception::what() const
{
	return m_what;
}

} //endnamespace YAWCG
