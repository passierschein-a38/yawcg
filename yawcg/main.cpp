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

#include <iostream>
#include <sstream>

#include <boost/program_options.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/fstream.hpp> 

#include "IWebCam.h"
#include "Exception.h"
#include "ILogger.h"

using namespace YAWCG;
using namespace boost::program_options;
using namespace boost::filesystem;

int main( int argc, char** argv )
{
	options_description desc( "Options" );
	
	desc.add_options()
				("help",							"produce help message")
				("verbose",							"get some verbose output")
				("number", value<int>()			,	"number of pictures to take")
				("delay",  value<int>()			,	"delay between taking multiple pictures")
				("outdir", value<std::string>()	,	"picture output directory")
				("format", value<std::string>()	,	"jpg, png, dib, bmp, tiff");
				

	variables_map vm;

	try{
		store( parse_command_line( argc, argv, desc ), vm );		
	}catch( std::exception& poe )
	{
		std::cerr << poe.what();
		return -1;
	}

	notify( vm );    

	if( vm.count("help") )
	{
		std::cout << desc << std::endl;
        return 0;
	}

	//bool verbose output
	bool verbose = false;

	if( vm.count("verbose") )
	{
		verbose = true;
	}

	LoggerPtr logger = ILogger::Create( verbose );
	logger->Log( L"Startup" , 1 );

	//number of pictures to take
	int num = 1;

	if( vm.count("number") )
	{
		num = vm["number"].as<int>();
	}

	//default 1 second
	int delay = 1;

	if( vm.count("delay") )
	{
		delay = vm["delay"].as<int>();
	}

	//default output directory
	std::string outdir = "";

	if( vm.count("outdir") )
	{
		outdir = vm["outdir"].as<std::string>();
		path dir(outdir);

		if( !exists( dir ) )
		{ 

			#ifdef _WINDOWS			
			if( ! create_directories( dir ) )
			{
				std::cerr << "Invalid output directory: " << outdir;
				return -1;
			}
			#else
			if( ! create_directory( dir ) )
			{
				std::cerr << "Invalid output directory: " << outdir;
				return -1;
			}
			#endif
		}
	}

	//picture format
	std::string format = "jpg";

	if( vm.count("format") )
	{
		format = vm["format"].as<std::string>();

		if( format != "jpg"  &&
			format != "png"  &&
			format != "bmp"  &&
			format != "tiff" &&
			format != "dib" )
		{
			std::cerr << "Unknown format: " << format;
			return -1;
		}
	}

	try{
		WebCamPtr cam = IWebCam::Create();
		cam->Start();

		for(int i=0; i<num; ++i )
		{
			ImagePtr img = cam->Snapshot();
			std::stringstream stream;

			if( outdir.size() > 0 )
			{
				stream << outdir << "/";
			}
			
			{
				char       buf[80];
				time_t     now;
				struct tm  *ts;
				time(&now);
				ts = localtime(&now);
				strftime(buf, sizeof(buf), "%Y-%m-%d-%S", ts);
				stream << "yawcg_" << buf;
			}

			stream << "." << format;
			img->Save( stream.str().c_str() );
			
			#ifdef WIN32
				Sleep( ( delay * 1000 ) );
			#else
				sleep(  ( delay  ) );
			#endif
		}

		cam->Stop();
	}catch( yawcg_exception& e )
	{
		std::cout << e.what();
		return -1;
	}

	logger->Log( L"Shutdown" , 1 );

	return 0;
}